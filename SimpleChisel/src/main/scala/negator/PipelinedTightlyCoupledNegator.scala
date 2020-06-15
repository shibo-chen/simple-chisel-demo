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

class PipelinedTightlyCoupledNegatorInterface(implicit val p: Parameters) extends Interface{
    val in = new Bundle{{
      val valid = Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), Bool())
      val data = Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W))
    }
    val out = new Bundle{{
      val valid = Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), Bool())
      val data = Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W))
    }
}

class PipelinedTightlyCoupledNegator(implicit val p: Parameters) extends Stage with PipelinedTightlyCoupledNegatorInterface {

  val input_buffer = State(new State()) 
  in >>> input_buffer

  val negated_data = State(new State())
  val negated_result = Wire( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W)) );
  Packet{negated_result, input_buffer.valid} >>> negated_data

  val add_one = Wire( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W)) );

  for(i <- 0 until p(WIDTH_IN_NUM_OF_FULL_INTEGER)) {
    negated_result(i) := ~input_buffer.data(i) 
    add_one(i) := negated_data.data(i) + 1;
  }

  Packet{negated_data.valid, add_one} >>> out
}
