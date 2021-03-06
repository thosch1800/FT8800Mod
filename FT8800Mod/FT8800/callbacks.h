#ifndef CALLBACKS_H_
#define CALLBACKS_H_

#include <stdint-gcc.h>

typedef struct
{
    uint8_t Index;
    uint8_t Data[64];
} Buffer;

Buffer buffer0;
Buffer buffer1;

void OnFrameReceived0();
void OnFrameReceived1();

#endif /* CALLBACKS_H_ */