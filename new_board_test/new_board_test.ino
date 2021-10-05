#include <Servo.h>

Servo myservo;

const int buttonPin = 3;
const int ledPin = 5;
const byte photoPin = A0;
const byte slidePin = A2;
const byte servoPin = 9;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(photoPin, INPUT);
  pinMode(slidePin, INPUT);
  Serial.begin(9600);
  myservo.attach(servoPin);
}

void loop() {
  int buttonValue = digitalRead(buttonPin);
  int photoValue = analogRead(photoPin);
  int slideValue = analogRead(slidePin);


  Serial.println(slideValue);

  if (buttonValue) {
    analogWrite(ledPin, 255);
    myservo.write(180);
  } else {
    analogWrite(ledPin, 0);
    myservo.write(5);
  }
  
  // put your main code here, to run repeatedly:

}
