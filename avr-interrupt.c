#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include <stdlib.h>
#include "timer.h"

void init(void);

extern volatile uint8_t cnt;

int main(void) {
	init();

	while (1) {
		PORTB = ~((cnt << 4) | (~PINA & 0x0F));
	}
	
	exit(0);
}

void init(void) {
	DDRA = 0x00;
	DDRB = 0xFF;

	timerInit();

	sei();

	return;
}
