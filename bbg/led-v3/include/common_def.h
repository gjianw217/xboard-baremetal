#ifndef __COMMON_DEF_H__
#define __COMMON_DEF_H__

/* AM335X type */
#define BONE_BOARD	0
#define GP_BOARD	1
#define IA_BOARD	2
#define IPP_BOARD	3
#define BASE_BOARD	4

/* Profiles */
#define PROFILE_NONE	0x0
#define PROFILE_0	(1 << 0)
#define PROFILE_1	(1 << 1)
#define PROFILE_2	(1 << 2)
#define PROFILE_3	(1 << 3)
#define PROFILE_4	(1 << 4)
#define PROFILE_5	(1 << 5)
#define PROFILE_6	(1 << 6)
#define PROFILE_7	(1 << 7)
#define PROFILE_ALL	0xFF

extern void pll_init(void);
extern void mpu_pll_config(int mpupll_M);
extern void enable_ddr_clocks(void);

extern void enable_i2c0_pin_mux(void);
extern void enable_uart0_pin_mux(void);
extern void configure_evm_pin_mux(unsigned char daughter_board_id,
					char daughter_board_version[],
					unsigned short daughter_board_profile,
					unsigned int daughter_board_flag);

