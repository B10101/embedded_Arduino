#include <Arduino.h>
#include <Stepper.h>

#define STEPS 200

Stepper stepper(STEPS, 8, 9, 10, 11);

int prev = 0;
void setup() {
  stepper.setSpeed(30);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(0);
  stepper.step(val-prev);
  prev = val;
}

