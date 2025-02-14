## README - ESP8266 Web Server LED Control

### Description
This project demonstrates how to control an external LED connected to an ESP8266 using a web server. The ESP8266 connects to Wi-Fi and hosts a simple web server with endpoints to turn the LED on and off.

### Features
- Connects the ESP8266 to a Wi-Fi network.
- Hosts a web server on port 80.
- Allows LED control via HTTP requests (`/led/on` and `/led/off`).
- Displays the ESP8266's IP address upon connection.

---

## Instructions

### **1. Hardware Setup**
- Connect an LED to **GPIO5 (D1)** of the ESP8266.
  - **LED Anode (+)** → **D1 (GPIO5)**
  - **LED Cathode (-)** → **GND** (through a **220Ω resistor**)

### **2. Code Explanation**
- **Wi-Fi Connection**: Connects the ESP8266 to the defined Wi-Fi (`ssid` and `password`).
- **Web Server**: Handles HTTP requests:
  - **`/led/on`** → Turns the LED on.
  - **`/led/off`** → Turns the LED off.
  - **`/`** → Displays a simple message.
- **Loop Function**: Continuously listens for incoming client requests.

### **3. How to Use**
1. **Flash the Code** onto your ESP8266.
2. **Open the Serial Monitor** (Baud rate: `9600`).
3. **Find the ESP8266's IP Address** printed on the Serial Monitor.
4. Open a web browser and enter:
   - `http://<ESP_IP>/led/on` → Turns the LED **ON**.
   - `http://<ESP_IP>/led/off` → Turns the LED **OFF**.

### **4. Troubleshooting**
- **Cannot Connect to Wi-Fi?** Check SSID and Password.
- **ESP8266 Not Responding?** Reset the board and ensure proper power supply.
- **LED Not Working?** Verify wiring and resistor values.

Happy coding! 🚀