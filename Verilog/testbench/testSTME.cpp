#include <stdlib.h>
#include <stdint.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "verilated.h"
#include "VDatapath_STME.h"
#include "util/util.h"
#include "testSTME.h"

int testSTME(){
    std::cout << "**************Testing STME*************"<<std::endl;
    VDatapath_STME *test_module = new VDatapath_STME;
    unsigned num_instance_evaluated = 5;
    int64_t last_input[2];
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
    test_module->input_data = last_input[0];
    test_module->eval();
    test_module->clock = 0;
    test_module->eval();
    test_module->clock = 1;
    test_module->input_data = last_input[1];
    test_module->eval();

    while (num_instance_evaluated > 0)
    {

        test_module->clock = 0;
        test_module->eval();

        if(test_module->output_valid){
            num_instance_evaluated --;
            if(!isCorrect_64(test_module->output_valid, last_input[0], test_module->output_data)){
                std::cout << "**************STMEtest FAILED*************\n"<<std::endl;
                std::cout<<"Expected: "<< last_input[0]<<"  Get: "<<test_module->output_data<<std::endl;
                return 0;
            }
            test_module->clock = 1;
            test_module->eval();
            if(!test_module->output_valid){
                std::cout << "**************STMEtest FAILED*************\n"<<std::endl;
                std::cout<<"Expected: valid, Get: invalid"<<std::endl;
                return 0;
            }
            if(!isCorrect_64(test_module->output_valid, last_input[1], test_module->output_data)){
                std::cout << "**************STME test FAILED*************\n"<<std::endl;
                std::cout<<"Expected: "<< last_input[1]<<"  Get: "<<test_module->output_data<<std::endl;
                return 0;
            }
            test_module->clock = 0;
            test_module->eval();


            test_module->input_valid = 1;
            last_input[0] = rand();
            last_input[1] = rand();
            test_module->input_data = last_input[0];
            test_module->clock = 1;
            test_module->eval();
            test_module->clock = 0;
            test_module->eval();
            test_module->input_data = last_input[1];
        }
        else{
            test_module->input_valid = 0;
            test_module->input_data = 0;
        }
        test_module->clock = 1;
        test_module->eval();
    }
    std::cout << "**************STME test PASSED*************\n"<<std::endl;
    delete test_module;
    return 0;
}