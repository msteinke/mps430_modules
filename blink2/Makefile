#for blink2
PROJ=blink
CC=msp430-gcc
MCU=msp430g2553
CFLAGS=-Os -g -Wall -mmcu=$(MCU)
LDFLAGS=-g -mmcu=$(MCU)

OBJS=$(PROJ).o

# Default target.
all: $(PROJ).elf


# Compile: create object files from C source files.
$(PROJ).o: $(PROJ).c ../modules/system.h
	$(CC) $(CFLAGS) -c $^

system.o: ../modules/system.c ../modules/system.h
	$(CC) $(CFLAGS) -c $^

# Link: create output file (executable) from object files.
$(PROJ).elf: $(PROJ).o system.o
	$(CC) $(LDFLAGS) -o $(PROJ).elf $^
	@echo  " "
	@echo  "--== Size of firmware ==--"
	msp430-size $(PROJ).elf
	@echo  " "

# Target: clean project.
.PHONY: clean
clean:
	@echo cleaning $<
#	rm -fr $(PROJ).elf $(OBJS)
	-rm *.o *.elf

# Target: program project.
.PHONY: flash
flash: all
	mspdebug rf2500 'erase' 'load $(PROJ).elf' 'exit'


