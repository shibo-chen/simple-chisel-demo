/////////////////////////////////////////////
// Modulename:                             //
//      SingleCycleTightlyCoupledNegator   //
// Description:                            //
//          Negate an unsigned integer     //
//                 to the negative         //
//                                         //
/////////////////////////////////////////////
package negator

import chisel3._
import chisel3.util._ 

class SingleCycleTightlyCoupledNegatorInterface(val INTEGER_WIDTH:Int = 64) extends Bundle{
    val input_data = Input( UInt(INTEGER_WIDTH.W) )
    val output_data = Output( UInt(INTEGER_WIDTH.W))
}
class SingleCycleTightlyCoupledNegator(val INTEGER_WIDTH:Int = 64) extends Module {

  val io = IO(new SingleCycleTightlyCoupledNegatorInterface(INTEGER_WIDTH))
  

  io.output_data := (~io.input_data) + 1.U
}
