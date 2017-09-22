#ifndef UARTUTILS_H_
#define UARTUTILS_H_

#include "uart.h"
#define BAUD_RATE 19200

void InitializeUart();

uint8_t ReadMainByte(uint8_t* status);
uint8_t ReadPanelByte(uint8_t* status);

#endif /* UARTUTILS_H_ */