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

class SimulatedAESEncryptEnginInterface(implicit val p: Parameters) extends Bundle{
    val input_data = Flipped(Valid(UInt(128.W)))
    val output_data = Valid(UInt(128.W))
}


class SimulatedAESEncryptEngin(implicit val p: Parameters) extends Module{
    val io =IO(new SimulatedAESEncryptEnginInterface)


    val buffered_stage = pipe(io.input_data, p(NUM_OF_CYCLES_FOR_ENC_DEC_ENGIN))
    io.output_data <> buffered_stage
}