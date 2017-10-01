#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <stdint-gcc.h>

#include "state.h"
#include "MainUnitToPanelPacketBytes.h"
#include "PanelToMainUnitPacketBytes.h"


void InitializeUart();

void SetPortAPin(uint8_t pin, uint8_t state);

void SendPanelPacket();

void SendDisplayPacket();

#endif /* UTILITIES_H_ */