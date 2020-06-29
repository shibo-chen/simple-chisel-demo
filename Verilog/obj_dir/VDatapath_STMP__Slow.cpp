// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_STMP.h for the primary calling header

#include "VDatapath_STMP.h"
#include "VDatapath_STMP__Syms.h"

//==========

VL_CTOR_IMP(VDatapath_STMP) {
    VDatapath_STMP__Syms* __restrict vlSymsp = __VlSymsp = new VDatapath_STMP__Syms(this, name());
    VDatapath_STMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VDatapath_STMP::__Vconfigure(VDatapath_STMP__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-10);
}

VDatapath_STMP::~VDatapath_STMP() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VDatapath_STMP::_settle__TOP__2(VDatapath_STMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STMP::_settle__TOP__2\n"); );
    VDatapath_STMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->output_data = (1ULL + (~ vlTOPp->Datapath_STMP__DOT__data_buffer));
    vlTOPp->output_valid = vlTOPp->Datapath_STMP__DOT__buffer_valid;
}

void VDatapath_STMP::_eval_initial(VDatapath_STMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STMP::_eval_initial\n"); );
    VDatapath_STMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VDatapath_STMP::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STMP::final\n"); );
    // Variables
    VDatapath_STMP__Syms* __restrict vlSymsp = this->__VlSymsp;
    VDatapath_STMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VDatapath_STMP::_eval_settle(VDatapath_STMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STMP::_eval_settle\n"); );
    VDatapath_STMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VDatapath_STMP::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STMP::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    input_valid = VL_RAND_RESET_I(1);
    input_data = VL_RAND_RESET_Q(64);
    output_valid = VL_RAND_RESET_I(1);
    output_data = VL_RAND_RESET_Q(64);
    Datapath_STMP__DOT__buffer_valid = VL_RAND_RESET_I(1);
    Datapath_STMP__DOT__data_buffer = VL_RAND_RESET_Q(64);
}
