// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_PDMP.h for the primary calling header

#include "VDatapath_PDMP.h"
#include "VDatapath_PDMP__Syms.h"

//==========

void VDatapath_PDMP::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDatapath_PDMP::eval\n"); );
    VDatapath_PDMP__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VDatapath_PDMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("Datapath_PDMP.sv", 16, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VDatapath_PDMP::_eval_initial_loop(VDatapath_PDMP__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("Datapath_PDMP.sv", 16, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VDatapath_PDMP::_sequent__TOP__1(VDatapath_PDMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDMP::_sequent__TOP__1\n"); );
    VDatapath_PDMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__valid = 0U;
    } else {
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__valid 
            = ((1U & (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__valid)) 
               | (2U & (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__n_valid)));
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__valid 
            = ((2U & (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__valid)) 
               | (1U & (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__n_valid)));
    }
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter));
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO = 0U;
    } else {
        if (((IData)(vlTOPp->input_valid) & (4U > (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)))) {
            vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT____Vlvbound1 
                = vlTOPp->input_valid;
            if ((4U >= (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter))) {
                vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO 
                    = (((~ ((IData)(1U) << (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter))) 
                        & (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO)) 
                       | ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT____Vlvbound1) 
                          << (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)));
            }
        }
    }
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count 
        = (7U & (((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter) 
                  > (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter))
                  ? (((0U == (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter)) 
                      & (4U == (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)))
                      ? ((IData)(4U) - (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter))
                      : ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter) 
                         - (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter)))
                  : (((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter) 
                      > (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter))
                      ? ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter) 
                         - (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter))
                      : 0U)));
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__negated_data 
        = ((IData)(vlTOPp->reset) ? 0ULL : (~ vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__input_buffer));
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
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter));
    vlTOPp->output_data = (1ULL + vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__negated_data);
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__input_buffer = 0ULL;
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter = 0U;
    } else {
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__input_buffer 
            = ((0x13fU >= (0x1ffU & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                     << 6U))) ? (((0U 
                                                   == 
                                                   (0x1fU 
                                                    & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                       << 6U)))
                                                   ? 0ULL
                                                   : 
                                                  ((QData)((IData)(
                                                                   vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[
                                                                   ((IData)(2U) 
                                                                    + 
                                                                    (0xeU 
                                                                     & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                                        << 1U)))])) 
                                                   << 
                                                   ((IData)(0x40U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                        << 6U))))) 
                                                 | (((QData)((IData)(
                                                                     vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[
                                                                     ((IData)(1U) 
                                                                      + 
                                                                      (0xeU 
                                                                       & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                                          << 1U)))])) 
                                                     << 
                                                     ((0U 
                                                       == 
                                                       (0x1fU 
                                                        & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                           << 6U)))
                                                       ? 0x20U
                                                       : 
                                                      ((IData)(0x20U) 
                                                       - 
                                                       (0x1fU 
                                                        & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                           << 6U))))) 
                                                    | ((QData)((IData)(
                                                                       vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[
                                                                       (0xeU 
                                                                        & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                                           << 1U))])) 
                                                       >> 
                                                       (0x1fU 
                                                        & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                           << 6U)))))
                : 0ULL);
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter 
            = vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter;
    }
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[0U] = 0U;
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[1U] = 0U;
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[2U] = 0U;
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[3U] = 0U;
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[4U] = 0U;
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[5U] = 0U;
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[6U] = 0U;
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[7U] = 0U;
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[8U] = 0U;
        vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[9U] = 0U;
    } else {
        if (((IData)(vlTOPp->input_valid) & (4U > (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count)))) {
            vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT____Vlvbound1 
                = vlTOPp->input_data;
            if ((0x13fU >= (0x1ffU & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter) 
                                      << 6U)))) {
                VL_ASSIGNSEL_WIIQ(64,(0x1ffU & ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter) 
                                                << 6U)), vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO, vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT____Vlvbound1);
            }
        }
    }
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count 
        = (7U & (((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter) 
                  > (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter))
                  ? (((0U == (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter)) 
                      & (4U == (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)))
                      ? ((IData)(4U) - (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter))
                      : ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter) 
                         - (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter)))
                  : (((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter) 
                      > (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter))
                      ? ((IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter) 
                         - (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter))
                      : 0U)));
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter 
        = (7U & (((0U != (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)) 
                  & (0U != (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter)))
                  : (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter)));
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter));
}

VL_INLINE_OPT void VDatapath_PDMP::_combo__TOP__3(VDatapath_PDMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDMP::_combo__TOP__3\n"); );
    VDatapath_PDMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter 
        = (7U & (((IData)(vlTOPp->input_valid) & (4U 
                                                  > (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)))
                  : (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter)));
    vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter 
        = (7U & (((IData)(vlTOPp->input_valid) & (4U 
                                                  > (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count)))
                  ? ((4U == (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter))
                      ? 0U : ((IData)(1U) + (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)))
                  : (IData)(vlTOPp->Datapath_PDMP__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter)));
}

void VDatapath_PDMP::_eval(VDatapath_PDMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDMP::_eval\n"); );
    VDatapath_PDMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VDatapath_PDMP::_change_request(VDatapath_PDMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDMP::_change_request\n"); );
    VDatapath_PDMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VDatapath_PDMP::_change_request_1(VDatapath_PDMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDMP::_change_request_1\n"); );
    VDatapath_PDMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VDatapath_PDMP::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PDMP::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
