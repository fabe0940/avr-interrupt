APPLICATION_NAME := avr-interrupt
CC := avr-gcc
CFLAGS := -mmcu=atmega32 -O0
SRC := $(wildcard *.c)
OBJ := $(patsubst %.c, %.o, $(SRC))

DEV := /dev/ttyS0

CLOCK_1MHz = 0xE1
CLOCK_2MHz = 0xE2
CLOCK_4MHz = 0xE3
CLOCK_8MHz = 0xE4

.PHONY : all install clock clean rebuild

all : $(APPLICATION_NAME)

install : $(APPLICATION_NAME) clock
	avrdude -q -q -p atmega32 -P $(DEV) -c stk500v2 \
		-U lfuse:w:$(CLOCK_1MHz):m \
		-U flash:w:$(APPLICATION_NAME).hex:i

$(APPLICATION_NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	objcopy -S -O ihex $(APPLICATION_NAME) $(APPLICATION_NAME).hex

%.o : %.c
	$(CC) $(CFLAGS) -c $<

avr-interrupt.c : timer.h
timer.c : timer.h

clean :
	\rm -f $(APPLICATION_NAME) $(APPLICATION_NAME).hex $(OBJ)

rebuild :
	make clean
	make all
