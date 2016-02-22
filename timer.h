#ifndef _TIMER_H_
#define _TIMER_H_

#include <avr/io.h>
#include <inttypes.h>

#define DELAY_ONE_SECOND 24
#define PRESCALER_MASK ((1<<CS02)|(1<<CS01)|(1<<CS00))
#define PRESCALER_NONE ((0<<CS02)|(0<<CS01)|(0<<CS00))
#define PRESCALER_1    ((0<<CS02)|(0<<CS01)|(1<<CS00))
#define PRESCALER_8    ((0<<CS02)|(1<<CS01)|(0<<CS00))
#define PRESCALER_64   ((0<<CS02)|(1<<CS01)|(1<<CS00))
#define PRESCALER_256  ((1<<CS02)|(0<<CS01)|(0<<CS00))
#define PRESCALER_1024 ((1<<CS02)|(0<<CS01)|(1<<CS00))

volatile uint32_t timer;
void timerInit(void);
void timerStart(void);
void timerEnd(void);

#endif /* _TIMER_H_ */
