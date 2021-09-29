#include <Servo.h>

Servo servoMotor;
int servoPin = 3;
int sensorValue = 0;
float EMA_a = .02;
int EMA_S = 0;
int lastServoAngle = 0;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(servoPin);
  EMA_S = analogRead(A0);
}

void loop() {
  int sensorValue = analogRead(A0);
  EMA_S = (EMA_a * sensorValue) + ((1 - EMA_a)*EMA_S);
  Serial.println(EMA_S);

  int servoAngle = map(EMA_S, 0, 1023, 0, 179);
  if (servoAngle != lastServoAngle) {
    servoMotor.write(servoAngle);
    lastServoAngle = servoAngle;
  }
}
