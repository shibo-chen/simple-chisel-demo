// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VDatapath_PDME__Syms.h"


//======================

void VDatapath_PDME::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VDatapath_PDME::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VDatapath_PDME__Syms* __restrict vlSymsp = static_cast<VDatapath_PDME__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VDatapath_PDME::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VDatapath_PDME::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VDatapath_PDME__Syms* __restrict vlSymsp = static_cast<VDatapath_PDME__Syms*>(userp);
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VDatapath_PDME::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VDatapath_PDME__Syms* __restrict vlSymsp = static_cast<VDatapath_PDME__Syms*>(userp);
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+169,"clock", false,-1);
        tracep->declBit(c+170,"reset", false,-1);
        tracep->declBit(c+171,"input_valid", false,-1);
        tracep->declQuad(c+172,"input_data", false,-1, 63,0);
        tracep->declBit(c+174,"output_valid", false,-1);
        tracep->declQuad(c+175,"output_data", false,-1, 63,0);
        tracep->declBit(c+169,"Datapath_PDME clock", false,-1);
        tracep->declBit(c+170,"Datapath_PDME reset", false,-1);
        tracep->declBit(c+171,"Datapath_PDME input_valid", false,-1);
        tracep->declQuad(c+172,"Datapath_PDME input_data", false,-1, 63,0);
        tracep->declBit(c+174,"Datapath_PDME output_valid", false,-1);
        tracep->declQuad(c+175,"Datapath_PDME output_data", false,-1, 63,0);
        tracep->declBit(c+1,"Datapath_PDME next_to_encrypt", false,-1);
        tracep->declBit(c+2,"Datapath_PDME next_to_decrypt", false,-1);
        tracep->declBit(c+163,"Datapath_PDME n_next_to_decrypt", false,-1);
        tracep->declBit(c+3,"Datapath_PDME ready_from_encrypt", false,-1);
        tracep->declBit(c+4,"Datapath_PDME ready_from_decrypt", false,-1);
        tracep->declBit(c+5,"Datapath_PDME input_counter", false,-1);
        tracep->declBit(c+164,"Datapath_PDME n_input_counter", false,-1);
        tracep->declBus(c+6,"Datapath_PDME output_counter", false,-1, 1,0);
        tracep->declBus(c+7,"Datapath_PDME n_output_counter", false,-1, 1,0);
        tracep->declArray(c+8,"Datapath_PDME input_buffer", false,-1, 127,0);
        tracep->declArray(c+165,"Datapath_PDME n_input_buffer", false,-1, 127,0);
        tracep->declArray(c+12,"Datapath_PDME output_buffer", false,-1, 127,0);
        tracep->declArray(c+16,"Datapath_PDME n_output_buffer", false,-1, 127,0);
        tracep->declArray(c+20,"Datapath_PDME input_to_encrypt", false,-1, 127,0);
        tracep->declArray(c+8,"Datapath_PDME input_to_decrypt", false,-1, 127,0);
        tracep->declArray(c+24,"Datapath_PDME output_from_encrypt", false,-1, 127,0);
        tracep->declArray(c+28,"Datapath_PDME output_from_decrypt", false,-1, 127,0);
        tracep->declBit(c+32,"Datapath_PDME neg_intput_counter", false,-1);
        tracep->declBit(c+33,"Datapath_PDME n_neg_intput_counter", false,-1);
        tracep->declBit(c+34,"Datapath_PDME neg_output_counter", false,-1);
        tracep->declBit(c+35,"Datapath_PDME n_neg_output_counter", false,-1);
        tracep->declBit(c+36,"Datapath_PDME input_valid_buffer", false,-1);
        tracep->declBit(c+37,"Datapath_PDME n_input_valid_buffer", false,-1);
        tracep->declBit(c+1,"Datapath_PDME output_valid_buffer", false,-1);
        tracep->declBit(c+38,"Datapath_PDME n_output_valid_buffer", false,-1);
        tracep->declArray(c+39,"Datapath_PDME dec_to_neg_buffer", false,-1, 127,0);
        tracep->declArray(c+43,"Datapath_PDME n_dec_to_neg_buffer", false,-1, 127,0);
        tracep->declArray(c+20,"Datapath_PDME neg_to_enc_buffer", false,-1, 127,0);
        tracep->declArray(c+47,"Datapath_PDME n_neg_to_enc_buffer", false,-1, 127,0);
        tracep->declQuad(c+51,"Datapath_PDME input_to_negator", false,-1, 63,0);
        tracep->declQuad(c+53,"Datapath_PDME output_from_negator", false,-1, 63,0);
        tracep->declBit(c+55,"Datapath_PDME valid_input_to_negator", false,-1);
        tracep->declBit(c+56,"Datapath_PDME valid_output_from_negator", false,-1);
        tracep->declBit(c+57,"Datapath_PDME ready_out", false,-1);
        tracep->declBit(c+177,"Datapath_PDME ready_input", false,-1);
        tracep->declBus(c+178,"Datapath_PDME simulatedAESDecryptEngin NUM_CYCLE", false,-1, 31,0);
        tracep->declBit(c+169,"Datapath_PDME simulatedAESDecryptEngin clock", false,-1);
        tracep->declBit(c+170,"Datapath_PDME simulatedAESDecryptEngin reset", false,-1);
        tracep->declBit(c+2,"Datapath_PDME simulatedAESDecryptEngin next", false,-1);
        tracep->declArray(c+8,"Datapath_PDME simulatedAESDecryptEngin block", false,-1, 127,0);
        tracep->declBit(c+4,"Datapath_PDME simulatedAESDecryptEngin ready", false,-1);
        tracep->declArray(c+28,"Datapath_PDME simulatedAESDecryptEngin new_block", false,-1, 127,0);
        tracep->declArray(c+58,"Datapath_PDME simulatedAESDecryptEngin buffer", false,-1, 511,0);
        tracep->declBus(c+74,"Datapath_PDME simulatedAESDecryptEngin valid", false,-1, 3,0);
        tracep->declArray(c+75,"Datapath_PDME simulatedAESDecryptEngin n_buffer", false,-1, 511,0);
        tracep->declBus(c+91,"Datapath_PDME simulatedAESDecryptEngin n_valid", false,-1, 3,0);
        tracep->declBus(c+178,"Datapath_PDME SimulatedAESEncryptEngin NUM_CYCLE", false,-1, 31,0);
        tracep->declBit(c+169,"Datapath_PDME SimulatedAESEncryptEngin clock", false,-1);
        tracep->declBit(c+170,"Datapath_PDME SimulatedAESEncryptEngin reset", false,-1);
        tracep->declBit(c+1,"Datapath_PDME SimulatedAESEncryptEngin next", false,-1);
        tracep->declArray(c+20,"Datapath_PDME SimulatedAESEncryptEngin block", false,-1, 127,0);
        tracep->declBit(c+3,"Datapath_PDME SimulatedAESEncryptEngin ready", false,-1);
        tracep->declArray(c+24,"Datapath_PDME SimulatedAESEncryptEngin new_block", false,-1, 127,0);
        tracep->declArray(c+92,"Datapath_PDME SimulatedAESEncryptEngin buffer", false,-1, 511,0);
        tracep->declBus(c+108,"Datapath_PDME SimulatedAESEncryptEngin valid", false,-1, 3,0);
        tracep->declArray(c+109,"Datapath_PDME SimulatedAESEncryptEngin n_buffer", false,-1, 511,0);
        tracep->declBus(c+125,"Datapath_PDME SimulatedAESEncryptEngin n_valid", false,-1, 3,0);
        tracep->declBus(c+179,"Datapath_PDME pipelinedDecoupledNegator WIDTH_IN_NUM_OF_FULL_INTEGER", false,-1, 31,0);
        tracep->declBus(c+180,"Datapath_PDME pipelinedDecoupledNegator INTEGER_WIDTH", false,-1, 31,0);
        tracep->declBus(c+178,"Datapath_PDME pipelinedDecoupledNegator SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH", false,-1, 31,0);
        tracep->declBit(c+169,"Datapath_PDME pipelinedDecoupledNegator clock", false,-1);
        tracep->declBit(c+170,"Datapath_PDME pipelinedDecoupledNegator reset", false,-1);
        tracep->declBit(c+55,"Datapath_PDME pipelinedDecoupledNegator input_valid", false,-1);
        tracep->declBit(c+57,"Datapath_PDME pipelinedDecoupledNegator input_ready", false,-1);
        tracep->declQuad(c+51,"Datapath_PDME pipelinedDecoupledNegator input_data", false,-1, 63,0);
        tracep->declBit(c+56,"Datapath_PDME pipelinedDecoupledNegator output_valid", false,-1);
        tracep->declBit(c+177,"Datapath_PDME pipelinedDecoupledNegator output_ready", false,-1);
        tracep->declQuad(c+53,"Datapath_PDME pipelinedDecoupledNegator output_data", false,-1, 63,0);
        tracep->declQuad(c+126,"Datapath_PDME pipelinedDecoupledNegator input_buffer", false,-1, 63,0);
        tracep->declQuad(c+128,"Datapath_PDME pipelinedDecoupledNegator data_queue_output", false,-1, 63,0);
        tracep->declQuad(c+128,"Datapath_PDME pipelinedDecoupledNegator n_input_buffer", false,-1, 63,0);
        tracep->declQuad(c+130,"Datapath_PDME pipelinedDecoupledNegator negated_data", false,-1, 63,0);
        tracep->declQuad(c+132,"Datapath_PDME pipelinedDecoupledNegator n_negated_data", false,-1, 63,0);
        tracep->declBus(c+134,"Datapath_PDME pipelinedDecoupledNegator valid", false,-1, 1,0);
        tracep->declBus(c+135,"Datapath_PDME pipelinedDecoupledNegator n_valid", false,-1, 1,0);
        tracep->declBit(c+136,"Datapath_PDME pipelinedDecoupledNegator validity_queue_output", false,-1);
        tracep->declBit(c+137,"Datapath_PDME pipelinedDecoupledNegator data_queue_empty", false,-1);
        tracep->declBit(c+138,"Datapath_PDME pipelinedDecoupledNegator validity_queue_full", false,-1);
        tracep->declBit(c+139,"Datapath_PDME pipelinedDecoupledNegator queue_read", false,-1);
        tracep->declBit(c+55,"Datapath_PDME pipelinedDecoupledNegator queue_write", false,-1);
        tracep->declBit(c+177,"Datapath_PDME pipelinedDecoupledNegator queue_enable", false,-1);
        tracep->declBit(c+140,"Datapath_PDME pipelinedDecoupledNegator data_queue_full", false,-1);
        tracep->declBit(c+141,"Datapath_PDME pipelinedDecoupledNegator validity_queue_empty", false,-1);
        tracep->declBus(c+179,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data WIDTH_IN_NUM_OF_FULL_DATA", false,-1, 31,0);
        tracep->declBus(c+180,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+178,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH", false,-1, 31,0);
        tracep->declBit(c+169,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data clock", false,-1);
        tracep->declBit(c+170,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data reset", false,-1);
        tracep->declQuad(c+51,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data data_in", false,-1, 63,0);
        tracep->declBit(c+139,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data read", false,-1);
        tracep->declBit(c+55,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data write", false,-1);
        tracep->declBit(c+177,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data enable", false,-1);
        tracep->declQuad(c+128,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data data_out", false,-1, 63,0);
        tracep->declBit(c+137,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data empty", false,-1);
        tracep->declBit(c+140,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data full", false,-1);
        tracep->declBus(c+142,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data Count", false,-1, 2,0);
        tracep->declArray(c+143,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data FIFO", false,-1, 319,0);
        tracep->declBus(c+153,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data readCounter", false,-1, 2,0);
        tracep->declBus(c+154,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data writeCounter", false,-1, 2,0);
        tracep->declBus(c+155,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data n_readCounter", false,-1, 2,0);
        tracep->declBus(c+156,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_data n_writeCounter", false,-1, 2,0);
        tracep->declBus(c+179,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity WIDTH_IN_NUM_OF_FULL_DATA", false,-1, 31,0);
        tracep->declBus(c+179,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+178,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity SIZE_OF_BUFFER_IN_NUM_OF_INPUT_WIDTH", false,-1, 31,0);
        tracep->declBit(c+169,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity clock", false,-1);
        tracep->declBit(c+170,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity reset", false,-1);
        tracep->declBus(c+55,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity data_in", false,-1, 0,0);
        tracep->declBit(c+139,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity read", false,-1);
        tracep->declBit(c+55,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity write", false,-1);
        tracep->declBit(c+177,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity enable", false,-1);
        tracep->declBus(c+136,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity data_out", false,-1, 0,0);
        tracep->declBit(c+141,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity empty", false,-1);
        tracep->declBit(c+138,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity full", false,-1);
        tracep->declBus(c+157,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity Count", false,-1, 2,0);
        tracep->declBus(c+158,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity FIFO", false,-1, 4,0);
        tracep->declBus(c+159,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity readCounter", false,-1, 2,0);
        tracep->declBus(c+160,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity writeCounter", false,-1, 2,0);
        tracep->declBus(c+161,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity n_readCounter", false,-1, 2,0);
        tracep->declBus(c+162,"Datapath_PDME pipelinedDecoupledNegator fifobuffer_for_validity n_writeCounter", false,-1, 2,0);
    }
}

void VDatapath_PDME::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VDatapath_PDME::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VDatapath_PDME__Syms* __restrict vlSymsp = static_cast<VDatapath_PDME__Syms*>(userp);
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VDatapath_PDME::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VDatapath_PDME__Syms* __restrict vlSymsp = static_cast<VDatapath_PDME__Syms*>(userp);
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Variables
    WData/*127:0*/ __Vtemp67[4];
    WData/*127:0*/ __Vtemp68[4];
    WData/*127:0*/ __Vtemp69[4];
    WData/*127:0*/ __Vtemp75[4];
    WData/*127:0*/ __Vtemp78[4];
    WData/*127:0*/ __Vtemp82[4];
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->Datapath_PDME__DOT__output_valid_buffer));
        tracep->fullBit(oldp+2,(vlTOPp->Datapath_PDME__DOT__next_to_decrypt));
        tracep->fullBit(oldp+3,((1U & ((IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid) 
                                       >> 3U))));
        tracep->fullBit(oldp+4,((1U & ((IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                                       >> 3U))));
        tracep->fullBit(oldp+5,(vlTOPp->Datapath_PDME__DOT__input_counter));
        tracep->fullCData(oldp+6,(vlTOPp->Datapath_PDME__DOT__output_counter),2);
        tracep->fullCData(oldp+7,(((8U & (IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid))
                                    ? 1U : ((1U & (IData)(vlTOPp->Datapath_PDME__DOT__output_counter))
                                             ? 2U : 0U))),2);
        tracep->fullWData(oldp+8,(vlTOPp->Datapath_PDME__DOT__input_buffer),128);
        tracep->fullWData(oldp+12,(vlTOPp->Datapath_PDME__DOT__output_buffer),128);
        if ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid))) {
            __Vtemp67[0U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xcU];
            __Vtemp67[1U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xdU];
            __Vtemp67[2U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xeU];
            __Vtemp67[3U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xfU];
        } else {
            __Vtemp67[0U] = vlTOPp->Datapath_PDME__DOT__output_buffer[0U];
            __Vtemp67[1U] = vlTOPp->Datapath_PDME__DOT__output_buffer[1U];
            __Vtemp67[2U] = vlTOPp->Datapath_PDME__DOT__output_buffer[2U];
            __Vtemp67[3U] = vlTOPp->Datapath_PDME__DOT__output_buffer[3U];
        }
        tracep->fullWData(oldp+16,(__Vtemp67),128);
        tracep->fullWData(oldp+20,(vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer),128);
        __Vtemp68[0U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xcU];
        __Vtemp68[1U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xdU];
        __Vtemp68[2U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xeU];
        __Vtemp68[3U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xfU];
        tracep->fullWData(oldp+24,(__Vtemp68),128);
        __Vtemp69[0U] = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xcU];
        __Vtemp69[1U] = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xdU];
        __Vtemp69[2U] = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xeU];
        __Vtemp69[3U] = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xfU];
        tracep->fullWData(oldp+28,(__Vtemp69),128);
        tracep->fullBit(oldp+32,(vlTOPp->Datapath_PDME__DOT__neg_intput_counter));
        tracep->fullBit(oldp+33,(((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer) 
                                  & (~ (IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)))));
        tracep->fullBit(oldp+34,(vlTOPp->Datapath_PDME__DOT__neg_output_counter));
        tracep->fullBit(oldp+35,((1U & ((~ (IData)(vlTOPp->Datapath_PDME__DOT__output_valid_buffer)) 
                                        & ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                                            ? (~ (IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter))
                                            : (IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter))))));
        tracep->fullBit(oldp+36,(vlTOPp->Datapath_PDME__DOT__input_valid_buffer));
        tracep->fullBit(oldp+37,((1U & ((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer)
                                         ? (~ (IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter))
                                         : ((IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                                            >> 3U)))));
        tracep->fullBit(oldp+38,(((~ (IData)(vlTOPp->Datapath_PDME__DOT__output_valid_buffer)) 
                                  & ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                                      ? (IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                                      : (IData)(vlTOPp->Datapath_PDME__DOT__output_valid_buffer)))));
        tracep->fullWData(oldp+39,(vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer),128);
        if (vlTOPp->Datapath_PDME__DOT__input_valid_buffer) {
            __Vtemp75[0U] = ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                              ? 0U : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[0U]);
            __Vtemp75[1U] = ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                              ? 0U : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[1U]);
            __Vtemp75[2U] = ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                              ? 0U : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[2U]);
            __Vtemp75[3U] = ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                              ? 0U : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[3U]);
        } else {
            __Vtemp75[0U] = ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid))
                              ? vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xcU]
                              : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[0U]);
            __Vtemp75[1U] = ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid))
                              ? vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xdU]
                              : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[1U]);
            __Vtemp75[2U] = ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid))
                              ? vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xeU]
                              : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[2U]);
            __Vtemp75[3U] = ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid))
                              ? vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xfU]
                              : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[3U]);
        }
        tracep->fullWData(oldp+43,(__Vtemp75),128);
        VL_EXTEND_WQ(128,64, __Vtemp78, (1ULL + vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data));
        if (vlTOPp->Datapath_PDME__DOT__output_valid_buffer) {
            __Vtemp82[0U] = 0U;
            __Vtemp82[1U] = 0U;
            __Vtemp82[2U] = 0U;
            __Vtemp82[3U] = 0U;
        } else {
            __Vtemp82[0U] = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                              ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                                  ? (IData)((((QData)((IData)(
                                                              vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[0U]))))
                                  : __Vtemp78[0U]) : 
                             vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[0U]);
            __Vtemp82[1U] = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                              ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                                  ? (IData)(((((QData)((IData)(
                                                               vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[0U]))) 
                                             >> 0x20U))
                                  : __Vtemp78[1U]) : 
                             vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[1U]);
            __Vtemp82[2U] = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                              ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                                  ? (IData)((1ULL + vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data))
                                  : __Vtemp78[2U]) : 
                             vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[2U]);
            __Vtemp82[3U] = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                              ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                                  ? (IData)(((1ULL 
                                              + vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data) 
                                             >> 0x20U))
                                  : __Vtemp78[3U]) : 
                             vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[3U]);
        }
        tracep->fullWData(oldp+47,(__Vtemp82),128);
        tracep->fullQData(oldp+51,(((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer)
                                     ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                                         ? (((QData)((IData)(
                                                             vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[3U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[2U])))
                                         : (((QData)((IData)(
                                                             vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[0U]))))
                                     : 0ULL)),64);
        tracep->fullQData(oldp+53,((1ULL + vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data)),64);
        tracep->fullBit(oldp+55,(vlTOPp->Datapath_PDME__DOT__input_valid_buffer));
        tracep->fullBit(oldp+56,((1U & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid) 
                                        >> 1U))));
        tracep->fullBit(oldp+57,((4U != (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count))));
        tracep->fullWData(oldp+58,(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer),512);
        tracep->fullCData(oldp+74,(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid),4);
        tracep->fullWData(oldp+75,(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer),512);
        tracep->fullCData(oldp+91,(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_valid),4);
        tracep->fullWData(oldp+92,(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer),512);
        tracep->fullCData(oldp+108,(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid),4);
        tracep->fullWData(oldp+109,(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer),512);
        tracep->fullCData(oldp+125,(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_valid),4);
        tracep->fullQData(oldp+126,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__input_buffer),64);
        tracep->fullQData(oldp+128,(((0x13fU >= (0x1ffU 
                                                 & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                    << 6U)))
                                      ? (((0U == (0x1fU 
                                                  & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                     << 6U)))
                                           ? 0ULL : 
                                          ((QData)((IData)(
                                                           vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[
                                                           ((IData)(2U) 
                                                            + 
                                                            (0xeU 
                                                             & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                                << 1U)))])) 
                                           << ((IData)(0x40U) 
                                               - (0x1fU 
                                                  & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                     << 6U))))) 
                                         | (((QData)((IData)(
                                                             vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO[
                                                             ((IData)(1U) 
                                                              + 
                                                              (0xeU 
                                                               & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                                  << 1U)))])) 
                                             << ((0U 
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
                                               >> (0x1fU 
                                                   & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                      << 6U)))))
                                      : 0ULL)),64);
        tracep->fullQData(oldp+130,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data),64);
        tracep->fullQData(oldp+132,((~ vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__input_buffer)),64);
        tracep->fullCData(oldp+134,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid),2);
        tracep->fullCData(oldp+135,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__n_valid),2);
        tracep->fullBit(oldp+136,(((4U >= (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)) 
                                   & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO) 
                                      >> (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)))));
        tracep->fullBit(oldp+137,((0U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count))));
        tracep->fullBit(oldp+138,((4U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count))));
        tracep->fullBit(oldp+139,((0U != (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count))));
        tracep->fullBit(oldp+140,((4U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count))));
        tracep->fullBit(oldp+141,((0U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count))));
        tracep->fullCData(oldp+142,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count),3);
        tracep->fullWData(oldp+143,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO),320);
        tracep->fullCData(oldp+153,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter),3);
        tracep->fullCData(oldp+154,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter),3);
        tracep->fullCData(oldp+155,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter),3);
        tracep->fullCData(oldp+156,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter),3);
        tracep->fullCData(oldp+157,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count),3);
        tracep->fullCData(oldp+158,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO),5);
        tracep->fullCData(oldp+159,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter),3);
        tracep->fullCData(oldp+160,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter),3);
        tracep->fullCData(oldp+161,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter),3);
        tracep->fullCData(oldp+162,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter),3);
        tracep->fullBit(oldp+163,(vlTOPp->Datapath_PDME__DOT__n_next_to_decrypt));
        tracep->fullBit(oldp+164,(vlTOPp->Datapath_PDME__DOT__n_input_counter));
        tracep->fullWData(oldp+165,(vlTOPp->Datapath_PDME__DOT__n_input_buffer),128);
        tracep->fullBit(oldp+169,(vlTOPp->clock));
        tracep->fullBit(oldp+170,(vlTOPp->reset));
        tracep->fullBit(oldp+171,(vlTOPp->input_valid));
        tracep->fullQData(oldp+172,(vlTOPp->input_data),64);
        tracep->fullBit(oldp+174,(vlTOPp->output_valid));
        tracep->fullQData(oldp+175,(vlTOPp->output_data),64);
        tracep->fullBit(oldp+177,(1U));
        tracep->fullIData(oldp+178,(4U),32);
        tracep->fullIData(oldp+179,(1U),32);
        tracep->fullIData(oldp+180,(0x40U),32);
    }
}
