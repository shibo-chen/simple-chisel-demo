// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VDATAPATH_PDMP__SYMS_H_
#define _VDATAPATH_PDMP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VDatapath_PDMP.h"

// SYMS CLASS
class VDatapath_PDMP__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VDatapath_PDMP*                TOPp;
    
    // CREATORS
    VDatapath_PDMP__Syms(VDatapath_PDMP* topp, const char* namep);
    ~VDatapath_PDMP__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
