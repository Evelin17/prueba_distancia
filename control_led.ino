#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "TU_WIFI";
const char* password = "TU_PASSWORD";

const char* firebaseHost = "https://control-led-default-rtdb.firebaseio.com/estado.json";

const int ledPin = 2; // LED integrado o pin de relé

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado a WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(firebaseHost);
    int httpCode = http.GET();

    if (httpCode == 200) {
      String payload = http.getString();
      payload.trim();
      if (payload == "1") {
        digitalWrite(ledPin, HIGH);
      } else {
        digitalWrite(ledPin, LOW);
      }
    } else {
      Serial.print("Error HTTP: ");
      Serial.println(httpCode);
    }

    http.end();
  }

  delay(2000); // consulta cada 2 segundos
}
