#include "Arduino.h"

const int green = 2;
const int blue = 3;

void setup(){
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop(){
  for (int i = 255; i > 0; i--)
  {
    analogWrite(green, i);
    analogWrite(blue, 256 - i);

  }
   
  
}