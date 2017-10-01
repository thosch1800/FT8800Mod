#include <avr/io.h>
#include "utilities.h"
#include "uart.h"

extern PanelToMainUnitPacketBytes panel;
extern MainUnitToPanelPacketBytes display;
extern uint8_t* pPanel;
extern uint8_t* pDisplay;

inline void InitializeUart()
{
    uart_init(UART_BAUD_SELECT(19200UL, F_CPU));
    uart1_init(UART_BAUD_SELECT(19200UL, F_CPU));
}

inline void SetPortAPin(uint8_t pin, uint8_t state)
{
    if(state)
    PORTA &= ~(1 << pin);
    else
    PORTA |=  (1 << pin);
}

inline void SendPanelPacket()
{
    for(uint8_t i = 0; i < sizeof(panel); ++i)
    {
        uart_putc(pPanel[i]);
    }
}

inline void SendDisplayPacket()
{
    for(uint8_t i = 0; i < sizeof(display); ++i)
    {
        uart1_putc(pDisplay[i]);
    }
}