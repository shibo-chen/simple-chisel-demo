package negator

import chisel3._

/**
 * This provides an alternate way to run tests, by executing then as a main
 * From sbt (Note: the test: prefix is because this main is under the test package hierarchy):
 * {{{
 * test:runMain negator.NegatorMain
 * }}}
 * To see all command line options use:
 * {{{
 * test:runMain negator.NegatorMain --help
 * }}}
 * To run with verilator:
 * {{{
 * test:runMain negator.NegatorMain --backend-name verilator
 * }}}
 * To run with verilator from your terminal shell use:
 * {{{
 * sbt 'test:runMain negator.NegatorMain --backend-name verilator'
 * }}}
 */
object NegatorMain extends App {
  iotesters.Driver.execute(args, () => new Datapath_STMP) {
    c => new Datapath_STMP_Tester(c)
  }
}