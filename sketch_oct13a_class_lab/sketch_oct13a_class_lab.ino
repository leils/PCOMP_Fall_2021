#define RED 3
#define GREEN 4

const int redInterval = 1000;
const int greenInterval = 100;

int redStart = 0;
int greenStart = 0;

int redState = LOW;
int greenState = LOW;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  checkLED(RED, &redStart, &redState, redInterval);
  checkLED(GREEN, &greenStart, &greenState, greenInterval);
  

  digitalWrite(RED, redState);
  digitalWrite(GREEN, greenState);
}

void checkLED(int pin, int* start, int* state, int interval) {
  int currentTime = millis();
  if (currentTime - *start > interval) {
    *start = currentTime;
    *state = !*state;
  }
}
