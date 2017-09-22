#include "timer.h"
#include "callbacks.h"
#include <avr/io.h>

const uint8_t start0 = 0x30;
const uint8_t start2 = 0x20;
const uint8_t measure = 0;
const uint8_t indicate = 1;

void InitializeTimer()
{
	TCCR0 =	(1 << CS01) | (1 << CS00);
	TCNT0 = start0;
	if(measure) TIMSK |= (1 << TOIE0); // start timer immediately when measuring

	TCCR2 =	(1 << CS22);
	TCNT2 = start2;
	if(measure) TIMSK |= (1 << TOIE2); // start timer immediately when measuring

	if(indicate)
	{
		DDRA = 0xFF; // let port A be outputs
		PORTA = 0xFF; // set outputs to off
	}
}

void RestartTimer0()
{
	if(!measure)
	{	// reset timer
		TCNT0 = start0;
		TIMSK |= (1 << TOIE0);
	}
	if(indicate) PORTA ^= (1 << PA2); // toggle pin to indicate timer elapsed

	OnByteReceived0();
}

void RestartTimer2()
{
	if(!measure)
	{	// reset timer
		TCNT2 = start2;
		TIMSK |= (1 << TOIE2);
	}
	if(indicate) PORTA ^= (1 << PA6); // toggle pin to indicate timer elapsed

	OnByteReceived1();
}

ISR (TIMER0_OVF_vect)
{
	if(measure) TCNT0 = start0; // restart timer immediately when measuring
	if(indicate) PORTA ^= (1 << PA0); // toggle pin to indicate timer elapsed

	OnFrameReceived0();
}

ISR (TIMER2_OVF_vect)
{
	if(measure) TCNT2 = start2; // restart timer immediately when measuring
	if(indicate) PORTA ^= (1 << PA4); // toggle pin to indicate timer elapsed

	OnFrameReceived1();
}