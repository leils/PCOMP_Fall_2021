const int ledA = 3;
const int ledB = 4;

int ledAState = LOW;
int ledBState = LOW;

unsigned long prevMillsA = 0;
unsigned long prevMillsB = 0;

const long intervalA = 700;
const long intervalB = 200;

void setup() {
  // pinMode(2, INPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  unsigned long currentMills = millis();
  handleA(currentMills);
  handleB(currentMills);
}

void handleA(long currentMills) {
  if(currentMills - prevMillsA >= intervalA) {
  // if(currentMills % intervalA == 0) {
    prevMillsA = currentMills;

    ledAState = !ledAState;
  }

  digitalWrite(ledA, ledAState);
}

void handleB(long currentMills) {
  if(currentMills - prevMillsB >= intervalB) {
    prevMillsB = currentMills;

  // if(currentMills % intervalB == 0) {
    ledBState = !ledBState;
  }

  digitalWrite(ledB, ledBState);
}
