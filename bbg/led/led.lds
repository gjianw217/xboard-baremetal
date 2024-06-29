/* led.lds */

SECTIONS
{
	. = 0x402F0400;			/*BL1 start address*/
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
