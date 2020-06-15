//////////////////////////////////////////////////
// Modulename:                                  //
//            SimulatedAESEncryptEngin          //
// Description:                                 //
//            Simulate a multi-stage encryption //
//             engine.                          //
//   We assume SBOX and key is integrated inside//
//                                              //
//////////////////////////////////////////////////

package negator

import chisel3._
import chisel3.util._ 
import freechips.rocketchip.config.Parameters

class SimulatedAESEncryptEnginInterface(implicit val p: Parameters) extends ValidInterface{
    val in = new Bundle{
        val data = UInt(128.W)
    }
    val out = new Bundle{
        val data = UInt(128.W)
    }
}


class SimulatedAESEncryptEngin(implicit val p: Parameters) extends Stage with SimulatedAESEncryptEnginInterface{
    in >>> State(latency = p(NUM_OF_CYCLES_FOR_ENC_DEC_ENGIN)) >>> out
}