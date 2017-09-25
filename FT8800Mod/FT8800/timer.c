#include "timer.h"
#include "callbacks.h"
#include <avr/interrupt.h>

#ifdef MEASURE_TIMINGS
#include <avr/io.h>
#endif

void InitializeTimer()
{
    TIMSK |= (1 << TOIE2); // enable timer 2 interrupt
    TIMSK |= (1 << TOIE0); // enable timer 0 interrupt
}

// running in context of ISR(UART0_RECEIVE_INTERRUPT)
inline void OnByteReceivedUart0()
{
    TCNT2 = 0x70; // set timer 2 start value
    TCCR2 = (1 << CS22); // start timer 2

    #ifdef MEASURE_TIMINGS
    PORTA &= ~(1 << PINA2); // reset pin
    #endif
}

// running in context of ISR(UART1_RECEIVE_INTERRUPT)
inline void OnByteReceivedUart1()
{
    TCNT0 = 0x85; // set timer 0 start value
    TCCR0 = (1 << CS01) | (1 << CS00); // start timer 0

    #ifdef MEASURE_TIMINGS
    PORTA &= ~(1 << PINA0); // reset pin
    #endif
}

ISR (TIMER2_OVF_vect)
{
    TCCR2 &= ~((1 << CS22) | (1 << CS21) | (1 << CS20)); // stop timer 2

    #ifdef MEASURE_TIMINGS
    PORTA |= (1 << PINA2); // set pin
    #endif

    OnFrameReceived0();
}

ISR (TIMER0_OVF_vect)
{
    TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00)); // stop timer 0

    #ifdef MEASURE_TIMINGS
    PORTA |= (1 << PINA0); // set pin
    #endif

    OnFrameReceived1();
}

