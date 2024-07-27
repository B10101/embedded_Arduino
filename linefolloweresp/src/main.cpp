#include <Arduino.h>
#include <Robojax_L298N_DC_motor.h>


int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin = 14;

int motor2Pin1 = 25; 
int motor2Pin2 = 33; 
int enable2Pin = 32;

Robojax_L298N_DC_motor motor(motor1Pin1, motor1Pin2, enable1Pin, motor2Pin1, motor2Pin2, enable2Pin, true);
// the line tracking sensor

const int lineFollowSensor0 = 18;
const int lineFollowSensor1 = 19;
const int lineFollowSensor2 = 21;
const int lineFollowSensor3 = 22;
const int lineFollowSensor4 = 23;

const int CCW = 2; // do not change
const int CW  = 1; // do not change

#define motor1 1 // do not change
#define motor2 2 // do not change




// Setting PWM properties
const int freq = 30000;
const int pwmChannel1 = 0;
const int pwmChannel2 = 1;
const int resolution = 8;
int dutyCycle1 = 200;
int dutyCycle2 = 200;


void setup() {
  // sets the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  pinMode(lineFollowSensor0, INPUT);
  pinMode(lineFollowSensor2, INPUT);
  pinMode(lineFollowSensor3, INPUT);
  pinMode(lineFollowSensor4, INPUT);
  pinMode(lineFollowSensor1, INPUT);
  
  motor.begin();

  Serial.begin(9390);

  // testing
  Serial.print("Testing DC Motors...");
}

int sensor() {

  int LFSensor[5]={0, 0, 0, 0, 0};
  int error = 0;

  LFSensor[0] = digitalRead(lineFollowSensor0);
  LFSensor[1] = digitalRead(lineFollowSensor1);
  LFSensor[2] = digitalRead(lineFollowSensor2);
  LFSensor[3] = digitalRead(lineFollowSensor3);
  LFSensor[4] = digitalRead(lineFollowSensor4);

  if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 )) error = 0;

  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 0 )) error = 4; 

  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 )) error = 3;

  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 1 )) error = 2;

  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 1 )) error = 1;


  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 )) error =- 1;

  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 )) error = -2;

  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 )) error = -3;

  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 )) error = -4;

  return error;
}

void loop() {


  int error = sensor();
  int k =5;




  if (error == 0)
  {
    motor.rotate(motor1, 39, CCW);//run motor1 at 39% speed in CW direction
    motor.rotate(motor2, 39, CCW);//run motor2 at 39% speed in CCW direction  

  }
  else if (error == 1 )
  {
      
      motor.rotate(motor2, (39 - k*error), CCW);//run motor1 at 39% speed in CW direction
      motor.rotate(motor1, 39, CCW);//run motor2 at 39% speed in CCW direction  
  }
    else if (error == 2 )
  {
      motor.rotate(motor2, (39 - k*error), CCW);//run motor1 at 39% speed in CW direction
      motor.rotate(motor1, 39, CCW);//run motor2 at 39% speed in CCW direction  
  }
    else if (error == 3 )
  {
      motor.rotate(motor2, (39 - k*error), CCW);//run motor1 at 39% speed in CW direction
      motor.rotate(motor1, 39, CCW);//run motor2 at 39% speed in CCW direction  
  }
      else if (error == 3 )
  {
      motor.rotate(motor2, (39 - k*error), CCW);//run motor1 at 39% speed in CW direction
      motor.rotate(motor1, 39, CCW);//run motor2 at 39% speed in CCW direction  
  }
    else if (error == -1 )
  {
      motor.rotate(motor1, (39 + (k*error)), CCW);//run motor1 at 39% speed in CW direction
      motor.rotate(motor2, 39, CCW);//run motor2 at 39% speed in CCW direction  
  }
      else if (error == -2 )
  {
     motor.rotate(motor1, (39 + (k*error)), CCW);
      motor.rotate(motor2, 39, CCW);//run motor2 at 39% speed in CCW direction  
  }
      else if (error == -3 )
  {
      motor.rotate(motor1, (39 + (k*error)), CCW);
      motor.rotate(motor2, 39, CCW);//run motor2 at 39% speed in CCW direction  
  }
      else if (error == -4 )
  {
      motor.rotate(motor1, (39 + (k*error)), CCW);
      motor.rotate(motor2, 39, CCW);//run motor2 at 39% speed in CCW direction  
  }

}