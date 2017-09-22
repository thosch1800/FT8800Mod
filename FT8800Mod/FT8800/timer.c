#include "timer.h"
#include "callbacks.h"
#include <avr/interrupt.h>

const uint8_t start0 = 0x30;
const uint8_t start2 = 0x20;

void InitializeTimer()
{
    TCCR0 =	(1 << CS01) | (1 << CS00);
    TCNT0 = start0;
    TIMSK |= (1 << TOIE0);

    TCCR2 =	(1 << CS22);
    TCNT2 = start2;
    TIMSK |= (1 << TOIE2);
}

inline void RestartTimer0()
{
    OnByteReceived0();
}

inline void RestartTimer2()
{
    OnByteReceived1();
}

ISR (TIMER0_OVF_vect)
{
    OnFrameReceived0();
}

ISR (TIMER2_OVF_vect)
{
    OnFrameReceived1();
}