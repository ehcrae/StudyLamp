#define whitePin 9
#define redPin 10

void fade(int pinVal, int endVal) {
    if (endVal == 255) {
        for (int i = 0; i <= 255; i++) {
            analogWrite(pinVal, i);
            delay(10);
        }
    }
    else {
        for (int i = 255; i >= 0; i--) {
            analogWrite(pinVal, i);
            delay(10);
        }
    }
}

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    fade(whitePin, 255);
    delay(30000);
    fade(whitePin, 0);
    delay(100);
    fade(redPin, 255);
    delay(6000);
    fade(redPin, 0);
    delay(100);
}
