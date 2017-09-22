#include "timer.h"
#include "callbacks.h"
#include <avr/io.h>
#include <avr/interrupt.h>

const uint8_t start0 = 0x30;
const uint8_t start2 = 0x20;

//#define MEASURE
//#define INDICATE

void InitializeTimer()
{
    TCCR0 =	(1 << CS01) | (1 << CS00);
    TCNT0 = start0;

    #ifdef MEASURE
    TIMSK |= (1 << TOIE0); // start timer immediately when measuring
    #endif

    TCCR2 =	(1 << CS22);
    TCNT2 = start2;

    #ifdef MEASURE
    TIMSK |= (1 << TOIE2); // start timer immediately when measuring
    #endif

    #ifdef INDICATE
    DDRA = 0xFF; // let port A be outputs
    PORTA = 0xFF; // set outputs to off
    #endif // INDICATE
}

void RestartTimer0()
{
    #ifdef MEASURE
    TCNT0 = start0; // reset timer
    TIMSK |= (1 << TOIE0);
    #endif // ifdef MEASURE

    #ifdef INDICATE
    PORTA ^= (1 << PA2); // toggle pin to indicate timer elapsed
    #endif

    OnByteReceived0();
}

void RestartTimer2()
{
    #ifdef MEASURE
    TCNT2 = start2; // reset timer
    TIMSK |= (1 << TOIE2);
    #endif // MEASURE

    #ifdef INDICATE
    PORTA ^= (1 << PA6); // toggle pin to indicate timer elapsed
    #endif

    OnByteReceived1();
}

ISR (TIMER0_OVF_vect)
{
    #ifdef MEASURE
    TCNT0 = start0; // restart timer immediately when measuring
    #endif

    #ifdef INDICATE
    PORTA ^= (1 << PA0); // toggle pin to indicate timer elapsed
    #endif

    OnFrameReceived0();
}

ISR (TIMER2_OVF_vect)
{
    #ifdef MEASURE
    TCNT2 = start2; // restart timer immediately when measuring
    #endif
    
    #ifdef INDICATE
    PORTA ^= (1 << PA4); // toggle pin to indicate timer elapsed
    #endif

    OnFrameReceived1();
}