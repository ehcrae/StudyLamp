#define PomodoroTime 25
#define BreakTime 5
// add above this line (in minutes)
#define stripPin 5
#define buttonPin 6

void setup() {
  pinMode(stripPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(stripPin, HIGH);
}

void loop() {
    for (int i = 0; i <= PomodoroTime*60000; i++) {
        if (digitalRead(buttonPin) == HIGH && digitalRead(stripPin) == LOW) {
            digitalWrite(stripPin, HIGH);
            delay(100);
            } else if (digitalRead(buttonPin) == HIGH && digitalRead(stripPin) == HIGH) {
                digitalWrite(stripPin, LOW);
                delay(100);
                }
    }
    delay(200);
    for (int i = 0; i <= BreakTime*60000; i++) {
        if (digitalRead(buttonPin) == HIGH && digitalRead(stripPin) == LOW) {
            digitalWrite(stripPin, HIGH);
            } else if (digitalRead(buttonPin) == HIGH && digitalRead(stripPin) == HIGH) {
                digitalWrite(stripPin, LOW);
                }
    }
}
