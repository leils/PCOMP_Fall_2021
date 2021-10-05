#include <Servo.h>

Servo myservo;

const byte buttonPin = 3;
const byte slidePin = A2;
const byte servoPin = 9;
const byte ledPin = 5;
const byte photoPin = A0;

const int photoThreshold = 15;
//hysteresis adds "stickyness" to the crossing of the threshold
const int hysteresisMargin = 10;
const int minServo = 100;
const int maxServo = 170;

int servoPos = 0; // 0 - 1024 range 

//stores on/off mode when in Automatic mode 
int photoMode = LOW;

int lastManualModeReading = LOW;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //note: NOT HANDLING MODE CHANGES PROPERLY (does not move to current state when moving manual -> automatic
  int manualMode = digitalRead(buttonPin);
  if (manualMode) { //manual mode 
    int potReading = analogRead(slidePin);
    writeOut(potReading);
  } else if (!manualMode && lastManualModeReading) { //find the falling value for Manual -> Auto change
    //reset to low
    Serial.println('switching change');
    turnOffAll();
    photoMode = LOW;
    servoPos = minServo;
  } else { //Automatic mode 
    int photoReading = analogRead(photoPin);
    if ((photoReading < (photoThreshold - hysteresisMargin)) && !photoMode) {
      //turn on if reading crosses threshold & was previously off
      turnOnAll();
      photoMode = HIGH;
    } else if ((photoReading > (photoThreshold + hysteresisMargin)) && photoMode) {
      //turn off if reading crosses threshold & was previously on
      Serial.println("turning off");
      turnOffAll();
      photoMode = LOW;
    }
  }

  lastManualModeReading = manualMode;
  delay(50);
}

void writeOut(int rawPotOutput) {
  if ((servoPos - rawPotOutput) > 15) {
    servoPos-= 10;
     
  } else if((servoPos - rawPotOutput) < -15) {
    servoPos+= 10;
  }

  int servoValue = map(servoPos, 0, 1023, minServo, maxServo);
  
  myservo.write(servoValue);
  Serial.println(servoPos);
  analogWrite(ledPin, map(servoPos, 0, 1023, 0, 255));
}

//void writeOutput(val) {
//  
//}
//
//void upMode() {
//  if (servoPos < 1004) {
//    servoPos+= 10;
//  }
//
//  writeOutput();
//}
//
//void downMode() {
//  if (servoPos > 20) {
//    servoPos-= 10;
//  }
//
//  writeOutput();
//}

void turnOnAll() {
  myservo.write(maxServo);
  analogWrite(ledPin, 255);
  servoPos = 1020; //needed for consistency between states
}

void turnOffAll() {
  myservo.write(minServo);
  analogWrite(ledPin, 0);
  servoPos = 0; //needed for consistency between states
}
