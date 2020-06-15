/*
Negator: PipelinedDecoupledNegator
Negator Bandwidth: 64
Memory Bandwidth: 64
Interface: DECOUPLED
Encryption: YES
*/

package negator

import chisel3._
import chisel3.util._ 
import freechips.rocketchip.config.Parameters

class DatapathInterface extends Bundle{
	val mem2proc_reponse = Input(UInt(4.W))
    val mem2proc_data = Input(UInt(64.W))
    val mem2proc_tag = Input(UInt(4.W))

	val proc2mem_command = Output(UInt(2.W))
    val proc2mem_address = Output(UInt(64.W))
    val proc2mem_data = Output(UInt(64.W)
}

class Datapath extends Module{
    val io = IO(new DatapathInterface)

    val BUS_NONE = 0.U(2.W)
    val BUS_LOAD = 1.U(2.W)
    val BUS_STORE = 2.U(2.W)

    val pipelinedDecoupledNegator = Module(new PipelinedDecoupledNegator)
    val simulatedAESDecryptEngin  = Module(new SimulatedAESDecryptEngin)
    val simulatedAESEncryptEngin  = Module(new SimulatedAESEncryptEngin)	

    val n_proc2mem_cmd = Wire(UInt(64.W))
    val proc2mem_cmd = RegNext(n_proc2mem_cmd)

    val n_address_to_load = Wire(UInt(64.W))
    val address_to_load = RegNext(n_address_to_load)
    val n_address_to_store = Wire(UInt(64.W))
    val address_to_store = RegNext(n_address_to_store)

    val n_load_buffer = Wire(UInt(64.W))
    val load_buffer = RegNext(n_load_buffer)
    val n_store_buffer = Wire(UInt(64.W))
    val store_buffer = RegNext(n_store_buffer)

    val n_input_counter = Wire(UInt(1.W))
    val input_counter = RegNext(n_input_counter)

    val n_output_counter = Wire(UInt(1.W))
    val output_counter = RegNext(n_output_counter)
    val input_to_negator = Wire(UInt(64.W))
	val negator_output_data = Wire(UInt(64.W))

    val n_last_ld_st = Wire(Bool)
    val last_ld_st = RegNext(n_last_ld_st)

    val n_mem_counter = Wire(UInt(1.W))
    val mem_counter = RegNext(n_mem_counter)

    val n_unresolved_req = Wire(Bool)
    val unresolved_req = RegNext(n_unresolved_req)

    val valid_output_from_negator = Wire(Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), Bool()))
    val valid_input_to_negator = Wire(Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), Bool()))

	val negator_input_ready = Wire(Bool()) 
    val negator_output_ready = Wire(Bool()) 
	val valid_input_to_decrypt = Wire(Bool()) 
    val valid_input_to_encrypt = Wire(Bool()) 

	val n_decrypt_to_negator_buffer = Wire(UInt(64.W))
    val decrypt_to_negator_buffer = RegNext(n_decrypt_to_negator_buffer)

	val n_negator_to_encrypt_buffer = Wire(UInt(64.W))
	val negator_to_encrypt_buffer = RegNext(n_negator_to_encrypt_buffer)

    val valid_output_from_decrypt = Wire(UInt(1.W))
    simulatedAESDecryptEngin.io.input_data.valid := next_input_to_decrypt
    simulatedAESDecryptEngin.io.input_data.bits := Cat(load_buffer, io.mem2proc_data)
    valid_output_from_decrypt := simulatedAESDecryptEngin.io.output_data.valid

    val valid_output_from_encrypt = Wire(UInt(1.W))
    simulatedAESEncryptEngin.io.input_data.valid := next_input_to_encrypt
    simulatedAESEncryptEngin.io.input_data.bits := 
        Cat(pipelinedDecoupledNegator.io.output_data.bits,negator_to_encrypt_buffer)
	valid_output_from_encrypt := simulatedAESEncryptEngin.io.output_data.valid
    
    pipelinedDecoupledNegator.io.input_valid := valid_input_to_negator
    pipelinedDecoupledNegator.io.input_data.bits := input_to_negator
    pipelinedDecoupledNegator.io.input_data.valid := (valid_input_to_negator != 0)
    negator_input_ready := pipelinedDecoupledNegator.io.input_data.ready
    valid_output_from_negator := pipelinedDecoupledNegator.io.output_valid
    negator_output_data := pipelinedDecoupledNegator.io.output_data.bits
    pipelinedDecoupledNegator.io.output_data.ready := negator_output_ready
    // Assign outputs
	io.proc2mem_command := proc2mem_cmd

	when(proc2mem_cmd === BUS_LOAD)
		io.proc2mem_address = address_to_load
	.elsewhen(proc2mem_cmd === BUS_STORE)
		io.proc2mem_address = address_to_store
	.otherwise
		io.proc2mem_address = 0.U

	io.proc2mem_data := Mux( (mem_counter === 1.U), store_buffer, simulatedAESEncryptEngin.io.output_data(63 : 0))
	//if we have requested a new data, we can increment it by 4
	n_address_to_load := Mux((proc2mem_cmd === BUS_LOAD) , (address_to_load + 4.U) , address_to_load) 
	//if we have stored a new data, we can increment it by 4
	n_address_to_store := Mux((proc2mem_cmd === BUS_STORE) , (address_to_store + 4.U) , address_to_store)

	/*First, figure out the connection between enc/dec and mem*/
	when(last_ld_st) {// last req is a load
		when(unresolved_req) {
			when(io.mem2proc_tag) {
				when(mem_counter){
					n_mem_counter := 0.U
					n_load_buffer := 0.U
					n_store_buffer := 0.U
					next_input_to_decrypt := 1.U
					n_proc2mem_cmd:= BUS_NONE
					n_unresolved_req := 0.U
					n_last_ld_st := 1.U
				}
				.otherwise { // issue next request
					n_mem_counter := 1.U
					n_load_buffer := mem2proc_data
					n_store_buffer := 0.U
					next_input_to_decrypt := 0.U
					n_proc2mem_cmd:= BUS_LOAD
					n_unresolved_req := 1.U
					n_last_ld_st := 1.U					
				}
			}
			.otherwise {
				n_mem_counter := mem_counter
				n_load_buffer := load_buffer
				n_store_buffer := 0.U
				next_input_to_decrypt := 0.U
				n_proc2mem_cmd:= BUS_NONE
				n_unresolved_req := 1.U
				n_last_ld_st := last_ld_st		
			}
		}
		.otherwise {
			when(simulatedAESEncryptEngin.io.output_data.valid) {
				n_mem_counter := 1.U
				n_load_buffer := 0.U
				n_store_buffer := simulatedAESEncryptEngin.io.output_data(127 : 64)
				next_input_to_decrypt := 0.U
				n_proc2mem_cmd:= BUS_STORE
				n_unresolved_req := 1.U
				n_last_ld_st := 0.U		
			} 
			.otherwise {
				n_mem_counter := 0.U
				n_load_buffer := 0.U
				n_store_buffer := 0.U
				next_input_to_decrypt := 0.U
				n_proc2mem_cmd:= BUS_NONE
				n_unresolved_req := 0.U
				n_last_ld_st := 1.U						
			}
		}
	}
	.otherwise {
		when(unresolved_req) { // last req is a store
				when(io.mem2proc_tag) { 
					when(mem_counter){ // issue next request
						n_mem_counter := 0.U
						n_load_buffer := 0.U
						n_store_buffer := 0.U
						next_input_to_decrypt := 0.U
						n_proc2mem_cmd:= BUS_STORE
						n_unresolved_req := 1.U
						n_last_ld_st := 0.U
					}
					.otherwise { // issue load
						n_mem_counter := 0.U
						n_load_buffer := 0.U
						n_store_buffer := 0.U
						next_input_to_decrypt := 0.U
						n_proc2mem_cmd:= BUS_LOAD
						n_unresolved_req := 1.U
						n_last_ld_st := 1.U					
					}
				}
				.otherwise {
					n_mem_counter := mem_counter
					n_load_buffer := 0.U
					n_store_buffer := store_buffer
					next_input_to_decrypt := 0.U
					n_proc2mem_cmd:= BUS_NONE
					n_unresolved_req := 1.U
					n_last_ld_st := last_ld_st		
				}
			}
		.otherwise {
			n_mem_counter := mem_counter
			n_load_buffer := 0.U
			n_store_buffer := store_buffer
			next_input_to_decrypt := 0.U
			n_proc2mem_cmd:= BUS_NONE
			n_unresolved_req := 0.U
			n_last_ld_st := last_ld_st	
		}
	}

	/*Then, figure out the connection between enc/dec and negator*/
	when(valid_output_from_decrypt) {
		n_input_counter := 1.U
		n_decrypt_to_negator_buffer := simulatedAESDecryptEngin.io.output_data.bits(127 : 64)
		valid_input_to_negator := 3.U(2.W)
		input_to_negator := simulatedAESDecryptEngin.io.output_data.bits(63 : 0)
	}
	.otherwise {
		when(input_counter) {
			n_input_counter := 0.U
			n_decrypt_to_negator_buffer := 0.U
			valid_input_to_negator := 3.U(2.W)
			input_to_negator := decrypt_to_negator_buffer
		}
		.otherwise {
			n_input_counter := 0.U
			n_decrypt_to_negator_buffer := 0.U
			valid_input_to_negator := 0.U
			input_to_negator := 0.U	
		}
	}

	when(negator_output_ready) {
		n_output_counter := 1.U
		n_negator_to_encrypt_buffer := negator_output_data
		next_input_to_encrypt := 0.U	
        negator_output_ready := 0.U
	}
	.otherwise
		when(output_counter) {
			n_output_counter := 0.U
			n_negator_to_encrypt_buffer := 0.U
			next_input_to_encrypt := 1.U	
            negator_output_ready := 1.U
		} 
		.otherwise {
			n_output_counter := 0.U
			n_negator_to_encrypt_buffer := 0.U
			next_input_to_encrypt := 0.U
            negator_output_ready := 0.U				
		}
	}
}