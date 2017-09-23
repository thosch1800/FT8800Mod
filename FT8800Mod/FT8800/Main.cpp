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
    #include "uartUtils.h"
}

PanelToMainUnitPacketBytes panel;
MainUnitToPanelPacketBytes display;

int main()
{
    #ifdef MEASURE_TIMINGS
    DDRA = 0xFF; // use port A as output
    PORTA = 0xFF; // reset all pins
    #endif

    Controller controller;
    controller.SetMainUnitToPanelPacket(&display);
    controller.SetPanelToMainUnitPacket(&panel);

    InitializeTimer();
    InitializeUart();
    sei();

    DDRA = 0xFF; // use port A as output
    PORTA = 0xFF; // reset all pins

    while(true)
    {
        PORTA =
        ~(
        display.SignalLeftBar1 << PINA0 |
        display.SignalLeftBar2 << PINA1 |
        display.SignalLeftBar3 << PINA2 |
        display.SignalLeftBar4 << PINA3 |
        display.SignalLeftBar5 << PINA4 |
        display.SignalLeftBar6 << PINA5 |
        display.SignalLeftBar7 << PINA6 |
        display.SignalLeftBar8 << PINA7 
        );
    }

    return 0;
}