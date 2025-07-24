#include <ESP8266WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266HTTPClient.h>

#define RST_PIN D0
#define SS_PIN  D8

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* scriptURL = "YOUR_GOOGLE_SCRIPT_WEB_APP_URL";

void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Connect WiFi...");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  lcd.clear();
  lcd.print("WiFi Connected");
  delay(1000);
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) return;

  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uid += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    uid += String(mfrc522.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();

  Serial.println("UID: " + uid);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sending...");

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(scriptURL);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String postData = "uid=" + uid;
    int httpResponseCode = http.POST(postData);

    lcd.clear();
    if (httpResponseCode > 0) {
      lcd.setCursor(0, 0);
      lcd.print("Sent: ");
      lcd.setCursor(0, 1);
      lcd.print(uid);
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Failed!");
    }
    http.end();
  } else {
    lcd.clear();
    lcd.print("No WiFi");
  }

  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan Card...");
}
