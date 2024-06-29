#ifndef  AM335X_PER_H__
#define  AM335X_PER_H__


#include  "AM335X_Mapping.h"

/*
*Clock Module P916
*/

#define             CM_PER_L4LS_CLKSTCTRL          (*(volatile unsigned long *)(CM_PER_BASE + 0x0   ))
#define             CM_PER_L3S_CLKSTCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0x4   ))
#define             CM_PER_L3_CLKSTCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0xC   ))
#define             CM_PER_CPGMAC0_CLKCTRL         (*(volatile unsigned long *)(CM_PER_BASE + 0x14  ))
#define             CM_PER_LCDC_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0x18  ))
#define             CM_PER_USB0_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0x1C  ))
#define             CM_PER_TPTC0_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0x24  ))
#define             CM_PER_EMIF_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0x28  ))
#define             CM_PER_OCMCRAM_CLKCTRL         (*(volatile unsigned long *)(CM_PER_BASE + 0x2C  ))
#define             CM_PER_GPMC_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0x30  ))
#define             CM_PER_MCASP0_CLKCTRL          (*(volatile unsigned long *)(CM_PER_BASE + 0x34  ))
#define             CM_PER_UART5_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0x38  ))
#define             CM_PER_MMC0_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0x3C  ))
#define             CM_PER_ELM_CLKCTRL             (*(volatile unsigned long *)(CM_PER_BASE + 0x40  ))
#define             CM_PER_I2C2_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0x44  ))
#define             CM_PER_I2C1_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0x48  ))
#define             CM_PER_SPI0_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0x4C  ))
#define             CM_PER_SPI1_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0x50  ))
#define             CM_PER_L4LS_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0x60  ))
#define             CM_PER_MCASP1_CLKCTRL          (*(volatile unsigned long *)(CM_PER_BASE + 0x68  ))
#define             CM_PER_UART1_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0x6C  ))
#define             CM_PER_UART2_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0x70  ))
#define             CM_PER_UART3_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0x74  ))
#define             CM_PER_UART4_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0x78  ))
#define             CM_PER_TIMER7_CLKCTRL          (*(volatile unsigned long *)(CM_PER_BASE + 0x7C  ))
#define             CM_PER_TIMER2_CLKCTRL          (*(volatile unsigned long *)(CM_PER_BASE + 0x80  ))
#define             CM_PER_TIMER3_CLKCTRL          (*(volatile unsigned long *)(CM_PER_BASE + 0x84  ))
#define             CM_PER_TIMER4_CLKCTRL          (*(volatile unsigned long *)(CM_PER_BASE + 0x88  ))
#define             CM_PER_GPIO1_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0xAC  ))
#define             CM_PER_GPIO2_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0xB0  ))
#define             CM_PER_GPIO3_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0xB4  ))
#define             CM_PER_TPCC_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0xBC  ))
#define             CM_PER_DCAN0_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0xC0  ))
#define             CM_PER_DCAN1_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0xC4  ))
#define             CM_PER_EPWMSS1_CLKCTRL         (*(volatile unsigned long *)(CM_PER_BASE + 0xCC  ))
#define             CM_PER_EPWMSS0_CLKCTRL         (*(volatile unsigned long *)(CM_PER_BASE + 0xD4  ))
#define             CM_PER_EPWMSS2_CLKCTRL         (*(volatile unsigned long *)(CM_PER_BASE + 0xD8  ))
#define             CM_PER_L3_INSTR_CLKCTRL        (*(volatile unsigned long *)(CM_PER_BASE + 0xDC  ))
#define             CM_PER_L3_CLKCTRL              (*(volatile unsigned long *)(CM_PER_BASE + 0xE0  ))
#define             CM_PER_IEEE5000_CLKCTRL        (*(volatile unsigned long *)(CM_PER_BASE + 0xE4  ))
#define             CM_PER_PRU_ICSS_CLKCTRL        (*(volatile unsigned long *)(CM_PER_BASE + 0xE8  ))
#define             CM_PER_TIMER5_CLKCTRL          (*(volatile unsigned long *)(CM_PER_BASE + 0xEC  ))
#define             CM_PER_TIMER6_CLKCTRL          (*(volatile unsigned long *)(CM_PER_BASE + 0xF0  ))
#define             CM_PER_MMC1_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0xF4  ))
#define             CM_PER_MMC2_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0xF8  ))
#define             CM_PER_TPTC1_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0xFC  ))
#define             CM_PER_TPTC2_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0x100 ))
#define             CM_PER_SPINLOCK_CLKCTRL        (*(volatile unsigned long *)(CM_PER_BASE + 0x10C ))
#define             CM_PER_MAILBOX0_CLKCTRL        (*(volatile unsigned long *)(CM_PER_BASE + 0x110 ))
#define             CM_PER_L4HS_CLKSTCTRL          (*(volatile unsigned long *)(CM_PER_BASE + 0x11C ))
#define             CM_PER_L4HS_CLKCTRL            (*(volatile unsigned long *)(CM_PER_BASE + 0x120 ))
#define             CM_PER_OCPWP_L3_CLKSTCTRL      (*(volatile unsigned long *)(CM_PER_BASE + 0x12C ))
#define             CM_PER_OCPWP_CLKCTRL           (*(volatile unsigned long *)(CM_PER_BASE + 0x130 ))
#define             CM_PER_PRU_ICSS_CLKSTCTRL      (*(volatile unsigned long *)(CM_PER_BASE + 0x140 ))
#define             CM_PER_CPSW_CLKSTCTRL          (*(volatile unsigned long *)(CM_PER_BASE + 0x144 ))
#define             CM_PER_LCDC_CLKSTCTRL          (*(volatile unsigned long *)(CM_PER_BASE + 0x148 ))
#define             CM_PER_CLKDIV32K_CLKCTRL       (*(volatile unsigned long *)(CM_PER_BASE + 0x14C ))
#define             CM_PER_CLK_24MHZ_CLKSTCTRL     (*(volatile unsigned long *)(CM_PER_BASE + 0x150 ))


/**CM_WUP**/


#define          CM_WKUP_CLKSTCTRL                     (*(volatile unsigned long *)(CM_WKUP_BASE + 0x0 ))
#define          CM_WKUP_CONTROL_CLKCTRL               (*(volatile unsigned long *)(CM_WKUP_BASE + 0x4 ))
#define          CM_WKUP_GPIO0_CLKCTRL                 (*(volatile unsigned long *)(CM_WKUP_BASE + 0x8 ))
#define          CM_WKUP_L4WKUP_CLKCTRL                (*(volatile unsigned long *)(CM_WKUP_BASE + 0xC ))
#define          CM_WKUP_TIMER0_CLKCTRL                (*(volatile unsigned long *)(CM_WKUP_BASE + 0x10))
#define          CM_WKUP_DEBUGSS_CLKCTRL               (*(volatile unsigned long *)(CM_WKUP_BASE + 0x14))
#define          CM_L3_AON_CLKSTCTRL                   (*(volatile unsigned long *)(CM_WKUP_BASE + 0x18))
#define          CM_AUTOIDLE_DPLL_MPU                  (*(volatile unsigned long *)(CM_WKUP_BASE + 0x1C))
#define          CM_IDLEST_DPLL_MPU                    (*(volatile unsigned long *)(CM_WKUP_BASE + 0x20))
#define          CM_SSC_DELTAMSTEP_DPLL_MPU            (*(volatile unsigned long *)(CM_WKUP_BASE + 0x24))
#define          CM_SSC_MODFREQDIV_DPLL_MPU            (*(volatile unsigned long *)(CM_WKUP_BASE + 0x28))
#define          CM_CLKSEL_DPLL_MPU                    (*(volatile unsigned long *)(CM_WKUP_BASE + 0x2C))
#define          CM_AUTOIDLE_DPLL_DDR                  (*(volatile unsigned long *)(CM_WKUP_BASE + 0x30))
#define          CM_IDLEST_DPLL_DDR                    (*(volatile unsigned long *)(CM_WKUP_BASE + 0x34))
#define          CM_SSC_DELTAMSTEP_DPLL_DDR            (*(volatile unsigned long *)(CM_WKUP_BASE + 0x38))
#define          CM_SSC_MODFREQDIV_DPLL_DDR            (*(volatile unsigned long *)(CM_WKUP_BASE + 0x3C))
#define          CM_CLKSEL_DPLL_DDR                    (*(volatile unsigned long *)(CM_WKUP_BASE + 0x40))
#define          CM_AUTOIDLE_DPLL_DISP                 (*(volatile unsigned long *)(CM_WKUP_BASE + 0x44))
#define          CM_IDLEST_DPLL_DISP                   (*(volatile unsigned long *)(CM_WKUP_BASE + 0x48))
#define          CM_SSC_DELTAMSTEP_DPLL_DISP           (*(volatile unsigned long *)(CM_WKUP_BASE + 0x4C))
#define          CM_SSC_MODFREQDIV_DPLL_DISP           (*(volatile unsigned long *)(CM_WKUP_BASE + 0x50))
#define          CM_CLKSEL_DPLL_DISP                   (*(volatile unsigned long *)(CM_WKUP_BASE + 0x54))
#define          CM_AUTOIDLE_DPLL_CORE                 (*(volatile unsigned long *)(CM_WKUP_BASE + 0x58))
#define          CM_IDLEST_DPLL_CORE                   (*(volatile unsigned long *)(CM_WKUP_BASE + 0x5C))
#define          CM_SSC_DELTAMSTEP_DPLL_CORE           (*(volatile unsigned long *)(CM_WKUP_BASE + 0x60))
#define          CM_SSC_MODFREQDIV_DPLL_CORE           (*(volatile unsigned long *)(CM_WKUP_BASE + 0x64))
#define          CM_CLKSEL_DPLL_CORE                   (*(volatile unsigned long *)(CM_WKUP_BASE + 0x68))
#define          CM_AUTOIDLE_DPLL_PER                  (*(volatile unsigned long *)(CM_WKUP_BASE + 0x6C))
#define          CM_IDLEST_DPLL_PER                    (*(volatile unsigned long *)(CM_WKUP_BASE + 0x70))
#define          CM_SSC_DELTAMSTEP_DPLL_PER            (*(volatile unsigned long *)(CM_WKUP_BASE + 0x74))
#define          CM_SSC_MODFREQDIV_DPLL_PER            (*(volatile unsigned long *)(CM_WKUP_BASE + 0x78))
#define          CM_CLKDCOLDO_DPLL_PER                 (*(volatile unsigned long *)(CM_WKUP_BASE + 0x7C))
#define          CM_DIV_M4_DPLL_CORE                   (*(volatile unsigned long *)(CM_WKUP_BASE + 0x80))
#define          CM_DIV_M5_DPLL_CORE                   (*(volatile unsigned long *)(CM_WKUP_BASE + 0x84))
#define          CM_CLKMODE_DPLL_MPU                   (*(volatile unsigned long *)(CM_WKUP_BASE + 0x88))
#define          CM_CLKMODE_DPLL_PER                   (*(volatile unsigned long *)(CM_WKUP_BASE + 0x8C))
#define          CM_CLKMODE_DPLL_CORE                  (*(volatile unsigned long *)(CM_WKUP_BASE + 0x90))
#define          CM_CLKMODE_DPLL_DDR                   (*(volatile unsigned long *)(CM_WKUP_BASE + 0x94))
#define          CM_CLKMODE_DPLL_DISP                  (*(volatile unsigned long *)(CM_WKUP_BASE + 0x98))
#define          CM_CLKSEL_DPLL_PERIPH                 (*(volatile unsigned long *)(CM_WKUP_BASE + 0x9C))
#define          CM_DIV_M2_DPLL_DDR                    (*(volatile unsigned long *)(CM_WKUP_BASE + 0xA0))
#define          CM_DIV_M2_DPLL_DISP                   (*(volatile unsigned long *)(CM_WKUP_BASE + 0xA4))
#define          CM_DIV_M2_DPLL_MPU                    (*(volatile unsigned long *)(CM_WKUP_BASE + 0xA8))
#define          CM_DIV_M2_DPLL_PER                    (*(volatile unsigned long *)(CM_WKUP_BASE + 0xAC))
#define          CM_WKUP_WKUP_M3_CLKCTRL               (*(volatile unsigned long *)(CM_WKUP_BASE + 0xB0))
#define          CM_WKUP_UART0_CLKCTRL                 (*(volatile unsigned long *)(CM_WKUP_BASE + 0xB4))
#define          CM_WKUP_I2C0_CLKCTRL                  (*(volatile unsigned long *)(CM_WKUP_BASE + 0xB8))
#define          CM_WKUP_ADC_TSC_CLKCTRL               (*(volatile unsigned long *)(CM_WKUP_BASE + 0xBC))
#define          CM_WKUP_SMARTREFLEX0_CLKCTRL          (*(volatile unsigned long *)(CM_WKUP_BASE + 0xC0))
#define          CM_WKUP_TIMER1_CLKCTRL                (*(volatile unsigned long *)(CM_WKUP_BASE + 0xC4))
#define          CM_WKUP_SMARTREFLEX1_CLKCTRL          (*(volatile unsigned long *)(CM_WKUP_BASE + 0xC8))
#define          CM_L4_WKUP_AON_CLKSTCTRL              (*(volatile unsigned long *)(CM_WKUP_BASE + 0xCC))
#define          CM_WKUP_WDT1_CLKCTRL                  (*(volatile unsigned long *)(CM_WKUP_BASE + 0xD4))
#define          CM_DIV_M6_DPLL_CORE                   (*(volatile unsigned long *)(CM_WKUP_BASE + 0xD8))


/**CM_DPLL P1041**/
#define           CLKSEL_TIMER7_CLK                    (*(volatile unsigned long *)(CM_DPLL_BASE + 0x4 ))
#define           CLKSEL_TIMER2_CLK                    (*(volatile unsigned long *)(CM_DPLL_BASE + 0x8 ))
#define           CLKSEL_TIMER3_CLK                    (*(volatile unsigned long *)(CM_DPLL_BASE + 0xC ))
#define           CLKSEL_TIMER4_CLK                    (*(volatile unsigned long *)(CM_DPLL_BASE + 0x10))
#define           CM_MAC_CLKSEL                        (*(volatile unsigned long *)(CM_DPLL_BASE + 0x14))
#define           CLKSEL_TIMER5_CLK                    (*(volatile unsigned long *)(CM_DPLL_BASE + 0x18))
#define           CLKSEL_TIMER6_CLK                    (*(volatile unsigned long *)(CM_DPLL_BASE + 0x1C))
#define           CM_CPTS_RFT_CLKSEL                   (*(volatile unsigned long *)(CM_DPLL_BASE + 0x20))
#define           CLKSEL_TIMER1MS_CLK                  (*(volatile unsigned long *)(CM_DPLL_BASE + 0x28))
#define           CLKSEL_GFX_FCLK                      (*(volatile unsigned long *)(CM_DPLL_BASE + 0x2C))
#define           CLKSEL_PRU_ICSS_OCP_CLK              (*(volatile unsigned long *)(CM_DPLL_BASE + 0x30))
#define           CLKSEL_LCDC_PIXEL_CLK                (*(volatile unsigned long *)(CM_DPLL_BASE + 0x34))
#define           CLKSEL_WDT1_CLK                      (*(volatile unsigned long *)(CM_DPLL_BASE + 0x38))
#define           CLKSEL_GPIO0_DBCLK                   (*(volatile unsigned long *)(CM_DPLL_BASE + 0x3C))



/**CM_MPU**/

#define              CM_MPU_CLKSTCTRL			(*(volatile unsigned long *)(CM_MPU_BASE + 0x0))
#define              CM_MPU_MPU_CLKCTRL			(*(volatile unsigned long *)(CM_MPU_BASE + 0x4))


/**CM_DEVICE**/


#define             CM_CLKOUT_CTRL			(*(volatile unsigned long *)(CONTROL_MODULE_BASE + 0x0 ))

/**CM_RTC**/

#define            CM_RTC_RTC_CLKCTRL   	(*(volatile unsigned long *)(CM_RTC_BASE + 0x0 ))
#define            CM_RTC_CLKSTCTRL  		(*(volatile unsigned long *)(CM_RTC_BASE + 0x4))


/**CM_GFX **/

#define                  CM_GFX_L3_CLKSTCTRL			   (*(volatile unsigned long *)(CM_GFX_BASE + 0x0 ))
#define                  CM_GFX_GFX_CLKCTRL                (*(volatile unsigned long *)(CM_GFX_BASE + 0x4 ))
#define                  CM_GFX_L4LS_GFX_CLKSTCTRL         (*(volatile unsigned long *)(CM_GFX_BASE + 0xC ))
#define                  CM_GFX_MMUCFG_CLKCTRL             (*(volatile unsigned long *)(CM_GFX_BASE + 0x10))
#define                  CM_GFX_MMUDATA_CLKCTRL            (*(volatile unsigned long *)(CM_GFX_BASE + 0x14))


/**CM_CEFUSE
#define              CM_CEFUSE_CLKSTCTRL            	(*(volatile unsigned long *)(CM_CEFUSE_BASE + 0x0))
#define              CM_CEFUSE_CEFUSE_CLKCTRL			(*(volatile unsigned long *)(CM_CEFUSE_BASE + 0x20))  
**/



#endif

