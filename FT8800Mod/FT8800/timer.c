#include "timer.h"
#include "callbacks.h"
#include <avr/interrupt.h>

// uncomment following line to enable measurement
// timer0 interrupt (frame complete) PinA0
// timer2 interrupt (frame complete) PinA2
//#define MEASURE_TIMINGS

#ifdef MEASURE_TIMINGS
#include <avr/io.h>
#endif

void InitializeTimer()
{
    TIMSK |= (1 << TOIE0); // enable timer 0 interrupt
    TIMSK |= (1 << TOIE2); // enable timer 2 interrupt

#ifdef MEASURE_TIMINGS
    DDRA = 0xFF; // use port A as output
    PORTA = 0xFF; // reset all pins
#endif
}

// running in context of ISR(UART0_RECEIVE_INTERRUPT)
inline void RestartTimer0()
{
    TCNT0 = 0x85; // set timer start value
    TCCR0 = (1 << CS01) | (1 << CS00); // start timer

#ifdef MEASURE_TIMINGS
    PORTA |= (1 << PINA0); // set pin
#endif

    OnByteReceived0();
}

// running in context of ISR(UART1_RECEIVE_INTERRUPT)
inline void RestartTimer2()
{
    TCNT2 = 0x70; // set timer start value
    TCCR2 = (1 << CS22); // start timer

#ifdef MEASURE_TIMINGS
    PORTA |= (1 << PINA2); // set pin
#endif

    OnByteReceived1();
}

ISR (TIMER0_OVF_vect)
{
    TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00)); // stop timer

#ifdef MEASURE_TIMINGS
    PORTA &= ~(1 << PINA0); // reset pin
#endif

    OnFrameReceived0();
}

ISR (TIMER2_OVF_vect)
{
    TCCR2 &= ~((1 << CS22) | (1 << CS21) | (1 << CS20)); // stop timer

#ifdef MEASURE_TIMINGS
    PORTA &= ~(1 << PINA2); // reset pin
#endif

    OnFrameReceived1();
}