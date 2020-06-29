/* Version 1.2 
Negator: SingleCycleTightlyCoupledNegator
Negator Bandwidth: 64
Memory Bandwidth: 64
Interface: TIGHTLY_COUPLED
Encryption: NO
*/
`include "negator/SingleCycleTightlyCoupledNegator.sv"

`timescale 1ns/100ps

// mem bandwidth is 64 bit, each integer is 64 bit

module Datapath_STMP (
	input clock,
	input reset,
	input logic input_valid, // hi for input valid, lo for input not valid
	input logic [63:0] input_data,

	output logic output_valid, // hi for output valid, lo for output not valid
	output logic [63:0] output_data
);

	logic buffer_valid;
	logic [63:0] data_buffer;

	// Connect the component to the datapath
	SingleCycleTightlyCoupledNegator #(1, 64)  singleCycleTightlyCoupledNegator( data_buffer, output_data);

	//assign output
	assign output_valid = buffer_valid;

    always_ff @(posedge clock) begin 
		if(reset) begin
			data_buffer <=  'b0;
			buffer_valid <=  'b0;
		end
		else begin
			data_buffer <=  input_data;
			buffer_valid <=  input_valid;
		end
	end

endmodule