// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_PDME.h for the primary calling header

#include "VDatapath_PDME.h"
#include "VDatapath_PDME__Syms.h"

//==========

void VDatapath_PDME::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDatapath_PDME::eval\n"); );
    VDatapath_PDME__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("Datapath_PDME.sv", 15, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VDatapath_PDME::_eval_initial_loop(VDatapath_PDME__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("Datapath_PDME.sv", 15, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VDatapath_PDME::_sequent__TOP__1(VDatapath_PDME__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDME::_sequent__TOP__1\n"); );
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp22[4];
    // Body
    vlTOPp->Datapath_PDME__DOT__next_to_decrypt = (
                                                   (~ (IData)(vlTOPp->reset)) 
                                                   & (IData)(vlTOPp->Datapath_PDME__DOT__n_next_to_decrypt));
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDME__DOT__output_buffer[0U] = 0U;
        vlTOPp->Datapath_PDME__DOT__output_buffer[1U] = 0U;
        vlTOPp->Datapath_PDME__DOT__output_buffer[2U] = 0U;
        vlTOPp->Datapath_PDME__DOT__output_buffer[3U] = 0U;
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter = 0U;
        vlTOPp->Datapath_PDME__DOT__output_counter = 0U;
    } else {
        vlTOPp->Datapath_PDME__DOT__output_buffer[0U] 
            = vlTOPp->Datapath_PDME__DOT__n_output_buffer[0U];
        vlTOPp->Datapath_PDME__DOT__output_buffer[1U] 
            = vlTOPp->Datapath_PDME__DOT__n_output_buffer[1U];
        vlTOPp->Datapath_PDME__DOT__output_buffer[2U] 
            = vlTOPp->Datapath_PDME__DOT__n_output_buffer[2U];
        vlTOPp->Datapath_PDME__DOT__output_buffer[3U] 
            = vlTOPp->Datapath_PDME__DOT__n_output_buffer[3U];
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter 
            = vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter;
        vlTOPp->Datapath_PDME__DOT__output_counter 
            = vlTOPp->Datapath_PDME__DOT__n_output_counter;
    }
    vlTOPp->Datapath_PDME__DOT__input_counter = ((~ (IData)(vlTOPp->reset)) 
                                                 & (IData)(vlTOPp->Datapath_PDME__DOT__n_input_counter));
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDME__DOT__input_buffer[0U] = 0U;
        vlTOPp->Datapath_PDME__DOT__input_buffer[1U] = 0U;
        vlTOPp->Datapath_PDME__DOT__input_buffer[2U] = 0U;
        vlTOPp->Datapath_PDME__DOT__input_buffer[3U] = 0U;
        vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[0U] = 0U;
        vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[1U] = 0U;
        vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[2U] = 0U;
        vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[3U] = 0U;
    } else {
        vlTOPp->Datapath_PDME__DOT__input_buffer[0U] 
            = vlTOPp->Datapath_PDME__DOT__n_input_buffer[0U];
        vlTOPp->Datapath_PDME__DOT__input_buffer[1U] 
            = vlTOPp->Datapath_PDME__DOT__n_input_buffer[1U];
        vlTOPp->Datapath_PDME__DOT__input_buffer[2U] 
            = vlTOPp->Datapath_PDME__DOT__n_input_buffer[2U];
        vlTOPp->Datapath_PDME__DOT__input_buffer[3U] 
            = vlTOPp->Datapath_PDME__DOT__n_input_buffer[3U];
        vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[0U] 
            = vlTOPp->Datapath_PDME__DOT__n_neg_to_enc_buffer[0U];
        vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[1U] 
            = vlTOPp->Datapath_PDME__DOT__n_neg_to_enc_buffer[1U];
        vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[2U] 
            = vlTOPp->Datapath_PDME__DOT__n_neg_to_enc_buffer[2U];
        vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[3U] 
            = vlTOPp->Datapath_PDME__DOT__n_neg_to_enc_buffer[3U];
    }
    vlTOPp->Datapath_PDME__DOT__neg_output_counter 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->Datapath_PDME__DOT__n_neg_output_counter));
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid = 0U;
    } else {
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid 
            = ((1U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid)) 
               | (2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__n_valid)));
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid 
            = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid)) 
               | (1U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__n_valid)));
    }
    vlTOPp->Datapath_PDME__DOT__output_valid_buffer 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->Datapath_PDME__DOT__n_output_valid_buffer));
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0U] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[1U] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[2U] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[3U] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[4U] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[5U] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[6U] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[7U] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[8U] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[9U] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xaU] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xbU] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xcU] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xdU] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xeU] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xfU] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0U] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[1U] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[2U] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[3U] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[4U] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[5U] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[6U] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[7U] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[8U] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[9U] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xaU] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xbU] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xcU] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xdU] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xeU] = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xfU] = 0U;
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid = 0U;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid = 0U;
    } else {
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0U];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[1U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[1U];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[2U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[2U];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[3U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[3U];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[4U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[4U];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[5U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[5U];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[6U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[6U];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[7U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[7U];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[8U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[8U];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[9U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[9U];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xaU] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xaU];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xbU] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xbU];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xcU] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xcU];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xdU] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xdU];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xeU] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xeU];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xfU] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xfU];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0U] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0U];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[1U] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[1U];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[2U] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[2U];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[3U] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[3U];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[4U] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[4U];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[5U] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[5U];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[6U] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[6U];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[7U] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[7U];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[8U] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[8U];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[9U] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[9U];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xaU] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xaU];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xbU] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xbU];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xcU] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xcU];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xdU] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xdU];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xeU] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xeU];
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xfU] 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xfU];
        vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_valid;
        vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid 
            = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_valid;
    }
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO = 0U;
    } else {
        if (((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer) 
             & (4U > (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)))) {
            vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT____Vlvbound1 
                = vlTOPp->Datapath_PDME__DOT__input_valid_buffer;
            if ((4U >= (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter))) {
                vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO 
                    = (((~ ((IData)(1U) << (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter))) 
                        & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO)) 
                       | ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT____Vlvbound1) 
                          << (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)));
            }
        }
    }
    vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count 
        = (7U & (((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter) 
                  > (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter))
                  ? (((0U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter)) 
                      & (4U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)))
                      ? ((IData)(4U) - (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter))
                      : ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter) 
                         - (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter)))
                  : (((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter) 
                      > (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter))
                      ? ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter) 
                         - (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter))
                      : 0U)));
    vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data 
        = ((IData)(vlTOPp->reset) ? 0ULL : (~ vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__input_buffer));
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_valid 
        = ((0xeU & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_valid)) 
           | (IData)(vlTOPp->Datapath_PDME__DOT__next_to_decrypt));
    vlTOPp->output_valid = (1U & ((IData)(vlTOPp->Datapath_PDME__DOT__output_counter) 
                                  | ((IData)(vlTOPp->Datapath_PDME__DOT__output_counter) 
                                     >> 1U)));
    vlTOPp->output_data = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__output_counter))
                            ? (((QData)((IData)(vlTOPp->Datapath_PDME__DOT__output_buffer[3U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->Datapath_PDME__DOT__output_buffer[2U])))
                            : (((QData)((IData)(vlTOPp->Datapath_PDME__DOT__output_buffer[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->Datapath_PDME__DOT__output_buffer[0U]))));
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0U] 
        = vlTOPp->Datapath_PDME__DOT__input_buffer[0U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[1U] 
        = vlTOPp->Datapath_PDME__DOT__input_buffer[1U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[2U] 
        = vlTOPp->Datapath_PDME__DOT__input_buffer[2U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[3U] 
        = vlTOPp->Datapath_PDME__DOT__input_buffer[3U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0U] 
        = vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[0U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[1U] 
        = vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[1U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[2U] 
        = vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[2U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[3U] 
        = vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[3U];
    vlTOPp->Datapath_PDME__DOT__n_output_valid_buffer 
        = ((~ (IData)(vlTOPp->Datapath_PDME__DOT__output_valid_buffer)) 
           & ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
               ? (IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
               : (IData)(vlTOPp->Datapath_PDME__DOT__output_valid_buffer)));
    vlTOPp->Datapath_PDME__DOT__n_neg_output_counter 
        = (1U & ((~ (IData)(vlTOPp->Datapath_PDME__DOT__output_valid_buffer)) 
                 & ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                     ? (~ (IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter))
                     : (IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter))));
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_valid 
        = ((0xeU & (IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_valid)) 
           | (IData)(vlTOPp->Datapath_PDME__DOT__output_valid_buffer));
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[4U] 
        = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[5U] 
        = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[1U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[6U] 
        = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[2U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[7U] 
        = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[3U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[8U] 
        = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[4U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[9U] 
        = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[5U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xaU] 
        = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[6U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xbU] 
        = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[7U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xcU] 
        = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[8U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xdU] 
        = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[9U];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xeU] 
        = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xaU];
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer[0xfU] 
        = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xbU];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[4U] 
        = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[5U] 
        = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[1U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[6U] 
        = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[2U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[7U] 
        = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[3U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[8U] 
        = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[4U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[9U] 
        = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[5U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xaU] 
        = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[6U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xbU] 
        = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[7U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xcU] 
        = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[8U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xdU] 
        = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[9U];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xeU] 
        = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xaU];
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer[0xfU] 
        = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xbU];
    if ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid))) {
        vlTOPp->Datapath_PDME__DOT__n_output_counter = 1U;
        vlTOPp->Datapath_PDME__DOT__n_output_buffer[0U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xcU];
        vlTOPp->Datapath_PDME__DOT__n_output_buffer[1U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xdU];
        vlTOPp->Datapath_PDME__DOT__n_output_buffer[2U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xeU];
        vlTOPp->Datapath_PDME__DOT__n_output_buffer[3U] 
            = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xfU];
    } else {
        vlTOPp->Datapath_PDME__DOT__n_output_counter 
            = ((1U & (IData)(vlTOPp->Datapath_PDME__DOT__output_counter))
                ? 2U : 0U);
        vlTOPp->Datapath_PDME__DOT__n_output_buffer[0U] 
            = vlTOPp->Datapath_PDME__DOT__output_buffer[0U];
        vlTOPp->Datapath_PDME__DOT__n_output_buffer[1U] 
            = vlTOPp->Datapath_PDME__DOT__output_buffer[1U];
        vlTOPp->Datapath_PDME__DOT__n_output_buffer[2U] 
            = vlTOPp->Datapath_PDME__DOT__output_buffer[2U];
        vlTOPp->Datapath_PDME__DOT__n_output_buffer[3U] 
            = vlTOPp->Datapath_PDME__DOT__output_buffer[3U];
    }
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_valid 
        = ((0xdU & (IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_valid)) 
           | (2U & ((IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_valid 
        = ((0xbU & (IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_valid)) 
           | (4U & ((IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_valid 
        = ((7U & (IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_valid)) 
           | (8U & ((IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_valid 
        = ((0xdU & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_valid)) 
           | (2U & ((IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_valid 
        = ((0xbU & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_valid)) 
           | (4U & ((IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_valid 
        = ((7U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_valid)) 
           | (8U & ((IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                    << 1U)));
    vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter 
        = (7U & (((0U != (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)) 
                  & (0U != (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)))
                  : (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)));
    vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__n_valid 
        = ((2U & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid) 
                  << 1U)) | ((0U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count))
                              ? 0U : (1U & ((4U >= (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)) 
                                            & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO) 
                                               >> (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter))))));
    vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter));
    VL_EXTEND_WQ(128,64, __Vtemp22, (1ULL + vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data));
    if (vlTOPp->Datapath_PDME__DOT__output_valid_buffer) {
        vlTOPp->Datapath_PDME__DOT__n_neg_to_enc_buffer[0U] = 0U;
        vlTOPp->Datapath_PDME__DOT__n_neg_to_enc_buffer[1U] = 0U;
        vlTOPp->Datapath_PDME__DOT__n_neg_to_enc_buffer[2U] = 0U;
        vlTOPp->Datapath_PDME__DOT__n_neg_to_enc_buffer[3U] = 0U;
    } else {
        vlTOPp->Datapath_PDME__DOT__n_neg_to_enc_buffer[0U] 
            = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                    ? (IData)((((QData)((IData)(vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[0U]))))
                    : __Vtemp22[0U]) : vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[0U]);
        vlTOPp->Datapath_PDME__DOT__n_neg_to_enc_buffer[1U] 
            = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                    ? (IData)(((((QData)((IData)(vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[1U])) 
                                 << 0x20U) | (QData)((IData)(
                                                             vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[0U]))) 
                               >> 0x20U)) : __Vtemp22[1U])
                : vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[1U]);
        vlTOPp->Datapath_PDME__DOT__n_neg_to_enc_buffer[2U] 
            = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                    ? (IData)((1ULL + vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data))
                    : __Vtemp22[2U]) : vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[2U]);
        vlTOPp->Datapath_PDME__DOT__n_neg_to_enc_buffer[3U] 
            = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                    ? (IData)(((1ULL + vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data) 
                               >> 0x20U)) : __Vtemp22[3U])
                : vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[3U]);
    }
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__input_buffer = 0ULL;
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter = 0U;
    } else {
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__input_buffer 
            = ((0x13fU >= (0x1ffU & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                     << 6U))) ? (((0U 
                                                   == 
                                                   (0x1fU 
                                                    & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                       << 6U)))
                                                   ? 0ULL
                                                   : 
                                                  ((QData)((IData)(
                                                                   vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[
                                                                   ((IData)(2U) 
                                                                    + 
                                                                    (0xeU 
                                                                     & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                                        << 1U)))])) 
                                                   << 
                                                   ((IData)(0x40U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                        << 6U))))) 
                                                 | (((QData)((IData)(
                                                                     vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[
                                                                     ((IData)(1U) 
                                                                      + 
                                                                      (0xeU 
                                                                       & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                                          << 1U)))])) 
                                                     << 
                                                     ((0U 
                                                       == 
                                                       (0x1fU 
                                                        & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                           << 6U)))
                                                       ? 0x20U
                                                       : 
                                                      ((IData)(0x20U) 
                                                       - 
                                                       (0x1fU 
                                                        & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                           << 6U))))) 
                                                    | ((QData)((IData)(
                                                                       vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[
                                                                       (0xeU 
                                                                        & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                                           << 1U))])) 
                                                       >> 
                                                       (0x1fU 
                                                        & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                           << 6U)))))
                : 0ULL);
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter 
            = vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter;
    }
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[0U] = 0U;
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[1U] = 0U;
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[2U] = 0U;
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[3U] = 0U;
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[4U] = 0U;
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[5U] = 0U;
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[6U] = 0U;
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[7U] = 0U;
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[8U] = 0U;
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[9U] = 0U;
    } else {
        if (((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer) 
             & (4U > (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count)))) {
            vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT____Vlvbound1 
                = ((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer)
                    ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                        ? (((QData)((IData)(vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[3U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[2U])))
                        : (((QData)((IData)(vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[0U]))))
                    : 0ULL);
            if ((0x13fU >= (0x1ffU & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter) 
                                      << 6U)))) {
                VL_ASSIGNSEL_WIIQ(64,(0x1ffU & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter) 
                                                << 6U)), vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO, vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT____Vlvbound1);
            }
        }
    }
    vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count 
        = (7U & (((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter) 
                  > (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter))
                  ? (((0U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter)) 
                      & (4U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)))
                      ? ((IData)(4U) - (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter))
                      : ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter) 
                         - (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter)))
                  : (((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter) 
                      > (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter))
                      ? ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter) 
                         - (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter))
                      : 0U)));
    vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter 
        = (7U & (((0U != (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)) 
                  & (0U != (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter)))
                  : (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter)));
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter = 0U;
        vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[0U] = 0U;
        vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[1U] = 0U;
        vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[2U] = 0U;
        vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[3U] = 0U;
    } else {
        vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter 
            = vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter;
        vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[0U] 
            = vlTOPp->Datapath_PDME__DOT__n_dec_to_neg_buffer[0U];
        vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[1U] 
            = vlTOPp->Datapath_PDME__DOT__n_dec_to_neg_buffer[1U];
        vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[2U] 
            = vlTOPp->Datapath_PDME__DOT__n_dec_to_neg_buffer[2U];
        vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[3U] 
            = vlTOPp->Datapath_PDME__DOT__n_dec_to_neg_buffer[3U];
    }
    vlTOPp->Datapath_PDME__DOT__neg_intput_counter 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->Datapath_PDME__DOT__n_neg_intput_counter));
    vlTOPp->Datapath_PDME__DOT__input_valid_buffer 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->Datapath_PDME__DOT__n_input_valid_buffer));
    vlTOPp->Datapath_PDME__DOT__n_neg_intput_counter 
        = ((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer) 
           & (~ (IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)));
    vlTOPp->Datapath_PDME__DOT__n_input_valid_buffer 
        = (1U & ((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer)
                  ? (~ (IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter))
                  : ((IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                     >> 3U)));
    vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter 
        = (7U & (((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer) 
                  & (4U > (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)))
                  : (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)));
    vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter 
        = (7U & (((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer) 
                  & (4U > (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)))
                  : (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)));
    if (vlTOPp->Datapath_PDME__DOT__input_valid_buffer) {
        vlTOPp->Datapath_PDME__DOT__n_dec_to_neg_buffer[0U] 
            = ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                ? 0U : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[0U]);
        vlTOPp->Datapath_PDME__DOT__n_dec_to_neg_buffer[1U] 
            = ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                ? 0U : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[1U]);
        vlTOPp->Datapath_PDME__DOT__n_dec_to_neg_buffer[2U] 
            = ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                ? 0U : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[2U]);
        vlTOPp->Datapath_PDME__DOT__n_dec_to_neg_buffer[3U] 
            = ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                ? 0U : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[3U]);
    } else {
        vlTOPp->Datapath_PDME__DOT__n_dec_to_neg_buffer[0U] 
            = ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid))
                ? vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xcU]
                : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[0U]);
        vlTOPp->Datapath_PDME__DOT__n_dec_to_neg_buffer[1U] 
            = ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid))
                ? vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xdU]
                : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[1U]);
        vlTOPp->Datapath_PDME__DOT__n_dec_to_neg_buffer[2U] 
            = ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid))
                ? vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xeU]
                : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[2U]);
        vlTOPp->Datapath_PDME__DOT__n_dec_to_neg_buffer[3U] 
            = ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid))
                ? vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xfU]
                : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[3U]);
    }
}

VL_INLINE_OPT void VDatapath_PDME::_combo__TOP__3(VDatapath_PDME__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDME::_combo__TOP__3\n"); );
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp62[4];
    // Body
    vlTOPp->Datapath_PDME__DOT__n_next_to_decrypt = 
        ((IData)(vlTOPp->input_valid) & (IData)(vlTOPp->Datapath_PDME__DOT__input_counter));
    vlTOPp->Datapath_PDME__DOT__n_input_counter = (1U 
                                                   & ((IData)(vlTOPp->input_valid)
                                                       ? 
                                                      (~ (IData)(vlTOPp->Datapath_PDME__DOT__input_counter))
                                                       : (IData)(vlTOPp->Datapath_PDME__DOT__input_counter)));
    VL_EXTEND_WQ(128,64, __Vtemp62, vlTOPp->input_data);
    if (vlTOPp->input_valid) {
        vlTOPp->Datapath_PDME__DOT__n_input_buffer[0U] 
            = ((IData)(vlTOPp->Datapath_PDME__DOT__input_counter)
                ? (IData)((((QData)((IData)(vlTOPp->Datapath_PDME__DOT__input_buffer[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlTOPp->Datapath_PDME__DOT__input_buffer[0U]))))
                : __Vtemp62[0U]);
        vlTOPp->Datapath_PDME__DOT__n_input_buffer[1U] 
            = ((IData)(vlTOPp->Datapath_PDME__DOT__input_counter)
                ? (IData)(((((QData)((IData)(vlTOPp->Datapath_PDME__DOT__input_buffer[1U])) 
                             << 0x20U) | (QData)((IData)(
                                                         vlTOPp->Datapath_PDME__DOT__input_buffer[0U]))) 
                           >> 0x20U)) : __Vtemp62[1U]);
        vlTOPp->Datapath_PDME__DOT__n_input_buffer[2U] 
            = ((IData)(vlTOPp->Datapath_PDME__DOT__input_counter)
                ? (IData)(vlTOPp->input_data) : __Vtemp62[2U]);
        vlTOPp->Datapath_PDME__DOT__n_input_buffer[3U] 
            = ((IData)(vlTOPp->Datapath_PDME__DOT__input_counter)
                ? (IData)((vlTOPp->input_data >> 0x20U))
                : __Vtemp62[3U]);
    } else {
        vlTOPp->Datapath_PDME__DOT__n_input_buffer[0U] 
            = vlTOPp->Datapath_PDME__DOT__input_buffer[0U];
        vlTOPp->Datapath_PDME__DOT__n_input_buffer[1U] 
            = vlTOPp->Datapath_PDME__DOT__input_buffer[1U];
        vlTOPp->Datapath_PDME__DOT__n_input_buffer[2U] 
            = vlTOPp->Datapath_PDME__DOT__input_buffer[2U];
        vlTOPp->Datapath_PDME__DOT__n_input_buffer[3U] 
            = vlTOPp->Datapath_PDME__DOT__input_buffer[3U];
    }
}

void VDatapath_PDME::_eval(VDatapath_PDME__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDME::_eval\n"); );
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VDatapath_PDME::_change_request(VDatapath_PDME__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDME::_change_request\n"); );
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VDatapath_PDME::_change_request_1(VDatapath_PDME__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDME::_change_request_1\n"); );
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VDatapath_PDME::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDME::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
