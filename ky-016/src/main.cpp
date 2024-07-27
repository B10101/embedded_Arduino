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
    analogWrite(red,255- i);
    analogWrite(blue, 128-i);
  }
   for (int i = 0; i < 255; i++)
  {
    analogWrite(green, i);
    analogWrite(red,255- i);
    analogWrite(blue, 128-i);
  }
  
}