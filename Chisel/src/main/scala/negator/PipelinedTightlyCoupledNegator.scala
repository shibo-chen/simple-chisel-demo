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

class PipelinedTightlyCoupledNegatorInterface(val WIDTH_IN_NUM_OF_FULL_INTEGER = 1, val INTEGER_WIDTH = 64)(implicit val p: Parameters) extends Bundle{
    val input_data = Flipped(Valid( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W)) ))
    val output_data = Valid( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W)) )
}

class PipelinedTightlyCoupledNegator(implicit val p: Parameters) extends Module {

  val io = IO(new PipelinedTightlyCoupledNegatorInterface)

  val input_buffer  = RegNext(io.input_data.bits)

  val n_negated_data = Wire(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W));
  val negated_data = RegNext(n_negated_data);

  val n_valid = Vec(2,Bool())
  val valid = RegNext(n_valid)

  io.output_data.valid := valid(1)

  n_valid := Cat(valid(0), io.input_data.valid)
  for(i <- 0 until WIDTH_IN_NUM_OF_FULL_INTEGER) {
    n_negated_data(i) := ~input_buffer(i) 
    io.output_data.bits(i) := negated_data(i) + 1.U
  }
}
