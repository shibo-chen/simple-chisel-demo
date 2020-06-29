#include <stdlib.h>
#include <stdint.h>
#include <cstdlib>
#include <iostream>

bool isHigh(bool out){
    return out == true;
}

bool isCorrect_64(bool output_valid, int64_t input, int64_t output ){
    if(output_valid){
        if(input == (-output))
            std::cout<<"Output matched: "<< input<<" - "<<output<<std::endl;
        return input == (-output);
    }
    else
        return true;
}

bool isCorrect_32(bool output_valid, int32_t* input, int32_t* output ){
    if(output_valid){
        int32_t first_input = *input;
        int32_t second_intput = *(input + 1);
        int32_t first_output = *output;
        int32_t second_output = *(output + 1);
        if((first_input == (-first_output)) && (second_intput == (-second_output)))
            std::cout<<"Output matched: "<< first_input<<" - "<<first_output<<", "<<second_intput<<" - "<<second_output<<std::endl;
        return ( (first_input == (-first_output)) && (second_intput == (-second_output)));
    }
    else
        return true;
}