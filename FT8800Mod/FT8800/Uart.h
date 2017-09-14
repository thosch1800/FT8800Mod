#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>

class Uart
{
    public: void Write(uint8_t data);
    public: void Write(uint8_t data*, uint8_t dataLength);
    
    
}

#endif
