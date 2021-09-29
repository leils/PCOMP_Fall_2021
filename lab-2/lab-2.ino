#include <Adafruit_DotStar.h>
// Trinket M0 - turns on LED when it gets dark

Adafruit_DotStar strip = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

const int ledPin = 2;
int analogValue = 0;
int transformedAnalog = 0;
int brightness = 0;
// analogValue input is 0-1000 (likely)

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  strip.begin();
  strip.setPixelColor(0, 0, 0, 0); strip.show();
}

void loop() {
  // AnalogValue ranges 0-255, can be mapped directly to LED
  analogValue = analogRead(A3);
  // Invert brightness to shine when dark

  transformedAnalog = map(analogValue, 0, 1000, 0, 255);
  Serial.println(transformedAnalog);
  if(transformedAnalog > 20) {
    brightness = 0;
  } else {
    brightness = 255;
  }
  analogWrite(ledPin, brightness);
  // analogWrite(ledPin, 255);
}
