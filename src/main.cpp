#include <Arduino.h>

#define LED_GREEN 13
#define LED_YELLOW 12
#define LED_RED 8

unsigned long previousMillis = 0;
const long greenTime = 5000;
const long yellowTime = 2000;
const long redTime = 5000;
int currentState = 0;

void setup() {
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);
}

void loop() {
    unsigned long currentMillis = millis();

    switch (currentState) {
        case 0: // Green Light
            digitalWrite(LED_GREEN, HIGH);
            digitalWrite(LED_YELLOW, LOW);
            digitalWrite(LED_RED, LOW);
            if (currentMillis - previousMillis >= greenTime) {
                previousMillis = currentMillis;
                currentState = 1;
            }
            break;

        case 1: // Yellow Light
            digitalWrite(LED_GREEN, LOW);
            digitalWrite(LED_YELLOW, HIGH);
            digitalWrite(LED_RED, LOW);
            if (currentMillis - previousMillis >= yellowTime) {
                previousMillis = currentMillis;
                currentState = 2;
            }
            break;

        case 2: // Red Light
            digitalWrite(LED_GREEN, LOW);
            digitalWrite(LED_YELLOW, LOW);
            digitalWrite(LED_RED, HIGH);
            if (currentMillis - previousMillis >= redTime) {
                previousMillis = currentMillis;
                currentState = 0;
            }
            break;
    }
}
