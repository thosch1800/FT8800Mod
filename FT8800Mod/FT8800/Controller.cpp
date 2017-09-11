#include "Controller.h"

Controller::Controller()
{
}

bool Controller::IsInitialized()
{
	auto isInitialized = pDisplay != nullptr && pPanel != nullptr;
	return isInitialized;
}

void Controller::Press1() { PressNumber(0x03, 0x1B); }
void Controller::Press2() { PressNumber(0x03, 0x32); }
void Controller::Press3() { PressNumber(0x03, 0x4b); }
void Controller::Press4() { PressNumber(0x19, 0x1B); }
void Controller::Press5() { PressNumber(0x19, 0x32); }
void Controller::Press6() { PressNumber(0x19, 0x4B); }
void Controller::Press7() { PressNumber(0x31, 0x1B); }
void Controller::Press8() { PressNumber(0x31, 0x32); }
void Controller::Press9() { PressNumber(0x31, 0x4B); }
void Controller::Press0() { PressNumber(0x4B, 0x33); }

void Controller::PressNumber(uint8_t byte06, uint8_t byte09)
{
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
