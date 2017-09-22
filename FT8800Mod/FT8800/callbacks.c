#include "callbacks.h"
#include "uart.h"
#include "MainUnitToPanelPacketBytes.h"
#include "PanelToMainUnitPacketBytes.h"
#include <string.h>

extern PanelToMainUnitPacketBytes panel;
extern MainUnitToPanelPacketBytes display;

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
    if(buffer0.Index >= sizeof(PanelToMainUnitPacketBytes))
    {
        memcpy(&panel, buffer0.Data, sizeof(PanelToMainUnitPacketBytes));

        Reset(&buffer0);
    }
}

inline void OnFrameReceived1()
{
    if(buffer1.Index >= sizeof(MainUnitToPanelPacketBytes))
    {
        memcpy(&display, buffer1.Data, sizeof(MainUnitToPanelPacketBytes));

        Reset(&buffer1);
    }
}

inline void Reset(Buffer* buffer)
{
    memset(buffer->Data, 0, sizeof(buffer->Data));

    buffer->Index = 0;
}
