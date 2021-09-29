#include <Servo.h>

Servo myservo;

const byte togglePin = A4;
const byte potPin = A0;
const byte servoPin = 5;
const byte ledPin = 2;
const byte photoPin = A2;
const int photoThreshold = 20;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int manualMode = digitalRead(togglePin);
  if (manualMode) {
    int potReading = analogRead(potPin);
    writeOut(potReading);
  } else {
    int photoReading = analogRead(photoPin);
    if (photoReading < photoThreshold) {
      writeOut(1023);
    } else {
      writeOut(0);
    }
  }
}

void writeOut(int rawPotOutput) {
  Serial.println(rawPotOutput);
  myservo.write(map(rawPotOutput, 0, 1023, 0, 180));
  analogWrite(ledPin, map(rawPotOutput, 0, 1023, 0, 255));
  delay(15);
}
