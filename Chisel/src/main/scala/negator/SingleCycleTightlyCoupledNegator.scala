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


class SingleCycleTightlyCoupledNegatorInterface(implicit val p: Parameters) extends Bundle{
    val input_data = Input( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W)) )
    val output_data = Output( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W)) )
}
class SingleCycleTightlyCoupledNegator(implicit val p: Parameters) extends Module {

  val io = IO(new SingleCycleTightlyCoupledNegatorInterface)
  
  val input_buffer  = RegNext(io.input_data)

  for(i <- 0 until p(WIDTH_IN_NUM_OF_FULL_INTEGER)) 
    io.output_data(i) := (~input_buffer(i)) + 1;
}
