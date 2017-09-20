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

char Controller::Segment(uint8_t place, bool left, bool channelMode)
{
	if(channelMode)
	{
		switch(place)
		{
			case 1: return left ?
				Segment(pDisplay->ChannelLeftPlace1BarA, 
					pDisplay->ChannelLeftPlace1BarB, 
					pDisplay->ChannelLeftPlace1BarC, 
					pDisplay->ChannelLeftPlace1BarD, 
					pDisplay->ChannelLeftPlace1BarE, 
					pDisplay->ChannelLeftPlace1BarF, 
					pDisplay->ChannelLeftPlace1BarG) :
				Segment(pDisplay->ChannelRightPlace1BarA, 
					pDisplay->ChannelRightPlace1BarB, 
					pDisplay->ChannelRightPlace1BarC, 
					pDisplay->ChannelRightPlace1BarD, 
					pDisplay->ChannelRightPlace1BarE, 
					pDisplay->ChannelRightPlace1BarF, 
					pDisplay->ChannelRightPlace1BarG);

			case 2: return left ?
				Segment(pDisplay->ChannelLeftPlace2BarA, 
					pDisplay->ChannelLeftPlace2BarB, 
					pDisplay->ChannelLeftPlace2BarC, 
					pDisplay->ChannelLeftPlace2BarD, 
					pDisplay->ChannelLeftPlace2BarE, 
					pDisplay->ChannelLeftPlace2BarF, 
					pDisplay->ChannelLeftPlace2BarG) :
				Segment(pDisplay->ChannelRightPlace2BarA, 
					pDisplay->ChannelRightPlace2BarB, 
					pDisplay->ChannelRightPlace2BarC, 
					pDisplay->ChannelRightPlace2BarD, 
					pDisplay->ChannelRightPlace2BarE, 
					pDisplay->ChannelRightPlace2BarF, 
					pDisplay->ChannelRightPlace2BarG);

			case 3: return left ?
				Segment(pDisplay->ChannelLeftPlace3BarA, 
					pDisplay->ChannelLeftPlace3BarB, 
					pDisplay->ChannelLeftPlace3BarC, 
					pDisplay->ChannelLeftPlace3BarD, 
					pDisplay->ChannelLeftPlace3BarE, 
					pDisplay->ChannelLeftPlace3BarF, 
					pDisplay->ChannelLeftPlace3BarG) :
				Segment(pDisplay->ChannelRightPlace3BarA, 
					pDisplay->ChannelRightPlace3BarB, 
					pDisplay->ChannelRightPlace3BarC, 
					pDisplay->ChannelRightPlace3BarD, 
					pDisplay->ChannelRightPlace3BarE, 
					pDisplay->ChannelRightPlace3BarF, 
					pDisplay->ChannelRightPlace3BarG);
		}
	}
	else
	{
		switch(place)
		{
			case 1: return left ?
				Segment(pDisplay->FrequencyLeftPlace1BarA, 
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
					pDisplay->FrequencyLeftPlace1BarP,
					pDisplay->FrequencyLeftPlace1BarN) :
				Segment(pDisplay->FrequencyRightPlace1BarA, 
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
					pDisplay->FrequencyRightPlace1BarP,
					pDisplay->FrequencyRightPlace1BarN));
			
			case 2: return left ?
				Segment(pDisplay->FrequencyLeftPlace2BarA, 
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
					pDisplay->FrequencyLeftPlace2BarP,
					pDisplay->FrequencyLeftPlace2BarN) :
				Segment(pDisplay->FrequencyRightPlace2BarA, 
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
					pDisplay->FrequencyRightPlace2BarP,
					pDisplay->FrequencyRightPlace2BarN));

			case 3: return left ?
				Segment(pDisplay->FrequencyLeftPlace3BarA, 
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
					pDisplay->FrequencyLeftPlace3BarP,
					pDisplay->FrequencyLeftPlace3BarN) :
				Segment(pDisplay->FrequencyRightPlace3BarA, 
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
					pDisplay->FrequencyRightPlace3BarP,
					pDisplay->FrequencyRightPlace3BarN));
			
			case 4: return left ?
				Segment(pDisplay->FrequencyLeftPlace4BarA, 
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
					pDisplay->FrequencyLeftPlace4BarP,
					pDisplay->FrequencyLeftPlace4BarN) :
				Segment(pDisplay->FrequencyRightPlace4BarA, 
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
					pDisplay->FrequencyRightPlace4BarP,
					pDisplay->FrequencyRightPlace4BarN));
			
			case 5: return left ?
				Segment(pDisplay->FrequencyLeftPlace5BarA, 
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
					pDisplay->FrequencyLeftPlace5BarP,
					pDisplay->FrequencyLeftPlace5BarN) :
				Segment(pDisplay->FrequencyRightPlace5BarA, 
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
					pDisplay->FrequencyRightPlace5BarP,
					pDisplay->FrequencyRightPlace5BarN));

			case 6: return left ?
				Segment(pDisplay->FrequencyLeftPlace6BarA, 
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
					pDisplay->FrequencyLeftPlace6BarP,
					pDisplay->FrequencyLeftPlace6BarN) :
				Segment(pDisplay->FrequencyRightPlace6BarA, 
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
					pDisplay->FrequencyRightPlace6BarP,
					pDisplay->FrequencyRightPlace6BarN));
	}
}

char Controller::Segment(bool A, bool B, bool C, bool D, bool E, bool F, bool G)
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

char Controller::Segment(bool A, bool B, bool C, bool D, bool E, bool F, bool G, bool M, bool H, bool J, bool K, bool Q, bool P, bool N)
{
	//    AAAAAAA      ----- 
	//   F H J K B    |\ | /|
	//   F  HJK  B    | \|/ |
	//    GGG MMM      -- --
	//   E  QPN  C    | /|\ |
	//   E Q P N C    |/ | \|
	//    DDDDDDDD     -----
	
	if(!A &&  B &&  C && !D && !E && !F && !G && !M && !H && !J && !K && !Q && !P && !N) return '1';
	if( A &&  B && !C &&  D &&  E && !F &&  G &&  M && !H && !J && !K && !Q && !P && !N) return '2';
	if( A &&  B &&  C &&  D && !E && !F &&  G &&  M && !H && !J && !K && !Q && !P && !N) return '3';
	if(!A &&  B &&  C && !D && !E &&  F &&  G &&  M && !H && !J && !K && !Q && !P && !N) return '4';
	if( A && !B &&  C &&  D && !E &&  F &&  G &&  M && !H && !J && !K && !Q && !P && !N) return '5';
	if( A && !B &&  C &&  D &&  E &&  F &&  G &&  M && !H && !J && !K && !Q && !P && !N) return '6';
	if( A &&  B &&  C && !D && !E && !F && !G && !M && !H && !J && !K && !Q && !P && !N) return '7';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M && !H && !J && !K && !Q && !P && !N) return '8';
	if( A &&  B &&  C &&  D && !E &&  F &&  G &&  M && !H && !J && !K && !Q && !P && !N) return '9';
	if( A &&  B &&  C &&  D &&  E &&  F && !G && !M && !H && !J &&  K &&  Q && !P && !N) return '0';

	if( A &&  B &&  C && !D &&  E &&  F &&  G &&  M && !H && !J && !K && !Q && !P && !N) return 'A';
	//TODO: define remaining character mode segments
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'B';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'C';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'D';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'E';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'F';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'G';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'H';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'I';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'J';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'K';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'L';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'M';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'N';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'O';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'P';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'Q';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'R';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'S';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'T';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'U';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'V';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'W';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'X';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'Y';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return 'Z';

	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return '.';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return ',';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return '+';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return '-';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return '*';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return '/';
	if( A &&  B &&  C &&  D &&  E &&  F &&  G &&  M &&  H &&  J &&  K &&  Q &&  P &&  N) return ':';

	return ' ';
}
