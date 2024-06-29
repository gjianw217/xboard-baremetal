/*************************************************************************
    > File Name: led.c
    > Description: 完善AM335X裸机LED
    > Created Time: 20170726
*************************************************************************/

#include "AM335X_SOC.h"
#include "delay.h"
/********************
V15	CONF_GPMC_A5 mode7  gpio1_21  
********************/

void led_init(void)
{
	//1.使能GPIO外设时钟. CP468
	CM_PER_GPIO1_CLKCTRL   = (0x40002);
	
	//2 配置gpio引脚
	CONF_GPMC_A5 =  ((0x7 << 0 ) | (0X1 << 4 ) | (0x1 << 3) );
	
	//3.设置为输出;CP3731
	GPIO1_OE &= ~(0x01<<21);

	//4.设置允许输出位;
	GPIO1_SETDATAOUT |= (0x01<<21);
	
	delay(1000);
	GPIO1_DATAOUT |= (0x01<<21);
	delay(1000);
	GPIO1_DATAOUT &= ~(0x01<<21 );
	
	GPIO1_SETDATAOUT = (0xFFFFFFFF);
	GPIO1_OE &=~(1<<21);
	
	while(1)
	{
		GPIO1_CLEARDATAOUT = (1<<21); 
		delay(500000);
		
		GPIO1_SETDATAOUT = (1<<21); 
		delay(500000);		
	}
}
