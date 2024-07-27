#include <Arduino.h>

int button = 3;
int led = 7;




void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  
}

void loop() {
  int di = digitalRead(button);
  digitalWrite(led,di);
  delay(200);
  
}

