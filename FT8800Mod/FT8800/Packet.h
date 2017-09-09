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
	uint8_t FrequencyLeftDecimalPoint : 1;
	
	// 01    10    S-Meter links Balken 9
	uint8_t SignalLeftBar9 : 1;
	
	// 01    20    Frequenz links Stelle 6 Balken C
	uint8_t FrequencyLeftPlace6BarC : 1;
	
	// 01    40    Frequenz links Stelle 6 Balken M
	uint8_t FrequencyLeftPlace6BarM : 1;
	
	// 01    80    ???
	uint8_t Unknown0180 : 1;
	
	
	
	// 02    80    ???
	// 02    40    Frequenz links Stelle 6 Balken N
	// 02    20    Low TX Power links
	// 02    10    Frequenz links Stelle 6 Balken H
	// 02    08    Frequenz links Stelle 6 Balken G
	// 02    04    Frequenz links Stelle 6 Balken A
	// 02    02    Frequenz links Stelle 6 Balken K
	// 02    01    Frequenz links Stelle 6 Balken B

	// 03    80    ???
	// 03    40    S-Meter links Balken 7
	// 03    20    Frequenz links Stelle 6 Balken F
	// 03    10    Frequenz links Stelle 6 Balken E
	// 03    08    Frequenz links Stelle 6 Balken Q
	// 03    04    S-Meter links Balken 8
	// 03    02    Frequenz links Stelle 6 Balken J+P
	// 03    01    Frequenz links Stelle 6 Balken D

	// 04    80    ???
	// 04    40    Frequenz links Stelle 5 Balken H
	// 04    20    Frequenz links Stelle 5 Balken G
	// 04    10    Frequenz links Stelle 5 Balken A
	// 04    08    Frequenz links Stelle 5 Balken K
	// 04    04    Frequenz links Stelle 5 Balken B
	// 04    02    Frequenz links Stelle 5 Balken M
	// 04    01    Frequenz links Stelle 5 Balken C

	// 05    80    ???
	// 05    40    Frequenz links Stelle 5 Balken E
	// 05    20    Frequenz links Stelle 5 Balken Q
	// 05    10    S-Meter links Balken 6
	// 05    08    Frequenz links Stelle 5 Balken J+P
	// 05    04    Frequenz links Stelle 5 Balken D
	// 05    02    Frequenz links Stelle 5 Balken N
	// 05    01    9600 bps links

	// 06    80    ???
	// 06    40    Frequenz links Stelle 4 Balken A
	// 06    20    Frequenz links Stelle 4 Balken K
	// 06    10    Frequenz links Stelle 4 Balken B
	// 06    08    Frequenz links Stelle 4 Balken M
	// 06    04    Frequenz links Stelle 4 Balken C
	// 06    02    S-Meter links Balken 5
	// 06    01    Frequenz links Stelle 5 Balken F

	// 07    80    ???
	// 07    40    S-Meter links Balken 4
	// 07    20    Frequenz links Stelle 4 Balken J+P
	// 07    10    Frequenz links Stelle 4 Balken D
	// 07    08    Frequenz links Stelle 4 Balken N
	// 07    04    AM links
	// 07    02    Frequenz links Stelle 4 Balken H
	// 07    01    Frequenz links Stelle 4 Balken G

	// 08    80    ???
	// 08    40    ???
	// 08    20    ???
	// 08    10    ???
	// 08    08    ???
	// 08    04    Frequenz links Stelle 4 Balken F
	// 08    02    Frequenz links Stelle 4 Balken E
	// 08    01    Frequenz links Stelle 4 Balken Q

	// 09    80    ???
	// 09    40    Frequenz links Stelle 3 Balken K
	// 09    20    Frequenz links Stelle 3 Balken B
	// 09    10    Frequenz links Stelle 3 Balken M
	// 09    08    Frequenz links Stelle 3 Balken C
	// 09    04    S-Meter links Balken 3
	// 09    02    ???
	// 09    01    Dezimal-Punkt MHz links

	// 10    80    ???
	// 10    40    Frequenz links Stelle 3 Balken J+P
	// 10    20    Frequenz links Stelle 3 Balken D
	// 10    10    Frequenz links Stelle 3 Balken N
	// 10    08    DCS links
	// 10    04    Frequenz links Stelle 3 Balken H
	// 10    02    Frequenz links Stelle 3 Balken G
	// 10    01    Frequenz links Stelle 3 Balken A

	// 11    80    ???
	// 11    40    Frequenz links Stelle 2 Balken M
	// 11    20    Frequenz links Stelle 2 Balken C
	// 11    10    S-Meter links Balken 1
	// 11    08    Frequenz links Stelle 3 Balken F
	// 11    04    Frequenz links Stelle 3 Balken E
	// 11    02    Frequenz links Stelle 3 Balken Q
	// 11    01    S-Meter links Balken 2

	// 12    80    ???
	// 12    40    Frequenz links Stelle 2 Balken N
	// 12    20    MUTE links
	// 12    10    Frequenz links Stelle 2 Balken H
	// 12    08    Frequenz links Stelle 2 Balken G
	// 12    04    Frequenz links Stelle 2 Balken A
	// 12    02    Frequenz links Stelle 2 Balken K
	// 12    01    Frequenz links Stelle 2 Balken B

	// 13    80    ???
	// 13    40    Memory Tune links
	// 13    20    Frequenz links Stelle 2 Balken F
	// 13    10    Frequenz links Stelle 2 Balken E
	// 13    08    Frequenz links Stelle 2 Balken Q
	// 13    04    BUSY links
	// 13    02    Frequenz links Stelle 2 Balken J+P
	// 13    01    Frequenz links Stelle 2 Balken D

	// 14    80    ???
	// 14    40    Frequenz links Stelle 1 Balken H
	// 14    20    Frequenz links Stelle 1 Balken G
	// 14    10    Frequenz links Stelle 1 Balken A
	// 14    08    Frequenz links Stelle 1 Balken K
	// 14    04    Frequenz links Stelle 1 Balken B
	// 14    02    Frequenz links Stelle 1 Balken M
	// 14    01    Frequenz links Stelle 1 Balken C

	// 15    80    ???
	// 15    40    Frequenz links Stelle 1 Balken E
	// 15    20    Frequenz links Stelle 1 Balken Q
	// 15    10    ???
	// 15    08    Frequenz links Stelle 1 Balken J+P
	// 15    04    Frequenz links Stelle 1 Balken D
	// 15    02    Frequenz links Stelle 1 Balken N
	// 15    01    ???

	// 16    80    ???
	// 16    40    ???
	// 16    20    ???
	// 16    10    ???
	// 16    08    ???
	// 16    04    ???
	// 16    02    ???
	// 16    01    Frequenz links Stelle 1 Balken F

	// 17    80    ???
	// 17    40    Frequenz rechts Stelle 6 Balken M
	// 17    20    Frequenz rechts Stelle 6 Balken C
	// 17    10    S-Meter rechts Balken 9
	// 17    08    Dezimal-Punkt kHz rechts
	// 17    04    Middle TX Power rechts
	// 17    02    ???
	// 17    01    Kleine kHz 5 rechts

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