void setup() {
  // nothing to do here
  Serial.begin(9600);
}
 
void loop() {
  // get a sensor reading:
  int sensorReading = analogRead(A0);
  Serial.println(sensorReading);
  // map the results from the sensor reading's range
  // to the desired pitch range:
  float frequency = map(sensorReading, 200, 900, 100, 1000);
  // change the pitch, play for 10 ms:
  tone(8, frequency, 10);
  delay(10);
}
