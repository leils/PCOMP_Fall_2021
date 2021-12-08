const int maxnum = 10;
const int minnum = 0;
int n = 0;
int increment = 1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //When reaching a minimum or maximum, swap direction of increment
  if (n <= minnum || n >= maxnum) {
    increment = increment * -1;
  }

  n += increment;
  Serial.println(n);
}
