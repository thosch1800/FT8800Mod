#include "uartUtils.h"
#include "uart.h"

void InitializeUart()
{
	uart_init(UART_BAUD_SELECT(BAUD_RATE, F_CPU));
	uart1_init(UART_BAUD_SELECT(BAUD_RATE, F_CPU));
}
