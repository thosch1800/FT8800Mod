#include "Controller.h"

Controller::Controller()
{
}

bool Controller::IsInitialized()
{
	auto isInitialized = pDisplay != nullptr && pPanel != nullptr;
	return isInitialized;
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
		case Left:
		if(left)	pPanel->DialLeft = 0xFF;
		else		pPanel->DialRight = 0x7F;
		break;
		
		case Right:
		if(left)	pPanel->DialLeft = 0x81;
		else		pPanel->DialRight = 0x01;
		break;

		case None:
		if(left)	pPanel->DialLeft = 0x80;
		else		pPanel->DialRight = 0x00;
		break;
	}
}

void Controller::Press(Key key, bool left)
{
	switch(key)
	{
		case PTT: pPanel->Byte03 = 0x1B; break;

		case Low:     left ? pPanel->Byte10 = 0x61 : pPanel->Byte11 = 0x00; break;
		case VM:      left ? pPanel->Byte10 = 0x40 : pPanel->Byte11 = 0x1F; break;
		case HM:      left ? pPanel->Byte10 = 0x1F : pPanel->Byte11 = 0x40; break;
		case Scn:     left ? pPanel->Byte10 = 0x00 : pPanel->Byte11 = 0x61; break;

		case Set:     pPanel->Byte12 = 0x04; break;
		case VolSql:  pPanel->Byte12 = left ? 0x08 : pPanel->Byte12; break; // right volume is power on/off
		case DialKey: pPanel->Byte12 = left ? 0x02 : 0x01; break;

		case H1:  pPanel->Byte13 = 0x01; break;
		case H2:  pPanel->Byte13 = 0x02; break;
		case H3:  pPanel->Byte13 = 0x03; break;
		case H4:  pPanel->Byte13 = 0x04; break;
		case H5:  pPanel->Byte13 = 0x05; break;
		case H6:  pPanel->Byte13 = 0x06; break;
	}
}

void Controller::Press(Number number)
{
	uint8_t byte06 = 0x00;
	uint8_t byte09 = 0x00;

	switch(number)
	{
		case Num1:    byte06 = 0x03; byte09 = 0x1B; break;
		case Num2:    byte06 = 0x03; byte09 = 0x32; break;
		case Num3:    byte06 = 0x03; byte09 = 0x4b; break;
		case NumA:    byte06 = 0x03; byte09 = 0x66; break;
		
		case Num4:    byte06 = 0x19; byte09 = 0x1B; break;
		case Num5:    byte06 = 0x19; byte09 = 0x32; break;
		case Num6:    byte06 = 0x19; byte09 = 0x4B; break;
		case NumB:    byte06 = 0x19; byte09 = 0x66; break;
		
		case Num7:    byte06 = 0x31; byte09 = 0x1B; break;
		case Num8:    byte06 = 0x31; byte09 = 0x32; break;
		case Num9:    byte06 = 0x31; byte09 = 0x4B; break;
		case NumC:    byte06 = 0x31; byte09 = 0x66; break;

		case NumStar: byte06 = 0x4B; byte09 = 0x1C; break;
		case Num0:    byte06 = 0x4B; byte09 = 0x33; break;
		case NumHash: byte06 = 0x4B; byte09 = 0x4B; break;
		case NumD:    byte06 = 0x4B; byte09 = 0x66; break;

		case NumP1:   byte06 = 0x63; byte09 = 0x1C; break;
		case NumP2:   byte06 = 0x63; byte09 = 0x33; break;
		case NumP3:   byte06 = 0x63; byte09 = 0x4B; break;
		case NumP4:   byte06 = 0x63; byte09 = 0x66; break;

		case NumDown: byte06 = 0x1D; byte09 = 0x06; break;
		case NumUp:   byte06 = 0x34; byte09 = 0x06; break;
	}

	pPanel->Byte06 = byte06;
	pPanel->Byte09 = byte09;
}

void Controller::SelectVfo(bool left)
{
	pPanel->Byte12 = left ? 0x02 : 0x01;
}

bool Controller::SelectedVfo(bool left)
{
	auto selected = left ? pDisplay->MainLeft : pDisplay->MainRight;
	return selected != 0;
}
