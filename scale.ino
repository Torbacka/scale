
const int latchPin = 2;
const int dataPin = 3;
const int clockPin = 4;

int currentLED = 0;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}


void loop() {

    for (int i = 0; i< 4096; i++) {
    
      
      
      digitalWrite(latchPin, LOW);
      if (i < 255) {
        shiftOut(dataPin, clockPin, MSBFIRST, 0);
      } else {
        String info = String("i: ") + i + String("   i%255: ") + modff(23.42, 1.0);
        Serial.println(info);
        shiftOut(dataPin, clockPin, MSBFIRST, i/255);
      }
      shiftOut(dataPin, clockPin, MSBFIRST, i);
        
      digitalWrite(latchPin, HIGH);
    
      delay(10);
    }
 
  
}

void display(float first) {


  
}
