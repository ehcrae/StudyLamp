#define PomodoroTime 25
#define BreakTime 5
// add above this line (in minutes)
#define stripPin 5
#define switchPin 6

void setup() {
  pinMode(stripPin, OUTPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(stripPin, HIGH);
}

void loop() {
    while (digitalRead(switchPin) == HIGH)
    {
        digitalWrite(stripPin, HIGH);
        delay(PomodoroTime*60000);
        digitalWrite(stripPin, LOW);
        delay(200);
        digitalWrite(stripPin, HIGH);
    }
}
