#include <stdlib.h>
#include <stdint.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "verilated.h"
#include "VDatapath_PTMP.h"
#include "util/util.h"
#include "testPTMP.h"

int testPTMP(){
    std::cout << "**************Testing PTMP*************"<<std::endl;
    VDatapath_PTMP *test_module = new VDatapath_PTMP;
    unsigned num_instance_evaluated = 5;
    int64_t last_input = 0;
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
    last_input = rand();
    test_module->input_data = last_input;
    test_module->eval();

    while (num_instance_evaluated > 0)
    {
        test_module->clock = 0;
        test_module->eval();

        if(!isCorrect_64(test_module->output_valid, last_input, test_module->output_data)){
            std::cout << "**************PTMP test FAILED*************\n"<<std::endl;
            std::cout<<"Expected: "<< last_input<<"  Get: "<<test_module->output_data<<std::endl;
            return 0;
        }
        if(test_module->output_valid){
            num_instance_evaluated --;
            test_module->input_valid = 1;
            last_input = rand();
            test_module->input_data = last_input;
        }
        else{
            test_module->input_valid = 0;
            test_module->input_data = 0;
        }
        test_module->clock = 1;
        test_module->eval();
    }
    std::cout << "**************PTMP test PASSED*************\n"<<std::endl;
    delete test_module;
    return 0;
}