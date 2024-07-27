#include "Arduino.h"

const int green = 2;
const int blue = 3;
const int red = 5;

void setup(){
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop(){
  for (int i = 255; i > 0; i--)
  {
    analogWrite(green, i);
    delay(10);
    analogWrite(red,255- i);
    delay(10);
    analogWrite(blue, 128-i);
    delay(10);
  }
   
  
}