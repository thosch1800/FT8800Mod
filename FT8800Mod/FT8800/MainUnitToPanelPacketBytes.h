#ifndef MAINUNITTOPANELPACKETBYTES_H_
#define MAINUNITTOPANELPACKETBYTES_H_

#include <stdint-gcc.h>

// http://www.dg1sfj.de/funk/geraete/88-yaesu-ft-8800?showall=&start=3

enum BacklightValue
{
    Backlight_Off =  0x000,
    Backlight_Dim1 = 0x111,
    Backlight_Dim2 = 0x011,
    Backlight_Dim3 = 0x100,
};

//suppress warning #pragma pack(1)
typedef struct
{
    // 01    01    5 kHz links
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

    // 02    01    Frequenz links Stelle 6 Balken B
    uint8_t FrequencyLeftPlace6BarB : 1;
    // 02    02    Frequenz links Stelle 6 Balken K
    uint8_t FrequencyLeftPlace6BarK : 1;
    // 02    04    Frequenz links Stelle 6 Balken A
    uint8_t FrequencyLeftPlace6BarA : 1;
    // 02    08    Frequenz links Stelle 6 Balken G
    uint8_t FrequencyLeftPlace6BarG : 1;
    // 02    10    Frequenz links Stelle 6 Balken H
    uint8_t FrequencyLeftPlace6BarH : 1;
    // 02    20    Low TX Power links
    uint8_t TxPowerLeftLow : 1;
    // 02    40    Frequenz links Stelle 6 Balken N
    uint8_t FrequencyLeftPlace6BarN : 1;
    // 02    80    ???
    uint8_t Unknown0280 : 1;

    // 03    01    Frequenz links Stelle 6 Balken D
    uint8_t FrequencyLeftPlace6BarD : 1;
    // 03    02    Frequenz links Stelle 6 Balken J+P
    uint8_t FrequencyLeftPlace6BarJ : 1;
    // 03    04    S-Meter links Balken 8
    uint8_t SignalLeftBar8 : 1;
    // 03    08    Frequenz links Stelle 6 Balken Q
    uint8_t FrequencyLeftPlace6BarQ : 1;
    // 03    10    Frequenz links Stelle 6 Balken E
    uint8_t FrequencyLeftPlace6BarE : 1;
    // 03    20    Frequenz links Stelle 6 Balken F
    uint8_t FrequencyLeftPlace6BarF : 1;
    // 03    40    S-Meter links Balken 7
    uint8_t SignalLeftBar7 : 1;
    // 03    80    ???
    uint8_t Unknown0380 : 1;

    // 04    01    Frequenz links Stelle 5 Balken C
    uint8_t FrequencyLeftPlace5BarC : 1;
    // 04    02    Frequenz links Stelle 5 Balken M
    uint8_t FrequencyLeftPlace5BarM : 1;
    // 04    04    Frequenz links Stelle 5 Balken B
    uint8_t FrequencyLeftPlace5BarB : 1;
    // 04    08    Frequenz links Stelle 5 Balken K
    uint8_t FrequencyLeftPlace5BarK : 1;
    // 04    10    Frequenz links Stelle 5 Balken A
    uint8_t FrequencyLeftPlace5BarA : 1;
    // 04    20    Frequenz links Stelle 5 Balken G
    uint8_t FrequencyLeftPlace5BarG : 1;
    // 04    40    Frequenz links Stelle 5 Balken H
    uint8_t FrequencyLeftPlace5BarH : 1;
    // 04    80    ???
    uint8_t Unknown0480 : 1;

    // 05    01    9600 bps links
    uint8_t Data9600bpsLeft : 1;
    // 05    02    Frequenz links Stelle 5 Balken N
    uint8_t FrequencyLeftPlace5BarN : 1;
    // 05    04    Frequenz links Stelle 5 Balken D
    uint8_t FrequencyLeftPlace5BarD : 1;
    // 05    08    Frequenz links Stelle 5 Balken J+P
    uint8_t FrequencyLeftPlace5BarJ : 1;
    // 05    10    S-Meter links Balken 6
    uint8_t SignalLeftBar6 : 1;
    // 05    20    Frequenz links Stelle 5 Balken Q
    uint8_t FrequencyLeftPlace5BarQ : 1;
    // 05    40    Frequenz links Stelle 5 Balken E
    uint8_t FrequencyLeftPlace5BarE : 1;
    // 05    80    ???
    uint8_t Unknown0580 : 1;

    // 06    01    Frequenz links Stelle 5 Balken F
    uint8_t FrequencyLeftPlace5BarF : 1;
    // 06    02    S-Meter links Balken 5
    uint8_t SignalLeftBar5 : 1;
    // 06    04    Frequenz links Stelle 4 Balken C
    uint8_t FrequencyLeftPlace4BarC : 1;
    // 06    08    Frequenz links Stelle 4 Balken M
    uint8_t FrequencyLeftPlace4BarM : 1;
    // 06    10    Frequenz links Stelle 4 Balken B
    uint8_t FrequencyLeftPlace4BarB : 1;
    // 06    20    Frequenz links Stelle 4 Balken K
    uint8_t FrequencyLeftPlace4BarK : 1;
    // 06    40    Frequenz links Stelle 4 Balken A
    uint8_t FrequencyLeftPlace4BarA : 1;
    // 06    80    ???
    uint8_t Unknown0680 : 1;

    // 07    01    Frequenz links Stelle 4 Balken G
    uint8_t FrequencyLeftPlace4BarG : 1;
    // 07    02    Frequenz links Stelle 4 Balken H
    uint8_t FrequencyLeftPlace4BarH : 1;
    // 07    04    AM links
    uint8_t AmplitudeModulationLeft : 1;
    // 07    08    Frequenz links Stelle 4 Balken N
    uint8_t FrequencyLeftPlace4BarN : 1;
    // 07    10    Frequenz links Stelle 4 Balken D
    uint8_t FrequencyLeftPlace4BarD : 1;
    // 07    20    Frequenz links Stelle 4 Balken J+P
    uint8_t FrequencyLeftPlace4BarJ : 1;
    // 07    40    S-Meter links Balken 4
    uint8_t SignalLeftBar4 : 1;
    // 07    80    ???
    uint8_t Unknown0780 : 1;

    // 08    01    Frequenz links Stelle 4 Balken Q
    uint8_t FrequencyLeftPlace4BarQ : 1;
    // 08    02    Frequenz links Stelle 4 Balken E
    uint8_t FrequencyLeftPlace4BarE : 1;
    // 08    04    Frequenz links Stelle 4 Balken F
    uint8_t FrequencyLeftPlace4BarF : 1;
    // 08    08    ???
    uint8_t Unknown0808 : 1;
    // 08    10    ???
    uint8_t Unknown0810 : 1;
    // 08    20    ???
    uint8_t Unknown0820 : 1;
    // 08    40    ???
    uint8_t Unknown0840 : 1;
    // 08    80    ???
    uint8_t Unknown0880 : 1;

    // 09    01    Dezimal-Punkt MHz links
    uint8_t FrequencyLeftDecimalPointMhz : 1;
    // 09    02    ???
    uint8_t Unknown0902 : 1;
    // 09    04    S-Meter links Balken 3
    uint8_t SignalLeftBar3 : 1;
    // 09    08    Frequenz links Stelle 3 Balken C
    uint8_t FrequencyLeftPlace3BarC : 1;
    // 09    10    Frequenz links Stelle 3 Balken M
    uint8_t FrequencyLeftPlace3BarM : 1;
    // 09    20    Frequenz links Stelle 3 Balken B
    uint8_t FrequencyLeftPlace3BarB : 1;
    // 09    40    Frequenz links Stelle 3 Balken K
    uint8_t FrequencyLeftPlace3BarK : 1;
    // 09    80    ???
    uint8_t Unknown0980 : 1;

    // 10    01    Frequenz links Stelle 3 Balken A
    uint8_t FrequencyLeftPlace3BarA : 1;
    // 10    02    Frequenz links Stelle 3 Balken G
    uint8_t FrequencyLeftPlace3BarG : 1;
    // 10    04    Frequenz links Stelle 3 Balken H
    uint8_t FrequencyLeftPlace3BarH : 1;
    // 10    08    DCS links
    uint8_t DcsLeft: 1;
    // 10    10    Frequenz links Stelle 3 Balken N
    uint8_t FrequencyLeftPlace3BarN : 1;
    // 10    20    Frequenz links Stelle 3 Balken D
    uint8_t FrequencyLeftPlace3BarD : 1;
    // 10    40    Frequenz links Stelle 3 Balken J+P
    uint8_t FrequencyLeftPlace3BarJ : 1;
    // 10    80    ???
    uint8_t Unknown1080 : 1;

    // 11    01    S-Meter links Balken 2
    uint8_t SignalLeftBar2 : 1;
    // 11    02    Frequenz links Stelle 3 Balken Q
    uint8_t FrequencyLeftPlace3BarQ : 1;
    // 11    04    Frequenz links Stelle 3 Balken E
    uint8_t FrequencyLeftPlace3BarE : 1;
    // 11    08    Frequenz links Stelle 3 Balken F
    uint8_t FrequencyLeftPlace3BarF : 1;
    // 11    10    S-Meter links Balken 1
    uint8_t SignalLeftBar1 : 1;
    // 11    20    Frequenz links Stelle 2 Balken C
    uint8_t FrequencyLeftPlace2BarC : 1;
    // 11    40    Frequenz links Stelle 2 Balken M
    uint8_t FrequencyLeftPlace2BarM : 1;
    // 11    80    ???
    uint8_t Unknown1180 : 1;

    // 12    01    Frequenz links Stelle 2 Balken B
    uint8_t FrequencyLeftPlace2BarB : 1;
    // 12    02    Frequenz links Stelle 2 Balken K
    uint8_t FrequencyLeftPlace2BarK : 1;
    // 12    04    Frequenz links Stelle 2 Balken A
    uint8_t FrequencyLeftPlace2BarA : 1;
    // 12    08    Frequenz links Stelle 2 Balken G
    uint8_t FrequencyLeftPlace2BarG : 1;
    // 12    10    Frequenz links Stelle 2 Balken H
    uint8_t FrequencyLeftPlace2BarH : 1;
    // 12    20    MUTE links
    uint8_t MuteLeft : 1;
    // 12    40    Frequenz links Stelle 2 Balken N
    uint8_t FrequencyLeftPlace2BarN : 1;
    // 12    80    ???
    uint8_t Unknown1280 : 1;

    // 13    01    Frequenz links Stelle 2 Balken D
    uint8_t FrequencyLeftPlace2BarD : 1;
    // 13    02    Frequenz links Stelle 2 Balken J+P
    uint8_t FrequencyLeftPlace2BarJ : 1;
    // 13    04    BUSY links
    uint8_t BusyLeft : 1;
    // 13    08    Frequenz links Stelle 2 Balken Q
    uint8_t FrequencyLeftPlace2BarQ : 1;
    // 13    10    Frequenz links Stelle 2 Balken E
    uint8_t FrequencyLeftPlace2BarE : 1;
    // 13    20    Frequenz links Stelle 2 Balken F
    uint8_t FrequencyLeftPlace2BarF : 1;
    // 13    40    Memory Tune links
    uint8_t MemoryTuneLeft : 1;
    // 13    80    ???
    uint8_t Unknown1380 : 1;

    // 14    01    Frequenz links Stelle 1 Balken C
    uint8_t FrequencyLeftPlace1BarC : 1;
    // 14    02    Frequenz links Stelle 1 Balken M
    uint8_t FrequencyLeftPlace1BarM : 1;
    // 14    04    Frequenz links Stelle 1 Balken B
    uint8_t FrequencyLeftPlace1BarB : 1;
    // 14    08    Frequenz links Stelle 1 Balken K
    uint8_t FrequencyLeftPlace1BarK : 1;
    // 14    10    Frequenz links Stelle 1 Balken A
    uint8_t FrequencyLeftPlace1BarA : 1;
    // 14    20    Frequenz links Stelle 1 Balken G
    uint8_t FrequencyLeftPlace1BarG : 1;
    // 14    40    Frequenz links Stelle 1 Balken H
    uint8_t FrequencyLeftPlace1BarH : 1;
    // 14    80    ???
    uint8_t Unknown1480 : 1;

    // 15    01    ???
    uint8_t Unknown1501 : 1;
    // 15    02    Frequenz links Stelle 1 Balken N
    uint8_t FrequencyLeftPlace1BarN : 1;
    // 15    04    Frequenz links Stelle 1 Balken D
    uint8_t FrequencyLeftPlace1BarD : 1;
    // 15    08    Frequenz links Stelle 1 Balken J+P
    uint8_t FrequencyLeftPlace1BarJ : 1;
    // 15    10    ???
    uint8_t Unknown1510 : 1;
    // 15    20    Frequenz links Stelle 1 Balken Q
    uint8_t FrequencyLeftPlace1BarQ : 1;
    // 15    40    Frequenz links Stelle 1 Balken E
    uint8_t FrequencyLeftPlace1BarE : 1;
    // 15    80    ???
    uint8_t Unknown1580 : 1;

    // 16    01    Frequenz links Stelle 1 Balken F
    uint8_t FrequencyLeftPlace1BarF : 1;
    // 16    02    ???
    uint8_t Unknown1602 : 1;
    // 16    04    ???
    uint8_t Unknown1604 : 1;
    // 16    08    ???
    uint8_t Unknown1608 : 1;
    // 16    10    ???
    uint8_t Unknown1610 : 1;
    // 16    20    ???
    uint8_t Unknown1620 : 1;
    // 16    40    ???
    uint8_t Unknown1640 : 1;
    // 16    80    ???
    uint8_t Unknwon1680 : 1;

    // 17    01    5 kHz rechts
    uint8_t FrequencyRightFiveKhz : 1;
    // 17    02    ???
    uint8_t Unknown1702 : 1;
    // 17    04    Middle TX Power rechts
    uint8_t TxPowerRightMiddle : 1;
    // 17    08    Dezimal-Punkt kHz rechts
    uint8_t FrequencyRightDecimalPointKhz : 1;
    // 17    10    S-Meter rechts Balken 9
    uint8_t SignalRightBar9 : 1;
    // 17    20    Frequenz rechts Stelle 6 Balken C
    uint8_t FrequencyRightPlace6BarC : 1;
    // 17    40    Frequenz rechts Stelle 6 Balken M
    uint8_t FrequencyRightPlace6BarM : 1;
    // 17    80    ???
    uint8_t Unknown1780 : 1;

    // 18    01    Frequenz rechts Stelle 6 Balken B
    uint8_t FrequencyRightPlace6BarB : 1;
    // 18    02    Frequenz rechts Stelle 6 Balken K
    uint8_t FrequencyRightPlace6BarK : 1;
    // 18    04    Frequenz rechts Stelle 6 Balken A
    uint8_t FrequencyRightPlace6BarA : 1;
    // 18    08    Frequenz rechts Stelle 6 Balken G
    uint8_t FrequencyRightPlace6BarG : 1;
    // 18    10    Frequenz rechts Stelle 6 Balken H
    uint8_t FrequencyRightPlace6BarH : 1;
    // 18    20    Low TX Power rechts
    uint8_t TxPowerRightLow : 1;
    // 18    40    Frequenz rechts Stelle 6 Balken N
    uint8_t FrequencyRightPlace6BarN : 1;
    // 18    80    ???
    uint8_t Unknown1880 : 1;

    // 19    01    Frequenz rechts Stelle 6 Balken D
    uint8_t FrequencyRightPlace6BarD : 1;
    // 19    02    Frequenz rechts Stelle 6 Balken J+P
    uint8_t FrequencyRightPlace6BarJ : 1;
    // 19    04    S-Meter rechts Balken 8
    uint8_t SignalRightBar8 : 1;
    // 19    08    Frequenz rechts Stelle 6 Balken Q
    uint8_t FrequencyRightPlace6BarQ : 1;
    // 19    10    Frequenz rechts Stelle 6 Balken E
    uint8_t FrequencyRightPlace6BarE : 1;
    // 19    20    Frequenz rechts Stelle 6 Balken F
    uint8_t FrequencyRightPlace6BarF : 1;
    // 19    40    S-Meter rechts Balken 7
    uint8_t SignalRightBar7 : 1;
    // 19    80    ???
    uint8_t Unknown1980 : 1;

    // 20    01    Frequenz rechts Stelle 5 Balken C
    uint8_t FrequencyRightPlace5BarC : 1;
    // 20    02    Frequenz rechts Stelle 5 Balken M
    uint8_t FrequencyRightPlace5BarM : 1;
    // 20    04    Frequenz rechts Stelle 5 Balken B
    uint8_t FrequencyRightPlace5BarB : 1;
    // 20    08    Frequenz rechts Stelle 5 Balken K
    uint8_t FrequencyRightPlace5BarK : 1;
    // 20    10    Frequenz rechts Stelle 5 Balken A
    uint8_t FrequencyRightPlace5BarA : 1;
    // 20    20    Frequenz rechts Stelle 5 Balken G
    uint8_t FrequencyRightPlace5BarG : 1;
    // 20    40    Frequenz rechts Stelle 5 Balken H
    uint8_t FrequencyRightPlace5BarH : 1;
    // 20    80    ???
    uint8_t Unknown2080 : 1;

    // 21    01    9600 bps rechts
    uint8_t Data9600bpsRight : 1;
    // 21    02    Frequenz rechts Stelle 5 Balken N
    uint8_t FrequencyRightPlace5BarN : 1;
    // 21    04    Frequenz rechts Stelle 5 Balken D
    uint8_t FrequencyRightPlace5BarD : 1;
    // 21    08    Frequenz rechts Stelle 5 Balken J+P
    uint8_t FrequencyRightPlace5BarJ : 1;
    // 21    10    S-Meter rechts Balken 6
    uint8_t SignalRightBar6 : 1;
    // 21    20    Frequenz rechts Stelle 5 Balken Q
    uint8_t FrequencyRightPlace5BarQ : 1;
    // 21    40    Frequenz rechts Stelle 5 Balken E
    uint8_t FrequencyRightPlace5BarE : 1;
    // 21    80    ???
    uint8_t Unknown2180 : 1;

    // 22    01    Frequenz rechts Stelle 5 Balken F
    uint8_t FrequencyRightPlace5BarF : 1;
    // 22    02    S-Meter rechts Balken 5
    uint8_t SignalRightBar5 : 1;
    // 22    04    Frequenz rechts Stelle 4 Balken C
    uint8_t FrequencyRightPlace4BarC : 1;
    // 22    08    Frequenz rechts Stelle 4 Balken M
    uint8_t FrequencyRightPlace4BarM : 1;
    // 22    10    Frequenz rechts Stelle 4 Balken B
    uint8_t FrequencyRightPlace4BarB : 1;
    // 22    20    Frequenz rechts Stelle 4 Balken K
    uint8_t FrequencyRightPlace4BarK : 1;
    // 22    40    Frequenz rechts Stelle 4 Balken A
    uint8_t FrequencyRightPlace4BarA : 1;
    // 22    80    ???
    uint8_t Unknown2280 : 1;

    // 23    01    Frequenz rechts Stelle 4 Balken G
    uint8_t FrequencyRightPlace4BarG : 1;
    // 23    02    Frequenz rechts Stelle 4 Balken H
    uint8_t FrequencyRightPlace4BarH : 1;
    // 23    04    DCS rechts
    uint8_t DcsRight : 1;
    // 23    08    Frequenz rechts Stelle 4 Balken N
    uint8_t FrequencyRightPlace4BarN : 1;
    // 23    10    Frequenz rechts Stelle 4 Balken D
    uint8_t FrequencyRightPlace4BarD : 1;
    // 23    20    Frequenz rechts Stelle 4 Balken J+P
    uint8_t FrequencyRightPlace4BarJ : 1;
    // 23    40    S-Meter rechts Balken 4
    uint8_t SignalRightBar4 : 1;
    // 23    80    ???
    uint8_t Unknown2380 : 1;

    // 24    01    Frequenz rechts Stelle 4 Balken Q
    uint8_t FrequencyRightPlace4BarQ : 1;
    // 24    02    Frequenz rechts Stelle 4 Balken E
    uint8_t FrequencyRightPlace4BarE : 1;
    // 24    04    Frequenz rechts Stelle 4 Balken F
    uint8_t FrequencyRightPlace4BarF : 1;
    // 24    08    ???
    uint8_t Unknown2408 : 1;
    // 24    10    ???
    uint8_t Unknown2410 : 1;
    // 24    20    ???
    uint8_t Unknown2420 : 1;
    // 24    40    ???
    uint8_t Unknown2440 : 1;
    // 24    80    ???
    uint8_t Unknown2480 : 1;

    // 25    01    Dezimal-Punkt MHz rechts
    uint8_t FrequencyRightDecimalPointMhz : 1;
    // 25    02    ???
    uint8_t Unknown2502 : 1;
    // 25    04    S-Meter rechts Balken 3
    uint8_t SignalRightBar3 : 1;
    // 25    08    Frequenz rechts Stelle 3 Balken C
    uint8_t FrequencyRightPlace3BarC : 1;
    // 25    10    Frequenz rechts Stelle 3 Balken M
    uint8_t FrequencyRightPlace3BarM : 1;
    // 25    20    Frequenz rechts Stelle 3 Balken B
    uint8_t FrequencyRightPlace3BarB : 1;
    // 25    40    Frequenz rechts Stelle 3 Balken K
    uint8_t FrequencyRightPlace3BarK : 1;
    // 25    80    ???
    uint8_t Unknown2580 : 1;

    // 26    01    Frequenz rechts Stelle 3 Balken A
    uint8_t FrequencyRightPlace3BarA : 1;
    // 26    02    Frequenz rechts Stelle 3 Balken G
    uint8_t FrequencyRightPlace3BarG : 1;
    // 26    04    Frequenz rechts Stelle 3 Balken H
    uint8_t FrequencyRightPlace3BarH : 1;
    // 26    08    MUTE rechts
    uint8_t MuteRight : 1;
    // 26    10    Frequenz rechts Stelle 3 Balken N
    uint8_t FrequencyRightPlace3BarN : 1;
    // 26    20    Frequenz rechts Stelle 3 Balken D
    uint8_t FrequencyRightPlace3BarD : 1;
    // 26    40    Frequenz rechts Stelle 3 Balken J+P
    uint8_t FrequencyRightPlace3BarJ : 1;
    // 26    80    ???
    uint8_t Unknwon2680 : 1;

    // 27    01    S-Meter rechts Balken 2
    uint8_t SignalRightBar2 : 1;
    // 27    02    Frequenz rechts Stelle 3 Balken Q
    uint8_t FrequencyRightPlace3BarQ : 1;
    // 27    04    Frequenz rechts Stelle 3 Balken E
    uint8_t FrequencyRightPlace3BarE : 1;
    // 27    08    Frequenz rechts Stelle 3 Balken F
    uint8_t FrequencyRightPlace3BarF : 1;
    // 27    10    S-Meter rechts Balken 1
    uint8_t SignalRightBar1 : 1;
    // 27    20    Frequenz rechts Stelle 2 Balken C
    uint8_t FrequencyRightPlace2BarC : 1;
    // 27    40    Frequenz rechts Stelle 2 Balken M
    uint8_t FrequencyRightPlace2BarM : 1;
    // 27    80    ???
    uint8_t Unknown2780 : 1;

    // 28    01    Frequenz rechts Stelle 2 Balken B
    uint8_t FrequencyRightPlace2BarB : 1;
    // 28    02    Frequenz rechts Stelle 2 Balken K
    uint8_t FrequencyRightPlace2BarK : 1;
    // 28    04    Frequenz rechts Stelle 2 Balken A
    uint8_t FrequencyRightPlace2BarA : 1;
    // 28    08    Frequenz rechts Stelle 2 Balken G
    uint8_t FrequencyRightPlace2BarG : 1;
    // 28    10    Frequenz rechts Stelle 2 Balken H
    uint8_t FrequencyRightPlace2BarH : 1;
    // 28    20    Memory Tune rechts
    uint8_t MemoryTuneRight : 1;
    // 28    40    Frequenz rechts Stelle 2 Balken N
    uint8_t FrequencyRightPlace2BarN : 1;
    // 28    80    ???
    uint8_t Unknown2880 : 1;

    // 29    01    Frequenz rechts Stelle 2 Balken D
    uint8_t FrequencyRightPlace2BarD : 1;
    // 29    02    Frequenz rechts Stelle 2 Balken J+P
    uint8_t FrequencyRightPlace2BarJ : 1;
    // 29    04    BUSY rechts
    uint8_t BusyRight : 1;
    // 29    08    Frequenz rechts Stelle 2 Balken Q
    uint8_t FrequencyRightPlace2BarQ : 1;
    // 29    10    Frequenz rechts Stelle 2 Balken E
    uint8_t FrequencyRightPlace2BarE : 1;
    // 29    20    Frequenz rechts Stelle 2 Balken F
    uint8_t FrequencyRightPlace2BarF : 1;
    // 29    40    KEY2
    uint8_t SecondaryMenuKey : 1;
    // 29    80    ???
    uint8_t Unknown2980 : 1;

    // 30    01    Frequenz rechts Stelle 1 Balken C
    uint8_t FrequencyRightPlace1BarC : 1;
    // 30    02    Frequenz rechts Stelle 1 Balken M
    uint8_t FrequencyRightPlace1BarM : 1;
    // 30    04    Frequenz rechts Stelle 1 Balken B
    uint8_t FrequencyRightPlace1BarB : 1;
    // 30    08    Frequenz rechts Stelle 1 Balken K
    uint8_t FrequencyRightPlace1BarK : 1;
    // 30    10    Frequenz rechts Stelle 1 Balken A
    uint8_t FrequencyRightPlace1BarA : 1;
    // 30    20    Frequenz rechts Stelle 1 Balken G
    uint8_t FrequencyRightPlace1BarG : 1;
    // 30    40    Frequenz rechts Stelle 1 Balken H
    uint8_t FrequencyRightPlace1BarH : 1;
    // 30    80    ???
    uint8_t Unknown3080 : 1;

    // 31    01    SET
    uint8_t SetKey : 1;
    // 31    02    Frequenz rechts Stelle 1 Balken N
    uint8_t FrequencyRightPlace1BarN : 1;
    // 31    04    Frequenz rechts Stelle 1 Balken D
    uint8_t FrequencyRightPlace1BarD : 1;
    // 31    08    Frequenz rechts Stelle 1 Balken J+P
    uint8_t FrequencyRightPlace1BarJ : 1;
    // 31    10    Keypad Lock
    uint8_t KeypadLocked : 1;
    // 31    20    Frequenz rechts Stelle 1 Balken Q
    uint8_t FrequencyRightPlace1BarQ : 1;
    // 31    40    Frequenz rechts Stelle 1 Balken E
    uint8_t FrequencyRightPlace1BarE : 1;
    // 31    80    ???
    uint8_t Unknown3180 : 1;

    // 32    01    Frequenz rechts Stelle 1 Balken F
    uint8_t FrequencyRightPlace1BarF : 1;
    // 32    02    ???
    uint8_t Unknown3202 : 1;
    // 32    04    ???
    uint8_t Unknown3204 : 1;
    // 32    08    ???
    uint8_t Unknwon3208 : 1;
    // 32    10    ???
    uint8_t Unknown3210 : 1;
    // 32    20    ???
    uint8_t Unknown3220 : 1;
    // 32    40    ???
    uint8_t Unknown3240 : 1;
    // 32    80    ???
    uint8_t Unknown3280 : 1;

    // 33    01    MAIN rechts
    uint8_t MainRight : 1;
    // 33    02    TX rechts
    uint8_t TxRight : 1;
    // 33    04    Positiv rechts
    uint8_t PositiveRight : 1;
    // 33    08    Negativ rechts
    uint8_t NegativeRight : 1;
    // 33    10    ENC rechts
    uint8_t EncRight : 1;
    // 33    20    DEC rechts
    uint8_t DecRight : 1;
    // 33    40    Preferential Memory rechts
    uint8_t PreferentialMemoryRight : 1;
    // 33    80    ???
    uint8_t Unknown3380 : 1;

    // 34    01    SKIP rechts
    uint8_t SkipRight : 1;
    // 34    02    Kanal rechts Stelle 3 Balken C
    uint8_t ChannelRightPlace3BarC : 1;
    // 34    04    Kanal rechts Stelle 3 Balken B
    uint8_t ChannelRightPlace3BarB : 1;
    // 34    08    Kanal rechts Stelle 3 Balken G
    uint8_t ChannelRightPlace3BarG : 1;
    // 34    10    Kanal rechts Stelle 3 Balken A
    uint8_t ChannelRightPlace3BarA : 1;
    // 34    20    Kanal rechts Stelle 3 Balken E
    uint8_t ChannelRightPlace3BarE : 1;
    // 34    40    Kanal rechts Stelle 3 Balken F
    uint8_t ChannelRightPlace3BarF : 1;
    // 34    80    ???
    uint8_t Unknown4380 : 1;

    // 35    01    Kanal rechts Stelle 3 Balken D
    uint8_t ChannelRightPlace3BarD : 1;
    // 35    02    Kanal rechts Stelle 1 Balken D
    uint8_t ChannelRightPlace1BarD : 1;
    // 35    04    Kanal rechts Stelle 2 Balken C
    uint8_t ChannelRightPlace2BarC : 1;
    // 35    08    Kanal rechts Stelle 2 Balken B
    uint8_t ChannelRightPlace2BarB : 1;
    // 35    10    Kanal rechts Stelle 2 Balken G
    uint8_t ChannelRightPlace2BarG : 1;
    // 35    20    Kanal rechts Stelle 2 Balken A
    uint8_t ChannelRightPlace2BarA : 1;
    // 35    40    Kanal rechts Stelle 2 Balken E
    uint8_t ChannelRightPlace2BarE : 1;
    // 35    80    ???
    uint8_t Unknown3580 : 1;

    // 36    01    Kanal rechts Stelle 2 Balken F
    uint8_t ChannelRightPlace2BarF : 1;
    // 36    02    Kanal rechts Stelle 2 Balken D
    uint8_t ChannelRightPlace2BarD : 1;
    // 36    04    Kanal rechts Trennstrich
    uint8_t ChannelRightDividerBar : 1;
    // 36    08    Kanal rechts Stelle 1 Balken C
    uint8_t ChannelRightPlace1BarC : 1;
    // 36    10    Kanal rechts Stelle 1 Balken B
    uint8_t ChannelRightPlace1BarB : 1;
    // 36    20    Kanal rechts Stelle 1 Balken G
    uint8_t ChannelRightPlace1BarG : 1;
    // 36    40    Kanal rechts Stelle 1 Balken A
    uint8_t ChannelRightPlace1BarA : 1;
    // 36    80    ???
    uint8_t Unknown3680 : 1;

    // 37    01    Kanal rechts Stelle 1 Balken E
    uint8_t ChannelRightPlace1BarE : 1;
    // 37    02    Kanal rechts Stelle 1 Balken F
    uint8_t ChannelRightPlace1BarF : 1;
    // 37    04    MAIN links
    uint8_t MainLeft : 1;
    // 37    08    TX links
    uint8_t TxLeft : 1;
    // 37    10    Positiv links
    uint8_t PositiveLeft : 1;
    // 37    20    Negativ links
    uint8_t NegativeLeft : 1;
    // 37    40    ENC links
    uint8_t EncLeft : 1;
    // 37    80    ???
    uint8_t Unknown3780 : 1;

    // 38    01    DEC links
    uint8_t DecLeft : 1;
    // 38    02    Preferential Memory links
    uint8_t PreferentialMemoryLeft : 1;
    // 38    04    SKIP links
    uint8_t SkipLeft : 1;
    // 38    08    Kanal links Stelle 3 Balken C
    uint8_t ChannelLeftPlace3BarC : 1;
    // 38    10    Kanal links Stelle 3 Balken B
    uint8_t ChannelLeftPlace3BarB : 1;
    // 38    20    Kanal links Stelle 3 Balken G
    uint8_t ChannelLeftPlace3BarG : 1;
    // 38    40    Kanal links Stelle 3 Balken A
    uint8_t ChannelLeftPlace3BarA : 1;
    // 38    80    ???
    uint8_t Unknown3880 : 1;

    // 39    01    Kanal links Stelle 3 Balken E
    uint8_t ChannelLeftPlace3BarE : 1;
    // 39    02    Kanal links Stelle 3 Balken F
    uint8_t ChannelLeftPlace3BarF : 1;
    // 39    04    Kanal links Stelle 3 Balken D
    uint8_t ChannelLeftPlace3BarD : 1;
    // 39    08    Kanal links Stelle 1 Balken D
    uint8_t ChannelLeftPlace1BarD : 1;
    // 39    10    Kanal links Stelle 2 Balken C
    uint8_t ChannelLeftPlace2BarC : 1;
    // 39    20    Kanal links Stelle 2 Balken B
    uint8_t ChannelLeftPlace2BarB : 1;
    // 39    40    ???
    uint8_t Unknown3940 : 1;
    // 39    80    ???
    uint8_t Unknown3980 : 1;

    // 40    01    ???
    uint8_t Unknown4001 : 1;
    // 40    02    ???
    uint8_t Unknown4002 : 1;
    // 40    04    ???
    uint8_t Unknown4004 : 1;
    // 40    08    Kanal links Stelle 2 Balken G
    uint8_t ChannelLeftPlace2BarG : 1;
    // 40    10    Kanal links Stelle 2 Balken A
    uint8_t ChannelLeftPlace2BarA : 1;
    // 40    20    Kanal links Stelle 2 Balken E
    uint8_t ChannelLeftPlace2BarE : 1;
    // 40    40    Kanal links Stelle 2 Balken F
    uint8_t ChannelLeftPlace2BarF : 1;
    // 40    80    ???
    uint8_t Unknown4080 : 1;

    // 41    01    Kanal links Stelle 2 Balken D
    uint8_t ChannelLeftPlace2BarD : 1;
    // 41    02    Kanal links Trennstrich
    uint8_t ChannelLeftDividerBar : 1;
    // 41    04    Kanal links Stelle 1 Balken C
    uint8_t ChannelLeftPlace1BarC : 1;
    // 41    08    Kanal links Stelle 1 Balken B
    uint8_t ChannelLeftPlace1BarB : 1;
    // 41    10    Kanal links Stelle 1 Balken G
    uint8_t ChannelLeftPlace1BarG : 1;
    // 41    20    Kanal links Stelle 1 Balken A
    uint8_t ChannelLeftPlace1BarA : 1;
    // 41    40    Kanal links Stelle 1 Balken E
    uint8_t ChannelLeftPlace1BarE : 1;
    // 41    80    ???
    uint8_t Unknown4180 : 1;

    // 42    01    Kanal links Stelle 1 Balken F
    uint8_t ChannelLeftPlace1BarF : 1;
    // 42    08/04/02    ## Helligkeit Hintergrundbeleuchtung
    uint8_t Backlight : 3;
    // 42    10    ???
    uint8_t Unknown4210 : 1;
    // 42    20    ???
    uint8_t Unknown4220 : 1;
    // 42    40    ???
    uint8_t Unknown4240 : 1;
    // 42    80    ???
    uint8_t Unknown4280 : 1;
} MainUnitToPanelPacketBytes;

#endif /* PACKET_H_ */
