// void setup() {
//     pinMode(5, OUTPUT); // GPIO5 (D1)
// }

// void loop() {
//     digitalWrite(5, HIGH); // LED ON
//     delay(1000);
//     digitalWrite(5, LOW);  // LED OFF
//     delay(1000);
// }

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Beik";     
const char* password = "albei@1886934070";  

ESP8266WebServer server(80); // Create a web server on port 80

const int LED_PIN = 5; // GPIO5 (D1) for external LED

void handle_On() {
    Serial.println("Turning LED ON");
    digitalWrite(LED_PIN, HIGH);
    server.send(200, "text/plain", "LED ON");
}

void handle_Off() {
    Serial.println("Turning LED OFF");
    digitalWrite(LED_PIN, LOW);
    server.send(200, "text/plain", "LED OFF");
}

void handle_Root() {
    server.send(200, "text/plain", "ESP8266 Web Server Running!");
}

void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); // Ensure LED is OFF initially

    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("\nConnected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    server.on("/", handle_Root);
    server.on("/led/on", HTTP_GET, handle_On);
    server.on("/led/off", HTTP_GET, handle_Off);
    server.begin();
    Serial.println("Server started...");
}

void loop() {
    server.handleClient();
}
