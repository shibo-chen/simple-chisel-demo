/* Version 1.2 
Negator: PipelinedTightlyCoupledNegator
Negator Bandwidth: 32
Memory Bandwidth: 64
Interface: TIGHTLY_COUPLED
Encryption: NO
*/
package negator

import chisel3._
import chisel3.util._ 
import freechips.rocketchip.config.Parameters

class DatapathInterface extends Bundle{
    val in = new Bundle{
        val input_data = Valid(UInt(64.W)
    }
    val out = new Bundle{
        val output_data = Valid(UInt(64.W)
    }
}

class Datapath_PTUP extends Module and DatapathInterface{	
	val pipelinedTightlycoupledNegator = Module(new PipelinedTightlycoupledNegator(1, 32) )

     in >>> pipelinedTightlycoupledNegator >>>  out
}