/*
* Packet.h
*
* Created: 08.09.2017 22:55:20
*  Author: thosch
*/


#ifndef PACKET_H_
#define PACKET_H_

// see http://www.dg1sfj.de/index.php/funk/geraete/88-yaesu-ft-8800?showall=&start=2 for more information

#pragma pack(1)
typedef struct
{
	// 01    01    Kleine kHz 5 links
	uint8_t FrequencyLeftFiveKhz : 1;
	
	// 01    02    Automatic Power Off Active
	uint8_t AutomaticPowerOffActive : 1;
	
	// 01    04    Middle TX Power links
	uint8_t TxPowerLeftMiddle : 1;
	
	// 01    08    Dezimal-Punkt kHz links
	uint8_t FrequencyLeftDecimalPointKhz : 1;
	
	// 01    10    S-Meter links Balken 9
	uint8_t SignalLeftBar9 : 1;
	
	// 01    20    Frequenz links Stelle 6 Balken C
	uint8_t FrequencyLeftPlace6BarC : 1;
	
	// 01    40    Frequenz links Stelle 6 Balken M
	uint8_t FrequencyLeftPlace6BarM : 1;
	
	// 01    80    ???
	uint8_t Unknown0180 : 1;
	
	
	
	// 02    80    ???
	uint8_t Unknown0280 : 1;
	
	// 02    40    Frequenz links Stelle 6 Balken N
	uint8_t FrequencyLeftPlace6BarN : 1;
	
	// 02    20    Low TX Power links
	uint8_t TyPowerLeftLow : 1;

	// 02    10    Frequenz links Stelle 6 Balken H
	uint8_t FrequencyLeftPlace6BarH : 1;

	// 02    08    Frequenz links Stelle 6 Balken G
	uint8_t FrequencyLeftPlace6BarG : 1;

	// 02    04    Frequenz links Stelle 6 Balken A
	uint8_t FrequencyLeftPlace6BarA : 1;

	// 02    02    Frequenz links Stelle 6 Balken K
	uint8_t FrequencyLeftPlace6BarK : 1;

	// 02    01    Frequenz links Stelle 6 Balken B
	uint8_t FrequencyLeftPlace6BarB : 1;

	
	
	// 03    80    ???
	uint8_t Unknown0380 : 1;
	
	// 03    40    S-Meter links Balken 7
	uint8_t SignalLeftBar7 : 1;
	
	// 03    20    Frequenz links Stelle 6 Balken F
	uint8_t FrequencyLeftPlace6BarF : 1;

	// 03    10    Frequenz links Stelle 6 Balken E
	uint8_t FrequencyLeftPlace6BarE : 1;

	// 03    08    Frequenz links Stelle 6 Balken Q
	uint8_t FrequencyLeftPlace6BarQ : 1;

	// 03    04    S-Meter links Balken 8
	uint8_t SignalLeftBar8 : 1;

	// 03    02    Frequenz links Stelle 6 Balken J+P
	uint8_t FrequencyLeftPlace6BarJP : 1;
	
	// 03    01    Frequenz links Stelle 6 Balken D
	uint8_t FrequencyLeftPlace6BarD : 1;
	

	
	// 04    80    ???
	uint8_t Unknown0480 : 1;
	
	// 04    40    Frequenz links Stelle 5 Balken H
	uint8_t FrequencyLeftPlace5BarH : 1;
	
	// 04    20    Frequenz links Stelle 5 Balken G
	uint8_t FrequencyLeftPlace5BarG : 1;
	
	// 04    10    Frequenz links Stelle 5 Balken A
	uint8_t FrequencyLeftPlace5BarA : 1;
	
	// 04    08    Frequenz links Stelle 5 Balken K
	uint8_t FrequencyLeftPlace5BarK : 1;
	
	// 04    04    Frequenz links Stelle 5 Balken B
	uint8_t FrequencyLeftPlace5BarB : 1;
	
	// 04    02    Frequenz links Stelle 5 Balken M
	uint8_t FrequencyLeftPlace5BarM : 1;
	
	// 04    01    Frequenz links Stelle 5 Balken C
	uint8_t FrequencyLeftPlace5BarC : 1;
	

	
	// 05    80    ???
	uint8_t Unknown0580 : 1;
	
	// 05    40    Frequenz links Stelle 5 Balken E
	uint8_t FrequencyLeftPlace5BarE : 1;
	
	// 05    20    Frequenz links Stelle 5 Balken Q
	uint8_t FrequencyLeftPlace5BarQ : 1;
	
	// 05    10    S-Meter links Balken 6
	uint8_t SignalLeftBar6 : 1;
	
	// 05    08    Frequenz links Stelle 5 Balken J+P
	uint8_t FrequencyLeftPlace5BarJP : 1;
	
	// 05    04    Frequenz links Stelle 5 Balken D
	uint8_t FrequencyLeftPlace5BarD : 1;
	
	// 05    02    Frequenz links Stelle 5 Balken N
	uint8_t FrequencyLeftPlace5BarN : 1;
	
	// 05    01    9600 bps links
	uint8_t DataLeft9600bps : 1;
	

	
	// 06    80    ???
	uint8_t Unknown0680 : 1;
	
	// 06    40    Frequenz links Stelle 4 Balken A
	uint8_t FrequencyLeftPlace4BarA : 1;
	
	// 06    20    Frequenz links Stelle 4 Balken K
	uint8_t FrequencyLeftPlace4BarK : 1;

	// 06    10    Frequenz links Stelle 4 Balken B
	uint8_t FrequencyLeftPlace4BarB : 1;

	// 06    08    Frequenz links Stelle 4 Balken M
	uint8_t FrequencyLeftPlace4BarM : 1;

	// 06    04    Frequenz links Stelle 4 Balken C
	uint8_t FrequencyLeftPlace4BarC : 1;

	// 06    02    S-Meter links Balken 5
	uint8_t SignalLeftBar5 : 1;

	// 06    01    Frequenz links Stelle 5 Balken F
	uint8_t FrequencyLeftPlace5BarF : 1;


	// 07    80    ???
	uint8_t Unknown0780 : 1;
	
	// 07    40    S-Meter links Balken 4
	uint8_t SignalLeftBar4 : 1;

	// 07    20    Frequenz links Stelle 4 Balken J+P
	uint8_t FrequencyLeftPlace4BarJP : 1;

	// 07    10    Frequenz links Stelle 4 Balken D
	uint8_t FrequencyLeftPlace4BarD : 1;

	// 07    08    Frequenz links Stelle 4 Balken N
	uint8_t FrequencyLeftPlace4BarN : 1;

	// 07    04    AM links
	uint8_t AmplitudeModulationLeft : 1;

	// 07    02    Frequenz links Stelle 4 Balken H
	uint8_t FrequencyLeftPlace4BarH : 1;

	// 07    01    Frequenz links Stelle 4 Balken G
	uint8_t FrequencyLeftPlace4BarG : 1;


	
	// 08    80    ???
	uint8_t Unknown0880 : 1;

	// 08    40    ???
	uint8_t Unknown0840 : 1;

	// 08    20    ???
	uint8_t Unknown0820 : 1;

	// 08    10    ???
	uint8_t Unknown0810 : 1;

	// 08    08    ???
	uint8_t Unknown0808 : 1;

	// 08    04    Frequenz links Stelle 4 Balken F
	uint8_t FrequencyLeftPlace4BarF : 1;

	// 08    02    Frequenz links Stelle 4 Balken E
	uint8_t FrequencyLeftPlace4BarE : 1;
	
	// 08    01    Frequenz links Stelle 4 Balken Q
	uint8_t FrequencyLeftPlace4BarQ : 1;

	
	
	// 09    80    ???
	uint8_t Unknown0980 : 1;

	// 09    40    Frequenz links Stelle 3 Balken K
	uint8_t FrequencyLeftPlace3BarK : 1;

	// 09    20    Frequenz links Stelle 3 Balken B
	uint8_t FrequencyLeftPlace3BarB : 1;

	// 09    10    Frequenz links Stelle 3 Balken M
	uint8_t FrequencyLeftPlace3BarM : 1;

	// 09    08    Frequenz links Stelle 3 Balken C
	uint8_t FrequencyLeftPlace3BarC : 1;

	// 09    04    S-Meter links Balken 3
	uint8_t SignalLeftBar3 : 1;

	// 09    02    ???
	uint8_t Unknown0902 : 1;

	// 09    01    Dezimal-Punkt MHz links
	uint8_t FrequencyLeftDecimalPointMhz : 1; 


	// 10    80    ???
	uint8_t Unknown1080 : 1;

	// 10    40    Frequenz links Stelle 3 Balken J+P
	uint8_t FrequencyLeftPlace3BarJP : 1;

	// 10    20    Frequenz links Stelle 3 Balken D
	uint8_t FrequencyLeftPlace3BarD : 1;

	// 10    10    Frequenz links Stelle 3 Balken N
	uint8_t FrequencyLeftPlace3BarN : 1;

	// 10    08    DCS links
	uint8_t DcsLeft: 1;

	// 10    04    Frequenz links Stelle 3 Balken H
	uint8_t FrequencyLeftPlace3BarH : 1;

	// 10    02    Frequenz links Stelle 3 Balken G
	uint8_t FrequencyLeftPlace3BarG : 1;

	// 10    01    Frequenz links Stelle 3 Balken A
	uint8_t FrequencyLeftPlace3BarA : 1;


	// 11    80    ???
	uint8_t Unknown1180 : 1;

	// 11    40    Frequenz links Stelle 2 Balken M
	uint8_t FrequencyLeftPlace2BarM : 1;

	// 11    20    Frequenz links Stelle 2 Balken C
	uint8_t FrequencyLeftPlace2BarC : 1;

	// 11    10    S-Meter links Balken 1
	uint8_t SignalLeftBar1 : 1;

	// 11    08    Frequenz links Stelle 3 Balken F
	uint8_t FrequencyLeftPlace3BarF : 1;

	// 11    04    Frequenz links Stelle 3 Balken E
	uint8_t FrequencyLeftPlace3BarE : 1;

	// 11    02    Frequenz links Stelle 3 Balken Q
	uint8_t FrequencyLeftPlace3BarQ : 1;

	// 11    01    S-Meter links Balken 2
	uint8_t SignalLeftBar2 : 1;


	
	// 12    80    ???
	uint8_t Unknown1280 : 1;
	
	// 12    40    Frequenz links Stelle 2 Balken N
	uint8_t FrequencyLeftPlace2BarN : 1;

	// 12    20    MUTE links
	uint8_t MuteLeft : 1;
	
	// 12    10    Frequenz links Stelle 2 Balken H
	uint8_t FrequencyLeftPlace2BarH : 1;

	// 12    08    Frequenz links Stelle 2 Balken G
	uint8_t FrequencyLeftPlace2BarG : 1;

	// 12    04    Frequenz links Stelle 2 Balken A
	uint8_t FrequencyLeftPlace2BarA : 1;

	// 12    02    Frequenz links Stelle 2 Balken K
	uint8_t FrequencyLeftPlace2BarK : 1;

	// 12    01    Frequenz links Stelle 2 Balken B
	uint8_t FrequencyLeftPlace2BarB : 1;


	
	// 13    80    ???
	uint8_t Unknown1380 : 1;
	
	// 13    40    Memory Tune links
	uint8_t MemoryTuneLeft : 1;

	// 13    20    Frequenz links Stelle 2 Balken F
	uint8_t FrequencyLeftPlace2BarF : 1;

	// 13    10    Frequenz links Stelle 2 Balken E
	uint8_t FrequencyLeftPlace2BarE : 1;

	// 13    08    Frequenz links Stelle 2 Balken Q
	uint8_t FrequencyLeftPlace2BarQ : 1;

	// 13    04    BUSY links
	uint8_t BusyLeft : 1;

	// 13    02    Frequenz links Stelle 2 Balken J+P
	uint8_t FrequencyLeftPlace2BarJP : 1;

	// 13    01    Frequenz links Stelle 2 Balken D
	uint8_t FrequencyLeftPlace2BarD : 1;


	// 14    80    ???
	uint8_t Unknown1480 : 1;

	// 14    40    Frequenz links Stelle 1 Balken H
	uint8_t FrequencyLeftPlace1BarH : 1;

	// 14    20    Frequenz links Stelle 1 Balken G
	uint8_t FrequencyLeftPlace1BarG : 1;

	// 14    10    Frequenz links Stelle 1 Balken A
	uint8_t FrequencyLeftPlace1BarA : 1;

	// 14    08    Frequenz links Stelle 1 Balken K
	uint8_t FrequencyLeftPlace1BarK : 1;

	// 14    04    Frequenz links Stelle 1 Balken B
	uint8_t FrequencyLeftPlace1BarB : 1;

	// 14    02    Frequenz links Stelle 1 Balken M
	uint8_t FrequencyLeftPlace1BarM : 1;

	// 14    01    Frequenz links Stelle 1 Balken C
	uint8_t FrequencyLeftPlace1BarC : 1;


	// 15    80    ???
	uint8_t Unknown1580 : 1;

	// 15    40    Frequenz links Stelle 1 Balken E
	uint8_t FrequencyLeftPlace1BarE : 1;

	// 15    20    Frequenz links Stelle 1 Balken Q
	uint8_t FrequencyLeftPlace1BarQ : 1;

	// 15    10    ???
	uint8_t Unknown1510 : 1;

	// 15    08    Frequenz links Stelle 1 Balken J+P
	uint8_t FrequencyLeftPlace1BarJP : 1;

	// 15    04    Frequenz links Stelle 1 Balken D
	uint8_t FrequencyLeftPlace1BarD : 1;

	// 15    02    Frequenz links Stelle 1 Balken N
	uint8_t FrequencyLeftPlace1BarN : 1;

	// 15    01    ???
	uint8_t Unknown1501 : 1;

	

	// 16    80    ???
	uint8_t Unknwon1680 : 1;

	// 16    40    ???
	uint8_t Unknown1640 : 1;

	// 16    20    ???
	uint8_t Unknown1620 : 1;

	// 16    10    ???
	uint8_t Unknown1610 : 1;

	// 16    08    ???
	uint8_t Unknown1608 : 1;

	// 16    04    ???
	uint8_t Unknown1604 : 1;

	// 16    02    ???
	uint8_t Unknown1602 : 1;

	// 16    01    Frequenz links Stelle 1 Balken F
	uint8_t FrequencyLeftPlace1BarF : 1;

	

	// 17    80    ???
	uint8_t Unknown1780 : 1;

	// 17    40    Frequenz rechts Stelle 6 Balken M
	uint8_t FrequencyRightPlace6BarM : 1;

	// 17    20    Frequenz rechts Stelle 6 Balken C
	uint8_t FrequencyRightPlace6BarC : 1;

	// 17    10    S-Meter rechts Balken 9
	uint8_t SignalRightBar9 : 1;

	// 17    08    Dezimal-Punkt kHz rechts
	uint8_t FrequencyRightDecimalPointKhz : 1;

	// 17    04    Middle TX Power rechts
	uint8_t TxPowerRightMiddle : 1;

	// 17    02    ???
	uint8_t Unknown1702 : 1;

	// 17    01    Kleine kHz 5 rechts
	uint8_t FrequencyRightFiveKhz : 1;


	
	// 18    80    ???
	// 18    40    Frequenz rechts Stelle 6 Balken N
	// 18    20    Low TX Power rechts
	// 18    10    Frequenz rechts Stelle 6 Balken H
	// 18    08    Frequenz rechts Stelle 6 Balken G
	// 18    04    Frequenz rechts Stelle 6 Balken A
	// 18    02    Frequenz rechts Stelle 6 Balken K
	// 18    01    Frequenz rechts Stelle 6 Balken B

	// 19    80    ???
	// 19    40    S-Meter rechts Balken 7
	// 19    20    Frequenz rechts Stelle 6 Balken F
	// 19    10    Frequenz rechts Stelle 6 Balken E
	// 19    08    Frequenz rechts Stelle 6 Balken Q
	// 19    04    S-Meter rechts Balken 8
	// 19    02    Frequenz rechts Stelle 6 Balken J+P
	// 19    01    Frequenz rechts Stelle 6 Balken D

	// 20    80    ???
	// 20    40    Frequenz rechts Stelle 5 Balken H
	// 20    20    Frequenz rechts Stelle 5 Balken G
	// 20    10    Frequenz rechts Stelle 5 Balken A
	// 20    08    Frequenz rechts Stelle 5 Balken K
	// 20    04    Frequenz rechts Stelle 5 Balken B
	// 20    02    Frequenz rechts Stelle 5 Balken M
	// 20    01    Frequenz rechts Stelle 5 Balken C

	// 21    80    ???
	// 21    40    Frequenz rechts Stelle 5 Balken E
	// 21    20    Frequenz rechts Stelle 5 Balken Q
	// 21    10    S-Meter rechts Balken 6
	// 21    08    Frequenz rechts Stelle 5 Balken J+P
	// 21    04    Frequenz rechts Stelle 5 Balken D
	// 21    02    Frequenz rechts Stelle 5 Balken N
	// 21    01    9600 bps rechts

	// 22    80    ???
	// 22    40    Frequenz rechts Stelle 4 Balken A
	// 22    20    Frequenz rechts Stelle 4 Balken K
	// 22    10    Frequenz rechts Stelle 4 Balken B
	// 22    08    Frequenz rechts Stelle 4 Balken M
	// 22    04    Frequenz rechts Stelle 4 Balken C
	// 22    02    S-Meter rechts Balken 5
	// 22    01    Frequenz rechts Stelle 5 Balken F

	// 23    80    ???
	// 23    40    S-Meter rechts Balken 4
	// 23    20    Frequenz rechts Stelle 4 Balken J+P
	// 23    10    Frequenz rechts Stelle 4 Balken D
	// 23    08    Frequenz rechts Stelle 4 Balken N
	// 23    04    DCS rechts
	// 23    02    Frequenz rechts Stelle 4 Balken H
	// 23    01    Frequenz rechts Stelle 4 Balken G

	// 24    80    ???
	// 24    40    ???
	// 24    20    ???
	// 24    10    ???
	// 24    08    ???
	// 24    04    Frequenz rechts Stelle 4 Balken F
	// 24    02    Frequenz rechts Stelle 4 Balken E
	// 24    01    Frequenz rechts Stelle 4 Balken Q

	// 25    80    ???
	// 25    40    Frequenz rechts Stelle 3 Balken K
	// 25    20    Frequenz rechts Stelle 3 Balken B
	// 25    10    Frequenz rechts Stelle 3 Balken M
	// 25    08    Frequenz rechts Stelle 3 Balken C
	// 25    04    S-Meter rechts Balken 3
	// 25    02    ???
	// 25    01    Dezimal-Punkt MHz rechts

	// 26    80    ???
	// 26    40    Frequenz rechts Stelle 3 Balken J+P
	// 26    20    Frequenz rechts Stelle 3 Balken D
	// 26    10    Frequenz rechts Stelle 3 Balken N
	// 26    08    MUTE rechts
	// 26    04    Frequenz rechts Stelle 3 Balken H
	// 26    02    Frequenz rechts Stelle 3 Balken G
	// 26    01    Frequenz rechts Stelle 3 Balken A

	// 27    80    ???
	// 27    40    Frequenz rechts Stelle 2 Balken M
	// 27    20    Frequenz rechts Stelle 2 Balken C
	// 27    10    S-Meter rechts Balken 1
	// 27    08    Frequenz rechts Stelle 3 Balken F
	// 27    04    Frequenz rechts Stelle 3 Balken E
	// 27    02    Frequenz rechts Stelle 3 Balken Q
	// 27    01    S-Meter rechts Balken 2

	// 28    80    ???
	// 28    40    Frequenz rechts Stelle 2 Balken N
	// 28    20    Memory Tune rechts
	// 28    10    Frequenz rechts Stelle 2 Balken H
	// 28    08    Frequenz rechts Stelle 2 Balken G
	// 28    04    Frequenz rechts Stelle 2 Balken A
	// 28    02    Frequenz rechts Stelle 2 Balken K
	// 28    01    Frequenz rechts Stelle 2 Balken B

	// 29    80    ???
	// 29    40    KEY2
	// 29    20    Frequenz rechts Stelle 2 Balken F
	// 29    10    Frequenz rechts Stelle 2 Balken E
	// 29    08    Frequenz rechts Stelle 2 Balken Q
	// 29    04    BUSY rechts
	// 29    02    Frequenz rechts Stelle 2 Balken J+P
	// 29    01    Frequenz rechts Stelle 2 Balken D

	// 30    80    ???
	// 30    40    Frequenz rechts Stelle 1 Balken H
	// 30    20    Frequenz rechts Stelle 1 Balken G
	// 30    10    Frequenz rechts Stelle 1 Balken A
	// 30    08    Frequenz rechts Stelle 1 Balken K
	// 30    04    Frequenz rechts Stelle 1 Balken B
	// 30    02    Frequenz rechts Stelle 1 Balken M
	// 30    01    Frequenz rechts Stelle 1 Balken C

	// 31    80    ???
	// 31    40    Frequenz rechts Stelle 1 Balken E
	// 31    20    Frequenz rechts Stelle 1 Balken Q
	// 31    10    Keypad Lock
	// 31    08    Frequenz rechts Stelle 1 Balken J+P
	// 31    04    Frequenz rechts Stelle 1 Balken D
	// 31    02    Frequenz rechts Stelle 1 Balken N
	// 31    01    SET

	// 32    80    ???
	// 32    40    ???
	// 32    20    ???
	// 32    10    ???
	// 32    08    ???
	// 32    04    ???
	// 32    02    ???
	// 32    01    Frequenz rechts Stelle 1 Balken F

	// 33    80    ???
	// 33    40    Preferential Memory rechts
	// 33    20    DEC rechts
	// 33    10    ENC rechts
	// 33    08    Negativ rechts
	// 33    04    Positiv rechts
	// 33    02    TX rechts
	// 33    01    MAIN rechts

	// 34    80    ???
	// 34    40    Kanal rechts Stelle 3 Balken F
	// 34    20    Kanal rechts Stelle 3 Balken E
	// 34    10    Kanal rechts Stelle 3 Balken A
	// 34    08    Kanal rechts Stelle 3 Balken G
	// 34    04    Kanal rechts Stelle 3 Balken B
	// 34    02    Kanal rechts Stelle 3 Balken C
	// 34    01    SKIP rechts

	// 35    80    ???
	// 35    40    Kanal rechts Stelle 2 Balken E
	// 35    20    Kanal rechts Stelle 2 Balken A
	// 35    10    Kanal rechts Stelle 2 Balken G
	// 35    08    Kanal rechts Stelle 2 Balken B
	// 35    04    Kanal rechts Stelle 2 Balken C
	// 35    02    Kanal rechts Stelle 1 Balken D
	// 35    01    Kanal rechts Stelle 3 Balken D

	// 36    80    ???
	// 36    40    Kanal rechts Stelle 1 Balken A
	// 36    20    Kanal rechts Stelle 1 Balken G
	// 36    10    Kanal rechts Stelle 1 Balken B
	// 36    08    Kanal rechts Stelle 1 Balken C
	// 36    04    Kanal rechts Trennstrich
	// 36    02    Kanal rechts Stelle 2 Balken D
	// 36    01    Kanal rechts Stelle 2 Balken F

	// 37    80    ???
	// 37    40    ENC links
	// 37    20    Negativ links
	// 37    10    Positiv links
	// 37    08    TX links
	// 37    04    MAIN links
	// 37    02    Kanal rechts Stelle 1 Balken F
	// 37    01    Kanal rechts Stelle 1 Balken E

	// 38    80    ???
	// 38    40    Kanal links Stelle 3 Balken A
	// 38    20    Kanal links Stelle 3 Balken G
	// 38    10    Kanal links Stelle 3 Balken B
	// 38    08    Kanal links Stelle 3 Balken C
	// 38    04    SKIP links
	// 38    02    Preferential Memory links
	// 38    01    DEC links

	// 39    80    ???
	// 39    40    ???
	// 39    20    Kanal links Stelle 2 Balken B
	// 39    10    Kanal links Stelle 2 Balken C
	// 39    08    Kanal links Stelle 1 Balken D
	// 39    04    Kanal links Stelle 3 Balken D
	// 39    02    Kanal links Stelle 3 Balken F
	// 39    01    Kanal links Stelle 3 Balken E

	// 40    80    ???
	// 40    40    Kanal links Stelle 2 Balken F
	// 40    20    Kanal links Stelle 2 Balken E
	// 40    10    Kanal links Stelle 2 Balken A
	// 40    08    Kanal links Stelle 2 Balken G
	// 40    04    ???
	// 40    02    ???
	// 40    01    ???

	// 41    80    ???
	// 41    40    Kanal links Stelle 1 Balken E
	// 41    20    Kanal links Stelle 1 Balken A
	// 41    10    Kanal links Stelle 1 Balken G
	// 41    08    Kanal links Stelle 1 Balken B
	// 41    04    Kanal links Stelle 1 Balken C
	// 41    02    Kanal links Trennstrich
	// 41    01    Kanal links Stelle 2 Balken D

	// 42    80    ???
	// 42    40    ???
	// 42    20    ???
	// 42    10    ???
	// 42    08    ##
	// 42    04    ## Helligkeit Hintergrundbeleuchtung
	// 42    02    ##
	// 42    01    Kanal links Stelle 1 Balken F

	// Helligkeit Hintergrundbeleuchtung:
	// Aus : xxxx000x
	// DIM1: xxxx111x
	// DIM2: xxxx011x
	// DIM3: xxxx100x

} MainUnitToPanelPacket;

#pragma pack(1)
typedef struct
{
	//Linker Wahlknopf drehen    : Byte 1 normal auf 80
	//bei Linksdrehung auf FF
	//bei Rechtsdrehung auf 81

	//Rechter Wahlknopf drehen   : Byte 2 normal auf 00
	//bei Linksdrehung auf 7F
	//bei Rechtsdrehung auf 01
	
	//PTT am Mikro        : Byte 3 von 7F auf 1B

	//Squelch rechts             : Byte 4 offen 7F, geschlossen 00

	//Lautstärke rechts          : Byte 5 leise 00, laut 7F

	//Lautstärke links           : Byte 7 leise 00, laut 7F

	//Squelch links              : Byte 8 offen 7F, geschlossen 00

	//LOW links                  : Byte 10 von 7F auf 61
	//V/M links                  : Byte 10 von 7F auf 40
	//HM links                   : Byte 10 von 7F auf 1F
	//SCN links                  : Byte 10 von 7F auf 00

	//Low rechts                 : Byte 11 von 7F auf 00
	//V/M rechts                 : Byte 11 von 7F auf 1F
	//HM rechts                  : Byte 11 von 7F auf 40
	//SCN rechts                 : Byte 11 von 7F auf 61

	//SET Knopf                  : Byte 12 von 00 auf 04
	//VOL/SQL Taster links       : Byte 12 von 00 auf 08
	//VOL/SQL Taster rechts      : Ein/Ausschalter, nur elektrisch als Signal auf Pin 2
	//Linker Wahlknopf drücken   : Byte 12 von 00 auf 02
	//Rechter Wahlknopf drücken  : Byte 12 von 00 auf 01
	
	//Hyper Taste 1        : Byte 13 auf 01
	//Hyper Taste 2        : Byte 13 auf 02
	//Hyper Taste 3        : Byte 13 auf 03
	//Hyper Taste 4        : Byte 13 auf 04
	//Hyper Taste 5        : Byte 13 auf 05
	//Hyper Taste 6        : Byte 13 auf 06

	//1 am Mikro          : Byte 6 auf 03 und Byte 9 auf 1B
	//2 am Mikro          : Byte 6 auf 03 und Byte 9 auf 32
	//3 am Mikro          : Byte 6 auf 03 und Byte 9 auf 4B
	//A am Mikro          : Byte 6 auf 03 und Byte 9 auf 66
	//4 am Mikro          : Byte 6 auf 19 und Byte 9 auf 1B
	//5 am Mikro          : Byte 6 auf 19 und Byte 9 auf 32
	//6 am Mikro          : Byte 6 auf 19 und Byte 9 auf 4B
	//B am Mikro          : Byte 6 auf 19 und Byte 9 auf 66
	//7 am Mikro          : Byte 6 auf 31 und Byte 9 auf 1B
	//8 am Mikro          : Byte 6 auf 31 und Byte 9 auf 32
	//9 am Mikro          : Byte 6 auf 31 und Byte 9 auf 4B
	//C am Mikro          : Byte 6 auf 31 und Byte 9 auf 66
	//* am Mikro          : Byte 6 auf 4B und Byte 9 auf 1C
	//0 am Mikro          : Byte 6 auf 4B und Byte 9 auf 33
	//# am Mikro          : Byte 6 auf 4B und Byte 9 auf 4B
	//D am Mikro          : Byte 6 auf 4B und Byte 9 auf 66

	//P1 Taste am Mikro   : Byte 6 auf 63 und Byte 9 auf 1C
	//P2 Taste am Mikro   : Byte 6 auf 63 und Byte 9 auf 33
	//P3 Taste am Mikro   : Byte 6 auf 63 und Byte 9 auf 4C
	//P4 Taste am Mikro   : Byte 6 auf 63 und Byte 9 auf 66

	//UP-Taste am Mikro   : Byte 6 auf 1D und Byte 9 auf 06
	//DOWN-Taste am Mikro : Byte 6 auf 34 und Byte 9 auf 06	
} PanelToMainUnitPacket;

#endif /* PACKET_H_ */
