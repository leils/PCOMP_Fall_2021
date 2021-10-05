#include <Servo.h>

Servo myservo; 

const int servoPin = 9;

void setup() {
  myservo.attach(servoPin);
  // put your setup code here, to run once:

}

void loop() {
  myservo.write(180);
  // put your main code here, to run repeatedly:

}
