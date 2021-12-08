/*
  DigitalReadSerial connected to Unity using Ardity
  
  Reads a digital input on pin 2, prints the result to Serial 
  On my mac, it uses /dev/cu.usbmodem1451301
  The main modification is the delay for 100ms
This example code is in the public domain and based on http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/
// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}
// the loop routine runs over and over again forever:
void loop() {
  bool buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  delay(100);  // IMPORTANT ---> delay in between reads
}
