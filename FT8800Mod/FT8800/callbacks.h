#ifndef CALLBACKS_H_
#define CALLBACKS_H_

#include <stdint-gcc.h>

typedef struct
{
    uint8_t Index;
    uint8_t Data[64];
    uint8_t Lock;
} Buffer;

Buffer buffer0;
Buffer buffer1;

void OnByteReceived0();
void OnByteReceived1();

void OnFrameReceived0();
void OnFrameReceived1();

void Reset(Buffer* buffer);
void TakeLock(Buffer* buffer);
void ReleaseLock(Buffer* buffer);

#endif /* CALLBACKS_H_ */