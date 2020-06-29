#include <stdlib.h>
#include <stdint.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "verilated.h"
#include "VDatapath_PDUP.h"
#include "testPDUP.h"
#include "util/util.h"

int testPDUP(){
    std::cout << "**************Testing PDUP*************"<<std::endl;
    VDatapath_PDUP *test_module = new VDatapath_PDUP;
    unsigned num_instance_evaluated = 5;
    int32_t last_input[2];
    int64_t input = 0;
    std::srand(std::time(NULL));
    /*Initialize*/
    test_module->clock = 1;
    test_module->reset = 1;
    test_module->eval();
    test_module->clock = 0;
    test_module->eval();
    /*generate inputs*/
    test_module->clock = 1;
    test_module->reset = 0;
    test_module->input_valid = 1;
    last_input[0] = rand();
    last_input[1] = rand();
    strncpy((char*)&input, (char*)last_input, 8);

    test_module->input_data = input;
    test_module->eval();
    while (num_instance_evaluated > 0 )
    {

        test_module->clock = 0;
        test_module->eval();
        if(!isCorrect_32(test_module->output_valid, last_input, (int32_t*) &(test_module->output_data) )){
            std::cout << "**************PDUP test FAILED*************\n"<<std::endl;
            std::cout<<"Expected: "<< last_input<<"  Get: "<<test_module->output_data<<std::endl;
            return 0;
        }

        if(test_module->output_valid){
            num_instance_evaluated --;
            test_module->input_valid = 1;
            last_input[0] = rand();
            last_input[1] = rand();
            strncpy((char*)&input, (char*)last_input, 8);
            test_module->input_data = input;
        }
        else{
            test_module->input_valid = 0;
            test_module->input_data = 0;
        }
        test_module->clock = 1;
        test_module->eval();

    }
    std::cout << "**************PDUP test PASSED*************\n"<<std::endl;
    delete test_module;
    return 0;
}