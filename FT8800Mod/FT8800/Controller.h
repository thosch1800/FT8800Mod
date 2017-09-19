#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdint-gcc.h>
#include "MainUnitToPanelPacketBytes.h"
#include "PanelToMainUnitPacketBytes.h"

// CPU clock in Hz
#define F_CPU 14745600

enum class Direction { None, Left, Right };
enum class Key { PTT, Low, VM, HM, Scn, Set, DialKey, VolSql, H1, H2, H3, H4, H5, H6 };
enum class Number { Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, NumA, NumB, NumC, NumD, NumStar, NumHash, NumP1, NumP2, NumP3, NumP4, NumUp, NumDown };

class Controller
{
	public:
	Controller();

	void Initialize();
	void WaitForPacketsInitialized();

	void Squelch(uint8_t value, bool left);
	void Volume(uint8_t value, bool left);
	void Turn(Direction direction, bool left);
	void Press(Key key, bool left = true);
	void Press(Number number);
	
	bool SelectedVfo(bool left);

	private:
	PanelToMainUnitPacketBytes* pPanel = nullptr;
	MainUnitToPanelPacketBytes* pDisplay = nullptr;
};

#endif /* CONTROLLER_H_ */
