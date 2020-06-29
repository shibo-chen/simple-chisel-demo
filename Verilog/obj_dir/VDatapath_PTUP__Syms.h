// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VDATAPATH_PTUP__SYMS_H_
#define _VDATAPATH_PTUP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VDatapath_PTUP.h"

// SYMS CLASS
class VDatapath_PTUP__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VDatapath_PTUP*                TOPp;
    
    // CREATORS
    VDatapath_PTUP__Syms(VDatapath_PTUP* topp, const char* namep);
    ~VDatapath_PTUP__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
