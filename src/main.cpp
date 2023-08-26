#include <Arduino.h>
#include <TM1637Display.h>
#include <Encoder.h>
#include <arduino-timer.h>

#define DIO 2
#define CLK 3
#define EncoderCLK 4
#define EncoderDT 5

TM1637Display tm(CLK, DIO);
Encoder myEnc(EncoderCLK, EncoderDT);
Timer<10, millis> timer;

int countdownValue = 100;
int exposureTime = 0;
void getValueFromEncoder();
bool countdown(void *);

void setup()
{
  tm.setBrightness(0x00);
  timer.every(1000, countdown);
}

void loop()
{
  timer.tick();
  if (countdownValue == 0)
    timer.cancel();

  getValueFromEncoder();
}

void getValueFromEncoder()
{
  int newPosition = myEnc.read();
  if (newPosition != exposureTime)
  {
    exposureTime = newPosition;
  }
}

bool countdown(void *)
{
  countdownValue--;
  tm.showNumberDecEx(countdownValue, 0x40, false);
  return true;
}
