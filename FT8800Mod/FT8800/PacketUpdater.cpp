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

PacketUpdater::PacketUpdater()
{
	uart_init(UART_BAUD_SELECT(BAUD_RATE, F_CPU));
	uart1_init(UART_BAUD_SELECT(BAUD_RATE, F_CPU));
}

uint8_t PacketUpdater::ReadMainByte(uint8_t* status)
{
	int value = uart_getc();

	*status = (value >> 8);

	return (uint8_t)value;
}

uint8_t PacketUpdater::ReadPanelByte(uint8_t* status)
{
	int value = uart1_getc();

	*status = (value >> 8);

	return (uint8_t)value;
}
