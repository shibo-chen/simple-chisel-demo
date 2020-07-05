/////////////////////////////////////////////
// Modulename:                             //
//      PipelinedDecoupledNegator          //
// Description:                            //
//          Negate an signed integer       //
//                 to the negative         //
//                                         //
/////////////////////////////////////////////

/*
Buffer      Cycle 0         Cycle 1                 Cycle 2                         
        Input Buffer    Bit-wise negation       Add 1 to get Two's complement   
*/
package negator

import chisel3._
import chisel3.util._ 

class PipelinedDecoupledNegatorInterface(val INTEGER_WIDTH: Int = 64) extends Bundle{
    val input_data = Flipped(Decoupled( UInt(INTEGER_WIDTH.W)))
    val output_data = Decoupled(UInt(INTEGER_WIDTH.W) )
}

class PipelinedDecoupledNegator(val INTEGER_WIDTH: Int = 64, val NUM_OF_QUEUE_ENTRY:Int = 4) extends Module {

  val io = IO(new PipelinedDecoupledNegatorInterface(INTEGER_WIDTH))


  val fifo_queue_for_data = Module(new Queue(UInt(INTEGER_WIDTH.W), NUM_OF_QUEUE_ENTRY))
  fifo_queue_for_data.io.enq <> io.input_data

  val n_input_buffer = Wire( UInt(INTEGER_WIDTH.W) )
  n_input_buffer := fifo_queue_for_data.io.deq.bits
  fifo_queue_for_data.io.deq.ready := io.output_data.ready

  val input_buffer  = RegNext(n_input_buffer)
  n_input_buffer := Mux(io.output_data.ready, fifo_queue_for_data.io.deq.bits, input_buffer)
  
  val n_negated_data = Wire( UInt(INTEGER_WIDTH.W) )
  val negated_result = Wire( UInt(INTEGER_WIDTH.W) )
  val negated_data = RegNext(n_negated_data)
  n_negated_data := Mux(io.output_data.ready, negated_result, negated_data)

  val n_valid = Vec(2, Bool())
  val valid = RegNext(n_valid)
  io.output_data.valid := valid(1)

  n_valid := Mux( io.output_data.ready,
    Cat(valid(0), fifo_queue_for_data.io.deq.valid), valid )
  negated_result := ~input_buffer
  io.output_data.bits := negated_data + 1.U

}
