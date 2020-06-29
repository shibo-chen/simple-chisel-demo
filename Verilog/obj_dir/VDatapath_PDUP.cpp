// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_PDUP.h for the primary calling header

#include "VDatapath_PDUP.h"
#include "VDatapath_PDUP__Syms.h"

//==========

void VDatapath_PDUP::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDatapath_PDUP::eval\n"); );
    VDatapath_PDUP__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VDatapath_PDUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("Datapath_PDUP.sv", 14, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VDatapath_PDUP::_eval_initial_loop(VDatapath_PDUP__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("Datapath_PDUP.sv", 14, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VDatapath_PDUP::_sequent__TOP__1(VDatapath_PDUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDUP::_sequent__TOP__1\n"); );
    VDatapath_PDUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter = 0U;
        vlTOPp->Datapath_PDUP__DOT__output_buffer = 0ULL;
        vlTOPp->Datapath_PDUP__DOT__input_buffer = 0ULL;
    } else {
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter 
            = vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter;
        vlTOPp->Datapath_PDUP__DOT__output_buffer = vlTOPp->Datapath_PDUP__DOT__n_output_buffer;
        vlTOPp->Datapath_PDUP__DOT__input_buffer = vlTOPp->Datapath_PDUP__DOT__n_input_buffer;
    }
    vlTOPp->Datapath_PDUP__DOT__output_counter = ((~ (IData)(vlTOPp->reset)) 
                                                  & (IData)(vlTOPp->Datapath_PDUP__DOT__n_output_counter));
    vlTOPp->Datapath_PDUP__DOT__input_counter = ((~ (IData)(vlTOPp->reset)) 
                                                 & (IData)(vlTOPp->Datapath_PDUP__DOT__n_input_counter));
    vlTOPp->Datapath_PDUP__DOT__output_valid_buffer 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->Datapath_PDUP__DOT__n_output_valid_buffer));
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__valid = 0U;
    } else {
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__valid 
            = ((1U & (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__valid)) 
               | (2U & (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__n_valid)));
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__valid 
            = ((2U & (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__valid)) 
               | (1U & (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__n_valid)));
    }
    vlTOPp->Datapath_PDUP__DOT__input_valid_buffer 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->Datapath_PDUP__DOT__n_input_valid_buffer));
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO = 0U;
    } else {
        if (((IData)(vlTOPp->Datapath_PDUP__DOT__valid_input_to_negator) 
             & (4U > (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)))) {
            vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT____Vlvbound1 
                = vlTOPp->Datapath_PDUP__DOT__valid_input_to_negator;
            if ((4U >= (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter))) {
                vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO 
                    = (((~ ((IData)(1U) << (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter))) 
                        & (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO)) 
                       | ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT____Vlvbound1) 
                          << (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)));
            }
        }
    }
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count 
        = (7U & (((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter) 
                  > (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter))
                  ? (((0U == (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter)) 
                      & (4U == (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)))
                      ? ((IData)(4U) - (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter))
                      : ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter) 
                         - (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter)))
                  : (((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter) 
                      > (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter))
                      ? ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter) 
                         - (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter))
                      : 0U)));
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__negated_data 
        = ((IData)(vlTOPp->reset) ? 0U : (~ vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__input_buffer));
    vlTOPp->output_data = vlTOPp->Datapath_PDUP__DOT__output_buffer;
    vlTOPp->output_valid = vlTOPp->Datapath_PDUP__DOT__output_valid_buffer;
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
    vlTOPp->Datapath_PDUP__DOT__n_input_counter = ((IData)(vlTOPp->Datapath_PDUP__DOT__input_valid_buffer) 
                                                   & (~ (IData)(vlTOPp->Datapath_PDUP__DOT__input_counter)));
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter 
        = (7U & (((0U != (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)) 
                  & (0U != (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)))
                  : (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)));
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__n_valid 
        = ((2U & ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__valid) 
                  << 1U)) | ((0U == (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count))
                              ? 0U : (1U & ((4U >= (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)) 
                                            & ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO) 
                                               >> (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter))))));
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter));
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
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__input_buffer = 0U;
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter = 0U;
    } else {
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__input_buffer 
            = ((0x9fU >= (0xffU & ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                   << 5U))) ? (((0U 
                                                 == 
                                                 (0x1fU 
                                                  & ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                     << 5U)))
                                                 ? 0U
                                                 : 
                                                (vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[
                                                 ((IData)(1U) 
                                                  + 
                                                  (7U 
                                                   & (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter)))] 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                      << 5U))))) 
                                               | (vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[
                                                  (7U 
                                                   & (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter))] 
                                                  >> 
                                                  (0x1fU 
                                                   & ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                      << 5U))))
                : 0U);
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter 
            = vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter;
    }
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[0U] = 0U;
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[1U] = 0U;
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[2U] = 0U;
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[3U] = 0U;
        vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[4U] = 0U;
    } else {
        if (((IData)(vlTOPp->Datapath_PDUP__DOT__valid_input_to_negator) 
             & (4U > (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count)))) {
            vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT____Vlvbound1 
                = vlTOPp->Datapath_PDUP__DOT__input_to_negator;
            if ((0x9fU >= (0xffU & ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter) 
                                    << 5U)))) {
                VL_ASSIGNSEL_WIII(32,(0xffU & ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter) 
                                               << 5U)), vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO, vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT____Vlvbound1);
            }
        }
    }
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count 
        = (7U & (((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter) 
                  > (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter))
                  ? (((0U == (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter)) 
                      & (4U == (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)))
                      ? ((IData)(4U) - (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter))
                      : ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter) 
                         - (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter)))
                  : (((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter) 
                      > (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter))
                      ? ((IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter) 
                         - (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter))
                      : 0U)));
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
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter));
    vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter 
        = (7U & (((IData)(vlTOPp->Datapath_PDUP__DOT__valid_input_to_negator) 
                  & (4U > (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)))
                  : (IData)(vlTOPp->Datapath_PDUP__DOT__PipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)));
}

VL_INLINE_OPT void VDatapath_PDUP::_combo__TOP__3(VDatapath_PDUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDUP::_combo__TOP__3\n"); );
    VDatapath_PDUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->Datapath_PDUP__DOT__input_valid_buffer) {
        vlTOPp->Datapath_PDUP__DOT__n_input_valid_buffer 
            = (1U & (~ (IData)(vlTOPp->Datapath_PDUP__DOT__input_counter)));
        vlTOPp->Datapath_PDUP__DOT__n_input_buffer 
            = ((IData)(vlTOPp->Datapath_PDUP__DOT__input_counter)
                ? 0ULL : vlTOPp->Datapath_PDUP__DOT__input_buffer);
    } else {
        vlTOPp->Datapath_PDUP__DOT__n_input_valid_buffer 
            = (1U & (IData)(vlTOPp->input_valid));
        vlTOPp->Datapath_PDUP__DOT__n_input_buffer 
            = vlTOPp->input_data;
    }
}

void VDatapath_PDUP::_eval(VDatapath_PDUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDUP::_eval\n"); );
    VDatapath_PDUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VDatapath_PDUP::_change_request(VDatapath_PDUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDUP::_change_request\n"); );
    VDatapath_PDUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VDatapath_PDUP::_change_request_1(VDatapath_PDUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDUP::_change_request_1\n"); );
    VDatapath_PDUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VDatapath_PDUP::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDUP::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
