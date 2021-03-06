#include <stdint-gcc.h>
#include <string.h>
#include <avr/io.h>
#include "callbacks.h"
#include "uart.h"
#include "MainUnitToPanelPacketBytes.h"
#include "PanelToMainUnitPacketBytes.h"
#include "mux.h"
#include "state.h"

extern PanelToMainUnitPacketBytes panel;
extern MainUnitToPanelPacketBytes display;
extern enum State panelState;
extern enum State displayState;

//NOTE: all callbacks run in context of ISRs, see timer.c for more detailed information

inline void OnFrameReceived0()
{
    buffer0.Index = 0;

    unsigned int readValue = 0;
    while(1)
    {   // read existing
        readValue = uart_getc();
        if( readValue == UART_NO_DATA) { break; }
        buffer0.Data[buffer0.Index++] = readValue;
    }

    if(buffer0.Index < sizeof(panel)) { return; } // not enough data

    if(panelState == ReadyToReceive)
    {
        SetMuxBit0(1);
        memcpy(&panel, buffer0.Data, sizeof(panel));
        panelState = Received;
    }

    #ifdef MEASURE_TIMINGS
    PORTA ^= (1 << PINA4);
    #endif
}

inline void OnFrameReceived1()
{
    buffer1.Index = 0;

    unsigned int readValue = 0;
    while(1)
    {   // read existing
        readValue = uart1_getc();
        if( readValue == UART_NO_DATA) { break; }
        buffer1.Data[buffer1.Index++] = readValue;
    }

    if(buffer1.Index < sizeof(display)) { return; } // not enough data

    if(displayState == ReadyToReceive)
    {
        SetMuxBit1(1);
        memcpy(&display, buffer1.Data, sizeof(display));
        displayState = Received;
    }

    #ifdef MEASURE_TIMINGS
    PORTA ^= (1 << PINA6);
    #endif
}
