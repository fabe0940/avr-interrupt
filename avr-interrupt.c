#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include <stdlib.h>
#include "timer.h"

uint8_t state;
uint32_t delay;
void init(void);

int main(void) {
	init();

	while (1) {
		PORTB = 0x00;
	}
	
	exit(0);
}

void init(void) {
	timerInit();

	DDRB = 0xFF;
}
