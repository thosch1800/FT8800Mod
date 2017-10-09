#include "modem.h"

#include <avr/io.h>

inline void InitializeModem()
{
    DDRC |= 0x04;

    SetDataPTT(0);
}

uint8_t IsModemPTT()
{
    return PINC & PINC3 != 0;
}

void SetDataPTT(uint8_t active)
{
    if(active)
    PORTC |=  (1 << PINC2);
    else
    PORTC &= ~(1 << PINC2);
}

