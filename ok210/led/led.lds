/* led.lds */

SECTIONS
{
	. = 0xD0020010;			/*BL1 start address*/
	.text : {
				start.o
				* (.text)
	}
	.data : {
				* (.data)
	}
	.bss_start = .;
	.bss : {
				* (.bss)
	}
	.bss_end = .;
}
