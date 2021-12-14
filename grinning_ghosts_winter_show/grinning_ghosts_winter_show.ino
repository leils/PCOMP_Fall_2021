const char sensorPins[] = {
  A0, A1, A2, A3, A6
};
int sensorStatus[] = {
  1,1,1,1,1
};

const int solenoidPins[] = {
  2, 4, 5, 6, 7
};

int pinCount = 5;
int lastCount = 0;
int threshold = 100;
int downTime = 0;
bool downWaiting = false;

void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(sensorPins[thisPin], INPUT);
  }

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
      
      Serial.write(pinIndex);
      sensorStatus[pinIndex] = !sensorStatus[pinIndex];
    } else if ((pinReading > threshold) && (lastStatus == LOW)) { //cross threshold up
      Serial.write(pinIndex);
      sensorStatus[pinIndex] = !sensorStatus[pinIndex];
    }
  }

  // int count should equal the number of statuses are low 
  // if the count doesn't equal the last one & the new count is 5: 
  // set the time in millis 
  // wait a set time 
  // run the solenoid thing 

//  if (count != lastCount){
//    Serial.print('latest count: ');
//    Serial.println(count);
//    lastCount = count;
//  }
}

void calibrate() {
  
}
