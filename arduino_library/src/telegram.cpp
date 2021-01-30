#include "Arduino.h"
#include <telegram.h>

#define long_starter    9000    //mikrosekunden
#define short_starter   4500    //us
#define t_break         550     
#define t_true          1715
#define t_false         600

/// <summary>
/// Initialize
/// </summary>
/// <param name="pin">IR-diode-pin</param>
myTelegram::myTelegram(int pin) {
    _pin = pin;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, false);
}

/// <summary>
/// Sets the blower level for the ambient blower.
/// </summary>
/// <param name="level">0...4 (level 1 to 5); 5 -> Auto</param>
/// <returns>true if successfull</returns>
bool myTelegram::setBlowerLevel(int level) 
{
   if ((level >= 0) && (level <= 5))
   {
       int arr[3] = { 0 }; //REVERSED!!!
       int dec = level;
       int i = 0;

       while(dec > 0)
       {
            arr[i] = dec % 2;
            i++;
            dec = dec / 2;
       }
       data[5] = arr[2];
       data[6] = arr[1];
       data[7] = arr[0];

       return true;

   } else { 
       return false;
   }

};

/// <summary>
/// Sets the target temperature.
/// </summary>
/// <param name="temperature">7 to 40 °C</param>
/// <returns>true if successful</returns>
bool myTelegram::setTemperature(int temperature)
{
    if ((temperature >= 7) && (temperature <= 40))
    {
        int arr[6] = { 0 }; //REVERSED
        int dec = temperature - 7;
        int i = 0;

        while (dec > 0) {
            arr[i] = dec % 2;
            i++;
            dec = dec / 2;
        }
        data[10] = arr[5];
        data[11] = arr[4];
        data[12] = arr[3];
        data[13] = arr[2];
        data[14] = arr[1];
        data[15] = arr[0];

        return true;
    }
    else {
        return false;
    }
};

/// <summary>
/// Sets timer 1 On time.
/// </summary>
/// <param name="hour">Hour, 0 -> 23, standart 0</param>
/// <param name="minute">Minute, 0 -> 59, standart 0</param>
/// <returns>true if successfull</returns>
bool myTelegram::setTimer1on(int hour, int minute)
{
    //Wertebereich Stunde prüfen
    if ((hour >= 0) && (hour < 24))
    {
        int arr[5] = { 0 };
        int dec = hour;
        int i = 0;

        while (dec > 0) {
            arr[i] = dec % 2;
            i++;
            dec = dec / 2;
        }

        data[16] = arr[4];
        data[17] = arr[3];
        data[18] = arr[2];
        data[19] = arr[1];
        data[20] = arr[0];        
    }
    else {
        return false;
    }

    //Wertebereich Minute Prüfen
    if ((minute >= 0) && (minute < 60))
    {
        int arr[3] = { 0 };
        int dec = minute / 10;
        int i = 0;

        while (dec > 0) {
            arr[i] = dec % 2;
            i++;
            dec = dec / 2;
        }

        data[21] = arr[2];
        data[22] = arr[1];
        data[23] = arr[0];

        return true;
    }
    else {
        return false;
    }

};

/// <summary>
/// Sets timer 1 Off time.
/// </summary>
/// <param name="hour">Hour, 0 -> 23, standart 0</param>
/// <param name="minute">Minute, 0 -> 59, standart 0</param>
/// <returns>true if successfull</returns>
bool myTelegram::setTimer1off(int hour, int minute)
{
    //Wertebereich Stunde prüfen
    if ((hour >= 0) && (hour < 24))
    {
        int arr[5] = { 0 };
        int dec = hour;
        int i = 0;

        while (dec > 0) {
            arr[i] = dec % 2;
            i++;
            dec = dec / 2;
        }

        data[24] = arr[4];
        data[25] = arr[3];
        data[26] = arr[2];
        data[27] = arr[1];
        data[28] = arr[0];
    }
    else {
        return false;
    }

    //Wertebereich Minute Prüfen
    if ((minute >= 0) && (minute < 60))
    {
        int arr[3] = { 0 };
        int dec = minute / 10;
        int i = 0;

        while (dec > 0) {
            arr[i] = dec % 2;
            i++;
            dec = dec / 2;
        }

        data[29] = arr[2];
        data[30] = arr[1];
        data[31] = arr[0];

        return true;
    }
    else {
        return false;
    }
};

/// <summary>
/// Sets timer 2 On time.
/// </summary>
/// <param name="hour">Hour, 0 -> 23, standart 0</param>
/// <param name="minute">Minute, 0 -> 59, standart 0</param>
/// <returns>true if successfull</returns>
bool myTelegram::setTimer2on(int hour, int minute)
{
    //Wertebereich Stunde prüfen
    if ((hour >= 0) && (hour < 24))
    {
        int arr[5] = { 0 };
        int dec = hour;
        int i = 0;

        while (dec > 0) {
            arr[i] = dec % 2;
            i++;
            dec = dec / 2;
        }

        data[32] = arr[4];
        data[33] = arr[3];
        data[34] = arr[2];
        data[35] = arr[1];
        data[36] = arr[0];
    } else {
        return false;
    }

    //Wertebereich Minute Prüfen
    if ((minute >= 0) && (minute < 60))
    {
        int arr[3] = { 0 };
        int dec = minute / 10;
        int i = 0;

        while (dec > 0) {
            arr[i] = dec % 2;
            i++;
            dec = dec / 2;
        }

        data[37] = arr[2];
        data[38] = arr[1];
        data[39] = arr[0];
        return true;
    } else {
        return false;
    }
};

/// <summary>
/// Sets timer 2 Off time.
/// </summary>
/// <param name="hour">Hour, 0 -> 23, standart 0</param>
/// <param name="minute">Minute, 0 -> 59, standart 0</param>
/// <returns>true if successfull</returns>
bool myTelegram::setTimer2off(int hour, int minute)
{
    //Wertebereich Stunde prüfen
    if ((hour >= 0) && (hour < 24))
    {
        int arr[5] = { 0 };
        int dec = hour;
        int i = 0;

        while (dec > 0) {
            arr[i] = dec % 2;
            i++;
            dec = dec / 2;
        }

        data[40] = arr[4];
        data[41] = arr[3];
        data[42] = arr[2];
        data[43] = arr[1];
        data[44] = arr[0];
    } else {
        return false;
    }

    //Wertebereich Minute Prüfen
    if ((minute >= 0) && (minute < 60))
    {
        int arr[3] = { 0 };
        int dec = minute / 10;
        int i = 0;

        while (dec > 0) {
            arr[i] = dec % 2;
            i++;
            dec = dec / 2;
        }

        data[45] = arr[2];
        data[46] = arr[1];
        data[47] = arr[0];
        
        return true;
    } else {
        return false;
    }
};

/// <summary>
/// Sets daytime by hour and minute.
/// </summary>
/// <param name="hour">0 -> 23</param>
/// <param name="minute">0 -> 59</param>
/// <returns>true if successfull</returns>
bool myTelegram::setTime(int hour, int minute)
{
    //Wertebereich Stunde prüfen
    if ((hour >= 0) && (hour < 24))
    {
        int arr[8] = { 0 };
        int dec = hour;
        int i = 0;

        while (dec > 0) {
            arr[i] = dec % 2;
            i++;
            dec = dec / 2;
        }

        data[48] = arr[7];
        data[49] = arr[6];
        data[50] = arr[5];
        data[51] = arr[4];
        data[52] = arr[3];
        data[53] = arr[2];
        data[54] = arr[1];
        data[55] = arr[0];
    }
    else {
        return false;
    }

    if ((minute >= 0) && (minute < 60))
    {
        int arr[8] = { 0 };
        int dec = minute;
        int i = 0;

        while (dec > 0) {
            arr[i] = dec % 2;
            i++;
            dec = dec / 2;
        }

        data[56] = arr[7];
        data[57] = arr[6];
        data[58] = arr[5];
        data[59] = arr[4];
        data[60] = arr[3];
        data[61] = arr[2];
        data[62] = arr[1];
        data[63] = arr[0];
        return true;
    }
    else {
        return false;
    }
};

/// <summary>
/// Converts a nibble to a decimal number.
/// </summary>
/// <param name="nib">nibble as array</param>
/// <returns>decimal number as integer</returns>
int nibbleToDec(bool nib[4] = { 0 })
{
    int dez = 0;
    if (nib[3]) { dez += 1; }
    if (nib[2]) { dez += 2; }
    if (nib[1]) { dez += 4; }
    if (nib[0]) { dez += 8; }
    return dez;
}

/// <summary>
/// Calculates the checksum-nibble based on the first 17 nibbles.
/// </summary>
/// <returns>true if successfull</returns>
bool myTelegram::calcPruefsumme()
{
    int nibbles[17] = { 0 };
    for (int i = 0; i < 17; i++) {
        //4 bit in 1 nibble
        bool t_nib[4] = {data[4*i+0], data[4 * i + 1], data[4 * i + 2], data[4 * i + 3] };
        //convert nibble to decimal and write it to nibbles
        nibbles[i] = nibbleToDec(t_nib);
    }

    int p_sum = 0;

    for (int i = 0; i < 17; i++) {
        int t_p_sum = p_sum + nibbles[i];
        if (t_p_sum < 16) {
            p_sum = t_p_sum;
        }
        else {
            p_sum = t_p_sum - 16;
        }
    }

    int arr[4] = { 0 };

    int dec = p_sum;
    int i = 0;

    while (dec > 0) {
        arr[i] = dec % 2;
        i++;
        dec = dec / 2;
    }

    data[68] = !arr[3];
    data[69] = !arr[2];
    data[70] = !arr[1];
    data[71] = !arr[0];
   
    return true;
}

/// <summary>
/// Sets all bits inside the telegram.
/// </summary>
/// <returns>true if successfull</returns>
bool myTelegram::calcTelegram()
{
    data[0] = 1;            //unknown
    data[1] = 1;            //unknown
    data[2] = AUTOTimer;
    data[3] = OnOff;
    data[4] = Turbo;
    //data 5...7 by setBlowerLevel()
    data[8] = Econo;
    data[9] = 0;            //unknown
    //data 10...15 by setTemperature()
    //data 16...47 by setTimerXon or setTimerXoff
    //data 48...63 by setTime()
    data[64] = timer1onActive;
    data[65] = timer1offActive;
    data[66] = timer2onActive;
    data[67] = timer2offActive;

    if (calcPruefsumme()) {
        return true;
    }
    else {
        return false;
    }

    
}

/// <summary>
/// Converts the bool-array data into a string
/// </summary>
/// <returns>string, containing the telegram (human redable)</returns>
String myTelegram::toString()
{
    if (calcTelegram()) 
    {
        String t_str = "";
        for (int i = 0; i < 72; i++) {
            t_str += String(data[i]);
        }

        return t_str;
    }
    else {
        return "ERROR";
    }

};

/*
#define long_starter    9000    //mikrosekunden
#define short_starter   4500    //us
#define t_break         550
#define t_true          1715
#define t_false         600
*/

bool myTelegram::sendTelegram() {
    digitalWrite(_pin, true);
    delayMicroseconds(long_starter);
    digitalWrite(_pin, false);
    delayMicroseconds(short_starter);

    for (int i = 0; i < 72; i++) {
        digitalWrite(_pin, true);
        delayMicroseconds(t_break);
        digitalWrite(_pin, false);
        if (data[i]) { 
            delayMicroseconds(t_true); 
        }
        else { 
            delayMicroseconds(t_false); 
        }
    }
    digitalWrite(_pin, false);

    return true;
}


bool myTelegram::sendTelegramSoftPWM() {

    //Set PWM Frequency
    analogWriteFreq(38000);
    analogWrite(_pin, 512);
    delayMicroseconds(long_starter);
    analogWrite(_pin, 0);
    delayMicroseconds(short_starter);

    for (int i = 0; i < 72; i++) {
        analogWrite(_pin, 512);
        delayMicroseconds(t_break);
        analogWrite(_pin, 0);
        if (data[i]) {
            delayMicroseconds(t_true);
        }
        else {
            delayMicroseconds(t_false);
        }
    }
    analogWrite(_pin, 512);
    delayMicroseconds(t_break);
    analogWrite(_pin, 0);

    return true;
}
