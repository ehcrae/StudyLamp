#define whitePin 9
#define redPin 10

void setup() {
    pinMode(whitePin, OUTPUT);
    pinMode(redPin, OUTPUT);
}

void loop() {

    for (int i = 0; i <= 255; i++) {
        analogWrite(redPin, i);
        delay(10);
    }

    delay(30000);

    for (int i = 255; i >= 0; i--) {
        analogWrite(redPin, i);
        delay(10);
    }

    delay(100);

    for (int i = 0; i <= 255; i++) {
        analogWrite(whitePin, i);
        delay(10);
    }

    delay(6000);

    for (int i = 255; i >= 0; i--) {
        analogWrite(whitePin, i);
        delay(10);
    }

    delay(100);
    
}
