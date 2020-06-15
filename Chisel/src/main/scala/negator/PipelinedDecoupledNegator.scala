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

class PipelinedDecoupledNegatorInterface(implicit val p: Parameters) extends Bundle{
    val input_valid = Input( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), Bool()) )
    val output_valid = Output( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), Bool()) )
    val input_data = Flipped(Decoupled( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W))))
    val output_data = Decoupled( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W) ) )
}

class PipelinedDecoupledNegator(implicit val p: Parameters) extends Module {

  val io = IO(new PipelinedDecoupledNegatorInterface)


  val fifo_queue_for_data = Module(new Queue(Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W)), p(NUM_OF_QUEUE_ENTRY)))
  val fifo_queue_for_valid = Module(new Queue(Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W)), p(NUM_OF_QUEUE_ENTRY)))
  fifo_queue_for_data.enq <> io.input_data
  fifo_queue_for_valid.enq.valid := io.input_data.valid
  fifo_queue_for_valid.enq.bits := io.input_valid

  n_input_buffer := fifo_queue_for_data.deq.bits
  fifo_queue_for_data.deq.ready := io.output_data.ready

  val n_input_buffer = Wire( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W)) )
  val input_buffer  = RegNext(n_input_buffer)
  n_input_buffer := Mux(io.output_data.ready, fifo_queue_for_data.deq.bits, input_buffer)
  
  val n_negated_data = Wire( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W)) );
  val negated_result = Wire( Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), UInt(p(INTEGER_WIDT).W)) );
  val negated_data = RegNext(n_negated_data);
  n_negated_data := Mux(io.output_data.ready, negated_result, negated_data)

  val n_valid = Vec(2, Vec(p(WIDTH_IN_NUM_OF_FULL_INTEGER), Bool()));
  val valid = RegNext(n_valid);

  n_valid := Mux( io.output_data.ready,
    Cat(valid(0), fifo_queue_for_valid.deq.bits), valid )
  for(i <- 0 until p(WIDTH_IN_NUM_OF_FULL_INTEGER)) {
    negated_result(i) := ~input_buffer(i) 
    io.output_data.bits(i) := negated_data(i) + 1;
  }

}
