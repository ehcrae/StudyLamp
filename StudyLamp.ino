#define ledSwitch 6
#define ledPin 5
int ledBrightness = 255;
int ledSwitchState = 0;

void timer(int pinVal, float minuteLength) {
    for (int i = 0; i < minuteLength * 60000; i += 100) {
        delay(100);
        analogWrite(pinVal, ledBrightness);
        ledSwitchState = digitalRead(ledSwitch);
        if (ledSwitchState == HIGH) ledBrightness += 85;
        else if (ledBrightness > 255) {
            ledBrightness = 0;
            analogWrite(pinVal, ledBrightness);
        }
    }
}

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
    pinMode(ledSwitch, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    fade(ledPin, 255);
    timer(ledPin, 0.25);
    if (ledBrightness != 0) {
        fade(ledPin, 0);
    }
}
