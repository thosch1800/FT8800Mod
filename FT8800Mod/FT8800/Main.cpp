#include "Controller.h"
#include "PacketUpdater.h"

int main()
{
	Controller controller;
	PacketUpdater packetUpdater;

	packetUpdater.Initialize();
	packetUpdater.WaitForPacketsInitialized();

	//TODO: add logic here

	while(true) asm("NOP"); // keep main loop running

	return 0;
}