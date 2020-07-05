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

class SimulatedAESDecryptEnginInterface extends Bundle{
    val input_data = Flipped(Valid(UInt(128.W)))
    val output_data = Valid(UInt(128.W))
}

class SimulatedAESDecryptEngin(val NUM_OF_CYCLES_FOR_ENC_DEC_ENGIN:Int = 4) extends Module{
    val io =IO(new SimulatedAESDecryptEnginInterface)

    val buffered_stage = Pipe(io.input_data, NUM_OF_CYCLES_FOR_ENC_DEC_ENGIN)
    io.output_data <> buffered_stage
}