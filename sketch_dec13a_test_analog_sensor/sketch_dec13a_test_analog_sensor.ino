char pin = A6;

void setup() {
  pinMode(pin, INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  Serial.println(analogRead(pin));
  delay(50);
  // put your main code here, to run repeatedly:

}
