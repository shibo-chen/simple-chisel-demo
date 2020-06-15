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

class PipelinedTightlyCoupledNegatorInterface(implicit val p: Parameters) extends Bundle{
    val input_valid = Input(  Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), Bool()) )
    val input_data = Input( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W)) )
    val output_data = Output( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W)) )
    val output_valid = Input(  Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), Bool()) )
}

class PipelinedTightlyCoupledNegator(implicit val p: Parameters) extends Module {

  val io = IO(new PipelinedTightlyCoupledNegatorInterface)

  val input_buffer  = RegNext(io.input_data)

  val n_negated_data = Wire(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W));
  val negated_data = RegNext(n_negated_data);

  val n_valid = Vec(2, Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), Bool()));
  val valid = RegNext(n_valid);

  n_valid := Cat(valid(0), input_valid)
  for(i <- 0 until p(WIDTH_IN_NUM_OF_FULL_INTEGER)) {
    n_negated_data(i) := ~input_buffer(i) 
    io.output_data(i) := negated_data(i) + 1;
  }
}
