const char sensorPin = A2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(sensorPin));
  delay(50);
}
