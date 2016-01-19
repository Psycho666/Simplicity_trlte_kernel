/*
 * =================================================================
 *
 *       Filename:  smart_mtp_s6e3.h
 *
 *    Description:  Smart dimming algorithm implementation
 *
 *        Company:  Samsung Electronics
 *
 * ================================================================
 */
/*
<one line to give the program's name and a brief idea of what it does.>
Copyright (C) 2012, Samsung Electronics. All rights reserved.

*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
*/
#ifndef _SS_DSI_SMART_DIMMING_S6E3HA2_AMS567DJ01_H_
#define _SS_DSI_SMART_DIMMING_S6E3HA2_AMS567DJ01_H_

#include "../ss_dsi_panel_common.h"
#include "../ss_dsi_smart_dimming_common.h"

/*
*	From 4.8 inch model use AID function
*	CASE#1 is used for now.
*/
#define AID_OPERATION

#define MAX_TABLE_HMT 29

enum {
	GAMMA_CURVE_1P9 = 0,
	GAMMA_CURVE_2P15,
	GAMMA_CURVE_2P2,
};

#define LUMINANCE_MAX 65
#define GAMMA_SET_MAX 35
#define BIT_SHIFT 22
/*
	it means BIT_SHIFT is 22.  pow(2,BIT_SHIFT) is 4194304.
	BIT_SHIFT is used for right bit shfit
*/
#define BIT_SHFIT_MUL 4194304

#define GRAY_SCALE_MAX 256

/*6.4*4194304 */
#define VREG0_REF_6P4 26843546

/*6.3*4194304 */
#define VREG0_REF_6P3 26424115

/*6.2*4194304 */
#define VREG0_REF_6P2 26004685

/*V0,V3,V11,V23,V35,V51,V87,V151,V203,V255*/
#define ARRAY_MAX 11

/* PANEL DEPENDENT THINGS */
#define MIN_CANDELA	2

/*
*	ID 0x20
*/
#define V255_300CD_R_MSB_20 0x01
#define V255_300CD_R_LSB_20 0x00

#define V255_300CD_G_MSB_20 0x01
#define V255_300CD_G_LSB_20 0x00

#define V255_300CD_B_MSB_20 0x01
#define V255_300CD_B_LSB_20 0x00

#define V203_300CD_R_20 0x80
#define V203_300CD_G_20 0x80
#define V203_300CD_B_20 0x80

#define V151_300CD_R_20 0x80
#define V151_300CD_G_20 0x80
#define V151_300CD_B_20 0x80

#define V87_300CD_R_20 0x80
#define V87_300CD_G_20 0x80
#define V87_300CD_B_20 0x80

#define V51_300CD_R_20 0x80
#define V51_300CD_G_20 0x80
#define V51_300CD_B_20 0x80

#define V35_300CD_R_20 0x80
#define V35_300CD_G_20 0x80
#define V35_300CD_B_20 0x80

#define V23_300CD_R_20 0x80
#define V23_300CD_G_20 0x80
#define V23_300CD_B_20 0x80

#define V11_300CD_R_20 0x80
#define V11_300CD_G_20 0x80
#define V11_300CD_B_20 0x80

#define V3_300CD_R_20 0x80
#define V3_300CD_G_20 0x80
#define V3_300CD_B_20 0x80

#define V0_300CD_R_20 0x00
#define V0_300CD_G_20 0x00
#define V0_300CD_B_20 0x00

#define VT_300CD_R_20 0x00
#define VT_300CD_G_20 0x00
#define VT_300CD_B_20 0x00

#define PANEL_REVA 0x01
#define PANEL_REVB 0x02
#define PANEL_REVC 0x03
#define PANEL_REVD 0x04
#define PANEL_REVF 0x05
#define PANEL_REVG 0x06
#define PANEL_REVH 0x07
#define PANEL_REVI 0x08
#define PANEL_REVJ 0x09

#define AOR_FIX_CD		172
#define AOR_ADJUST_CD		111
#define AOR_DIM_BASE_CD		116
#define AOR_DIM_BASE_CD_REVA 	110
#define AOR_DIM_BASE_CD_REVB 	112
#define AOR_DIM_BASE_CD_REVD 	114

#define AOR_DIM_BASE_CD_REVC 	117
#define AOR_DIM_BASE_CD_REVF	119
#define AOR_DIM_BASE_CD_REVH	113


/* PANEL DEPENDENT THINGS END*/

enum {
	V1_INDEX = 0,
	V3_INDEX = 1,
	V11_INDEX = 2,
	V23_INDEX = 3,
	V35_INDEX = 4,
	V51_INDEX = 5,
	V87_INDEX = 6,
	V151_INDEX = 7,
	V203_INDEX = 8,
	V255_INDEX = 9,
};

struct GAMMA_LEVEL {
	int level_0;
	int level_1;
	int level_3;
	int level_11;
	int level_23;
	int level_35;
	int level_51;
	int level_87;
	int level_151;
	int level_203;
	int level_255;
} __packed;

struct RGB_OUTPUT_VOLTARE {
	struct GAMMA_LEVEL R_VOLTAGE;
	struct GAMMA_LEVEL G_VOLTAGE;
	struct GAMMA_LEVEL B_VOLTAGE;
} __packed;

struct GRAY_VOLTAGE {
	/*
		This voltage value use 14bit right shit
		it means voltage is divied by 16384.
	*/
	int R_Gray;
	int G_Gray;
	int B_Gray;
} __packed;

struct GRAY_SCALE {
	struct GRAY_VOLTAGE TABLE[GRAY_SCALE_MAX];
	struct GRAY_VOLTAGE VT_TABLE;
} __packed;

/*V0,V1,V3,V11,V23,V35,V51,V87,V151,V203,V255*/

struct MTP_SET {
	char OFFSET_255_MSB;
	char OFFSET_255_LSB;
	char OFFSET_203;
	char OFFSET_151;
	char OFFSET_87;
	char OFFSET_51;
	char OFFSET_35;
	char OFFSET_23;
	char OFFSET_11;
	char OFFSET_3;
	char OFFSET_0;
	char OFFSET_T;
} __packed;

struct MTP_SET_R {
	char OFFSET_255_MSB;
	char OFFSET_255_LSB;
	char OFFSET_203;
	char OFFSET_151;
	char OFFSET_87;
	char OFFSET_51;
	char OFFSET_35;
	char OFFSET_23;
	char OFFSET_11;
	char OFFSET_3;
	char OFFSET_0;
} __packed;

struct MTP_OFFSET {
	struct MTP_SET_R R_OFFSET;
	struct MTP_SET G_OFFSET;
	struct MTP_SET B_OFFSET;
} __packed;

struct illuminance_table {
	int lux;
	char gamma_setting[GAMMA_SET_MAX];
} __packed;

struct SMART_DIM {
	struct MTP_OFFSET MTP_ORIGN;
	struct MTP_OFFSET MTP;
	struct RGB_OUTPUT_VOLTARE RGB_OUTPUT;
	struct GRAY_SCALE GRAY;

	/* Because of AID funtion, below members are added*/
	int lux_table_max;
	int *plux_table;
	struct illuminance_table gen_table[LUMINANCE_MAX];
	struct illuminance_table hmt_gen_table[MAX_TABLE_HMT];

	int brightness_level;
	int ldi_revision;
	int vregout_voltage;
} __packed;


#define CANDELA_MAX_TABLE 64
#define RGB_COMPENSATION 24

static int candela_table[][2] = {
	{2, 0,},
	{3, 1,},
	{4, 2,},
	{5, 3,},
	{6, 4,},
	{7, 5,},
	{8, 6,},
	{9, 7,},
	{10, 8,},
	{11, 9,},
	{12, 10,},
	{13, 11,},
	{14, 12,},
	{15, 13,},
	{16, 14,},
	{17, 15,},
	{19, 16,},
	{20, 17,},
	{21, 18,},
	{22, 19,},
	{24, 20,},
	{25, 21,},
	{27, 22,},
	{29, 23,},
	{30, 24,},
	{32, 25,},
	{34, 26,},
	{37, 27,},
	{39, 28,},
	{41, 29,},
	{44, 30,},
	{47, 31,},
	{50, 32,},
	{53, 33,},
	{56, 34,},
	{60, 35,},
	{64, 36,},
	{68, 37,},
	{72, 38,},
	{77, 39,},
	{82, 40,},
	{87, 41,},
	{93, 42,},
	{98, 43,},
	{105, 44,},
	{111, 45,},
	{119, 46,},
	{126, 47,},
	{134, 48,},
	{143, 49,},
	{152, 50,},
	{162, 51,},
	{172, 52,},
	{183, 53,},
	{195, 54,},
	{207, 55,},
	{220, 56,},
	{234, 57,},
	{249, 58,},
	{265, 59,},
	{282, 60,},
	{300, 61,},
	{316, 62,},
	{333, 63,},
	{350, 64,},
};

static int gradation_offset_revA[][9] = {
/*	V255 V203 V151 V87 V51 V35 V23 V11 V3 */
	{ 0, 7, 13, 19, 27, 31, 34, 32, 32 },
	{ 0, 6, 11, 15, 20, 25, 28, 32, 32 },
	{ 0, 5, 8, 12, 16, 20, 23, 27, 26 },
	{ 0, 5, 7, 11, 14, 17, 20, 25, 22 },
	{ 0, 4, 6, 9, 12, 15, 18, 22, 21 },
	{ 0, 4, 6, 8, 11, 13, 16, 20, 22 },
	{ 0, 3, 5, 8, 10, 12, 15, 19, 19 },
	{ 0, 3, 4, 7, 9, 11, 14, 18, 16 },
	{ 0, 3, 4, 6, 8, 10, 13, 16, 19 },
	{ 0, 3, 4, 6, 7, 9, 11, 15, 19 },
	{ 0, 3, 4, 6, 7, 9, 11, 15, 14 },
	{ 0, 3, 4, 5, 7, 8, 10, 14, 16 },
	{ 0, 3, 4, 5, 6, 8, 10, 14, 13 },
	{ 0, 3, 4, 5, 6, 7, 9, 13, 16 },
	{ 0, 3, 4, 4, 5, 7, 8, 13, 13 },
	{ 0, 3, 3, 5, 5, 7, 8, 13, 12 },
	{ 0, 3, 3, 4, 5, 6, 7, 12, 10 },
	{ 0, 3, 3, 4, 4, 6, 7, 12, 10 },
	{ 0, 3, 3, 4, 4, 6, 7, 11, 12 },
	{ 0, 3, 3, 4, 4, 6, 7, 11, 11 },
	{ 0, 2, 3, 4, 4, 5, 6, 10, 12 },
	{ 0, 3, 3, 4, 4, 5, 6, 10, 12 },
	{ 0, 3, 3, 3, 3, 4, 6, 9, 13 },
	{ 0, 2, 3, 3, 3, 4, 6, 9, 10 },
	{ 0, 2, 3, 3, 3, 4, 6, 9, 10 },
	{ 0, 2, 3, 3, 3, 4, 5, 8, 11 },
	{ 0, 2, 3, 3, 3, 3, 5, 8, 9 },
	{ 0, 2, 3, 3, 2, 3, 5, 8, 7 },
	{ 0, 2, 2, 2, 2, 3, 4, 7, 10 },
	{ 0, 2, 2, 2, 2, 3, 4, 7, 8 },
	{ 0, 2, 2, 2, 2, 3, 4, 6, 5 },
	{ 0, 2, 2, 2, 2, 2, 4, 6, 9 },
	{ 0, 2, 2, 2, 2, 2, 4, 6, 7 },
	{ 0, 2, 2, 2, 2, 2, 3, 6, 4 },
	{ 0, 2, 2, 2, 1, 2, 3, 5, 7 },
	{ 0, 2, 2, 2, 1, 1, 3, 5, 4 },
	{ 0, 2, 2, 2, 1, 1, 3, 4, 8 },
	{ 0, 2, 1, 2, 1, 1, 2, 4, 5 },
	{ 0, 2, 1, 1, 1, 1, 2, 4, 3 },
	{ 0, 3, 0, 1, 1, 1, 3, 4, 5 },
	{ 0, 2, 2, 2, 1, 1, 3, 3, 5 },
	{ 0, 1, 1, 2, 0, 1, 2, 3, 4 },
	{ 0, 1, 0, 1, 0, 0, 2, 3, 5 },
	{ 0, 2, 2, 2, 2, 1, 2, 3, 7 },
	{ 0, 2, 2, 2, 1, 1, 2, 3, 6 },
	{ 0, 2, 3, 2, 1, 1, 1, 2, 6 },
	{ 0, 1, 3, 3, 1, 1, 2, 3, 2 },
	{ 0, 2, 4, 2, 1, 1, 2, 3, 3 },
	{ 0, 2, 3, 2, 2, 1, 2, 3, 2 },
	{ 0, 2, 3, 2, 2, 1, 2, 3, 4 },
	{ 0, 3, 4, 2, 1, 1, 1, 2, 4 },
	{ 0, 2, 3, 2, 1, 1, 2, 2, 3 },
	{ 0, 3, 4, 3, 1, 1, 1, 3, 1 },
	{ 0, 2, 3, 2, 1, 0, 1, 1, 4 },
	{ 0, 2, 2, 2, 0, 0, 1, 1, 3 },
	{ 0, 2, 2, 1, 0, 0, 0, 1, 0 },
	{ 0, 1, 1, 1, 0, -1, 0, 1, 0 },
	{ 0, 1, 1, 1, 0, -1, 0, 1, 0 },
	{ 0, 1, 1, 0, 0, -1, 0, 0, 4 },
	{ 0, 1, 1, 0, 0, -1, -1, 0, 0 },
	{ 0, 1, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 0, -1, -1, -1, 0, 1 },
	{ 0, 2, 1, 0, -1, 0, 0, 0, 2 },
	{ 0, 0, 1, -2, -1, -1, -1, -1, 3 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

static int gradation_offset_revC[][9] = {
/*	V255 V203 V151 V87 V51 V35 V23 V11 V3 */
	{0, 8, 14, 23, 32, 37, 40, 35, 37},
	{0, 7, 12, 19, 25, 28, 32, 35, 37},
	{0, 6, 10, 16, 21, 25, 28, 31, 32},
	{0, 6, 8, 14, 17, 21, 23, 27, 28},
	{0, 5, 7, 12, 15, 19, 21, 25, 25},
	{0, 5, 6, 11, 14, 16, 19, 23, 21},
	{0, 5, 6, 10, 12, 15, 17, 22, 20},
	{0, 4, 5, 9, 12, 14, 16, 20, 22},
	{0, 4, 5, 9, 11, 13, 16, 19, 20},
	{0, 3, 4, 8, 10, 11, 14, 18, 18},
	{0, 3, 4, 7, 9, 11, 13, 17, 17},
	{0, 3, 4, 7, 9, 10, 13, 16, 16},
	{0, 3, 4, 7, 8, 10, 12, 15, 18},
	{0, 3, 3, 6, 8, 9, 11, 15, 14},
	{0, 3, 3, 6, 7, 9, 11, 15, 13},
	{0, 3, 3, 6, 7, 8, 10, 14, 14},
	{0, 3, 3, 5, 6, 8, 9, 13, 15},
	{0, 3, 3, 5, 6, 8, 9, 13, 12},
	{0, 3, 3, 5, 6, 7, 9, 13, 11},
	{0, 3, 2, 5, 5, 7, 8, 12, 15},
	{0, 3, 2, 5, 5, 7, 8, 12, 9},
	{0, 3, 2, 5, 5, 6, 7, 11, 14},
	{0, 3, 2, 5, 5, 6, 7, 11, 9},
	{0, 3, 2, 5, 4, 6, 7, 10, 13},
	{0, 3, 2, 4, 4, 5, 6, 10, 11},
	{0, 3, 2, 4, 4, 5, 6, 10, 9},
	{0, 3, 2, 4, 3, 5, 6, 9, 11},
	{0, 3, 2, 3, 3, 4, 5, 9, 7},
	{0, 2, 2, 3, 3, 4, 5, 8, 10},
	{0, 2, 2, 3, 3, 4, 5, 8, 8},
	{0, 2, 2, 3, 3, 4, 5, 7, 10},
	{0, 2, 2, 3, 2, 3, 4, 7, 8},
	{0, 2, 1, 3, 2, 3, 4, 7, 6},
	{0, 2, 1, 3, 2, 3, 4, 6, 9},
	{0, 2, 1, 2, 2, 3, 4, 6, 6},
	{0, 2, 1, 2, 2, 2, 3, 5, 9},
	{0, 2, 1, 2, 2, 2, 3, 5, 7},
	{0, 2, 1, 2, 2, 2, 3, 5, 5},
	{0, 2, 1, 2, 1, 2, 3, 5, 4},
	{0, 2, 1, 2, 1, 2, 3, 4, 6},
	{0, 3, 1, 2, 1, 1, 3, 4, 7},
	{0, 2, 2, 2, 1, 1, 3, 3, 5},
	{0, 2, 3, 2, 1, 1, 2, 3, 6},
	{0, 1, 2, 2, 0, 1, 3, 3, 6},
	{0, 1, 2, 2, 1, 2, 2, 4, 4},
	{0, 1, 2, 2, 1, 1, 2, 3, 6},
	{0, 1, 3, 3, 1, 1, 2, 3, 3},
	{0, 1, 3, 2, 1, 1, 2, 3, 4},
	{0, 2, 3, 2, 0, 1, 1, 3, 3},
	{0, 2, 2, 2, 1, 1, 2, 3, 3},
	{0, 2, 3, 2, 1, 1, 1, 2, 4},
	{0, 2, 4, 2, 1, 1, 2, 2, 5},
	{0, 2, 4, 2, 1, 1, 1, 3, 1},
	{0, 3, 4, 3, 1, 0, 1, 2, 3},
	{0, 2, 3, 2, 1, 0, 1, 2, 0},
	{0, 2, 2, 2, 0, 0, 1, 1, 3},
	{0, 2, 2, 1, 0, 0, 0, 1, 1},
	{0, 1, 1, 1, 0, -1, 0, 1, 0},
	{0, 1, 1, 1, 0, -1, 0, 1, 0},
	{0, 2, 2, 1, 0, -1, 0, 1, 1},
	{0, 0, 1, -1, 0, -1, 0, 0, 2},
	{0, 1, 1, -1, -1, -1, -1, 0, 2},
	{0, 2, 2, 0, 0, 0, 0, 0, 3},
	{0, 1, 1, 0, 0, -1, -1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static int gradation_offset_revH[][9] = {
/*	V255 V203 V151 V87 V51 V35 V23 V11 V3 */
	{0, 9, 17, 22, 27, 33, 35, 27, 4},
	{0, 8, 12, 17, 17, 25, 29, 29, 4},
	{0, 7, 12, 16, 19, 21, 24, 26, 23},
	{0, 5, 9, 13, 15, 17, 20, 22, 21},
	{0, 6, 10, 12, 14, 16, 19, 21, 21},
	{0, 5, 9, 11, 13, 14, 18, 20, 21},
	{0, 4, 8, 10, 12, 13, 17, 19, 19},
	{0, 4, 7, 9, 12, 13, 16, 19, 18},
	{0, 4, 7, 9, 10, 12, 15, 18, 20},
	{0, 4, 7, 8, 10, 11, 15, 17, 16},
	{0, 4, 6, 8, 10, 11, 14, 16, 17},
	{0, 4, 6, 7, 10, 11, 14, 16, 17},
	{0, 4, 5, 6, 9, 10, 13, 15, 17},
	{0, 4, 6, 7, 9, 10, 12, 15, 15},
	{0, 4, 5, 6, 8, 9, 12, 14, 16},
	{0, 4, 5, 6, 8, 9, 11, 14, 13},
	{0, 4, 5, 6, 7, 8, 10, 13, 14},
	{0, 4, 5, 5, 7, 8, 10, 13, 11},
	{0, 4, 5, 5, 7, 7, 10, 13, 10},
	{0, 4, 5, 5, 6, 7, 9, 12, 11},
	{0, 4, 4, 5, 6, 6, 8, 11, 12},
	{0, 4, 5, 5, 6, 6, 8, 11, 11},
	{0, 4, 4, 4, 5, 6, 8, 10, 12},
	{0, 4, 4, 4, 5, 6, 8, 10, 9},
	{0, 3, 5, 4, 5, 5, 8, 10, 8},
	{0, 4, 4, 4, 5, 5, 7, 9, 10},
	{0, 4, 4, 4, 4, 5, 7, 9, 7},
	{0, 4, 4, 3, 4, 4, 6, 8, 8},
	{0, 3, 4, 4, 4, 5, 6, 8, 8},
	{0, 4, 4, 3, 4, 4, 6, 7, 10},
	{0, 3, 4, 3, 4, 4, 6, 7, 8},
	{0, 3, 4, 3, 3, 4, 6, 7, 5},
	{0, 3, 4, 3, 4, 3, 5, 6, 8},
	{0, 3, 4, 3, 3, 3, 5, 6, 6},
	{0, 3, 4, 3, 3, 3, 5, 5, 8},
	{0, 3, 4, 3, 3, 3, 5, 5, 6},
	{0, 3, 4, 2, 3, 2, 4, 5, 4},
	{0, 3, 3, 2, 3, 2, 4, 4, 6},
	{0, 3, 3, 2, 3, 2, 4, 4, 4},
	{0, 3, 3, 2, 3, 2, 3, 4, 2},
	{0, 2, 3, 2, 2, 3, 3, 4, 2},
	{0, 1, 2, 2, 2, 2, 3, 4, 1},
	{0, 2, 3, 3, 2, 2, 3, 4, 1},
	{0, 2, 4, 3, 2, 2, 3, 3, 5},
	{0, 1, 3, 2, 2, 2, 3, 3, 4},
	{0, 0, 2, 2, 1, 1, 3, 3, 2},
	{0, 0, 4, 3, 2, 2, 3, 3, 4},
	{0, -2, 3, 3, 2, 2, 3, 3, 6},
	{0, -1, 3, 2, 2, 1, 3, 3, 5},
	{0, 0, 2, 3, 2, 1, 2, 3, 0},
	{0, 0, 3, 3, 2, 2, 2, 3, 2},
	{0, 0, 3, 3, 2, 2, 2, 2, 0},
	{0, 0, 2, 2, 1, 2, 1, 2, 3},
	{0, 1, 3, 2, 1, 1, 1, 1, 2},
	{0, 0, 2, 2, 1, 1, 1, 1, 1},
	{0, -1, 1, 1, 1, 1, 0, 1, 0},
	{0, -1, 1, 1, 1, 1, 0, 1, 0},
	{0, -1, 1, 1, 0, 1, 0, 1, 2},
	{0, 0, 1, 1, 0, 0, 0, 0, 2},
	{0, 1, 1, 1, 0, 0, 1, 0, 3},
	{0, 1, 1, 1, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0, 0, 0, 0, 0},
	{0, 1, 0, 1, 0, -1, 0, 0, 0},
	{0, 0, 0, 0, 0, -1, -1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
};


static int gradation_offset_revF[][9] = {
	{0, 8, 13, 21, 27, 29, 32, 30, 23},
	{0, 8, 12, 16, 20, 24, 27, 30, 23},
	{0, 7, 10, 15, 18, 21, 23, 27, 25},
	{0, 6, 9, 13, 15, 17, 19, 23, 22},
	{0, 6, 8, 12, 14, 16, 18, 22, 23},
	{0, 5, 8, 11, 13, 15, 17, 21, 20},
	{0, 5, 7, 10, 11, 13, 16, 19, 21},
	{0, 5, 7, 9, 11, 13, 16, 19, 19},
	{0, 5, 6, 9, 11, 13, 15, 18, 21},
	{0, 3, 5, 7, 10, 12, 14, 17, 21},
	{0, 3, 4, 7, 9, 11, 13, 17, 17},
	{0, 3, 4, 6, 8, 10, 13, 16, 17},
	{0, 3, 4, 6, 8, 10, 12, 16, 15},
	{0, 4, 5, 6, 8, 10, 12, 15, 16},
	{0, 4, 4, 6, 7, 9, 11, 14, 17},
	{0, 3, 3, 5, 7, 9, 10, 14, 15},
	{0, 3, 3, 5, 6, 8, 9, 13, 15},
	{0, 3, 4, 5, 6, 8, 9, 13, 14},
	{0, 3, 3, 4, 6, 8, 9, 13, 13},
	{0, 3, 3, 4, 6, 7, 8, 12, 13},
	{0, 3, 3, 4, 5, 7, 8, 12, 12},
	{0, 3, 3, 4, 5, 7, 8, 11, 12},
	{0, 3, 3, 4, 5, 6, 7, 11, 11},
	{0, 3, 3, 4, 4, 6, 7, 10, 11},
	{0, 3, 3, 4, 4, 6, 7, 10, 10},
	{0, 3, 3, 3, 4, 5, 6, 9, 10},
	{0, 3, 3, 3, 4, 5, 6, 9, 9},
	{0, 3, 2, 3, 3, 5, 5, 8, 9},
	{0, 3, 2, 2, 3, 4, 5, 8, 9},
	{0, 3, 2, 2, 3, 4, 5, 8, 7},
	{0, 3, 2, 2, 3, 4, 5, 7, 9},
	{0, 3, 2, 2, 2, 3, 4, 7, 7},
	{0, 3, 2, 2, 2, 3, 4, 7, 6},
	{0, 3, 2, 2, 2, 3, 4, 6, 8},
	{0, 2, 2, 2, 2, 3, 4, 6, 6},
	{0, 2, 2, 2, 2, 3, 3, 5, 7},
	{0, 2, 2, 1, 2, 2, 3, 5, 6},
	{0, 2, 1, 1, 2, 2, 3, 5, 4},
	{0, 2, 1, 1, 1, 2, 3, 4, 6},
	{0, 2, 1, 1, 1, 2, 2, 4, 4},
	{0, 2, 2, 2, 1, 1, 3, 4, 4},
	{0, 2, 1, 1, 1, 2, 3, 4, 3},
	{0, 2, 3, 2, 1, 2, 2, 3, 5},
	{0, 1, 2, 2, 1, 1, 3, 3, 6},
	{0, 1, 2, 2, 1, 2, 2, 3, 6},
	{0, 1, 3, 2, 1, 1, 2, 3, 6},
	{0, 0, 3, 2, 1, 1, 2, 3, 2},
	{0, 1, 3, 2, 1, 1, 2, 3, 4},
	{0, 0, 2, 1, 1, 1, 1, 3, 3},
	{0, 1, 3, 2, 1, 1, 2, 3, 3},
	{0, 1, 3, 2, 1, 1, 1, 2, 5},
	{0, 1, 3, 2, 1, 1, 2, 2, 4},
	{0, 2, 2, 2, 1, 1, 1, 2, 5},
	{0, 2, 2, 1, 1, 1, 0, 1, 3},
	{0, 2, 2, 1, 1, 1, 0, 1, 2},
	{0, 1, 2, 1, 1, 0, 0, 1, 0},
	{0, 1, 2, 1, 1, 0, 0, 1, 0},
	{0, 1, 2, 1, 0, 1, 0, 1, 0},
	{0, 1, 1, 1, 0, 0, 0, 0, 4},
	{0, 1, 1, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, -1, 0, 0, 0, 0},
	{0, 0, 1, 0, -1, -1, 0, 0, 1},
	{0, 2, 0, -1, -1, -1, 0, 0, 1},
	{0, 0, 0, -1, 0, -1, -1, 0, 3},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static int rgb_offset_revA[][RGB_COMPENSATION] = {
/*	R255 G255 B255 R203 G203 B203 R151 G151 B151
	R87 G87 B87 R51 G51 B51 R35 G35 B35
	R23 G23 B23 R11 G11 B11
*/
	{-6, 0, -4, -4, 0, -3, -4, 0, -3, -14, 2, -6, -15, 5, -12, -6, 5, -10, -1, 5, -12, 0, 6, -12},
	{-4, 0, -3, -2, 0, -2, -4, 0, -3, -10, 1, -4, -16, 4, -10, -8, 4, -8, -1, 4, -12, 0, 6, -12},
	{-2, 0, -2, -3, 0, -2, -3, 0, -2, -7, 1, -3, -13, 4, -8, -10, 4, -9, -3, 4, -12, 0, 5, -12},
	{-2, 0, -2, -2, 0, -2, -3, 0, -2, -7, 1, -2, -13, 3, -8, -11, 4, -9, -4, 4, -10, 0, 6, -13},
	{-1, 0, -1, -2, 0, -2, -3, 0, -2, -7, 0, -2, -11, 2, -6, -11, 4, -9, -5, 4, -10, -1, 8, -16},
	{-1, 0, -1, -2, 0, -2, -1, 0, -1, -6, 1, -2, -10, 2, -5, -12, 4, -9, -6, 4, -12, 1, 8, -16},
	{0, 0, -1, -2, 0, -1, -2, 0, -2, -6, 0, -2, -8, 2, -5, -13, 4, -9, -6, 4, -10, -1, 9, -18},
	{0, 0, -1, -1, 0, -1, -2, 0, -1, -4, 0, -1, -9, 2, -5, -12, 3, -8, -6, 3, -10, -2, 8, -16},
	{0, 0, -1, -1, 0, -1, -2, 0, -1, -5, 0, -1, -7, 2, -5, -12, 3, -8, -6, 3, -10, -2, 10, -20},
	{0, 0, -1, -1, 0, -1, -2, 0, -1, -4, 0, 0, -7, 2, -4, -11, 3, -7, -7, 3, -12, -1, 9, -20},
	{0, 0, -1, -1, 0, -1, -2, 0, -1, -4, 0, 0, -7, 1, -4, -9, 3, -6, -8, 3, -11, -2, 8, -18},
	{0, 0, -1, -1, 0, -1, -1, 0, 0, -4, 0, -1, -6, 2, -4, -10, 3, -6, -9, 3, -11, 0, 10, -21},
	{0, 0, 0, -1, 0, -2, -1, 0, 0, -4, 0, -1, -5, 1, -4, -10, 3, -6, -8, 3, -10, -2, 9, -20},
	{0, 0, 0, -1, 0, -2, -1, 0, 0, -2, 0, 0, -6, 2, -4, -10, 2, -6, -8, 2, -11, -1, 10, -22},
	{0, 0, 0, -1, 0, -2, -1, 0, 0, -2, 0, 0, -5, 1, -3, -10, 2, -6, -9, 2, -11, 0, 9, -19},
	{0, 0, 0, 0, 0, -1, -2, 0, -2, -2, 0, 0, -5, 1, -3, -10, 2, -6, -9, 2, -11, -3, 8, -18},
	{0, 0, 0, 0, 0, -1, -2, 0, -2, -1, 0, 1, -3, 1, -2, -9, 2, -5, -9, 2, -12, -2, 8, -17},
	{0, 0, 0, 0, 0, -1, -2, 0, -2, -1, 0, 1, -3, 1, -2, -9, 2, -5, -9, 2, -12, -2, 7, -16},
	{0, 0, 0, 0, 0, -1, -1, 0, -1, -2, 0, 0, -3, 1, -2, -8, 2, -4, -7, 2, -10, -3, 10, -22},
	{0, 0, 0, 0, 0, -1, -1, 0, -1, -2, 0, 0, -3, 0, -2, -8, 2, -4, -7, 2, -10, -4, 10, -21},
	{0, 0, 0, 0, 0, -1, -1, 0, -1, -2, 0, 0, -2, 0, -1, -8, 2, -4, -7, 2, -11, -2, 11, -22},
	{0, 0, 0, 0, 0, -1, -1, 0, -2, -2, 0, 1, -2, 0, -1, -8, 1, -4, -7, 1, -11, -4, 10, -22},
	{0, 0, 0, 0, 0, 0, 0, 0, -2, -3, 0, 0, -2, 1, -2, -8, 2, -4, -5, 2, -9, -3, 12, -26},
	{0, 0, 0, 0, 0, 0, 0, 0, -2, -3, 0, 0, -2, 0, -2, -7, 2, -4, -5, 2, -8, -4, 11, -22},
	{0, 0, 0, 0, 0, 0, 0, 0, -2, -3, 0, 0, -1, 0, -2, -8, 1, -4, -5, 1, -8, -5, 10, -22},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, -1, 0, -2, -8, 1, -4, -4, 1, -10, -5, 12, -24},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, -1, 0, -2, -7, 2, -4, -3, 2, -8, -5, 10, -22},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, -2, 0, -2, -6, 1, -4, -3, 1, -8, -6, 10, -20},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, 0, 0, -1, -6, 1, -3, -2, 1, -10, -6, 10, -22},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, 0, 0, -1, -6, 1, -3, -2, 1, -10, -6, 10, -20},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, 0, 0, -1, -4, 1, -2, -1, 1, -9, -7, 12, -25},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, 0, 0, 0, -5, 1, -3, -1, 1, -9, -8, 11, -23},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, -5, 1, -3, -1, 1, -8, -9, 10, -22},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, -4, 1, -2, -2, 1, -10, -5, 8, -16},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -4, 1, -3, 0, 1, -9, -6, 10, -20},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -3, 1, -2, 0, 1, -8, -4, 9, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -3, 1, -2, 1, 1, -8, -6, 10, -22},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -2, 1, -2, 2, 1, -9, -4, 9, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -2, 1, -2, 3, 1, -9, -5, 8, -16},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, -8, -4, 8, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, -2, 0, -1, 0, 0, -8, -4, 8, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, -2, 2, 0, -7, -5, 8, -16},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -2, 0, -1, 1, 0, -7, -4, 7, -16},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, -6, -5, 8, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -6, -4, 8, -17},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -2, 0, -1, 0, 0, -6, -4, 7, -16},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -5, -1, 6, -14},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -5, -2, 6, -14},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0, 0, -4, -1, 6, -13},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, -2, 0, 0, 0, 0, -4, -2, 6, -14},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -4, -1, 6, -13},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, -2, 0, 6, -13},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -3, 0, 5, -12},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, -2, 0, 5, -11},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -2, 0, 5, -11},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 2, 0, -2, 3, 4, -9},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, -2, 4, 4, -9},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, -2, 4, 4, -9},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static int rgb_offset_revC[][RGB_COMPENSATION] = {
/*	R255 G255 B255 R203 G203 B203 R151 G151 B151
	R87 G87 B87 R51 G51 B51 R35 G35 B35
	R23 G23 B23 R11 G11 B11
*/
	{-7, 1, -5, -3, 0, -2, -5, 0, -4, -10, 3, -6, -9, 5, -12, -5, 3, -8, 0, 3, -8, 4, 5, -10},
	{-5, 0, -4, -3, 0, -2, -5, 0, -4, -8, 2, -4, -10, 5, -11, -7, 4, -9, 0, 4, -8, 4, 5, -10},
	{-4, 0, -3, -2, 0, -2, -4, 0, -3, -8, 1, -4, -10, 4, -9, -10, 4, -10, -2, 4, -10, 2, 6, -12},
	{-3, 0, -3, -2, 0, -1, -3, 0, -2, -7, 1, -4, -11, 4, -8, -8, 4, -9, -3, 4, -12, 0, 6, -13},
	{-3, 0, -3, -1, 0, 0, -3, 0, -3, -6, 1, -3, -10, 3, -8, -8, 4, -8, -4, 4, -12, 1, 7, -14},
	{-2, 0, -2, -2, 0, -1, -2, 0, -2, -6, 1, -2, -8, 3, -6, -9, 4, -9, -5, 4, -9, 0, 8, -16},
	{-2, 0, -2, -2, 0, -1, -1, 0, -1, -5, 1, -2, -8, 3, -6, -9, 3, -8, -6, 3, -12, 0, 6, -14},
	{-2, 0, -2, -1, 0, 0, -2, 0, -2, -6, 0, -2, -6, 2, -6, -10, 4, -9, -6, 4, -11, 1, 7, -16},
	{-2, 0, -2, -1, 0, 0, -1, 0, -1, -5, 0, -2, -8, 2, -6, -9, 3, -8, -7, 3, -10, -1, 9, -18},
	{0, 0, -1, -3, 0, -1, -1, 0, -1, -4, 1, -2, -6, 2, -5, -10, 3, -8, -6, 3, -10, 0, 7, -16},
	{0, 0, -1, -3, 0, -1, -1, 0, -1, -3, 0, -1, -6, 2, -5, -10, 3, -8, -7, 3, -11, 0, 7, -16},
	{0, 0, -1, -3, 0, -1, -1, 0, -1, -3, 0, -1, -5, 2, -4, -10, 3, -8, -6, 3, -8, -2, 9, -18},
	{0, 0, -1, -3, 0, -1, -1, 0, -1, -2, 0, 0, -5, 2, -5, -8, 3, -6, -8, 3, -12, -1, 10, -20},
	{0, 0, 0, -2, 0, -1, -1, 0, -1, -3, 0, 0, -5, 2, -4, -8, 3, -6, -8, 3, -11, -1, 8, -16},
	{0, 0, 0, -2, 0, -1, -1, 0, -1, -3, 0, 0, -6, 2, -5, -8, 2, -6, -8, 2, -10, -3, 7, -16},
	{0, 0, 0, 0, 0, -1, -3, 0, -1, -3, 0, 0, -5, 2, -4, -8, 2, -6, -7, 2, -10, -2, 9, -18},
	{0, 0, 0, 0, 0, -1, -3, 0, -1, -2, 0, 0, -5, 2, -4, -7, 2, -5, -8, 2, -11, 0, 9, -20},
	{0, 0, 0, 0, 0, -1, -3, 0, -1, -2, 0, 0, -5, 1, -4, -7, 2, -5, -8, 2, -10, -1, 9, -18},
	{0, 0, 0, 0, 0, -1, -3, 0, -1, -2, 0, 0, -5, 1, -4, -8, 2, -6, -7, 2, -9, -2, 9, -18},
	{0, 0, 0, 0, 0, -1, -2, 0, -1, -2, 0, 0, -4, 1, -4, -8, 2, -5, -7, 2, -10, -1, 10, -22},
	{0, 0, 0, 0, 0, -1, -2, 0, -1, -2, 0, 0, -3, 1, -3, -7, 2, -4, -5, 2, -8, -3, 8, -18},
	{0, 0, 0, 0, 0, -1, -2, 0, -1, -2, 0, 0, -3, 1, -3, -7, 2, -5, -6, 2, -11, -2, 10, -22},
	{0, 0, 0, 0, 0, -1, -2, 0, -1, -2, 0, 0, -2, 1, -2, -6, 2, -4, -6, 2, -10, -2, 8, -18},
	{0, 0, 0, 0, 0, 0, -2, 0, -2, -2, 0, 0, -2, 1, -3, -6, 1, -4, -5, 1, -9, -2, 11, -24},
	{0, 0, 0, 0, 0, 0, -2, 0, -2, -1, 0, 1, -2, 1, -2, -5, 1, -4, -5, 1, -10, -4, 9, -20},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -3, 0, 0, -2, 0, -2, -5, 1, -4, -5, 1, -10, -5, 8, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -3, 0, 0, -1, 0, -2, -6, 1, -4, -5, 1, -9, -2, 11, -22},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -3, 0, 0, -1, 1, -2, -5, 1, -4, -4, 1, -10, -3, 8, -17},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -3, 0, 0, -1, 0, -2, -5, 2, -4, -3, 2, -9, -3, 10, -22},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -3, 0, 0, -1, 0, -2, -5, 1, -4, -3, 1, -9, -3, 10, -20},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -3, 0, 0, -1, 0, -2, -4, 1, -3, -2, 1, -8, -4, 12, -24},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -3, 0, 0, -1, 0, -1, -5, 1, -3, -2, 1, -8, -3, 10, -20},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -3, 0, 0, -1, 0, -1, -4, 1, -2, -2, 1, -8, -3, 9, -19},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -3, 0, 0, -1, 0, -1, -4, 0, -2, -2, 0, -8, -3, 11, -23},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, -1, -4, 1, -2, -1, 1, -7, -2, 10, -20},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, -1, -4, 1, -2, 0, 1, -9, -2, 11, -22},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, -1, -4, 0, -2, 1, 0, -8, -2, 10, -21},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, 0, -2, 1, -2, 0, 1, -8, -2, 9, -19},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, -1, -3, 0, -2, 0, 0, -8, -2, 8, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, -1, -3, 0, -2, 1, 0, -8, -2, 9, -20},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0, 0, 0, -4, 0, -2, 1, 0, -8, -1, 9, -20},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, 0, -1, 0, 0, 2, 0, -7, -2, 8, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, -2, 0, -1, 1, 0, -7, -1, 9, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0, 0, 0, -2, 0, -1, 2, 0, -6, 0, 9, -18},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 1, -1, 0, 0, 1, 0, -6, -2, 7, -16},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -2, 0, 0, 2, 0, -5, 0, 8, -17},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, -5, 0, 7, -16},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -5, 0, 7, -15},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, -4, 0, 7, -14},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, -3, 0, 7, -15},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -3, 0, 7, -15},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0, 0, -2, 0, 7, -14},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, -1, 0, 0, -1, 0, -3, 2, 6, -12},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0, 0, -2, 0, 5, -12},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, -1, 0, 1, 0, 0, -2, 2, 5, -11},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, -2, 0, 5, -12},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, -2, 2, 5, -10},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 1, 0, -2, 2, 4, -10},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static int rgb_offset_revF[][RGB_COMPENSATION] = {
	/*	R255 G255 B255 R203 G203 B203 R151 G151 B151
		R87 G87 B87 R51 G51 B51 R35 G35 B35
		R23 G23 B23 R11 G11 B11
	*/
		{-5, 1, -4, -3, 0, -1, -5, 0, -3, -13, 1, -4, -17, 4, -8, -10, 3, -6, -6, 3, -8, 5, 1, -4},
		{-4, 0, -4, -2, 0, -1, -4, 0, -2, -11, 1, -4, -18, 3, -7, -13, 3, -7, -6, 3, -8, 5, 1, -4},
		{-3, 0, -3, -2, 0, -2, -3, 0, -2, -10, 1, -4, -17, 1, -4, -13, 3, -7, -9, 3, -9, 2, 2, -5},
		{-2, 0, -2, -1, 0, -2, -4, 0, -2, -7, 1, -3, -14, 1, -2, -17, 3, -7, -8, 3, -8, 1, 5, -10},
		{-1, 0, -2, -1, 0, -1, -4, 0, -2, -6, 1, -4, -14, 1, -3, -15, 2, -6, -9, 2, -10, 3, 4, -9},
		{0, 0, -1, -2, 0, -2, -3, 0, -1, -5, 1, -3, -11, 1, -3, -14, 2, -6, -9, 2, -10, 0, 5, -10},
		{0, 0, -1, -1, 0, -1, -3, 0, -2, -5, 1, -3, -11, 1, -4, -14, 2, -6, -9, 2, -9, 0, 7, -15},
		{0, 0, -1, -1, 0, -1, -2, 0, -1, -6, 1, -4, -9, 1, -4, -12, 3, -6, -8, 3, -8, 0, 8, -16},
		{0, 0, 0, -1, 0, -2, -2, 0, -1, -4, 1, -3, -9, 1, -4, -11, 2, -6, -9, 2, -10, 1, 8, -16},
		{0, 0, -1, -1, 0, 0, -3, 0, -2, -4, 1, -3, -9, 1, -4, -11, 2, -6, -8, 2, -10, 0, 9, -18},
		{0, 0, -1, -1, 0, 0, -2, 0, -1, -4, 1, -3, -7, 1, -4, -10, 2, -6, -8, 2, -10, -1, 7, -16},
		{0, 0, -1, -1, 0, 0, -2, 0, -1, -3, 1, -2, -7, 1, -4, -9, 2, -6, -7, 2, -8, -1, 9, -18},
		{0, 0, -1, -1, 0, 0, -2, 0, -1, -2, 1, -2, -7, 1, -4, -8, 2, -5, -6, 2, -10, -1, 7, -16},
		{0, 0, -1, -1, 0, 0, -2, 0, -1, -1, 1, -2, -7, 1, -4, -7, 1, -4, -7, 1, -10, -1, 9, -20},
		{0, 0, -1, 0, 0, 0, -2, 0, 0, -2, 1, -2, -7, 1, -3, -7, 2, -4, -7, 2, -8, 1, 11, -22},
		{0, 0, -1, 0, 0, 0, -1, 0, 0, -2, 1, -2, -8, 1, -4, -7, 1, -4, -8, 1, -9, 0, 10, -20},
		{0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 1, -2, -6, 1, -3, -7, 2, -4, -9, 2, -10, 1, 10, -21},
		{0, 0, 0, 0, 0, -1, -2, 0, 0, -2, 0, -2, -7, 1, -4, -7, 1, -4, -9, 1, -9, 0, 10, -21},
		{0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 0, -2, -6, 1, -2, -7, 1, -4, -8, 1, -8, -1, 8, -18},
		{0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 0, -2, -5, 1, -2, -6, 2, -4, -8, 2, -8, 0, 11, -22},
		{0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 0, -2, -5, 1, -2, -6, 1, -4, -7, 1, -6, -2, 9, -20},
		{0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 0, -2, -4, 1, -2, -6, 1, -3, -7, 1, -6, -1, 13, -26},
		{0, 0, 0, 0, 0, -1, -1, 0, 0, -1, 0, -1, -4, 1, -2, -6, 1, -4, -8, 1, -8, -2, 10, -22},
		{0, 0, 0, 0, 0, -1, -1, 0, 0, -1, 0, -1, -4, 1, -2, -5, 1, -2, -7, 1, -7, -1, 12, -24},
		{0, 0, 0, 0, 0, -1, -1, 0, 0, -1, 0, -1, -4, 0, -2, -6, 1, -3, -6, 1, -6, -2, 11, -24},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -2, -4, 0, -2, -5, 1, -3, -6, 1, -7, -1, 12, -26},
		{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, -1, -4, 0, -2, -3, 1, -2, -6, 1, -6, -1, 11, -22},
		{0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, -4, 0, -2, -4, 0, -2, -6, 0, -8, -1, 12, -26},
		{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -4, 0, -2, -4, 1, -2, -5, 1, -8, -2, 11, -24},
		{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -3, 0, -1, -4, 1, -2, -3, 1, -7, -3, 10, -22},
		{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -3, 0, -1, -3, 0, -2, -4, 0, -7, -3, 12, -26},
		{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 0, -1, -4, 1, -2, -3, 1, -8, -3, 10, -21},
		{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 0, -1, -4, 0, -2, -3, 0, -8, -4, 9, -20},
		{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 0, -1, -2, 0, -1, -4, 0, -8, -3, 11, -24},
		{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 0, -1, -2, 0, -1, -2, 0, -7, -5, 10, -22},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, -1, -2, 0, -1, -3, 0, -8, -3, 12, -24},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, -2, 0, -1, -1, 0, -8, -4, 11, -22},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, -1, 0, -1, -1, 0, -7, -4, 10, -20},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -1, 0, -1, -1, 0, -7, -4, 11, -23},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, -8, -5, 9, -20},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, 0, 0, 0, -6, -4, 10, -20},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, -1, 0, 0, -6, -4, 9, -18},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -6, -4, 9, -19},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -5, -5, 9, -20},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -4, -5, 9, -20},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, 0, -1, 0, -5, -5, 8, -18},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, -4, -2, 7, -14},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, -5, -4, 7, -15},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 1, 0, 0, -4, -3, 6, -14},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -3, -3, 7, -14},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, -3, -4, 6, -14},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, -1, 0, 0, 0, 0, -2, -4, 7, -14},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0, 0, 1, 0, 0, -1, -3, 6, -14},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, -2, -1, 6, -12},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, -2, -2, 6, -12},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -2, -1, 5, -10},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -2, -1, 4, -10},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 2, 0, -1, -1, 4, -10},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static int rgb_offset_revH[][RGB_COMPENSATION] = {
/*	R255 G255 B255 R203 G203 B203 R151 G151 B151
	R87 G87 B87 R51 G51 B51 R35 G35 B35
	R23 G23 B23 R11 G11 B11
*/
	{-3, 4, 0, -1, 1, 0, -5, 0, -3, -14, -1, -6, -22, 0, -14, -7, -1, -5, 2, 2, -8, 21, -2, 1},
	{-3, 3, -1, -2, -1, -1, -4, 1, -1, -10, 1, -4, -26, -1, -15, -4, -1, -3, -3, 1, -8, 21, -2, 1},
	{0, 4, 1, -2, -1, -1, -3, 1, -1, -9, 1, -5, -18, -1, -8, -10, 4, -4, -7, 2, -10, 10, -2, -6},
	{0, 3, 1, -1, 1, 0, -3, 1, -1, -7, 1, -4, -13, 1, -3, -12, 1, -6, -8, 2, -8, 10, 0, -6},
	{-2, 1, -2, -1, -1, -1, -3, 1, -1, -6, 1, -4, -11, 2, -2, -12, 2, -6, -7, 2, -8, 10, 2, -7},
	{-1, 1, -1, 0, 0, 0, -3, 1, -1, -6, 1, -4, -9, 2, -3, -11, 2, -6, -6, 2, -8, 4, 4, -9},
	{0, 0, -1, -2, 1, 0, -2, 1, 0, -5, 2, -3, -7, 2, -3, -12, 2, -7, -7, 1, -9, 4, 5, -11},
	{0, 0, -1, -1, 1, 0, -2, 1, 0, -5, 2, -2, -7, 3, -4, -10, 1, -7, -7, 4, -9, 0, 1, -14},
	{0, 0, -1, 0, 1, 1, -2, 1, 0, -5, 2, -2, -7, 3, -4, -9, 1, -7, -7, 3, -9, 0, 2, -14},
	{0, 0, -1, 0, 1, 1, -2, 1, 0, -3, 2, -2, -7, 2, -4, -9, 1, -7, -7, 2, -9, 1, 5, -14},
	{0, 0, -1, 0, 1, 1, -1, 1, 0, -3, 2, -2, -7, 2, -4, -7, 1, -6, -6, 3, -9, 2, 5, -13},
	{0, 0, -1, -1, 0, 0, -1, 1, 0, -2, 2, -2, -7, 2, -4, -7, 1, -6, -7, 2, -11, 1, 6, -14},
	{0, 0, 0, 0, 0, 0, -1, 1, 0, -2, 2, -2, -7, 1, -4, -5, 1, -4, -6, 5, -11, 5, 8, -13},
	{0, 0, 0, 0, 0, 0, -1, 1, 0, -2, 2, -2, -6, 1, -4, -5, 1, -4, -6, 5, -11, 0, 3, -14},
	{0, 0, 0, 0, 0, 0, -1, 1, 0, -2, 2, -2, -6, 1, -4, -5, 1, -4, -8, 2, -11, 6, 10, -13},
	{0, 0, 0, 0, 0, 0, -1, 0, -1, -2, 2, -2, -6, 1, -3, -5, 1, -4, -7, 3, -11, 3, 6, -13},
	{0, 0, 0, 0, 0, 0, -1, 0, -1, -2, 2, -2, -6, 1, -3, -5, 1, -5, -7, 3, -11, 8, 9, -13},
	{0, 0, 0, 0, 0, 0, -1, 0, -1, -2, 2, -1, -6, 1, -3, -6, 0, -6, -7, 4, -10, 6, 5, -16},
	{0, 0, 0, 0, 0, 0, -1, 0, -2, -2, 2, 0, -5, 1, -3, -5, 1, -5, -7, 3, -8, 1, 3, -17},
	{0, 0, 0, 0, 0, 0, -1, 0, -2, -2, 2, 0, -5, 1, -2, -5, 2, -5, -5, 3, -8, 5, 7, -15},
	{0, 0, 0, 0, 0, 0, -1, 0, -1, -2, 2, 0, -3, 1, -2, -5, 2, -4, -3, 5, -10, 6, 8, -15},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 2, 0, -3, 1, -2, -5, 2, -4, -5, 4, -10, 5, 7, -15},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 2, 0, -3, 1, -2, -5, 1, -4, -5, 2, -10, 11, 12, -15},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 2, 0, -3, 0, -2, -5, 1, -5, -5, 2, -9, 8, 10, -16},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 1, 0, -3, 2, -1, -2, 1, -4, -7, -1, -9, 7, 9, -16},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 1, 0, -3, 2, 0, -3, 0, -5, -2, 2, -9, 11, 12, -14},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 1, 0, -2, 2, 1, -3, 0, -5, -4, 1, -9, 7, 8, -16},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 1, 0, -2, 2, 1, -3, 0, -5, 1, 5, -7, 7, 9, -16},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 1, 0, -2, 2, 1, -3, 0, -5, 0, 2, -8, 8, 9, -15},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 2, 1, -3, 0, -5, -1, 2, -9, 15, 16, -12},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 2, 1, -5, -2, -7, 0, 2, -8, 13, 14, -12},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 2, 1, -4, -2, -7, 1, 0, -9, 10, 12, -14},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 0, 1, -2, 1, -5, 3, 3, -8, 12, 14, -12},
	{0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -2, 0, 0, -2, 1, -4, 3, 2, -8, 10, 12, -13},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -2, 0, 0, -2, 1, -4, 3, 1, -8, 19, 18, -11},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -2, 0, 0, -1, 0, -4, 2, 0, -9, 14, 15, -13},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -2, 0, 0, 0, 2, -2, 7, 3, -8, 7, 8, -11},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -2, 0, 0, 0, 1, -2, 7, 3, -8, 13, 12, -11},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -2, 0, 0, 0, 1, -2, 6, 1, -9, 11, 11, -13},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -2, 0, 0, 1, 2, -1, 11, 4, -8, 5, 3, -12},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, 1, 2, -1, 6, -1, -10, 6, 6, -15},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 1, 2, -1, 6, 0, -10, 5, 5, -12},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 1, 2, -1, 3, -4, -12, 4, 3, -10},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1, 1, -1, 4, -2, -10, 13, 10, -7},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, -1, -3, -10, 17, 14, -3},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, -3, -9, 16, 12, -4},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 4, 0, -6, 15, 11, -4},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 1, 0, 0, -1, -1, -4, -9, 11, 8, -4},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 1, 1, 0, 0, -1, 0, -3, -7, 10, 6, -5},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 2, -1, -5, 10, 4, -5},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0, 0, 0, -3, -4, -7, 15, 10, -1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -5, 15, 9, -1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5, 15, 9, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -4, 13, 9, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, -5, 13, 8, -1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, -1, 11, 1, -2},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 3, -1, 8, -3, -5},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 3, -1, 7, -4, -5},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

#endif
