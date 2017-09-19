#include "Controller.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint-gcc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
extern "C"
{
	#include "uart.h"
};

Controller::Controller()
{
}

void Controller::Initialize()
{
	uart_init(UART_BAUD_SELECT(19200, F_CPU));
	uart1_init(UART_BAUD_SELECT(19200, F_CPU));
	sei();
}

void Controller::WaitForPacketsInitialized()
{
	while(pDisplay == nullptr || pPanel == nullptr)
	{
		asm("NOP");
	}
}

void Controller::Squelch(uint8_t value, bool left)
{
	if(left)	pPanel->SquelchLeft = value;   // 0x00 - 0x7F
	else		pPanel->SquelchRight = 0x7F - value; // 0x7F - 0x00
}

void Controller::Volume(uint8_t value, bool left)
{
	if(left)	pPanel->VolumeLeft = value;  // 0x00 - 0x7F
	else		pPanel->VolumeRight = value; // 0x00 - 0x7F
}

void Controller::Turn(Direction direction, bool left)
{
	switch(direction)
	{
		case Direction::Left:
		if(left)	pPanel->DialLeft = 0xFF;
		else		pPanel->DialRight = 0x7F;
		break;
		
		case Direction::Right:
		if(left)	pPanel->DialLeft = 0x81;
		else		pPanel->DialRight = 0x01;
		break;

		case Direction::None:
		if(left)	pPanel->DialLeft = 0x80;
		else		pPanel->DialRight = 0x00;
		break;
	}
}

void Controller::Press(Key key, bool left)
{
	switch(key)
	{
		case Key::PTT: pPanel->PushToTalk = 0x1B; break;

		case Key::Low: left ? pPanel->KeysLeft = 0x61 : pPanel->KeysRight = 0x00; break;
		case Key::VM:  left ? pPanel->KeysLeft = 0x40 : pPanel->KeysRight = 0x1F; break;
		case Key::HM:  left ? pPanel->KeysLeft = 0x1F : pPanel->KeysRight = 0x40; break;
		case Key::Scn: left ? pPanel->KeysLeft = 0x00 : pPanel->KeysRight = 0x61; break;

		case Key::Set:     pPanel->Keys = 0x04; break;
		case Key::DialKey: pPanel->Keys = left ? 0x02 : 0x01; break;
		case Key::VolSql:  if(left) pPanel->Keys = 0x08; break; //NOTE: right volume is power on/off

		case Key::H1:  pPanel->Hyper = 0x01; break;
		case Key::H2:  pPanel->Hyper = 0x02; break;
		case Key::H3:  pPanel->Hyper = 0x03; break;
		case Key::H4:  pPanel->Hyper = 0x04; break;
		case Key::H5:  pPanel->Hyper = 0x05; break;
		case Key::H6:  pPanel->Hyper = 0x06; break;
	}
}

void Controller::Press(Number number)
{
	switch(number)
	{
		case Number::Num1:    pPanel->Mic06 = 0x03; pPanel->Mic09 = 0x1B; break;
		case Number::Num2:    pPanel->Mic06 = 0x03; pPanel->Mic09 = 0x32; break;
		case Number::Num3:    pPanel->Mic06 = 0x03; pPanel->Mic09 = 0x4b; break;
		case Number::NumA:    pPanel->Mic06 = 0x03; pPanel->Mic09 = 0x66; break;
		
		case Number::Num4:    pPanel->Mic06 = 0x19; pPanel->Mic09 = 0x1B; break;
		case Number::Num5:    pPanel->Mic06 = 0x19; pPanel->Mic09 = 0x32; break;
		case Number::Num6:    pPanel->Mic06 = 0x19; pPanel->Mic09 = 0x4B; break;
		case Number::NumB:    pPanel->Mic06 = 0x19; pPanel->Mic09 = 0x66; break;
		
		case Number::Num7:    pPanel->Mic06 = 0x31; pPanel->Mic09 = 0x1B; break;
		case Number::Num8:    pPanel->Mic06 = 0x31; pPanel->Mic09 = 0x32; break;
		case Number::Num9:    pPanel->Mic06 = 0x31; pPanel->Mic09 = 0x4B; break;
		case Number::NumC:    pPanel->Mic06 = 0x31; pPanel->Mic09 = 0x66; break;
		
		case Number::NumStar: pPanel->Mic06 = 0x4B; pPanel->Mic09 = 0x1C; break;
		case Number::Num0:    pPanel->Mic06 = 0x4B; pPanel->Mic09 = 0x33; break;
		case Number::NumHash: pPanel->Mic06 = 0x4B; pPanel->Mic09 = 0x4B; break;
		case Number::NumD:    pPanel->Mic06 = 0x4B; pPanel->Mic09 = 0x66; break;
		
		case Number::NumP1:   pPanel->Mic06 = 0x63; pPanel->Mic09 = 0x1C; break;
		case Number::NumP2:   pPanel->Mic06 = 0x63; pPanel->Mic09 = 0x33; break;
		case Number::NumP3:   pPanel->Mic06 = 0x63; pPanel->Mic09 = 0x4B; break;
		case Number::NumP4:   pPanel->Mic06 = 0x63; pPanel->Mic09 = 0x66; break;
		
		case Number::NumDown: pPanel->Mic06 = 0x1D; pPanel->Mic09 = 0x06; break;
		case Number::NumUp:   pPanel->Mic06 = 0x34; pPanel->Mic09 = 0x06; break;
	}
}

bool Controller::SelectedVfo(bool left)
{
	auto selected = left ? pDisplay->MainLeft : pDisplay->MainRight;
	return selected != 0;
}

char Controller::Number(bool A, bool B, bool C, bool D, bool E, bool F, bool G)
{
	if(!A &&  B &&  C && !D && !E && !F && !G) return '1';
	if( A &&  B && !C &&  D &&  E && !F &&  G) return '2';
	if( A &&  B &&  C &&  D && !E && !F &&  G) return '3';
	if(!A &&  B &&  C && !D && !E &&  F &&  G) return '4';
	if( A && !B &&  C &&  D && !E &&  F &&  G) return '5';
	if( A && !B &&  C &&  D &&  E &&  F &&  G) return '6';
	if( A &&  B &&  C && !D && !E && !F && !G) return '7';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G) return '8';
	if( A &&  B &&  C &&  D && !E &&  F &&  G) return '9';
	if( A &&  B &&  C &&  D &&  E &&  F && !G) return '0';
	
	return ' ';
}

char Controller::Character(bool A, bool B, bool C, bool D, bool E, bool F, bool G, bool M,
bool H, bool J, bool K, bool Q, bool P, bool N)
{
	return ' ';
}
