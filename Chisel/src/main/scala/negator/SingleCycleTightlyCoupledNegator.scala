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
import freechips.rocketchip.config.Parameters


class SingleCycleTightlyCoupledNegatorInterface(val WIDTH_IN_NUM_OF_FULL_INTEGER = 1, val INTEGER_WIDTH = 64)(implicit val p: Parameters) extends Bundle{
    val input_data = Input( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W)) )
    val output_data = Output( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W)) )
}
class SingleCycleTightlyCoupledNegator(implicit val p: Parameters) extends Module {

  val io = IO(new SingleCycleTightlyCoupledNegatorInterface)
  

  for(i <- 0 until WIDTH_IN_NUM_OF_FULL_INTEGER) 
    io.output_data(i) := (~io.input_data(i)) + 1.U
}
