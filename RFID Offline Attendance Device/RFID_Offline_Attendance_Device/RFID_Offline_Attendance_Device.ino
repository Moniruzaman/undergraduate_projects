#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <RTClib.h>
#include <EEPROM.h>

#define RST_PIN 9
#define SS_PIN 10
MFRC522 rfid(SS_PIN, RST_PIN);
RTC_DS1307 rtc;

const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;
const int buzzer = 6;

int eepromAddress = 0;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  Wire.begin();
  rtc.begin();

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  if (!rtc.isrunning()) {
    Serial.println("RTC not running, setting time...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uid += String(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    uid += String(rfid.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();

  // Map UID to name (example hardcoded)
  String name = "Unknown";
  if (uid == "A1B2C3D4") name = "ratan";
  else if (uid == "11223344") name = "masum";
  else if (uid == "55667788") name = "momin";

  DateTime now = rtc.now();
  String timestamp = String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
  String date = String(now.day()) + "/" + String(now.month()) + "/" + String(now.year());

  String log = "ID: " + uid + ", " + name + ", Time: " + timestamp + ", Date: " + date;
  Serial.println(log);

  storeInEEPROM(log);

  // Feedback
  digitalWrite(buzzer, HIGH);
  digitalWrite(greenLED, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  digitalWrite(greenLED, LOW);

  rfid.PICC_HaltA();
  delay(1000);
}

void storeInEEPROM(String data) {
  for (int i = 0; i < data.length(); i++) {
    EEPROM.write(eepromAddress++, data[i]);
    if (eepromAddress >= EEPROM.length()) {
      Serial.println("EEPROM full!");
      return;
    }
  }
  EEPROM.write(eepromAddress++, '\n');  // Newline separator
}

void serialEvent() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command == "SHOW") {
      Serial.println("Reading EEPROM data:");
      for (int i = 0; i < eepromAddress; i++) {
        char c = EEPROM.read(i);
        Serial.print(c);
      }
      Serial.println("\n--- End of Data ---");
    }
  }
}
