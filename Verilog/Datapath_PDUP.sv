/* Version 1.2 
Negator: PipelinedDecoupledNegator
Negator Bandwidth: 32
Memory Bandwidth: 64
Interface: DECOUPLED
Encryption: NO
*/
`include "negator/PipelinedDecoupledNegator.sv"

`timescale 1ns/100ps

// mem bandwidth is 64 bit, but each integer is 32 bit

module Datapath_PDUP (
	input clock,
	input reset,
	input logic input_valid, // hi for input valid, lo for input not valid
	input logic [63:0] input_data,

	output logic output_valid, // hi for output valid, lo for output not valid
	output logic [63:0] output_data
);

	logic input_counter, n_input_counter;
	logic output_counter, n_output_counter;
	logic input_valid_buffer, n_input_valid_buffer;
	logic output_valid_buffer, n_output_valid_buffer;
	logic [63:0] input_buffer;
	logic [63:0] n_input_buffer;

	logic [63:0] output_buffer;
	logic [63:0] n_output_buffer;

	logic [31:0] input_to_negator;
	logic [31:0] output_from_negator;
	logic valid_input_to_negator, valid_output_from_negator;

	// Connect the component to the datapath
		/* verilator lint_off UNUSED */
	logic ready_out, ready_input;
	assign ready_input = 1;
	PipelinedDecoupledNegator #(1, 32, 4) 
	PipelinedDecoupledNegator( clock, reset, valid_input_to_negator, ready_out, input_to_negator, valid_output_from_negator, ready_input, output_from_negator);
	/* verilator lint_on UNUSED */

	assign output_valid = output_valid_buffer;
	assign output_data = output_buffer;

	always_comb begin
		if(!input_valid_buffer) begin
			if(input_valid) begin
				n_input_valid_buffer = 'b1;
				n_input_buffer = input_data;
				n_input_counter = 'b0;
				input_to_negator = 'b0;
				valid_input_to_negator = 'b0;
			end
			else begin
				n_input_valid_buffer = 'b0;
				n_input_buffer = input_data;
				n_input_counter = 'b0;
				input_to_negator = 'b0;
				valid_input_to_negator = 'b0;
			end
		end
		else if(input_counter == 0) begin
			n_input_valid_buffer = 'b1;
			n_input_buffer = input_buffer;
			n_input_counter = 'b1;
			input_to_negator = input_buffer[31:0];
			valid_input_to_negator = 'b1;
		end
		else begin
			n_input_valid_buffer = 'b0;
			n_input_buffer = 'b0;
			n_input_counter = 'b0;
			input_to_negator = input_buffer[63:32];
			valid_input_to_negator = 'b1;
		end
	end

	always_comb begin
		if(!output_valid_buffer) begin
			if(valid_output_from_negator) begin
				if(output_counter) begin
					n_output_valid_buffer = 1;
					n_output_buffer = {output_from_negator,output_buffer[31:0]};
					n_output_counter = 0;
				end
				else begin
					n_output_valid_buffer = 0;
					n_output_buffer = {32'b0, output_from_negator};
					n_output_counter = 1;
				end
			end
			else begin
				n_output_valid_buffer = output_valid_buffer;
				n_output_buffer = output_buffer;
				n_output_counter = output_counter;
			end
		end
		else begin
			n_output_valid_buffer = 'b0;
			n_output_buffer = 'b0;
			n_output_counter = 'b0;			
		end
	end

    always_ff @(posedge clock) begin 
		if(reset) begin
			input_buffer <=  'b0;
			output_buffer <=  'b0;
			input_counter <=  'b0;
			output_counter <=  'b0;
			input_valid_buffer <=  'b0;
			output_valid_buffer <=  'b0;
		end
		else begin
			input_buffer <=  n_input_buffer;
			output_buffer <=  n_output_buffer;
			input_counter <=  n_input_counter;
			output_counter <=  n_output_counter;
			input_valid_buffer <=  n_input_valid_buffer;
			output_valid_buffer <=  n_output_valid_buffer;
		end
	end

endmodule