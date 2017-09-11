#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdint-gcc.h>
#include "MainUnitToPanelPacketBytes.h"
#include "PanelToMainUnitPacketBytes.h"

class Controller
{
	public: Controller();
	
	public: bool IsInitialized();
	
	public: void Press1();
	public: void Press2();
	public: void Press3();
	public: void Press4();
	public: void Press5();
	public: void Press6();
	public: void Press7();
	public: void Press8();
	public: void Press9();
	public: void Press0();
	private: void PressNumber(uint8_t byte06, uint8_t byte09);

	public: void SelectVfo(bool left);
	private: bool SelectedVfo(bool left);
	
	private: PanelToMainUnitPacketBytes* pPanel = nullptr;
	private: MainUnitToPanelPacketBytes* pDisplay = nullptr;
};

#endif /* CONTROLLER_H_ */