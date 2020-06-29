// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_STUP.h for the primary calling header

#include "VDatapath_STUP.h"
#include "VDatapath_STUP__Syms.h"

//==========

VL_CTOR_IMP(VDatapath_STUP) {
    VDatapath_STUP__Syms* __restrict vlSymsp = __VlSymsp = new VDatapath_STUP__Syms(this, name());
    VDatapath_STUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VDatapath_STUP::__Vconfigure(VDatapath_STUP__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-10);
}

VDatapath_STUP::~VDatapath_STUP() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VDatapath_STUP::_settle__TOP__2(VDatapath_STUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STUP::_settle__TOP__2\n"); );
    VDatapath_STUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->output_valid = vlTOPp->Datapath_STUP__DOT__output_valid_buffer;
    vlTOPp->output_data = vlTOPp->Datapath_STUP__DOT__output_buffer;
    vlTOPp->Datapath_STUP__DOT__n_counter = ((IData)(vlTOPp->Datapath_STUP__DOT__input_valid_buffer) 
                                             & (~ (IData)(vlTOPp->Datapath_STUP__DOT__counter)));
    vlTOPp->Datapath_STUP__DOT__n_output_valid_buffer 
        = ((IData)(vlTOPp->Datapath_STUP__DOT__input_valid_buffer) 
           & (IData)(vlTOPp->Datapath_STUP__DOT__counter));
    if (vlTOPp->Datapath_STUP__DOT__input_valid_buffer) {
        vlTOPp->Datapath_STUP__DOT__n_input_valid_buffer 
            = (1U & (~ (IData)(vlTOPp->Datapath_STUP__DOT__counter)));
        vlTOPp->Datapath_STUP__DOT__n_input_buffer 
            = ((IData)(vlTOPp->Datapath_STUP__DOT__counter)
                ? 0ULL : vlTOPp->Datapath_STUP__DOT__input_buffer);
        vlTOPp->Datapath_STUP__DOT__input_to_negator 
            = ((IData)(vlTOPp->Datapath_STUP__DOT__counter)
                ? (IData)((vlTOPp->Datapath_STUP__DOT__input_buffer 
                           >> 0x20U)) : (IData)(vlTOPp->Datapath_STUP__DOT__input_buffer));
    } else {
        vlTOPp->Datapath_STUP__DOT__n_input_valid_buffer 
            = (1U & (IData)(vlTOPp->input_valid));
        vlTOPp->Datapath_STUP__DOT__n_input_buffer 
            = ((IData)(vlTOPp->input_valid) ? vlTOPp->input_data
                : 0ULL);
        vlTOPp->Datapath_STUP__DOT__input_to_negator = 0U;
    }
    if (vlTOPp->Datapath_STUP__DOT__input_valid_buffer) {
        if (vlTOPp->Datapath_STUP__DOT__counter) {
            vlTOPp->Datapath_STUP__DOT__n_output_buffer 
                = ((0xffffffffULL & vlTOPp->Datapath_STUP__DOT__n_output_buffer) 
                   | ((QData)((IData)(((IData)(1U) 
                                       + (~ vlTOPp->Datapath_STUP__DOT__input_to_negator)))) 
                      << 0x20U));
            vlTOPp->Datapath_STUP__DOT__n_output_buffer 
                = ((0xffffffff00000000ULL & vlTOPp->Datapath_STUP__DOT__n_output_buffer) 
                   | (IData)((IData)(vlTOPp->Datapath_STUP__DOT__output_buffer)));
        } else {
            vlTOPp->Datapath_STUP__DOT__n_output_buffer 
                = (0xffffffffULL & vlTOPp->Datapath_STUP__DOT__n_output_buffer);
            vlTOPp->Datapath_STUP__DOT__n_output_buffer 
                = ((0xffffffff00000000ULL & vlTOPp->Datapath_STUP__DOT__n_output_buffer) 
                   | (IData)((IData)(((IData)(1U) + 
                                      (~ vlTOPp->Datapath_STUP__DOT__input_to_negator)))));
        }
    } else {
        vlTOPp->Datapath_STUP__DOT__n_output_buffer = 0ULL;
    }
}

void VDatapath_STUP::_eval_initial(VDatapath_STUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STUP::_eval_initial\n"); );
    VDatapath_STUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VDatapath_STUP::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STUP::final\n"); );
    // Variables
    VDatapath_STUP__Syms* __restrict vlSymsp = this->__VlSymsp;
    VDatapath_STUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VDatapath_STUP::_eval_settle(VDatapath_STUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STUP::_eval_settle\n"); );
    VDatapath_STUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VDatapath_STUP::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STUP::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    input_valid = VL_RAND_RESET_I(1);
    input_data = VL_RAND_RESET_Q(64);
    output_valid = VL_RAND_RESET_I(1);
    output_data = VL_RAND_RESET_Q(64);
    Datapath_STUP__DOT__counter = VL_RAND_RESET_I(1);
    Datapath_STUP__DOT__n_counter = VL_RAND_RESET_I(1);
    Datapath_STUP__DOT__input_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_STUP__DOT__n_input_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_STUP__DOT__output_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_STUP__DOT__n_output_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_STUP__DOT__input_buffer = VL_RAND_RESET_Q(64);
    Datapath_STUP__DOT__n_input_buffer = VL_RAND_RESET_Q(64);
    Datapath_STUP__DOT__output_buffer = VL_RAND_RESET_Q(64);
    Datapath_STUP__DOT__n_output_buffer = VL_RAND_RESET_Q(64);
    Datapath_STUP__DOT__input_to_negator = VL_RAND_RESET_I(32);
}
