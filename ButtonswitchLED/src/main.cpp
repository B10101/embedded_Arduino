#include <Arduino.h>

const int button = 8;
const int Led = 9;



void setup() {
  pinMode(button, INPUT);
  pinMode(Led, OUTPUT);
 
}

void loop() {
  int buttonstate = digitalRead(button);
  if (buttonstate == 1)
  {
    digitalWrite(Led, HIGH);
    delay(1000);
  }

  
}
