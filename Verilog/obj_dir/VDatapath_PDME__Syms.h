// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VDATAPATH_PDME__SYMS_H_
#define _VDATAPATH_PDME__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VDatapath_PDME.h"

// SYMS CLASS
class VDatapath_PDME__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VDatapath_PDME*                TOPp;
    
    // CREATORS
    VDatapath_PDME__Syms(VDatapath_PDME* topp, const char* namep);
    ~VDatapath_PDME__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
