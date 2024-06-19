//gph2-0  gph2-1 gph2-2 gph2-3
	#define GPH2_CON	(*(volatile unsigned long *)0xE0200C40)
	#define GPH2_DAT	(*(volatile unsigned long *)0xE0200C44)
	#define GPH2_PUD    (*(volatile unsigned long *)0xE0200C48)
	#define GPD0CON  	(*(volatile unsigned long *)0xE02000A0)

void clock_init(void);
void putc(char c);
void uart_init(void);
void putout(char * c);
int print(const char *fmt, ...);

static void Delay(int count)
{
    	volatile int i, j = 0;
    	volatile static int loop = 800000000/10000;
    	for(;count > 0;count--)
    		for(i=0;i < loop; i++) { j++; }
}

void main(void)
{
	int i;
	GPD0CON &= ~(0xF << 0);//关闭蜂鸣器

	GPH2_CON=(GPH2_CON & ~0x0000FFFF)| 0x00001111;//设置EINT16\EINT17\EINT18\EINT19为管脚为输出方式

	clock_init();
        uart_init();

	for( i=0;i<4;i++)//关闭led
	{
		GPH2_DAT |=  ( 1<< i);
		Delay(100000);	
	}
	
  	char print[40]={'l','e','d','1',' ','i','s',' ','o','n'};
  	char print1[40]={'l','e','d','1',' ','i','s',' ','o','f','f'};
	while(1)
	{

		for( i=0;i<4;i++)//循环点亮led 
		{       
      			print[3]= i+48;
			print1[3]= i+48;
			GPH2_DAT &= ~( 1<< i);            
      			putout(print);//输出打印信息  
			Delay(300000);	
			GPH2_DAT |= ( 1<< i);
      			putout(print1);// 输出打印信息
			Delay(300000);	
		}
	}

}

