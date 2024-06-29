/*
 * evm.c
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

//#define DEBUG

#include "ddr_def.h"
#include "common_def.h"
#include "AM335X_SOC.h"
#include "AM335X_DataType.h"
#include "hardware.h"

#define __raw_readl(a)		(*(volatile unsigned int *)(a))
#define __raw_writel(v, a)	(*(volatile unsigned int *)(a) = (v))
#define __raw_readw(a)		(*(volatile unsigned short *)(a))
#define __raw_writew(v, a)	(*(volatile unsigned short *)(a) = (v))
#define __raw_readc(a)		(*(volatile char *)(a))
#define __raw_writec(v, a)	(*(volatile char *)(a) = (v))


/* UART Defines */
#define UART_SYSCFG_OFFSET	(0x54)
#define UART_SYSSTS_OFFSET	(0x58)

#define UART_RESET		(0x1 << 1)
#define UART_CLK_RUNNING_MASK	0x1
#define UART_SMART_IDLE_EN	(0x1 << 0x3)

/* Timer Defines */
#define TSICR_REG		0x54
#define TIOCP_CFG_REG		0x10
#define TCLR_REG		0x38

/* CPLD registers */
#define CFG_REG			0x10

/*
 * I2C Address of various board
 */
#define I2C_BASE_BOARD_ADDR	0x50
#define I2C_DAUGHTER_BOARD_ADDR 0x51
#define I2C_LCD_BOARD_ADDR	0x52

#define I2C_CPLD_ADDR		0x35

/* RGMII mode define */
#define RGMII_MODE_ENABLE	0xA
#define RMII_MODE_ENABLE	0x5
#define MII_MODE_ENABLE		0x0

#define NO_OF_MAC_ADDR          3
#define ETH_ALEN		6

struct am335x_baseboard_id {
	unsigned int  magic;
	char name[8];
	char version[4];
	char serial[12];
	char config[32];
	char mac_addr[NO_OF_MAC_ADDR][ETH_ALEN];
};

static struct am335x_baseboard_id header;
extern void cpsw_eth_set_mac_addr(const u_int8_t *addr);
static unsigned char daughter_board_connected;
static volatile int board_id = BASE_BOARD;

static void init_timer(void)
{
	/* Reset the Timer */
	__raw_writel(0x2, (DMTIMER2_BASE + TSICR_REG));

	/* Wait until the reset is done */
	while (__raw_readl(DMTIMER2_BASE + TIOCP_CFG_REG) & 1);

	/* Start the Timer */
	__raw_writel(0x1, (DMTIMER2_BASE + TCLR_REG));
}
#endif



/* 
 * Added by MYIR, turn off lcd backlight by setting GPIO0_2 output LOW.
 */
extern void enable_backlight_pin_mux(void);
extern void enable_wdt_pin_mux(void);
static void myir_init_backlight()
{
#define SOC_PRCM_REGS                        (0x44E00000)
#define SOC_CM_WKUP_REGS                     (SOC_PRCM_REGS + 0x400)
#define CM_WKUP_GPIO0_CLKCTRL   (0x8)
#define CM_WKUP_GPIO0_CLKCTRL_MODULEMODE_ENABLE   (0x2u)
#define CM_WKUP_GPIO0_CLKCTRL_MODULEMODE   (0x00000003u)
#define CM_WKUP_GPIO0_CLKCTRL_OPTFCLKEN_GPIO0_GDBCLK   (0x00040000u)
#define CM_WKUP_CONTROL_CLKCTRL_IDLEST_FUNC   (0x0u)
#define CM_WKUP_CONTROL_CLKCTRL_IDLEST_SHIFT   (0x00000010u)
#define CM_WKUP_CONTROL_CLKCTRL   (0x4)
#define CM_WKUP_CONTROL_CLKCTRL_IDLEST   (0x00030000u)
#define CM_WKUP_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_L3_AON_GCLK   (0x00000008u)
#define CM_WKUP_CM_L3_AON_CLKSTCTRL   (0x18)
#define CM_WKUP_L4WKUP_CLKCTRL_IDLEST_FUNC   (0x0u)
#define CM_WKUP_L4WKUP_CLKCTRL_IDLEST_SHIFT   (0x00000010u)
#define CM_WKUP_L4WKUP_CLKCTRL   (0xc)
#define CM_WKUP_L4WKUP_CLKCTRL_IDLEST   (0x00030000u)
#define CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK   (0x00000004u)
#define CM_WKUP_CLKSTCTRL   (0x0)
#define CM_WKUP_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_L4_WKUP_AON_GCLK   (0x00000004u)
#define CM_WKUP_CM_L4_WKUP_AON_CLKSTCTRL   (0xcc)
#define CM_WKUP_GPIO0_CLKCTRL_IDLEST_FUNC   (0x0u)
#define CM_WKUP_GPIO0_CLKCTRL_IDLEST_SHIFT   (0x00000010u)
#define CM_WKUP_GPIO0_CLKCTRL   (0x8)
#define CM_WKUP_GPIO0_CLKCTRL_IDLEST   (0x00030000u)
#define CM_WKUP_CLKSTCTRL_CLKACTIVITY_GPIO0_GDBCLK   (0x00000100u)

#define GPIO0_BASE              0x44E07000
#define GPIO0_OE                (GPIO0_BASE + 0x134)
#define GPIO0_DATAOUT           (GPIO0_BASE + 0x13c)
#define GPIO0_SETDATAOUT        (GPIO0_BASE + 0x194)
#define GPIO0_CLEARDATAOUT      (GPIO0_BASE + 0x190)
#define BL_BIT                 (1 << 2)

    /* Writing to MODULEMODE field of CM_WKUP_GPIO0_CLKCTRL register. */
    __raw_writel(__raw_readl(SOC_CM_WKUP_REGS + CM_WKUP_GPIO0_CLKCTRL) |=
        CM_WKUP_GPIO0_CLKCTRL_MODULEMODE_ENABLE, SOC_CM_WKUP_REGS + CM_WKUP_GPIO0_CLKCTRL);

    /* Waiting for MODULEMODE field to reflect the written value. */
    while(CM_WKUP_GPIO0_CLKCTRL_MODULEMODE_ENABLE !=
          (__raw_readl(SOC_CM_WKUP_REGS + CM_WKUP_GPIO0_CLKCTRL) &
           CM_WKUP_GPIO0_CLKCTRL_MODULEMODE));

    /*
    ** Writing to OPTFCLKEN_GPIO0_GDBCLK field of CM_WKUP_GPIO0_CLKCTRL
    ** register.
    */
    __raw_writel(__raw_readl(SOC_CM_WKUP_REGS + CM_WKUP_GPIO0_CLKCTRL) |=
        CM_WKUP_GPIO0_CLKCTRL_OPTFCLKEN_GPIO0_GDBCLK, SOC_CM_WKUP_REGS + CM_WKUP_GPIO0_CLKCTRL);

    /* Waiting for OPTFCLKEN_GPIO0_GDBCLK field to reflect the written value. */
    while(CM_WKUP_GPIO0_CLKCTRL_OPTFCLKEN_GPIO0_GDBCLK !=
          (__raw_readl(SOC_CM_WKUP_REGS + CM_WKUP_GPIO0_CLKCTRL) &
           CM_WKUP_GPIO0_CLKCTRL_OPTFCLKEN_GPIO0_GDBCLK));

    /* Verifying if the other bits are set to required settings. */

    /*
    ** Waiting for IDLEST field in CM_WKUP_CONTROL_CLKCTRL register to attain
    ** desired value.
    */
    while((CM_WKUP_CONTROL_CLKCTRL_IDLEST_FUNC <<
           CM_WKUP_CONTROL_CLKCTRL_IDLEST_SHIFT) !=
          (__raw_readl(SOC_CM_WKUP_REGS + CM_WKUP_CONTROL_CLKCTRL) &
           CM_WKUP_CONTROL_CLKCTRL_IDLEST));

    /*
    ** Waiting for CLKACTIVITY_L3_AON_GCLK field in CM_L3_AON_CLKSTCTRL
    ** register to attain desired value.
    */
    while(CM_WKUP_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_L3_AON_GCLK !=
          (__raw_readl(SOC_CM_WKUP_REGS + CM_WKUP_CM_L3_AON_CLKSTCTRL) &
           CM_WKUP_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_L3_AON_GCLK));

    /*
    ** Waiting for IDLEST field in CM_WKUP_L4WKUP_CLKCTRL register to attain
    ** desired value.
    */
    while((CM_WKUP_L4WKUP_CLKCTRL_IDLEST_FUNC <<
           CM_WKUP_L4WKUP_CLKCTRL_IDLEST_SHIFT) !=
          (__raw_readl(SOC_CM_WKUP_REGS + CM_WKUP_L4WKUP_CLKCTRL) &
           CM_WKUP_L4WKUP_CLKCTRL_IDLEST));

    /*
    ** Waiting for CLKACTIVITY_L4_WKUP_GCLK field in CM_WKUP_CLKSTCTRL register
    ** to attain desired value.
    */
    while(CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK !=
          (__raw_readl(SOC_CM_WKUP_REGS + CM_WKUP_CLKSTCTRL) &
           CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK));

    /*
    ** Waiting for CLKACTIVITY_L4_WKUP_AON_GCLK field in CM_L4_WKUP_AON_CLKSTCTRL
    ** register to attain desired value.
    */
    while(CM_WKUP_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_L4_WKUP_AON_GCLK !=
          (__raw_readl(SOC_CM_WKUP_REGS + CM_WKUP_CM_L4_WKUP_AON_CLKSTCTRL) &
           CM_WKUP_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_L4_WKUP_AON_GCLK));


    /* Writing to IDLEST field in CM_WKUP_GPIO0_CLKCTRL register. */
    while((CM_WKUP_GPIO0_CLKCTRL_IDLEST_FUNC <<
           CM_WKUP_GPIO0_CLKCTRL_IDLEST_SHIFT) !=
          (__raw_readl(SOC_CM_WKUP_REGS + CM_WKUP_GPIO0_CLKCTRL) &
           CM_WKUP_GPIO0_CLKCTRL_IDLEST));

    /*
    ** Waiting for CLKACTIVITY_GPIO0_GDBCLK field in CM_WKUP_GPIO0_CLKCTRL
    ** register to attain desired value.
    */
    while(CM_WKUP_CLKSTCTRL_CLKACTIVITY_GPIO0_GDBCLK !=
          (__raw_readl(SOC_CM_WKUP_REGS + CM_WKUP_CLKSTCTRL) &
           CM_WKUP_CLKSTCTRL_CLKACTIVITY_GPIO0_GDBCLK));



	enable_backlight_pin_mux();
	__raw_writel(__raw_readl(GPIO0_OE) & ~BL_BIT, GPIO0_OE);
	__raw_writel(BL_BIT, GPIO0_CLEARDATAOUT);

}


/*
 * early system init of muxing and clocks.
 */
void s_init(void)
{
	/* Can be removed as A8 comes up with L2 enabled */
	//l2_cache_enable();

	/* WDT1 is already running when the bootloader gets control
	 * Disable it to avoid "random" resets
	 */
	__raw_writel(0xAAAA, WDT_WSPR);
	while(__raw_readl(WDT_WWPS) != 0x0);
	__raw_writel(0x5555, WDT_WSPR);
	while(__raw_readl(WDT_WWPS) != 0x0);

	/* Added by MYIR, init LCD backlight(turn_off) */
	myir_init_backlight();
	enable_wdt_pin_mux();


	/* Setup the PLLs and the clocks for the peripherals */
	pll_init();

	/* UART softreset */
	u32 regVal;
	u32 uart_base = DEFAULT_UART_BASE;

	enable_uart0_pin_mux();
	/* IA Motor Control Board has default console on UART3*/
	/* XXX: This is before we've probed / set board_id */


	regVal = __raw_readl(uart_base + UART_SYSCFG_OFFSET);
	regVal |= UART_RESET;
	__raw_writel(regVal, (uart_base + UART_SYSCFG_OFFSET) );
	while ((__raw_readl(uart_base + UART_SYSSTS_OFFSET) &
			UART_CLK_RUNNING_MASK) != UART_CLK_RUNNING_MASK);

	/* Disable smart idle */
	regVal = __raw_readl((uart_base + UART_SYSCFG_OFFSET));
	regVal |= UART_SMART_IDLE_EN;
	__raw_writel(regVal, (uart_base + UART_SYSCFG_OFFSET));

	/* Initialize the Timer */
	init_timer();

	//preloader_console_init();



}

static unsigned char profile = PROFILE_0;

/*
 * Basic board specific setup
 */

int board_evm_init(void)
{
	/* mach type passed to kernel */
	if (board_id == IA_BOARD)
		gd->bd->bi_arch_number = MACH_TYPE_TIAM335IAEVM;
	else
		gd->bd->bi_arch_number = MACH_TYPE_TIAM335EVM;

	/* address of boot parameters */
	gd->bd->bi_boot_params = PHYS_DRAM_1 + 0x100;

	return 0;
}



