
/* start.S */

.global _start
_start: 		
	ldr r0, =0xE0200C40		//GPH2CON address
	ldr r1, =0x00001000		//EINT19引脚设置为输出
	str r1, [r0]
	mov r2, #0x1000			//LED循环计数
led_blink:
	ldr r0, =0xE0200C44		//GPH2DAT address
	mov r1, #0x8			//设置EINT19为高电平，Led熄灭
	str r1, [r0]	
	bl  delay	
	ldr r0, =0xE0200C44
	mov r1, #0x0000			//设置GPL13为低电平，Led点亮
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
	mov pc, lr				//从delay子程序返回
	
