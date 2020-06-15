/////////////////////////////////////////////
// Modulename:                             //
//      FIFOBuffer                         //
// Description:                            //
//          First In First Out Buffer      //
//                                         //
//                                         //
/////////////////////////////////////////////

`timescale 1ns/100ps
`define SD #1

module FIFOBuffer
#(parameter WIDTH_IN_NUM_OF_FULL_DATA = 1,
parameter DATA_WIDTH = 32,
parameter SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH = 1)
( 
    input clock, 
    input reset,
    input logic[WIDTH_IN_NUM_OF_FULL_DATA*DATA_WIDTH-1: 0] data_in, 
    input logic read, 
    input logic write,
    input logic enable, 
    output logic[WIDTH_IN_NUM_OF_FULL_DATA*DATA_WIDTH-1: 0] data_out, 
    output logic empty, 
    output logic full); 

logic [$clog2(SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH):0]  Count; 
logic [SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH : 0][WIDTH_IN_NUM_OF_FULL_DATA*DATA_WIDTH-1:0] FIFO; 
logic [$clog2(SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH):0]  readCounter, 
           writeCounter; 

assign empty = (Count==0)? 1'b1:1'b0; 
assign full = (Count==DATA_WIDTH)? 1'b1:1'b0; 

always_ff(@posedge clock) begin 
 if (enable==0); 
 else begin 
  if (reset) begin 
   readCounter = 0; 
   writeCounter = 0; 
  end 
  else if (read ==1'b1 && Count!=0) begin 
   dataOut  = FIFO[readCounter]; 
   readCounter = readCounter+1; 
  end 
  else if (write==1'b1 && Count<DATA_WIDTH) begin
   FIFO[writeCounter]  = data_in; 
   writeCounter  = writeCounter+1; 
  end 
  else; 
 end 
 if (writeCounter == SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH) 
    writeCounter=0; 
 else if (readCounter == SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH) 
  readCounter=0; 
 else;
 if (readCounter > writeCounter) begin 
  Count=readCounter-writeCounter; 
 end 
 else if (writeCounter > readCounter) 
  Count=writeCounter-readCounter; 
 else;
end 

endmodule
