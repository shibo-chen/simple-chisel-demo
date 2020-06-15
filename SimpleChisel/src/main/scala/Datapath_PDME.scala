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

class DatapathInterface extends Interface{
    val BUS_NONE = 0.U(2.W)
    val BUS_LOAD = 1.U(2.W)
    val BUS_STORE = 2.U(2.W)

	val in = new Bundle{
        val mem2proc_reponse = UInt(4.W)
        val mem2proc_data = UInt(64.W)
        val mem2proc_tag = UInt(4.W)
    }

	val out = new Bundle{
        val proc2mem_command = UInt(2.W)
        val proc2mem_address = UInt(64.W)
        val proc2mem_data = UInt(64.W)
    }
}

class Datapath extends Module with DatapathInterface{

    val pipelinedDecoupledNegator = Stage(new PipelinedDecoupledNegator)
    val simulatedAESDecryptEngin  = Stage(new SimulatedAESDecryptEngin)
    val simulatedAESEncryptEngin  = Stage(new SimulatedAESEncryptEngin)	

    val input_valid = Wire(Bool())

    val store_buffer = Stage(new Queue(2, UInt(64.W)))

    // Connect Mem to decryptor
    val input_to_decryptor = ValidIO(valid = input_valid, mem2proc_data)
    input_to_decryptor >>> simulatedAESDecryptEngin

    // Connect encryptor to mem
    simulatedAESEncryptEngin >>> store_buffer

    //****state machine for mem********
    val n_address_to_load = UInt(64.W)
    val n_address_to_store = UInt(64.W)
    val address_to_load = RegNext(n_address_to_load)
    val address_to_store = RegNext(n_address_to_store)
    
	//if we have requested a new data, we can increment it by 4
	n_address_to_load := Mux(proc2mem_cmd === BUS_LOAD, (address_to_load + 4.U), address_to_load)
	//if we have stored a new data, we can increment it by 4
	n_address_to_store := Mux(proc2mem_cmd === BUS_STORE, (address_to_store + 4.U), address_to_store)

	out.proc2mem_command := proc2mem_cmd;

	when(proc2mem_cmd === BUS_LOAD){
		out.proc2mem_address := address_to_load
    }
	.elsewhen(proc2mem_cmd === BUS_STORE){
		out.proc2mem_address := address_to_store
    }
	.otherwise{
		out.proc2mem_address := 0
    }


	out.proc2mem_data := store_buffer.out.bits

    val n_last_ld_st = Wire(Bool)
    val last_ld_st = RegNext(n_last_ld_st)

    val n_mem_counter = Wire(UInt(1.W))
    val mem_counter = RegNext(n_mem_counter)

    val n_unresolved_req = Wire(Bool)
    val unresolved_req = RegNext(n_unresolved_req)

	/*First, figure out the connection between enc/dec and mem*/
	when(last_ld_st){// last req is a load
		when (unresolved_req) {
			when (in.mem2proc_tag) {
				when(mem_counter){
					n_mem_counter := 0
					input_valid := true.B
					proc2mem_cmd := BUS_NONE
					n_unresolved_req := fase.B
					n_last_ld_st := true.B
                    store_buffer.out.ctrl.ready := false.B
                }
				.otherwise{ // issue next request
					n_mem_counter := 1.U
					input_valid := false.B
					proc2mem_cmd := BUS_LOAD
					n_unresolved_req := true.B
					n_last_ld_st := true.B
                    store_buffer.out.ctrl.ready := false.B			
				}
			}
			.otherwise{
                n_mem_counter := mem_counter
                input_valid := false.B
                proc2mem_cmd := BUS_NONE
                n_unresolved_req := true.B
                n_last_ld_st := last_ld_st
                store_buffer.out.ctrl.ready := false.B		

			}
		}
		.otherwise{
			when(store_buffer.out.ctrl.valid){
                n_mem_counter := 1.U
                input_valid := false.B
                proc2mem_cmd := BUS_STORE
                n_unresolved_req := true.B
                n_last_ld_st := false.B
                store_buffer.out.ctrl.ready := false.B		
			} 
			.otherwise{
                n_mem_counter := 0.U
                input_valid := false.B
                proc2mem_cmd := BUS_NONE
                n_unresolved_req := false.B
                n_last_ld_st := true.B
                store_buffer.ctrl.ready := false.B						
			}
		}
	}
	.otherwise{
		when(unresolved_req) { // last req is a store
				when(in.mem2proc_tag) { 
					when(mem_counter){ // issue next request
                        n_mem_counter := 0.U
                        input_valid := false.B
                        proc2mem_cmd := BUS_STORE
                        n_unresolved_req := true.B
                        n_last_ld_st := false.B
                        store_buffer.ctrl.ready := true.B	
					}
					.otherwise { // issue load
                        n_mem_counter := 0.U
                        input_valid := false.B
                        proc2mem_cmd := BUS_LOAD
                        n_unresolved_req := true.B
                        n_last_ld_st := true.B
                        store_buffer.ctrl.ready := false.B				
					}
				}
				.otherwise {
                    n_mem_counter := mem_counter
                    input_valid := false.B
                    proc2mem_cmd := BUS_NONE
                    n_unresolved_req := true.B
                    n_last_ld_st := last_ld_st
                    store_buffer.ctrl.ready := false.B			
				}
			}
		.otherwise {
            n_mem_counter := mem_counter
            input_valid := false.B
            proc2mem_cmd := BUS_NONE
            n_unresolved_req := false.B
            n_last_ld_st := last_ld_st
            store_buffer.ctrl.ready := false.B			
		}
	}


    // connect the inner pipeline

    val valid_output_from_negator = Wire(Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), Bool()))
    val valid_input_to_negator = Wire(Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), Bool()))

    when(simulatedAESDecryptEngin.out.ctrl.valid){
        valid_input_to_negator := Vec.fill(p(WIDTH_IN_NUM_OF_FULL_INTEGER), true.B)
    }.otherwise{
        valid_input_to_negator := Vec.fill(p(WIDTH_IN_NUM_OF_FULL_INTEGER), false.B)
    }

    Packet(valid_input_to_negator, simulatedAESDecryptEngin) >>> 
    pipelinedDecoupledNegator >>> Packet(valid_output_from_negator, simulatedAESEncryptEngin)
}