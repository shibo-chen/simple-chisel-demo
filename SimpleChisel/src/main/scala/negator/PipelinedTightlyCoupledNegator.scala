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
package negator

import chisel3._
import chisel3.util._ 
import freechips.rocketchip.config.Parameters

class PipelinedTightlyCoupledNegatorInterface(val WIDTH_IN_NUM_OF_FULL_INTEGER:Int,val INTEGER_WIDTH:Int ) extends Interface{
    val in = new Bundle{{
      val valid = Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, Bool())
      val data = Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W))
    }
    val out = new Bundle{{
      val valid = Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, Bool())
      val data = Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W))
    }
}

class PipelinedTightlyCoupledNegator(val WIDTH_IN_NUM_OF_FULL_INTEGER:Int,val INTEGER_WIDTH:Int )
  extends Stage with PipelinedTightlyCoupledNegatorInterface(WIDTH_IN_NUM_OF_FULL_INTEGER, INTEGER_WIDTH) {

  val input_buffer = State(new State()) 
  in >>> input_buffer

  val negated_data = State(new State())
  val negated_result = Wire( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W)) );
  Bundle{negated_result, input_buffer.valid} >>> negated_data

  val add_one = Wire( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W)) );

  for(i <- 0 until WIDTH_IN_NUM_OF_FULL_INTEGER) {
    negated_result(i) := ~input_buffer.data(i) 
    add_one(i) := negated_data.data(i) + 1;
  }

  Bundle{negated_data.valid, add_one} >>> out
}
