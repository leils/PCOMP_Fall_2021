#define BUTTON_PIN 2
#define LED_A 3
#define LED_B 4

int ledState = LOW;
int lastButtonState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  // int buttonState = digitalRead(BUTTON_PIN);

  // if (buttonState) {
  //   ledState = !ledState;
  // }

  if (buttonReleased()) {
    ledState = !ledState;
  }

  digitalWrite(LED_A, ledState);
  digitalWrite(LED_B, ledState);
}


bool buttonReleased() {
  int buttonState = digitalRead(BUTTON_PIN);
  int hasBeenReleased = false;

  if((buttonState == 0) && (lastButtonState == 1)) {
    hasBeenReleased = true;
    Serial.println("released");
    delay(100);
  }

  lastButtonState = buttonState;

  return hasBeenReleased;
}
