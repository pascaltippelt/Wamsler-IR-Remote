# Wamsler-IR-Remote

I have got a Wamsler / Westminster Quattro 6 pellet stove with a IR-Remote. I wanted to reverse-engineer the transmission-code, this is the result with big help from [mikrocontroller.net](https://www.mikrocontroller.net/topic/511335#6560508). The control unit is based on the Duepi Evo line.

This is how a transmission telegram might look:

![transmission-example](https://raw.githubusercontent.com/pascaltippelt/Wamsler-IR-Remote/main/2.PNG)

The "short" impulses are a logigal 0, the "long" impulses are a logical 1. So a telegram might look like the following:

111100111000111000110011010110001001100010101101000101010000110011111011

## protocall explenation

| area | explenation | calculation | unit |
| --- | --- | --- | --- |
| bit 0 to 1 | currently unknown | | |
| bit 2 | timer "auto" | 1 = true, 0 = false | |
| bit 3 | stove on / off | 1 = on, 0 = off | |
| bit 4 | "turbo" mode on / off | 1 = on, 0 = off | |
| bit 5 to 7 | blower level | 1 + binToDec; 6 = AUTO | |
| bit 8  | "econo" mode on / off | 1 = on, 0 = off | |
| bit 9 | currently unknown | | |
| bit 10 to 15 | temperature | 7 + binToDec | °C |
| bit 16 to 20 | timer 1 ON hour | binToDec | hours |
| bit 21 to 23 | timer 1 ON minute | binToDec * 10 | minutes|
| bit 24 to 28 | timer 1 OFF hour | binToDec | hours |
| bit 29 to 31 | timer 1 OFF minute | binToDec * 10 | minutes|
| bit 32 to 36 | timer 2 ON hour | binToDec | hours |
| bit 37 to 39 | timer 2 ON minute | binToDec * 10 | minutes|
| bit 40 to 44 | timer 2 OFF hour | binToDec | hours |
| bit 45 to 47 | timer 2 OFF minute | binToDec * 10 | minutes|
| bit 48 to 49 | currently unknown, maybe part of 50..55 | | |
| bit 50 to 55 | hour of day | binToDec | hours |
| bit 56 to 57 | currently unknown, maybe part of 59..64 | | |
| bit 59 to 63 | minute of day | binToDec | minutes |
| bit 64 | timer 1 ON active | 1 = true, 0 = false | |
| bit 65 | timer 1 OFF active | 1 = true, 0 = false | |
| bit 66 | timer 2 ON active | 1 = true, 0 = false | |
| bit 67 | timer 1 OFF active | 1 = true, 0 = false | |
| bit 68 to 71 | custom checksum | see below | |

I build a simple decoder in excel, provided [here](https://github.com/pascaltippelt/Wamsler-IR-Remote/raw/main/IR-Decoder.xlsx).

There is also a prototype of a encoder available under [src](/src).

### custom checksum

To calculate the "checksum", add the first 17 nibbles without overflow. See "calcPruefsumme()" in src/telegram.cpp !

## arduino library

There is a simple prototype of an arduino library available, see [arduino_library](/arduino_library). How to use: Creaty a new folder called "telegram" in .../Arduino/libraries/. Copy all contents from [arduino_library](/arduino_library) inside. Then load the example script:

```c++
#include <telegram.h>

myTelegram t = myTelegram(13);

void setup() {
  t.AUTOTimer = true;
  t.setBlowerLevel(3);
  t.OnOff = true;
  t.Turbo = false;
  t.setTemperature(21);
  t.setTimer1on(6, 30);
  t.setTimer1off(11, 00);
  t.setTimer2on(19, 00);
  t.setTimer2off(21, 50);
  t.setTime(20, 3);
  t.timer1onActive = true;
  t.timer1offActive = true;
  t.timer2onActive = true;
  t.timer2offActive = true;

  Serial.begin(9600);
  Serial.println(t.toString());
  
  t.sendTelegram();
  
  }

void loop() {

}
```
## tipp: connect to the stove via serial interface...
...as it was done by [aceindy](https://github.com/aceindy/Duepi_EVO). This is just a reference for your information.
