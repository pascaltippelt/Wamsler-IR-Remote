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
  
  //Sends telegram WITHOUT modulation (for use with hardware modulator)
  t.sendTelegram();
  
  //Sends teöegram with software pwm modulation at 38kHz
  t.sendTelegramSoftPWM();
  
  }

void loop() {

}
