CC      = $(CROSS_COMPILE)gcc
AR      = $(CROSS_COMPILE)ar

CFLAGS 		:= -Wall -O2 -fno-builtin
CPPFLAGS   	:= -nostdinc

objs := div64.o lib1funcs.o ctype.o muldi3.o printf.o string.o vsprintf.o

libc.a: $(objs)
	${AR} -r -o $@ $^
	
%.o:%.c
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

%.o:%.S
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

clean:
	rm -f libc.a *.o		
	
