const char sensorPins[] = {
  A0, A2, A3, A6, A7 
};
int sensorStatus[] = {
  1,1,1,1,1
};

int pinCount = 5;
int lastCount = 0;
int threshold = 100;
int downTime = 0;
bool downWaiting = false;
int solenoidPin = 2;

void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(sensorPins[thisPin], INPUT);
  }

  pinMode(solenoidPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
//  int count = 0;

  for (int pinIndex = 0; pinIndex < pinCount; pinIndex++) {
    int pinReading = analogRead(sensorPins[pinIndex]);
    int lastStatus = sensorStatus[pinIndex];
    if ((pinReading < threshold) && (lastStatus == HIGH)) { //cross threshold down
      downWaiting = true;
      downTime = millis();
      
      Serial.println(pinIndex);
      sensorStatus[pinIndex] = !sensorStatus[pinIndex];
    } else if ((pinReading > threshold) && (lastStatus == LOW)) { //cross threshold up
      Serial.println(pinIndex);
      sensorStatus[pinIndex] = !sensorStatus[pinIndex];
    }
  }

  int currentTime = millis();
  if (currentTime >= downTime + 1000 && currentTime <= downTime + 1500) {
    digitalWrite(solenoidPin, HIGH);
  } else {
    digitalWrite(solenoidPin, LOW);
  }
//  if (count != lastCount){
//    Serial.print('latest count: ');
//    Serial.println(count);
//    lastCount = count;
//  }
}

void calibrate() {
  
}
