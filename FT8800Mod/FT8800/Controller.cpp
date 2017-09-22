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

void Controller::SetPanelToMainUnitPacket(MainUnitToPanelPacketBytes packet)
{
	display = packet;
}

void Controller::SetMainUnitToPanelPacket(PanelToMainUnitPacketBytes packet)
{
	panel = packet;
}

void Controller::Squelch(uint8_t value, bool left)
{
	if(left)	panel.SquelchLeft = value;   // 0x00 - 0x7F
	else		panel.SquelchRight = 0x7F - value; // 0x7F - 0x00
}

void Controller::Volume(uint8_t value, bool left)
{
	if(left)	panel.VolumeLeft = value;  // 0x00 - 0x7F
	else		panel.VolumeRight = value; // 0x00 - 0x7F
}

void Controller::Turn(Direction direction, bool left)
{
	switch(direction)
	{
		case Direction::Left:
		if(left)	panel.DialLeft = 0xFF;
		else		panel.DialRight = 0x7F;
		break;
		
		case Direction::Right:
		if(left)	panel.DialLeft = 0x81;
		else		panel.DialRight = 0x01;
		break;

		case Direction::None:
		if(left)	panel.DialLeft = 0x80;
		else		panel.DialRight = 0x00;
		break;
	}
}

void Controller::Press(Key key, bool left)
{
	switch(key)
	{
		case Key::PTT: panel.PushToTalk = 0x1B; break;

		case Key::Low: left ? panel.KeysLeft = 0x61 : panel.KeysRight = 0x00; break;
		case Key::VM:  left ? panel.KeysLeft = 0x40 : panel.KeysRight = 0x1F; break;
		case Key::HM:  left ? panel.KeysLeft = 0x1F : panel.KeysRight = 0x40; break;
		case Key::Scn: left ? panel.KeysLeft = 0x00 : panel.KeysRight = 0x61; break;

		case Key::Set:     panel.Keys = 0x04; break;
		case Key::DialKey: panel.Keys = left ? 0x02 : 0x01; break;
		case Key::VolSql:  if(left) panel.Keys = 0x08; break; //NOTE: right volume is power on/off

		case Key::H1:  panel.Hyper = 0x01; break;
		case Key::H2:  panel.Hyper = 0x02; break;
		case Key::H3:  panel.Hyper = 0x03; break;
		case Key::H4:  panel.Hyper = 0x04; break;
		case Key::H5:  panel.Hyper = 0x05; break;
		case Key::H6:  panel.Hyper = 0x06; break;
	}
}

void Controller::Press(Number number)
{
	switch(number)
	{
		case Number::Num1:    panel.Mic06 = 0x03; panel.Mic09 = 0x1B; break;
		case Number::Num2:    panel.Mic06 = 0x03; panel.Mic09 = 0x32; break;
		case Number::Num3:    panel.Mic06 = 0x03; panel.Mic09 = 0x4b; break;
		case Number::NumA:    panel.Mic06 = 0x03; panel.Mic09 = 0x66; break;
		
		case Number::Num4:    panel.Mic06 = 0x19; panel.Mic09 = 0x1B; break;
		case Number::Num5:    panel.Mic06 = 0x19; panel.Mic09 = 0x32; break;
		case Number::Num6:    panel.Mic06 = 0x19; panel.Mic09 = 0x4B; break;
		case Number::NumB:    panel.Mic06 = 0x19; panel.Mic09 = 0x66; break;
		
		case Number::Num7:    panel.Mic06 = 0x31; panel.Mic09 = 0x1B; break;
		case Number::Num8:    panel.Mic06 = 0x31; panel.Mic09 = 0x32; break;
		case Number::Num9:    panel.Mic06 = 0x31; panel.Mic09 = 0x4B; break;
		case Number::NumC:    panel.Mic06 = 0x31; panel.Mic09 = 0x66; break;
		
		case Number::NumStar: panel.Mic06 = 0x4B; panel.Mic09 = 0x1C; break;
		case Number::Num0:    panel.Mic06 = 0x4B; panel.Mic09 = 0x33; break;
		case Number::NumHash: panel.Mic06 = 0x4B; panel.Mic09 = 0x4B; break;
		case Number::NumD:    panel.Mic06 = 0x4B; panel.Mic09 = 0x66; break;
		
		case Number::NumP1:   panel.Mic06 = 0x63; panel.Mic09 = 0x1C; break;
		case Number::NumP2:   panel.Mic06 = 0x63; panel.Mic09 = 0x33; break;
		case Number::NumP3:   panel.Mic06 = 0x63; panel.Mic09 = 0x4B; break;
		case Number::NumP4:   panel.Mic06 = 0x63; panel.Mic09 = 0x66; break;
		
		case Number::NumDown: panel.Mic06 = 0x1D; panel.Mic09 = 0x06; break;
		case Number::NumUp:   panel.Mic06 = 0x34; panel.Mic09 = 0x06; break;
	}
}

bool Controller::SelectedVfo(bool left)
{
	auto selected = left ? display.MainLeft : display.MainRight;
	return selected != 0;
}

char Controller::Segment(uint8_t place, bool left, bool channelMode)
{
	if(channelMode)
	{
		switch(place)
		{
			case 1: return left ?
			Segment(
			display.ChannelLeftPlace1BarA,
			display.ChannelLeftPlace1BarB,
			display.ChannelLeftPlace1BarC,
			display.ChannelLeftPlace1BarD,
			display.ChannelLeftPlace1BarE,
			display.ChannelLeftPlace1BarF,
			display.ChannelLeftPlace1BarG) :
			Segment(
			display.ChannelRightPlace1BarA,
			display.ChannelRightPlace1BarB,
			display.ChannelRightPlace1BarC,
			display.ChannelRightPlace1BarD,
			display.ChannelRightPlace1BarE,
			display.ChannelRightPlace1BarF,
			display.ChannelRightPlace1BarG);

			case 2: return left ?
			Segment(
			display.ChannelLeftPlace2BarA,
			display.ChannelLeftPlace2BarB,
			display.ChannelLeftPlace2BarC,
			display.ChannelLeftPlace2BarD,
			display.ChannelLeftPlace2BarE,
			display.ChannelLeftPlace2BarF,
			display.ChannelLeftPlace2BarG) :
			Segment(
			display.ChannelRightPlace2BarA,
			display.ChannelRightPlace2BarB,
			display.ChannelRightPlace2BarC,
			display.ChannelRightPlace2BarD,
			display.ChannelRightPlace2BarE,
			display.ChannelRightPlace2BarF,
			display.ChannelRightPlace2BarG);

			case 3: return left ?
			Segment(
			display.ChannelLeftPlace3BarA,
			display.ChannelLeftPlace3BarB,
			display.ChannelLeftPlace3BarC,
			display.ChannelLeftPlace3BarD,
			display.ChannelLeftPlace3BarE,
			display.ChannelLeftPlace3BarF,
			display.ChannelLeftPlace3BarG) :
			Segment(
			display.ChannelRightPlace3BarA,
			display.ChannelRightPlace3BarB,
			display.ChannelRightPlace3BarC,
			display.ChannelRightPlace3BarD,
			display.ChannelRightPlace3BarE,
			display.ChannelRightPlace3BarF,
			display.ChannelRightPlace3BarG);
		}
	}
	else
	{
		switch(place)
		{
			case 1: return left ?
			Segment(
			display.FrequencyLeftPlace1BarA,
			display.FrequencyLeftPlace1BarB,
			display.FrequencyLeftPlace1BarC,
			display.FrequencyLeftPlace1BarD,
			display.FrequencyLeftPlace1BarE,
			display.FrequencyLeftPlace1BarF,
			display.FrequencyLeftPlace1BarG,
			display.FrequencyLeftPlace1BarM,
			display.FrequencyLeftPlace1BarH,
			display.FrequencyLeftPlace1BarJ,
			display.FrequencyLeftPlace1BarK,
			display.FrequencyLeftPlace1BarQ,
			display.FrequencyLeftPlace1BarP,
			display.FrequencyLeftPlace1BarN) :
			Segment(
			display.FrequencyRightPlace1BarA,
			display.FrequencyRightPlace1BarB,
			display.FrequencyRightPlace1BarC,
			display.FrequencyRightPlace1BarD,
			display.FrequencyRightPlace1BarE,
			display.FrequencyRightPlace1BarF,
			display.FrequencyRightPlace1BarG,
			display.FrequencyRightPlace1BarM,
			display.FrequencyRightPlace1BarH,
			display.FrequencyRightPlace1BarJ,
			display.FrequencyRightPlace1BarK,
			display.FrequencyRightPlace1BarQ,
			display.FrequencyRightPlace1BarP,
			display.FrequencyRightPlace1BarN);
			
			case 2: return left ?
			Segment(
			display.FrequencyLeftPlace2BarA,
			display.FrequencyLeftPlace2BarB,
			display.FrequencyLeftPlace2BarC,
			display.FrequencyLeftPlace2BarD,
			display.FrequencyLeftPlace2BarE,
			display.FrequencyLeftPlace2BarF,
			display.FrequencyLeftPlace2BarG,
			display.FrequencyLeftPlace2BarM,
			display.FrequencyLeftPlace2BarH,
			display.FrequencyLeftPlace2BarJ,
			display.FrequencyLeftPlace2BarK,
			display.FrequencyLeftPlace2BarQ,
			display.FrequencyLeftPlace2BarP,
			display.FrequencyLeftPlace2BarN) :
			Segment(
			display.FrequencyRightPlace2BarA,
			display.FrequencyRightPlace2BarB,
			display.FrequencyRightPlace2BarC,
			display.FrequencyRightPlace2BarD,
			display.FrequencyRightPlace2BarE,
			display.FrequencyRightPlace2BarF,
			display.FrequencyRightPlace2BarG,
			display.FrequencyRightPlace2BarM,
			display.FrequencyRightPlace2BarH,
			display.FrequencyRightPlace2BarJ,
			display.FrequencyRightPlace2BarK,
			display.FrequencyRightPlace2BarQ,
			display.FrequencyRightPlace2BarP,
			display.FrequencyRightPlace2BarN);

			case 3: return left ?
			Segment(
			display.FrequencyLeftPlace3BarA,
			display.FrequencyLeftPlace3BarB,
			display.FrequencyLeftPlace3BarC,
			display.FrequencyLeftPlace3BarD,
			display.FrequencyLeftPlace3BarE,
			display.FrequencyLeftPlace3BarF,
			display.FrequencyLeftPlace3BarG,
			display.FrequencyLeftPlace3BarM,
			display.FrequencyLeftPlace3BarH,
			display.FrequencyLeftPlace3BarJ,
			display.FrequencyLeftPlace3BarK,
			display.FrequencyLeftPlace3BarQ,
			display.FrequencyLeftPlace3BarP,
			display.FrequencyLeftPlace3BarN) :
			Segment(
			display.FrequencyRightPlace3BarA,
			display.FrequencyRightPlace3BarB,
			display.FrequencyRightPlace3BarC,
			display.FrequencyRightPlace3BarD,
			display.FrequencyRightPlace3BarE,
			display.FrequencyRightPlace3BarF,
			display.FrequencyRightPlace3BarG,
			display.FrequencyRightPlace3BarM,
			display.FrequencyRightPlace3BarH,
			display.FrequencyRightPlace3BarJ,
			display.FrequencyRightPlace3BarK,
			display.FrequencyRightPlace3BarQ,
			display.FrequencyRightPlace3BarP,
			display.FrequencyRightPlace3BarN);
			
			case 4: return left ?
			Segment(
			display.FrequencyLeftPlace4BarA,
			display.FrequencyLeftPlace4BarB,
			display.FrequencyLeftPlace4BarC,
			display.FrequencyLeftPlace4BarD,
			display.FrequencyLeftPlace4BarE,
			display.FrequencyLeftPlace4BarF,
			display.FrequencyLeftPlace4BarG,
			display.FrequencyLeftPlace4BarM,
			display.FrequencyLeftPlace4BarH,
			display.FrequencyLeftPlace4BarJ,
			display.FrequencyLeftPlace4BarK,
			display.FrequencyLeftPlace4BarQ,
			display.FrequencyLeftPlace4BarP,
			display.FrequencyLeftPlace4BarN) :
			Segment(
			display.FrequencyRightPlace4BarA,
			display.FrequencyRightPlace4BarB,
			display.FrequencyRightPlace4BarC,
			display.FrequencyRightPlace4BarD,
			display.FrequencyRightPlace4BarE,
			display.FrequencyRightPlace4BarF,
			display.FrequencyRightPlace4BarG,
			display.FrequencyRightPlace4BarM,
			display.FrequencyRightPlace4BarH,
			display.FrequencyRightPlace4BarJ,
			display.FrequencyRightPlace4BarK,
			display.FrequencyRightPlace4BarQ,
			display.FrequencyRightPlace4BarP,
			display.FrequencyRightPlace4BarN);
			
			case 5: return left ?
			Segment(
			display.FrequencyLeftPlace5BarA,
			display.FrequencyLeftPlace5BarB,
			display.FrequencyLeftPlace5BarC,
			display.FrequencyLeftPlace5BarD,
			display.FrequencyLeftPlace5BarE,
			display.FrequencyLeftPlace5BarF,
			display.FrequencyLeftPlace5BarG,
			display.FrequencyLeftPlace5BarM,
			display.FrequencyLeftPlace5BarH,
			display.FrequencyLeftPlace5BarJ,
			display.FrequencyLeftPlace5BarK,
			display.FrequencyLeftPlace5BarQ,
			display.FrequencyLeftPlace5BarP,
			display.FrequencyLeftPlace5BarN) :
			Segment(
			display.FrequencyRightPlace5BarA,
			display.FrequencyRightPlace5BarB,
			display.FrequencyRightPlace5BarC,
			display.FrequencyRightPlace5BarD,
			display.FrequencyRightPlace5BarE,
			display.FrequencyRightPlace5BarF,
			display.FrequencyRightPlace5BarG,
			display.FrequencyRightPlace5BarM,
			display.FrequencyRightPlace5BarH,
			display.FrequencyRightPlace5BarJ,
			display.FrequencyRightPlace5BarK,
			display.FrequencyRightPlace5BarQ,
			display.FrequencyRightPlace5BarP,
			display.FrequencyRightPlace5BarN);

			case 6: return left ?
			Segment(
			display.FrequencyLeftPlace6BarA,
			display.FrequencyLeftPlace6BarB,
			display.FrequencyLeftPlace6BarC,
			display.FrequencyLeftPlace6BarD,
			display.FrequencyLeftPlace6BarE,
			display.FrequencyLeftPlace6BarF,
			display.FrequencyLeftPlace6BarG,
			display.FrequencyLeftPlace6BarM,
			display.FrequencyLeftPlace6BarH,
			display.FrequencyLeftPlace6BarJ,
			display.FrequencyLeftPlace6BarK,
			display.FrequencyLeftPlace6BarQ,
			display.FrequencyLeftPlace6BarP,
			display.FrequencyLeftPlace6BarN) :
			Segment(
			display.FrequencyRightPlace6BarA,
			display.FrequencyRightPlace6BarB,
			display.FrequencyRightPlace6BarC,
			display.FrequencyRightPlace6BarD,
			display.FrequencyRightPlace6BarE,
			display.FrequencyRightPlace6BarF,
			display.FrequencyRightPlace6BarG,
			display.FrequencyRightPlace6BarM,
			display.FrequencyRightPlace6BarH,
			display.FrequencyRightPlace6BarJ,
			display.FrequencyRightPlace6BarK,
			display.FrequencyRightPlace6BarQ,
			display.FrequencyRightPlace6BarP,
			display.FrequencyRightPlace6BarN);
		}
	}
	
	return ' ';
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
	if( A &&  B &&  C &&  D && !E && !F && !G &&  M && !H &&  J && !K && !Q &&  P && !N) return 'B';
	if( A && !B && !C &&  D &&  E &&  F && !G && !M && !H && !J && !K && !Q && !P && !N) return 'C';
	if( A &&  B &&  C &&  D && !E && !F && !G && !M && !H &&  J && !K && !Q &&  P && !N) return 'D';
	if( A && !B && !C &&  D &&  E &&  F &&  G &&  M && !H && !J && !K && !Q && !P && !N) return 'E';
	if( A && !B && !C && !D &&  E &&  F &&  G &&  M && !H && !J && !K && !Q && !P && !N) return 'F';
	if( A && !B &&  C &&  D &&  E &&  F && !G &&  M && !H && !J && !K && !Q && !P && !N) return 'G';
	if(!A &&  B &&  C && !D &&  E &&  F &&  G &&  M && !H && !J && !K && !Q && !P && !N) return 'H';
	if( A && !B && !C &&  D && !E && !F && !G && !M && !H &&  J && !K && !Q &&  P && !N) return 'I';
	if( A &&  B &&  C &&  D &&  E && !F && !G && !M && !H && !J && !K && !Q && !P && !N) return 'J';
	if(!A && !B && !C && !D &&  E &&  F &&  G && !M && !H && !J &&  K && !Q && !P &&  N) return 'K';
	if(!A && !B && !C &&  D &&  E &&  F && !G && !M && !H && !J && !K && !Q && !P && !N) return 'L';
	if(!A &&  B &&  C && !D &&  E &&  F && !G && !M &&  H && !J &&  K && !Q && !P && !N) return 'M';
	if(!A &&  B &&  C && !D &&  E &&  F && !G && !M &&  H && !J && !K && !Q && !P &&  N) return 'N';
	if( A &&  B &&  C &&  D &&  E &&  F && !G && !M && !H && !J && !K && !Q && !P && !N) return 'O';
	if( A &&  B && !C && !D &&  E &&  F &&  G &&  M && !H && !J && !K && !Q && !P && !N) return 'P';
	if( A &&  B &&  C &&  D &&  E &&  F && !G && !M && !H && !J && !K && !Q && !P &&  N) return 'Q';
	if( A &&  B && !C && !D &&  E &&  F &&  G &&  M && !H && !J && !K && !Q && !P &&  N) return 'R';
	if( A && !B && !C &&  D && !E &&  F &&  G && !M && !H && !J && !K && !Q && !P &&  N) return 'S';
	if( A && !B && !C && !D && !E && !F && !G && !M && !H &&  J && !K && !Q &&  P && !N) return 'T';
	if(!A &&  B &&  C &&  D &&  E &&  F && !G && !M && !H && !J && !K && !Q && !P && !N) return 'U';
	if(!A && !B && !C && !D &&  E &&  F && !G && !M && !H && !J &&  K &&  Q && !P && !N) return 'V';
	if(!A &&  B &&  C && !D &&  E &&  F && !G && !M && !H && !J && !K &&  Q && !P &&  N) return 'W';
	if(!A && !B && !C && !D && !E && !F && !G && !M &&  H && !J &&  K &&  Q && !P &&  N) return 'X';
	if(!A && !B && !C && !D && !E && !F && !G && !M &&  H && !J &&  K && !Q &&  P && !N) return 'Y';
	if( A && !B && !C &&  D && !E && !F && !G && !M && !H && !J &&  K &&  Q && !P && !N) return 'Z';

	//    AAAAAAA      -----
	//   F H J K B    |\ | /|
	//   F  HJK  B    | \|/ |
	//    GGG MMM      -- --
	//   E  QPN  C    | /|\ |
	//   E Q P N C    |/ | \|
	//    DDDDDDDD     -----
	
	//if(!A && !B && !C && !D && !E && !F && !G && !M && !H && !J && !K && !Q && !P && !N) return '.';
	//if(!A && !B && !C && !D && !E && !F && !G && !M && !H && !J && !K && !Q && !P && !N) return ',';
	//if(!A && !B && !C && !D && !E && !F && !G && !M && !H && !J && !K && !Q && !P && !N) return '+';
	//if(!A && !B && !C && !D && !E && !F && !G && !M && !H && !J && !K && !Q && !P && !N) return '-';
	//if(!A && !B && !C && !D && !E && !F && !G && !M && !H && !J && !K && !Q && !P && !N) return '*';
	//if(!A && !B && !C && !D && !E && !F && !G && !M && !H && !J && !K && !Q && !P && !N) return '/';
	//if(!A && !B && !C && !D && !E && !F && !G && !M && !H && !J && !K && !Q && !P && !N) return ':';

	return ' ';
}
