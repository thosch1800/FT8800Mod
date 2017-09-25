#include <stdint-gcc.h>
#include <avr/interrupt.h>
#include "Controller.h"

extern "C"
{
    #include "MainUnitToPanelPacketBytes.h"
    #include "PanelToMainUnitPacketBytes.h"
    #include "callbacks.h"
    #include "timer.h"
    #include "uart.h"
    #include "utilities.h"
}

PanelToMainUnitPacketBytes panel;
MainUnitToPanelPacketBytes display;

int main()
{
    Controller controller;
    controller.SetMainUnitToPanelPacket(&display);
    controller.SetPanelToMainUnitPacket(&panel);

    InitializeTimer();
    InitializeUart();

    sei();

    DDRA = 0xFF; // use port A as output
    PORTA = 0x0; // reset all pins

    while(true)
    {
        SetPortAPin(PINA0, controller.IsMain(true));
        SetPortAPin(PINA1, controller.IsMain(false));
        SetPortAPin(PINA2, controller.IsBusy(true));
        SetPortAPin(PINA3, controller.IsBusy(false));
        SetPortAPin(PINA4, controller.IsVfoMode(true));
        SetPortAPin(PINA5, controller.IsVfoMode(false));
        SetPortAPin(PINA6, controller.IsInInputMode(true));
        SetPortAPin(PINA7, controller.IsInInputMode(false));
    }

    while(true) { }
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
