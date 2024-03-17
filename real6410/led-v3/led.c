// LED1 对应于 GPIO GPL13口的控制寄存器地址 
#define rGPLCON1_RGE *((volatile unsigned long *)0x7F008814)
#define rGPLDAT_RGE     *((volatile unsigned long *)0x7F008818)
#define rGPLPUD_RGE     *((volatile unsigned long *)0x7F00881C)
// LED2 对应于 GPIO GPN6口的控制寄存器地址 
#define rGPNCON_RGE     *((volatile unsigned long *)0x7F008830)
#define rGPNDAT_RGE     *((volatile unsigned long *)0x7F008834)
#define rGPNPUD_RGE     *((volatile unsigned long *)0x7F008838)
// 延时
void msDelay()
{
	volatile int i = 0x100000;
	while (i--);

}
// LED1 电灯 灭灯
void LED1_SET(void)
{
	rGPLDAT_RGE  = 0x00;   // bit13 清零
}
void LED1_CLR(void)
{
	rGPLDAT_RGE  = 0x2000;   // bit13 置一
}

// LED2 电灯 灭灯
void LED2_SET(void)
{
	rGPNDAT_RGE  = 0x00;    // bit6 清零
}
void LED2_CLR(void)
{
	rGPNDAT_RGE  = 0x40;    // bit6 置一
}
 // 初始化 LED1 LED2 
 void GPIO_Init(void)
{
	rGPLCON1_RGE = 0x00100000;  // 设置 GPL13 为输出口
	LED1_CLR();
	rGPNCON_RGE  = 0x00001000;   // 设置 GPN6 为输出口
	LED2_CLR();
}


int main(void)
{
	GPIO_Init();
		while(1)
	{
		LED1_SET();
		LED2_CLR();
		msDelay();
		LED2_SET();
		LED1_CLR();
		msDelay(); 
	}

	return 0;
}