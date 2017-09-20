#ifndef __PACKETUPDATER_H__
#define __PACKETUPDATER_H__

#include <stdint-gcc.h>
#include "MainUnitToPanelPacketBytes.h"
#include "PanelToMainUnitPacketBytes.h"

// CPU clock in Hz
#define F_CPU 14745600

class PacketUpdater
{
	public:
	void Initialize();
	void WaitForPacketsInitialized();
	
	private:
	PanelToMainUnitPacketBytes* pPanel = nullptr;
	MainUnitToPanelPacketBytes* pDisplay = nullptr;
};

#endif //__PACKETUPDATER_H__
