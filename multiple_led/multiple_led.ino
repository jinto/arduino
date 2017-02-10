/*     ---------------------------------------------------------
 *     |  Arduino Experimentation Kit Example Code             |
 *     |  CIRC-02 .: 8 LED Fun :. (Multiple LEDs)   |
 *     ---------------------------------------------------------
 *
 *  A few Simple LED animations
 *
 * For more information on this circuit http://tinyurl.com/d2hrud
 *
 */

//#pragma once

#define countof(a) (sizeof(a) / sizeof(a[0]))
//#include <Common.h>

int const LedPins[] =
{
  2, 3, 4, 5, 6, 7, 8, 9
};
int const LedPinCount = countof(LedPins);
int const DelayTime = 100;

void setup()
{
  for (int i = 0; i < LedPinCount; ++i)
  {
    pinMode(LedPins[i], OUTPUT);
  }
}

void loop()
{
  clearAll();
  oneAfterAnotherLoop();
  clearAll();
  oneOnAtATime();
  clearAll();
  inAndOut();
}

void clearAll()
{
  for (int i = 0; i < LedPinCount; ++i)
  {
    digitalWrite(LedPins[i], LOW);
  }
}

void oneAfterAnotherLoop()
{
  for (int i = 0; i < LedPinCount; ++i)
  {
    digitalWrite(LedPins[i], HIGH);
    delay(DelayTime);
  }

  for (int i = LedPinCount - 1; i >= 0; --i)
  {
    digitalWrite(LedPins[i], LOW);
    delay(DelayTime);
  }
}

void oneOnAtATime()
{
  for (int i = 0; i < LedPinCount; ++i)
  {
    int previous = i == 0
      ? LedPinCount - 1
      : i - 1;
    
    digitalWrite(LedPins[i], HIGH);
    digitalWrite(LedPins[previous], LOW);
    delay(DelayTime);
  }
}

void inAndOut()
{
  //runs the LEDs out from the middle
  for (int i = 0; i <= 3; i++) {
    int previous = i - 1;  //Calculate which LED was turned on last time through
    if (i == 0) {        //for i = 1 to 7 this is i minus 1 (i.e. if i = 2 we will
      previous = 3;        //turn on LED 2 and off LED 1)
    }                    //however if i = 0 we don't want to turn of led -1 (doesn't exist)
    //instead we turn off LED 7, (looping around)
    int onLED1 = 3 - i;       //this is the first LED to go on ie. LED #3 when i = 0 and LED
    //#0 when i = 3
    int onLED2 = 4 + i;       //this is the first LED to go on ie. LED #4 when i = 0 and LED
    //#7 when i = 3
    int previous1 = 3 - previous; //turns off the LED we turned on last time
    int previous2 = 4 + previous; //turns off the LED we turned on last time

    digitalWrite(LedPins[onLED1], HIGH);
    digitalWrite(LedPins[onLED2], HIGH);
    digitalWrite(LedPins[previous1], LOW);
    digitalWrite(LedPins[previous2], LOW);
    delay(DelayTime);
  }

  //runs the LEDs into the middle
  for (int i = 3; i >= 0; i--) {
    int previous = i + 1;  //Calculate which LED was turned on last time through
    if (i == 3) {        //for i = 1 to 7 this is i minus 1 (i.e. if i = 2 we will
      previous = 0;        //turn on LED 2 and off LED 1)
    }                    //however if i = 0 we don't want to turn of led -1 (doesn't exist)
    //instead we turn off LED 7, (looping around)
    int onLED1 = 3 - i;       //this is the first LED to go on ie. LED #3 when i = 0 and LED
    //#0 when i = 3
    int onLED2 = 4 + i;       //this is the first LED to go on ie. LED #4 when i = 0 and LED
    //#7 when i = 3
    int previous1 = 3 - previous; //turns off the LED we turned on last time
    int previous2 = 4 + previous; //turns off the LED we turned on last time

    digitalWrite(LedPins[onLED1], HIGH);
    digitalWrite(LedPins[onLED2], HIGH);
    digitalWrite(LedPins[previous1], LOW);
    digitalWrite(LedPins[previous2], LOW);
    delay(DelayTime);
  }
}

