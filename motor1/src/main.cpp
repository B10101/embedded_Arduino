#include <Arduino.h>

int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin = 14;

int motor2Pin1 = 25; 
int motor2Pin2 = 33; 
int enable2Pin = 32;

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
  
  // configure LED PWM functionalities for motor 1
  ledcSetup(pwmChannel1, freq, resolution);
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel1);

  // configure LED PWM functionalities for motor 2
  ledcSetup(pwmChannel2, freq, resolution);
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable2Pin, pwmChannel2);

  Serial.begin(115200);

  // testing
  Serial.print("Testing DC Motors...");
}

void loop() {
  // Move the DC motor 1 forward at maximum speed
  Serial.println("Moving Motor 1 Forward");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 
  delay(2000);

  // Stop the DC motor 1
  Serial.println("Motor 1 stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  delay(1000);

  // Move DC motor 1 backwards at maximum speed
  Serial.println("Moving Motor 1 Backwards");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW); 
  delay(2000);

  // Stop the DC motor 1
  Serial.println("Motor 1 stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  delay(1000);

  // Move DC motor 1 forward with increasing speed
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  while (dutyCycle1 <= 255){
    ledcWrite(pwmChannel1, dutyCycle1);   
    Serial.print("Motor 1 Forward with duty cycle: ");
    Serial.println(dutyCycle1);
    dutyCycle1 = dutyCycle1 + 5;
    delay(500);
  }
  dutyCycle1 = 200;

  // Move the DC motor 2 forward at maximum speed
  Serial.println("Moving Motor 2 Forward");
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH); 
  delay(2000);

  // Stop the DC motor 2
  Serial.println("Motor 2 stopped");
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(1000);

  // Move DC motor 2 backwards at maximum speed
  Serial.println("Moving Motor 2 Backwards");
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW); 
  delay(2000);

  // Stop the DC motor 2
  Serial.println("Motor 2 stopped");
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(1000);

  // Move DC motor 2 forward with increasing speed
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  while (dutyCycle2 <= 255){
    ledcWrite(pwmChannel2, dutyCycle2);   
    Serial.print("Motor 2 Forward with duty cycle: ");
    Serial.println(dutyCycle2);
    dutyCycle2 = dutyCycle2 + 5;
    delay(500);
  }
  dutyCycle2 = 200;
}
