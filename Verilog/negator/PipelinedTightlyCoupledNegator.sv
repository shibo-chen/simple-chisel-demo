/////////////////////////////////////////////
// Modulename:                             //
//      PipelinedTightlyCoupledNegator     //
// Description:                            //
//          Negate an signed integer       //
//                 to the negative         //
//                                         //
/////////////////////////////////////////////

/*
Cycle 0         Cycle 1                 Cycle 2 
Input Buffer    Bit-wise negation       Add 1 to get Two's complement   
*/

`timescale 1ns/100ps
`define SD #1

module PipelinedTightlyCoupledNegator
#(parameter WIDTH_IN_NUM_OF_FULL_INTEGER = 1,
parameter INTEGER_WIDTH = 32)
(
    input clock, // System clock
    input reset, // System reset
    input logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1: 0] input_valid, // Whether the input is valid
    input logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH - 1: 0] input_data, // The input data
    output logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1: 0] output_valid, // Wether the output is valid
    output logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH - 1: 0] output_data// The output data
);

    logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH - 1: 0] input_buffer;
    logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH - 1: 0] negated_data;
    logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH - 1: 0] n_negated_data;

    logic [1:0][WIDTH_IN_NUM_OF_FULL_INTEGER - 1: 0] valid;
    logic [1:0][WIDTH_IN_NUM_OF_FULL_INTEGER - 1: 0] n_valid;

    // Determine what the value in next cycle would be 
    assign n_valid = {valid[0], input_valid};
    
    // Assign output
    assign output_valid = valid[1];

    always_ff(@posedge clock) begin 
        if(reset) begin
            input_buffer <= `SD 'b0;
            negated_data <= `SD 'b0;
            valid <= `SD 'b0;
        end
        else begin
            input_buffer <= `SD input_data; // store the input into buffer for 1 cycle
            negated_data <= `SD n_negated_data; // Store the unsigned int that has been negated
            valid <= `SD n_valid;
        end
    end

    genvar i;
    generate
        for (i=0; i < WIDTH_IN_NUM_OF_FULL_INTEGER; i++) begin // Generate WIDTH_IN_NUM_OF_FULL_INTEGER inverter
            assign n_negated_data[i] 
                    = ~input_buffer[i]; // In the first stage, we negate it
            assign output_data[i] 
                    = negated_data[i] + 1; // In the second stage, we add 1 to it
        end
    endgenerate
    
endmodule