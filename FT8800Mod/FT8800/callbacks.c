#include "callbacks.h"
#include "uart.h"
#include "MainUnitToPanelPacketBytes.h"
#include "PanelToMainUnitPacketBytes.h"

extern PanelToMainUnitPacketBytes panel;
extern MainUnitToPanelPacketBytes display;

void OnByteReceived0()
{
    TakeLock(&buffer0);
    
    buffer0.Data[buffer0.Index++] = uart_getc();
    
    ReleaseLock(&buffer0);
}

void OnByteReceived1()
{
    TakeLock(&buffer1);

    buffer1.Data[buffer1.Index++] = uart1_getc();

    ReleaseLock(&buffer1);
}

void OnFrameReceived0()
{
    if(buffer0.Index >= sizeof(PanelToMainUnitPacketBytes))
    {
        TakeLock(&buffer0);

        memcpy_P(&panel, buffer0.Data, sizeof(PanelToMainUnitPacketBytes));

        Reset(&buffer0);

        ReleaseLock(&buffer0);
    }
}

void OnFrameReceived1()
{
    if(buffer1.Index >= sizeof(MainUnitToPanelPacketBytes))
    {
        TakeLock(&buffer1);

        memcpy_P(&display, buffer1.Data, sizeof(MainUnitToPanelPacketBytes));

        Reset(&buffer1);

        ReleaseLock(&buffer1);
    }
}

inline void Reset(Buffer* buffer)
{
    for(uint8_t i = 0; i < sizeof(buffer->Data); ++i)
    {
        buffer->Data[i] = 0;
    }

    buffer->Index = 0;
}

inline void TakeLock(Buffer* buffer)
{
    //while(buffer->Lock > 0)
    //{
    //asm("NOP");
    //}

    //buffer->Lock = 1;
}

inline void ReleaseLock(Buffer* buffer)
{
    //buffer->Lock = 0;
}
