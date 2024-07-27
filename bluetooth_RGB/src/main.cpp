#include <Arduino.h>
const int blue = 3;
const int red = 5;
const int green = 6;


void setup() {
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);



}

void loop() {
  if(Serial.available()){
    char incoming_byte = Serial.read();

    switch (incoming_byte)
    {
    case 'R':
      set_color(255,0,0);
      break;
    case 'b':
      set_color(0,255,0);
      break;
    case 'g':
      set_color(0,0,255);
      break;
    
    default:
      break;
    }
  }

}

void set_color(int r, int g, int b){
  analogWrite(red, r);
  analogWrite(blue, g);
  analogWrite(green, b);
}
