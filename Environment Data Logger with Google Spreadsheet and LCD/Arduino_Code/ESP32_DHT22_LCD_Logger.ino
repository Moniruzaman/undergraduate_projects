
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <DHT.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 14
#define DHTTYPE DHT22
const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* scriptURL = "https://script.google.com/macros/s/AKfycbwFebgQwwVTX_6W3lL7grLzGpjSFEYMDX2KjY5nqyJVUesJoRxxXTxV6xoZIaqBhTOW/exec";

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
  lcd.clear();
  lcd.print("WiFi Connected!");
  delay(1000);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.clear();
  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    Serial.println("Failed to read from DHT sensor!");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(t, 1);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(h, 0);
    lcd.print("%");

    Serial.printf("Temperature: %.2f °C, Humidity: %.2f %%\n", t, h);

    if (WiFi.status() == WL_CONNECTED) {
      WiFiClientSecure client;
      client.setInsecure();

      HTTPClient http;
      http.begin(client, scriptURL);
      http.addHeader("Content-Type", "application/json");

      StaticJsonDocument<200> doc;
      doc["temperature"] = t;
      doc["humidity"] = h;

      String jsonStr;
      serializeJson(doc, jsonStr);

      int httpCode = http.POST(jsonStr);
      Serial.print("HTTP Response: ");
      Serial.println(httpCode);
      http.end();
    }
  }

  delay(10000);
}
