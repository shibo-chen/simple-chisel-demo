/* Version 1.2 
Negator: PipelinedTightlyCoupledNegator
Negator Bandwidth: 64
Memory Bandwidth: 64
Interface: TIGHTLY_COUPLED
Encryption: YES
*/

package negator

import chisel3._
import chisel3.util._ 
import freechips.rocketchip.config.Parameters

class DatapathInterface extends Bundle{
    val in = new Bundle{
        Valid(UInt(64.W)
    }
    val out = new Bundle{
        Valid(UInt(64.W)
    }
}

class Datapath_PTME extends Module and DatapathInterface{	
    val simulatedAESDecryptEngin  = Module(new SimulatedAESDecryptEngin)
    val simulatedAESEncryptEngin  = Module(new SimulatedAESEncryptEngin)	
	val pipelinedTightlycoupledNegator = Module(new PipelinedTightlycoupledNegator(1, 64) )

     in >>> simulatedAESDecryptEngin >>> pipelinedTightlycoupledNegator >>> 
                simulatedAESEncryptEngin >>> out
}