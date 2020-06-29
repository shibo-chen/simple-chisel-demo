// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_STME.h for the primary calling header

#include "VDatapath_STME.h"
#include "VDatapath_STME__Syms.h"

//==========

VL_CTOR_IMP(VDatapath_STME) {
    VDatapath_STME__Syms* __restrict vlSymsp = __VlSymsp = new VDatapath_STME__Syms(this, name());
    VDatapath_STME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VDatapath_STME::__Vconfigure(VDatapath_STME__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-10);
}

VDatapath_STME::~VDatapath_STME() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VDatapath_STME::_settle__TOP__2(VDatapath_STME__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STME::_settle__TOP__2\n"); );
    VDatapath_STME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp33[4];
    // Body
    vlTOPp->output_valid = (1U & ((IData)(vlTOPp->Datapath_STME__DOT__output_counter) 
                                  | ((IData)(vlTOPp->Datapath_STME__DOT__output_counter) 
                                     >> 1U)));
    vlTOPp->Datapath_STME__DOT__n_next_to_decrypt = 
        ((IData)(vlTOPp->input_valid) & (IData)(vlTOPp->Datapath_STME__DOT__input_counter));
    vlTOPp->Datapath_STME__DOT__n_input_counter = (1U 
                                                   & ((IData)(vlTOPp->input_valid)
                                                       ? 
                                                      (~ (IData)(vlTOPp->Datapath_STME__DOT__input_counter))
                                                       : (IData)(vlTOPp->Datapath_STME__DOT__input_counter)));
    vlTOPp->output_data = ((2U & (IData)(vlTOPp->Datapath_STME__DOT__output_counter))
                            ? (((QData)((IData)(vlTOPp->Datapath_STME__DOT__output_buffer[3U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->Datapath_STME__DOT__output_buffer[2U])))
                            : (((QData)((IData)(vlTOPp->Datapath_STME__DOT__output_buffer[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->Datapath_STME__DOT__output_buffer[0U]))));
    if ((8U & (IData)(vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__valid))) {
        vlTOPp->Datapath_STME__DOT__n_output_counter = 1U;
        vlTOPp->Datapath_STME__DOT__n_output_buffer[0U] 
            = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xcU];
        vlTOPp->Datapath_STME__DOT__n_output_buffer[1U] 
            = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xdU];
        vlTOPp->Datapath_STME__DOT__n_output_buffer[2U] 
            = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xeU];
        vlTOPp->Datapath_STME__DOT__n_output_buffer[3U] 
            = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xfU];
    } else {
        vlTOPp->Datapath_STME__DOT__n_output_counter 
            = ((1U & (IData)(vlTOPp->Datapath_STME__DOT__output_counter))
                ? 2U : 0U);
        vlTOPp->Datapath_STME__DOT__n_output_buffer[0U] 
            = vlTOPp->Datapath_STME__DOT__output_buffer[0U];
        vlTOPp->Datapath_STME__DOT__n_output_buffer[1U] 
            = vlTOPp->Datapath_STME__DOT__output_buffer[1U];
        vlTOPp->Datapath_STME__DOT__n_output_buffer[2U] 
            = vlTOPp->Datapath_STME__DOT__output_buffer[2U];
        vlTOPp->Datapath_STME__DOT__n_output_buffer[3U] 
            = vlTOPp->Datapath_STME__DOT__output_buffer[3U];
    }
    VL_EXTEND_WQ(128,64, __Vtemp33, vlTOPp->input_data);
    if (vlTOPp->input_valid) {
        vlTOPp->Datapath_STME__DOT__n_input_buffer[0U] 
            = ((IData)(vlTOPp->Datapath_STME__DOT__input_counter)
                ? (IData)((((QData)((IData)(vlTOPp->Datapath_STME__DOT__input_buffer[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlTOPp->Datapath_STME__DOT__input_buffer[0U]))))
                : __Vtemp33[0U]);
        vlTOPp->Datapath_STME__DOT__n_input_buffer[1U] 
            = ((IData)(vlTOPp->Datapath_STME__DOT__input_counter)
                ? (IData)(((((QData)((IData)(vlTOPp->Datapath_STME__DOT__input_buffer[1U])) 
                             << 0x20U) | (QData)((IData)(
                                                         vlTOPp->Datapath_STME__DOT__input_buffer[0U]))) 
                           >> 0x20U)) : __Vtemp33[1U]);
        vlTOPp->Datapath_STME__DOT__n_input_buffer[2U] 
            = ((IData)(vlTOPp->Datapath_STME__DOT__input_counter)
                ? (IData)(vlTOPp->input_data) : __Vtemp33[2U]);
        vlTOPp->Datapath_STME__DOT__n_input_buffer[3U] 
            = ((IData)(vlTOPp->Datapath_STME__DOT__input_counter)
                ? (IData)((vlTOPp->input_data >> 0x20U))
                : __Vtemp33[3U]);
    } else {
        vlTOPp->Datapath_STME__DOT__n_input_buffer[0U] 
            = vlTOPp->Datapath_STME__DOT__input_buffer[0U];
        vlTOPp->Datapath_STME__DOT__n_input_buffer[1U] 
            = vlTOPp->Datapath_STME__DOT__input_buffer[1U];
        vlTOPp->Datapath_STME__DOT__n_input_buffer[2U] 
            = vlTOPp->Datapath_STME__DOT__input_buffer[2U];
        vlTOPp->Datapath_STME__DOT__n_input_buffer[3U] 
            = vlTOPp->Datapath_STME__DOT__input_buffer[3U];
    }
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[4U] 
        = vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[0U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[5U] 
        = vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[1U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[6U] 
        = vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[2U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[7U] 
        = vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[3U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_valid 
        = ((0xdU & (IData)(vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_valid)) 
           | (2U & ((IData)(vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[8U] 
        = vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[4U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[9U] 
        = vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[5U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xaU] 
        = vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[6U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xbU] 
        = vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[7U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_valid 
        = ((0xbU & (IData)(vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_valid)) 
           | (4U & ((IData)(vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xcU] 
        = vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[8U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xdU] 
        = vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[9U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xeU] 
        = vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xaU];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xfU] 
        = vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xbU];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_valid 
        = ((7U & (IData)(vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_valid)) 
           | (8U & ((IData)(vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0U] 
        = vlTOPp->Datapath_STME__DOT__input_buffer[0U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[1U] 
        = vlTOPp->Datapath_STME__DOT__input_buffer[1U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[2U] 
        = vlTOPp->Datapath_STME__DOT__input_buffer[2U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[3U] 
        = vlTOPp->Datapath_STME__DOT__input_buffer[3U];
    vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_valid 
        = ((0xeU & (IData)(vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_valid)) 
           | (IData)(vlTOPp->Datapath_STME__DOT__next_to_decrypt));
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[4U] 
        = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[5U] 
        = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[1U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[6U] 
        = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[2U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[7U] 
        = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[3U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_valid 
        = ((0xdU & (IData)(vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_valid)) 
           | (2U & ((IData)(vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[8U] 
        = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[4U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[9U] 
        = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[5U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xaU] 
        = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[6U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xbU] 
        = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[7U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_valid 
        = ((0xbU & (IData)(vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_valid)) 
           | (4U & ((IData)(vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xcU] 
        = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[8U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xdU] 
        = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[9U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xeU] 
        = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xaU];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xfU] 
        = vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xbU];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_valid 
        = ((7U & (IData)(vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_valid)) 
           | (8U & ((IData)(vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0U] 
        = vlTOPp->Datapath_STME__DOT__neg_to_enc_buffer[0U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[1U] 
        = vlTOPp->Datapath_STME__DOT__neg_to_enc_buffer[1U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[2U] 
        = vlTOPp->Datapath_STME__DOT__neg_to_enc_buffer[2U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[3U] 
        = vlTOPp->Datapath_STME__DOT__neg_to_enc_buffer[3U];
    vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_valid 
        = ((0xeU & (IData)(vlTOPp->Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_valid)) 
           | (IData)(vlTOPp->Datapath_STME__DOT__output_valid_buffer));
    vlTOPp->Datapath_STME__DOT__n_counter = ((IData)(vlTOPp->Datapath_STME__DOT__input_valid_buffer) 
                                             & (~ (IData)(vlTOPp->Datapath_STME__DOT__counter)));
    vlTOPp->Datapath_STME__DOT__n_input_valid_buffer 
        = (1U & ((IData)(vlTOPp->Datapath_STME__DOT__input_valid_buffer)
                  ? (~ (IData)(vlTOPp->Datapath_STME__DOT__counter))
                  : ((IData)(vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                     >> 3U)));
    if (vlTOPp->Datapath_STME__DOT__input_valid_buffer) {
        if (vlTOPp->Datapath_STME__DOT__counter) {
            vlTOPp->Datapath_STME__DOT__n_neg_to_enc_buffer[2U] 
                = (IData)((1ULL + (~ ((IData)(vlTOPp->Datapath_STME__DOT__input_valid_buffer)
                                       ? ((IData)(vlTOPp->Datapath_STME__DOT__counter)
                                           ? (((QData)((IData)(
                                                               vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[3U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[2U])))
                                           : (((QData)((IData)(
                                                               vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[0U]))))
                                       : 0ULL))));
            vlTOPp->Datapath_STME__DOT__n_neg_to_enc_buffer[3U] 
                = (IData)(((1ULL + (~ ((IData)(vlTOPp->Datapath_STME__DOT__input_valid_buffer)
                                        ? ((IData)(vlTOPp->Datapath_STME__DOT__counter)
                                            ? (((QData)((IData)(
                                                                vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[3U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[2U])))
                                            : (((QData)((IData)(
                                                                vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[1U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[0U]))))
                                        : 0ULL))) >> 0x20U));
            vlTOPp->Datapath_STME__DOT__n_neg_to_enc_buffer[0U] 
                = (IData)((((QData)((IData)(vlTOPp->Datapath_STME__DOT__neg_to_enc_buffer[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlTOPp->Datapath_STME__DOT__neg_to_enc_buffer[0U]))));
            vlTOPp->Datapath_STME__DOT__n_neg_to_enc_buffer[1U] 
                = (IData)(((((QData)((IData)(vlTOPp->Datapath_STME__DOT__neg_to_enc_buffer[1U])) 
                             << 0x20U) | (QData)((IData)(
                                                         vlTOPp->Datapath_STME__DOT__neg_to_enc_buffer[0U]))) 
                           >> 0x20U));
        } else {
            vlTOPp->Datapath_STME__DOT__n_neg_to_enc_buffer[2U] = 0U;
            vlTOPp->Datapath_STME__DOT__n_neg_to_enc_buffer[3U] = 0U;
            vlTOPp->Datapath_STME__DOT__n_neg_to_enc_buffer[0U] 
                = (IData)((1ULL + (~ ((IData)(vlTOPp->Datapath_STME__DOT__input_valid_buffer)
                                       ? ((IData)(vlTOPp->Datapath_STME__DOT__counter)
                                           ? (((QData)((IData)(
                                                               vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[3U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[2U])))
                                           : (((QData)((IData)(
                                                               vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[0U]))))
                                       : 0ULL))));
            vlTOPp->Datapath_STME__DOT__n_neg_to_enc_buffer[1U] 
                = (IData)(((1ULL + (~ ((IData)(vlTOPp->Datapath_STME__DOT__input_valid_buffer)
                                        ? ((IData)(vlTOPp->Datapath_STME__DOT__counter)
                                            ? (((QData)((IData)(
                                                                vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[3U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[2U])))
                                            : (((QData)((IData)(
                                                                vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[1U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[0U]))))
                                        : 0ULL))) >> 0x20U));
        }
    } else {
        vlTOPp->Datapath_STME__DOT__n_neg_to_enc_buffer[0U] = 0U;
        vlTOPp->Datapath_STME__DOT__n_neg_to_enc_buffer[1U] = 0U;
        vlTOPp->Datapath_STME__DOT__n_neg_to_enc_buffer[2U] = 0U;
        vlTOPp->Datapath_STME__DOT__n_neg_to_enc_buffer[3U] = 0U;
    }
    if (vlTOPp->Datapath_STME__DOT__input_valid_buffer) {
        vlTOPp->Datapath_STME__DOT__n_dec_to_neg_buffer[0U] 
            = ((IData)(vlTOPp->Datapath_STME__DOT__counter)
                ? 0U : vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[0U]);
        vlTOPp->Datapath_STME__DOT__n_dec_to_neg_buffer[1U] 
            = ((IData)(vlTOPp->Datapath_STME__DOT__counter)
                ? 0U : vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[1U]);
        vlTOPp->Datapath_STME__DOT__n_dec_to_neg_buffer[2U] 
            = ((IData)(vlTOPp->Datapath_STME__DOT__counter)
                ? 0U : vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[2U]);
        vlTOPp->Datapath_STME__DOT__n_dec_to_neg_buffer[3U] 
            = ((IData)(vlTOPp->Datapath_STME__DOT__counter)
                ? 0U : vlTOPp->Datapath_STME__DOT__dec_to_neg_buffer[3U]);
    } else {
        vlTOPp->Datapath_STME__DOT__n_dec_to_neg_buffer[0U] 
            = ((8U & (IData)(vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__valid))
                ? vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xcU]
                : 0U);
        vlTOPp->Datapath_STME__DOT__n_dec_to_neg_buffer[1U] 
            = ((8U & (IData)(vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__valid))
                ? vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xdU]
                : 0U);
        vlTOPp->Datapath_STME__DOT__n_dec_to_neg_buffer[2U] 
            = ((8U & (IData)(vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__valid))
                ? vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xeU]
                : 0U);
        vlTOPp->Datapath_STME__DOT__n_dec_to_neg_buffer[3U] 
            = ((8U & (IData)(vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__valid))
                ? vlTOPp->Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xfU]
                : 0U);
    }
}

void VDatapath_STME::_eval_initial(VDatapath_STME__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STME::_eval_initial\n"); );
    VDatapath_STME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VDatapath_STME::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STME::final\n"); );
    // Variables
    VDatapath_STME__Syms* __restrict vlSymsp = this->__VlSymsp;
    VDatapath_STME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VDatapath_STME::_eval_settle(VDatapath_STME__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STME::_eval_settle\n"); );
    VDatapath_STME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VDatapath_STME::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STME::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    input_valid = VL_RAND_RESET_I(1);
    input_data = VL_RAND_RESET_Q(64);
    output_valid = VL_RAND_RESET_I(1);
    output_data = VL_RAND_RESET_Q(64);
    Datapath_STME__DOT__next_to_decrypt = VL_RAND_RESET_I(1);
    Datapath_STME__DOT__n_next_to_decrypt = VL_RAND_RESET_I(1);
    Datapath_STME__DOT__input_counter = VL_RAND_RESET_I(1);
    Datapath_STME__DOT__n_input_counter = VL_RAND_RESET_I(1);
    Datapath_STME__DOT__output_counter = VL_RAND_RESET_I(2);
    Datapath_STME__DOT__n_output_counter = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(128, Datapath_STME__DOT__input_buffer);
    VL_RAND_RESET_W(128, Datapath_STME__DOT__n_input_buffer);
    VL_RAND_RESET_W(128, Datapath_STME__DOT__output_buffer);
    VL_RAND_RESET_W(128, Datapath_STME__DOT__n_output_buffer);
    Datapath_STME__DOT__counter = VL_RAND_RESET_I(1);
    Datapath_STME__DOT__n_counter = VL_RAND_RESET_I(1);
    Datapath_STME__DOT__input_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_STME__DOT__n_input_valid_buffer = VL_RAND_RESET_I(1);
    Datapath_STME__DOT__output_valid_buffer = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, Datapath_STME__DOT__dec_to_neg_buffer);
    VL_RAND_RESET_W(128, Datapath_STME__DOT__n_dec_to_neg_buffer);
    VL_RAND_RESET_W(128, Datapath_STME__DOT__neg_to_enc_buffer);
    VL_RAND_RESET_W(128, Datapath_STME__DOT__n_neg_to_enc_buffer);
    VL_RAND_RESET_W(512, Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__buffer);
    Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__valid = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(512, Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_buffer);
    Datapath_STME__DOT__simulatedAESDecryptEngin__DOT__n_valid = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(512, Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__buffer);
    Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__valid = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(512, Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer);
    Datapath_STME__DOT__SimulatedAESEncryptEngin__DOT__n_valid = VL_RAND_RESET_I(4);
}
