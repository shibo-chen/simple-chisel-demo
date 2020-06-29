// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_PTUP.h for the primary calling header

#include "VDatapath_PTUP.h"
#include "VDatapath_PTUP__Syms.h"

//==========

VL_CTOR_IMP(VDatapath_PTUP) {
    VDatapath_PTUP__Syms* __restrict vlSymsp = __VlSymsp = new VDatapath_PTUP__Syms(this, name());
    VDatapath_PTUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VDatapath_PTUP::__Vconfigure(VDatapath_PTUP__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-10);
}

VDatapath_PTUP::~VDatapath_PTUP() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VDatapath_PTUP::_settle__TOP__2(VDatapath_PTUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTUP::_settle__TOP__2\n"); );
    VDatapath_PTUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->output_valid = vlTOPp->Datapath_PTUP__DOT__output_valid_buffer;
    vlTOPp->output_data = vlTOPp->Datapath_PTUP__DOT__output_buffer;
    vlTOPp->Datapath_PTUP__DOT__valid_input_to_negator 
        = vlTOPp->Datapath_PTUP__DOT__input_valid_buffer;
    vlTOPp->Datapath_PTUP__DOT__pipelinedTightlyCoupledNegator__DOT__n_valid 
        = (1U & (IData)(vlTOPp->Datapath_PTUP__DOT__pipelinedTightlyCoupledNegator__DOT__valid));
    vlTOPp->Datapath_PTUP__DOT__n_input_counter = ((IData)(vlTOPp->Datapath_PTUP__DOT__input_valid_buffer) 
                                                   & (~ (IData)(vlTOPp->Datapath_PTUP__DOT__input_counter)));
    vlTOPp->Datapath_PTUP__DOT__n_input_valid_buffer 
        = (1U & ((IData)(vlTOPp->Datapath_PTUP__DOT__input_valid_buffer)
                  ? (~ (IData)(vlTOPp->Datapath_PTUP__DOT__input_counter))
                  : (IData)(vlTOPp->input_valid)));
    vlTOPp->Datapath_PTUP__DOT__n_output_valid_buffer 
        = ((~ (IData)(vlTOPp->Datapath_PTUP__DOT__output_valid_buffer)) 
           & ((2U & (IData)(vlTOPp->Datapath_PTUP__DOT__pipelinedTightlyCoupledNegator__DOT__valid))
               ? (IData)(vlTOPp->Datapath_PTUP__DOT__output_counter)
               : (IData)(vlTOPp->Datapath_PTUP__DOT__output_valid_buffer)));
    vlTOPp->Datapath_PTUP__DOT__n_output_counter = 
        (1U & ((~ (IData)(vlTOPp->Datapath_PTUP__DOT__output_valid_buffer)) 
               & ((2U & (IData)(vlTOPp->Datapath_PTUP__DOT__pipelinedTightlyCoupledNegator__DOT__valid))
                   ? (~ (IData)(vlTOPp->Datapath_PTUP__DOT__output_counter))
                   : (IData)(vlTOPp->Datapath_PTUP__DOT__output_counter))));
    vlTOPp->Datapath_PTUP__DOT__n_input_buffer = ((IData)(vlTOPp->Datapath_PTUP__DOT__input_valid_buffer)
                                                   ? 
                                                  ((IData)(vlTOPp->Datapath_PTUP__DOT__input_counter)
                                                    ? 0ULL
                                                    : vlTOPp->Datapath_PTUP__DOT__input_buffer)
                                                   : vlTOPp->input_data);
    vlTOPp->Datapath_PTUP__DOT__n_output_buffer = ((IData)(vlTOPp->Datapath_PTUP__DOT__output_valid_buffer)
                                                    ? 0ULL
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->Datapath_PTUP__DOT__pipelinedTightlyCoupledNegator__DOT__valid))
                                                     ? 
                                                    ((IData)(vlTOPp->Datapath_PTUP__DOT__output_counter)
                                                      ? 
                                                     (((QData)((IData)(
                                                                       ((IData)(1U) 
                                                                        + vlTOPp->Datapath_PTUP__DOT__pipelinedTightlyCoupledNegator__DOT__negated_data))) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(vlTOPp->Datapath_PTUP__DOT__output_buffer)))
                                                      : (QData)((IData)(
                                                                        ((IData)(1U) 
                                                                         + vlTOPp->Datapath_PTUP__DOT__pipelinedTightlyCoupledNegator__DOT__negated_data))))
                                                     : vlTOPp->Datapath_PTUP__DOT__output_buffer));
    vlTOPp->Datapath_PTUP__DOT__input_to_negator = 
        ((IData)(vlTOPp->Datapath_PTUP__DOT__input_valid_buffer)
          ? ((IData)(vlTOPp->Datapath_PTUP__DOT__input_counter)
              ? (IData)((vlTOPp->Datapath_PTUP__DOT__input_buffer 
                         >> 0x20U)) : (IData)(vlTOPp->Datapath_PTUP__DOT__input_buffer))
          : 0U);
}

void VDatapath_PTUP::_eval_initial(VDatapath_PTUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTUP::_eval_initial\n"); );
    VDatapath_PTUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VDatapath_PTUP::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTUP::final\n"); );
    // Variables
    VDatapath_PTUP__Syms* __restrict vlSymsp = this->__VlSymsp;
    VDatapath_PTUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VDatapath_PTUP::_eval_settle(VDatapath_PTUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTUP::_eval_settle\n"); );
    VDatapath_PTUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VDatapath_PTUP::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTUP::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    input_valid = VL_RAND_RESET_I(1);
    input_data = VL_RAND_RESET_Q(64);
    output_valid = VL_RAND_RESET_I(1);
    output_data = VL_RAND_RESET_Q(64);
    Datapath_PTUP__DOT__input_counter = VL_RAND_RESET_I(1);
    Datapath_PTUP__DOT__n_input_counter = VL_RAND_RESET_I(1);
    Datapath_PTUP__DOT__output_counter = VL_RAND_RESET_I(1);
    Datapath_PTUP__DOT__n_output_counter = VL_RAND_RESET_I(1);
    Datapath_PTUP__DOT__input_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_PTUP__DOT__n_input_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_PTUP__DOT__output_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_PTUP__DOT__n_output_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_PTUP__DOT__input_buffer = VL_RAND_RESET_Q(64);
    Datapath_PTUP__DOT__n_input_buffer = VL_RAND_RESET_Q(64);
    Datapath_PTUP__DOT__output_buffer = VL_RAND_RESET_Q(64);
    Datapath_PTUP__DOT__n_output_buffer = VL_RAND_RESET_Q(64);
    Datapath_PTUP__DOT__input_to_negator = VL_RAND_RESET_I(32);
    Datapath_PTUP__DOT__valid_input_to_negator = VL_RAND_RESET_I(1);
    Datapath_PTUP__DOT__pipelinedTightlyCoupledNegator__DOT__input_buffer = VL_RAND_RESET_I(32);
    Datapath_PTUP__DOT__pipelinedTightlyCoupledNegator__DOT__negated_data = VL_RAND_RESET_I(32);
    Datapath_PTUP__DOT__pipelinedTightlyCoupledNegator__DOT__valid = VL_RAND_RESET_I(2);
    Datapath_PTUP__DOT__pipelinedTightlyCoupledNegator__DOT__n_valid = VL_RAND_RESET_I(1);
}
