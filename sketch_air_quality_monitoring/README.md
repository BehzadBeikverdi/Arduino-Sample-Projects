📊 MQ-135 Air Quality Sensor with ESP8266
1️⃣ Introduction
The MQ-135 is a gas sensor capable of detecting various gases like ammonia, carbon dioxide (CO2), alcohol, and smoke. It is particularly useful for monitoring indoor air quality. When combined with an ESP8266 (NodeMCU), it can send real-time air quality data to a cloud platform or display it on a local screen.

2️⃣ Features
✅ Detects gases such as CO2, NH3, alcohol, and smoke
✅ Measures CO2 concentration (PPM)
✅ Output: Analog signal (connect to ESP8266 analog input pin)
✅ Can be calibrated for accurate readings
✅ Suitable for air quality monitoring systems

3️⃣ MQ-135 Pinout
🖼️ Diagram:

pgsql
Copy
Edit
   +-----------------+
   |      MQ-135     |
   |                 |
   | 1 | 2 | 3 | 4   |
   +-----------------+
   | VCC | GND | AO | DO
   +-----------------+
📌 Pin Description:

Pin #	Name	Function
1	VCC	Power Supply (Connect to 3.3V or 5V)
2	GND	Ground (Connect to ESP8266 GND)
3	AO	Analog Output (Connect to ESP8266 Analog Pin)
4	DO	Digital Output (Optional, use for threshold-based detection)
4️⃣ Wiring MQ-135 to ESP8266 (NodeMCU)
MQ-135 Pin	ESP8266 Pin
VCC	3.3V or 5V
GND	GND
AO	A0 (Analog Pin)
DO	Not connected (optional, use if needed)
5️⃣ Code Explanation
The provided code reads the analog values from the MQ-135 sensor, calculates the CO2 concentration in parts per million (PPM), and classifies air quality into various categories:

Code Overview:
Analog reading: The sensor's analog output is read via the A0 pin.
Voltage calculation: The analog value is converted to a voltage value.
Resistance calculation: The resistance of the sensor is calculated using the voltage divider formula.
CO2 calculation: The CO2 concentration in PPM is estimated using a formula based on the sensor's resistance.
Air quality classification: Based on the calculated CO2 level, air quality is classified as "Fresh Air", "Good Air", "Moderate Air", or "Hazardous".
6️⃣ How to Use
Connect the MQ-135 to your ESP8266 following the wiring instructions above.
Upload the Code: Use Arduino IDE to upload the code to the ESP8266.
Monitor Data: Open the Serial Monitor to view the raw sensor data, calculated CO2 levels, and air quality classification.
7️⃣ Expected Results
Once the sensor is connected and the code is uploaded, you will start seeing data like the following in the Serial Monitor:

yaml
Copy
Edit
---- MQ-135 Sensor Data ----
Raw Sensor Value: 714.20
Voltage: 2.30 V
Sensor Resistance: 4.32 kΩ
Estimated CO2 Level: 1133.47 ppm
Air Quality: Moderate Air
----------------------------