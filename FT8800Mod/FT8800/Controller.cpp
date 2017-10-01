#include "Controller.h"
#include "segment.h"
#include <string.h>

Controller::Controller(PanelToMainUnitPacketBytes* pPanelPacket, MainUnitToPanelPacketBytes* pDisplayPacket)
{
    pPanel = pPanelPacket;
    pDisplay = pDisplayPacket;
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

bool Controller::IsVfoMode(bool left)
{
    char channel = GetChannel(3, left);
    bool isVfoMode = channel == ' ';
    return isVfoMode;
}

bool Controller::IsChannelMode(bool left) { return !IsVfoMode(left); }

bool Controller::IsMain(bool left)
{   //NOTE: the 'main' label is blinking after VFO change - therefore we save the last known state.

    bool isSelectedLeft = pDisplay->MainLeft;
    bool isSelectedRight = pDisplay->MainRight;

    if(!(isSelectedLeft || isSelectedRight))
    {   // use last known activity
        isSelectedLeft = mainLastKnownActivityLeft;
        isSelectedRight = mainLastKnownActivityRight;
    }
    else
    {   // update last known activity
        mainLastKnownActivityLeft = isSelectedLeft;
        mainLastKnownActivityRight = isSelectedRight;
    }

    bool isSelected = left ? isSelectedLeft : isSelectedRight;
    return isSelected != 0;
}

bool Controller::IsInInputMode(bool left)
{
    char frequencyCharSix = GetFrequency(6, left);
    bool isInInputMode = frequencyCharSix == '\n';
    return isInInputMode != 0;
}

bool Controller::IsBusy(bool left)
{
    bool isBusy = left ? pDisplay->BusyLeft : pDisplay->BusyRight;
    return isBusy != 0;
}

void Controller::GetDisplayText(char* text, bool left)
{
    char str[7];
    str[0] = GetFrequency(1, left);
    str[1] = GetFrequency(2, left);
    str[2] = GetFrequency(3, left);
    str[3] = GetFrequency(4, left);
    str[4] = GetFrequency(5, left);
    str[5] = GetFrequency(6, left);
    str[6] = '\0';

    strncpy(text, str, 7);
}

void Controller::SetDisplayText(const char* text, bool left, uint8_t offset)
{
    uint8_t txtlen = strlen(text) - offset;
    if(txtlen > 7) txtlen = 7;

    char str[7] = "      ";
    strncpy(str, text + offset, txtlen);

    SetFrequency(str[0], 1, left);
    SetFrequency(str[1], 2, left);
    SetFrequency(str[2], 3, left);
    SetFrequency(str[3], 4, left);
    SetFrequency(str[4], 5, left);
    SetFrequency(str[5], 6, left);

    if(left)
    {
        pDisplay->FrequencyLeftDecimalPointMhz = 0;
        pDisplay->FrequencyLeftDecimalPointMhz = 0;
    }
    else
    {
        pDisplay->FrequencyRightDecimalPointMhz = 0;
        pDisplay->FrequencyRightDecimalPointMhz = 0;
    }
}

char Controller::GetChannel(uint8_t place, bool left)
{
    switch(place)
    {
        case 1: return left ?
        GetSegment(
        pDisplay->ChannelLeftPlace1BarA,
        pDisplay->ChannelLeftPlace1BarB,
        pDisplay->ChannelLeftPlace1BarC,
        pDisplay->ChannelLeftPlace1BarD,
        pDisplay->ChannelLeftPlace1BarE,
        pDisplay->ChannelLeftPlace1BarF,
        pDisplay->ChannelLeftPlace1BarG) :
        GetSegment(
        pDisplay->ChannelRightPlace1BarA,
        pDisplay->ChannelRightPlace1BarB,
        pDisplay->ChannelRightPlace1BarC,
        pDisplay->ChannelRightPlace1BarD,
        pDisplay->ChannelRightPlace1BarE,
        pDisplay->ChannelRightPlace1BarF,
        pDisplay->ChannelRightPlace1BarG);

        case 2: return left ?
        GetSegment(
        pDisplay->ChannelLeftPlace2BarA,
        pDisplay->ChannelLeftPlace2BarB,
        pDisplay->ChannelLeftPlace2BarC,
        pDisplay->ChannelLeftPlace2BarD,
        pDisplay->ChannelLeftPlace2BarE,
        pDisplay->ChannelLeftPlace2BarF,
        pDisplay->ChannelLeftPlace2BarG) :
        GetSegment(
        pDisplay->ChannelRightPlace2BarA,
        pDisplay->ChannelRightPlace2BarB,
        pDisplay->ChannelRightPlace2BarC,
        pDisplay->ChannelRightPlace2BarD,
        pDisplay->ChannelRightPlace2BarE,
        pDisplay->ChannelRightPlace2BarF,
        pDisplay->ChannelRightPlace2BarG);

        case 3: return left ?
        GetSegment(
        pDisplay->ChannelLeftPlace3BarA,
        pDisplay->ChannelLeftPlace3BarB,
        pDisplay->ChannelLeftPlace3BarC,
        pDisplay->ChannelLeftPlace3BarD,
        pDisplay->ChannelLeftPlace3BarE,
        pDisplay->ChannelLeftPlace3BarF,
        pDisplay->ChannelLeftPlace3BarG) :
        GetSegment(
        pDisplay->ChannelRightPlace3BarA,
        pDisplay->ChannelRightPlace3BarB,
        pDisplay->ChannelRightPlace3BarC,
        pDisplay->ChannelRightPlace3BarD,
        pDisplay->ChannelRightPlace3BarE,
        pDisplay->ChannelRightPlace3BarF,
        pDisplay->ChannelRightPlace3BarG);
    }

    return ' ';
}

char Controller::GetSegment(bool A, bool B, bool C, bool D, bool E, bool F, bool G)
{
    //    AAAAAAAA
    //   F        B
    //   F        B
    //   F        B
    //    GGGGGGGG
    //   E        C
    //   E        C
    //   E        C
    //    DDDDDDDD
    
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

char Controller::GetFrequency(uint8_t place, bool left)
{
    switch(place)
    {
        case 1: return left ?
        GetSegment(
        pDisplay->FrequencyLeftPlace1BarA,
        pDisplay->FrequencyLeftPlace1BarB,
        pDisplay->FrequencyLeftPlace1BarC,
        pDisplay->FrequencyLeftPlace1BarD,
        pDisplay->FrequencyLeftPlace1BarE,
        pDisplay->FrequencyLeftPlace1BarF,
        pDisplay->FrequencyLeftPlace1BarG,
        pDisplay->FrequencyLeftPlace1BarM,
        pDisplay->FrequencyLeftPlace1BarH,
        pDisplay->FrequencyLeftPlace1BarJ,
        pDisplay->FrequencyLeftPlace1BarK,
        pDisplay->FrequencyLeftPlace1BarQ,
        pDisplay->FrequencyLeftPlace1BarN) :
        GetSegment(
        pDisplay->FrequencyRightPlace1BarA,
        pDisplay->FrequencyRightPlace1BarB,
        pDisplay->FrequencyRightPlace1BarC,
        pDisplay->FrequencyRightPlace1BarD,
        pDisplay->FrequencyRightPlace1BarE,
        pDisplay->FrequencyRightPlace1BarF,
        pDisplay->FrequencyRightPlace1BarG,
        pDisplay->FrequencyRightPlace1BarM,
        pDisplay->FrequencyRightPlace1BarH,
        pDisplay->FrequencyRightPlace1BarJ,
        pDisplay->FrequencyRightPlace1BarK,
        pDisplay->FrequencyRightPlace1BarQ,
        pDisplay->FrequencyRightPlace1BarN);
        
        case 2: return left ?
        GetSegment(
        pDisplay->FrequencyLeftPlace2BarA,
        pDisplay->FrequencyLeftPlace2BarB,
        pDisplay->FrequencyLeftPlace2BarC,
        pDisplay->FrequencyLeftPlace2BarD,
        pDisplay->FrequencyLeftPlace2BarE,
        pDisplay->FrequencyLeftPlace2BarF,
        pDisplay->FrequencyLeftPlace2BarG,
        pDisplay->FrequencyLeftPlace2BarM,
        pDisplay->FrequencyLeftPlace2BarH,
        pDisplay->FrequencyLeftPlace2BarJ,
        pDisplay->FrequencyLeftPlace2BarK,
        pDisplay->FrequencyLeftPlace2BarQ,
        pDisplay->FrequencyLeftPlace2BarN) :
        GetSegment(
        pDisplay->FrequencyRightPlace2BarA,
        pDisplay->FrequencyRightPlace2BarB,
        pDisplay->FrequencyRightPlace2BarC,
        pDisplay->FrequencyRightPlace2BarD,
        pDisplay->FrequencyRightPlace2BarE,
        pDisplay->FrequencyRightPlace2BarF,
        pDisplay->FrequencyRightPlace2BarG,
        pDisplay->FrequencyRightPlace2BarM,
        pDisplay->FrequencyRightPlace2BarH,
        pDisplay->FrequencyRightPlace2BarJ,
        pDisplay->FrequencyRightPlace2BarK,
        pDisplay->FrequencyRightPlace2BarQ,
        pDisplay->FrequencyRightPlace2BarN);

        case 3: return left ?
        GetSegment(
        pDisplay->FrequencyLeftPlace3BarA,
        pDisplay->FrequencyLeftPlace3BarB,
        pDisplay->FrequencyLeftPlace3BarC,
        pDisplay->FrequencyLeftPlace3BarD,
        pDisplay->FrequencyLeftPlace3BarE,
        pDisplay->FrequencyLeftPlace3BarF,
        pDisplay->FrequencyLeftPlace3BarG,
        pDisplay->FrequencyLeftPlace3BarM,
        pDisplay->FrequencyLeftPlace3BarH,
        pDisplay->FrequencyLeftPlace3BarJ,
        pDisplay->FrequencyLeftPlace3BarK,
        pDisplay->FrequencyLeftPlace3BarQ,
        pDisplay->FrequencyLeftPlace3BarN) :
        GetSegment(
        pDisplay->FrequencyRightPlace3BarA,
        pDisplay->FrequencyRightPlace3BarB,
        pDisplay->FrequencyRightPlace3BarC,
        pDisplay->FrequencyRightPlace3BarD,
        pDisplay->FrequencyRightPlace3BarE,
        pDisplay->FrequencyRightPlace3BarF,
        pDisplay->FrequencyRightPlace3BarG,
        pDisplay->FrequencyRightPlace3BarM,
        pDisplay->FrequencyRightPlace3BarH,
        pDisplay->FrequencyRightPlace3BarJ,
        pDisplay->FrequencyRightPlace3BarK,
        pDisplay->FrequencyRightPlace3BarQ,
        pDisplay->FrequencyRightPlace3BarN);
        
        case 4: return left ?
        GetSegment(
        pDisplay->FrequencyLeftPlace4BarA,
        pDisplay->FrequencyLeftPlace4BarB,
        pDisplay->FrequencyLeftPlace4BarC,
        pDisplay->FrequencyLeftPlace4BarD,
        pDisplay->FrequencyLeftPlace4BarE,
        pDisplay->FrequencyLeftPlace4BarF,
        pDisplay->FrequencyLeftPlace4BarG,
        pDisplay->FrequencyLeftPlace4BarM,
        pDisplay->FrequencyLeftPlace4BarH,
        pDisplay->FrequencyLeftPlace4BarJ,
        pDisplay->FrequencyLeftPlace4BarK,
        pDisplay->FrequencyLeftPlace4BarQ,
        pDisplay->FrequencyLeftPlace4BarN) :
        GetSegment(
        pDisplay->FrequencyRightPlace4BarA,
        pDisplay->FrequencyRightPlace4BarB,
        pDisplay->FrequencyRightPlace4BarC,
        pDisplay->FrequencyRightPlace4BarD,
        pDisplay->FrequencyRightPlace4BarE,
        pDisplay->FrequencyRightPlace4BarF,
        pDisplay->FrequencyRightPlace4BarG,
        pDisplay->FrequencyRightPlace4BarM,
        pDisplay->FrequencyRightPlace4BarH,
        pDisplay->FrequencyRightPlace4BarJ,
        pDisplay->FrequencyRightPlace4BarK,
        pDisplay->FrequencyRightPlace4BarQ,
        pDisplay->FrequencyRightPlace4BarN);
        
        case 5: return left ?
        GetSegment(
        pDisplay->FrequencyLeftPlace5BarA,
        pDisplay->FrequencyLeftPlace5BarB,
        pDisplay->FrequencyLeftPlace5BarC,
        pDisplay->FrequencyLeftPlace5BarD,
        pDisplay->FrequencyLeftPlace5BarE,
        pDisplay->FrequencyLeftPlace5BarF,
        pDisplay->FrequencyLeftPlace5BarG,
        pDisplay->FrequencyLeftPlace5BarM,
        pDisplay->FrequencyLeftPlace5BarH,
        pDisplay->FrequencyLeftPlace5BarJ,
        pDisplay->FrequencyLeftPlace5BarK,
        pDisplay->FrequencyLeftPlace5BarQ,
        pDisplay->FrequencyLeftPlace5BarN) :
        GetSegment(
        pDisplay->FrequencyRightPlace5BarA,
        pDisplay->FrequencyRightPlace5BarB,
        pDisplay->FrequencyRightPlace5BarC,
        pDisplay->FrequencyRightPlace5BarD,
        pDisplay->FrequencyRightPlace5BarE,
        pDisplay->FrequencyRightPlace5BarF,
        pDisplay->FrequencyRightPlace5BarG,
        pDisplay->FrequencyRightPlace5BarM,
        pDisplay->FrequencyRightPlace5BarH,
        pDisplay->FrequencyRightPlace5BarJ,
        pDisplay->FrequencyRightPlace5BarK,
        pDisplay->FrequencyRightPlace5BarQ,
        pDisplay->FrequencyRightPlace5BarN);

        case 6: return left ?
        GetSegment(
        pDisplay->FrequencyLeftPlace6BarA,
        pDisplay->FrequencyLeftPlace6BarB,
        pDisplay->FrequencyLeftPlace6BarC,
        pDisplay->FrequencyLeftPlace6BarD,
        pDisplay->FrequencyLeftPlace6BarE,
        pDisplay->FrequencyLeftPlace6BarF,
        pDisplay->FrequencyLeftPlace6BarG,
        pDisplay->FrequencyLeftPlace6BarM,
        pDisplay->FrequencyLeftPlace6BarH,
        pDisplay->FrequencyLeftPlace6BarJ,
        pDisplay->FrequencyLeftPlace6BarK,
        pDisplay->FrequencyLeftPlace6BarQ,
        pDisplay->FrequencyLeftPlace6BarN) :
        GetSegment(
        pDisplay->FrequencyRightPlace6BarA,
        pDisplay->FrequencyRightPlace6BarB,
        pDisplay->FrequencyRightPlace6BarC,
        pDisplay->FrequencyRightPlace6BarD,
        pDisplay->FrequencyRightPlace6BarE,
        pDisplay->FrequencyRightPlace6BarF,
        pDisplay->FrequencyRightPlace6BarG,
        pDisplay->FrequencyRightPlace6BarM,
        pDisplay->FrequencyRightPlace6BarH,
        pDisplay->FrequencyRightPlace6BarJ,
        pDisplay->FrequencyRightPlace6BarK,
        pDisplay->FrequencyRightPlace6BarQ,
        pDisplay->FrequencyRightPlace6BarN);
    }

    return ' ';
}

void Controller::SetFrequency(char character, uint8_t place, bool left)
{
    bool A, B, C, D, E, F, G, M, H, J, K, Q, N;
    SetSegment(character, &A, &B, &C, &D, &E, &F, &G, &M, &H, &J, &K, &Q, &N);

    switch(place)
    {
        case 1:
        if(left)
        {
            pDisplay->FrequencyLeftPlace1BarA = A;
            pDisplay->FrequencyLeftPlace1BarB = B;
            pDisplay->FrequencyLeftPlace1BarC = C;
            pDisplay->FrequencyLeftPlace1BarD = D;
            pDisplay->FrequencyLeftPlace1BarE = E;
            pDisplay->FrequencyLeftPlace1BarF = F;
            pDisplay->FrequencyLeftPlace1BarG = G;
            pDisplay->FrequencyLeftPlace1BarM = M;
            pDisplay->FrequencyLeftPlace1BarH = H;
            pDisplay->FrequencyLeftPlace1BarJ = J;
            pDisplay->FrequencyLeftPlace1BarK = K;
            pDisplay->FrequencyLeftPlace1BarQ = Q;
            pDisplay->FrequencyLeftPlace1BarN = N;
        }
        else
        {
            pDisplay->FrequencyRightPlace1BarA = A;
            pDisplay->FrequencyRightPlace1BarB = B;
            pDisplay->FrequencyRightPlace1BarC = C;
            pDisplay->FrequencyRightPlace1BarD = D;
            pDisplay->FrequencyRightPlace1BarE = E;
            pDisplay->FrequencyRightPlace1BarF = F;
            pDisplay->FrequencyRightPlace1BarG = G;
            pDisplay->FrequencyRightPlace1BarM = M;
            pDisplay->FrequencyRightPlace1BarH = H;
            pDisplay->FrequencyRightPlace1BarJ = J;
            pDisplay->FrequencyRightPlace1BarK = K;
            pDisplay->FrequencyRightPlace1BarQ = Q;
            pDisplay->FrequencyRightPlace1BarN = N;
        }
        
        case 2:
        if(left)
        {
            pDisplay->FrequencyLeftPlace2BarA = A;
            pDisplay->FrequencyLeftPlace2BarB = B;
            pDisplay->FrequencyLeftPlace2BarC = C;
            pDisplay->FrequencyLeftPlace2BarD = D;
            pDisplay->FrequencyLeftPlace2BarE = E;
            pDisplay->FrequencyLeftPlace2BarF = F;
            pDisplay->FrequencyLeftPlace2BarG = G;
            pDisplay->FrequencyLeftPlace2BarM = M;
            pDisplay->FrequencyLeftPlace2BarH = H;
            pDisplay->FrequencyLeftPlace2BarJ = J;
            pDisplay->FrequencyLeftPlace2BarK = K;
            pDisplay->FrequencyLeftPlace2BarQ = Q;
            pDisplay->FrequencyLeftPlace2BarN = N;
        }
        else
        {
            pDisplay->FrequencyRightPlace2BarA = A;
            pDisplay->FrequencyRightPlace2BarB = B;
            pDisplay->FrequencyRightPlace2BarC = C;
            pDisplay->FrequencyRightPlace2BarD = D;
            pDisplay->FrequencyRightPlace2BarE = E;
            pDisplay->FrequencyRightPlace2BarF = F;
            pDisplay->FrequencyRightPlace2BarG = G;
            pDisplay->FrequencyRightPlace2BarM = M;
            pDisplay->FrequencyRightPlace2BarH = H;
            pDisplay->FrequencyRightPlace2BarJ = J;
            pDisplay->FrequencyRightPlace2BarK = K;
            pDisplay->FrequencyRightPlace2BarQ = Q;
            pDisplay->FrequencyRightPlace2BarN = N;
        }

        case 3:
        if(left)
        {
            pDisplay->FrequencyLeftPlace3BarA = A;
            pDisplay->FrequencyLeftPlace3BarB = B;
            pDisplay->FrequencyLeftPlace3BarC = C;
            pDisplay->FrequencyLeftPlace3BarD = D;
            pDisplay->FrequencyLeftPlace3BarE = E;
            pDisplay->FrequencyLeftPlace3BarF = F;
            pDisplay->FrequencyLeftPlace3BarG = G;
            pDisplay->FrequencyLeftPlace3BarM = M;
            pDisplay->FrequencyLeftPlace3BarH = H;
            pDisplay->FrequencyLeftPlace3BarJ = J;
            pDisplay->FrequencyLeftPlace3BarK = K;
            pDisplay->FrequencyLeftPlace3BarQ = Q;
            pDisplay->FrequencyLeftPlace3BarN = N;
        }
        else
        {
            pDisplay->FrequencyRightPlace3BarA = A;
            pDisplay->FrequencyRightPlace3BarB = B;
            pDisplay->FrequencyRightPlace3BarC = C;
            pDisplay->FrequencyRightPlace3BarD = D;
            pDisplay->FrequencyRightPlace3BarE = E;
            pDisplay->FrequencyRightPlace3BarF = F;
            pDisplay->FrequencyRightPlace3BarG = G;
            pDisplay->FrequencyRightPlace3BarM = M;
            pDisplay->FrequencyRightPlace3BarH = H;
            pDisplay->FrequencyRightPlace3BarJ = J;
            pDisplay->FrequencyRightPlace3BarK = K;
            pDisplay->FrequencyRightPlace3BarQ = Q;
            pDisplay->FrequencyRightPlace3BarN = N;
        }
        
        case 4:
        if(left)
        {
            pDisplay->FrequencyLeftPlace4BarA = A;
            pDisplay->FrequencyLeftPlace4BarB = B;
            pDisplay->FrequencyLeftPlace4BarC = C;
            pDisplay->FrequencyLeftPlace4BarD = D;
            pDisplay->FrequencyLeftPlace4BarE = E;
            pDisplay->FrequencyLeftPlace4BarF = F;
            pDisplay->FrequencyLeftPlace4BarG = G;
            pDisplay->FrequencyLeftPlace4BarM = M;
            pDisplay->FrequencyLeftPlace4BarH = H;
            pDisplay->FrequencyLeftPlace4BarJ = J;
            pDisplay->FrequencyLeftPlace4BarK = K;
            pDisplay->FrequencyLeftPlace4BarQ = Q;
            pDisplay->FrequencyLeftPlace4BarN = N;
        }
        else
        {
            pDisplay->FrequencyRightPlace4BarA = A;
            pDisplay->FrequencyRightPlace4BarB = B;
            pDisplay->FrequencyRightPlace4BarC = C;
            pDisplay->FrequencyRightPlace4BarD = D;
            pDisplay->FrequencyRightPlace4BarE = E;
            pDisplay->FrequencyRightPlace4BarF = F;
            pDisplay->FrequencyRightPlace4BarG = G;
            pDisplay->FrequencyRightPlace4BarM = M;
            pDisplay->FrequencyRightPlace4BarH = H;
            pDisplay->FrequencyRightPlace4BarJ = J;
            pDisplay->FrequencyRightPlace4BarK = K;
            pDisplay->FrequencyRightPlace4BarQ = Q;
            pDisplay->FrequencyRightPlace4BarN = N;
        }
        
        case 5:
        if(left)
        {
            pDisplay->FrequencyLeftPlace5BarA = A;
            pDisplay->FrequencyLeftPlace5BarB = B;
            pDisplay->FrequencyLeftPlace5BarC = C;
            pDisplay->FrequencyLeftPlace5BarD = D;
            pDisplay->FrequencyLeftPlace5BarE = E;
            pDisplay->FrequencyLeftPlace5BarF = F;
            pDisplay->FrequencyLeftPlace5BarG = G;
            pDisplay->FrequencyLeftPlace5BarM = M;
            pDisplay->FrequencyLeftPlace5BarH = H;
            pDisplay->FrequencyLeftPlace5BarJ = J;
            pDisplay->FrequencyLeftPlace5BarK = K;
            pDisplay->FrequencyLeftPlace5BarQ = Q;
            pDisplay->FrequencyLeftPlace5BarN = N;
        }
        else
        {
            pDisplay->FrequencyRightPlace5BarA = A;
            pDisplay->FrequencyRightPlace5BarB = B;
            pDisplay->FrequencyRightPlace5BarC = C;
            pDisplay->FrequencyRightPlace5BarD = D;
            pDisplay->FrequencyRightPlace5BarE = E;
            pDisplay->FrequencyRightPlace5BarF = F;
            pDisplay->FrequencyRightPlace5BarG = G;
            pDisplay->FrequencyRightPlace5BarM = M;
            pDisplay->FrequencyRightPlace5BarH = H;
            pDisplay->FrequencyRightPlace5BarJ = J;
            pDisplay->FrequencyRightPlace5BarK = K;
            pDisplay->FrequencyRightPlace5BarQ = Q;
            pDisplay->FrequencyRightPlace5BarN = N;
        }

        case 6:
        if(left)
        {
            pDisplay->FrequencyLeftPlace6BarA = A;
            pDisplay->FrequencyLeftPlace6BarB = B;
            pDisplay->FrequencyLeftPlace6BarC = C;
            pDisplay->FrequencyLeftPlace6BarD = D;
            pDisplay->FrequencyLeftPlace6BarE = E;
            pDisplay->FrequencyLeftPlace6BarF = F;
            pDisplay->FrequencyLeftPlace6BarG = G;
            pDisplay->FrequencyLeftPlace6BarM = M;
            pDisplay->FrequencyLeftPlace6BarH = H;
            pDisplay->FrequencyLeftPlace6BarJ = J;
            pDisplay->FrequencyLeftPlace6BarK = K;
            pDisplay->FrequencyLeftPlace6BarQ = Q;
            pDisplay->FrequencyLeftPlace6BarN = N;
        }
        else
        {
            pDisplay->FrequencyRightPlace6BarA = A;
            pDisplay->FrequencyRightPlace6BarB = B;
            pDisplay->FrequencyRightPlace6BarC = C;
            pDisplay->FrequencyRightPlace6BarD = D;
            pDisplay->FrequencyRightPlace6BarE = E;
            pDisplay->FrequencyRightPlace6BarF = F;
            pDisplay->FrequencyRightPlace6BarG = G;
            pDisplay->FrequencyRightPlace6BarM = M;
            pDisplay->FrequencyRightPlace6BarH = H;
            pDisplay->FrequencyRightPlace6BarJ = J;
            pDisplay->FrequencyRightPlace6BarK = K;
            pDisplay->FrequencyRightPlace6BarQ = Q;
            pDisplay->FrequencyRightPlace6BarN = N;
        }
    }
}

char Controller::GetSegment(bool A, bool B, bool C, bool D, bool E, bool F, bool G, bool M, bool H, bool J, bool K, bool Q, bool N)
{
    for(uint8_t i = 0; i < segmentsSize; ++i)
    {
        if(
        segments[i].A == A &&
        segments[i].B == B &&
        segments[i].C == C &&
        segments[i].D == D &&
        segments[i].E == E &&
        segments[i].F == F &&
        segments[i].G == G &&
        segments[i].M == M &&
        segments[i].H == H &&
        segments[i].J == J &&
        segments[i].K == K &&
        segments[i].Q == Q &&
        segments[i].N == N )
        {
            return segments[i].Character;
        }
    }

    return ' ';
}

void Controller::SetSegment(char character, bool* A, bool* B, bool* C, bool* D, bool* E, bool* F, bool* G, bool* M, bool* H, bool* J, bool* K, bool* Q, bool* N)
{
    for(uint8_t i = 0; i < segmentsSize; ++i)
    {
        if(character == segments[i].Character)
        {
            *A = segments[i].A;
            *B = segments[i].B;
            *C = segments[i].C;
            *D = segments[i].D;
            *E = segments[i].E;
            *F = segments[i].F;
            *G = segments[i].G;
            *M = segments[i].M;
            *H = segments[i].H;
            *J = segments[i].J;
            *K = segments[i].K;
            *Q = segments[i].Q;
            *N = segments[i].N;
            break;
        }
    }
}
