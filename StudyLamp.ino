unsigned long StudyMinutes = 25;
unsigned long BreakMinutes = 5;
unsigned long DelayMillis = 1000;

// adjust your timing above this line (in minutes)

#define stripPin 5
#define buttonPin 6

void setup() {
  pinMode(stripPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

unsigned long studyMillis = 0;
unsigned long breakMillis = 0;

void loop() {
  unsigned long previousMillis = millis();

  while (studyMillis < (StudyMinutes*60000 + previousMillis) && digitalRead(buttonPin) == HIGH) {
    studyMillis = millis();
    digitalWrite(stripPin, HIGH);
  }

  digitalWrite(stripPin, LOW);
  delay(DelayMillis);

  while (breakMillis < (BreakMinutes*60000 + studyMillis + previousMillis) && digitalRead(buttonPin) == HIGH) {
    breakMillis = millis();
    digitalWrite(stripPin, HIGH);
  }
  studyMillis = 0;
  breakMillis = 0;
}