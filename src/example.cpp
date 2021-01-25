#include <iostream>
#include <telegram.h>


int main()
{
    telegram t;
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

    std::cout << t.toString();
    //schould present 111100110000111000110011010110001001100010101101000101000000001111111101
}
