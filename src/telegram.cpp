#include <telegram.h>
#include <string>

/// <summary>
/// Sets the blower level for the ambient blower.
/// </summary>
/// <param name="level">0...4 (level 1 to 5); 5 -> Auto</param>
/// <returns>true if successfull</returns>
bool telegram::setBlowerLevel(int level) 
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
bool telegram::setTemperature(int temperature)
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
bool telegram::setTimer1on(int hour, int minute)
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

        data[19] = arr[4];
        data[20] = arr[3];
        data[21] = arr[2];
        data[22] = arr[1];
        data[23] = arr[0];        
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

        data[16] = arr[2];
        data[17] = arr[1];
        data[18] = arr[0];

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
bool telegram::setTimer1off(int hour, int minute)
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

        data[27] = arr[4];
        data[28] = arr[3];
        data[29] = arr[2];
        data[30] = arr[1];
        data[31] = arr[0];
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

        data[24] = arr[2];
        data[25] = arr[1];
        data[26] = arr[0];

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
bool telegram::setTimer2on(int hour, int minute)
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

        data[35] = arr[4];
        data[36] = arr[3];
        data[37] = arr[2];
        data[38] = arr[1];
        data[39] = arr[0];
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

        data[32] = arr[2];
        data[33] = arr[1];
        data[34] = arr[0];
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
bool telegram::setTimer2off(int hour, int minute)
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

        data[43] = arr[4];
        data[44] = arr[3];
        data[45] = arr[2];
        data[46] = arr[1];
        data[47] = arr[0];
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

        data[40] = arr[2];
        data[41] = arr[1];
        data[42] = arr[0];
        
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
bool telegram::setTime(int hour, int minute)
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

bool telegram::calcPruefsumme()
{
    int pr = 0;
    for (int i = 0; i < 17; i++) {  //add first 17 nibbles without overflow
        
    }

    return true;
}

bool telegram::calcTelegram()
{
    data[0] = 1;            //unknown
    data[1] = 1;            //unknown
    data[2] = AUTOTimer;
    data[3] = OnOff;
    data[4] = Turbo;
    //data 5...7 by setBlowerLevel()
    data[8] = Econo;
    data[9] = 1;            //unknown
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

std::string telegram::toString()
{
    if (calcTelegram()) 
    {
        std::string t_str = "";
        for (int i = 0; i < 72; i++) {
            t_str += std::to_string(data[i]);
        }

        return t_str;
    }
    else {
        return "ERROR";
    }

};



bool importTelegram(std::string tel_str)
{
    return NULL;
}

//std::string toBinary(int n)
//{
//    std::string r;
//    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
//    return r;
//}
