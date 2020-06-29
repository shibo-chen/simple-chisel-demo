/* Version 1.2 
Negator: SingleCycleTightlyCoupledNegator
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
        val input_data = Valid(UInt(64.W)
    }
    val out = new Bundle{
        val output_data = Valid(UInt(64.W)
    }
}

class Datapath_STME extends Module and DatapathInterface{	
    val simulatedAESDecryptEngin  = Module(new SimulatedAESDecryptEngin)
    val simulatedAESEncryptEngin  = Module(new SimulatedAESEncryptEngin)	
	val singleCycleTightlyCoupledNegator = Module(new SingleCycleTightlyCoupledNegator(1, 64) )

     in >>> simulatedAESDecryptEngin >>> singleCycleTightlyCoupledNegator >>> 
                simulatedAESEncryptEngin >>> out
}