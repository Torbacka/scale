
#include <math.h>

const int latchPin = 2;
const int dataPin = 3;
const int clockPin = 4;

int currentLED = 0;
byte numbers[10]={
  0b00010100, //0
  0b11110101, //1
  0b10011000, //2
  0b10110000, //3
  0b01110001, //4
  0b00110010, //5
  0b00010011, //6 
  0b11110100, //7
  0b00010000, //8
  0b01110000  //9
};
void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}


void loop() {

    for (int i = 0; i< 4096; i++) {
    
      
      
      digitalWrite(latchPin, LOW);
      
      shiftOut(dataPin, clockPin, MSBFIRST, 0b11110001);
      
      shiftOut(dataPin, clockPin, MSBFIRST, numbers[i % 10]);
        
      digitalWrite(latchPin, HIGH);
    
      delay(1000);
    }
 
  
}

void display(double first) {
    double decimalPart;                                                              
    int fractionPart = (int) ((modf(first, &decimalPart)*10)/10);  // first number after decimalPoint

    int holeNumber = (int) decimalPart;

    int firstDigit, secondDigit, thirdDigit;
    firstDigit = holeNumber % 10;
    secondDigit = (holeNumber / 10) % 100;
    thirdDigit = (holeNumber / 100) % 1000;
    
}
