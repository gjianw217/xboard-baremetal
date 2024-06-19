
#define MP0_4CON	(*(volatile unsigned long *)0xE0200340)
#define MP0_4DAT	(*(volatile unsigned long *)0xE0200344)
#define GPD0CON  	(*(volatile unsigned long *)0xE02000A0)
#define GPD0DAT		(*(volatile unsigned long *)0xE02000A4)
#define GPA0CON 	(*(volatile unsigned long *)0xE0200000)		
#define GPA1CON 	(*(volatile unsigned long *)0xE0200020)

// clock

#define APLL_LOCK 	(*(volatile unsigned long *)0xE0100000)	
#define MPLL_LOCK 	(*(volatile unsigned long *)0xE0100008)
#define APLL_CON0 	(*(volatile unsigned long *)0xE0100100)
#define APLL_CON1 	(*(volatile unsigned long *)0xE0100104)
#define MPLL_CON 	(*(volatile unsigned long *)0xE0100108)
#define CLK_SRC0 	(*(volatile unsigned long *)0xE0100200)
#define CLK_SRC1 	(*(volatile unsigned long *)0xE0100204)
#define CLK_SRC2 	(*(volatile unsigned long *)0xE0100208)
#define CLK_SRC3 	(*(volatile unsigned long *)0xE010020c)
#define CLK_SRC4 	(*(volatile unsigned long *)0xE0100210)
#define CLK_SRC5 	(*(volatile unsigned long *)0xE0100214)
#define CLK_SRC6 	(*(volatile unsigned long *)0xE0100218)
#define CLK_SRC_MASK0 	(*(volatile unsigned long *)0xE0100280)
#define CLK_SRC_MASK1 	(*(volatile unsigned long *)0xE0100284)
#define CLK_DIV0 	(*(volatile unsigned long *)0xE0100300)
#define CLK_DIV1 	(*(volatile unsigned long *)0xE0100304)
#define CLK_DIV2 	(*(volatile unsigned long *)0xE0100308)
#define CLK_DIV3 	(*(volatile unsigned long *)0xE010030c)
#define CLK_DIV4 	(*(volatile unsigned long *)0xE0100310)
#define CLK_DIV5 	(*(volatile unsigned long *)0xE0100314)
#define CLK_DIV6 	(*(volatile unsigned long *)0xE0100318)
#define CLK_DIV7 	(*(volatile unsigned long *)0xE010031c)
#define CLK_DIV0_MASK	0x7fffffff
#define APLL_MDIV       0x7d
#define APLL_PDIV       0x3
#define APLL_SDIV      	0x1
#define MPLL_MDIV	0x29b
#define MPLL_PDIV	0xc
#define MPLL_SDIV	0x1
#define set_pll(mdiv, pdiv, sdiv)	(1<<31 | mdiv<<16 | pdiv<<8 | sdiv)
#define APLL_VAL		set_pll(APLL_MDIV,APLL_PDIV,APLL_SDIV)
#define MPLL_VAL		set_pll(MPLL_MDIV,MPLL_PDIV,MPLL_SDIV)
//#define PLL_OFF
// UART

#define ULCON2 			(*(volatile unsigned long *)0xE2900800)
#define UCON2			(*(volatile unsigned long *)0xE2900804)
#define UFCON2			(*(volatile unsigned long *)0xE2900808)
#define UMCON2			(*(volatile unsigned long *)0xE290080C)
#define UFSTAT2 		(*(volatile unsigned long *)0xE2900818)
#define UBRDIV2 		(*(volatile unsigned long *)0xE2900828)
#define UDIVSLOT2		(*(volatile unsigned long *)0xE290082C)
#define UTXH2			(*(volatile unsigned long *)0xE2900820)
#define URXH2 			(*(volatile unsigned long *)0xE2900824)
#define UTRSTAT2 		(*(volatile unsigned long *)0xE2900810)

void clock_init(void)
{
    CLK_SRC0 = 0x0;// close PLL
    APLL_LOCK= 0x0000FFFF; 
    MPLL_LOCK = 0x0000FFFF;    	 	
    APLL_CON0 =APLL_VAL; //FOUT= MDIV * FIN / (PDIV*2^(SDIV-1)) = 0x7d*24/(0x3*2^(1-1))=1000 MHz	
    MPLL_CON = MPLL_VAL;// FOUT = MDIV*FIN/(PDIV*2^SDIV)=0x29b*24/(0xc*2^1)= 667 MHz		
    CLK_SRC0= 0x10001111;// FOUT = MDIV*FIN/(PDIV*2^SDIV)=0x29b*24/(0xc*2^1)= 667 MHz	
}

void uart_init(void)
{
    GPA0CON= 0x22222222;
    GPA1CON= 0x2222;//配置引脚为RX/TX功能
    UFCON2= 0x1;//使能FIFO
    UMCON2= 0x0;//无流控	
    ULCON2= 0x3;//数据位8,无校验,停止位1
    UCON2= 0x5; //时钟为PCLK，禁止中断，使能UART收 发
    UBRDIV2= 35;//设置波特率 				
    UDIVSLOT2= 0x1;  
}

// 接收一个字符 
char getc(void)
{
	// 如果RX FIFO空，等待
	while (!(UTRSTAT2 & (1<<0)));
	// 取数据
	return URXH2;                   	
}
void putc(char c)
{
	// 如果TX FIFO满，等待
	while (!(UTRSTAT2 & (1<<2)));
	// 写数据
	UTXH2 = c;                      	
}
void putout(char * c)
{
	// 如果TX FIFO满，等待
        char *b =c;
        while (*b!= '\0')
	{
		while (!(UTRSTAT2 & (1<<2)));
		// 写数据
		UTXH2 = *b;   
        	b++;
	}
	while (!(UTRSTAT2 & (1<<2)));
	// 写数据
	UTXH2 = '\r';  
	while (!(UTRSTAT2 & (1<<2)));
	// 写数据
	UTXH2 = '\n';  
	
	                     	
}
