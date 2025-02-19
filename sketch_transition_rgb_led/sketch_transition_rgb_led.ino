#include <Arduino.h>

#define RGB_LED_PIN 12  // Use a PWM-capable pin like GPIO 12 (D6)

void setup() {
    pinMode(RGB_LED_PIN, OUTPUT);
}

void loop() {
    // Smooth color fading effect
    for (int i = 0; i < 256; i++) {
        analogWrite(RGB_LED_PIN, i);  // Increase brightness
        delay(1);
    }
    for (int i = 255; i >= 0; i--) {
        analogWrite(RGB_LED_PIN, i);  // Decrease brightness
        delay(1);
    }
}
