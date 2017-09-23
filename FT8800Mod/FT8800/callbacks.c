#include "callbacks.h"
#include "uart.h"
#include "MainUnitToPanelPacketBytes.h"
#include "PanelToMainUnitPacketBytes.h"
#include <string.h>

extern PanelToMainUnitPacketBytes panel;
extern MainUnitToPanelPacketBytes display;

//NOTE: all callbacks run in context of ISRs, see timer.c for more detailed information

inline void OnByteReceived0()
{
    buffer0.Data[buffer0.Index++] = uart_getc();
}

inline void OnByteReceived1()
{
    buffer1.Data[buffer1.Index++] = uart1_getc();
}

inline void OnFrameReceived0()
{
    if(buffer0.Index < sizeof(panel)) return; // continue collect data

    if(buffer0.Index == sizeof(panel)) memcpy(&panel, buffer0.Data, sizeof(panel)); // copy frame data

    buffer0.Index = 0; // reset index (no matter if packet received or not!)
}

inline void OnFrameReceived1()
{
    if(buffer1.Index < sizeof(display)) return; // continue collect data

    if(buffer1.Index == sizeof(display)) memcpy(&display, buffer1.Data, sizeof(display)); // copy frame data

    buffer1.Index = 0; // reset index (no matter if packet received or not!)
}
