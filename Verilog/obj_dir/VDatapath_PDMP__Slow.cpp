// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_PDMP.h for the primary calling header

#include "VDatapath_PDMP.h"
#include "VDatapath_PDMP__Syms.h"

//==========

VL_CTOR_IMP(VDatapath_PDMP) {
    VDatapath_PDMP__Syms* __restrict vlSymsp = __VlSymsp = new VDatapath_PDMP__Syms(this, name());
    VDatapath_PDMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VDatapath_PDMP::__Vconfigure(VDatapath_PDMP__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-10);
}

VDatapath_PDMP::~VDatapath_PDMP() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VDatapath_PDMP::_settle__TOP__2(VDatapath_PDMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDMP::_settle__TOP__2\n"); );
    VDatapath_PDMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->output_data = (1ULL + vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__negated_data);
    vlTOPp->output_valid = (1U & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__valid) 
                                  >> 1U));
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter 
        = (7U & (((0U != (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)) 
                  & (0U != (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)))
                  : (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)));
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__n_valid 
        = ((2U & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__valid) 
                  << 1U)) | ((0U == (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count))
                              ? 0U : (1U & ((4U >= (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)) 
                                            & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO) 
                                               >> (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter))))));
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter 
        = (7U & (((IData)(vlTOPp->input_valid) & (4U 
                                                  > (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)))
                  : (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)));
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter 
        = (7U & (((0U != (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)) 
                  & (0U != (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter)))
                  : (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter)));
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter 
        = (7U & (((IData)(vlTOPp->input_valid) & (4U 
                                                  > (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)))
                  : (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)));
}

void VDatapath_PDMP::_eval_initial(VDatapath_PDMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDMP::_eval_initial\n"); );
    VDatapath_PDMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VDatapath_PDMP::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDMP::final\n"); );
    // Variables
    VDatapath_PDMP__Syms* __restrict vlSymsp = this->__VlSymsp;
    VDatapath_PDMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VDatapath_PDMP::_eval_settle(VDatapath_PDMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDMP::_eval_settle\n"); );
    VDatapath_PDMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VDatapath_PDMP::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDMP::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    input_valid = VL_RAND_RESET_I(1);
    input_data = VL_RAND_RESET_Q(64);
    output_valid = VL_RAND_RESET_I(1);
    output_data = VL_RAND_RESET_Q(64);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__input_buffer = VL_RAND_RESET_Q(64);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__negated_data = VL_RAND_RESET_Q(64);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__valid = VL_RAND_RESET_I(2);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__n_valid = VL_RAND_RESET_I(2);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(320, Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter = VL_RAND_RESET_I(3);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter = VL_RAND_RESET_I(3);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter = VL_RAND_RESET_I(3);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter = VL_RAND_RESET_I(3);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT____Vlvbound1 = VL_RAND_RESET_Q(64);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count = VL_RAND_RESET_I(3);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO = VL_RAND_RESET_I(5);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter = VL_RAND_RESET_I(3);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter = VL_RAND_RESET_I(3);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter = VL_RAND_RESET_I(3);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter = VL_RAND_RESET_I(3);
    Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT____Vlvbound1 = VL_RAND_RESET_I(1);
}
