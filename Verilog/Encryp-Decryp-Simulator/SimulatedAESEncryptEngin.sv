//////////////////////////////////////////////////
// Modulename:                                  //
//            SimulatedAESEncryptEngin          //
// Description:                                 //
//            Simulate a multi-stage encryption //
//             engine.                          //
//   We assume SBOX and key is integrated inside//
//                                              //
//////////////////////////////////////////////////

// Interface found here:
// https://github.com/secworks/aes/blob/master/src/rtl/aes_encipher_block.v 

`timescale 1ns/100ps
`define BLOCK_WIDTH 128
module SimulatedAESEncryptEngin#(
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

    logic [NUM_CYCLE-1: 0][`BLOCK_WIDTH - 1: 0] buffer;
    logic [NUM_CYCLE-1: 0] valid;

    logic [NUM_CYCLE-1: 0][`BLOCK_WIDTH - 1: 0] n_buffer;
    logic [NUM_CYCLE-1: 0] n_valid;

    // Determine what the value in next cycle would be 
    genvar i;
     generate
        for (i=1; i < NUM_CYCLE; i++) begin
            assign n_buffer[i] = buffer[i-1]; 
            assign n_valid[i] = valid[i-1];
        end
    endgenerate
    assign n_buffer[0] = block;
    assign n_valid[0] = next;

    // Assign output
    assign ready = valid[NUM_CYCLE-1];
    assign new_block = buffer[NUM_CYCLE-1];

    always_ff @(posedge clock) begin 
        if(reset) begin
            buffer <=  'b0;
            valid <=  'b0;
        end
        else begin
            buffer <=  n_buffer; 
            valid <=  n_valid;
        end
    end

endmodule