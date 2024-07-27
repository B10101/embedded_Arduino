#include <Arduino.h>
const int blue = 3;
const int red = 5;
const int green = 6;


void setup() {
  pinMode(blue, OUTPUT);
   pinMode(red, OUTPUT);

 pinMode(green, OUTPUT);


}

void loop() {
  digitalWrite(blue, HIGH);
  delay(500);
  digitalWrite(blue,LOW);
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red,LOW);
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(green,LOW);

}
