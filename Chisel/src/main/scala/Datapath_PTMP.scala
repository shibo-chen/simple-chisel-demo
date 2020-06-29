/* Version 1.2
Negator: PipelinedTightlyCoupledNegator
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

class Datapath_PTMP extends Module{
    val io = IO(new DatapathInterface)

	val pipelinedTightlyCoupledNegator = Module(new PipelinedTightlyCoupledNegator(1, 64) )
	io.input_data <> pipelinedTightlyCoupledNegator.io.input_data
    io.output_data <> pipelinedTightlyCoupledNegator.io.output_data
}