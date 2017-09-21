#include "Controller.h"
#include "PacketUpdater.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint-gcc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

int main()
{
	uint8_t panelBuffer[32];
	uint8_t panelBufferIndex = 0;
	uint8_t panelBufferStatus = 0;

	uint8_t displayBuffer[96];
	uint8_t displayBufferIndex = 0;
	uint8_t displayBufferStatus = 0;

	Controller controller;
	PacketUpdater packetUpdater;

	sei();

	PanelToMainUnitPacketBytes* panel = (PanelToMainUnitPacketBytes*)panelBuffer;
	MainUnitToPanelPacketBytes* display = (MainUnitToPanelPacketBytes*)displayBuffer;
	do
	{
		//TODO: read bytes into buffer (buffer size: ~ 1.5-x times packet size)
		//		start timer whenever byte received
		//		when timer elapsed, get last bytes of buffer (timer should fire when 1ms is over)

		//for(panelBufferIndex = 0; panelBufferIndex < sizeof(PanelToMainUnitPacketBytes);)
		//{
		//uint8_t value = packetUpdater.ReadPanelByte(&panelBufferStatus);
		//if(panelBufferStatus == 0)
		//panelBuffer[panelBufferIndex++] = value;
		//}

		for(displayBufferIndex = 0; displayBufferIndex < sizeof(MainUnitToPanelPacketBytes);)
		{
			uint8_t value = packetUpdater.ReadMainByte(&displayBufferStatus);
			if(displayBufferStatus == 0)
			displayBuffer[displayBufferIndex++] = value;
		}

		//int startIndex = 0;
		//panel = (PanelToMainUnitPacketBytes*)(panelBuffer + startIndex);
		//display = (MainUnitToPanelPacketBytes*)(displayBuffer + startIndex);

		asm("NOP"); // breakpoint action: {panel->Byte01} {panel->Byte02} {panel->Byte03} {panel->Byte04} {panel->Byte05} {panel->Byte06} {panel->Byte07} {panel->Byte08} {panel->Byte09} {panel->Byte10} {panel->Byte11} {panel->Byte12} {panel->Byte13}
		asm("NOP"); // breakpoint action: {panel->Byte01} {panel->Byte02} {panel->Byte03} {panel->Byte04} {panel->Byte05} {panel->Byte06} {panel->Byte07} {panel->Byte08} {panel->Byte09} {panel->Byte10} {panel->Byte11} {panel->Byte12} {panel->Byte13}

	} while(true);

	return 0;
}