
.global _start
_start:
	//设置CPU
	ldr r0,=0x70000000
	orr r0,r0,#0x13			@0x13=b10011=256M, 参见arm1176jzfs内核参考手册Page3-130
	mcr p15,0,r0,c15,c2,4 	@把r0的值(包括了外设基地址+外设大小)告诉cpu
	//关看门狗
	ldr r0,=0x7E004000
	mov r1,#0				@disable watch dog
	str r1,[r0]
	//设置LED1
	ldr r0,=0x7F008814 
	ldr r1,[r0]  
	bic r1,r1,#0x00F00000  
	orr r1,r1,#0x00100000  @设置GPL13为输出
	str r1,[r0]
	ldr r0,=0x7F008818 
	ldr r1,[r0]  
	orr r1,r1,#0x00002000 @设置GPL13为输出为高电平
	str r1, [r0]
	ldr r0,=0x7F00881C
	ldr r1,[r0]  
	bic r1,r1,#0x0B000000
	orr r1,r1,#0x0A000000 @设置GPL13为上拉
	str r1, [r0]
	//设置LED2
	ldr r0,=0x7F008830
	ldr r1,[r0]  
	bic r1,r1,#0x0000F000  
	orr r1,r1,#0x00001000 @设置GPN6为输出
	str r1, [r0]
	ldr r0,=0x7F008834
	ldr r1,[r0] 
	orr r1,r1,#0x00000040 @设置GPN6为输出为高电平
	str r1, [r0]
	ldr r0,=0x7F008838
	ldr r1,[r0]  
	bic r1,r1,#0x00003000
	orr r1,r1,#0x00002000 @设置GPN6为上拉
	str r1, [r0]
	mov r2, #0x1000			//LED循环计数
light_on:
	ldr r0,=0x7F008818
	ldr r1,[r0]  
	bic r1,r1,#0x00002000 @设置GPL13为输出为低电平
	str r1, [r0]
	ldr r0,=0x7F008834 
	ldr r1,[r0]  
	orr r1,r1,#0x00000040 @设置GPN6为输出为高电平
	str r1, [r0]
	bl delay
light_off:
	ldr r0,=0x7F008818 
	ldr r1,[r0] 
	orr r1,r1,#0x00002000 @设置GPL13为输出为高电平
	str r1, [r0]
	ldr r0,=0x7F008834 
	ldr r1,[r0]  
	bic r1,r1,#0x00000040 @设置GPN6为输出为低电平
	str r1, [r0]
	bl delay 
	sub r2, r2, #1	
	cmp r2, #0
	bne light_on
	
halt:
	b   halt
delay:
	mov r0, #0x1000000	
delay_loop:
	sub r0,r0,#1
	cmp r0,#0
	bne delay_loop 
	mov pc,lr			@从delay子程序返回
	