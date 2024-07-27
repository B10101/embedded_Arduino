#include <Arduino.h>
#include <Servo.h>

Servo servo;

int pot_pin = 0;
int val;



void setup() {
  servo.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pot_pin);
  val = map(val, 0, 1023, 0, 180);
  servo.write(val);
  delayMicroseconds(15000);
}

