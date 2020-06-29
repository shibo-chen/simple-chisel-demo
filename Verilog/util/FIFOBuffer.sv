/////////////////////////////////////////////
// Modulename:                             //
//      FIFOBuffer                         //
// Description:                            //
//          First In First Out Buffer      //
//                                         //
//                                         //
/////////////////////////////////////////////

`timescale 1ns/100ps

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
    output logic full
); 

logic [$clog2(SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH):0]  Count; 
logic [SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH : 0][WIDTH_IN_NUM_OF_FULL_DATA*DATA_WIDTH-1:0] FIFO; 
logic [$clog2(SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH):0]  readCounter, 
           writeCounter; 

logic [$clog2(SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH):0]  n_readCounter, 
           n_writeCounter; 

assign empty = (Count==0)? 1'b1:1'b0; 

assign full = (Count==SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH)? 1'b1:1'b0; 
assign data_out = FIFO[readCounter]; 

always_comb begin
    if(read ==1'b1 && Count!=0) begin
        n_readCounter = (readCounter == SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH)?0:readCounter+1;
    end
    else begin
        n_readCounter = readCounter;
    end

    if(write==1'b1 && Count<SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH) begin
        n_writeCounter = (writeCounter == SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH)? 0: writeCounter+1; 
    end
    else begin
        n_writeCounter = writeCounter; 
    end

end

always_ff@(posedge clock) begin 
 if (enable==0); 
 else begin 
  if (reset) begin 
   readCounter <= 0; 
   writeCounter <= 0; 
   FIFO <= 0;
  end 
  else  begin 
      readCounter <= n_readCounter;
      writeCounter <= n_writeCounter;
      if (write==1'b1 && Count<SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH)
        FIFO[writeCounter]  <= data_in; 
  end
 end 

 if (n_readCounter > n_writeCounter) begin 
     if(n_writeCounter == 0 && writeCounter == SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH)
        Count<=SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH - n_readCounter; 
     else 
        Count<=n_readCounter-n_writeCounter; 
 end 
 else if (n_writeCounter > n_readCounter) 
  Count<=n_writeCounter-n_readCounter; 
 else
    Count <= 0;
end 

endmodule
