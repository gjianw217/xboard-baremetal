CROSS_COMPILE?=arm-linux-

TARGET=led

CFLAG=-c
LDFLAG=-e _start -Ttext 0x0c000000

CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=${CROSS_COMPILE}objdump


all: $(TARGET).dis $(TARGET).bin


$(TARGET).dis: $(TARGET)
	$(OBJDUMP) -D $(TARGET) > $(TARGET).dis

$(TARGET).bin: $(TARGET)
	$(OBJCOPY) -O binary $< $@

# start.o 必须在最前面
$(TARGET): start.o $(TARGET).o
	$(LD) $(LDFLAG) $? -o $@

%.o:%.S
	$(CC) $(CFLAG) $< -o $@

flash:$(TARGET).bin $(SDCARD)
	#$(FLASH) ./$(TARGET).bin $(SDCARD)
	@if [ $(shell du -b $(TARGET).bin|cut -f1) -le 8192 ];then \
	$(FLASH) $(TARGET).bin $(SDCARD); \
	else \
	echo bin file is lager than 8192,size is $(shell du -b $(TARGET).bin|cut -f1); \
	fi \

clean:
	rm *.o $(TARGET) $(TARGET).bin $(TARGET).dis  -f