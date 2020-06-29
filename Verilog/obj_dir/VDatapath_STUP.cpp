// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDatapath_STUP.h for the primary calling header

#include "VDatapath_STUP.h"
#include "VDatapath_STUP__Syms.h"

//==========

void VDatapath_STUP::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDatapath_STUP::eval\n"); );
    VDatapath_STUP__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VDatapath_STUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("Datapath_STUP.sv", 14, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VDatapath_STUP::_eval_initial_loop(VDatapath_STUP__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("Datapath_STUP.sv", 14, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VDatapath_STUP::_sequent__TOP__1(VDatapath_STUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STUP::_sequent__TOP__1\n"); );
    VDatapath_STUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Datapath_STUP__DOT__output_valid_buffer 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->Datapath_STUP__DOT__n_output_valid_buffer));
    if (vlTOPp->reset) {
        vlTOPp->Datapath_STUP__DOT__output_buffer = 0ULL;
        vlTOPp->Datapath_STUP__DOT__input_buffer = 0ULL;
    } else {
        vlTOPp->Datapath_STUP__DOT__output_buffer = vlTOPp->Datapath_STUP__DOT__n_output_buffer;
        vlTOPp->Datapath_STUP__DOT__input_buffer = vlTOPp->Datapath_STUP__DOT__n_input_buffer;
    }
    vlTOPp->Datapath_STUP__DOT__counter = ((~ (IData)(vlTOPp->reset)) 
                                           & (IData)(vlTOPp->Datapath_STUP__DOT__n_counter));
    vlTOPp->Datapath_STUP__DOT__input_valid_buffer 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->Datapath_STUP__DOT__n_input_valid_buffer));
    vlTOPp->output_valid = vlTOPp->Datapath_STUP__DOT__output_valid_buffer;
    vlTOPp->output_data = vlTOPp->Datapath_STUP__DOT__output_buffer;
    vlTOPp->Datapath_STUP__DOT__n_counter = ((IData)(vlTOPp->Datapath_STUP__DOT__input_valid_buffer) 
                                             & (~ (IData)(vlTOPp->Datapath_STUP__DOT__counter)));
    vlTOPp->Datapath_STUP__DOT__n_output_valid_buffer 
        = ((IData)(vlTOPp->Datapath_STUP__DOT__input_valid_buffer) 
           & (IData)(vlTOPp->Datapath_STUP__DOT__counter));
    vlTOPp->Datapath_STUP__DOT__input_to_negator = 
        ((IData)(vlTOPp->Datapath_STUP__DOT__input_valid_buffer)
          ? ((IData)(vlTOPp->Datapath_STUP__DOT__counter)
              ? (IData)((vlTOPp->Datapath_STUP__DOT__input_buffer 
                         >> 0x20U)) : (IData)(vlTOPp->Datapath_STUP__DOT__input_buffer))
          : 0U);
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

VL_INLINE_OPT void VDatapath_STUP::_combo__TOP__3(VDatapath_STUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STUP::_combo__TOP__3\n"); );
    VDatapath_STUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->Datapath_STUP__DOT__input_valid_buffer) {
        vlTOPp->Datapath_STUP__DOT__n_input_valid_buffer 
            = (1U & (~ (IData)(vlTOPp->Datapath_STUP__DOT__counter)));
        vlTOPp->Datapath_STUP__DOT__n_input_buffer 
            = ((IData)(vlTOPp->Datapath_STUP__DOT__counter)
                ? 0ULL : vlTOPp->Datapath_STUP__DOT__input_buffer);
    } else {
        vlTOPp->Datapath_STUP__DOT__n_input_valid_buffer 
            = (1U & (IData)(vlTOPp->input_valid));
        vlTOPp->Datapath_STUP__DOT__n_input_buffer 
            = ((IData)(vlTOPp->input_valid) ? vlTOPp->input_data
                : 0ULL);
    }
}

void VDatapath_STUP::_eval(VDatapath_STUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STUP::_eval\n"); );
    VDatapath_STUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VDatapath_STUP::_change_request(VDatapath_STUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STUP::_change_request\n"); );
    VDatapath_STUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VDatapath_STUP::_change_request_1(VDatapath_STUP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STUP::_change_request_1\n"); );
    VDatapath_STUP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VDatapath_STUP::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDatapath_STUP::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
