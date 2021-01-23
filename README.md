# Wamsler-IR-Remote

I have got a Wamsler / Westminster Quattro 6 pellet stove with a IR-Remote. I wanted to reverse-engineer the transmission-code, this is the result with big help from [mikrocontroller.net](https://www.mikrocontroller.net/topic/511335#6560508).

This is how a transmission telegram might look:

![transmission-example](https://raw.githubusercontent.com/pascaltippelt/Wamsler-IR-Remote/main/2.PNG)

The "short" impulses are a logigal 0, the "long" impulses are a logical 1. So a telegram might look like the following:

111100111000111000110011010110001001100010101101000101010000110011111011

##Protocall explenation

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
| bit 16 to 18 | timer 1 ON minute | binToDec * 10 | minutes|
| bit 19 to 23 | timer 1 ON hour | binToDec | hours |
| bit 24 to 26 | timer 1 OFF minute | binToDec * 10 | minutes|
| bit 27 to 31 | timer 1 OFF hour | binToDec | hours |
| bit 32 to 34 | timer 2 ON minute | binToDec * 10 | minutes|
| bit 35 to 39 | timer 2 ON hour | binToDec | hours |
| bit 40 to 42 | timer 2 OFF minute | binToDec * 10 | minutes|
| bit 43 to 47 | timer 2 OFF hour | binToDec | hours |
| bit 48 to 49 | currently unknown, maybe part of 50..55 | | |
| bit 50 to 55 | hour of day | binToDec | hours |
| bit 56 to 57 | currently unknown, maybe part of 59..64 | | |
| bit 59 to 63 | minute of day | binToDec | minutes |
| bit 64 | timer 1 ON active | 1 = true, 0 = false | |
| bit 65 | timer 1 OFF active | 1 = true, 0 = false | |
| bit 66 | timer 2 ON active | 1 = true, 0 = false | |
| bit 67 | timer 1 OFF active | 1 = true, 0 = false | |
| bit 68 to 71 | propably parity or so| | (to be determined) |

I build a simple decoder in excel, provided [here](https://github.com/pascaltippelt/Wamsler-IR-Remote/raw/main/IR-Decoder.xlsx).

##future steps

My plan is to build an esp* based IR "remote" to control the stove remotely via internet. Progress will be published here.
