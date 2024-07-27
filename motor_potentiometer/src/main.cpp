#include <Arduino.h>
const int mot = 5;
const int pot = A1;

void setup() {
  pinMode(mot, OUTPUT);
  pinMode(pot, A1);
}

void loop() {
  int read = analogRead(pot);
  int speed= map(read, 0 , 1023, 0, 255);
  analogWrite(mot, speed);
  delay(2);
}
