int solenoidPin = 2; //This is the output pin on the Arduino
int buttonPin = 3;
int lastButtonRead = 0;
int lastPhotoRead = 100;
int threshold = 50;

void setup() 
{
  pinMode(solenoidPin, OUTPUT);          //Sets that pin as an output
  pinMode(4, OUTPUT);          //Sets that pin as an output
  pinMode(5, OUTPUT);          //Sets that pin as an output
  pinMode(6, OUTPUT);          //Sets that pin as an output
  pinMode(7, OUTPUT);          //Sets that pin as an output

  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

  pinMode(A0, INPUT);
}

void loop() 
{
  int photoRead = analogRead(A0);
  int buttonVal = digitalRead(buttonPin);
  
//  if (buttonVal && !lastButtonRead) {
  if (photoRead < threshold && lastPhotoRead > threshold) {
//    Serial.println("button");
    delay(500);
    digitalWrite(solenoidPin, HIGH);      //Switch Solenoid ON
    delay(100);                          //Wait 1 Second
    digitalWrite(solenoidPin, LOW);       //Switch Solenoid OFF

    //solenoid 2
    delay(500);
    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(4, LOW);

        delay(500);
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(5, LOW);

delay(500);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    
    delay(500);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

  }

  lastButtonRead = buttonVal;
  lastPhotoRead = photoRead;
}
