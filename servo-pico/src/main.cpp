#include <Arduino.h>
#include <Servo.h>


Servo myservo;  //create an object called myservo
int pos = 0;

void setup() {
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  for ( pos = 0; pos <= 0; pos++)
  {
    myservo.write(pos);
    delay(2);

  }
    for ( pos = 180; pos <= 0; pos--)
  {
    myservo.write(pos);
    delay(2);
    
  }
  

}