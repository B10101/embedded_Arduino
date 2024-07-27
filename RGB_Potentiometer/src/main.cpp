#include <Arduino.h>
const int bluec = 9;
const int redc = 10;
const int greenc = 11;

const int pot = A1;



void red(int x, int y){
  analogWrite(x, y);
}
void blue(int x, int y){
  analogWrite(x, y);
}
void green(int x, int y){
  analogWrite(x, y);
}
void setup() {
  pinMode(bluec, OUTPUT);
  pinMode(redc, OUTPUT);
  pinMode(greenc, OUTPUT);
  pinMode(pot, A1);
}

void loop() {
  int read = analogRead(pot);
  int speed= map(read, 0 , 1023, 0, 255);

  if (speed<=85)
  {
    int r = map(speed,0,1023,0,255);
    red(redc,r);
  }
  else if (speed <= 170)
  {
    int r = map(speed,0,1023,0,255);
    blue(bluec,r);
  }
   else
  {
    int r = map(speed,0,1023,0,255);
    green(greenc,r);
  }
  
  
  

}
