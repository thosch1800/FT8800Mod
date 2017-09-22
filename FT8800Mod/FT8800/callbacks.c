#include "callbacks.h"
#include "uart.h"
#include "MainUnitToPanelPacketBytes.h"
#include "PanelToMainUnitPacketBytes.h"

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

        asm("NOP"); // {buffer0.Data[0]} {buffer0.Data[1]} {buffer0.Data[2]} {buffer0.Data[3]} {buffer0.Data[4]} {buffer0.Data[5]} {buffer0.Data[6]} {buffer0.Data[7]} {buffer0.Data[8]} {buffer0.Data[9]} {buffer0.Data[10]} {buffer0.Data[11]} {buffer0.Data[12]} {buffer0.Data[13]}

        //TODO: update controller data

        Reset(&buffer0);
        ReleaseLock(&buffer0);
    }
}

void OnFrameReceived1()
{
    if(buffer1.Index >= sizeof(MainUnitToPanelPacketBytes))
    {
        TakeLock(&buffer1);

        asm("NOP");

        //TODO: update controller data

        Reset(&buffer1);

        ReleaseLock(&buffer1);
    }
}

void Reset(Buffer* buffer)
{
    for(uint8_t i = 0; i < sizeof(buffer->Data); ++i)
    {
        buffer->Data[i] = 0;
    }

    buffer->Index = 0;
}

void TakeLock(Buffer* buffer)
{
    while(buffer->Lock > 0)
    {
        asm("NOP");
    }

    buffer->Lock = 1;
}

void ReleaseLock(Buffer* buffer)
{
    buffer->Lock = 0;
}
