// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_PDUP.h for the primary calling header

#include "VDatapath_PDUP.h"
#include "VDatapath_PDUP__Syms.h"

//==========

VL_CTOR_IMP(VDatapath_PDUP) {
    VDatapath_PDUP__Syms* __restrict vlSymsp = __VlSymsp = new VDatapath_PDUP__Syms(this, name());
    VDatapath_PDUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VDatapath_PDUP::__Vconfigure(VDatapath_PDUP__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-10);
}

VDatapath_PDUP::~VDatapath_PDUP() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VDatapath_PDUP::_settle__TOP__2(VDatapath_PDUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDUP::_settle__TOP__2\n"); );
    VDatapath_PDUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->output_valid = vlTOPp->Datapath_PDUP__DOT__output_valid_buffer;
    vlTOPp->output_data = vlTOPp->Datapath_PDUP__DOT__output_buffer;
    vlTOPp->Datapath_PDUP__DOT__n_input_counter = ((IData)(vlTOPp->Datapath_PDUP__DOT__input_valid_buffer) 
                                                   & (~ (IData)(vlTOPp->Datapath_PDUP__DOT__input_counter)));
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter 
        = (7U & (((0U != (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)) 
                  & (0U != (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)))
                  : (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)));
    vlTOPp->Datapath_PDUP__DOT__n_input_valid_buffer 
        = (1U & ((IData)(vlTOPp->Datapath_PDUP__DOT__input_valid_buffer)
                  ? (~ (IData)(vlTOPp->Datapath_PDUP__DOT__input_counter))
                  : (IData)(vlTOPp->input_valid)));
    vlTOPp->Datapath_PDUP__DOT__n_output_valid_buffer 
        = ((~ (IData)(vlTOPp->Datapath_PDUP__DOT__output_valid_buffer)) 
           & ((2U & (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__valid))
               ? (IData)(vlTOPp->Datapath_PDUP__DOT__output_counter)
               : (IData)(vlTOPp->Datapath_PDUP__DOT__output_valid_buffer)));
    vlTOPp->Datapath_PDUP__DOT__n_output_counter = 
        (1U & ((~ (IData)(vlTOPp->Datapath_PDUP__DOT__output_valid_buffer)) 
               & ((2U & (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__valid))
                   ? (~ (IData)(vlTOPp->Datapath_PDUP__DOT__output_counter))
                   : (IData)(vlTOPp->Datapath_PDUP__DOT__output_counter))));
    vlTOPp->Datapath_PDUP__DOT__n_input_buffer = ((IData)(vlTOPp->Datapath_PDUP__DOT__input_valid_buffer)
                                                   ? 
                                                  ((IData)(vlTOPp->Datapath_PDUP__DOT__input_counter)
                                                    ? 0ULL
                                                    : vlTOPp->Datapath_PDUP__DOT__input_buffer)
                                                   : vlTOPp->input_data);
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__n_valid 
        = ((2U & ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__valid) 
                  << 1U)) | ((0U == (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count))
                              ? 0U : (1U & ((4U >= (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)) 
                                            & ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO) 
                                               >> (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter))))));
    vlTOPp->Datapath_PDUP__DOT__n_output_buffer = ((IData)(vlTOPp->Datapath_PDUP__DOT__output_valid_buffer)
                                                    ? 0ULL
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__valid))
                                                     ? 
                                                    ((IData)(vlTOPp->Datapath_PDUP__DOT__output_counter)
                                                      ? 
                                                     (((QData)((IData)(
                                                                       ((IData)(1U) 
                                                                        + vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__negated_data))) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(vlTOPp->Datapath_PDUP__DOT__output_buffer)))
                                                      : (QData)((IData)(
                                                                        ((IData)(1U) 
                                                                         + vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__negated_data))))
                                                     : vlTOPp->Datapath_PDUP__DOT__output_buffer));
    vlTOPp->Datapath_PDUP__DOT__input_to_negator = 
        ((IData)(vlTOPp->Datapath_PDUP__DOT__input_valid_buffer)
          ? ((IData)(vlTOPp->Datapath_PDUP__DOT__input_counter)
              ? (IData)((vlTOPp->Datapath_PDUP__DOT__input_buffer 
                         >> 0x20U)) : (IData)(vlTOPp->Datapath_PDUP__DOT__input_buffer))
          : 0U);
    vlTOPp->Datapath_PDUP__DOT__valid_input_to_negator 
        = vlTOPp->Datapath_PDUP__DOT__input_valid_buffer;
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter 
        = (7U & (((0U != (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)) 
                  & (0U != (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter)))
                  : (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter)));
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter 
        = (7U & (((IData)(vlTOPp->Datapath_PDUP__DOT__valid_input_to_negator) 
                  & (4U > (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)))
                  : (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)));
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter 
        = (7U & (((IData)(vlTOPp->Datapath_PDUP__DOT__valid_input_to_negator) 
                  & (4U > (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)))
                  : (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)));
}

void VDatapath_PDUP::_eval_initial(VDatapath_PDUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDUP::_eval_initial\n"); );
    VDatapath_PDUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VDatapath_PDUP::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDUP::final\n"); );
    // Variables
    VDatapath_PDUP__Syms* __restrict vlSymsp = this->__VlSymsp;
    VDatapath_PDUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VDatapath_PDUP::_eval_settle(VDatapath_PDUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDUP::_eval_settle\n"); );
    VDatapath_PDUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VDatapath_PDUP::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDUP::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    input_valid = VL_RAND_RESET_I(1);
    input_data = VL_RAND_RESET_Q(64);
    output_valid = VL_RAND_RESET_I(1);
    output_data = VL_RAND_RESET_Q(64);
    Datapath_PDUP__DOT__input_counter = VL_RAND_RESET_I(1);
    Datapath_PDUP__DOT__n_input_counter = VL_RAND_RESET_I(1);
    Datapath_PDUP__DOT__output_counter = VL_RAND_RESET_I(1);
    Datapath_PDUP__DOT__n_output_counter = VL_RAND_RESET_I(1);
    Datapath_PDUP__DOT__input_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_PDUP__DOT__n_input_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_PDUP__DOT__output_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_PDUP__DOT__n_output_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_PDUP__DOT__input_buffer = VL_RAND_RESET_Q(64);
    Datapath_PDUP__DOT__n_input_buffer = VL_RAND_RESET_Q(64);
    Datapath_PDUP__DOT__output_buffer = VL_RAND_RESET_Q(64);
    Datapath_PDUP__DOT__n_output_buffer = VL_RAND_RESET_Q(64);
    Datapath_PDUP__DOT__input_to_negator = VL_RAND_RESET_I(32);
    Datapath_PDUP__DOT__valid_input_to_negator = VL_RAND_RESET_I(1);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__input_buffer = VL_RAND_RESET_I(32);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__negated_data = VL_RAND_RESET_I(32);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__valid = VL_RAND_RESET_I(2);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__n_valid = VL_RAND_RESET_I(2);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(160, Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter = VL_RAND_RESET_I(3);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter = VL_RAND_RESET_I(3);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter = VL_RAND_RESET_I(3);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter = VL_RAND_RESET_I(3);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count = VL_RAND_RESET_I(3);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO = VL_RAND_RESET_I(5);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter = VL_RAND_RESET_I(3);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter = VL_RAND_RESET_I(3);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter = VL_RAND_RESET_I(3);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter = VL_RAND_RESET_I(3);
    Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT____Vlvbound1 = VL_RAND_RESET_I(1);
}
