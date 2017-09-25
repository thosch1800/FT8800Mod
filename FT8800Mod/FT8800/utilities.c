#include <avr/io.h>
#include "utilities.h"
#include "uart.h"

void InitializeUart()
{
    uart_init(UART_BAUD_SELECT(19200UL, F_CPU));
    uart1_init(UART_BAUD_SELECT(19200UL, F_CPU));
}

void SetPortAPin(uint8_t pin, uint8_t state)
{
    if(state)
    PORTA &= ~(1 << pin);
    else
    PORTA |=  (1 << pin);
}
