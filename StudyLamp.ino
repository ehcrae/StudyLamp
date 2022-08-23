unsigned long StudyMinutes = 25; // minutes
unsigned long BreakMinutes = 5; // minutes
unsigned long DelayMillis = 1000; // milliseconds

// adjust the timing of your pomodoro sessions with the values above!

#define stripPin 5
#define rockerPin 6

void setup() {
  pinMode(stripPin, OUTPUT);
  pinMode(rockerPin, INPUT);
}

unsigned long studyMillis = 0;
unsigned long breakMillis = 0;

void loop() {
  unsigned long previousMillis = millis();

  while (studyMillis < (StudyMinutes*60000 + previousMillis) && digitalRead(rockerPin) == HIGH) {
    studyMillis = millis();
    digitalWrite(stripPin, HIGH);
  }

  digitalWrite(rockerPin, LOW);
  delay(DelayMillis);

  while (breakMillis < (BreakMinutes*60000 + studyMillis + previousMillis) && digitalRead(rockerPin) == HIGH) {
    breakMillis = millis();
    digitalWrite(rockerPin, HIGH);
  }
  studyMillis = 0;
  breakMillis = 0;
}