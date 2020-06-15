//////////////////////////////////////////////////
// Modulename:                                  //
//            SimulatedAESDecryptEngin          //
// Description:                                 //
//            Simulate a multi-stage decryption //
//             engine.                          //
//   We assume SBOX and key is integrated inside//
//                                              //
//////////////////////////////////////////////////

// Interface found here:
// https://github.com/secworks/aes/blob/master/src/rtl/aes_encipher_block.v 

`timescale 1ns/100ps
`define SD #1
`define BLOCK_WIDTH 128
module SimulatedAESDecryptEngin#(
    parameter NUM_CYCLE = 4
)
(
        input          clock,
        input          reset,

        input          next,
        input logic [`BLOCK_WIDTH -1 : 0]  block,
        output         ready,
        output logic [`BLOCK_WIDTH -1 : 0] new_block
        );

    logic [`BLOCK_WIDTH*NUM_CYCLE-1: 0] buffer;
    logic [NUM_CYCLE-1: 0] valid;

    logic [`BLOCK_WIDTH*NUM_CYCLE-1: 0] n_buffer;
    logic [NUM_CYCLE-1: 0] n_valid;

    // Determine what the value in next cycle would be 
    assign n_buffer = {buffer[`BLOCK_WIDTH*NUM_CYCLE-1: `BLOCK_WIDTH], block}; // Shift it regardless of whether next signal is hi
    assign n_valid = {valid[NUM_CYCLE-1: 1], next};

    // Assign output
    assign ready = valid[NUM_CYCLE-1];
    assign new_block = buffer[`BLOCK_WIDTH*NUM_CYCLE-1: `BLOCK_WIDTH*(NUM_CYCLE-1)];

    always_ff(@posedge clock) begin 
        if(reset) begin
            buffer <= `SD 'b0;
            valid <= `SD 'b0;
        end
        else begin
            buffer <= `SD n_buffer; 
            valid <= `SD n_valid;
        end
    end

endmodule