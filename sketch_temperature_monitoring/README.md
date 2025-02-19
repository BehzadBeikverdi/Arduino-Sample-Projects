1️⃣ Introduction
The DS18B20 is a digital temperature sensor that communicates using the 1-Wire protocol. It provides accurate temperature readings and can operate on either 3.3V or 5V, making it ideal for use with the ESP8266 (NodeMCU).

2️⃣ Features
✅ Temperature Range: -55°C to +125°C
✅ Accuracy: ±0.5°C (from -10°C to +85°C)
✅ Resolution: 9-bit to 12-bit (default: 12-bit, 0.0625°C per step)
✅ Single-Wire Communication (needs only one data pin)
✅ Low Power Consumption

3️⃣ DS18B20 Pinout (TO-92 Package)
🖼️ Diagram:
sql
Copy
Edit
      DS18B20 (Front View, Flat Side Facing You)
      
       +------+
       |      |     
 VCC --| 1  2  3 |-- GND
       +------+
         |  |
       DATA (Middle Pin)

📌 Pin Description
Pin #	Name	Function
1	GND	Ground (Connect to ESP8266 GND)
2	DATA	1-Wire Data (Connect to GPIO with a 4.7kΩ pull-up resistor to VCC)
3	VCC	Power Supply (Connect to 3.3V or 5V)

4️⃣ Wiring DS18B20 to ESP8266 (NodeMCU)
DS18B20 Pin	ESP8266 Pin
VCC (Pin 3)	3.3V or 5V
GND (Pin 1)	G (Ground)
DATA (Pin 2)	D4 (GPIO2) or D2 (GPIO4)
4.7kΩ Resistor	Between VCC and DATA