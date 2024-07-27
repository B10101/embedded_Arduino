#include <Arduino.h>
const int buzzer = 9;
const int pot = A1;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(pot, A0);
}

void loop() {
  int read = analogRead(pot);
  int brightness= map(read, 0 , 1023, 0, 255);
  tone(buzzer, brightness);
  delay(2);
}