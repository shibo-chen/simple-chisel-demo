/* Version 1.2
Negator: PipelinedTightlyCoupledNegator
Negator Bandwidth: 64
Memory Bandwidth: 64
Interface: TIGHTLY_COUPLED
Encryption: NO
*/
`include "negator/PipelinedTightlyCoupledNegator.sv"

`timescale 1ns/100ps

// mem bandwidth is 64 bit, each integer is 64 bit

module Datapath_PTMP (
	input clock,
	input reset,
	input logic input_valid, // hi for input valid, lo for input not valid
	input logic [63:0] input_data,

	output logic output_valid, // hi for output valid, lo for output not valid
	output logic [63:0] output_data
);


	PipelinedTightlyCoupledNegator #(1, 64) 
	pipelinedTightlyCoupledNegator( clock, reset, input_valid, input_data, output_valid, output_data);

endmodule