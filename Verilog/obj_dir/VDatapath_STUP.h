// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VDATAPATH_STUP_H_
#define _VDATAPATH_STUP_H_  // guard

#include "verilated.h"

//==========

class VDatapath_STUP__Syms;

//----------

VL_MODULE(VDatapath_STUP) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(input_valid,0,0);
    VL_OUT8(output_valid,0,0);
    VL_IN64(input_data,63,0);
    VL_OUT64(output_data,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ Datapath_STUP__DOT__counter;
    CData/*0:0*/ Datapath_STUP__DOT__n_counter;
    CData/*0:0*/ Datapath_STUP__DOT__input_valid_buffer;
    CData/*0:0*/ Datapath_STUP__DOT__n_input_valid_buffer;
    CData/*0:0*/ Datapath_STUP__DOT__output_valid_buffer;
    CData/*0:0*/ Datapath_STUP__DOT__n_output_valid_buffer;
    IData/*31:0*/ Datapath_STUP__DOT__input_to_negator;
    QData/*63:0*/ Datapath_STUP__DOT__input_buffer;
    QData/*63:0*/ Datapath_STUP__DOT__n_input_buffer;
    QData/*63:0*/ Datapath_STUP__DOT__output_buffer;
    QData/*63:0*/ Datapath_STUP__DOT__n_output_buffer;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VDatapath_STUP__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VDatapath_STUP);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VDatapath_STUP(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VDatapath_STUP();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VDatapath_STUP__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VDatapath_STUP__Syms* symsp, bool first);
  private:
    static QData _change_request(VDatapath_STUP__Syms* __restrict vlSymsp);
    static QData _change_request_1(VDatapath_STUP__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(VDatapath_STUP__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VDatapath_STUP__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VDatapath_STUP__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VDatapath_STUP__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VDatapath_STUP__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VDatapath_STUP__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
