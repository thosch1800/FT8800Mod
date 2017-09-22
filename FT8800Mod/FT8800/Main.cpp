#include <stdlib.h>
#include <stdio.h>
#include <stdint-gcc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "Controller.h"
extern "C"
{
	#include "timer.h"
	#include "uart.h"
	#include "uartUtils.h"
};

int main()
{
	Controller controller;
	InitializeTimer();
	InitializeUart();
	sei();

	do
	{
		//pPanel = (PanelToMainUnitPacketBytes*)(panelBuffer + panelStartIndex);

		//asm("NOP"); // breakpoint action: {panel->Byte01} {panel->Byte02} {panel->Byte03} {panel->Byte04} {panel->Byte05} {panel->Byte06} {panel->Byte07} {panel->Byte08} {panel->Byte09} {panel->Byte10} {panel->Byte11} {panel->Byte12} {panel->Byte13}
	} while(true);

	return 0;
}