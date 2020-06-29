// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_PTME.h for the primary calling header

#include "VDatapath_PTME.h"
#include "VDatapath_PTME__Syms.h"

//==========

VL_CTOR_IMP(VDatapath_PTME) {
    VDatapath_PTME__Syms* __restrict vlSymsp = __VlSymsp = new VDatapath_PTME__Syms(this, name());
    VDatapath_PTME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VDatapath_PTME::__Vconfigure(VDatapath_PTME__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-10);
}

VDatapath_PTME::~VDatapath_PTME() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VDatapath_PTME::_settle__TOP__2(VDatapath_PTME__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTME::_settle__TOP__2\n"); );
    VDatapath_PTME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp39[4];
    WData/*127:0*/ __Vtemp44[4];
    // Body
    vlTOPp->output_valid = (1U & ((IData)(vlTOPp->Datapath_PTME__DOT__output_counter) 
                                  | ((IData)(vlTOPp->Datapath_PTME__DOT__output_counter) 
                                     >> 1U)));
    vlTOPp->Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__n_valid 
        = (1U & (IData)(vlTOPp->Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__valid));
    vlTOPp->Datapath_PTME__DOT__n_next_to_decrypt = 
        ((IData)(vlTOPp->input_valid) & (IData)(vlTOPp->Datapath_PTME__DOT__input_counter));
    vlTOPp->Datapath_PTME__DOT__n_input_counter = (1U 
                                                   & ((IData)(vlTOPp->input_valid)
                                                       ? 
                                                      (~ (IData)(vlTOPp->Datapath_PTME__DOT__input_counter))
                                                       : (IData)(vlTOPp->Datapath_PTME__DOT__input_counter)));
    vlTOPp->output_data = ((2U & (IData)(vlTOPp->Datapath_PTME__DOT__output_counter))
                            ? (((QData)((IData)(vlTOPp->Datapath_PTME__DOT__output_buffer[3U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->Datapath_PTME__DOT__output_buffer[2U])))
                            : (((QData)((IData)(vlTOPp->Datapath_PTME__DOT__output_buffer[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->Datapath_PTME__DOT__output_buffer[0U]))));
    if ((8U & (IData)(vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__valid))) {
        vlTOPp->Datapath_PTME__DOT__n_output_counter = 1U;
        vlTOPp->Datapath_PTME__DOT__n_output_buffer[0U] 
            = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xcU];
        vlTOPp->Datapath_PTME__DOT__n_output_buffer[1U] 
            = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xdU];
        vlTOPp->Datapath_PTME__DOT__n_output_buffer[2U] 
            = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xeU];
        vlTOPp->Datapath_PTME__DOT__n_output_buffer[3U] 
            = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xfU];
    } else {
        vlTOPp->Datapath_PTME__DOT__n_output_counter 
            = ((1U & (IData)(vlTOPp->Datapath_PTME__DOT__output_counter))
                ? 2U : 0U);
        vlTOPp->Datapath_PTME__DOT__n_output_buffer[0U] 
            = vlTOPp->Datapath_PTME__DOT__output_buffer[0U];
        vlTOPp->Datapath_PTME__DOT__n_output_buffer[1U] 
            = vlTOPp->Datapath_PTME__DOT__output_buffer[1U];
        vlTOPp->Datapath_PTME__DOT__n_output_buffer[2U] 
            = vlTOPp->Datapath_PTME__DOT__output_buffer[2U];
        vlTOPp->Datapath_PTME__DOT__n_output_buffer[3U] 
            = vlTOPp->Datapath_PTME__DOT__output_buffer[3U];
    }
    vlTOPp->Datapath_PTME__DOT__n_output_valid_buffer 
        = ((~ (IData)(vlTOPp->Datapath_PTME__DOT__output_valid_buffer)) 
           & ((2U & (IData)(vlTOPp->Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__valid))
               ? (IData)(vlTOPp->Datapath_PTME__DOT__neg_output_counter)
               : (IData)(vlTOPp->Datapath_PTME__DOT__output_valid_buffer)));
    vlTOPp->Datapath_PTME__DOT__n_neg_output_counter 
        = (1U & ((~ (IData)(vlTOPp->Datapath_PTME__DOT__output_valid_buffer)) 
                 & ((2U & (IData)(vlTOPp->Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__valid))
                     ? (~ (IData)(vlTOPp->Datapath_PTME__DOT__neg_output_counter))
                     : (IData)(vlTOPp->Datapath_PTME__DOT__neg_output_counter))));
    VL_EXTEND_WQ(128,64, __Vtemp39, vlTOPp->input_data);
    if (vlTOPp->input_valid) {
        vlTOPp->Datapath_PTME__DOT__n_input_buffer[0U] 
            = ((IData)(vlTOPp->Datapath_PTME__DOT__input_counter)
                ? (IData)((((QData)((IData)(vlTOPp->Datapath_PTME__DOT__input_buffer[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlTOPp->Datapath_PTME__DOT__input_buffer[0U]))))
                : __Vtemp39[0U]);
        vlTOPp->Datapath_PTME__DOT__n_input_buffer[1U] 
            = ((IData)(vlTOPp->Datapath_PTME__DOT__input_counter)
                ? (IData)(((((QData)((IData)(vlTOPp->Datapath_PTME__DOT__input_buffer[1U])) 
                             << 0x20U) | (QData)((IData)(
                                                         vlTOPp->Datapath_PTME__DOT__input_buffer[0U]))) 
                           >> 0x20U)) : __Vtemp39[1U]);
        vlTOPp->Datapath_PTME__DOT__n_input_buffer[2U] 
            = ((IData)(vlTOPp->Datapath_PTME__DOT__input_counter)
                ? (IData)(vlTOPp->input_data) : __Vtemp39[2U]);
        vlTOPp->Datapath_PTME__DOT__n_input_buffer[3U] 
            = ((IData)(vlTOPp->Datapath_PTME__DOT__input_counter)
                ? (IData)((vlTOPp->input_data >> 0x20U))
                : __Vtemp39[3U]);
    } else {
        vlTOPp->Datapath_PTME__DOT__n_input_buffer[0U] 
            = vlTOPp->Datapath_PTME__DOT__input_buffer[0U];
        vlTOPp->Datapath_PTME__DOT__n_input_buffer[1U] 
            = vlTOPp->Datapath_PTME__DOT__input_buffer[1U];
        vlTOPp->Datapath_PTME__DOT__n_input_buffer[2U] 
            = vlTOPp->Datapath_PTME__DOT__input_buffer[2U];
        vlTOPp->Datapath_PTME__DOT__n_input_buffer[3U] 
            = vlTOPp->Datapath_PTME__DOT__input_buffer[3U];
    }
    VL_EXTEND_WQ(128,64, __Vtemp44, (1ULL + vlTOPp->Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__negated_data));
    if (vlTOPp->Datapath_PTME__DOT__output_valid_buffer) {
        vlTOPp->Datapath_PTME__DOT__n_neg_to_enc_buffer[0U] = 0U;
        vlTOPp->Datapath_PTME__DOT__n_neg_to_enc_buffer[1U] = 0U;
        vlTOPp->Datapath_PTME__DOT__n_neg_to_enc_buffer[2U] = 0U;
        vlTOPp->Datapath_PTME__DOT__n_neg_to_enc_buffer[3U] = 0U;
    } else {
        vlTOPp->Datapath_PTME__DOT__n_neg_to_enc_buffer[0U] 
            = ((2U & (IData)(vlTOPp->Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__valid))
                ? ((IData)(vlTOPp->Datapath_PTME__DOT__neg_output_counter)
                    ? (IData)((((QData)((IData)(vlTOPp->Datapath_PTME__DOT__neg_to_enc_buffer[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->Datapath_PTME__DOT__neg_to_enc_buffer[0U]))))
                    : __Vtemp44[0U]) : vlTOPp->Datapath_PTME__DOT__neg_to_enc_buffer[0U]);
        vlTOPp->Datapath_PTME__DOT__n_neg_to_enc_buffer[1U] 
            = ((2U & (IData)(vlTOPp->Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__valid))
                ? ((IData)(vlTOPp->Datapath_PTME__DOT__neg_output_counter)
                    ? (IData)(((((QData)((IData)(vlTOPp->Datapath_PTME__DOT__neg_to_enc_buffer[1U])) 
                                 << 0x20U) | (QData)((IData)(
                                                             vlTOPp->Datapath_PTME__DOT__neg_to_enc_buffer[0U]))) 
                               >> 0x20U)) : __Vtemp44[1U])
                : vlTOPp->Datapath_PTME__DOT__neg_to_enc_buffer[1U]);
        vlTOPp->Datapath_PTME__DOT__n_neg_to_enc_buffer[2U] 
            = ((2U & (IData)(vlTOPp->Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__valid))
                ? ((IData)(vlTOPp->Datapath_PTME__DOT__neg_output_counter)
                    ? (IData)((1ULL + vlTOPp->Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__negated_data))
                    : __Vtemp44[2U]) : vlTOPp->Datapath_PTME__DOT__neg_to_enc_buffer[2U]);
        vlTOPp->Datapath_PTME__DOT__n_neg_to_enc_buffer[3U] 
            = ((2U & (IData)(vlTOPp->Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__valid))
                ? ((IData)(vlTOPp->Datapath_PTME__DOT__neg_output_counter)
                    ? (IData)(((1ULL + vlTOPp->Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__negated_data) 
                               >> 0x20U)) : __Vtemp44[3U])
                : vlTOPp->Datapath_PTME__DOT__neg_to_enc_buffer[3U]);
    }
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[4U] 
        = vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[0U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[5U] 
        = vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[1U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[6U] 
        = vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[2U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[7U] 
        = vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[3U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_valid 
        = ((0xdU & (IData)(vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_valid)) 
           | (2U & ((IData)(vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[8U] 
        = vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[4U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[9U] 
        = vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[5U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xaU] 
        = vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[6U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xbU] 
        = vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[7U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_valid 
        = ((0xbU & (IData)(vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_valid)) 
           | (4U & ((IData)(vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xcU] 
        = vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[8U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xdU] 
        = vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[9U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xeU] 
        = vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xaU];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xfU] 
        = vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xbU];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_valid 
        = ((7U & (IData)(vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_valid)) 
           | (8U & ((IData)(vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0U] 
        = vlTOPp->Datapath_PTME__DOT__input_buffer[0U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[1U] 
        = vlTOPp->Datapath_PTME__DOT__input_buffer[1U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[2U] 
        = vlTOPp->Datapath_PTME__DOT__input_buffer[2U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[3U] 
        = vlTOPp->Datapath_PTME__DOT__input_buffer[3U];
    vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_valid 
        = ((0xeU & (IData)(vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_valid)) 
           | (IData)(vlTOPp->Datapath_PTME__DOT__next_to_decrypt));
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[4U] 
        = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[5U] 
        = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[1U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[6U] 
        = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[2U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[7U] 
        = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[3U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_valid 
        = ((0xdU & (IData)(vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_valid)) 
           | (2U & ((IData)(vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[8U] 
        = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[4U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[9U] 
        = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[5U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xaU] 
        = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[6U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xbU] 
        = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[7U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_valid 
        = ((0xbU & (IData)(vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_valid)) 
           | (4U & ((IData)(vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xcU] 
        = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[8U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xdU] 
        = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[9U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xeU] 
        = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xaU];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xfU] 
        = vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xbU];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_valid 
        = ((7U & (IData)(vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_valid)) 
           | (8U & ((IData)(vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0U] 
        = vlTOPp->Datapath_PTME__DOT__neg_to_enc_buffer[0U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[1U] 
        = vlTOPp->Datapath_PTME__DOT__neg_to_enc_buffer[1U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[2U] 
        = vlTOPp->Datapath_PTME__DOT__neg_to_enc_buffer[2U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[3U] 
        = vlTOPp->Datapath_PTME__DOT__neg_to_enc_buffer[3U];
    vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_valid 
        = ((0xeU & (IData)(vlTOPp->Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_valid)) 
           | (IData)(vlTOPp->Datapath_PTME__DOT__output_valid_buffer));
    vlTOPp->Datapath_PTME__DOT__n_neg_intput_counter 
        = ((IData)(vlTOPp->Datapath_PTME__DOT__input_valid_buffer) 
           & (~ (IData)(vlTOPp->Datapath_PTME__DOT__neg_intput_counter)));
    if (vlTOPp->Datapath_PTME__DOT__input_valid_buffer) {
        vlTOPp->Datapath_PTME__DOT__n_input_valid_buffer 
            = (1U & (~ (IData)(vlTOPp->Datapath_PTME__DOT__neg_intput_counter)));
        vlTOPp->Datapath_PTME__DOT__n_dec_to_neg_buffer[0U] 
            = ((IData)(vlTOPp->Datapath_PTME__DOT__neg_intput_counter)
                ? 0U : vlTOPp->Datapath_PTME__DOT__dec_to_neg_buffer[0U]);
        vlTOPp->Datapath_PTME__DOT__n_dec_to_neg_buffer[1U] 
            = ((IData)(vlTOPp->Datapath_PTME__DOT__neg_intput_counter)
                ? 0U : vlTOPp->Datapath_PTME__DOT__dec_to_neg_buffer[1U]);
        vlTOPp->Datapath_PTME__DOT__n_dec_to_neg_buffer[2U] 
            = ((IData)(vlTOPp->Datapath_PTME__DOT__neg_intput_counter)
                ? 0U : vlTOPp->Datapath_PTME__DOT__dec_to_neg_buffer[2U]);
        vlTOPp->Datapath_PTME__DOT__n_dec_to_neg_buffer[3U] 
            = ((IData)(vlTOPp->Datapath_PTME__DOT__neg_intput_counter)
                ? 0U : vlTOPp->Datapath_PTME__DOT__dec_to_neg_buffer[3U]);
    } else {
        vlTOPp->Datapath_PTME__DOT__n_input_valid_buffer 
            = (1U & ((IData)(vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                     >> 3U));
        vlTOPp->Datapath_PTME__DOT__n_dec_to_neg_buffer[0U] 
            = ((8U & (IData)(vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__valid))
                ? vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xcU]
                : vlTOPp->Datapath_PTME__DOT__dec_to_neg_buffer[0U]);
        vlTOPp->Datapath_PTME__DOT__n_dec_to_neg_buffer[1U] 
            = ((8U & (IData)(vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__valid))
                ? vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xdU]
                : vlTOPp->Datapath_PTME__DOT__dec_to_neg_buffer[1U]);
        vlTOPp->Datapath_PTME__DOT__n_dec_to_neg_buffer[2U] 
            = ((8U & (IData)(vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__valid))
                ? vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xeU]
                : vlTOPp->Datapath_PTME__DOT__dec_to_neg_buffer[2U]);
        vlTOPp->Datapath_PTME__DOT__n_dec_to_neg_buffer[3U] 
            = ((8U & (IData)(vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__valid))
                ? vlTOPp->Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xfU]
                : vlTOPp->Datapath_PTME__DOT__dec_to_neg_buffer[3U]);
    }
}

void VDatapath_PTME::_eval_initial(VDatapath_PTME__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTME::_eval_initial\n"); );
    VDatapath_PTME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VDatapath_PTME::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTME::final\n"); );
    // Variables
    VDatapath_PTME__Syms* __restrict vlSymsp = this->__VlSymsp;
    VDatapath_PTME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VDatapath_PTME::_eval_settle(VDatapath_PTME__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTME::_eval_settle\n"); );
    VDatapath_PTME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VDatapath_PTME::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTME::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    input_valid = VL_RAND_RESET_I(1);
    input_data = VL_RAND_RESET_Q(64);
    output_valid = VL_RAND_RESET_I(1);
    output_data = VL_RAND_RESET_Q(64);
    Datapath_PTME__DOT__next_to_decrypt = VL_RAND_RESET_I(1);
    Datapath_PTME__DOT__n_next_to_decrypt = VL_RAND_RESET_I(1);
    Datapath_PTME__DOT__input_counter = VL_RAND_RESET_I(1);
    Datapath_PTME__DOT__n_input_counter = VL_RAND_RESET_I(1);
    Datapath_PTME__DOT__output_counter = VL_RAND_RESET_I(2);
    Datapath_PTME__DOT__n_output_counter = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(128, Datapath_PTME__DOT__input_buffer);
    VL_RAND_RESET_W(128, Datapath_PTME__DOT__n_input_buffer);
    VL_RAND_RESET_W(128, Datapath_PTME__DOT__output_buffer);
    VL_RAND_RESET_W(128, Datapath_PTME__DOT__n_output_buffer);
    Datapath_PTME__DOT__neg_intput_counter = VL_RAND_RESET_I(1);
    Datapath_PTME__DOT__n_neg_intput_counter = VL_RAND_RESET_I(1);
    Datapath_PTME__DOT__neg_output_counter = VL_RAND_RESET_I(1);
    Datapath_PTME__DOT__n_neg_output_counter = VL_RAND_RESET_I(1);
    Datapath_PTME__DOT__input_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_PTME__DOT__n_input_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_PTME__DOT__output_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_PTME__DOT__n_output_valid_buffer = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, Datapath_PTME__DOT__dec_to_neg_buffer);
    VL_RAND_RESET_W(128, Datapath_PTME__DOT__n_dec_to_neg_buffer);
    VL_RAND_RESET_W(128, Datapath_PTME__DOT__neg_to_enc_buffer);
    VL_RAND_RESET_W(128, Datapath_PTME__DOT__n_neg_to_enc_buffer);
    VL_RAND_RESET_W(512, Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__buffer);
    Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__valid = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(512, Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_buffer);
    Datapath_PTME__DOT__simulatedAESDecryptEngin__DOT__n_valid = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(512, Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__buffer);
    Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__valid = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(512, Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer);
    Datapath_PTME__DOT__SimulatedAESEncryptEngin__DOT__n_valid = VL_RAND_RESET_I(4);
    Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__input_buffer = VL_RAND_RESET_Q(64);
    Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__negated_data = VL_RAND_RESET_Q(64);
    Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__valid = VL_RAND_RESET_I(2);
    Datapath_PTME__DOT__pipelinedTightlyCoupledNegator__DOT__n_valid = VL_RAND_RESET_I(1);
}
