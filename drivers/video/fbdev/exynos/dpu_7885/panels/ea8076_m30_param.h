#ifndef __EA8076_M30_PARAM_H__
#define __EA8076_M30_PARAM_H__

#include <linux/types.h>
#include <linux/kernel.h>

#define EXTEND_BRIGHTNESS	365
#define UI_MAX_BRIGHTNESS	255
#define UI_DEFAULT_BRIGHTNESS	128

#define ACL_CMD_CNT				((u16)ARRAY_SIZE(SEQ_ACL_OFF))
#define HBM_CMD_CNT				((u16)ARRAY_SIZE(SEQ_HBM_OFF))
#define ELVSS_CMD_CNT				((u16)ARRAY_SIZE(SEQ_ELVSS_SET))

#define LDI_REG_BRIGHTNESS			0x51
#define LDI_REG_ID				0x04
#define LDI_REG_COORDINATE			0xEA
#define LDI_REG_DATE				LDI_REG_COORDINATE
#define LDI_REG_MANUFACTURE_INFO		LDI_REG_COORDINATE
#define LDI_REG_MANUFACTURE_INFO_CELL_ID	0xEF

/* len is read length */
#define LDI_LEN_ID				3
#define LDI_LEN_COORDINATE			4
#define LDI_LEN_DATE				7
#define LDI_LEN_MANUFACTURE_INFO		4
#define LDI_LEN_MANUFACTURE_INFO_CELL_ID	16

/* offset is position including addr, not only para */
#define LDI_OFFSET_ACL		1
#define LDI_OFFSET_HBM		1
#define LDI_OFFSET_ELVSS	6

#define LDI_GPARA_COORDINATE			3	/* EAh 4th Para: x, y */
#define LDI_GPARA_DATE				7	/* EAh 8th Para: [D7:D4]: Year */
#define LDI_GPARA_MANUFACTURE_INFO		15	/* EAh 16th Para: [D7:D4]:Site */
#define LDI_GPARA_MANUFACTURE_INFO_CELL_ID	2	/* EFh 3rd Para ~ 18th Para */

#define	LDI_REG_RDDPM		0x0A	/* Read Display Power Mode */
#define	LDI_LEN_RDDPM		1

#define	LDI_REG_RDDSM		0x0E	/* Read Display Signal Mode */
#define	LDI_LEN_RDDSM		1

#ifdef CONFIG_DISPLAY_USE_INFO
#define	LDI_REG_RDNUMPE		0x05		/* DPUI_KEY_PNDSIE: Read Number of the Errors on DSI */
#define	LDI_LEN_RDNUMPE		1
#define LDI_PNDSIE_MASK		(GENMASK(6, 0))

/*
 * ESD_ERROR[0] =  MIPI DSI error is occurred by ESD.
 * ESD_ERROR[1] =  HS CLK lane error is occurred by ESD.
 * ESD_ERROR[2] =  VLIN3 error is occurred by ESD.
 * ESD_ERROR[3] =  ELVDD error is occurred by ESD.
 * ESD_ERROR[4]  = CHECK_SUM error is occurred by ESD.
 * ESD_ERROR[5] =  Internal HSYNC error is occurred by ESD.
 * ESD_ERROR[6] =  VLIN1 error is occurred by ESD
 */
#define LDI_REG_ESDERR		0xEE		/* DPUI_KEY_PNELVDE, DPUI_KEY_PNVLI1E, DPUI_KEY_PNVLO3E, DPUI_KEY_PNESDE */
#define LDI_LEN_ESDERR		1
#define LDI_PNELVDE_MASK	(BIT(3))	/* ELVDD error */
#define LDI_PNVLI1E_MASK	(BIT(6))	/* VLIN1 error */
#define LDI_PNVLO3E_MASK	(BIT(2))	/* VLIN3 error */
#define LDI_PNESDE_MASK		(BIT(2) | BIT(3) | BIT(6))

#define LDI_REG_RDDSDR		0x0F		/* DPUI_KEY_PNSDRE: Read Display Self-Diagnostic Result */
#define LDI_LEN_RDDSDR		1
#define LDI_PNSDRE_MASK		(BIT(7))	/* D7: REG_DET: Register Loading Detection */
#endif

struct lcd_seq_info {
	unsigned char	*cmd;
	unsigned int	len;
	unsigned int	sleep;
};

static unsigned char SEQ_SLEEP_OUT[] = {
	0x11
};

static unsigned char SEQ_SLEEP_IN[] = {
	0x10
};

static unsigned char SEQ_DISPLAY_ON[] = {
	0x29
};

static unsigned char SEQ_DISPLAY_OFF[] = {
	0x28
};

static unsigned char SEQ_TEST_KEY_ON_F0[] = {
	0xF0,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_F0[] = {
	0xF0,
	0xA5, 0xA5
};

static unsigned char SEQ_TEST_KEY_ON_FC[] = {
	0xFC,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_FC[] = {
	0xFC,
	0xA5, 0xA5
};

static unsigned char SEQ_TE_ON[] = {
	0x35,
	0x00, 0x00
};

static unsigned char SEQ_PAGE_ADDR_SET[] = {
	0x2B,
	0x00, 0x00, 0x09, 0x23
};

static unsigned char SEQ_FFC_SET[] = {
	0xE9,
	0x11, 0x55, 0xA6, 0x75, 0xA3, 0xB2, 0x41, 0xC3, 0x00, 0x1A,
	0xB8		/* MIPI Speed 1.1Gbps */
};

static unsigned char SEQ_ERR_FG_SET[] = {
	0xE1,
	0x00, 0x00, 0x02, 0x00, 0x10, 0x10, 0x00, 0x00, 0x20, 0x00,
	0x00, 0x01, 0x19
};

static unsigned char SEQ_ELVSS_SET[] = {
	0xB7,
	0x01, 0x53, 0x28, 0x4D, 0x00, 0x90,	/* ELVSS Return */
};

static unsigned char SEQ_HBM_ON[] = {
	0x53,
	0xE8,
};

static unsigned char SEQ_HBM_OFF[] = {
	0x53,
	0x28,
};

static unsigned char SEQ_ACL_SETTING_1[] = {
	0xB0,
	0xD7
};

static unsigned char SEQ_ACL_SETTING_2[] = {
	0xB9,
	0x02, 0xA1, 0x8C, 0x4B
};

static unsigned char SEQ_ACL_OFF[] = {
	0x55,
	0x00
};

static unsigned char SEQ_ACL_08P[] = {
	0x55,
	0x01
};

static unsigned char SEQ_ACL_15P[] = {
	0x55,
	0x03
};

#if defined(CONFIG_EXYNOS_SUPPORT_DOZE)
enum {
	ALPM_OFF,
	ALPM_ON_LOW,	/* ALPM 2 NIT */
	HLPM_ON_LOW,	/* HLPM 2 NIT */
	ALPM_ON_HIGH,	/* ALPM 60 NIT */
	HLPM_ON_HIGH,	/* HLPM 60 NIT */
	ALPM_MODE_MAX
};

static unsigned char SEQ_HLPM_ON_02[] = {
	0x53,
	0x23		/* 0x23 : HLPM 2nit On */
};

static unsigned char SEQ_HLPM_ON_60[] = {
	0x53,
	0x22		/* 0x22 : HLPM 60nit On */
};

static unsigned char SEQ_HLPM_OFF[] = {
	0x53,
	0x28
};
#endif

#if defined(CONFIG_SEC_FACTORY)
static unsigned char SEQ_XTALK_B0[] = {
	0xB0,
	0x1C
};

static unsigned char SEQ_XTALK_ON[] = {
	0xD9,
	0x60
};

static unsigned char SEQ_XTALK_OFF[] = {
	0xD9,
	0xC0
};
#endif

enum {
	ACL_STATUS_OFF,
	ACL_STATUS_08P,
	ACL_STATUS_15P,
	ACL_STATUS_MAX,
};

enum {
	TEMP_ABOVE_MINUS_00_DEGREE,	/* T > 0 */
	TEMP_ABOVE_MINUS_15_DEGREE,	/* -15 < T <= 0 */
	TEMP_BELOW_MINUS_15_DEGREE,	/* T <= -15 */
	TEMP_MAX
};

enum {
	HBM_STATUS_OFF,
	HBM_STATUS_ON,
	HBM_STATUS_MAX
};

static unsigned char *HBM_TABLE[HBM_STATUS_MAX] = {SEQ_HBM_OFF, SEQ_HBM_ON};
static unsigned char *ACL_TABLE[ACL_STATUS_MAX] = {SEQ_ACL_OFF, SEQ_ACL_08P, SEQ_ACL_15P};

/* platform brightness <-> acl opr and percent */
static unsigned int brightness_opr_table[ACL_STATUS_MAX][EXTEND_BRIGHTNESS + 1] = {
	{
		[0 ... UI_MAX_BRIGHTNESS - 1]			= ACL_STATUS_15P,
		[UI_MAX_BRIGHTNESS ... EXTEND_BRIGHTNESS]	= ACL_STATUS_OFF,
	}, {
		[0 ... UI_MAX_BRIGHTNESS]					= ACL_STATUS_15P,
		[UI_MAX_BRIGHTNESS + 1 ... EXTEND_BRIGHTNESS]			= ACL_STATUS_08P
	}
};

/* platform brightness <-> gamma level */
static unsigned int brightness_table[EXTEND_BRIGHTNESS + 1] = {
	3,
	6, 9, 12, 15, 18, 21, 24, 27, 30, 33,
	36, 39, 42, 45, 49, 53, 57, 60, 64, 67,
	71, 75, 78, 82, 85, 89, 93, 96, 100, 103,
	107, 111, 114, 118, 121, 125, 129, 132, 136, 140,
	143, 147, 150, 154, 158, 161, 165, 168, 172, 176,
	179, 183, 186, 190, 194, 197, 201, 205, 208, 212,
	215, 219, 223, 226, 230, 233, 237, 241, 244, 248,
	251, 255, 259, 262, 266, 270, 273, 277, 280, 284,
	288, 291, 295, 298, 302, 306, 309, 313, 316, 320,
	324, 327, 331, 335, 338, 342, 345, 349, 353, 356,
	360, 363, 367, 371, 374, 378, 381, 385, 389, 392,
	396, 400, 403, 407, 410, 414, 418, 421, 425, 428,
	432, 436, 439, 443, 446, 450, 454, 456, 462, 467,	/* 128: 446 */
	471, 476, 480, 484, 489, 493, 498, 502, 507, 511,
	516, 520, 525, 529, 534, 538, 543, 547, 551, 556,
	560, 565, 569, 574, 578, 583, 587, 592, 596, 601,
	605, 610, 614, 618, 623, 627, 632, 636, 641, 645,
	650, 654, 659, 663, 668, 672, 676, 681, 685, 690,
	694, 699, 703, 708, 712, 717, 721, 726, 730, 735,
	739, 743, 748, 752, 757, 761, 766, 770, 775, 779,
	784, 788, 793, 797, 801, 806, 810, 815, 819, 824,
	828, 833, 837, 842, 846, 851, 855, 860, 864, 868,
	873, 877, 882, 886, 891, 895, 900, 904, 909, 913,
	918, 922, 926, 931, 935, 940, 944, 949, 953, 958,
	962, 967, 971, 976, 980, 985, 989, 993, 998, 1002,
	1007, 1011, 1016, 1020, 1023, 5, 9, 12, 16, 20,	/* 255: 1023 */
	23, 27, 31, 34, 38, 42, 45, 49, 53, 55,
	60, 64, 67, 71, 75, 78, 82, 86, 89, 93,
	97, 100, 104, 108, 111, 115, 119, 123, 126, 130,
	134, 137, 141, 145, 148, 152, 156, 159, 163, 167,
	170, 174, 178, 181, 185, 189, 192, 196, 200, 203,
	207, 211, 214, 218, 222, 225, 229, 233, 236, 240,
	244, 247, 251, 255, 258, 262, 266, 269, 273, 277,
	280, 284, 288, 291, 295, 299, 302, 306, 310, 313,
	317, 321, 325, 328, 332, 336, 339, 343, 347, 350,
	354, 358, 361, 365, 369, 372, 376, 380, 383, 387,
	391, 394, 398, 402, 404,
};

static unsigned int elvss_table[EXTEND_BRIGHTNESS + 1] = {
	[0 ... 255] = 0x90,
	0x99, 0x99, 0x99, 0x99, 0x99,
	0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
	0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
	0x99, 0x97, 0x97, 0x97, 0x97, 0x97, 0x97, 0x97, 0x97, 0x97,
	0x97, 0x97, 0x97, 0x97, 0x97, 0x96, 0x96, 0x96, 0x96, 0x96,
	0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x95, 0x95,
	0x95, 0x95, 0x95, 0x95, 0x95, 0x95, 0x95, 0x95, 0x95, 0x95,
	0x95, 0x95, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93,
	0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x92, 0x92, 0x92, 0x92,
	0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x91,
	0x91, 0x91, 0x91, 0x91, 0x91, 0x91, 0x91, 0x91, 0x91, 0x91,
	0x91, 0x91, 0x91, 0x91, 0x90,
};
#endif /* __EA8076_M30_PARAM_H__ */
