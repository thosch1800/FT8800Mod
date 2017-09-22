#ifndef PANELTOMAINUNITPACKETBYTES_H_
#define PANELTOMAINUNITPACKETBYTES_H_

#include <stdint-gcc.h>

// http://www.dg1sfj.de/index.php/funk/geraete/88-yaesu-ft-8800?showall=&start=2

#pragma pack(1)
typedef struct
{
    //Linker Wahlknopf drehen: Byte 1 normal auf 80, bei Linksdrehung auf FF, bei Rechtsdrehung auf 81
    union
    {
        uint8_t Byte01;
        uint8_t DialLeft;
    };
    
    //Rechter Wahlknopf drehen: Byte 2 normal auf 00, bei Linksdrehung auf 7F, bei Rechtsdrehung auf 01
    union
    {
        uint8_t Byte02;
        uint8_t DialRight;
    };
    
    //PTT am Mikro: Byte 3 von 7F auf 1B
    union
    {
        uint8_t Byte03;
        uint8_t PushToTalk;
    };

    //Squelch rechts: Byte 4 offen 7F, geschlossen 00
    union
    {
        uint8_t Byte04;
        uint8_t SquelchRight;
    };

    //Lautstärke rechts: Byte 5 leise 00, laut 7F
    union
    {
        uint8_t Byte05;
        uint8_t VolumeRight;
    };

    union
    {
        uint8_t Byte06;
        uint8_t Mic06;
    };

    //Lautstärke links: Byte 7 leise 00, laut 7F
    union
    {
        uint8_t Byte07;
        uint8_t VolumeLeft;
    };

    //Squelch links: Byte 8 offen 7F, geschlossen 00
    union
    {
        uint8_t Byte08;
        uint8_t SquelchLeft;
    };
    
    union
    {
        uint8_t Byte09;
        uint8_t Mic09;
    };

    //Low links: Byte 10 von 7F auf 61
    //V/M links: Byte 10 von 7F auf 40
    //HM links : Byte 10 von 7F auf 1F
    //Scn links: Byte 10 von 7F auf 00
    union
    {
        uint8_t Byte10;
        uint8_t KeysLeft;
    };

    //Low rechts: Byte 11 von 7F auf 00
    //V/M rechts: Byte 11 von 7F auf 1F
    //HM rechts : Byte 11 von 7F auf 40
    //Scn rechts: Byte 11 von 7F auf 61
    union
    {
        uint8_t Byte11;
        uint8_t KeysRight;
    };

    //SET Knopf                  : Byte 12 von 00 auf 04
    //VOL/SQL Taster links       : Byte 12 von 00 auf 08
    //VOL/SQL Taster rechts      : Ein/Ausschalter, nur elektrisch als Signal auf Pin 2
    //Linker Wahlknopf drücken   : Byte 12 von 00 auf 02
    //Rechter Wahlknopf drücken  : Byte 12 von 00 auf 01
    union
    {
        uint8_t Byte12;
        uint8_t Keys;
    };
    
    //Hyper Taste 1: Byte 13 auf 01
    //Hyper Taste 2: Byte 13 auf 02
    //Hyper Taste 3: Byte 13 auf 03
    //Hyper Taste 4: Byte 13 auf 04
    //Hyper Taste 5: Byte 13 auf 05
    //Hyper Taste 6: Byte 13 auf 06
    union
    {
        uint8_t Byte13;
        uint8_t Hyper;
    };

    //1 am Mikro: Byte 6 auf 03 und Byte 9 auf 1B
    //2 am Mikro: Byte 6 auf 03 und Byte 9 auf 32
    //3 am Mikro: Byte 6 auf 03 und Byte 9 auf 4B
    //A am Mikro: Byte 6 auf 03 und Byte 9 auf 66
    //4 am Mikro: Byte 6 auf 19 und Byte 9 auf 1B
    //5 am Mikro: Byte 6 auf 19 und Byte 9 auf 32
    //6 am Mikro: Byte 6 auf 19 und Byte 9 auf 4B
    //B am Mikro: Byte 6 auf 19 und Byte 9 auf 66
    //7 am Mikro: Byte 6 auf 31 und Byte 9 auf 1B
    //8 am Mikro: Byte 6 auf 31 und Byte 9 auf 32
    //9 am Mikro: Byte 6 auf 31 und Byte 9 auf 4B
    //C am Mikro: Byte 6 auf 31 und Byte 9 auf 66
    //* am Mikro: Byte 6 auf 4B und Byte 9 auf 1C
    //0 am Mikro: Byte 6 auf 4B und Byte 9 auf 33
    //# am Mikro: Byte 6 auf 4B und Byte 9 auf 4B
    //D am Mikro: Byte 6 auf 4B und Byte 9 auf 66

    //P1 Taste am Mikro: Byte 6 auf 63 und Byte 9 auf 1C
    //P2 Taste am Mikro: Byte 6 auf 63 und Byte 9 auf 33
    //P3 Taste am Mikro: Byte 6 auf 63 und Byte 9 auf 4C
    //P4 Taste am Mikro: Byte 6 auf 63 und Byte 9 auf 66

    //UP-Taste am Mikro: Byte 6 auf 1D und Byte 9 auf 06
    //DOWN-Taste am Mikro: Byte 6 auf 34 und Byte 9 auf 06
} PanelToMainUnitPacketBytes;

#endif /* PANELTOMAINUNITPACKETBYTES_H_ */
