#include "Controller.h"

int main()
{
	Controller controller;

	controller.Initialize();
	controller.WaitForPacketsInitialized();

	//TODO: add logic here

	while(true) asm("NOP"); // keep main loop running

	return 0;
}