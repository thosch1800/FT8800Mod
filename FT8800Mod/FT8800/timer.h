#ifndef TIMER_H_
#define TIMER_H_

#include <avr/interrupt.h>

void InitializeTimer();

void RestartTimer0();
void RestartTimer2();

#endif /* TIMER_H_ */