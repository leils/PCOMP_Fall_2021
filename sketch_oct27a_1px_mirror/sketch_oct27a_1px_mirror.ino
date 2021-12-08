#include <Servo.h>
Servo myServo;
int outPin = 5;
int ledPin = 3;

void setup() {
  Serial.begin(9600);
  myServo.attach(outPin);

}

void loop() {
  if(Serial.available()){
    byte serialByte = Serial.read();
    int ledmapped = map(serialByte, 0, 100, 0, 255); 
    analogWrite(3, mapped);
    int servomapped = map(serialByte, 0, 100, 60, 120);
    myServo.write(servomapped);
    delay(10);
  }
  // put your main code here, to run repeatedly:

}
