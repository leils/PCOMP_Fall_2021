void setup() {
  Serial.begin(9600);
}
void loop() {
  if (Serial.available()) {
    int fromSerial = Serial.parseInt();               // read first part of string as int
    analogWrite(3, fromSerial);
    fromSerial = Serial.parseInt();                    // read second part of string as int            
    analogWrite(5, fromSerial);   
  }
}
