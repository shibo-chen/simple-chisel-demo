/////////////////////////////////////////////
// Modulename:                             //
//      SingleCycleTightlyCoupledNegator   //
// Description:                            //
//          Negate an unsigned integer     //
//                 to the negative         //
//         Combinational Logic only        //
/////////////////////////////////////////////
`timescale 1ns/100ps
`define SD #1

module SingleCycleTightlyCoupledNegator
#(parameter WIDTH_IN_NUM_OF_FULL_INTEGER = 1, 
parameter INTEGER_WIDTH = 32)
(
    input logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH - 1: 0] input_data, // The input data
    output logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH - 1: 0] output_data // The output data
);

    genvar i;
     generate
        for (i=0; i < WIDTH_IN_NUM_OF_FULL_INTEGER; i++) begin // Generate WIDTH_IN_NUM_OF_FULL_INTEGER inverter
            assign output_data[i] 
                    = (~input_data[i]) + 1; // First we negate it, and then add one to it
        end
    endgenerate

endmodule