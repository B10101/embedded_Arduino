#include <Arduino.h>
const int motor = 5;

void setup() {
  pinMode(motor, OUTPUT);

}

void loop() {
  digitalWrite(motor, HIGH);
}

