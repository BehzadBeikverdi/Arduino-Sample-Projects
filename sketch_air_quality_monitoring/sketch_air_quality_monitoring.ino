#include <Arduino.h>

// Define MQ-135 sensor pin
#define MQ135_PIN A0  // Analog pin for MQ-135
#define RL_VALUE 10.0 // Load resistance in kilo-ohms
#define R0 9.83      // Calibrated sensor resistance in clean air (in kΩ, adjust if needed)
#define SAMPLE_COUNT 10  // Number of samples for averaging

// Function to get a filtered sensor reading (Moving Average Filter)
float getFilteredSensorValue() {
    float sum = 0;
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        sum += analogRead(MQ135_PIN);
        delay(50); // Small delay between readings
    }
    return sum / SAMPLE_COUNT; // Return averaged value
}

// Function to calculate CO2 PPM
float calculateCO2PPM(float sensorResistance) {
    float ratio = sensorResistance / R0;  // Sensor resistance ratio
    return 116.6020682 * pow(ratio, -2.769034857); // Approximate CO2 ppm calculation
}

// Function to classify air quality based on ppm
String classifyAirQuality(float ppm) {
    if (ppm < 400) return "Fresh Air";        // CO2 < 400 ppm (fresh air)
    else if (ppm < 1000) return "Good Air";   // CO2 < 1000 ppm (good air)
    else if (ppm < 2000) return "Moderate Air"; // CO2 < 2000 ppm (moderate air)
    else if (ppm < 5000) return "Unhealthy";  // CO2 < 5000 ppm (unhealthy)
    return "Hazardous";                       // CO2 > 5000 ppm (hazardous)
}

void setup() {
    Serial.begin(9600); // Higher baud rate for better serial performance
    pinMode(MQ135_PIN, INPUT);
}

void loop() {
    // Read and filter sensor value
    float sensorValue = getFilteredSensorValue();
    
    // Convert analog value to voltage (ESP8266 uses 3.3V reference)
    float voltage = sensorValue * (3.3 / 1023.0); 
    
    // Convert analog value to resistance (RS) using the voltage divider formula
    float sensorResistance = ((1023.0 * RL_VALUE) / sensorValue) - RL_VALUE;
    
    // Calculate CO2 concentration in ppm
    float ppm = calculateCO2PPM(sensorResistance);
    
    // Determine Air Quality based on CO2 ppm
    String airQuality = classifyAirQuality(ppm);

    // Print all sensor values
    Serial.println("---- MQ-135 Sensor Data ----");
    Serial.print("Raw Sensor Value: "); Serial.println(sensorValue);
    Serial.print("Voltage: "); Serial.print(voltage); Serial.println(" V");
    Serial.print("Sensor Resistance: "); Serial.print(sensorResistance); Serial.println(" kΩ");
    Serial.print("Estimated CO2 Level: "); Serial.print(ppm); Serial.println(" ppm");
    Serial.print("Air Quality: "); Serial.println(airQuality);
    Serial.println("----------------------------");
    
    delay(2000); // Wait 2 seconds before next reading
}
