#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include <stdlib.h>
#include "timer.h"

void init(void);

extern volatile uint8_t cnt;

int main(void) {
	init();

	/* Main loop */
	while (1) {
		/* Output the counter on the upper 4 LEDS
 		 * and the status of the switches on the lower 4 LEDS
 		 */
		PORTB = ~((cnt << 4) | (~PINA & 0x0F));
	}
	
	exit(0);
}

void init(void) {
	/* Initialize IO registers */
	DDRA = 0x00;
	DDRB = 0xFF;

	/* Initialize subsystems */
	timerInit();

	/* Enable interrupts */
	sei();

	return;
}
