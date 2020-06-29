/* Version 1.2 
Negator: SingleCycleTightlyCoupledNegator
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
        Valid(UInt(64.W)
    }
    val out = new Bundle{
        Valid(UInt(64.W)
    }
}

class Datapath_STUP extends Module and DatapathInterface{	
	
	val singleCycleTightlyCoupledNegator = Module(new SingleCycleTightlyCoupledNegator(1, 32) )

     in >>> singleCycleTightlyCoupledNegator >>> out
}