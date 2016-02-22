#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

extern volatile uint8_t cnt;
volatile uint8_t overflowCnt;

void timerInit(void) {
	/* Initialize TIMER0 to use the overflow ISR */
	TCCR0 = (TCCR0 & ~PRESCALER_MASK) | PRESCALER_256;
	TIMSK |= (1 << TOIE0);
	TCNT0 = 0x00;

	/* Initialize subsystem values */
	cnt = 0;
	overflowCnt = 0;

	return;
}

/* TIMER0 Overflow ISR */
ISR(TIMER0_OVF_vect) {
	/* Increment overflowCnt. Additionally, increment cnt if overflowCnt is
	 * a multiple of OVERFLOWS_PER_SECOND
	 */
	if (!(++overflowCnt % OVERFLOWS_PER_SECOND)) cnt++;
}
