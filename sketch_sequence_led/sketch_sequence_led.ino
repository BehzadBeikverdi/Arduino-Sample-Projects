// Define the GPIO pins for the 5 LEDs
const int ledPins[] = {5, 4, 12, 13, 14};  // GPIO5 (D1), GPIO4 (D2), GPIO12 (D6), GPIO13 (D7), GPIO14 (D5)
const int numLeds = 5;  // Number of LEDs

void setup() {
    // Initialize all LED pins as OUTPUT
    for (int i = 0; i < numLeds; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);  // Ensure all LEDs are OFF initially
    }
}

void loop() {
    // Loop through each LED and turn it on, wait for 1000ms, then turn it off
    for (int i = 0; i < numLeds; i++) {
        digitalWrite(ledPins[i], HIGH);  // Turn LED ON
        delay(300);                      // Wait for 300ms (.3 second)
        digitalWrite(ledPins[i], LOW);   // Turn LED OFF
        delay(300);                      // Wait for 300ms before turning the next LED on
    }
}
