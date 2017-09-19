#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdint-gcc.h>
#include "MainUnitToPanelPacketBytes.h"
#include "PanelToMainUnitPacketBytes.h"

enum class Direction { None, Left, Right };
enum class Key { PTT, Low, VM, HM, Scn, Set, DialKey, VolSql, H1, H2, H3, H4, H5, H6 };
enum class Number { Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, NumA, NumB, NumC, NumD, NumStar, NumHash, NumP1, NumP2, NumP3, NumP4, NumUp, NumDown };

class Controller
{
	public: Controller();
	
	public: bool IsInitialized();

	public: void Squelch(uint8_t value, bool left);
	public: void Volume(uint8_t value, bool left);
	private: uint8_t ToRange(uint8_t value, uint8_t min, uint8_t max);
	public: void Turn(Direction direction, bool left);
	public: void Press(Key key, bool left = true);
	public: void Press(Number number);
	
	public: bool SelectedVfo(bool left);

	private: PanelToMainUnitPacketBytes* pPanel = nullptr;
	private: MainUnitToPanelPacketBytes* pDisplay = nullptr;
};

#endif /* CONTROLLER_H_ */
