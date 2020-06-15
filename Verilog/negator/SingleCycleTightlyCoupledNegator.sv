/////////////////////////////////////////////
// Modulename:                             //
//      SingleCycleTightlyCoupledNegator   //
// Description:                            //
//          Negate an unsigned integer     //
//                 to the negative         //
//                                         //
/////////////////////////////////////////////
`timescale 1ns/100ps
`define SD #1

module SingleCycleTightlyCoupledNegator
#(parameter WIDTH_IN_NUM_OF_FULL_INTEGER = 1, 
parameter INTEGER_WIDTH = 32)
(
    input clock, // System clock
    input reset, // System reset
    input logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH - 1: 0] input_data, // The input data
    output logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH - 1: 0] output_data // The output data
);
    logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH - 1, 0] input_buffer;

    always_ff(@posedge clock) begin // store the input into buffer for 1 cycle
        if(reset) begin
            input_buffer <= `SD 'b0;
        end
        else begin
            input_buffer <= `SD input_data;
        end
    end

    genvar i;
     generate
        for (i=0; i < WIDTH_IN_NUM_OF_FULL_INTEGER; i++) begin // Generate WIDTH_IN_NUM_OF_FULL_INTEGER inverter
            assign output_data[i] 
                    = (~input_buffer[i]) + 1; // First we negate it, and then add one to it
        end
    endgenerate

endmodule