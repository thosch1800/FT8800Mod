# FT8800Mod

This project is a modification to the Yaesu FT-8800 / Yaesu FT-8900, a dual VFO amateur radio transceiver. The device has a data jack that can be configured to use a particular VFO. When configured it uses this VFO for signal reception, but it is still transmitting on the main VFO. The goal of this modification is to change that behavior.

Another feature is the ability to set the frequency through a CAT-like interface (e.g. from PC or smartphone).

Some useful links:
Yaesu FT-8800 https://www.universal-radio.com/catalog/fm_txvrs/0080.html  
Main2Panel http://www.dg1sfj.de/funk/geraete/88-yaesu-ft-8800?showall=&start=3  
Panel2Main http://www.dg1sfj.de/funk/geraete/88-yaesu-ft-8800?showall=&start=2

Current activity:
- 2017/09/30: During the last days I built a breadboard PCB prototype to play around with the rig. There are two modular jacks to be able to intercept the communication between main unit and panel (and back) and two mini-DIN jacks to get the modems PTT signal. Thanks to the multiplexer (CD4052) I can fully intercept the communication and manipulate the packets. Today I read the displayed values and overrode them. Some commands do not work as expected so there is work left. Next topic: modem PTT detection. 
![img_20170930_222655_507](https://user-images.githubusercontent.com/30317420/31059077-df932218-a6fe-11e7-9501-76856c2eafc3.jpg)
I did not get any modular jacks for soldering so I had to go the MacGyver way...

- 2017/09/23: the first packets were successfully received:
![img_20170923_171857_584](https://user-images.githubusercontent.com/30317420/30795108-322c3ce0-a1cc-11e7-9dea-8a86e293e2a6.jpg)
S-Meter of the left VFO mapped to the STK600 LED bar (LED for S9 left out)

![img_20170923_151625_545_0](https://user-images.githubusercontent.com/30317420/30795291-1aa12ecc-a1cd-11e7-8d79-c0164caf54d5.jpg)
Panel packets: The yellow graph shows the input of UART0, the red graph shows the "frame complete" signal (UART0->timer2->PINA4)
