led.bin: start.o
	${CROSS_COMPILE}ld -Tled.lds -o led.elf $^
	${CROSS_COMPILE}objcopy -O binary led.elf led.bin
	${CROSS_COMPILE}objdump -D led.elf > led_elf.dis

%.o : %.S
	${CROSS_COMPILE}gcc -o $@ $< -c

%.o : %.c
	${CROSS_COMPILE}gcc -o $@ $< -c 

clean:
	rm *.o *.elf *.bin *.dis  -rf
