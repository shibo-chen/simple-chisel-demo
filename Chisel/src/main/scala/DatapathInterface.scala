package negator

import chisel3._
import chisel3.util._ 

class DatapathInterface extends Bundle{
    val input_data = Flipped(Valid(UInt(64.W)))
    val output_data = Valid(UInt(64.W))
}