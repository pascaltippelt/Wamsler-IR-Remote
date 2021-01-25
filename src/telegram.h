#pragma once
#include <string>
#include <iostream>

class telegram
{
public:
	//Variablen
	int OnOff = 0;									//On = 1, Off = 0
	int AUTOTimer = 0;								//On = 1, Off = 0
	int Turbo = 0;									//On = 1, Off = 0
	int Econo = 0;									//On = 1, Off = 0
	int timer1onActive = 0;							//True = 1, False = 0
	int timer1offActive = 0;
	int timer2onActive = 0;
	int timer2offActive = 0;

	//Funktionen, Set
	bool setBlowerLevel(int level = 0);
	bool setTemperature(int temperature = 20);
	bool setTimer1on(int hour = 0, int minute = 0);
	bool setTimer1off(int hour = 0, int minute = 0);
	bool setTimer2on(int hour = 0, int minute = 0);
	bool setTimer2off(int hour = 0, int minute = 0);
	bool setTime(int hour = 0, int minute = 0);

	//Funktionen, Output
	std::string toString();
	

private:
	bool data[72] = { 0 };
	
	bool calcTelegram();

	bool calcPruefsumme();
};
