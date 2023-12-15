# makefile configuration

COMMON_OBJECTS  = main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../demos/h #-I../../f23-org-video-SophiaMontenegro/h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf

#additional rules for files
button.elf: ${COMMON_OBJECTS} stateMachines.o interrupt_handler.o led.o switches.o main.o ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ 

load: button.elf
	msp430loader.sh button.elf $^

clean:
	rm -f *.o *.elf

led.o: led.c led.h

interrupt_handler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h

switches.o: led.h switches.h
