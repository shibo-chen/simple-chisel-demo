// See LICENSE for license details.

package negator

import java.io.{File, FileWriter}

object Main extends App {
  val dir = new File(args(0)) ; dir.mkdirs
  val params = (new NegatorUNMatchedConfig).toInstance
  val chirrtl = firrtl.Parser.parse(chisel3.Driver.emit(() => new Datapath(params)))
  val writer = new FileWriter(new File(dir, s"${chirrtl.main}.fir"))
  writer write chirrtl.serialize
  writer.close

  val verilog = new FileWriter(new File(dir, s"${chirrtl.main}.v"))
  verilog write (new firrtl.VerilogCompiler).compileAndEmit(firrtl.CircuitState(chirrtl, firrtl.ChirrtlForm)).getEmittedCircuit.value
  verilog.close
}