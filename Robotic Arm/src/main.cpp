#include <Arduino.h>
#include <Servo.h>
#include <Stepper.h>
#include <string.h>

#define STEPS 200


Servo servo_0, servo_1, servo_2;
Stepper stepper_1(STEPS, 2,3,4,5);
String received = "";
String servo[3] = {"000", "000", "000"};
int pos[6] = { 34, 90, 120, 90, }; // Initialize an array to store servo positions as integers.
String stepper[1] = {"000"};
int dump;
char c;

// Function to handle received data and update servo positions.
void dataHandle(String line)
{
  int servoNum;
  int lineIndex = 0;
  int valueIndex = 0;
  for (servoNum = 0; servoNum < 6; servoNum++)
  {
    while (line[lineIndex] != ' ' && line[lineIndex] != 'e')
    {
      servo[servoNum][valueIndex] = line[lineIndex];
      valueIndex++;
      lineIndex++;
    }
    lineIndex++;
    pos[servoNum] = (servo[servoNum].toInt() / pow(10, 3 - valueIndex));
    valueIndex = 0;
  }
}
// Function to update servo positions based on integer values.
void armPosUpdate()
{
  stepper_1.step(pos[0]);
  servo_0.write(((float)180 / 270) * pos[1]);
  servo_1.write(((float)180 / 270) * pos[2]);
  servo_2.write(((float)180 / 270) * pos[3]);
}
String readServoPositions()
{
  int i;
  String poses = "";
  pos[1] = ((float)servo_0.read() * 1.5); // Convert servo positions back to integers.
  pos[2] = ((float)servo_1.read() * 1.5);
  pos[3] = ((float)servo_2.read() * 1.5);
  for (i = 0; i < 6; i++)
  {
    poses += String(String(pos[i]) + " ");
  }
  return poses;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  servo_0.attach(3);
  servo_1.attach(5);
  servo_2.attach(6);
  armPosUpdate();
  Serial.begin(115200); // Initialize serial communication at 115200 baud rate.
  Serial.write("start"); // Send "start" to indicate the setup is complete.
}
  

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    delay(20);
    do
    {
      c = Serial.read();
      if (c == 'u')
      {
        Serial.println(String("Update: " + readServoPositions()));
        delay(10);
        break;
      }
      else received += c;
    }
    while (c != 'e');
    while (Serial.available() > 0) dump = Serial.read(); // Clear the serial buffer.
    if (c != 'u' && received != "")
    {
      Serial.println(String("Received: " + received));
      dataHandle(received);
      armPosUpdate();
      received = "";
    }
  }
}

