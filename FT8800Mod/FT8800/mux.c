#include "mux.h"
#include <avr/io.h>

void InitializeMux()
{
    DDRC = 0x03;

    SetMuxBit0(0);
    SetMuxBit1(0);
}

inline void SetMuxBit0(uint8_t state)
{
    SetPortCPin(PINC0, state);
}

inline void SetMuxBit1(uint8_t state)
{
    SetPortCPin(PINC1, state);
}

inline void SetPortCPin(uint8_t pin, uint8_t state)
{
    if(state)
    PORTC |=  (1 << pin);
    else
    PORTC &= ~(1 << pin);
}
