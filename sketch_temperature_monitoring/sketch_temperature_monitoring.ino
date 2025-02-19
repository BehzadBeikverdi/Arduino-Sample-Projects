#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2  // GPIO2 (D4)

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
    Serial.begin(9600);
    sensors.begin();
}

void loop() {
    Serial.print("Searching for DS18B20 sensor...");
    
    sensors.requestTemperatures();
    float tempC = sensors.getTempCByIndex(0);

    if (tempC == -127.00) {
        Serial.println(" ERROR! No sensor detected.");
    } else {
        Serial.print(" Temperature: ");
        Serial.print(tempC);
        Serial.println(" °C");
        Serial.println("Delay: 5sec");
    }
    
    delay(5000);
}
