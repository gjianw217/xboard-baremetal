
#define __AM335X_HARDWARE_H
#ifndef __AM335X_HARDWARE_H


/* The objective is to keep only the overall memory map here
 * The break-up of the memory map for individual modules registers should
 * be in a different file like cpu.h so that this is the only place
 * where change is needed for new SoCs when the IP is otherwise the same
 */

#define SRAM0_START			0x402F0400

/* EMIF Base address */
#define EMIF4_0_CFG_BASE		0x4C000000
#define EMIF4_1_CFG_BASE		0x4D000000
#define DMM_BASE			0x4E000000

#define UART0_BASE			0x44E09000
#define UART1_BASE			0x48022000
#define UART2_BASE			0x48024000
#define UART3_BASE			0x481A6000

/* DM Timer base addresses */
#define DM_TIMER0_BASE			0x4802C000
#define DM_TIMER1_BASE			0x4802E000
#define DM_TIMER2_BASE			0x48040000
#define DM_TIMER3_BASE			0x48042000
#define DM_TIMER4_BASE			0x48044000
#define DM_TIMER5_BASE			0x48046000
#define DM_TIMER6_BASE			0x48048000
#define DM_TIMER7_BASE			0x4804A000

/* GPIO Base address */
#define GPIO0_BASE			0x48032000
#define GPIO1_BASE			0x4804C000

#define GPIO2_BASE			0x481AC000

/* BCH Error Location Module */
#define ELM_BASE			0x48080000

/* Watchdog Timer */

#define WDT_BASE			0x44E35000

/* Control Module Base Address */

#define CTRL_BASE			0x44E10000

/* PRCM Base Address */

#define PRCM_BASE			0x44E00000






#define DDRPHY_0_CONFIG_BASE		(CTRL_BASE + 0x1400)
#define DDRPHY_CONFIG_BASE		DDRPHY_0_CONFIG_BASE


/* GPMC Base address */
#define GPMC_BASE			0x50000000

/* CPSW Config space */


#define AM335X_CPSW_BASE               0x4A100000
#define AM335X_CPSW_MDIO_BASE          0x4A101000

#endif 


