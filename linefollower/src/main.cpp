#include "Arduino.h"

int mr1=2;  //motor right 1
int mr2=3;  //motor right 2
int ml1=4;  //motor left 1
int ml2=5; //motor left 2
int rr=6;   //sensor right
int r=7;
int m=8;   //sensor right
int l=9;  
int ll=10;  //sensor left
int srr=0;
int sr=0;
int sm=0;
int sl=0;
int sll=0;
int enr=0; 
int  enl=1;

int vspeed=100;    
int tspeed=255;
int tdelay=20;


void forward();
void left();
void right();
void stop();
void  setup()
{
 pinMode(mr1,OUTPUT);
 pinMode(mr2,OUTPUT);
 pinMode(ml1,OUTPUT);
 pinMode(ml2,OUTPUT);
 pinMode(sl,INPUT);
 pinMode(sll,INPUT);
 pinMode(sm,INPUT);
 pinMode(sl,INPUT);
 pinMode(srr,INPUT);
  
 delay(5000);
}

void loop()
{
 sr=digitalRead(sr);
 sl=digitalRead(sl);
 srr=digitalRead(srr);
 sll=digitalRead(sll);
 sm=digitalRead(sm);

  
  if(sl==LOW && sr==LOW)
  {
  forward(); //maju
  }

  if(sl==HIGH  && sr==LOW)
  {
  left(); //belok kiri
  }
 
  if(sl==LOW && sr==HIGH)
  { 
  right(); //belok kanan
  }
  
  if(sl==HIGH && sr==HIGH)
  {
  stop(); //berhenti
  }
}

void forward()
 {
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  analogWrite (enr,vspeed);
  analogWrite (enl,vspeed);
 } 

void backward()
  {
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
  analogWrite (enr,vspeed);
  analogWrite (enl,vspeed);
  }

void right()
 {
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
  delay(tdelay);
 } 

void left()
 {
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
  delay(tdelay);
}  

void stop()
 {
  analogWrite (enr,0);
  analogWrite  (enl,0);
 }