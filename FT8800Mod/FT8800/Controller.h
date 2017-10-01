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
    public:
    Controller(PanelToMainUnitPacketBytes* pPanelPacket, MainUnitToPanelPacketBytes* pDisplayPacket);

    void Squelch(uint8_t value, bool left);
    void Volume(uint8_t value, bool left);
    void Turn(Direction direction, bool left);
    void Press(Key key, bool left = true);
    void Press(Number number);
    
    bool IsVfoMode(bool left);
    bool IsChannelMode(bool left);
    bool IsMain(bool left);
    bool IsInInputMode(bool left);
    bool IsBusy(bool left);

    void GetDisplayText(char* text, bool left);
    void SetDisplayText(const char* text, bool left, uint8_t offset = 0);

    private:
    char GetChannel(uint8_t place, bool left);
    char GetSegment(bool A, bool B, bool C, bool D, bool E, bool F, bool G);

    char GetFrequency(uint8_t place, bool left);
    void SetFrequency(char character, uint8_t place, bool left);

    char GetSegment(bool A, bool B, bool C, bool D, bool E, bool F, bool G, bool M, bool H, bool JP, bool K, bool Q, bool N);
    void SetSegment(char character, bool* A, bool* B, bool* C, bool* D, bool* E, bool* F, bool* G, bool* M, bool* H, bool* JP, bool* K, bool* Q, bool* N);
    
    PanelToMainUnitPacketBytes* pPanel;
    MainUnitToPanelPacketBytes* pDisplay;
    bool mainLastKnownActivityLeft = false;
    bool mainLastKnownActivityRight = false;
};

#endif /* CONTROLLER_H_ */
