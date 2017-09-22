#include "callbacks.h"
#include "uart.h"

void OnByteReceived0()
{
	buffer0.Data[buffer0.Index++] = uart_getc();
}

void OnByteReceived1()
{
	buffer1.Data[buffer1.Index++] = uart_getc();
}

void OnFrameReceived0()
{
	Reset(&buffer0);
}

void OnFrameReceived1()
{
	Reset(&buffer1);
}

void Reset(Buffer* buffer)
{
	for(uint8_t i = 0; i < sizeof(buffer->Data); ++i)
	{
		buffer->Data[i] = 0;
	}

	buffer->Index = 0;
}
