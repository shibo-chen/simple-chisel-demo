//////////////////////////////////////////////////
// Modulename:                                  //
//            SimulatedAESDecryptEngin          //
// Description:                                 //
//            Simulate a multi-stage decryption //
//             engine.                          //
//   We assume SBOX and key is integrated inside//
//                                              //
//////////////////////////////////////////////////

package negator

import chisel3._
import chisel3.util._ 
import freechips.rocketchip.config.Parameters

class SimulatedAESDecryptEnginInterface(implicit val p: Parameters) extends ValidInterface{
    val in = new Bundle{
        val data = UInt(128.W)
    }
    val out = new Bundle{
        val data = UInt(128.W)
    }
}


class SimulatedAESDecryptEngin(implicit val p: Parameters) extends Stage with SimulatedAESDecryptEnginInterface{
    in >>> State(latency = p(NUM_OF_CYCLES_FOR_ENC_DEC_ENGIN)) >>> out
}