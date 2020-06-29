/////////////////////////////////////////////
// Modulename:                             //
//      PipelinedDecoupledNegator          //
// Description:                            //
//          Negate an signed integer       //
//                 to the negative         //
//                                         //
/////////////////////////////////////////////

/*
Buffer      Cycle 0         Cycle 1                 Cycle 2                         
        Input Buffer    Bit-wise negation       Add 1 to get Two's complement   
*/
`include "../util/FIFOBuffer.sv"
`timescale 1ns/100ps

module PipelinedDecoupledNegator
#(parameter WIDTH_IN_NUM_OF_FULL_INTEGER = 1,
parameter INTEGER_WIDTH = 32,
parameter SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH = 1)
(
    input clock, // System clock
    input reset, // System reset
    input logic input_valid, // Whether the input is valid
    output logic input_ready,
    input logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH - 1: 0] input_data, // The input data
    output logic output_valid, // Wether the output is valid
    input logic output_ready,
    output logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH-1: 0] output_data// The output data

);

    logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH-1: 0] input_buffer;
    logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH-1: 0] data_queue_output;
    logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH-1: 0] n_input_buffer;
    logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH-1: 0] negated_data;
    logic [WIDTH_IN_NUM_OF_FULL_INTEGER - 1:0][INTEGER_WIDTH-1: 0] n_negated_data;

    logic [1 : 0] valid;
    logic [1 : 0] n_valid;

    logic  validity_queue_output;
	/* verilator lint_off UNUSED */
    logic data_queue_empty, validity_queue_full;
	/* verilator lint_on UNUSED */

    logic queue_read, queue_write, queue_enable, data_queue_full, validity_queue_empty;
    assign queue_enable = 1;
    /**
    We need to first create two fifo queues, one for data and one for validity
    **/
    FIFOBuffer #(.WIDTH_IN_NUM_OF_FULL_DATA(WIDTH_IN_NUM_OF_FULL_INTEGER),
    .DATA_WIDTH(INTEGER_WIDTH),
    .SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH(SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH ))
    fifobuffer_for_data( clock, reset, input_data, 
    queue_read, 
    queue_write,
    queue_enable, 
    data_queue_output, 
    data_queue_empty, 
    data_queue_full); 

    FIFOBuffer #(.WIDTH_IN_NUM_OF_FULL_DATA(1),
    .DATA_WIDTH(1),
    .SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH(SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH ))
    fifobuffer_for_validity( clock, reset, input_valid, 
    queue_read, 
    queue_write,
    queue_enable, 
    validity_queue_output, 
    validity_queue_empty, 
    validity_queue_full); 

    /****************************/
    assign queue_read = ((output_ready) & (!validity_queue_empty)); // When the downstream is ready and data_queue is not empty, we can pop one out
    assign queue_write = (input_valid != 'b0); //If the upstream input is valid, we can push one



    // Determine what the value in next cycle would be 
    assign n_valid[1] = output_ready? valid[0] : valid[1];
    assign n_valid[0] = output_ready? ( validity_queue_empty? 'b0: validity_queue_output)
                                : valid[0];
    assign n_input_buffer = output_ready? data_queue_output : input_buffer;

    // Assign output

    always_ff@(posedge clock) begin 
        if(reset) begin
            input_buffer <=  'b0;
            negated_data <=  'b0;
            valid <=  'b0;
        end
        else begin
            input_buffer <=  n_input_buffer; // store the input into buffer for 1 cycle
            negated_data <=  n_negated_data; // Store the unsigned int that has been negated
            valid[1] <=  n_valid[1];
            valid[0] <=  n_valid[0];
        end
    end

    genvar i;
    generate
        for (i=0; i < WIDTH_IN_NUM_OF_FULL_INTEGER; i++) begin // Generate WIDTH_IN_NUM_OF_FULL_INTEGER inverter
            assign n_negated_data[i] 
                    = output_ready? ~input_buffer[i] : negated_data[i]; // In the first stage, we negate it
            assign output_data[i] 
                    = negated_data[i] + 1; // In the second stage, we add 1 to it
        end
    endgenerate

    // Assign outputs
    assign input_ready = !data_queue_full; // We can take in new input if the data queue is not full
    assign output_valid = valid[1];

endmodule