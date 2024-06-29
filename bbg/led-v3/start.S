.text
.global  _start
_start: 				


	
@设置栈
//
	ldr  sp,=0x4030ce00
		
//
	bl  main

halt:
	b  halt 




