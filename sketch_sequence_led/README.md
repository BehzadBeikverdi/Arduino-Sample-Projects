## README - ESP8266 Sequential LED Blinker

### **Description**
This project demonstrates how to sequentially blink multiple LEDs connected to an ESP8266 NodeMCU. The LEDs will turn on one after another with a short delay, creating a chasing effect.

---

### **Features**
- Controls **5 LEDs** connected to GPIO pins.
- Each LED turns **on** for **300ms**, then turns **off** before the next one turns on.
- Loops continuously to create a sequential blinking effect.

---

### **Hardware Setup**
Connect the **LEDs** to the following **GPIO** pins:
| LED Number | GPIO Pin | NodeMCU Pin |
|------------|---------|------------|
| LED 1      | GPIO5   | D1         |
| LED 2      | GPIO4   | D2         |
| LED 3      | GPIO12  | D6         |
| LED 4      | GPIO13  | D7         |
| LED 5      | GPIO14  | D5         |

**Connection for each LED:**
- **Anode (+)** → **GPIO pin** (via a **220Ω resistor**)
- **Cathode (-)** → **GND**

---

### **Code Explanation**
- **Setup (`setup()`):**
  - Defines **5 LED pins** and sets them as **OUTPUT**.
  - Ensures all LEDs are initially **OFF**.

- **Loop (`loop()`):**
  - Turns each LED **ON** in sequence.
  - Waits **300ms** before turning the LED **OFF**.
  - Repeats continuously to create a sequential LED effect.

---

### **How to Use**
1. **Flash the Code** to your ESP8266.
2. **Power the ESP8266** and observe the LEDs.
3. The LEDs will blink **one after another** in a loop.

---

### **Modifications**
- Change `delay(300);` to adjust LED timing.
- Add more LEDs by modifying the `ledPins[]` array.
- Use **PWM** (analogWrite) to create a fading effect.

---

### **Troubleshooting**
- **Only some LEDs work?** Check wiring and GPIO assignments.
- **No LEDs light up?** Verify power supply and resistor values.
- **LEDs not turning off?** Ensure correct `LOW` state in `digitalWrite()`.

Enjoy coding! 🚀