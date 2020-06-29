/* Version 1.2 
Negator: SingleCycleTightlyCoupledNegator
Negator Bandwidth: 64
Memory Bandwidth: 64
Interface: TIGHTLY_COUPLED
Encryption: NO
*/

package negator

import chisel3._
import chisel3.util._ 
import freechips.rocketchip.config.Parameters

class DatapathInterface extends Bundle{
    val input_data = Flipped(Valid(UInt(64.W)))
    val output_data = Valid(UInt(64.W)
}


class Datapath_STMP extends Module{
    val io = IO(new DatapathInterface)

    val buffer_valid = RegNext(io.input_data.valid)
    val data_buffer = RegNext(io.input_data.bits)

    val singleCycleTightlyCoupledNegator = Module( new SingleCycleTightlyCoupledNegator(1, 64))
    io.io.output_data.valid := buffer_valid
    io.output_data.bits := singleCycleTightlyCoupledNegator.io.output_data
    singleCycleTightlyCoupledNegator.io.output_data.bits := data_buffer
}