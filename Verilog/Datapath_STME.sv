/* Version 1.2 
Negator: SingleCycleTightlyCoupledNegator
Negator Bandwidth: 64
Memory Bandwidth: 64
Interface: TIGHTLY_COUPLED
Encryption: YES
*/
`include "Encryp-Decryp-Simulator/SimulatedAESDecryptEngin.sv"
`include "Encryp-Decryp-Simulator/SimulatedAESEncryptEngin.sv"
`include "negator/SingleCycleTightlyCoupledNegator.sv"

`timescale 1ns/100ps
`define SD #1

// mem bandwidth is 64 bit, each integer is 64 bit

module Datapath_STME (
	input clock,
	input reset,
	input logic input_valid, // hi for input valid, lo for input not valid
	input logic [63:0] input_data,

	output logic output_valid, // hi for output valid, lo for output not valid
	output logic [63:0] output_data
);
	logic next_to_encrypt;
	logic next_to_decrypt, n_next_to_decrypt;
	logic ready_from_encrypt, ready_from_decrypt;
	logic input_counter, n_input_counter;
	logic [1:0] output_counter;
	logic [1:0] n_output_counter;
	logic [127:0] input_buffer;
	logic [127:0] n_input_buffer;
	logic [127:0] output_buffer;
	logic [127:0] n_output_buffer;
	logic [127:0] input_to_encrypt;
	logic [127:0] input_to_decrypt;
	logic [127:0] output_from_encrypt;
	logic [127:0] output_from_decrypt;
	SimulatedAESDecryptEngin#(4) simulatedAESDecryptEngin(clock, reset, next_to_decrypt, input_to_decrypt, ready_from_decrypt, output_from_decrypt);
	SimulatedAESEncryptEngin#(4) SimulatedAESEncryptEngin(clock, reset, next_to_encrypt, input_to_encrypt, ready_from_encrypt, output_from_encrypt);

	// interface between in and dec
	assign input_to_decrypt = input_buffer;
	always_comb begin
		if(input_valid) begin
			if(input_counter) begin
				n_input_buffer = {input_data, input_buffer[63:0]};
				n_next_to_decrypt = 1;
				n_input_counter = 0;
			end
			else begin
				n_input_buffer = {64'b0, input_data};
				n_next_to_decrypt = 0;
				n_input_counter = 1;
			end
		end
		else begin
			n_input_buffer = input_buffer;
			n_next_to_decrypt = 0;
			n_input_counter = input_counter;
		end
	end

	always_ff @(posedge clock) begin
		if(reset) begin
			input_buffer <= 0;
			next_to_decrypt <= 0;
			input_counter <= 0;
		end
		else begin
			input_buffer <= n_input_buffer;
			next_to_decrypt <= n_next_to_decrypt;
			input_counter <= n_input_counter;
		end
	end

	// interface between out and enc
	assign output_data = output_counter[1]? output_buffer[127:64]: output_buffer[63:0];
	assign output_valid = output_counter[0] | output_counter[1];
	always_comb begin
		if(ready_from_encrypt) begin
			n_output_buffer = output_from_encrypt;
			n_output_counter = 'b01;
		end
		else begin
			n_output_buffer = output_buffer;
			if(output_counter[0]) begin
				n_output_counter = 'b10;
			end
			else begin
				n_output_counter = 'b00;
			end
		end
	end

	always_ff@(posedge clock) begin
		if(reset) begin
			output_buffer <= 0;
			output_counter <= 'b00;
		end
		else begin
			output_buffer <= n_output_buffer;
			output_counter <= n_output_counter;
		end
	end


	// singleCycle
	logic counter, n_counter;
	logic input_valid_buffer, n_input_valid_buffer;
	logic output_valid_buffer, n_output_valid_buffer;
	logic [127:0] dec_to_neg_buffer;
	logic [127:0] n_dec_to_neg_buffer;

	logic [127:0] neg_to_enc_buffer;
	logic [127:0] n_neg_to_enc_buffer;

	logic [63:0] input_to_negator;
	logic [63:0] output_from_negator;

	// Connect the component to the datapath
	SingleCycleTightlyCoupledNegator #(1, 64) singleCycleTightlyCoupledNegator(input_to_negator, output_from_negator);

	assign next_to_encrypt = output_valid_buffer;
	assign input_to_encrypt = neg_to_enc_buffer;

	always_comb begin
		if(!input_valid_buffer) begin
			if(ready_from_decrypt) begin
				n_input_valid_buffer = 'b1;
				n_dec_to_neg_buffer = output_from_decrypt;
				n_output_valid_buffer = 'b0;
				n_counter = 'b0;
				input_to_negator = 'b0;
				n_neg_to_enc_buffer = 'b0;
			end
			else begin
				n_input_valid_buffer = 'b0;
				n_dec_to_neg_buffer = 'b0;
				n_output_valid_buffer = 'b0;
				n_counter = 'b0;
				input_to_negator = 'b0;
				n_neg_to_enc_buffer = 'b0;
			end
		end
		else if(counter == 0) begin
			n_input_valid_buffer = 'b1;
			n_dec_to_neg_buffer = dec_to_neg_buffer;
			n_output_valid_buffer = 'b0;
			n_counter = 'b1;
			input_to_negator = dec_to_neg_buffer[63:0];
			n_neg_to_enc_buffer[127:64] = 'b0;
			n_neg_to_enc_buffer[63:0] = output_from_negator;
		end
		else begin
			n_input_valid_buffer = 'b0;
			n_dec_to_neg_buffer = 'b0;
			n_output_valid_buffer = 'b1;
			n_counter = 'b0;
			input_to_negator = dec_to_neg_buffer[127:64];
			n_neg_to_enc_buffer[127:64] = output_from_negator;
			n_neg_to_enc_buffer[63:0] = neg_to_enc_buffer[63:0];		
		end
	end

    always_ff @(posedge clock) begin 
		if(reset) begin
			dec_to_neg_buffer <=  'b0;
			neg_to_enc_buffer <=  'b0;
			counter <=  'b0;
			input_valid_buffer <=  'b0;
			output_valid_buffer <=  'b0;
		end
		else begin
			dec_to_neg_buffer <=  n_dec_to_neg_buffer;
			neg_to_enc_buffer <=  n_neg_to_enc_buffer;
			counter <=  n_counter;
			input_valid_buffer <=  n_input_valid_buffer;
			output_valid_buffer <=  n_output_valid_buffer;
		end
	end

endmodule