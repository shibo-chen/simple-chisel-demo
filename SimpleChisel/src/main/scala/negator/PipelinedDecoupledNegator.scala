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
package negator

import chisel3._
import chisel3.util._ 
import freechips.rocketchip.config.Parameters

class PipelinedDecoupledNegatorInterface(val WIDTH_IN_NUM_OF_FULL_INTEGER:Int,val INTEGER_WIDTH:Int )(val prependFIFOSize: Int) extends DecoupledInterface(prependFIFOSize){
    val in = new Bundle{
      val valid = Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, Bool())
      val data = Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W))
    }
    val out = new Bundle{
      val valid = Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, Bool())
      val data = Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W))
    }
}

class PipelinedDecoupledNegator(val WIDTH_IN_NUM_OF_FULL_INTEGER:Int,val INTEGER_WIDTH:Int )(val prependFIFOSize: Int = 1)
  extends Stage with PipelinedDecoupledNegatorInterface(WIDTH_IN_NUM_OF_FULL_INTEGER, INTEGER_WIDTH)(prependFIFOSize){

  val input_buffer = State(new State(stall = ~out.ctrl.ready)) 
  in >>> input_buffer

  val negated_data = State(new State(stall = ~out.ctrl.ready))
  val negated_result = Wire( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W)) );
  Bundle{negated_result, input_buffer.valid} >>> negated_data

  val add_one = Wire( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(INTEGER_WIDTH.W)) );

  for(i <- 0 until WIDTH_IN_NUM_OF_FULL_INTEGER) {
    negated_result(i) := ~input_buffer.data(i) 
    add_one(i) := negated_data.data(i) + 1;
  }

  Bundle{negated_data.valid, add_one} >>> out
}
