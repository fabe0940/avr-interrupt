#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

extern volatile uint8_t cnt;
volatile uint8_t overflowCnt;

void timerInit(void) {
	TCCR0 = (TCCR0 & ~PRESCALER_MASK) | PRESCALER_256;
	TIMSK |= (1 << TOIE0);
	TCNT0 = 0x00;

	cnt = 0;
	overflowCnt = 0;

	return;
}

ISR(TIMER0_OVF_vect) {
	if (!(++overflowCnt % OVERFLOWS_PER_SECOND)) cnt++;
}
