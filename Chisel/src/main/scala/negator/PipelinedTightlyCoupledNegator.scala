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

class PipelinedTightlyCoupledNegatorInterface(val INTEGER_WIDTH:Int = 64) extends Bundle{
    val input_data = Flipped(Valid( UInt(INTEGER_WIDTH.W) ))
    val output_data = Valid( UInt(INTEGER_WIDTH.W) )
}

class PipelinedTightlyCoupledNegator(val INTEGER_WIDTH:Int = 64) extends Module {

  val io = IO(new PipelinedTightlyCoupledNegatorInterface(INTEGER_WIDTH))

  val input_buffer  = RegNext(io.input_data.bits)

  val n_negated_data = Wire(UInt(INTEGER_WIDTH.W))
  val negated_data = RegNext(n_negated_data)

  val n_valid = Vec(2,Bool())
  val valid = RegNext(n_valid)

  io.output_data.valid := valid(1)

  n_valid := Cat(valid(0), io.input_data.valid)
  n_negated_data := ~input_buffer 
  io.output_data.bits:= negated_data + 1.U
}
