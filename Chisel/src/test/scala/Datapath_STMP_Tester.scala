// See README.md for license details.

package negator

import java.io.File

import chisel3.iotesters
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class Datapath_STMP_Tester(c: Datapath_STMP) extends PeekPokeTester(c) {

  private val datapath_stmp = c
  var iterate = 5
  var r = scala.util.Random
  var last_input = r.nextInt
  step(1)
  // put the first input in
  poke(datapath_stmp.io.input_data.valid, 1)
  poke(datapath_stmp.io.input_data.bits, last_input)
  step(1)
  while(iterate > 0){
      if(datapath_stmp.io.output_data.valid){
        iterate -= 1
        if(expect(datapath_stmp.io.output_data.bits, - last_input)){
          poke(datapath_stmp.io.input_data.valid, 1)
          last_input = r.nextInt
          poke(datapath_stmp.io.input_data.bits, last_input)
        }else{
          throw new Exception("Failed STMP")
        }
      }else{
        poke(datapath_stmp.io.input_data.valid, 0)
        poke(datapath_stmp.io.input_data.bits, 0)
      }
    step(1)
  }
}
