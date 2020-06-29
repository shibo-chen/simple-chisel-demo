/* Version 1.2 
Negator: PipelinedDecoupledNegator
Negator Bandwidth: 32
Memory Bandwidth: 64
Interface: DECOUPLED
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

class Datapath_PDUP extends Module and DatapathInterface{	
	val pipelinedDeoupledNegator = Module(new PipelinedDeoupledNegator(1, 32) )

     in >>> pipelinedTightlyCoupledNegator >>> out
}