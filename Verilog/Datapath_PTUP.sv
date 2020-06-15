/*
Negator: PipelinedTightlyCoupledNegator
Negator Bandwidth: 32
Memory Bandwidth: 64
Interface: TIGHTLY_COUPLED
Encryption: NO
*/
`include "Encryp-Decryp-Simulator/SimulatedDecryptEngin.sv"
`include "Encryp-Decryp-Simulator/SimulatedEncryptEngin.sv"
`include "negator/PipelinedDecoupledNegator.sv"
`include "negator/PipelinedTightlyCoupledNegator.sv"
`include "negator/SingleCycleTightlyCoupledNegator.sv"

`timescale 1ns/100ps
`define SD #1

`define BUS_NONE  2'b0
`define BUS_LOAD = 2'b01
`define BUS_STORE = 2'b10

// Iterate through mem space 0 ~ 0x10000
// Assuming word addressable
// 1. To move the pipeline forward, store has a higher priority
// 2. No MSHR ---> stall until resolved
// 3. mem bandwidth is 64 bit, but each integer is 32 bit
// 4. assume the mem request will always complete in finite cycles, but more than one cycle
module Datapath (
	input clock,
	input reset,
	input logic [3:0] mem2proc_reponse, // 0 = can't accept, other = tag of transaction
	input logic [63:0] mem2proc_data,
	input logic [3:0] mem2proc_tag, // 0 = no value, other = tag of transaction
	
	output logic [1:0] proc2mem_command, // `BUS_NONE, `BUS_LOAD, or `BUS_STORE
	output logic [63:0] proc2mem_address,
    output logic [63:0] proc2mem_data
);

	logic[1:0] proc2mem_cmd;
    logic[1:0] n_proc2mem_cmd; // Logic to determine if we shoud load or store
	logic [63:0] address_to_load;
    logic [63:0] address_to_store;
    logic [63:0] n_address_to_load;
    logic [63:0] n_address_to_store;
    logic [63:0] store_buffer;
	logic [63:0] n_store_buffer;
    logic [31:0] input_to_negator;
	logic [31:0] negator_output_data;
	logic [31:0] load_buffer;
	logic [31:0] n_load_buffer;
	logic [1:0] counter;
    logic [1:0] n_counter; // a counter to see which half of the value to be processed
    logic valid_input_to_negator, valid_output_from_negator;
	logic unresolved_req, n_unresolved_req; // hi if there is an unresolved request, lo is we are clear to issue new request
	logic last_ld_st, n_last_ld_st; // To store if last is store or load, hi is load, lo is store
	// Connect the component to the datapath
	PipelinedTightlyCoupledNegator #(WIDTH_IN_NUM_OF_FULL_INTEGER = 1, INTEGER_WIDTH = 32) 
	pipelinedTightlyCoupledNegator( clock, reset, valid_input_to_negator, input_to_negator, valid_output_from_negator, negator_output_data);

	// Assign outputs
	assign proc2mem_command = proc2mem_cmd;
	assign proc2mem_data = {store_buffer, negator_output_data};

	if(proc2mem_cmd == `BUS_LOAD)
		proc2mem_address = address_to_load;
	else if(proc2mem_cmd == `BUS_STORE)
		proc2mem_address = address_to_store;
	else
		proc2mem_address = 'b0;
        
	//if we have requested a new data, we can increment it by 4
	assign n_address_to_load = (proc2mem_cmd == `BUS_LOAD) ? (address_to_load + 'd4) : address_to_load; 
	//if we have stored a new data, we can increment it by 4
	assign n_address_to_store = (proc2mem_cmd == `BUS_STORE) ? (address_to_store + 'd4) : address_to_store; 

	if(last_ld_st) begin // if last req is load
		if( unresolved_req ) begin // if there is an unresolved load req
			if( mem2proc_tag) begin // we received a response
				n_counter = 2'b01; // We change counter to 1
				n_proc2mem_cmd = `BUS_NONE;
				n_last_ld_st = 'b1;
				n_unresolved_req = 'b0;
				n_load_buffer = mem2proc_data[63:32];
				n_store_buffer = 'b0;
                valid_input_to_negator = 'b1;
                input_to_negator = mem2proc_data[31:0];
			end
			else begin
				n_counter = 'b0;
				n_proc2mem_cmd = `BUS_NONE;
				n_last_ld_st = 'b1;
				n_unresolved_req = 'b1;
				n_load_buffer = 'b0;
				n_store_buffer = 'b0;
                valid_input_to_negator = 'b0;
                input_to_negator = 'b0;
			end
		end
		else begin 
			if(counter == 2'b01) begin
				n_counter = 2'b10;
				n_proc2mem_cmd = `BUS_NONE;
				n_last_ld_st = 'b1;
				n_unresolved_req = 'b0;	
				n_load_buffer = 'b0;
				n_store_buffer = 'b0; 
                valid_input_to_negator = 'b1;
                input_to_negator = load_buffer;
			end
			else if(counter == 2'b10) begin
				n_counter = 2'b11;
				n_proc2mem_cmd = `BUS_STORE; // we can issue a store at the next cycle
				n_last_ld_st = 'b0;
				n_unresolved_req = 'b0;	
				n_load_buffer = 'b0;
				n_store_buffer = negator_output_data; 
                valid_input_to_negator = 'b0;
                input_to_negator = 'b0;
			end
			else begin // We are issuing load at this cycle
				n_counter = 'b0;
				n_proc2mem_cmd = `BUS_NONE;
				n_last_ld_st = 'b1;
				n_unresolved_req = 'b1;
				n_load_buffer = 'b0;
				n_store_buffer = 'b0;
                valid_input_to_negator = 'b0;
                input_to_negator = 'b0;
			end
		end
	end
	else begin
		if( unresolved_req ) begin // if there is an unresolved store req
			if( mem2proc_tag) begin // we received a response
				n_counter = 'b0;
				n_proc2mem_cmd = `BUS_LOAD; // we can issue a load at the next cycle
				n_last_ld_st = 'b1;
				n_unresolved_req = 'b0;
				n_load_buffer = 'b0;
				n_store_buffer = 'b0;
                valid_input_to_negator = 'b0;
                input_to_negator = 'b0;
			end
			else begin
				n_counter = 'b0;
				n_proc2mem_cmd = `BUS_NONE;
				n_last_ld_st = 'b0;
				n_unresolved_req = 'b1;
				n_load_buffer = 'b0;
				n_store_buffer = 'b0;
                valid_input_to_negator = 'b0;
                input_to_negator = 'b0;
			end
		end
		else begin // We are issuing load at this cycle
			n_counter = 'b0;
			n_proc2mem_cmd = `BUS_NONE;
			n_last_ld_st = 'b0;
			n_unresolved_req = 'b1;
			n_load_buffer = 'b0;
			n_store_buffer = 'b0;
            valid_input_to_negator = 'b0;
            input_to_negator = 'b0;
		end		
	end

    always_ff(@posedge clock) begin 
        if(reset) begin
            address_to_load <= `SD 'b0;
            address_to_store <= `SD 'b0;
            store_buffer <= `SD 'b0;
            unresolved_req <= `SD 'b0;
            proc2mem_cmd <= `SD 'b0;
			last_ld_st <= `SD 'b0;
			load_buffer <= `SD 'b0;
			counter <= `SD 'b0;
        end
        else begin
            address_to_load <= `SD n_address_to_load;
            address_to_store <= `SD n_address_to_store;
            store_buffer <= `SD n_store_buffer;
            unresolved_req <= `SD n_unresolved_req;
            proc2mem_cmd <= `SD n_proc2mem_cmd;
			last_ld_st <= `SD n_last_ld_st;
			load_buffer <= `SD n_load_buffer;
			counter <= `SD n_counter;
        end
    end

endmodule