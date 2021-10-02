#include <Servo.h>

Servo myservo;

const byte togglePin = A4;
const byte potPin = A0;
const byte servoPin = 5;
const byte ledPin = 2;
const byte photoPin = A2;
const int photoThreshold = 15;
//hysteresis adds "stickyness" to the crossing of the threshold
const int hysteresisMargin = 10;

int servoPos = 0;

//stores on/off mode when in Automatic mode 
int photoMode = LOW;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //note: NOT HANDLING MODE CHANGES PROPERLY (does not move to current state when moving manual -> automatic
  int manualMode = digitalRead(togglePin);
  if (manualMode) { //manual mode 
    int potReading = analogRead(potPin);
    writeOut(potReading);
  } else { //Automatic mode 
    // need to reset state if crossing from manual to automatic. 
    int photoReading = analogRead(photoPin);
//    Serial.println(photoReading);
    if ((photoReading < (photoThreshold - hysteresisMargin)) && !photoMode) {
      //turn on if reading crosses threshold & was previously off
      Serial.println("turning on");
      turnOnAll();
      photoMode = HIGH;
    } else if ((photoReading > (photoThreshold + hysteresisMargin)) && photoMode) {
      //turn off if reading crosses threshold & was previously on
      Serial.println("turning off");
      turnOffAll();
      photoMode = LOW;
    }
  }
  delay(50);
}

void writeOut(int rawPotOutput) {
  Serial.println(rawPotOutput);

  if ((servoPos - rawPotOutput) > 15) {
    servoPos-= 10;
     
  } else if((servoPos - rawPotOutput) < -15) {
    servoPos+= 10;
  }
  
  myservo.write(map(servoPos, 0, 1023, 10, 180));
  analogWrite(ledPin, map(servoPos, 0, 1023, 0, 255));
}

void turnOnAll() {
  myservo.write(178);
  analogWrite(ledPin, 255);
}

void turnOffAll() {
  myservo.write(3);
  analogWrite(ledPin, 0);
}
