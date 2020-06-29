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
    val input_data = Flipped(Valid(UInt(64.W)))
    val output_data = Valid(UInt(64.W)
}

class Datapath_PDUP extends Module{
    val io = IO(new DatapathInterface)

    val n_input_counter = Wire(UInt(1.W))
    val input_counter = RegNext(n_input_counter)

    val n_output_counter = Wire(UInt(1.W))
    val output_counter = RegNext(n_output_counter)

	val n_input_valid_buffer = Wire(UInt(1.W))
    val input_valid_buffer = RegNext(n_input_valid_buffer)

    val n_output_valid_buffer = Wire(UInt(1.W))
	val output_valid_buffer = RegNext(n_output_valid_buffer)

    val n_input_buffer = Wire(UInt(64.W))
	val input_buffer = RegNext(n_input_buffer)


	val n_output_buffer = Wire(UInt(64.W))
	val output_buffer = RegNext(n_output_buffer)

	val input_to_negator = Wire(UInt(32.W))
	val output_from_negator = Wire(UInt(32.W))

	val valid_input_to_negator = Wire(UInt(1.W))
    val valid_output_from_negator = Wire(UInt(1.W))

	val pipelinedDecoupledNegator = Module(new PipelinedDecoupledNegator(1, 32))
    val output_ready = Wire(Bool)

	pipelinedDecoupledNegator.io.input_data.valid := valid_input_to_negator
    pipelinedDecoupledNegator.io.input_data.bits := input_to_negator
    output_from_negator := pipelinedDecoupledNegator.io.output_data.bits
    valid_output_from_negator := pipelinedDecoupledNegator.io.output_data.valid
    output_ready := pipelinedDecoupledNegator.io.input_data.output_ready
    pipelinedDecoupledNegator.io.output_data.ready := true.B
    
    io.output_data.bits := output_buffer
    io.output_data.valid := output_valid_buffer

    when(!input_valid_buffer) {
        when(io.input_data.valid) {
            n_input_valid_buffer = 1.U
            n_input_buffer = io.input_data.bits
            n_input_counter = 0.U
            input_to_negator = 0.U
            valid_input_to_negator = 0.U
        }
        .otherwise {
            n_input_valid_buffer = 0.U
            n_input_buffer = io.input_data.bits
            n_input_counter = 0.U
            input_to_negator = 0.U
            valid_input_to_negator = 0.U
        }
    }
    .elsewhen(input_counter === 0.U) {
        n_input_valid_buffer = 1.U
        n_input_buffer = input_buffer
        n_input_counter = 1.U
        input_to_negator = input_buffer(31:0)
        valid_input_to_negator = 1.U
    }
    .whenelse {
        n_input_valid_buffer = 0.U
        n_input_buffer = 0.U
        n_input_counter = 0.U
        input_to_negator = input_buffer(63:32)
        valid_input_to_negator = 1.U
    }

    when(!output_valid_buffer) {
        when(valid_output_from_negator) {
            when(output_counter) {
                n_output_valid_buffer = 1
                n_output_buffer = Cat(output_from_negator,output_buffer(31:0))
                n_output_counter = 0.U
            }
            .otherwise {
                n_output_valid_buffer = 0.U
                n_output_buffer = Cat(0.U(32.W), output_from_negator)
                n_output_counter = 1.U
            }
        }
        .otherwise {
            n_output_valid_buffer = output_valid_buffer
            n_output_buffer = output_buffer
            n_output_counter = output_counter
        }
    }
    .otherwise {
        n_output_valid_buffer = 0.U
        n_output_buffer = 0.U
        n_output_counter = 0.U			
    }

}