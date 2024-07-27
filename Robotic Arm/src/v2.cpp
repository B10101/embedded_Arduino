#include <AccelStepper.h>
#include <Servo.h>

// Define the number of steps per revolution for your stepper motor
const int stepsPerRevolution = 200;

// Define the motor pins
const int baseMotorPin1 = 2;    // Step pin for stepper motor
const int baseMotorPin2 = 3;    // Direction pin for stepper motor

// Define servo pins
const int shoulderServoPin = 4;
const int elbowServoPin = 5;
const int wristServoPin = 6;
const int gripperServoPin = 7;

// Create stepper motor object
AccelStepper baseMotor(1, baseMotorPin1, baseMotorPin2);

// Create servo objects
Servo shoulderServo;
Servo elbowServo;
Servo wristServo;
Servo gripperServo;

void setup() {
  // Set up stepper motor properties
  baseMotor.setMaxSpeed(1000);
  baseMotor.setAcceleration(500);

  // Attach servos to their pins
  shoulderServo.attach(shoulderServoPin);
  elbowServo.attach(elbowServoPin);
  wristServo.attach(wristServoPin);
  gripperServo.attach(gripperServoPin);

  // Initialize the serial communication
  Serial.begin(9600);
}

void loop() {
  // Example movement
  moveArm(90, 45, 30, 0); // Move to a specific position (angles in degrees)

  delay(1000); // Delay for 1 second
  moveArm(0, 0, 0, 90); // Return to the initial position (gripper closed)
  delay(1000); // Delay for 1 second
}

void moveArm(float baseAngle, float shoulderAngle, float elbowAngle, int gripperAngle) {
  // Convert angles to steps (adjust according to your arm design)
  int baseSteps = degreesToSteps(baseAngle);

  // Move the stepper motor (base)
  baseMotor.moveTo(baseSteps);
  while (baseMotor.run());

  // Move the servos
  shoulderServo.write(shoulderAngle);
  elbowServo.write(elbowAngle);
  wristServo.write(0); // Adjust as needed
  gripperServo.write(gripperAngle);

  // Wait for servos to reach their target positions
  delay(500); // You may need to adjust the delay based on servo speed and arm dynamics
}

int degreesToSteps(float degrees) {
  // Convert degrees to steps (adjust according to your stepper motor)
  float steps = degrees * stepsPerRevolution / 360.0;
  return round(steps);
}
