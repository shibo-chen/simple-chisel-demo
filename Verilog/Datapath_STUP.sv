/* Version 1.2 
Negator: SingleCycleTightlyCoupledNegator
Negator Bandwidth: 32
Memory Bandwidth: 64
Interface: TIGHTLY_COUPLED
Encryption: NO
*/
`include "negator/SingleCycleTightlyCoupledNegator.sv"

`timescale 1ns/100ps

// mem bandwidth is 64 bit, but each integer is 32 bit

module Datapath_STUP (
	input clock,
	input reset,
	input logic input_valid, // hi for input valid, lo for input not valid
	input logic [63:0] input_data,

	output logic output_valid, // hi for output valid, lo for output not valid
	output logic [63:0] output_data
);
	logic counter, n_counter;
	logic input_valid_buffer, n_input_valid_buffer;
	logic output_valid_buffer, n_output_valid_buffer;
	logic [63:0] input_buffer;
	logic [63:0] n_input_buffer;

	logic [63:0] output_buffer;
	logic [63:0] n_output_buffer;

	logic [31:0] input_to_negator;
	logic [31:0] output_from_negator;


	// Connect the component to the datapath
	SingleCycleTightlyCoupledNegator #(1, 32) singleCycleTightlyCoupledNegator(input_to_negator, output_from_negator);

	assign output_valid = output_valid_buffer;
	assign output_data = output_buffer;

	always_comb begin
		if(!input_valid_buffer) begin
			if(input_valid) begin
				n_input_valid_buffer = 'b1;
				n_input_buffer = input_data;
				n_output_valid_buffer = 'b0;
				n_counter = 'b0;
				input_to_negator = 'b0;
				n_output_buffer = 'b0;
			end
			else begin
				n_input_valid_buffer = 'b0;
				n_input_buffer = 'b0;
				n_output_valid_buffer = 'b0;
				n_counter = 'b0;
				input_to_negator = 'b0;
				n_output_buffer = 'b0;
			end
		end
		else if(counter == 0) begin
			n_input_valid_buffer = 'b1;
			n_input_buffer = input_buffer;
			n_output_valid_buffer = 'b0;
			n_counter = 'b1;
			input_to_negator = input_buffer[31:0];
			n_output_buffer[63:32] = 'b0;
			n_output_buffer[31:0] = output_from_negator;
		end
		else begin
			n_input_valid_buffer = 'b0;
			n_input_buffer = 'b0;
			n_output_valid_buffer = 'b1;
			n_counter = 'b0;
			input_to_negator = input_buffer[63:32];
			n_output_buffer[63:32] = output_from_negator;
			n_output_buffer[31:0] = output_buffer[31:0];		
		end
	end

    always_ff @(posedge clock) begin 
		if(reset) begin
			input_buffer <=  'b0;
			output_buffer <=  'b0;
			counter <=  'b0;
			input_valid_buffer <=  'b0;
			output_valid_buffer <=  'b0;
		end
		else begin
			input_buffer <=  n_input_buffer;
			output_buffer <=  n_output_buffer;
			counter <=  n_counter;
			input_valid_buffer <=  n_input_valid_buffer;
			output_valid_buffer <=  n_output_valid_buffer;
		end
	end

endmodule