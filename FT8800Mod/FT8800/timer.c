#include "timer.h"
#include "callbacks.h"
#include <avr/interrupt.h>

//#define MEASURE_TIMINGS

#ifdef MEASURE_TIMINGS
#include <avr/io.h>
#endif

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

#ifdef MEASURE_TIMINGS
    // toggle pin: measure timings
    DDRA = 0xFF; // use port A as output
    PORTA = 0xFF; // reset all pins
#endif
}

inline void RestartTimer0()
{
    TCNT0 = start0;

    OnByteReceived0();
}

inline void RestartTimer2()
{
    TCNT2 = start2;

    OnByteReceived1();
}

ISR (TIMER0_OVF_vect)
{
#ifdef MEASURE_TIMINGS
    PORTA ^= 1 << PINA0;
#endif

    OnFrameReceived0();
}

ISR (TIMER2_OVF_vect)
{
#ifdef MEASURE_TIMINGS
    PORTA ^= 1 << PINA2;
#endif

    OnFrameReceived1();
}