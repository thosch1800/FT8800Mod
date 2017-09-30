#include <stdint-gcc.h>
#include <avr/interrupt.h>
#include "Controller.h"

extern "C"
{
    #include "state.h"
    #include "MainUnitToPanelPacketBytes.h"
    #include "PanelToMainUnitPacketBytes.h"
    #include "callbacks.h"
    #include "timer.h"
    #include "uart.h"
    #include "utilities.h"
    #include "mux.h"
}

State panelState;
PanelToMainUnitPacketBytes panel;
uint8_t* pPanel = (uint8_t*)&panel;

State displayState;
MainUnitToPanelPacketBytes display;
uint8_t* pDisplay = (uint8_t*)&display;

int main()
{
    Controller controller(&panel, &display);
    InitializeTimer();
    InitializeUart();
    InitializeMux();

    sei();

    panelState = ReadyToReceive;
    displayState = ReadyToReceive;

    while(true)
    {
        if(panelState == Received)
        {
            //TODO: add logic here

            for(uint8_t i = 0; i < sizeof(panel); ++i) uart_putc(pPanel[i]);
            panelState = ReadyToReceive;
        }
        
        if(displayState == Received)
        {
            //TODO: add logic here

            for(uint8_t i = 0; i < sizeof(display); ++i) uart1_putc(pDisplay[i]);
            displayState = ReadyToReceive;
        }
    }

    return 0;
}

/*
Requirements:
- do not miss a panel packet because it would "eat up" user input
- display packets can be dropped, because they will be repeated

Interrupt priority:
12 0x016 TIMER2 OVF Timer/Counter2 Overflow
18 0x022 TIMER0 OVF Timer/Counter0 Overflow
20 0x026 USART0, RXC USART0, Rx Complete
21 0x028 USART1, RXC USART1, Rx Complete

Conclusion:
Timer2 for USART0 to handle the panel packets
Timer0 for USART1 to handle display packets

Whenever a byte was received by UART we start the corresponding timer.
Thus if the following byte is received until the timer overflowed the timer is reset.
If there is no byte received within the timer period we assume a complete frame.




changes made to uart.h/uart.c

uart.h:
increased buffer size
#define UART_TX_BUFFER_SIZE 128

uart.c:
added callbacks to ISRs
ISR (UART0_RECEIVE_INTERRUPT) => OnByteReceivedUart0();
ISR (UART1_RECEIVE_INTERRUPT) => OnByteReceivedUart1();
*/
