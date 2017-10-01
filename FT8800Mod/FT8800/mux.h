#ifndef MUX_H_
#define MUX_H_

#include <stdint-gcc.h>

void InitializeMux();
void SetMuxBit0(uint8_t state);
void SetMuxBit1(uint8_t state);
void SetPortCPin(uint8_t pin, uint8_t state);

#endif /* MUX_H_ */