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
    val input_data = Flipped(Valid(UInt(64.W)))
    val output_data = Valid(UInt(64.W)
}


class Datapath_STME extends Module{
    val io = IO(new DatapathInterface)

    val n_next_to_encrypt = Wire(UInt(1.W))
	val next_to_decrypt = RegNext(n_next_to_decrypt)
	val ready_from_encrypt = Wire(UInt(1.W)) 
    val ready_from_decrypt = Wire(UInt(1.W)) 
    
    val n_input_counter = Wire(UInt(1.W))
	val input_counter = RegNext(n_input_counter)
    val n_output_counter = Wire(Vec(2,UInt(1.W)))
	val output_counter = RegNext(n_output_counter)

	val n_input_buffer = Wire(UInt(128.W))
    val input_buffer = RegNext(n_input_buffer)

	val n_output_buffer = Wire(UInt(128.W))
    val output_buffer = RegNext(n_output_buffer)

	val input_to_encrypt = Wire(UInt(128.W))
	val input_to_decrypt = Wire(UInt(128.W))
	val output_from_encrypt = Wire(UInt(128.W))
	val output_from_decrypt = Wire(UInt(128.W))
	
    val simulatedAESDecryptEngin  = Module(new SimulatedAESDecryptEngin)
    val simulatedAESEncryptEngin  = Module(new SimulatedAESEncryptEngin)	

    simulatedAESDecryptEngin.io.input_data.valid := next_input_to_decrypt
    simulatedAESDecryptEngin.io.input_data.bits := input_to_decryp
    ready_from_decrypt := simulatedAESDecryptEngin.io.output_data.valid
    output_from_encrypt := simulatedAESEncryptEngin.io.output_data.bits

    simulatedAESEncryptEngin.io.input_data.valid := next_input_to_encrypt
    simulatedAESEncryptEngin.io.input_data.bits :=  input_to_encrypt
	ready_from_encrypt := simulatedAESEncryptEngin.io.output_data.valid
    output_from_decrypt := simulatedAESDecryptEngin.io.output_data.bits

	// interface between in and dec
	input_to_decrypt := input_buffer

    when(io.input_data.valid) {
        when(input_counter) {
            n_input_buffer := Cat(io.input_data.bits, input_buffer(63:0))
            n_next_to_decrypt := 1.U
            n_input_counter := 0.U
        }
        .otherwise {
            n_input_buffer := {0.U(64.W), io.input_data.bits}
            n_next_to_decrypt := 0.U
            n_input_counter := 1.U
        }
    }
    .otherwise {
        n_input_buffer := input_buffer
        n_next_to_decrypt := 0.U
        n_input_counter := input_counter
    }

	// interface between out and enc
	io.output_data.bits := Mux(output_counter(1), output_buffer(127:64), output_buffer(63:0))
	io.output_data.valid := output_counter(0) | output_counter(1)
    when(ready_from_encrypt) {
        n_output_buffer := output_from_encrypt
        n_output_counter := 1.U
    }
    .otherwise {
        n_output_buffer := output_buffer
        when(output_counter(0)) {
            n_output_counter := 2.U
        }
        .otherwise {
            n_output_counter := 0.U
        }
    }



	// singleCycle
	val n_counter = Wire(UInt(1.W)) 
    val counter = RegNext(n_counter)

    val n_input_valid_buffer = Wire(UInt(1.W)
    val input_valid_buffer = RegNext(n_input_valid_buffer)

	val n_output_valid_buffer = Wire(UInt(1.W)
    val output_valid_buffer = RegNext(n_output_valid_buffer)

	val n_dec_to_neg_buffer = Wire(UInt(128.W))
	val dec_to_neg_buffer

	val n_neg_to_enc_buffer = Wire(UInt(128.W))
	logic (127:0) neg_to_enc_buffer

	val input_to_negator = Wire(UInt(128.W))
	val output_from_negator = Wire(UInt(128.W))

	// Connect the component to the datapath
	val singleCycleTightlyCoupledNegator = Module( new SingleCycleTightlyCoupledNegator(1, 64))

    singleCycleTightlyCoupledNegator.io.input_data := input_to_negator
    output_from_negator := singleCycleTightlyCoupledNegator.io.output_data.bits

	next_to_encrypt := output_valid_buffer
	input_to_encrypt := neg_to_enc_buffer

    when(!input_valid_buffer) {
        when(ready_from_decrypt) {
            n_input_valid_buffer := 1.U
            n_dec_to_neg_buffer := output_from_decrypt
            n_output_valid_buffer := 0.U
            n_counter := 0.U
            input_to_negator := 0.U
            n_neg_to_enc_buffer := 0.U
        }
        .otherwise {
            n_input_valid_buffer := 0.U
            n_dec_to_neg_buffer := 0.U
            n_output_valid_buffer := 0.U
            n_counter := 0.U
            input_to_negator := 0.U
            n_neg_to_enc_buffer := 0.U
        }
    }
    .elsewhen(counter === 0.U) {
        n_input_valid_buffer := 1.U
        n_dec_to_neg_buffer := dec_to_neg_buffer
        n_output_valid_buffer := 0.U
        n_counter := 1.U
        input_to_negator := dec_to_neg_buffer(63:0)
        n_neg_to_enc_buffer(127:64) := 0.U
        n_neg_to_enc_buffer(63:0) := output_from_negator
    }
    .otherwise {
        n_input_valid_buffer := 0.U
        n_dec_to_neg_buffer := 0.U
        n_output_valid_buffer := 1.U
        n_counter := 0.U
        input_to_negator := dec_to_neg_buffer(127:64)
        n_neg_to_enc_buffer(127:64) := output_from_negator
        n_neg_to_enc_buffer(63:0) := neg_to_enc_buffer(63:0)		
    }

}