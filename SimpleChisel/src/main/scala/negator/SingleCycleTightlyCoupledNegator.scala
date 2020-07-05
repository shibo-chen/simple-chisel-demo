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


class SingleCycleTightlyCoupledNegatorInterface(val WIDTH_IN_NUM_OF_FULL_INTEGER:Int,val INTEGER_WIDTH:Int ) extends Interface{
    val in = new Bundle{{
      val data = Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W))
    }
    val out = {
      val data = Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W))
    }
}
class SingleCycleTightlyCoupledNegator(val WIDTH_IN_NUM_OF_FULL_INTEGER:Int,val INTEGER_WIDTH:Int )
  extends Stage with SingleCycleTightlyCoupledNegatorInterface(WIDTH_IN_NUM_OF_FULL_INTEGER, INTEGER_WIDTH) {
  
  val input_buffer = State(new State()) 
  in >>> input_buffer

  for(i <- 0 until WIDTH_IN_NUM_OF_FULL_INTEGER)
    out.data(i) := (~input_buffer.data(i)) + 1;
}
