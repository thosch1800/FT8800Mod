#ifndef MODEM_H_
#define MODEM_H_

#include <stdint-gcc.h>

void InitializeModem();
uint8_t IsModemPTT();
void SetDataPTT(uint8_t active);

#endif /* MODEM_H_ */