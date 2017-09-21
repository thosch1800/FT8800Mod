#ifndef __PACKETUPDATER_H__
#define __PACKETUPDATER_H__

#include <stdint-gcc.h>
#include "MainUnitToPanelPacketBytes.h"
#include "PanelToMainUnitPacketBytes.h"

// CPU clock in Hz
#define F_CPU 14745600

// FT8800 communication
#define BAUD_RATE 19200

class PacketUpdater
{
	public:
	PacketUpdater();

	uint8_t ReadMainByte(uint8_t* status);
	uint8_t ReadPanelByte(uint8_t* status);
};

#endif //__PACKETUPDATER_H__
