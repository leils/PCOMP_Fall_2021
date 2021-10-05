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

int servoPos = 0;

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
  } else { //Automatic mode 
    // TODO: need to reset state if crossing from manual to automatic. 
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
  Serial.println(servoValue);
  analogWrite(ledPin, map(servoPos, 0, 1023, 0, 255));
}

void turnOnAll() {
  myservo.write(maxServo);
  analogWrite(ledPin, 255);
}

void turnOffAll() {
  myservo.write(minServo);
  analogWrite(ledPin, 0);
}
