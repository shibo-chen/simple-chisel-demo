// See README.md for license details.

package negator

import java.io.File

import chisel3.iotesters
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class Datapath_STUP_Tester(c: Datapath_STUP) extends PeekPokeTester(c) {

  private val datapath_stup = c
  var iterate = 5
  var r = scala.util.Random
  var last_input_1 = r.nextInt
  var last_input_2 = r.nextInt
  step(1)
  // put the first input in
  poke(datapath_stup.io.input_data.valid, 1)
  poke(datapath_stup.io.input_data.bits(31,0), last_input_1)
  poke(datapath_stup.io.input_data.bits(63,32), last_input_2)
  step(1)
  while(iterate > 0){
    if(peek(datapath_stup.io.output_data.valid)  == BigInt(1)){
    iterate -= 1
    if(expect(datapath_stup.io.output_data.bits(31,0), -last_input_1) &&
        expect(datapath_stup.io.output_data.bits(63,32), -last_input_2) ){
        last_input_1 = r.nextInt
        last_input_2 = r.nextInt
        poke(datapath_stup.io.input_data.bits(31,0), last_input_1)
        poke(datapath_stup.io.input_data.bits(63,32), last_input_2)
    }else{
        throw new Exception("Failed stup")
    }
    }else{
    poke(datapath_stup.io.input_data.valid, 0)
    poke(datapath_stup.io.input_data.bits, 0)
    }

    step(1)
  }
}
