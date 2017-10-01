#include <stdint-gcc.h>
#include <avr/interrupt.h>
#include <string.h>
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

State panelState = None;
PanelToMainUnitPacketBytes panel;
uint8_t* pPanel = (uint8_t*)&panel;

State displayState = None;
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

            SendPanelPacket();
            panelState = ReadyToReceive;
        }
        
        if(displayState == Received)
        {
            //TODO: add logic here

            SendDisplayPacket();
            displayState = ReadyToReceive;
        }
    }

    return 0;
}
