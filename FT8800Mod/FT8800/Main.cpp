#include <stdint-gcc.h>
#include "uart.h"
#include "Controller.h"

#define F_CPU 14745600

int main()
{
	Controller controller;


	while(1)
	{
		asm("NOP");
	}

	return 0;
}