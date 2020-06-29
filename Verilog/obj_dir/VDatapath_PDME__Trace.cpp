// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VDatapath_PDME__Syms.h"


void VDatapath_PDME::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VDatapath_PDME__Syms* __restrict vlSymsp = static_cast<VDatapath_PDME__Syms*>(userp);
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VDatapath_PDME::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VDatapath_PDME__Syms* __restrict vlSymsp = static_cast<VDatapath_PDME__Syms*>(userp);
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Variables
    WData/*127:0*/ __Vtemp85[4];
    WData/*127:0*/ __Vtemp86[4];
    WData/*127:0*/ __Vtemp87[4];
    WData/*127:0*/ __Vtemp93[4];
    WData/*127:0*/ __Vtemp96[4];
    WData/*127:0*/ __Vtemp100[4];
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->Datapath_PDME__DOT__output_valid_buffer));
            tracep->chgBit(oldp+1,(vlTOPp->Datapath_PDME__DOT__next_to_decrypt));
            tracep->chgBit(oldp+2,((1U & ((IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid) 
                                          >> 3U))));
            tracep->chgBit(oldp+3,((1U & ((IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                                          >> 3U))));
            tracep->chgBit(oldp+4,(vlTOPp->Datapath_PDME__DOT__input_counter));
            tracep->chgCData(oldp+5,(vlTOPp->Datapath_PDME__DOT__output_counter),2);
            tracep->chgCData(oldp+6,(((8U & (IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid))
                                       ? 1U : ((1U 
                                                & (IData)(vlTOPp->Datapath_PDME__DOT__output_counter))
                                                ? 2U
                                                : 0U))),2);
            tracep->chgWData(oldp+7,(vlTOPp->Datapath_PDME__DOT__input_buffer),128);
            tracep->chgWData(oldp+11,(vlTOPp->Datapath_PDME__DOT__output_buffer),128);
            if ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid))) {
                __Vtemp85[0U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xcU];
                __Vtemp85[1U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xdU];
                __Vtemp85[2U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xeU];
                __Vtemp85[3U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xfU];
            } else {
                __Vtemp85[0U] = vlTOPp->Datapath_PDME__DOT__output_buffer[0U];
                __Vtemp85[1U] = vlTOPp->Datapath_PDME__DOT__output_buffer[1U];
                __Vtemp85[2U] = vlTOPp->Datapath_PDME__DOT__output_buffer[2U];
                __Vtemp85[3U] = vlTOPp->Datapath_PDME__DOT__output_buffer[3U];
            }
            tracep->chgWData(oldp+15,(__Vtemp85),128);
            tracep->chgWData(oldp+19,(vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer),128);
            __Vtemp86[0U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xcU];
            __Vtemp86[1U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xdU];
            __Vtemp86[2U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xeU];
            __Vtemp86[3U] = vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer[0xfU];
            tracep->chgWData(oldp+23,(__Vtemp86),128);
            __Vtemp87[0U] = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xcU];
            __Vtemp87[1U] = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xdU];
            __Vtemp87[2U] = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xeU];
            __Vtemp87[3U] = vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xfU];
            tracep->chgWData(oldp+27,(__Vtemp87),128);
            tracep->chgBit(oldp+31,(vlTOPp->Datapath_PDME__DOT__neg_intput_counter));
            tracep->chgBit(oldp+32,(((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer) 
                                     & (~ (IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)))));
            tracep->chgBit(oldp+33,(vlTOPp->Datapath_PDME__DOT__neg_output_counter));
            tracep->chgBit(oldp+34,((1U & ((~ (IData)(vlTOPp->Datapath_PDME__DOT__output_valid_buffer)) 
                                           & ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                                               ? (~ (IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter))
                                               : (IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter))))));
            tracep->chgBit(oldp+35,(vlTOPp->Datapath_PDME__DOT__input_valid_buffer));
            tracep->chgBit(oldp+36,((1U & ((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer)
                                            ? (~ (IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter))
                                            : ((IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid) 
                                               >> 3U)))));
            tracep->chgBit(oldp+37,(((~ (IData)(vlTOPp->Datapath_PDME__DOT__output_valid_buffer)) 
                                     & ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                                         ? (IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                                         : (IData)(vlTOPp->Datapath_PDME__DOT__output_valid_buffer)))));
            tracep->chgWData(oldp+38,(vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer),128);
            if (vlTOPp->Datapath_PDME__DOT__input_valid_buffer) {
                __Vtemp93[0U] = ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                                  ? 0U : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[0U]);
                __Vtemp93[1U] = ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                                  ? 0U : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[1U]);
                __Vtemp93[2U] = ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                                  ? 0U : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[2U]);
                __Vtemp93[3U] = ((IData)(vlTOPp->Datapath_PDME__DOT__neg_intput_counter)
                                  ? 0U : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[3U]);
            } else {
                __Vtemp93[0U] = ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid))
                                  ? vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xcU]
                                  : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[0U]);
                __Vtemp93[1U] = ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid))
                                  ? vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xdU]
                                  : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[1U]);
                __Vtemp93[2U] = ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid))
                                  ? vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xeU]
                                  : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[2U]);
                __Vtemp93[3U] = ((8U & (IData)(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid))
                                  ? vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer[0xfU]
                                  : vlTOPp->Datapath_PDME__DOT__dec_to_neg_buffer[3U]);
            }
            tracep->chgWData(oldp+42,(__Vtemp93),128);
            VL_EXTEND_WQ(128,64, __Vtemp96, (1ULL + vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data));
            if (vlTOPp->Datapath_PDME__DOT__output_valid_buffer) {
                __Vtemp100[0U] = 0U;
                __Vtemp100[1U] = 0U;
                __Vtemp100[2U] = 0U;
                __Vtemp100[3U] = 0U;
            } else {
                __Vtemp100[0U] = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                                   ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                                       ? (IData)((((QData)((IData)(
                                                                   vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[0U]))))
                                       : __Vtemp96[0U])
                                   : vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[0U]);
                __Vtemp100[1U] = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                                   ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                                       ? (IData)(((
                                                   ((QData)((IData)(
                                                                    vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[0U]))) 
                                                  >> 0x20U))
                                       : __Vtemp96[1U])
                                   : vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[1U]);
                __Vtemp100[2U] = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                                   ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                                       ? (IData)((1ULL 
                                                  + vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data))
                                       : __Vtemp96[2U])
                                   : vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[2U]);
                __Vtemp100[3U] = ((2U & (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid))
                                   ? ((IData)(vlTOPp->Datapath_PDME__DOT__neg_output_counter)
                                       ? (IData)(((1ULL 
                                                   + vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data) 
                                                  >> 0x20U))
                                       : __Vtemp96[3U])
                                   : vlTOPp->Datapath_PDME__DOT__neg_to_enc_buffer[3U]);
            }
            tracep->chgWData(oldp+46,(__Vtemp100),128);
            tracep->chgQData(oldp+50,(((IData)(vlTOPp->Datapath_PDME__DOT__input_valid_buffer)
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
            tracep->chgQData(oldp+52,((1ULL + vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data)),64);
            tracep->chgBit(oldp+54,(vlTOPp->Datapath_PDME__DOT__input_valid_buffer));
            tracep->chgBit(oldp+55,((1U & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid) 
                                           >> 1U))));
            tracep->chgBit(oldp+56,((4U != (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count))));
            tracep->chgWData(oldp+57,(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__buffer),512);
            tracep->chgCData(oldp+73,(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__valid),4);
            tracep->chgWData(oldp+74,(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_buffer),512);
            tracep->chgCData(oldp+90,(vlTOPp->Datapath_PDME__DOT__simulatedAESDecryptEngin__DOT__n_valid),4);
            tracep->chgWData(oldp+91,(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__buffer),512);
            tracep->chgCData(oldp+107,(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__valid),4);
            tracep->chgWData(oldp+108,(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_buffer),512);
            tracep->chgCData(oldp+124,(vlTOPp->Datapath_PDME__DOT__SimulatedAESEncryptEngin__DOT__n_valid),4);
            tracep->chgQData(oldp+125,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__input_buffer),64);
            tracep->chgQData(oldp+127,(((0x13fU >= 
                                         (0x1ffU & 
                                          ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                           << 6U)))
                                         ? (((0U == 
                                              (0x1fU 
                                               & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter) 
                                                  << 6U)))
                                              ? 0ULL
                                              : ((QData)((IData)(
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
                                         : 0ULL)),64);
            tracep->chgQData(oldp+129,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__negated_data),64);
            tracep->chgQData(oldp+131,((~ vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__input_buffer)),64);
            tracep->chgCData(oldp+133,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__valid),2);
            tracep->chgCData(oldp+134,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__n_valid),2);
            tracep->chgBit(oldp+135,(((4U >= (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)) 
                                      & ((IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO) 
                                         >> (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter)))));
            tracep->chgBit(oldp+136,((0U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count))));
            tracep->chgBit(oldp+137,((4U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count))));
            tracep->chgBit(oldp+138,((0U != (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count))));
            tracep->chgBit(oldp+139,((4U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count))));
            tracep->chgBit(oldp+140,((0U == (IData)(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count))));
            tracep->chgCData(oldp+141,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__Count),3);
            tracep->chgWData(oldp+142,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__FIFO),320);
            tracep->chgCData(oldp+152,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__readCounter),3);
            tracep->chgCData(oldp+153,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__writeCounter),3);
            tracep->chgCData(oldp+154,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_readCounter),3);
            tracep->chgCData(oldp+155,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_data__DOT__n_writeCounter),3);
            tracep->chgCData(oldp+156,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__Count),3);
            tracep->chgCData(oldp+157,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__FIFO),5);
            tracep->chgCData(oldp+158,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__readCounter),3);
            tracep->chgCData(oldp+159,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__writeCounter),3);
            tracep->chgCData(oldp+160,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_readCounter),3);
            tracep->chgCData(oldp+161,(vlTOPp->Datapath_PDME__DOT__pipelinedDecoupledNegator__DOT__fifobuffer_for_validity__DOT__n_writeCounter),3);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+162,(vlTOPp->Datapath_PDME__DOT__n_next_to_decrypt));
            tracep->chgBit(oldp+163,(vlTOPp->Datapath_PDME__DOT__n_input_counter));
            tracep->chgWData(oldp+164,(vlTOPp->Datapath_PDME__DOT__n_input_buffer),128);
        }
        tracep->chgBit(oldp+168,(vlTOPp->clock));
        tracep->chgBit(oldp+169,(vlTOPp->reset));
        tracep->chgBit(oldp+170,(vlTOPp->input_valid));
        tracep->chgQData(oldp+171,(vlTOPp->input_data),64);
        tracep->chgBit(oldp+173,(vlTOPp->output_valid));
        tracep->chgQData(oldp+174,(vlTOPp->output_data),64);
    }
}

void VDatapath_PDME::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VDatapath_PDME__Syms* __restrict vlSymsp = static_cast<VDatapath_PDME__Syms*>(userp);
    VDatapath_PDME* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
