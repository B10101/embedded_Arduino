#include <Arduino.h>
const int led = 9;
const int pot = A1;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pot, A0);
}

void loop() {
  int read = analogRead(pot);
  int brightness= map(read, 0 , 1023, 0, 255);
  analogWrite(led, brightness);
  delay(2);
}
