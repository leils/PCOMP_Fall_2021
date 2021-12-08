#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include<Fonts/FreeSans9pt7b.h>

#include <Wire.h>

 
const int SCREEN_WIDTH = 128; // OLED display width, in pixels
const int SCREEN_HEIGHT = 64; // OLED display height, in pixels
 
// initialize the display:
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

void setup() {
  // initialize serial and wait for serial monitor to open:
  Serial.begin(9600);
  if (!Serial) delay(3000);
  // first parameter of begin() sets voltage source.
  // SSD1306_SWITCHCAPVCC is for 3.3V
  // second parameter is I2C address, which is
  // 0x3C, or 3D for some 128x64 modules:
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Display setup failed");
    while (true);
  }
  Serial.println("Display is good to go");
  display.setFont(&FreeSans9pt7b);
}
void loop() {
  int sensorReading = analogRead(A0);
  // clear the display:
  display.clearDisplay();
  // set the text size to 2:
//  display.setTextSize(2);
  // set the text color to white:
  display.setTextColor(SSD1306_WHITE);
 
  // move the cursor to 0,0:
  display.setCursor(0, 20);
  // print the seconds:
  display.print("secs:");
  display.print(millis() / 1000);
 
  // move the cursor down 20 pixels:
  display.setCursor(0, 40);
  // print a sensor reading:
  display.print("sensor:");
  display.print(sensorReading);
  // push everything out to the screen:
  display.display();
}
