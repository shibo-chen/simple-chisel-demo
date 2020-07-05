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

class SimulatedAESEncryptEnginInterface extends Bundle{
    val input_data = Flipped(Valid(UInt(128.W)))
    val output_data = Valid(UInt(128.W))
}


class SimulatedAESEncryptEngin(val NUM_OF_CYCLES_FOR_ENC_DEC_ENGIN:Int = 4) extends Module{
    val io =IO(new SimulatedAESEncryptEnginInterface)


    val buffered_stage = Pipe(io.input_data, NUM_OF_CYCLES_FOR_ENC_DEC_ENGIN)
    io.output_data <> buffered_stage
}