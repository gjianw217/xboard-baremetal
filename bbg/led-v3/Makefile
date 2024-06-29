#PREFIX=arm-none-linux-gnueabi-
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
AR=$(CROSS_COMPILE)ar
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump

INCLUDEDIR 	:= $(shell pwd)/include/

CPPFLAGS   	:= -nostdlib -I$(INCLUDEDIR) 
# Add GCC lib
PLATFORM_LIBS += -L $(shell dirname `$(CC) $(CFLAGS) -print-libgcc-file-name`) -lgcc
#PLATFORM_LIBS += -L $(shell dirname `$(CC) $(CFLAGS) -print-libgcc-file-name`) 

#生成的目标文件名
TARGET   	:=am335x_hardware

#要编译的文件名

objs := start.o   delay.o  led.o  main.o 


$(TARGET).bin : $(objs)
	$(LD)   -Ttext 0x402F0400   -static -g  -o $(TARGET)_elf  $^   $(PLATFORM_LIBS)
	$(OBJCOPY) -O binary -S $(TARGET)_elf  $@
	$(OBJDUMP) -D -m arm  $(TARGET)_elf > $(TARGET).dis	

.PHONY : lib/libc.a
lib/libc.a:
	cd lib; make; cd ..
	
%.o:%.c
	$(CC) $(CPPFLAGS) -Wall  -g -c -o $@ $<

%.o:%.S
	$(CC) $(CPPFLAGS) -Wall  -g -c -o $@ $<	
	
clean:
	rm -f *.dis  *.bin  *.o  MLO *_elf


	
