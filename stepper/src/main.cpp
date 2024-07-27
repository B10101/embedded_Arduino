#include <Arduino.h>
#include <Stepper.h>

#define STEPS 200

Stepper stepper(STEPS, 8, 9, 10, 11);

void setup() {
  stepper.setSpeed(11);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Anti-clockwise");
  stepper.step(-STEPS);
  delayMicroseconds(500000);



}

