#include "PacketUpdater.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint-gcc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
extern "C"
{
	#include "uart.h"
};

void PacketUpdater::Initialize()
{
	uart_init(UART_BAUD_SELECT(19200, F_CPU));
	uart1_init(UART_BAUD_SELECT(19200, F_CPU));
	sei();
}

void PacketUpdater::WaitForPacketsInitialized()
{
	while(pDisplay == nullptr || pPanel == nullptr)
	{
		asm("NOP");
	}
}

