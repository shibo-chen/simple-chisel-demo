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


class SingleCycleTightlyCoupledNegatorInterface(implicit val p: Parameters) extends Interface{
    val in = new Bundle{{
      val data = Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W))
    }
    val out = {
      val data = Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W))
    }
}
class SingleCycleTightlyCoupledNegator(implicit val p: Parameters) extends Stage with SingleCycleTightlyCoupledNegatorInterface {
  
  val input_buffer = State(new State()) 
  in >>> input_buffer

  for(i <- 0 until p(WIDTH_IN_NUM_OF_FULL_INTEGER)) 
    out.data(i) := (~input_buffer.data(i)) + 1;
}
