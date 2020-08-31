#ifndef AGR_Sate_STRUCTS_H
#define AGR_Sate_STRUCTS_H

#include "SKP_Silk_SDK_API.h"
#include "AGR_BWE_bits.h"
#include "AGR_BWE_defines.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Parameters for Highband, added by Raphael*/
typedef struct {
    SKP_int16   x_hb_buf_fix[2 * 1280 + 480];/* Buffer for high band lpc analysis */
    SKP_int32	HB_NLSFInterpCoef_Q2;
    SKP_int32   HB_prev_NLSFq_Q15[MAX_LPC_ORDER];
    SKP_int32	interp_NLSF_Q15[NB_SUBFR][MAX_LPC_ORDER];
} AGR_Sate_encoder_hb_state_FIX;

typedef struct {
    /* Parameters for Highband, added by Raphael*/
    SKP_int32	hb_lossCnt;
    SKP_int16   hb_gIncr_fix;
    SKP_int32   HB_NLSFInterpCoef_Q2;
    SKP_int32   HB_prev_NLSFq_fix[MAX_LPC_ORDER];
    SKP_int16   HB_prev_Gain_fix;
    SKP_int32   HB_synth_state[MAX_LPC_ORDER];
} AGR_Sate_decoder_hb_state_FIX;

typedef struct {
    SKP_int32     hb_KHz;
    SKP_int32     lb_Delay;
    SKP_int16     h0_mem[QMF_ORDER];
    SKP_float     BWE_PredCoef[2][MAX_LPC_ORDER];  /* holds interpolated and final coefficients */
    SKP_int32     BWE_LPCOrder;
	SKP_int32     BWE_LPCFrameSize;
	SKP_int32     BWE_SubFrameSize;
    SKP_int32     first;
    SKP_int32     JC1_FrameSize;
	SKP_int32     QMF_HB_FrameSize;
	SKP_int32     QMF_LB_FrameSize;
	SKP_int32     SATE_FrameSize;
	SKP_int32     BWE_FrameSize;
	SKP_int32     bitstream_format;
} AGR_Sate_HB_encoder_control_FIX;

typedef struct {
    SKP_int16   g0_mem[QMF_ORDER];
    SKP_int16   g1_mem[QMF_ORDER];
    SKP_int32     first;
    SKP_int32     BWE_LPCOrder;
	SKP_int32     BWE_SubFrameSize;
    SKP_int32     JC1_FrameSize;
	SKP_int32     QMF_HB_FrameSize;
	SKP_int32     QMF_LB_FrameSize;
	SKP_int32     SATE_FrameSize;
	SKP_int32     BWE_FrameSize;
} AGR_Sate_HB_decoder_control_FIX;

typedef struct {
    void *stEnc;
    void *stHBEnc;
    SKP_SILK_SDK_EncControlStruct  encControl;
    AGR_Sate_HB_encoder_control_FIX HBencControl;
    NovaBits bits;
} SATEEncCtl;


typedef struct {
    void *stDec;
    void *stHBDec;
    SKP_SILK_SDK_DecControlStruct decControl;
    AGR_Sate_HB_decoder_control_FIX HBdecControl;
    NovaBits bits;
} SATEDecCtl;

#ifdef __cplusplus
}
#endif 

#endif