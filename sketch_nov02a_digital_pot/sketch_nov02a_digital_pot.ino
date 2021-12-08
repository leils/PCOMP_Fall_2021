#include <SPI.h>
const int CSPin = 10;   // chip select pin number
const int potPin = 1;

void setup() {
  // initialize SPI:
  SPI.begin();
}

void loop() {
  tone(9, 440); // play a tone on pin 9

//  digitalPotWrite(4, 255);
digitalPotWrite(potPin, 100);
delay(20);
digitalPotWrite(potPin, 255);
delay(20);

////   fade the loudness up:
//  for (int loudness = 100; loudness <= 255; loudness++) {
//    digitalPotWrite(potPin, loudness);
//    delay(20);
//  }
//  delay(1000); // delay 1 second
//
//  // fade the loudness down:
//  for (int loudness = 255; loudness >= 100; loudness--) {
//    digitalPotWrite(potPin, loudness);
//    delay(20);
//  }
//
//  delay(1000); // delay 1 second
}

void digitalPotWrite(int address, int value) {
  // take the SS pin low to select the chip:
  digitalWrite(CSPin, LOW);
  // send in the address and value via SPI:
  SPI.transfer(address);
  SPI.transfer(value);
  // take the SS pin high to de-select the chip:
  digitalWrite(CSPin, HIGH);
}
