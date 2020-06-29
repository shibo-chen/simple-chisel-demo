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
import freechips.rocketchip.config.Parameters

class PipelinedDecoupledNegatorInterface(val WIDTH_IN_NUM_OF_FULL_INTEGER = 1, val INTEGER_WIDTH = 64, val NUM_OF_QUEUE_ENTRY = 4)(implicit val p: Parameters) extends Bundle{
    val input_data = Flipped(Decoupled( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W))))
    val output_data = Decoupled( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W) ) )
}

class PipelinedDecoupledNegator(implicit val p: Parameters) extends Module {

  val io = IO(new PipelinedDecoupledNegatorInterface)


  val fifo_queue_for_data = Module(new Queue(Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W)), NUM_OF_QUEUE_ENTRY))
  fifo_queue_for_data.enq <> io.input_data


  n_input_buffer := fifo_queue_for_data.deq.bits
  fifo_queue_for_data.deq.ready := io.output_data.ready

  val n_input_buffer = Wire( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W)) )
  val input_buffer  = RegNext(n_input_buffer)
  n_input_buffer := Mux(io.output_data.ready, fifo_queue_for_data.deq.bits, input_buffer)
  
  val n_negated_data = Wire( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W)) )
  val negated_result = Wire( Vec(WIDTH_IN_NUM_OF_FULL_INTEGER, UInt(INTEGER_WIDTH.W)) )
  val negated_data = RegNext(n_negated_data);
  n_negated_data := Mux(io.output_data.ready, negated_result, negated_data)

  val n_valid = Vec(2, Bool())
  val valid = RegNext(n_valid)
  io.output_data.valid := valid(1)

  n_valid := Mux( io.output_data.ready,
    Cat(valid(0), fifo_queue_for_valid.deq.bits), valid )
  for(i <- 0 until WIDTH_IN_NUM_OF_FULL_INTEGER) {
    negated_result(i) := ~input_buffer(i) 
    io.output_data.bits(i) := negated_data(i) + 1
  }

}
