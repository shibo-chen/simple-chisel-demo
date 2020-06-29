// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_PTMP.h for the primary calling header

#include "VDatapath_PTMP.h"
#include "VDatapath_PTMP__Syms.h"

//==========

VL_CTOR_IMP(VDatapath_PTMP) {
    VDatapath_PTMP__Syms* __restrict vlSymsp = __VlSymsp = new VDatapath_PTMP__Syms(this, name());
    VDatapath_PTMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VDatapath_PTMP::__Vconfigure(VDatapath_PTMP__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-10);
}

VDatapath_PTMP::~VDatapath_PTMP() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VDatapath_PTMP::_settle__TOP__2(VDatapath_PTMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTMP::_settle__TOP__2\n"); );
    VDatapath_PTMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->output_data = (1ULL + vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__negated_data);
    vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__n_valid 
        = (1U & (IData)(vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__valid));
    vlTOPp->output_valid = (1U & ((IData)(vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__valid) 
                                  >> 1U));
}

void VDatapath_PTMP::_eval_initial(VDatapath_PTMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTMP::_eval_initial\n"); );
    VDatapath_PTMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VDatapath_PTMP::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTMP::final\n"); );
    // Variables
    VDatapath_PTMP__Syms* __restrict vlSymsp = this->__VlSymsp;
    VDatapath_PTMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VDatapath_PTMP::_eval_settle(VDatapath_PTMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTMP::_eval_settle\n"); );
    VDatapath_PTMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VDatapath_PTMP::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTMP::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    input_valid = VL_RAND_RESET_I(1);
    input_data = VL_RAND_RESET_Q(64);
    output_valid = VL_RAND_RESET_I(1);
    output_data = VL_RAND_RESET_Q(64);
    Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__input_buffer = VL_RAND_RESET_Q(64);
    Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__negated_data = VL_RAND_RESET_Q(64);
    Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__valid = VL_RAND_RESET_I(2);
    Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__n_valid = VL_RAND_RESET_I(1);
}
