#define ledPin 3

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    analogWrite(ledPin, 255);
}