/* Version 1.2 
Negator: PipelinedDecoupledNegator
Negator Bandwidth: 64
Memory Bandwidth: 64
Interface: DECOUPLED
Encryption: NO
*/

`include "negator/PipelinedDecoupledNegator.sv"


`timescale 1ns/100ps

// mem bandwidth is 64 bit, each integer is 64 bit

module Datapath_PDMP (
	input clock,
	input reset,
	input logic input_valid, // hi for input valid, lo for input not valid
	input logic [63:0] input_data,

	output logic output_valid, // hi for output valid, lo for output not valid
	output logic [63:0] output_data
);
	/* verilator lint_off UNUSED */
	logic ready_out, ready_input;
	assign ready_input = 1;
	// Connect the component to the datapath
	PipelinedDecoupledNegator #(1, 64, 4) 
	pipelinedDecoupledNegator ( clock, reset, input_valid, ready_out, input_data, output_valid,
		ready_input , output_data);
	/* verilator lint_on UNUSED */

endmodule