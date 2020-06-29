#include <stdlib.h>
#include <stdint.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <verilated_vcd_c.h>
#include "verilated.h"
#include "testSTMP.h"
#include "testSTUP.h"
#include "testSTME.h"
#include "testPTMP.h"
#include "testPTUP.h"
#include "testPTME.h"
#include "testPDMP.h"
#include "testPDUP.h"
#include "testPDME.h"

int main(int argc, char **argv) {
	// Initialize Verilators variables
	Verilated::commandArgs(argc, argv);

	testSTMP();
    testSTUP();
    testSTME();
    testPTMP();
    testPTUP();
    testPTME();
    testPDMP();
    testPDUP();
    testPDME();
}