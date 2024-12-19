/*
   Пример вывода на дисплей с регистром TM1637
   показывает все возможности библиотеки GyverTM1637
   AlexGyver Technologies https://alexgyver.ru/
*/
#define CLK 2
#define DIO 3
#include "GyverTM1637.h"
GyverTM1637 disp(CLK, DIO);
uint32_t Now, clocktimer;
boolean flag;
void setup() {
  Serial.begin(9600);
  disp.clear();
  disp.brightness(7); 
}
void loop() {
  runningText();
  scrolls();
  scrollClock();
  twists();
  twistClock();
  ints();
  bytes();
  fadeBlink();
  normClock();
}
void twists() {
  byte digs[4] = {3, 5, 7, 1};
  disp.twist(digs, 50);   
  delay(1000);
  disp.twistByte(0, _1, 50);
  delay(1000);
  disp.twist(0, 8, 70);
  delay(1000);
  disp.clear();
  delay(200);
  for (byte i = 0; i < 10; i++) {
    disp.twist(3, i, 20);
    delay(200);
  }
  byte troll[4] = {_t, _r, _o, _l};
  disp.twistByte(troll, 50);
  delay(1000);
  disp.twistByte(2, _G, 50);
  delay(1000);
}
void twistClock() {
  byte hrs = 21, mins = 55;
  uint32_t tmr;
  Now = millis();
  while (millis () - Now < 10000) {   
    if (millis() - tmr > 500) {      
      tmr = millis();
      flag = !flag;
      disp.point(flag);  
      if (flag) {
     
        mins ++;
        if (mins > 59) {
          mins = 0;
          hrs++;
          if (hrs > 24) hrs = 0;
        }
      
        disp.displayClockTwist(hrs, mins, 35);   
      }
    }
  }
  disp.point(0);   
}
void scrolls() {
 
  byte digs[4] = {3, 5, 7, 1};
  disp.scroll(digs, 100);    
  delay(1000);

  disp.scroll(0, 8, 200);
  delay(1000);
  disp.clear();
  delay(1000);
  for (byte i = 0; i < 10; i++) {
    disp.scroll(3, i, 50);
    delay(400);
  }
  
  byte troll[4] = {_t, _r, _o, _l};
  disp.scrollByte(troll, 100);
  delay(1000);
  
  disp.scrollByte(2, _G, 50);
  delay(1000);
}
void bytes() {
 
  byte troll[4] = {_t, _r, _o, _l};
  disp.displayByte(troll);
  delay(1000);

  disp.displayByte(_L, _O, _L, _empty);
  delay(1000);
 
  disp.displayByte(3, _O);   
  delay(1000);
  
  byte hell[4] = {6, 6, 6, 6};
  disp.display(hell);
  delay(1000);
 
  disp.display(1, 2, 3, 4);
  delay(1000);
  
  disp.display(0, 9);   
  delay(1000);
}
void fadeBlink() {

  disp.displayByte(_H, _E, _L, _L);
  Now = millis();
  while (millis () - Now < 3000) {  
    for (int i = 7; i > 0; i--) {
      disp.brightness(i);  
      delay(40);
    }
    for (int i = 0; i < 8; i++) {
      disp.brightness(i);  
      delay(40);
    }
  }
}
void scrollClock() {
  byte hrs = 15, mins = 0;
  uint32_t tmr;
  Now = millis();
  while (millis () - Now < 10000) {  
    if (millis() - tmr > 500) {      
      tmr = millis();
      flag = !flag;
      disp.point(flag);   
      if (flag) {
       
        mins ++;
        if (mins > 59) {
          mins = 0;
          hrs++;
          if (hrs > 24) hrs = 0;
        }
      
        disp.displayClockScroll(hrs, mins, 70);  
      }
    }
  }
  disp.point(0);   
}
void normClock() {
  byte hrs = 15, mins = 0;
  uint32_t tmr;
  Now = millis();
  while (millis () - Now < 10000) {   
    if (millis() - tmr > 500) {       
      tmr = millis();
      flag = !flag;
      disp.point(flag);   
     
      mins ++;
      if (mins > 59) {
        mins = 0;
        hrs++;
        if (hrs > 24) hrs = 0;
      }
     
      disp.displayClock(hrs, mins);   
    }
  }
  disp.point(0);   
}
void ints() {
  disp.displayInt(-999);
  delay(500);
  disp.displayInt(-99);
  delay(500);
  disp.displayInt(-9);
  delay(500);
  disp.displayInt(0);
  delay(500);
  disp.displayInt(6);
  delay(500);
  disp.displayInt(66);
  delay(500);
  disp.displayInt(666);
  delay(500);
  disp.displayInt(6666);
  delay(500);
}
void runningText() {
  byte welcome_banner[] = {_H, _E, _L, _L, _O, _empty, _empty,
                           _e, _n, _j, _o, _y, _empty, _empty,
                           _1, _6, _3, _7, _empty, _d, _i, _S, _P, _l, _a, _y
                          };
  disp.runningString(welcome_banner, sizeof(welcome_banner), 200);  
}