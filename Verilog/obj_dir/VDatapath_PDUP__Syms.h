// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VDATAPATH_PDUP__SYMS_H_
#define _VDATAPATH_PDUP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VDatapath_PDUP.h"

// SYMS CLASS
class VDatapath_PDUP__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VDatapath_PDUP*                TOPp;
    
    // CREATORS
    VDatapath_PDUP__Syms(VDatapath_PDUP* topp, const char* namep);
    ~VDatapath_PDUP__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
