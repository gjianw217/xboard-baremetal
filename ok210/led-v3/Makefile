CC      = $(CROSS_COMPILE)gcc
LD      = $(CROSS_COMPILE)ld
AR      = $(CROSS_COMPILE)ar
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump

INCLUDEDIR 	:= $(shell pwd)/include
CFLAGS 		:= -Wall -O2 -fno-builtin
CPPFLAGS   	:= -nostdinc -I$(INCLUDEDIR)


CFLAGS 		:= -Wall -O2 -fno-builtin -ffreestanding -nostdlib

led.bin: init.o main.o uart.o lib/libc.a 
	$(LD) -Ttext 0xD0020010 -o led.elf $^
	$(OBJCOPY) -O binary led.elf $@
	$(OBJDUMP) -D led.elf > led_elf.dis

%.o : %.S
	$(CC) $(CFLAGS) -o $@ $< -c

%.o : %.c
	$(CC) $(CFLAGS) -o $@ $< -c 

.PHONY : lig/libc.a
lib/libc.a:
	cd lib; make; cd ..
clean:
	rm *.o *.elf *.bin *.dis -f
