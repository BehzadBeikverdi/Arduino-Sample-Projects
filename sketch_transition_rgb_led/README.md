1️⃣ Introduction
This project smoothly fades an RGB LED in and out using Pulse Width Modulation (PWM) on an ESP8266 (NodeMCU). The LED brightness gradually increases and decreases in a loop.

✅ Hardware: ESP8266 (NodeMCU)
✅ Programming: Arduino C++
✅ LED Control: Smooth brightness transition

2️⃣ Components Required
🔹 ESP8266 (NodeMCU)
🔹 RGB LED (Common Anode or Common Cathode)
🔹 330Ω Resistor (optional for LED protection)
🔹 Jumper Wires
🔹 Breadboard

3️⃣ Pin Connections
RGB LED Pin	Common Cathode Setup	Common Anode Setup
Red (R)	D6 (GPIO12)	D6 (GPIO12)
GND	G (Ground)	3.3V (VCC)
Note:

This example controls only one LED channel (e.g., Red).
To control all three RGB channels, connect each to a separate PWM-capable GPIO (e.g., D5, D6, D7).
Use common anode (VCC) or common cathode (GND) accordingly.
