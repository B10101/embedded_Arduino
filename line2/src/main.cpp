#include <Arduino.h>

const int motorRPin1 = 27; // signal pin 1 for the right motor, connect to IN1               
const int motorRPin2 = 26;  // signal pin 2 for the right motor, connect to IN2
const int motorREnable = 14; // enable pin for the right motor (PWM enabled)

const int motorLPin1 = 25; // signal pin 1 for the left motor, connect to IN3           
const int motorLPin2 = 33; // signal pin 2 for the left motor, connect to IN4
const int motorLEnable = 32; // enable pin for the left motor (PWM enabled)

const int irPins[5] = {18, 19, 21, 22, 23};
int irSensorDigital[5] = {0,0,0,0,0};
int i,j = 0;
int d = 1000;

int irSensors = B00000000; 

int motorLSpeed = 255;
int motorRSpeed = 255;
int error = 140;   // 145 best 200  //  normal 255  // mad 0 

void check();
void rightS();
void leftS();
void scanD();

void setup() {
  
  
  Serial.begin(9600);
  
  
  pinMode(motorLPin1,OUTPUT);        
  pinMode(motorLPin2,OUTPUT);
  pinMode(motorLEnable,OUTPUT);
  
  pinMode(motorRPin1,OUTPUT);        
  pinMode(motorRPin2,OUTPUT);
  pinMode(motorREnable,OUTPUT);
   
  /* Set-up IR sensor pins as input */
  for (int i = 0; i <= 4; i++) 
  {pinMode(irPins[i], INPUT);}
 

}

void loop() {
     scanD();
     check(); 
}     
     
void check( ) 
{    
     switch (irSensors) {
     
     case B00000:// on white paper 
     rightS();
     break;
     
     case B10000: // leftmost sensor on the line
     rightS();
     break;
      
     case B01000:
     rightS();
     break;
     
     case B00100: 
     rightS();
     break;
     

     case B00010: 
     rightS();
     break; 
     
     case B00001: 
     leftS();
     break;     
     }
}





void rightS() 

{
     Serial.println("                         right motor forward (spin)");
     analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, HIGH);
     digitalWrite(motorRPin2, LOW);
     
     analogWrite(motorLEnable, motorLSpeed-error);
     digitalWrite(motorLPin1, LOW);
     digitalWrite(motorLPin2,HIGH);
  
}


void leftS()  //turn left
{
     Serial.println("                         left  motor forward (spin)");
     analogWrite(motorREnable, motorRSpeed-error);
     digitalWrite(motorRPin1, LOW);
     digitalWrite(motorRPin2, HIGH);
     
     analogWrite(motorLEnable, motorLSpeed);
     digitalWrite(motorLPin1, HIGH);
     digitalWrite(motorLPin2, LOW);
  
}

void go()
{
    Serial.println("                         forward ");
     analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, HIGH);
     digitalWrite(motorRPin2, LOW);
     
     analogWrite(motorLEnable, motorLSpeed);
     digitalWrite(motorLPin1, HIGH);
     digitalWrite(motorLPin2, LOW);
  
}

void stopme()
{
     Serial.println("                         stop");
     analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, LOW);
     digitalWrite(motorRPin2, LOW);
     
     analogWrite(motorLEnable, motorLSpeed);
     digitalWrite(motorLPin1, LOW);
     digitalWrite(motorLPin2, LOW);
  
}




void scanD()
{
  for ( byte count = 0; count < 5;count++ )
{
  bitWrite(irSensors, count, !digitalRead( irPins[count] ));
} 
}