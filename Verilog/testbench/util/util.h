#include <stdlib.h>
#include <stdint.h>
#include <cstdlib>

#ifndef _UTIL_H
#define _UTIL_H

bool isCorrect_32(bool output_valid, int32_t* input, int32_t* output );
bool isCorrect_64(bool output_valid, int64_t input, int64_t output );
bool isHigh(bool out);
#endif