#include <stdint-gcc.h>
#include "uart.h"
#include "Controller.h"

int main()
{
	Controller controller;


	while(1)
	{
		asm("NOP");
	}

	return 0;
}