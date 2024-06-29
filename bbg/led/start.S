
/* start.S */
.global _start
_start: 

	ldr r0, =0x44E000AC		/*gpio1时钟使能 CM_PER_GPIO1_CLKCTRL */
	ldr r1, =0x40002
	str r1, [r0]
	
	ldr r0, =0x44E10854        	/* GPMC_A5)寄存器 */
	ldr r1, =0x0000001F        	/* GPIO1_21引脚配置，输出上拉，模式7=gpio*/
	str r1, [r0]               
	
	ldr r0, =0x4804C134        	/* GPIO1_OE寄存器 */
	ldr r1, =0xffdfffff         	/*GPIO1_21引脚输出使能*/
	str r1, [r0]            
	
	ldr r0, =0x4804C194		/*GPIO1_SETDATAOUT寄存器*/
	ldr r1, =0x00200000		/*GPIO1_21引脚允许输出*/
	str r1, [r0]	
	
	ldr r0, =0x4804C13C        	/* GPIO1 DATAOUT寄存器 */
	ldr r1, =0x00200000        	/*GPIO1_21设置输出值*/
	str r1, [r0] 			 
	
	ldr r0, =0x4804C194		
	ldr r1, =0xFFFFFFFF	
	str r1, [r0]	
	
	ldr r0, =0x4804C134        
	ldr r1, =0xffdfffff         
	str r1, [r0]            
	
	
	mov r2, #0x1000			//LED循环计数
led_blink:
	ldr r0, =0x4804C194		/*GPIO1_21值为1*/
	ldr r1, =0x00200000	
	str r1, [r0]	
	bl  delay	
	ldr r0, =0x4804C190		/*GPIO1_21值为0*/
	ldr r1, =0x00200000			
	str r1, [r0]
	bl  delay
	sub r2, r2, #1	
	cmp r2, #0
	bne led_blink			// 循环闪烁
halt:
	b   halt				
delay:
	mov r0, #0x1000000	
delay_loop:		
	sub r0, r0, #1
	cmp r0, #0
	bne delay_loop
	mov pc, lr			//从delay子程序返回
	
