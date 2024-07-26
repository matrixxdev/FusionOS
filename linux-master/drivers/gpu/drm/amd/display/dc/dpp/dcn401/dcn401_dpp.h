/* Copyright 2023 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef __DCN401_DPP_H__
#define __DCN401_DPP_H__

#include "dcn20/dcn20_dpp.h"
#include "dcn30/dcn30_dpp.h"
#include "dcn32/dcn32_dpp.h"

#define TO_DCN401_DPP(dpp)\
	container_of(dpp, struct dcn401_dpp, base)

#define DPP_REG_LIST_SH_MASK_DCN401_COMMON(mask_sh)\
	TF_SF(CM0_CM_MEM_PWR_STATUS, GAMCOR_MEM_PWR_STATE, mask_sh),\
	TF_SF(CM0_CM_DEALPHA, CM_DEALPHA_EN, mask_sh),\
	TF_SF(CM0_CM_DEALPHA, CM_DEALPHA_ABLND, mask_sh),\
	TF_SF(CM0_CM_BIAS_CR_R, CM_BIAS_CR_R, mask_sh),\
	TF_SF(CM0_CM_BIAS_Y_G_CB_B, CM_BIAS_Y_G, mask_sh),\
	TF_SF(CM0_CM_BIAS_Y_G_CB_B, CM_BIAS_CB_B, mask_sh),\
	TF_SF(CM0_CM_MEM_PWR_CTRL, GAMCOR_MEM_PWR_DIS, mask_sh),\
	TF_SF(CM0_CM_MEM_PWR_CTRL, GAMCOR_MEM_PWR_FORCE, mask_sh),\
	TF_SF(CNVC_CFG0_PRE_DEGAM, PRE_DEGAM_MODE, mask_sh),\
	TF_SF(CNVC_CFG0_PRE_DEGAM, PRE_DEGAM_SELECT, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_CONTROL, CM_GAMCOR_MODE, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_CONTROL, CM_GAMCOR_SELECT, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_CONTROL, CM_GAMCOR_PWL_DISABLE, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_CONTROL, CM_GAMCOR_MODE_CURRENT, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_CONTROL, CM_GAMCOR_SELECT_CURRENT, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_LUT_INDEX, CM_GAMCOR_LUT_INDEX, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_LUT_DATA, CM_GAMCOR_LUT_DATA, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_LUT_CONTROL, CM_GAMCOR_LUT_WRITE_COLOR_MASK, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_LUT_CONTROL, CM_GAMCOR_LUT_READ_COLOR_SEL, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_LUT_CONTROL, CM_GAMCOR_LUT_READ_DBG, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_LUT_CONTROL, CM_GAMCOR_LUT_HOST_SEL, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_LUT_CONTROL, CM_GAMCOR_LUT_CONFIG_MODE, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_RAMA_START_CNTL_B, CM_GAMCOR_RAMA_EXP_REGION_START_B, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_RAMA_START_CNTL_B, CM_GAMCOR_RAMA_EXP_REGION_START_SEGMENT_B, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_RAMA_START_SLOPE_CNTL_B, CM_GAMCOR_RAMA_EXP_REGION_START_SLOPE_B, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_RAMA_START_BASE_CNTL_B, CM_GAMCOR_RAMA_EXP_REGION_START_BASE_B, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_RAMA_END_CNTL1_B, CM_GAMCOR_RAMA_EXP_REGION_END_BASE_B, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_RAMA_END_CNTL2_B, CM_GAMCOR_RAMA_EXP_REGION_END_B, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_RAMA_END_CNTL2_B, CM_GAMCOR_RAMA_EXP_REGION_END_SLOPE_B, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_RAMA_OFFSET_B, CM_GAMCOR_RAMA_OFFSET_B, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_RAMA_REGION_0_1, CM_GAMCOR_RAMA_EXP_REGION0_LUT_OFFSET, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_RAMA_REGION_0_1, CM_GAMCOR_RAMA_EXP_REGION0_NUM_SEGMENTS, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_RAMA_REGION_0_1, CM_GAMCOR_RAMA_EXP_REGION1_LUT_OFFSET, mask_sh),\
	TF_SF(CM0_CM_GAMCOR_RAMA_REGION_0_1, CM_GAMCOR_RAMA_EXP_REGION1_NUM_SEGMENTS, mask_sh),\
	TF_SF(DSCL0_DSCL_EXT_OVERSCAN_LEFT_RIGHT, EXT_OVERSCAN_LEFT, mask_sh),\
	TF_SF(DSCL0_DSCL_EXT_OVERSCAN_LEFT_RIGHT, EXT_OVERSCAN_RIGHT, mask_sh),\
	TF_SF(DSCL0_DSCL_EXT_OVERSCAN_TOP_BOTTOM, EXT_OVERSCAN_BOTTOM, mask_sh),\
	TF_SF(DSCL0_DSCL_EXT_OVERSCAN_TOP_BOTTOM, EXT_OVERSCAN_TOP, mask_sh),\
	TF_SF(DSCL0_OTG_H_BLANK, OTG_H_BLANK_START, mask_sh),\
	TF_SF(DSCL0_OTG_H_BLANK, OTG_H_BLANK_END, mask_sh),\
	TF_SF(DSCL0_OTG_V_BLANK, OTG_V_BLANK_START, mask_sh),\
	TF_SF(DSCL0_OTG_V_BLANK, OTG_V_BLANK_END, mask_sh),\
	TF_SF(DSCL0_LB_DATA_FORMAT, INTERLEAVE_EN, mask_sh),\
	TF2_SF(DSCL0, LB_DATA_FORMAT__ALPHA_EN, mask_sh),\
	TF_SF(DSCL0_LB_MEMORY_CTRL, MEMORY_CONFIG, mask_sh),\
	TF_SF(DSCL0_LB_MEMORY_CTRL, LB_MAX_PARTITIONS, mask_sh),\
	TF_SF(DSCL0_DSCL_AUTOCAL, AUTOCAL_MODE, mask_sh),\
	TF_SF(DSCL0_DSCL_AUTOCAL, AUTOCAL_NUM_PIPE, mask_sh),\
	TF_SF(DSCL0_DSCL_CONTROL, SCL_BOUNDARY_MODE, mask_sh),\
	TF_SF(DSCL0_DSCL_AUTOCAL, AUTOCAL_PIPE_ID, mask_sh),\
	TF_SF(DSCL0_SCL_TAP_CONTROL, SCL_V_NUM_TAPS, mask_sh),\
	TF_SF(DSCL0_SCL_TAP_CONTROL, SCL_H_NUM_TAPS, mask_sh),\
	TF_SF(DSCL0_SCL_TAP_CONTROL, SCL_V_NUM_TAPS_C, mask_sh),\
	TF_SF(DSCL0_SCL_TAP_CONTROL, SCL_H_NUM_TAPS_C, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_SELECT, SCL_COEF_RAM_TAP_PAIR_IDX, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_SELECT, SCL_COEF_RAM_PHASE, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_SELECT, SCL_COEF_RAM_FILTER_TYPE, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_DATA, SCL_COEF_RAM_EVEN_TAP_COEF, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_DATA, SCL_COEF_RAM_EVEN_TAP_COEF_EN, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_DATA, SCL_COEF_RAM_ODD_TAP_COEF, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_DATA, SCL_COEF_RAM_ODD_TAP_COEF_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_2TAP_CONTROL, SCL_H_2TAP_HARDCODE_COEF_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_2TAP_CONTROL, SCL_H_2TAP_SHARP_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_2TAP_CONTROL, SCL_H_2TAP_SHARP_FACTOR, mask_sh),\
	TF_SF(DSCL0_DSCL_2TAP_CONTROL, SCL_V_2TAP_HARDCODE_COEF_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_2TAP_CONTROL, SCL_V_2TAP_SHARP_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_2TAP_CONTROL, SCL_V_2TAP_SHARP_FACTOR, mask_sh),\
	TF_SF(DSCL0_SCL_MODE, SCL_COEF_RAM_SELECT, mask_sh),\
	TF_SF(DSCL0_SCL_MODE, DSCL_MODE, mask_sh),\
	TF_SF(DSCL0_RECOUT_START, RECOUT_START_X, mask_sh),\
	TF_SF(DSCL0_RECOUT_START, RECOUT_START_Y, mask_sh),\
	TF_SF(DSCL0_RECOUT_SIZE, RECOUT_WIDTH, mask_sh),\
	TF_SF(DSCL0_RECOUT_SIZE, RECOUT_HEIGHT, mask_sh),\
	TF_SF(DSCL0_MPC_SIZE, MPC_WIDTH, mask_sh),\
	TF_SF(DSCL0_MPC_SIZE, MPC_HEIGHT, mask_sh),\
	TF_SF(DSCL0_SCL_HORZ_FILTER_SCALE_RATIO, SCL_H_SCALE_RATIO, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_SCALE_RATIO, SCL_V_SCALE_RATIO, mask_sh),\
	TF_SF(DSCL0_SCL_HORZ_FILTER_SCALE_RATIO_C, SCL_H_SCALE_RATIO_C, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_SCALE_RATIO_C, SCL_V_SCALE_RATIO_C, mask_sh),\
	TF_SF(DSCL0_SCL_HORZ_FILTER_INIT, SCL_H_INIT_FRAC, mask_sh),\
	TF_SF(DSCL0_SCL_HORZ_FILTER_INIT, SCL_H_INIT_INT, mask_sh),\
	TF_SF(DSCL0_SCL_HORZ_FILTER_INIT_C, SCL_H_INIT_FRAC_C, mask_sh),\
	TF_SF(DSCL0_SCL_HORZ_FILTER_INIT_C, SCL_H_INIT_INT_C, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT, SCL_V_INIT_FRAC, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT, SCL_V_INIT_INT, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT_C, SCL_V_INIT_FRAC_C, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT_C, SCL_V_INIT_INT_C, mask_sh),\
	TF_SF(DSCL0_SCL_MODE, SCL_CHROMA_COEF_MODE, mask_sh),\
	TF_SF(DSCL0_SCL_MODE, SCL_COEF_RAM_SELECT_CURRENT, mask_sh), \
	TF_SF(CNVC_CFG0_PRE_DEALPHA, PRE_DEALPHA_EN, mask_sh), \
	TF_SF(CNVC_CFG0_PRE_DEALPHA, PRE_DEALPHA_ABLND_EN, mask_sh), \
	TF_SF(CNVC_CFG0_PRE_REALPHA, PRE_REALPHA_EN, mask_sh), \
	TF_SF(CNVC_CFG0_PRE_REALPHA, PRE_REALPHA_ABLND_EN, mask_sh), \
	TF_SF(CNVC_CFG0_PRE_CSC_MODE, PRE_CSC_MODE, mask_sh), \
	TF_SF(CNVC_CFG0_PRE_CSC_MODE, PRE_CSC_MODE_CURRENT, mask_sh), \
	TF_SF(CNVC_CFG0_PRE_CSC_C11_C12, PRE_CSC_C11, mask_sh), \
	TF_SF(CNVC_CFG0_PRE_CSC_C11_C12, PRE_CSC_C12, mask_sh), \
	TF_SF(CNVC_CFG0_PRE_CSC_C33_C34, PRE_CSC_C33, mask_sh), \
	TF_SF(CNVC_CFG0_PRE_CSC_C33_C34, PRE_CSC_C34, mask_sh), \
	TF_SF(CM0_CM_POST_CSC_CONTROL, CM_POST_CSC_MODE, mask_sh), \
	TF_SF(CM0_CM_POST_CSC_CONTROL, CM_POST_CSC_MODE_CURRENT, mask_sh), \
	TF_SF(CM0_CM_POST_CSC_C11_C12, CM_POST_CSC_C11, mask_sh), \
	TF_SF(CM0_CM_POST_CSC_C11_C12, CM_POST_CSC_C12, mask_sh), \
	TF_SF(CM0_CM_POST_CSC_C33_C34, CM_POST_CSC_C33, mask_sh), \
	TF_SF(CM0_CM_POST_CSC_C33_C34, CM_POST_CSC_C34, mask_sh), \
	TF_SF(CM0_CM_TEST_DEBUG_INDEX, CM_TEST_DEBUG_INDEX, mask_sh), \
	TF_SF(CNVC_CFG0_FORMAT_CONTROL, CNVC_BYPASS, mask_sh), \
	TF2_SF(CNVC_CFG0, FORMAT_CONTROL__ALPHA_EN, mask_sh), \
	TF_SF(CNVC_CFG0_FORMAT_CONTROL, FORMAT_EXPANSION_MODE, mask_sh), \
	TF_SF(CNVC_CFG0_CNVC_SURFACE_PIXEL_FORMAT, CNVC_SURFACE_PIXEL_FORMAT, mask_sh), \
	TF_SF(CNVC_CFG0_CNVC_SURFACE_PIXEL_FORMAT, CNVC_ALPHA_PLANE_ENABLE, mask_sh), \
	TF_SF(CM_CUR0_CURSOR0_CONTROL, CUR0_MODE, mask_sh), \
	TF_SF(CM_CUR0_CURSOR0_CONTROL, CUR0_EXPANSION_MODE, mask_sh), \
	TF_SF(CM_CUR0_CURSOR0_CONTROL, CUR0_ENABLE, mask_sh), \
	TF_SF(CM_CUR0_CURSOR0_COLOR0, CUR0_COLOR0, mask_sh), \
	TF_SF(CM_CUR0_CURSOR0_COLOR1, CUR0_COLOR1, mask_sh), \
	TF_SF(CM_CUR0_CURSOR0_FP_SCALE_BIAS_G_Y, CUR0_FP_BIAS_G_Y, mask_sh), \
	TF_SF(CM_CUR0_CURSOR0_FP_SCALE_BIAS_G_Y, CUR0_FP_SCALE_G_Y, mask_sh), \
	TF_SF(CM_CUR0_CURSOR0_FP_SCALE_BIAS_RB_CRCB, CUR0_FP_BIAS_RB_CRCB, mask_sh), \
	TF_SF(CM_CUR0_CURSOR0_FP_SCALE_BIAS_RB_CRCB, CUR0_FP_SCALE_RB_CRCB, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_MODE, CUR0_MATRIX_MODE, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_MODE, CUR0_MATRIX_MODE_CURRENT, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_MODE, CUR0_MATRIX_COEF_FORMAT, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_C11_C12_A, CUR0_MATRIX_C11_A, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_C11_C12_A, CUR0_MATRIX_C12_A, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_C13_C14_A, CUR0_MATRIX_C13_A, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_C13_C14_A, CUR0_MATRIX_C14_A, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_C21_C22_A, CUR0_MATRIX_C21_A, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_C21_C22_A, CUR0_MATRIX_C22_A, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_C23_C24_A, CUR0_MATRIX_C23_A, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_C23_C24_A, CUR0_MATRIX_C24_A, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_C31_C32_A, CUR0_MATRIX_C31_A, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_C31_C32_A, CUR0_MATRIX_C32_A, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_C33_C34_A, CUR0_MATRIX_C33_A, mask_sh), \
	TF_SF(CM_CUR0_CUR0_MATRIX_C33_C34_A, CUR0_MATRIX_C34_A, mask_sh), \
	TF_SF(DPP_TOP0_DPP_CONTROL, DPP_CLOCK_ENABLE, mask_sh), \
	TF_SF(CM0_CM_HDR_MULT_COEF, CM_HDR_MULT_COEF, mask_sh), \
	TF_SF(CM0_CM_CONTROL, CM_BYPASS, mask_sh), \
	TF_SF(CURSOR0_0_CURSOR_CONTROL, CURSOR_MODE, mask_sh), \
	TF_SF(CURSOR0_0_CURSOR_CONTROL, CURSOR_PITCH, mask_sh), \
	TF_SF(CURSOR0_0_CURSOR_CONTROL, CURSOR_LINES_PER_CHUNK, mask_sh), \
	TF_SF(CURSOR0_0_CURSOR_CONTROL, CURSOR_ENABLE, mask_sh), \
	TF_SF(CNVC_CFG0_FORMAT_CONTROL, FORMAT_CNV16, mask_sh), \
	TF_SF(CNVC_CFG0_FORMAT_CONTROL, CNVC_BYPASS_MSB_ALIGN, mask_sh), \
	TF_SF(CNVC_CFG0_FORMAT_CONTROL, CLAMP_POSITIVE, mask_sh), \
	TF_SF(CNVC_CFG0_FORMAT_CONTROL, CLAMP_POSITIVE_C, mask_sh), \
	TF_SF(CNVC_CFG0_FORMAT_CONTROL, FORMAT_CROSSBAR_R, mask_sh), \
	TF_SF(CNVC_CFG0_FORMAT_CONTROL, FORMAT_CROSSBAR_G, mask_sh), \
	TF_SF(CNVC_CFG0_FORMAT_CONTROL, FORMAT_CROSSBAR_B, mask_sh), \
	TF_SF(CNVC_CFG0_ALPHA_2BIT_LUT, ALPHA_2BIT_LUT0, mask_sh), \
	TF_SF(CNVC_CFG0_ALPHA_2BIT_LUT, ALPHA_2BIT_LUT1, mask_sh), \
	TF_SF(CNVC_CFG0_ALPHA_2BIT_LUT, ALPHA_2BIT_LUT2, mask_sh), \
	TF_SF(CNVC_CFG0_ALPHA_2BIT_LUT, ALPHA_2BIT_LUT3, mask_sh), \
	TF_SF(CNVC_CFG0_FCNV_FP_BIAS_R, FCNV_FP_BIAS_R, mask_sh), \
	TF_SF(CNVC_CFG0_FCNV_FP_BIAS_G, FCNV_FP_BIAS_G, mask_sh), \
	TF_SF(CNVC_CFG0_FCNV_FP_BIAS_B, FCNV_FP_BIAS_B, mask_sh), \
	TF_SF(CNVC_CFG0_FCNV_FP_SCALE_R, FCNV_FP_SCALE_R, mask_sh), \
	TF_SF(CNVC_CFG0_FCNV_FP_SCALE_G, FCNV_FP_SCALE_G, mask_sh), \
	TF_SF(CNVC_CFG0_FCNV_FP_SCALE_B, FCNV_FP_SCALE_B, mask_sh), \
	TF_SF(CNVC_CFG0_COLOR_KEYER_CONTROL, COLOR_KEYER_EN, mask_sh), \
	TF_SF(CNVC_CFG0_COLOR_KEYER_CONTROL, LUMA_KEYER_EN, mask_sh), \
	TF_SF(CNVC_CFG0_COLOR_KEYER_CONTROL, COLOR_KEYER_MODE, mask_sh), \
	TF_SF(CNVC_CFG0_COLOR_KEYER_ALPHA, COLOR_KEYER_ALPHA_LOW, mask_sh), \
	TF_SF(CNVC_CFG0_COLOR_KEYER_ALPHA, COLOR_KEYER_ALPHA_HIGH, mask_sh), \
	TF_SF(CNVC_CFG0_COLOR_KEYER_RED, COLOR_KEYER_RED_LOW, mask_sh), \
	TF_SF(CNVC_CFG0_COLOR_KEYER_RED, COLOR_KEYER_RED_HIGH, mask_sh), \
	TF_SF(CNVC_CFG0_COLOR_KEYER_GREEN, COLOR_KEYER_GREEN_LOW, mask_sh), \
	TF_SF(CNVC_CFG0_COLOR_KEYER_GREEN, COLOR_KEYER_GREEN_HIGH, mask_sh), \
	TF_SF(CNVC_CFG0_COLOR_KEYER_BLUE, COLOR_KEYER_BLUE_LOW, mask_sh), \
	TF_SF(CNVC_CFG0_COLOR_KEYER_BLUE, COLOR_KEYER_BLUE_HIGH, mask_sh), \
	TF_SF(CM_CUR0_CURSOR0_CONTROL, CUR0_PIX_INV_MODE, mask_sh), \
	TF_SF(CM_CUR0_CURSOR0_CONTROL, CUR0_PIXEL_ALPHA_MOD_EN, mask_sh), \
	TF_SF(CM_CUR0_CURSOR0_CONTROL, CUR0_ROM_EN, mask_sh),\
	TF_SF(DSCL0_OBUF_MEM_PWR_CTRL, OBUF_MEM_PWR_FORCE, mask_sh),\
	TF_SF(DSCL0_DSCL_MEM_PWR_CTRL, LUT_MEM_PWR_FORCE, mask_sh),\
	TF_SF(DSCL0_DSCL_MEM_PWR_STATUS, LUT_MEM_PWR_STATE, mask_sh),\
	TF_SF(DSCL0_DSCL_SC_MODE, SCL_SC_MATRIX_MODE, mask_sh),\
	TF_SF(DSCL0_DSCL_SC_MODE, SCL_SC_LTONL_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_MODE, SCL_EASF_H_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_MODE, SCL_EASF_H_RINGEST_FORCE_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_MODE, SCL_EASF_H_2TAP_SHARP_FACTOR, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF_CNTL, SCL_EASF_H_BF1_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF_CNTL, SCL_EASF_H_BF2_MODE, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF_CNTL, SCL_EASF_H_BF3_MODE, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF_CNTL, SCL_EASF_H_BF2_FLAT1_GAIN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF_CNTL, SCL_EASF_H_BF2_FLAT2_GAIN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF_CNTL, SCL_EASF_H_BF2_ROC_GAIN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_RINGEST_EVENTAP_REDUCE, SCL_EASF_H_RINGEST_EVENTAP_REDUCEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_RINGEST_EVENTAP_REDUCE, SCL_EASF_H_RINGEST_EVENTAP_REDUCEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_RINGEST_EVENTAP_GAIN, SCL_EASF_H_RINGEST_EVENTAP_GAIN1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_RINGEST_EVENTAP_GAIN, SCL_EASF_H_RINGEST_EVENTAP_GAIN2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF_FINAL_MAX_MIN, SCL_EASF_H_BF_MAXA, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF_FINAL_MAX_MIN, SCL_EASF_H_BF_MAXB, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF_FINAL_MAX_MIN, SCL_EASF_H_BF_MINA, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF_FINAL_MAX_MIN, SCL_EASF_H_BF_MINB, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG0, SCL_EASF_H_BF1_PWL_IN_SEG0, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG0, SCL_EASF_H_BF1_PWL_BASE_SEG0, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG0, SCL_EASF_H_BF1_PWL_SLOPE_SEG0, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG1, SCL_EASF_H_BF1_PWL_IN_SEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG1, SCL_EASF_H_BF1_PWL_BASE_SEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG1, SCL_EASF_H_BF1_PWL_SLOPE_SEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG2, SCL_EASF_H_BF1_PWL_IN_SEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG2, SCL_EASF_H_BF1_PWL_BASE_SEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG2, SCL_EASF_H_BF1_PWL_SLOPE_SEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG3, SCL_EASF_H_BF1_PWL_IN_SEG3, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG3, SCL_EASF_H_BF1_PWL_BASE_SEG3, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG3, SCL_EASF_H_BF1_PWL_SLOPE_SEG3, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG4, SCL_EASF_H_BF1_PWL_IN_SEG4, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG4, SCL_EASF_H_BF1_PWL_BASE_SEG4, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG4, SCL_EASF_H_BF1_PWL_SLOPE_SEG4, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG5, SCL_EASF_H_BF1_PWL_IN_SEG5, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG5, SCL_EASF_H_BF1_PWL_BASE_SEG5, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG5, SCL_EASF_H_BF1_PWL_SLOPE_SEG5, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG6, SCL_EASF_H_BF1_PWL_IN_SEG6, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG6, SCL_EASF_H_BF1_PWL_BASE_SEG6, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG6, SCL_EASF_H_BF1_PWL_SLOPE_SEG6, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG7, SCL_EASF_H_BF1_PWL_IN_SEG7, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF1_PWL_SEG7, SCL_EASF_H_BF1_PWL_BASE_SEG7, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG0, SCL_EASF_H_BF3_PWL_IN_SEG0, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG0, SCL_EASF_H_BF3_PWL_BASE_SEG0, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG0, SCL_EASF_H_BF3_PWL_SLOPE_SEG0, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG1, SCL_EASF_H_BF3_PWL_IN_SEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG1, SCL_EASF_H_BF3_PWL_BASE_SEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG1, SCL_EASF_H_BF3_PWL_SLOPE_SEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG2, SCL_EASF_H_BF3_PWL_IN_SEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG2, SCL_EASF_H_BF3_PWL_BASE_SEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG2, SCL_EASF_H_BF3_PWL_SLOPE_SEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG3, SCL_EASF_H_BF3_PWL_IN_SEG3, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG3, SCL_EASF_H_BF3_PWL_BASE_SEG3, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG3, SCL_EASF_H_BF3_PWL_SLOPE_SEG3, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG4, SCL_EASF_H_BF3_PWL_IN_SEG4, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG4, SCL_EASF_H_BF3_PWL_BASE_SEG4, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG4, SCL_EASF_H_BF3_PWL_SLOPE_SEG4, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG5, SCL_EASF_H_BF3_PWL_IN_SEG5, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_H_BF3_PWL_SEG5, SCL_EASF_H_BF3_PWL_BASE_SEG5, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_MODE, SCL_EASF_V_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_MODE, SCL_EASF_V_RINGEST_FORCE_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_MODE, SCL_EASF_V_2TAP_SHARP_FACTOR, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF_CNTL, SCL_EASF_V_BF1_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF_CNTL, SCL_EASF_V_BF2_MODE, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF_CNTL, SCL_EASF_V_BF3_MODE, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF_CNTL, SCL_EASF_V_BF2_FLAT1_GAIN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF_CNTL, SCL_EASF_V_BF2_FLAT2_GAIN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF_CNTL, SCL_EASF_V_BF2_ROC_GAIN, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_RINGEST_3TAP_CNTL1, SCL_EASF_V_RINGEST_3TAP_DNTILT_UPTILT, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_RINGEST_3TAP_CNTL1, SCL_EASF_V_RINGEST_3TAP_UPTILT_MAXVAL, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_RINGEST_3TAP_CNTL2, SCL_EASF_V_RINGEST_3TAP_DNTILT_SLOPE, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_RINGEST_3TAP_CNTL2, SCL_EASF_V_RINGEST_3TAP_UPTILT1_SLOPE, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_RINGEST_3TAP_CNTL3, SCL_EASF_V_RINGEST_3TAP_UPTILT2_SLOPE, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_RINGEST_3TAP_CNTL3, SCL_EASF_V_RINGEST_3TAP_UPTILT2_OFFSET, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_RINGEST_EVENTAP_REDUCE, SCL_EASF_V_RINGEST_EVENTAP_REDUCEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_RINGEST_EVENTAP_REDUCE, SCL_EASF_V_RINGEST_EVENTAP_REDUCEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_RINGEST_EVENTAP_GAIN, SCL_EASF_V_RINGEST_EVENTAP_GAIN1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_RINGEST_EVENTAP_GAIN, SCL_EASF_V_RINGEST_EVENTAP_GAIN2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF_FINAL_MAX_MIN, SCL_EASF_V_BF_MAXA, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF_FINAL_MAX_MIN, SCL_EASF_V_BF_MAXB, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF_FINAL_MAX_MIN, SCL_EASF_V_BF_MINA, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF_FINAL_MAX_MIN, SCL_EASF_V_BF_MINB, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG0, SCL_EASF_V_BF1_PWL_IN_SEG0, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG0, SCL_EASF_V_BF1_PWL_BASE_SEG0, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG0, SCL_EASF_V_BF1_PWL_SLOPE_SEG0, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG1, SCL_EASF_V_BF1_PWL_IN_SEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG1, SCL_EASF_V_BF1_PWL_BASE_SEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG1, SCL_EASF_V_BF1_PWL_SLOPE_SEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG2, SCL_EASF_V_BF1_PWL_IN_SEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG2, SCL_EASF_V_BF1_PWL_BASE_SEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG2, SCL_EASF_V_BF1_PWL_SLOPE_SEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG3, SCL_EASF_V_BF1_PWL_IN_SEG3, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG3, SCL_EASF_V_BF1_PWL_BASE_SEG3, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG3, SCL_EASF_V_BF1_PWL_SLOPE_SEG3, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG4, SCL_EASF_V_BF1_PWL_IN_SEG4, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG4, SCL_EASF_V_BF1_PWL_BASE_SEG4, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG4, SCL_EASF_V_BF1_PWL_SLOPE_SEG4, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG5, SCL_EASF_V_BF1_PWL_IN_SEG5, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG5, SCL_EASF_V_BF1_PWL_BASE_SEG5, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG5, SCL_EASF_V_BF1_PWL_SLOPE_SEG5, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG6, SCL_EASF_V_BF1_PWL_IN_SEG6, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG6, SCL_EASF_V_BF1_PWL_BASE_SEG6, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG6, SCL_EASF_V_BF1_PWL_SLOPE_SEG6, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG7, SCL_EASF_V_BF1_PWL_IN_SEG7, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF1_PWL_SEG7, SCL_EASF_V_BF1_PWL_BASE_SEG7, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG0, SCL_EASF_V_BF3_PWL_IN_SEG0, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG0, SCL_EASF_V_BF3_PWL_BASE_SEG0, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG0, SCL_EASF_V_BF3_PWL_SLOPE_SEG0, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG1, SCL_EASF_V_BF3_PWL_IN_SEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG1, SCL_EASF_V_BF3_PWL_BASE_SEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG1, SCL_EASF_V_BF3_PWL_SLOPE_SEG1, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG2, SCL_EASF_V_BF3_PWL_IN_SEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG2, SCL_EASF_V_BF3_PWL_BASE_SEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG2, SCL_EASF_V_BF3_PWL_SLOPE_SEG2, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG3, SCL_EASF_V_BF3_PWL_IN_SEG3, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG3, SCL_EASF_V_BF3_PWL_BASE_SEG3, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG3, SCL_EASF_V_BF3_PWL_SLOPE_SEG3, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG4, SCL_EASF_V_BF3_PWL_IN_SEG4, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG4, SCL_EASF_V_BF3_PWL_BASE_SEG4, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG4, SCL_EASF_V_BF3_PWL_SLOPE_SEG4, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG5, SCL_EASF_V_BF3_PWL_IN_SEG5, mask_sh),\
	TF_SF(DSCL0_DSCL_EASF_V_BF3_PWL_SEG5, SCL_EASF_V_BF3_PWL_BASE_SEG5, mask_sh),\
	TF_SF(DSCL0_DSCL_SC_MATRIX_C0C1, SCL_SC_MATRIX_C0, mask_sh),\
	TF_SF(DSCL0_DSCL_SC_MATRIX_C0C1, SCL_SC_MATRIX_C1, mask_sh),\
	TF_SF(DSCL0_DSCL_SC_MATRIX_C2C3, SCL_SC_MATRIX_C2, mask_sh),\
	TF_SF(DSCL0_DSCL_SC_MATRIX_C2C3, SCL_SC_MATRIX_C3, mask_sh),\
	TF_SF(DSCL0_ISHARP_DELTA_CTRL, ISHARP_DELTA_LUT_HOST_SELECT, mask_sh),\
	TF_SF(DSCL0_ISHARP_DELTA_DATA, ISHARP_DELTA_DATA, mask_sh),\
	TF_SF(DSCL0_ISHARP_DELTA_INDEX, ISHARP_DELTA_INDEX, mask_sh),\
	TF_SF(DSCL0_ISHARP_MODE, ISHARP_EN, mask_sh),\
	TF_SF(DSCL0_ISHARP_MODE, ISHARP_NOISEDET_EN, mask_sh),\
	TF_SF(DSCL0_ISHARP_MODE, ISHARP_NOISEDET_MODE, mask_sh),\
	TF_SF(DSCL0_ISHARP_MODE, ISHARP_LBA_MODE, mask_sh),\
	TF_SF(DSCL0_ISHARP_MODE, ISHARP_DELTA_LUT_SELECT, mask_sh),\
	TF_SF(DSCL0_ISHARP_MODE, ISHARP_FMT_MODE, mask_sh),\
	TF_SF(DSCL0_ISHARP_MODE, ISHARP_FMT_NORM, mask_sh),\
	TF_SF(DSCL0_ISHARP_MODE, ISHARP_DELTA_LUT_SELECT_CURRENT, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG0, ISHARP_LBA_PWL_IN_SEG0, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG0, ISHARP_LBA_PWL_BASE_SEG0, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG0, ISHARP_LBA_PWL_SLOPE_SEG0, mask_sh), \
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG1, ISHARP_LBA_PWL_IN_SEG1, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG1, ISHARP_LBA_PWL_BASE_SEG1, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG1, ISHARP_LBA_PWL_SLOPE_SEG1, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG2, ISHARP_LBA_PWL_IN_SEG2, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG2, ISHARP_LBA_PWL_BASE_SEG2, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG2, ISHARP_LBA_PWL_SLOPE_SEG2, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG3, ISHARP_LBA_PWL_IN_SEG3, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG3, ISHARP_LBA_PWL_BASE_SEG3, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG3, ISHARP_LBA_PWL_SLOPE_SEG3, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG4, ISHARP_LBA_PWL_IN_SEG4, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG4, ISHARP_LBA_PWL_BASE_SEG4, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG4, ISHARP_LBA_PWL_SLOPE_SEG4, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG5, ISHARP_LBA_PWL_IN_SEG5, mask_sh),\
	TF_SF(DSCL0_ISHARP_LBA_PWL_SEG5, ISHARP_LBA_PWL_BASE_SEG5, mask_sh),\
	TF_SF(DSCL0_ISHARP_NOISEDET_THRESHOLD, ISHARP_NOISEDET_UTHRE, mask_sh),\
	TF_SF(DSCL0_ISHARP_NOISEDET_THRESHOLD, ISHARP_NOISEDET_DTHRE, mask_sh), \
	TF_SF(DSCL0_ISHARP_NOISE_GAIN_PWL, ISHARP_NOISEDET_PWL_START_IN, mask_sh), \
	TF_SF(DSCL0_ISHARP_NOISE_GAIN_PWL, ISHARP_NOISEDET_PWL_END_IN, mask_sh), \
	TF_SF(DSCL0_ISHARP_NOISE_GAIN_PWL, ISHARP_NOISEDET_PWL_SLOPE, mask_sh), \
	TF_SF(DSCL0_ISHARP_NLDELTA_SOFT_CLIP, ISHARP_NLDELTA_SCLIP_EN_P, mask_sh), \
	TF_SF(DSCL0_ISHARP_NLDELTA_SOFT_CLIP, ISHARP_NLDELTA_SCLIP_PIVOT_P, mask_sh), \
	TF_SF(DSCL0_ISHARP_NLDELTA_SOFT_CLIP, ISHARP_NLDELTA_SCLIP_SLOPE_P, mask_sh), \
	TF_SF(DSCL0_ISHARP_NLDELTA_SOFT_CLIP, ISHARP_NLDELTA_SCLIP_EN_N, mask_sh), \
	TF_SF(DSCL0_ISHARP_NLDELTA_SOFT_CLIP, ISHARP_NLDELTA_SCLIP_PIVOT_N, mask_sh), \
	TF_SF(DSCL0_ISHARP_NLDELTA_SOFT_CLIP, ISHARP_NLDELTA_SCLIP_SLOPE_N, mask_sh), \
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT_BOT, SCL_V_INIT_FRAC_BOT, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT_BOT, SCL_V_INIT_INT_BOT, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT_BOT_C, SCL_V_INIT_FRAC_BOT_C, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT_BOT_C, SCL_V_INIT_INT_BOT_C, mask_sh)

#define DPP_REG_FIELD_LIST_DCN401(type) \
	DPP_REG_FIELD_LIST_DCN3(type); \
	type CUR0_FP_BIAS_G_Y; \
	type CUR0_FP_SCALE_G_Y; \
	type CUR0_FP_BIAS_RB_CRCB; \
	type CUR0_FP_SCALE_RB_CRCB; \
	type CUR0_MATRIX_MODE; \
	type CUR0_MATRIX_MODE_CURRENT; \
	type CUR0_MATRIX_COEF_FORMAT; \
	type CUR0_MATRIX_C11_A; \
	type CUR0_MATRIX_C12_A; \
	type CUR0_MATRIX_C13_A; \
	type CUR0_MATRIX_C14_A; \
	type CUR0_MATRIX_C21_A; \
	type CUR0_MATRIX_C22_A; \
	type CUR0_MATRIX_C23_A; \
	type CUR0_MATRIX_C24_A; \
	type CUR0_MATRIX_C31_A; \
	type CUR0_MATRIX_C32_A; \
	type CUR0_MATRIX_C33_A; \
	type CUR0_MATRIX_C34_A; \
	type LUMA_KEYER_EN;	\
	type SCL_SC_MATRIX_MODE; \
	type SCL_SC_LTONL_EN; \
	type SCL_EASF_H_EN; \
	type SCL_EASF_H_RINGEST_FORCE_EN; \
	type SCL_EASF_H_2TAP_SHARP_FACTOR; \
	type SCL_EASF_H_BF1_EN; \
	type SCL_EASF_H_BF2_MODE; \
	type SCL_EASF_H_BF3_MODE; \
	type SCL_EASF_H_BF2_FLAT1_GAIN; \
	type SCL_EASF_H_BF2_FLAT2_GAIN; \
	type SCL_EASF_H_BF2_ROC_GAIN; \
	type SCL_EASF_H_RINGEST_EVENTAP_REDUCEG1; \
	type SCL_EASF_H_RINGEST_EVENTAP_REDUCEG2; \
	type SCL_EASF_H_RINGEST_EVENTAP_GAIN1; \
	type SCL_EASF_H_RINGEST_EVENTAP_GAIN2; \
	type SCL_EASF_H_BF_MAXA; \
	type SCL_EASF_H_BF_MAXB; \
	type SCL_EASF_H_BF_MINA; \
	type SCL_EASF_H_BF_MINB; \
	type SCL_EASF_H_BF1_PWL_IN_SEG0; \
	type SCL_EASF_H_BF1_PWL_BASE_SEG0; \
	type SCL_EASF_H_BF1_PWL_SLOPE_SEG0; \
	type SCL_EASF_H_BF1_PWL_IN_SEG1; \
	type SCL_EASF_H_BF1_PWL_BASE_SEG1; \
	type SCL_EASF_H_BF1_PWL_SLOPE_SEG1; \
	type SCL_EASF_H_BF1_PWL_IN_SEG2; \
	type SCL_EASF_H_BF1_PWL_BASE_SEG2; \
	type SCL_EASF_H_BF1_PWL_SLOPE_SEG2; \
	type SCL_EASF_H_BF1_PWL_IN_SEG3; \
	type SCL_EASF_H_BF1_PWL_BASE_SEG3; \
	type SCL_EASF_H_BF1_PWL_SLOPE_SEG3; \
	type SCL_EASF_H_BF1_PWL_IN_SEG4; \
	type SCL_EASF_H_BF1_PWL_BASE_SEG4; \
	type SCL_EASF_H_BF1_PWL_SLOPE_SEG4; \
	type SCL_EASF_H_BF1_PWL_IN_SEG5; \
	type SCL_EASF_H_BF1_PWL_BASE_SEG5; \
	type SCL_EASF_H_BF1_PWL_SLOPE_SEG5; \
	type SCL_EASF_H_BF1_PWL_IN_SEG6; \
	type SCL_EASF_H_BF1_PWL_BASE_SEG6; \
	type SCL_EASF_H_BF1_PWL_SLOPE_SEG6; \
	type SCL_EASF_H_BF1_PWL_IN_SEG7; \
	type SCL_EASF_H_BF1_PWL_BASE_SEG7; \
	type SCL_EASF_H_BF3_PWL_IN_SEG0; \
	type SCL_EASF_H_BF3_PWL_BASE_SEG0; \
	type SCL_EASF_H_BF3_PWL_SLOPE_SEG0; \
	type SCL_EASF_H_BF3_PWL_IN_SEG1; \
	type SCL_EASF_H_BF3_PWL_BASE_SEG1; \
	type SCL_EASF_H_BF3_PWL_SLOPE_SEG1; \
	type SCL_EASF_H_BF3_PWL_IN_SEG2; \
	type SCL_EASF_H_BF3_PWL_BASE_SEG2; \
	type SCL_EASF_H_BF3_PWL_SLOPE_SEG2; \
	type SCL_EASF_H_BF3_PWL_IN_SEG3; \
	type SCL_EASF_H_BF3_PWL_BASE_SEG3; \
	type SCL_EASF_H_BF3_PWL_SLOPE_SEG3; \
	type SCL_EASF_H_BF3_PWL_IN_SEG4; \
	type SCL_EASF_H_BF3_PWL_BASE_SEG4; \
	type SCL_EASF_H_BF3_PWL_SLOPE_SEG4; \
	type SCL_EASF_H_BF3_PWL_IN_SEG5; \
	type SCL_EASF_H_BF3_PWL_BASE_SEG5; \
	type SCL_EASF_V_EN; \
	type SCL_EASF_V_RINGEST_FORCE_EN; \
	type SCL_EASF_V_2TAP_SHARP_FACTOR; \
	type SCL_EASF_V_BF1_EN; \
	type SCL_EASF_V_BF2_MODE; \
	type SCL_EASF_V_BF3_MODE; \
	type SCL_EASF_V_BF2_FLAT1_GAIN; \
	type SCL_EASF_V_BF2_FLAT2_GAIN; \
	type SCL_EASF_V_BF2_ROC_GAIN; \
	type SCL_EASF_V_RINGEST_3TAP_DNTILT_UPTILT; \
	type SCL_EASF_V_RINGEST_3TAP_UPTILT_MAXVAL; \
	type SCL_EASF_V_RINGEST_3TAP_DNTILT_SLOPE; \
	type SCL_EASF_V_RINGEST_3TAP_UPTILT1_SLOPE; \
	type SCL_EASF_V_RINGEST_3TAP_UPTILT2_SLOPE; \
	type SCL_EASF_V_RINGEST_3TAP_UPTILT2_OFFSET; \
	type SCL_EASF_V_RINGEST_EVENTAP_REDUCEG1; \
	type SCL_EASF_V_RINGEST_EVENTAP_REDUCEG2; \
	type SCL_EASF_V_RINGEST_EVENTAP_GAIN1; \
	type SCL_EASF_V_RINGEST_EVENTAP_GAIN2; \
	type SCL_EASF_V_BF_MAXA; \
	type SCL_EASF_V_BF_MAXB; \
	type SCL_EASF_V_BF_MINA; \
	type SCL_EASF_V_BF_MINB; \
	type SCL_EASF_V_BF1_PWL_IN_SEG0; \
	type SCL_EASF_V_BF1_PWL_BASE_SEG0; \
	type SCL_EASF_V_BF1_PWL_SLOPE_SEG0; \
	type SCL_EASF_V_BF1_PWL_IN_SEG1; \
	type SCL_EASF_V_BF1_PWL_BASE_SEG1; \
	type SCL_EASF_V_BF1_PWL_SLOPE_SEG1; \
	type SCL_EASF_V_BF1_PWL_IN_SEG2; \
	type SCL_EASF_V_BF1_PWL_BASE_SEG2; \
	type SCL_EASF_V_BF1_PWL_SLOPE_SEG2; \
	type SCL_EASF_V_BF1_PWL_IN_SEG3; \
	type SCL_EASF_V_BF1_PWL_BASE_SEG3; \
	type SCL_EASF_V_BF1_PWL_SLOPE_SEG3; \
	type SCL_EASF_V_BF1_PWL_IN_SEG4; \
	type SCL_EASF_V_BF1_PWL_BASE_SEG4; \
	type SCL_EASF_V_BF1_PWL_SLOPE_SEG4; \
	type SCL_EASF_V_BF1_PWL_IN_SEG5; \
	type SCL_EASF_V_BF1_PWL_BASE_SEG5; \
	type SCL_EASF_V_BF1_PWL_SLOPE_SEG5; \
	type SCL_EASF_V_BF1_PWL_IN_SEG6; \
	type SCL_EASF_V_BF1_PWL_BASE_SEG6; \
	type SCL_EASF_V_BF1_PWL_SLOPE_SEG6; \
	type SCL_EASF_V_BF1_PWL_IN_SEG7; \
	type SCL_EASF_V_BF1_PWL_BASE_SEG7; \
	type SCL_EASF_V_BF3_PWL_IN_SEG0; \
	type SCL_EASF_V_BF3_PWL_BASE_SEG0; \
	type SCL_EASF_V_BF3_PWL_SLOPE_SEG0; \
	type SCL_EASF_V_BF3_PWL_IN_SEG1; \
	type SCL_EASF_V_BF3_PWL_BASE_SEG1; \
	type SCL_EASF_V_BF3_PWL_SLOPE_SEG1; \
	type SCL_EASF_V_BF3_PWL_IN_SEG2; \
	type SCL_EASF_V_BF3_PWL_BASE_SEG2; \
	type SCL_EASF_V_BF3_PWL_SLOPE_SEG2; \
	type SCL_EASF_V_BF3_PWL_IN_SEG3; \
	type SCL_EASF_V_BF3_PWL_BASE_SEG3; \
	type SCL_EASF_V_BF3_PWL_SLOPE_SEG3; \
	type SCL_EASF_V_BF3_PWL_IN_SEG4; \
	type SCL_EASF_V_BF3_PWL_BASE_SEG4; \
	type SCL_EASF_V_BF3_PWL_SLOPE_SEG4; \
	type SCL_EASF_V_BF3_PWL_IN_SEG5; \
	type SCL_EASF_V_BF3_PWL_BASE_SEG5; \
	type SCL_SC_MATRIX_C0; \
	type SCL_SC_MATRIX_C1; \
	type SCL_SC_MATRIX_C2; \
	type SCL_SC_MATRIX_C3; \
	type ISHARP_EN;	\
	type ISHARP_NOISEDET_EN;	\
	type ISHARP_NOISEDET_MODE;	\
	type ISHARP_NOISEDET_UTHRE;	\
	type ISHARP_NOISEDET_DTHRE;	\
	type ISHARP_NOISEDET_PWL_START_IN;	\
	type ISHARP_NOISEDET_PWL_END_IN;	\
	type ISHARP_NOISEDET_PWL_SLOPE;	\
	type ISHARP_LBA_MODE;	\
	type ISHARP_LBA_PWL_IN_SEG0;	\
	type ISHARP_LBA_PWL_BASE_SEG0;	\
	type ISHARP_LBA_PWL_SLOPE_SEG0;	\
	type ISHARP_LBA_PWL_IN_SEG1;	\
	type ISHARP_LBA_PWL_BASE_SEG1;	\
	type ISHARP_LBA_PWL_SLOPE_SEG1;	\
	type ISHARP_LBA_PWL_IN_SEG2;	\
	type ISHARP_LBA_PWL_BASE_SEG2;	\
	type ISHARP_LBA_PWL_SLOPE_SEG2;	\
	type ISHARP_LBA_PWL_IN_SEG3;	\
	type ISHARP_LBA_PWL_BASE_SEG3;	\
	type ISHARP_LBA_PWL_SLOPE_SEG3;	\
	type ISHARP_LBA_PWL_IN_SEG4;	\
	type ISHARP_LBA_PWL_BASE_SEG4;	\
	type ISHARP_LBA_PWL_SLOPE_SEG4;	\
	type ISHARP_LBA_PWL_IN_SEG5;	\
	type ISHARP_LBA_PWL_BASE_SEG5;	\
	type ISHARP_FMT_MODE;	\
	type ISHARP_FMT_NORM;	\
	type ISHARP_DELTA_LUT_SELECT;	\
	type ISHARP_DELTA_LUT_SELECT_CURRENT;	\
	type ISHARP_DELTA_LUT_HOST_SELECT;	\
	type ISHARP_DELTA_DATA;	\
	type ISHARP_DELTA_INDEX; \
	type ISHARP_NLDELTA_SCLIP_EN_P;	\
	type ISHARP_NLDELTA_SCLIP_PIVOT_P;	\
	type ISHARP_NLDELTA_SCLIP_SLOPE_P;	\
	type ISHARP_NLDELTA_SCLIP_EN_N;	\
	type ISHARP_NLDELTA_SCLIP_PIVOT_N;	\
	type ISHARP_NLDELTA_SCLIP_SLOPE_N

struct dcn401_dpp_registers {
	DPP_DCN3_REG_VARIABLE_LIST_COMMON;
	uint32_t CURSOR0_FP_SCALE_BIAS_G_Y;
	uint32_t CURSOR0_FP_SCALE_BIAS_RB_CRCB;
	uint32_t CUR0_MATRIX_MODE;
	uint32_t CUR0_MATRIX_C11_C12_A;
	uint32_t CUR0_MATRIX_C13_C14_A;
	uint32_t CUR0_MATRIX_C21_C22_A;
	uint32_t CUR0_MATRIX_C23_C24_A;
	uint32_t CUR0_MATRIX_C31_C32_A;
	uint32_t CUR0_MATRIX_C33_C34_A;
	uint32_t CUR0_MATRIX_C11_C12_B;
	uint32_t CUR0_MATRIX_C13_C14_B;
	uint32_t CUR0_MATRIX_C21_C22_B;
	uint32_t CUR0_MATRIX_C23_C24_B;
	uint32_t CUR0_MATRIX_C31_C32_B;
	uint32_t CUR0_MATRIX_C33_C34_B;
	uint32_t DSCL_SC_MODE;
	uint32_t DSCL_EASF_H_MODE;
	uint32_t DSCL_EASF_H_BF_CNTL;
	uint32_t DSCL_EASF_H_RINGEST_EVENTAP_REDUCE;
	uint32_t DSCL_EASF_H_RINGEST_EVENTAP_GAIN;
	uint32_t DSCL_EASF_H_BF_FINAL_MAX_MIN;
	uint32_t DSCL_EASF_H_BF1_PWL_SEG0;
	uint32_t DSCL_EASF_H_BF1_PWL_SEG1;
	uint32_t DSCL_EASF_H_BF1_PWL_SEG2;
	uint32_t DSCL_EASF_H_BF1_PWL_SEG3;
	uint32_t DSCL_EASF_H_BF1_PWL_SEG4;
	uint32_t DSCL_EASF_H_BF1_PWL_SEG5;
	uint32_t DSCL_EASF_H_BF1_PWL_SEG6;
	uint32_t DSCL_EASF_H_BF1_PWL_SEG7;
	uint32_t DSCL_EASF_H_BF3_PWL_SEG0;
	uint32_t DSCL_EASF_H_BF3_PWL_SEG1;
	uint32_t DSCL_EASF_H_BF3_PWL_SEG2;
	uint32_t DSCL_EASF_H_BF3_PWL_SEG3;
	uint32_t DSCL_EASF_H_BF3_PWL_SEG4;
	uint32_t DSCL_EASF_H_BF3_PWL_SEG5;
	uint32_t DSCL_EASF_V_MODE;
	uint32_t DSCL_EASF_V_BF_CNTL;
	uint32_t DSCL_EASF_V_RINGEST_3TAP_CNTL1;
	uint32_t DSCL_EASF_V_RINGEST_3TAP_CNTL2;
	uint32_t DSCL_EASF_V_RINGEST_3TAP_CNTL3;
	uint32_t DSCL_EASF_V_RINGEST_EVENTAP_REDUCE;
	uint32_t DSCL_EASF_V_RINGEST_EVENTAP_GAIN;
	uint32_t DSCL_EASF_V_BF_FINAL_MAX_MIN;
	uint32_t DSCL_EASF_V_BF1_PWL_SEG0;
	uint32_t DSCL_EASF_V_BF1_PWL_SEG1;
	uint32_t DSCL_EASF_V_BF1_PWL_SEG2;
	uint32_t DSCL_EASF_V_BF1_PWL_SEG3;
	uint32_t DSCL_EASF_V_BF1_PWL_SEG4;
	uint32_t DSCL_EASF_V_BF1_PWL_SEG5;
	uint32_t DSCL_EASF_V_BF1_PWL_SEG6;
	uint32_t DSCL_EASF_V_BF1_PWL_SEG7;
	uint32_t DSCL_EASF_V_BF3_PWL_SEG0;
	uint32_t DSCL_EASF_V_BF3_PWL_SEG1;
	uint32_t DSCL_EASF_V_BF3_PWL_SEG2;
	uint32_t DSCL_EASF_V_BF3_PWL_SEG3;
	uint32_t DSCL_EASF_V_BF3_PWL_SEG4;
	uint32_t DSCL_EASF_V_BF3_PWL_SEG5;
	uint32_t DSCL_SC_MATRIX_C0C1;
	uint32_t DSCL_SC_MATRIX_C2C3;
	uint32_t ISHARP_MODE;
	uint32_t ISHARP_NOISEDET_THRESHOLD;
	uint32_t ISHARP_NOISE_GAIN_PWL;
	uint32_t ISHARP_LBA_PWL_SEG0;
	uint32_t ISHARP_LBA_PWL_SEG1;
	uint32_t ISHARP_LBA_PWL_SEG2;
	uint32_t ISHARP_LBA_PWL_SEG3;
	uint32_t ISHARP_LBA_PWL_SEG4;
	uint32_t ISHARP_LBA_PWL_SEG5;
	uint32_t ISHARP_DELTA_CTRL;
	uint32_t ISHARP_DELTA_DATA;
	uint32_t ISHARP_DELTA_INDEX;
	uint32_t ISHARP_NLDELTA_SOFT_CLIP;
};

struct dcn401_dpp_shift {
	DPP_REG_FIELD_LIST_DCN401(uint8_t);
};

struct dcn401_dpp_mask {
	DPP_REG_FIELD_LIST_DCN401(uint32_t);
};

struct dcn401_dpp {
	struct dpp base;

	const struct dcn401_dpp_registers *tf_regs;
	const struct dcn401_dpp_shift *tf_shift;
	const struct dcn401_dpp_mask *tf_mask;

	const uint16_t *filter_v;
	const uint16_t *filter_h;
	const uint16_t *filter_v_c;
	const uint16_t *filter_h_c;
	int lb_pixel_depth_supported;
	int lb_memory_size;
	int lb_bits_per_entry;
	bool is_write_to_ram_a_safe;
	struct scaler_data scl_data;
	struct pwl_params pwl_data;
};

bool dpp401_construct(struct dcn401_dpp *dpp401,
	struct dc_context *ctx,
	uint32_t inst,
	const struct dcn401_dpp_registers *tf_regs,
	const struct dcn401_dpp_shift *tf_shift,
	const struct dcn401_dpp_mask *tf_mask);

void dpp401_dscl_set_scaler_manual_scale(
	struct dpp *dpp_base,
	const struct scaler_data *scl_data);

void dpp401_full_bypass(struct dpp *dpp_base);

void dpp401_dpp_setup(
	struct dpp *dpp_base,
	enum surface_pixel_format format,
	enum expansion_mode mode,
	struct dc_csc_transform input_csc_color_matrix,
	enum dc_color_space input_color_space,
	struct cnv_alpha_2bit_lut *alpha_2bit_lut);

void dpp401_set_cursor_attributes(
	struct dpp *dpp_base,
	struct dc_cursor_attributes *cursor_attributes);

void dpp401_set_cursor_position(
	struct dpp *dpp_base,
	const struct dc_cursor_position *pos,
	const struct dc_cursor_mi_param *param,
	uint32_t width,
	uint32_t height);

void dpp401_set_optional_cursor_attributes(
	struct dpp *dpp_base,
	struct dpp_cursor_attributes *attr);

void dscl401_calc_lb_num_partitions(
		const struct scaler_data *scl_data,
		enum lb_memory_config lb_config,
		int *num_part_y,
		int *num_part_c);

void dscl401_spl_calc_lb_num_partitions(
		bool alpha_en,
		const struct spl_scaler_data *scl_data,
		enum lb_memory_config lb_config,
		int *num_part_y,
		int *num_part_c);

void dpp401_read_state(struct dpp *dpp_base, struct dcn_dpp_state *s);

void dpp401_set_cursor_matrix(
	struct dpp *dpp_base,
	enum dc_color_space color_space,
	struct dc_csc_transform cursor_csc_color_matrix);

#endif /* __DCN401_DPP_H__ */
