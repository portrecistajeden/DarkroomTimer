#include <Arduino.h>
#include <TM1637Display.h>

#define DIO 2 
#define CLK 3

TM1637Display display(CLK, DIO);

void setup() {
  // put your setup code here, to run once:
  display.setBrightness(0x00);
  display.showNumberDecEx(5);
}

void loop() {
  // put your main code here, to run repeatedly:
}

