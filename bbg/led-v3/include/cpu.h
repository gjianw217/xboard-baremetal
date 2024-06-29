

#ifndef _AM335X_CPU_H
#define _AM335X_CPU_H


#include "hardware.h"

typedef signed char s8;
typedef unsigned char u8;

typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;



#define BIT(x)				(1 << x)
#define CL_BIT(x)			(0 << x)

/* Timer registers */
#define TIMER_TCLR			0x38		/* Timer control register */
#define TIMER_TCRR			0x3C		/* Timer counter register */
#define TIMER_TLDR			0x40		/* Timer load value register*/



struct gptimer {
	u32 tidr;	/* 0x00 r */
	u8 res1[0xc];
	u32 tiocp_cfg;	/* 0x10 rw */
	u8 res2[0xc];
	u32 tier;	/* 0x20 rw */
	u32 tistatr;/* 0x24 r */
	u32 tistat;	/* 0x28 r */
	u32 tisr;	/* 0x2c rw */
	u32 tcicr;	/* 0x30 rw */
	u32 twer;	/* 0x34 rw */
	u32 tclr;	/* 0x38 rw - control reg */
	u32 tcrr;	/* 0x3c rw - counter reg */
	u32 tldr;	/* 0x40 rw - load reg */
	u32 ttgr;	/* 0x44 rw */
	u32 twpc;	/* 0x48 r*/
	u32 tmar;	/* 0x4c rw*/
	u32 tcar1;	/* 0x50 r */
	u32 tscir;	/* 0x54 r */
	u32 tcar2;	/* 0x58 r */
};
#endif /* __ASSEMBLY__ */
#endif /* __KERNEL_STRICT_NAMES */

/* Timer register bits */
#define TCLR_ST				BIT(0)		/* Start=1 Stop=0 */
#define TCLR_AR				BIT(1)		/* Auto reload */
#define TCLR_PRE			BIT(5)		/* Pre-scaler enable */
#define TCLR_PTV_SHIFT			(2)		/* Pre-scaler shift value */
#define TCLR_PRE_DISABLE		CL_BIT(5)	/* Pre-scalar disable */

/* Control */
#define CONTROL_STATUS			(CTRL_BASE + 0x40)

/* device type */
#define DEVICE_MASK			(BIT(8) | BIT(9) | BIT(10))
#define TST_DEVICE			0x0
#define EMU_DEVICE			0x1
#define HS_DEVICE			0x2
#define GP_DEVICE			0x3

/* rom boot device/mode id */
#define BOOT_DEVICE_OFFSET		8
#define BOOT_DEVICE_MASK		0xff

/* cpu-id for TI81XX family */

#define AM335X				0xB944

#define DEVICE_ID			(CTRL_BASE + 0x0600)
/* This gives the status of the boot mode pins on the evm */
#define SYSBOOT_MASK			(BIT(0) | BIT(1) | BIT(2) |BIT(3) |BIT(4))

/* Reset control */


#define PRM_RSTCTRL			(PRCM_BASE + 0x0F00)

#define PRM_RSTCTRL_RESET		0x01


/* Module Offsets */
#define CM_PER				(PRCM_BASE + 0x0)
#define CM_WKUP				(PRCM_BASE + 0x400)
#define CM_DPLL				(PRCM_BASE + 0x500)
#define CM_DEVICE			(PRCM_BASE + 0x0700)
#define CM_CEFUSE			(PRCM_BASE + 0x0A00)
#define PRM_DEVICE			(PRCM_BASE + 0x0F00)

/* Register Offsets */
/* Core PLL ADPLLS */
#define CM_CLKSEL_DPLL_CORE		(CM_WKUP + 0x68)
#define CM_CLKMODE_DPLL_CORE		(CM_WKUP + 0x90)

/* Core HSDIV */
#define CM_DIV_M4_DPLL_CORE		(CM_WKUP + 0x80)
#define CM_DIV_M5_DPLL_CORE		(CM_WKUP + 0x84)
#define CM_DIV_M6_DPLL_CORE		(CM_WKUP + 0xD8)
#define CM_IDLEST_DPLL_CORE		(CM_WKUP + 0x5c)

/* Peripheral PLL */
#define CM_CLKSEL_DPLL_PER		(CM_WKUP + 0x9c)
#define CM_CLKMODE_DPLL_PER		(CM_WKUP + 0x8c)
#define CM_DIV_M2_DPLL_PER		(CM_WKUP + 0xAC)
#define CM_IDLEST_DPLL_PER		(CM_WKUP + 0x70)

/* Display PLL */
#define CM_CLKSEL_DPLL_DISP		(CM_WKUP + 0x54)
#define CM_CLKMODE_DPLL_DISP		(CM_WKUP + 0x98)
#define CM_DIV_M2_DPLL_DISP		(CM_WKUP + 0xA4)

/* DDR PLL */
#define CM_CLKSEL_DPLL_DDR		(CM_WKUP + 0x40)
#define CM_CLKMODE_DPLL_DDR		(CM_WKUP + 0x94)
#define CM_DIV_M2_DPLL_DDR		(CM_WKUP + 0xA0)
#define CM_IDLEST_DPLL_DDR		(CM_WKUP + 0x34)

/* MPU PLL */
#define CM_CLKSEL_DPLL_MPU		(CM_WKUP + 0x2c)
#define CM_CLKMODE_DPLL_MPU		(CM_WKUP + 0x88)
#define CM_DIV_M2_DPLL_MPU		(CM_WKUP + 0xA8)
#define CM_IDLEST_DPLL_MPU		(CM_WKUP + 0x20)

/* TIMER Clock Source Select */
#define CLKSEL_TIMER2_CLK		(CM_DPLL + 0x8)

/* Interconnect clocks */
#define CM_PER_L4LS_CLKCTRL		(CM_PER + 0x60)	/* EMIF */
#define CM_PER_L4FW_CLKCTRL		(CM_PER + 0x64)	/* EMIF FW */
#define CM_PER_L3_CLKCTRL		(CM_PER + 0xE0)	/* OCMC RAM */
#define CM_PER_L3_INSTR_CLKCTRL		(CM_PER + 0xDC)
#define CM_PER_L4HS_CLKCTRL		(CM_PER + 0x120)
#define CM_WKUP_L4WKUP_CLKCTRL		(CM_WKUP + 0x0c)/* UART0 */

/* Domain Wake UP */
#define CM_WKUP_CLKSTCTRL		(CM_WKUP + 0)	/* UART0 */
#define CM_PER_L4LS_CLKSTCTRL		(CM_PER + 0x0)	/* TIMER2 */
#define CM_PER_L3_CLKSTCTRL		(CM_PER + 0x0c)	/* EMIF */
#define CM_PER_L4FW_CLKSTCTRL		(CM_PER + 0x08)	/* EMIF FW */
#define CM_PER_L3S_CLKSTCTRL		(CM_PER + 0x4)
#define CM_PER_L4HS_CLKSTCTRL		(CM_PER + 0x011c)
#define CM_CEFUSE_CLKSTCTRL		(CM_CEFUSE + 0x0)

/* Module Enable Registers */
#define CM_PER_TIMER2_CLKCTRL		(CM_PER + 0x80)	/* Timer2 */
#define CM_WKUP_UART0_CLKCTRL		(CM_WKUP + 0xB4)/* UART0 */
#define CM_WKUP_CONTROL_CLKCTRL		(CM_WKUP + 0x4)	/* Control Module */
#define CM_PER_EMIF_CLKCTRL		(CM_PER + 0x28)	/* EMIF */
#define CM_PER_EMIF_FW_CLKCTRL		(CM_PER + 0xD0)	/* EMIF FW */
#define CM_PER_GPMC_CLKCTRL		(CM_PER + 0x30)	/* GPMC */
#define CM_PER_ELM_CLKCTRL		(CM_PER + 0x40)	/* ELM */
#define CM_PER_SPI0_CLKCTRL		(CM_PER + 0x4c) /* SPI0 */
#define CM_PER_SPI1_CLKCTRL		(CM_PER + 0x50) /* SPI1 */
#define CM_WKUP_I2C0_CLKCTRL		(CM_WKUP + 0xB8) /* I2C0 */
#define CM_PER_CPGMAC0_CLKCTRL		(CM_PER + 0x14)	/* Ethernet */
#define CM_PER_CPSW_CLKSTCTRL		(CM_PER + 0x144)/* Ethernet */
#define CM_PER_OCMCRAM_CLKCTRL		(CM_PER	+ 0x2C) /* OCMC RAM */
#define CM_PER_GPIO1_CLKCTRL		(CM_PER + 0xAC) /* GPIO1 */
#define CM_PER_GPIO2_CLKCTRL		(CM_PER + 0xB0) /* GPIO2 */
#define CM_PER_UART3_CLKCTRL		(CM_PER + 0x74) /* UART3 */
#define CM_PER_I2C1_CLKCTRL		(CM_PER + 0x48) /* I2C1 */
#define CM_PER_I2C2_CLKCTRL		(CM_PER + 0x44) /* I2C2 */-
#define CM_WKUP_GPIO0_CLKCTRL		(CM_WKUP + 0x8) /* GPIO0 */

#define CM_PER_MMC0_CLKCTRL     	(CM_PER + 0x3C)
#define CM_PER_MMC1_CLKCTRL     	(CM_PER + 0xF4)
#define CM_PER_MMC2_CLKCTRL     	(CM_PER + 0xF8)



/* PRCM */
#define CM_DPLL_OFFSET			(PRCM_BASE + 0x0300)


#define DEFAULT_UART_BASE		UART0_BASE

/* UART registers */
/*TODO:Move to a new file */
#define UART_SYSCFG			(DEFAULT_UART_BASE + 0x54)
#define UART_SYSSTS			(DEFAULT_UART_BASE + 0x58)
#define UART_LCR			(DEFAULT_UART_BASE + 0x0C)
#define UART_EFR			(DEFAULT_UART_BASE + 0x08)
#define UART_MCR			(DEFAULT_UART_BASE + 0x10)
#define UART_SCR			(DEFAULT_UART_BASE + 0x40)
#define UART_TCR			(DEFAULT_UART_BASE + 0x18)
#define UART_FCR			(DEFAULT_UART_BASE + 0x08)
#define UART_DLL			(DEFAULT_UART_BASE + 0x00)
#define UART_DLH			(DEFAULT_UART_BASE + 0x04)
#define UART_MDR			(DEFAULT_UART_BASE + 0x20)

/*DMM & EMIF4 MMR Declaration*/

/*TODO: Move to a new file */
#define DMM_LISA_MAP__0			(DMM_BASE + 0x40)
#define DMM_LISA_MAP__1			(DMM_BASE + 0x44)
#define DMM_LISA_MAP__2			(DMM_BASE + 0x48)
#define DMM_LISA_MAP__3			(DMM_BASE + 0x4C)
#define DMM_PAT_BASE_ADDR		(DMM_BASE + 0x460)

#define EMIF_MOD_ID_REV			(EMIF4_0_CFG_BASE + 0x0)
#define EMIF4_0_SDRAM_STATUS            (EMIF4_0_CFG_BASE + 0x04)
#define EMIF4_0_SDRAM_CONFIG            (EMIF4_0_CFG_BASE + 0x08)
#define EMIF4_0_SDRAM_CONFIG2           (EMIF4_0_CFG_BASE + 0x0C)
#define EMIF4_0_SDRAM_REF_CTRL          (EMIF4_0_CFG_BASE + 0x10)
#define EMIF4_0_SDRAM_REF_CTRL_SHADOW   (EMIF4_0_CFG_BASE + 0x14)
#define EMIF4_0_SDRAM_TIM_1             (EMIF4_0_CFG_BASE + 0x18)
#define EMIF4_0_SDRAM_TIM_1_SHADOW      (EMIF4_0_CFG_BASE + 0x1C)
#define EMIF4_0_SDRAM_TIM_2             (EMIF4_0_CFG_BASE + 0x20)
#define EMIF4_0_SDRAM_TIM_2_SHADOW      (EMIF4_0_CFG_BASE + 0x24)
#define EMIF4_0_SDRAM_TIM_3             (EMIF4_0_CFG_BASE + 0x28)
#define EMIF4_0_SDRAM_TIM_3_SHADOW      (EMIF4_0_CFG_BASE + 0x2C)
#define EMIF0_0_SDRAM_MGMT_CTRL         (EMIF4_0_CFG_BASE + 0x38)
#define EMIF0_0_SDRAM_MGMT_CTRL_SHD     (EMIF4_0_CFG_BASE + 0x3C)
#define EMIF4_0_DDR_PHY_CTRL_1          (EMIF4_0_CFG_BASE + 0xE4)
#define EMIF4_0_DDR_PHY_CTRL_1_SHADOW   (EMIF4_0_CFG_BASE + 0xE8)
#define EMIF4_0_DDR_PHY_CTRL_2          (EMIF4_0_CFG_BASE + 0xEC)
#define EMIF4_0_IODFT_TLGC              (EMIF4_0_CFG_BASE + 0x60)


#define EMIF4_1_SDRAM_CONFIG		(EMIF4_1_CFG_BASE + 0x08)
#define EMIF4_1_SDRAM_CONFIG2		(EMIF4_1_CFG_BASE + 0x0C)
#define EMIF4_1_SDRAM_REF_CTRL		(EMIF4_1_CFG_BASE + 0x10)
#define EMIF4_1_SDRAM_REF_CTRL_SHADOW	(EMIF4_1_CFG_BASE + 0x14)
#define EMIF4_1_SDRAM_TIM_1		(EMIF4_1_CFG_BASE + 0x18)
#define EMIF4_1_SDRAM_TIM_1_SHADOW	(EMIF4_1_CFG_BASE + 0x1C)
#define EMIF4_1_SDRAM_TIM_2		(EMIF4_1_CFG_BASE + 0x20)
#define EMIF4_1_SDRAM_TIM_2_SHADOW	(EMIF4_1_CFG_BASE + 0x24)
#define EMIF4_1_SDRAM_TIM_3		(EMIF4_1_CFG_BASE + 0x28)
#define EMIF4_1_SDRAM_TIM_3_SHADOW	(EMIF4_1_CFG_BASE + 0x2C)
#define EMIF4_1_DDR_PHY_CTRL_1		(EMIF4_1_CFG_BASE + 0xE4)
#define EMIF4_1_DDR_PHY_CTRL_1_SHADOW	(EMIF4_1_CFG_BASE + 0xE8)
#define EMIF4_1_IODFT_TLGC		(EMIF4_1_CFG_BASE + 0x60)


#define VTP0_CTRL_REG			0x44E10E0C

#define VTP1_CTRL_REG			0x48140E10

/*EMIF4 PRCM Defintion*/
#define CM_DEFAULT_L3_FAST_CLKSTCTRL	(PRCM_BASE + 0x0508)
#define CM_DEFAULT_EMIF_0_CLKCTRL	(PRCM_BASE + 0x0520)
#define CM_DEFAULT_EMIF_1_CLKCTRL	(PRCM_BASE + 0x0524)
#define CM_DEFAULT_DMM_CLKCTRL		(PRCM_BASE + 0x0528)
#define CM_DEFAULT_FW_CLKCTRL		(PRCM_BASE + 0x052C)

/* Smartreflex Registers */
#define TI816X_SMRT_SCALE_ADDR		(CTRL_BASE + 0x06A0)
#define TI816X_SMRT_OPP_SVT_ADDR	(CTRL_BASE + 0x06A8)
#define TI816X_SMRT_OPP_HVT_ADDR	(CTRL_BASE + 0x06AC)


/* ALWON PRCM */

#define CM_ALWON_OCMC_0_CLKSTCTRL	CM_PER_L3_CLKSTCTRL
#define CM_ALWON_OCMC_0_CLKCTRL		CM_PER_OCMCRAM_CLKCTRL



#define CM_ALWON_GPMC_CLKCTRL		CM_PER_GPMC_CLKCTRL


#define SRAM0_SIZE			(0x1B400) /* 109 KB */
#define SRAM_GPMC_STACK_SIZE		(0x40)


#define LOW_LEVEL_SRAM_STACK		(SRAM0_START + SRAM0_SIZE - 4)

/* GPMC related */
#define GPMC_CONFIG_CS0			(0x60)
#define GPMC_CONFIG_CS0_BASE		(GPMC_BASE + GPMC_CONFIG_CS0)
#define GPMC_CONFIG1			(0x00)
#define GPMC_CONFIG2			(0x04)
#define GPMC_CONFIG3			(0x08)
#define GPMC_CONFIG4			(0x0C)
#define GPMC_CONFIG5			(0x10)
#define GPMC_CONFIG6			(0x14)
#define GPMC_CONFIG7			(0x18)

/* PAD configuration register offsets and values for gpmc address
 * lines a12 - a26


#ifdef CONFIG_AM335X
#define GPMC_A12			(CTRL_BASE + 0x8c0) /* LCD_DATA8 */
#define GPMC_A13			(CTRL_BASE + 0x8c4) /* LCD_DATA9 */
#define GPMC_A14			(CTRL_BASE + 0x8c8) /* LCD_DATA10 */
#define GPMC_A15			(CTRL_BASE + 0x8cc) /* LCD_DATA11 */
#define GPMC_A16			(CTRL_BASE + 0x8d0) /* LCD_DATA12 */
#define GPMC_A17			(CTRL_BASE + 0x8d4) /* LCD_DATA13 */
#define GPMC_A18			(CTRL_BASE + 0x8d8) /* LCD_DATA14 */
#define GPMC_A19			(CTRL_BASE + 0x8dc) /* LCD_DATA15 */
#define GPMC_A20			(CTRL_BASE + 0x850) /* GPMC_A4 */
#define GPMC_A21			(CTRL_BASE + 0x854) /* GPMC_A5 */
#define GPMC_A22			(CTRL_BASE + 0x858) /* GPMC_A6 */

/* DDR offsets */
#define	DDR_PHY_BASE_ADDR		0x44E12000
#define	DDR_IO_CTRL			0x44E10E04
#define	DDR_CKE_CTRL			0x44E1131C
#define	CONTROL_BASE_ADDR		0x44E10000

#define	DDR_CMD0_IOCTRL			(CONTROL_BASE_ADDR + 0x1404)
#define	DDR_CMD1_IOCTRL			(CONTROL_BASE_ADDR + 0x1408)
#define	DDR_CMD2_IOCTRL			(CONTROL_BASE_ADDR + 0x140C)
#define	DDR_DATA0_IOCTRL		(CONTROL_BASE_ADDR + 0x1440)
#define	DDR_DATA1_IOCTRL		(CONTROL_BASE_ADDR + 0x1444)

#define	CMD0_CTRL_SLAVE_RATIO_0		(DDR_PHY_BASE_ADDR + 0x01C)
#define	CMD0_CTRL_SLAVE_FORCE_0		(DDR_PHY_BASE_ADDR + 0x020)
#define	CMD0_CTRL_SLAVE_DELAY_0		(DDR_PHY_BASE_ADDR + 0x024)
#define	CMD0_DLL_LOCK_DIFF_0		(DDR_PHY_BASE_ADDR + 0x028)
#define	CMD0_INVERT_CLKOUT_0		(DDR_PHY_BASE_ADDR + 0x02C)

#define	CMD1_CTRL_SLAVE_RATIO_0		(DDR_PHY_BASE_ADDR + 0x050)
#define	CMD1_CTRL_SLAVE_FORCE_0		(DDR_PHY_BASE_ADDR + 0x054)
#define	CMD1_CTRL_SLAVE_DELAY_0		(DDR_PHY_BASE_ADDR + 0x058)
#define	CMD1_DLL_LOCK_DIFF_0		(DDR_PHY_BASE_ADDR + 0x05C)
#define	CMD1_INVERT_CLKOUT_0		(DDR_PHY_BASE_ADDR + 0x060)

#define	CMD2_CTRL_SLAVE_RATIO_0		(DDR_PHY_BASE_ADDR + 0x084)
#define	CMD2_CTRL_SLAVE_FORCE_0		(DDR_PHY_BASE_ADDR + 0x088)
#define	CMD2_CTRL_SLAVE_DELAY_0		(DDR_PHY_BASE_ADDR + 0x08C)
#define	CMD2_DLL_LOCK_DIFF_0		(DDR_PHY_BASE_ADDR + 0x090)
#define	CMD2_INVERT_CLKOUT_0		(DDR_PHY_BASE_ADDR + 0x094)

#define DATA0_RD_DQS_SLAVE_RATIO_0	(DDR_PHY_BASE_ADDR + 0x0C8)
#define DATA0_RD_DQS_SLAVE_RATIO_1	(DDR_PHY_BASE_ADDR + 0x0CC)
#define	DATA0_WR_DQS_SLAVE_RATIO_0	(DDR_PHY_BASE_ADDR + 0x0DC)

#define	DATA0_WR_DQS_SLAVE_RATIO_1	(DDR_PHY_BASE_ADDR + 0x0E0)
#define	DATA0_WRLVL_INIT_RATIO_0	(DDR_PHY_BASE_ADDR + 0x0F0)
#define DATA0_WRLVL_INIT_MODE_0		(DDR_PHY_BASE_ADDR + 0x0F8)
#define	DATA0_WRLVL_INIT_RATIO_1	(DDR_PHY_BASE_ADDR + 0x0F4)
#define	DATA0_GATELVL_INIT_RATIO_0	(DDR_PHY_BASE_ADDR + 0x0FC)

#define	DATA0_GATELVL_INIT_RATIO_1	(DDR_PHY_BASE_ADDR + 0x100)
#define DATA0_GATELVL_INIT_MODE_0	(DDR_PHY_BASE_ADDR + 0x104)
#define	DATA0_FIFO_WE_SLAVE_RATIO_0	(DDR_PHY_BASE_ADDR + 0x108)

#define	DATA0_FIFO_WE_SLAVE_RATIO_1	(DDR_PHY_BASE_ADDR + 0x10C)
#define	DATA0_WR_DATA_SLAVE_RATIO_0	(DDR_PHY_BASE_ADDR + 0x120)

#define	DATA0_WR_DATA_SLAVE_RATIO_1	(DDR_PHY_BASE_ADDR + 0x124)
#define DATA0_DLL_LOCK_DIFF_0		(DDR_PHY_BASE_ADDR + 0x138)

#define DATA0_RANK0_DELAYS_0		(DDR_PHY_BASE_ADDR + 0x134)
#define	DATA1_RANK0_DELAYS_0		(DDR_PHY_BASE_ADDR + 0x1D8)



struct gpmc_cs {
	u32 config1;		/* 0x00 */
	u32 config2;		/* 0x04 */
	u32 config3;		/* 0x08 */
	u32 config4;		/* 0x0C */
	u32 config5;		/* 0x10 */
	u32 config6;		/* 0x14 */
	u32 config7;		/* 0x18 */
	u32 nand_cmd;		/* 0x1C */
	u32 nand_adr;		/* 0x20 */
	u32 nand_dat;		/* 0x24 */
	u8 res[8];		/* blow up to 0x30 byte */
};

struct bch_res_0_3 {
	u32 bch_result_x[4];
};



struct gpmc {
	u8 res1[0x10];
	u32 sysconfig;		/* 0x10 */
	u8 res2[0x4];
	u32 irqstatus;		/* 0x18 */
	u32 irqenable;		/* 0x1C */
	u8 res3[0x20];
	u32 timeout_control;	/* 0x40 */
	u8 res4[0xC];
	u32 config;		/* 0x50 */
	u32 status;		/* 0x54 */
	u8 res5[0x8];		/* 0x58 */
	struct gpmc_cs cs[8];	/* 0x60, 0x90, .. */
	u8 res6[0x14];		/* 0x1E0 */
	u32 ecc_config;		/* 0x1F4 */
	u32 ecc_control;	/* 0x1F8 */
	u32 ecc_size_config;	/* 0x1FC */
	u32 ecc1_result;	/* 0x200 */
	u32 ecc2_result;	/* 0x204 */
	u32 ecc3_result;	/* 0x208 */
	u32 ecc4_result;	/* 0x20C */
	u32 ecc5_result;	/* 0x210 */
	u32 ecc6_result;	/* 0x214 */
	u32 ecc7_result;	/* 0x218 */
	u32 ecc8_result;	/* 0x21C */
	u32 ecc9_result;	/* 0x220 */
	u8 res7[12];		/* 0x224 */
	u32 testmomde_ctrl;	/* 0x230 */
	u8 res8[12];		/* 0x234 */
	struct bch_res_0_3 bch_result_0_3[2];	/* 0x240 */
};

/* Used for board specific gpmc initialization */
extern struct gpmc *gpmc_cfg;



/* Ethernet MAC ID from EFuse */
#define MAC_ID0_LO	(CTRL_BASE + 0x630)
#define MAC_ID0_HI	(CTRL_BASE + 0x634)
#define MAC_ID1_LO	(CTRL_BASE + 0x638)
#define MAC_ID1_HI	(CTRL_BASE + 0x63c)
#define MAC_MII_SEL	(CTRL_BASE + 0x650)

/* WDT related */
/* TODO: Move to a new file */
#define WDT_WDSC	(WDT_BASE + 0x010)
#define WDT_WDST	(WDT_BASE + 0x014)
#define WDT_WISR	(WDT_BASE + 0x018)
#define WDT_WIER	(WDT_BASE + 0x01C)
#define WDT_WWER	(WDT_BASE + 0x020)
#define WDT_WCLR	(WDT_BASE + 0x024)
#define WDT_WCRR	(WDT_BASE + 0x028)
#define WDT_WLDR	(WDT_BASE + 0x02C)
#define WDT_WTGR	(WDT_BASE + 0x030)
#define WDT_WWPS	(WDT_BASE + 0x034)
#define WDT_WDLY	(WDT_BASE + 0x044)
#define WDT_WSPR	(WDT_BASE + 0x048)
#define WDT_WIRQEOI	(WDT_BASE + 0x050)
#define WDT_WIRQSTATRAW	(WDT_BASE + 0x054)
#define WDT_WIRQSTAT	(WDT_BASE + 0x058)
#define WDT_WIRQENSET	(WDT_BASE + 0x05C)
#define WDT_WIRQENCLR	(WDT_BASE + 0x060)

#define WDT_UNFREEZE	(CTRL_BASE + 0x100)

#endif /* _TI816X_CPU_H */


