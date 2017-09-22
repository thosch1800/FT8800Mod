#include "uartUtils.h"

void InitializeUart()
{
	uart_init(UART_BAUD_SELECT(BAUD_RATE, F_CPU));
	uart1_init(UART_BAUD_SELECT(BAUD_RATE, F_CPU));
}

uint8_t ReadMainByte(uint8_t* status)
{
	int value = uart_getc();

	*status = (value >> 8);

	return (uint8_t)value;
}

uint8_t ReadPanelByte(uint8_t* status)
{
	int value = uart1_getc();

	*status = (value >> 8);

	return (uint8_t)value;
}
