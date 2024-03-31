#include <ESP8266WiFi.h>

const char* ssid = "TFK";
const char* password = "00000000";

void setup() {
  Serial.begin(115200);
  delay(100);
  connectToWiFi();
  pinMode(D3, OUTPUT);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi disconnected, reconnecting...");
    connectToWiFi();
  }
  delay(1000);  // Check WiFi connection every second
}

void connectToWiFi() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 10) {
    delay(1000);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    digitalWrite(D3, HIGH);
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } 
  else {
    Serial.println("");
    Serial.println("Failed to connect to WiFi");
     digitalWrite(D3, LOW);
  }
}



