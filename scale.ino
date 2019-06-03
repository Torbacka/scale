
#include <math.h>
#include "Adafruit_LEDBackpack.h"
#include <Wire.h>

#define DISPLAY_ADDRESS 0x70


const int dataPin = 1;
const int clockPin = 0;
Adafruit_7segment display = Adafruit_7segment();

double number = 0.0;

void setup() {
  
  Wire.begin(D2, D1);
  display.begin(DISPLAY_ADDRESS);
  Serial.begin(115200);
}


void loop() {
   Serial.print("Testing... ");
   Serial.println(number);

   writeToDisplay(number);
   number += 0.1;
   delay(100);
}

void writeToDisplay(double number) {
   display.printFloat(number, 1, DEC);
   display.writeDisplay();
}
