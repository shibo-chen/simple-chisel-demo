// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_PTMP.h for the primary calling header

#include "VDatapath_PTMP.h"
#include "VDatapath_PTMP__Syms.h"

//==========

void VDatapath_PTMP::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDatapath_PTMP::eval\n"); );
    VDatapath_PTMP__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VDatapath_PTMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("Datapath_PTMP.sv", 14, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VDatapath_PTMP::_eval_initial_loop(VDatapath_PTMP__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("Datapath_PTMP.sv", 14, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VDatapath_PTMP::_sequent__TOP__1(VDatapath_PTMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTMP::_sequent__TOP__1\n"); );
    VDatapath_PTMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__negated_data 
        = ((IData)(vlTOPp->reset) ? 0ULL : (~ vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__input_buffer));
    if (vlTOPp->reset) {
        vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__valid = 0U;
    } else {
        vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__valid 
            = ((2U & (IData)(vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__valid)) 
               | (IData)(vlTOPp->input_valid));
        vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__valid 
            = ((1U & (IData)(vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__valid)) 
               | ((IData)(vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__n_valid) 
                  << 1U));
    }
    vlTOPp->output_data = (1ULL + vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__negated_data);
    vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__input_buffer 
        = ((IData)(vlTOPp->reset) ? 0ULL : vlTOPp->input_data);
    vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__n_valid 
        = (1U & (IData)(vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__valid));
    vlTOPp->output_valid = (1U & ((IData)(vlTOPp->Datapath_PTMP__DOT__pipelinedTightlyCoupledNegator__DOT__valid) 
                                  >> 1U));
}

void VDatapath_PTMP::_eval(VDatapath_PTMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTMP::_eval\n"); );
    VDatapath_PTMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VDatapath_PTMP::_change_request(VDatapath_PTMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTMP::_change_request\n"); );
    VDatapath_PTMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VDatapath_PTMP::_change_request_1(VDatapath_PTMP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTMP::_change_request_1\n"); );
    VDatapath_PTMP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VDatapath_PTMP::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_PTMP::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
