#ifndef    AM335X_MAPPING_H__
#define  AM335X_MAPPING_H__


/*L3**/

//#define GPMC 			         0x00000000
#define Boot_ROM 		         0x4000_0000
#define SRAM_internal	          0x402F0400
#define L3_OCMC0 		         0x40300000
#define L3F_CFG_Regs	          0x44000000
#define L3S_CFG_Regs 	         0x44800000
#define L4WKUP 			    	    0x44C00000
#define McASP0_Data         	0x46000000
#define McASP1_Data         	0x46400000


#define USBSS        			  0x47400000
#define USB0         			 0x47401000
#define USB0PHY      			    0x47401300
#define USB0_Core    			      0x47401400
#define USB1         			 0x47401800
#define USB1PHY      			    0x47401B00
#define USB1_Core    			      0x47401C00
#define USB_CPPI_DMA_Controller          0x47402000
#define USB_CPPI_DMA_Scheduler          0x47403000
#define USB_Queue_Manager          0x47404000

#define MMCHS2          			0x47810000
#define L4_PER          			0x48000000

#define TPCC        	 0x49000000
#define TPTC0          0x49800000
#define TPTC1          0x49900000
#define TPTC2         0x49A00000

#define L4_FAST          		0x4A000000
#define DebugSS_DRM          0x4B160000
#define DebugSS_ETB          0x4B162000

#define EMIF0         		 0x4C000000

#define GPMC          			0x50000000
#define ADC_TSC_DMA          0x54C00000
#define SGX530        			0x56000000
#define EMIF0_SDRAM          0x80000000


/**L4**/

#define      L4_WKUP           0x44C00000

#define      CM_PER_BASE          0x44E00000
#define      CM_WKUP_BASE          0x44E00400
#define      CM_DPLL_BASE          0x44E00500
#define      CM_MPU_BASE          0x44E00600
#define      CM_DEVICE_BASE          0x44E00700
#define      CM_RTC_BASE          0x44E00800
#define      CM_GFX_BASE          0x44E00900
#define      CM_CEFUSE_BASE          0x44E0_0A00


#define      PRM_IRQ          0x44E00B00
#define      PRM_PER          0x44E00C00
#define      PRM_WKUP          0x44E00D00
#define      PRM_MPU          0x44E00E00
#define      PRM_DEVICE          0x44E0_0F00
#define      PRM_RTC          0x44E01000
#define      PRM_GFX          0x44E01100
#define      PRM_CEFUSE          0x44E01200


#define      DMTIMER0_BASE          0x44E05000
#define      GPIO0_BASE          0x44E07000

#define      UART0_BASE          0x44E09000

#define 	I2C0          0x44E0B000
#define 	ADC_TSC          0x44E0D000

#define 	CONTROL_MODULE_BASE          0x44E10000

#define 	DDR_PHY          0x44E12000
#define 	DMTIMER1_1MS_BASE          0x44E31000


#define 	WDT1_BASE         	 0x44E35000
#define 	SmartReflex0          0x44E37000
#define 	SmartReflex1          0x44E39000

#define 	RTCSS_BASE          0x44E3E000

#define 	DebugSS          0x44E40000
#define 	UART1          0x48022000
#define 	UART2          0x48024000
#define 	I2C1          0x4802A000
#define 	McSPI0          0x48030000
#define 	McASP0_CFG          0x48038000
#define 	McASP1_CFG          0x4803C000

#define 	DMTIMER2_BASE          0x48040000
#define 	DMTIMER3_BASE          0x48042000
#define 	DMTIMER4_BASE          0x48044000
#define 	DMTIMER5_BASE          0x48046000
#define 	DMTIMER6_BASE          0x48048000
#define 	DMTIMER7_BASE          0x4804A000

#define 	GPIO1_BASE          0x4804C000
#define 	MMCHS0          0x48060000
#define 	ELM          0x48080000
#define 	Mailbox_0          0x480C8000
#define 	Spinlock          0x480CA000
#define 	OCP_Watchpoint          0x4818C000
#define 	I2C2          0x4819C000
#define 	McSPI1          0x481A0000
#define 	UART3          0x481A6000
#define 	UART4          0x481A8000
#define 	UART5          0x481AA000
#define 	GPIO2_BASE         0x481AC000
#define 	GPIO3_BASE          0x481AE000

#define 	DCAN0          0x481CC000
#define 	DCAN1          0x481D0000
#define 	MMC1          0x481D8000
#define 	Interrupt_controller          0x48200000
#define 	MPUSS_config_register          0x48240000
#define 	PWM_Subsystem_0          0x48300000
#define 	eCAP0          0x48300100
#define 	eQEP0          0x48300180
#define 	ePWM0          0x48300200
#define 	PWM_Subsystem_1          0x48302000
#define 	eCAP1          0x48302100
#define 	eQEP1          0x48302180
#define 	ePWM1          0x48302200

#define 	PWM_Subsystem_2          0x48304000
#define 	eCAP2          0x48304100
#define 	eQEP2          0x48304180
#define 	ePWM2          0x48304200
#define 	LCD_Controller          0x4830E000
#define 	L4Fast_configuration          0x4A000000
#define 	CPSWSS          	0x4A100000
#define 	CPSWPORT          0x4A100100
#define 	CPSW_CPDMA          0x4A100800
#define 	CPSW_STATS          0x4A100900
#define 	CPSW_STATERAM          0x4A100A00
#define 	CPSW_CPTS         	 0x4A100C00
#define 	CPSW_ALE         	 0x4A100D00
#define 	CPSW_SL1          	0x4A100D80
#define 	CPSW_SL2         		 0x4A100DC0
#define 	MDIO         			 0x4A10_1000
#define 	CPSW_WR         	 0x4A101200
#define 	CPPI_RAM         	 0x4A102000
#define 	PRU_ICSS                   0x4A300000

#endif

