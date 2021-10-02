const byte potPin = A2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potReading = analogRead(potPin);
  Serial.println(potReading);
  // put your main code here, to run repeatedly:

}
