#include "Controller.h"

Controller::Controller()
{
}

bool Controller::IsInitialized()
{
	bool isInitialized = pDisplay != nullptr && pPanel != nullptr;
	return isInitialized;
}

void Controller::Press1() { Number(0x03, 0x1B); }
void Controller::Press2() { Number(0x03, 0x32); }
void Controller::Press3() { Number(0x03, 0x4b); }
void Controller::Press4() { Number(0x19, 0x1B); }
void Controller::Press5() { Number(0x19, 0x32); }
void Controller::Press6() { Number(0x19, 0x4B); }
void Controller::Press7() { Number(0x31, 0x1B); }
void Controller::Press8() { Number(0x31, 0x32); }
void Controller::Press9() { Number(0x31, 0x4B); }
void Controller::Press0() { Number(0x4B, 0x33); }

void Controller::Number(uint8_t byte06, uint8_t byte09)
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
	bool selected = left ? pDisplay->MainLeft : pDisplay->MainRight;
	return selected;
}
