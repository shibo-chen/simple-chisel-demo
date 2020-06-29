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
    val input_data = Flipped(Valid(UInt(64.W)))
    val output_data = Valid(UInt(64.W)
}

class Datapath_STUP extends Module{
    val io = IO(new DatapathInterface)

    val n_counter = Wire(UInt(1.W))
    val counter = RegNext(n_counter)

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


	// Connect the component to the datapath
    val singleCycleTightlyCoupledNegator = Module( new SingleCycleTightlyCoupledNegator(1, 32))
    
    singleCycleTightlyCoupledNegator.io.input_data := input_to_negator
    output_from_negator := singleCycleTightlyCoupledNegator.io.output_data

	io.output_data.valid := output_valid_buffer
	io.output_data.bits := output_buffer


    when(!input_valid_buffer) {
        when(io.input_data.valid) {
            n_input_valid_buffer := 1.U
            n_input_buffer := io.input_data.bits
            n_output_valid_buffer := 0.U
            n_counter := 0.U
            input_to_negator := 0.U
            n_output_buffer := 0.U
        }
        .otherwise {
            n_input_valid_buffer := 0.U
            n_input_buffer := 0.U
            n_output_valid_buffer := 0.U
            n_counter := 0.U
            input_to_negator := 0.U
            n_output_buffer := 0.U
        }
    }
    .whenelse(counter === 0.U) {
        n_input_valid_buffer := 1
        n_input_buffer := input_buffer
        n_output_valid_buffer := 0.U
        n_counter := 1
        input_to_negator := input_buffer(31:0)
        n_output_buffer(63:32) := 0.U
        n_output_buffer(31:0) := output_from_negator
    }
    .otherwise {
        n_input_valid_buffer := 0.U
        n_input_buffer := 0.U
        n_output_valid_buffer := 1.U
        n_counter := 0.U
        input_to_negator := input_buffer(63:32)
        n_output_buffer(63:32) := output_from_negator
        n_output_buffer(31:0) := output_buffer(31:0)		
    }


}