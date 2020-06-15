// See LICENSE for license details.

package nagator

import chisel3.Module
import freechips.rocketchip.config.{Parameters, Config}
import junctions._

class NegatorMatchedConfig extends Config((site, here, up) => {
    case INTEGER_WIDTH => 32
    case WIDTH_IN_NUM_OF_FULL_INTEGER => 2
    case MEM_WIDTH => 64
    case NUM_OF_QUEUE_ENTRY => 8
    case NUM_OF_CYCLES_FOR_ENC_DEC_ENGIN => 4
)

class NegatorUNMatchedConfig extends Config((site, here, up) => {
    case INTEGER_WIDTH => 32
    case WIDTH_IN_NUM_OF_FULL_INTEGER => 1
    case MEM_WIDTH => 64
    case NUM_OF_QUEUE_ENTRY => 8
    case NUM_OF_CYCLES_FOR_ENC_DEC_ENGIN => 4
)