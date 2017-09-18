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
		case PTT: pPanel->PushToTalk = 0x1B; break;

		case Low: left ? pPanel->KeysLeft = 0x61 : pPanel->KeysRight = 0x00; break;
		case VM:  left ? pPanel->KeysLeft = 0x40 : pPanel->KeysRight = 0x1F; break;
		case HM:  left ? pPanel->KeysLeft = 0x1F : pPanel->KeysRight = 0x40; break;
		case Scn: left ? pPanel->KeysLeft = 0x00 : pPanel->KeysRight = 0x61; break;

		case Set:     pPanel->Keys = 0x04; break;
		case DialKey: pPanel->Keys = left ? 0x02 : 0x01; break;
		case VolSql:  if(left) pPanel->Keys = 0x08; break; //NOTE: right volume is power on/off

		case H1:  pPanel->Hyper = 0x01; break;
		case H2:  pPanel->Hyper = 0x02; break;
		case H3:  pPanel->Hyper = 0x03; break;
		case H4:  pPanel->Hyper = 0x04; break;
		case H5:  pPanel->Hyper = 0x05; break;
		case H6:  pPanel->Hyper = 0x06; break;
	}
}

void Controller::Press(Number number)
{
	switch(number)
	{
		case Num1:    pPanel->Mic06 = 0x03; pPanel->Mic09 = 0x1B; break;
		case Num2:    pPanel->Mic06 = 0x03; pPanel->Mic09 = 0x32; break;
		case Num3:    pPanel->Mic06 = 0x03; pPanel->Mic09 = 0x4b; break;
		case NumA:    pPanel->Mic06 = 0x03; pPanel->Mic09 = 0x66; break;
		
		case Num4:    pPanel->Mic06 = 0x19; pPanel->Mic09 = 0x1B; break;
		case Num5:    pPanel->Mic06 = 0x19; pPanel->Mic09 = 0x32; break;
		case Num6:    pPanel->Mic06 = 0x19; pPanel->Mic09 = 0x4B; break;
		case NumB:    pPanel->Mic06 = 0x19; pPanel->Mic09 = 0x66; break;
		
		case Num7:    pPanel->Mic06 = 0x31; pPanel->Mic09 = 0x1B; break;
		case Num8:    pPanel->Mic06 = 0x31; pPanel->Mic09 = 0x32; break;
		case Num9:    pPanel->Mic06 = 0x31; pPanel->Mic09 = 0x4B; break;
		case NumC:    pPanel->Mic06 = 0x31; pPanel->Mic09 = 0x66; break;
		
		case NumStar: pPanel->Mic06 = 0x4B; pPanel->Mic09 = 0x1C; break;
		case Num0:    pPanel->Mic06 = 0x4B; pPanel->Mic09 = 0x33; break;
		case NumHash: pPanel->Mic06 = 0x4B; pPanel->Mic09 = 0x4B; break;
		case NumD:    pPanel->Mic06 = 0x4B; pPanel->Mic09 = 0x66; break;
		
		case NumP1:   pPanel->Mic06 = 0x63; pPanel->Mic09 = 0x1C; break;
		case NumP2:   pPanel->Mic06 = 0x63; pPanel->Mic09 = 0x33; break;
		case NumP3:   pPanel->Mic06 = 0x63; pPanel->Mic09 = 0x4B; break;
		case NumP4:   pPanel->Mic06 = 0x63; pPanel->Mic09 = 0x66; break;
		
		case NumDown: pPanel->Mic06 = 0x1D; pPanel->Mic09 = 0x06; break;
		case NumUp:   pPanel->Mic06 = 0x34; pPanel->Mic09 = 0x06; break;
	}
}

bool Controller::SelectedVfo(bool left)
{
	auto selected = left ? pDisplay->MainLeft : pDisplay->MainRight;
	return selected != 0;
}
