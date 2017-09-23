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
    Controller controller;
    controller.SetMainUnitToPanelPacket(&display);
    controller.SetPanelToMainUnitPacket(&panel);

    InitializeTimer();
    InitializeUart();
    sei();

    while(true);

    return 0;
}