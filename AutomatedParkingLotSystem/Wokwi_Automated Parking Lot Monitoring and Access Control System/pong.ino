#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pins
const int trigPins[4] = {3, 4, 6, 8};
const int echoPins[4] = {2, 5, 7, 9};
const int pirPin = 11;
const int servoPin = 10;
const int distanceThreshold = 15; // cm

Servo gateServo;
LiquidCrystal_I2C lcd(0x27, 20, 4); // 20x4 LCD

int distance[4], prevDistance[4];
bool motionDetected = false, prevMotion = false;
int availableSlots = 0, prevAvailableSlots = -1;

unsigned long lastUpdateTime = 0;
const unsigned long updateInterval = 1000;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Smart Parking System");
  delay(2000);
  lcd.clear();

  for (int i = 0; i < 4; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
    prevDistance[i] = -1; // force update on first run
  }

  pinMode(pirPin, INPUT);
  gateServo.attach(servoPin);
  gateServo.write(90);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastUpdateTime >= updateInterval) {
    lastUpdateTime = currentMillis;

    availableSlots = 0;
    bool updateNeeded = false;

    for (int i = 0; i < 4; i++) {
      distance[i] = readDistance(trigPins[i], echoPins[i]);
      if (distance[i] > distanceThreshold) availableSlots++;

      // Check if status has changed
      if ((distance[i] > distanceThreshold) != (prevDistance[i] > distanceThreshold)) {
        updateNeeded = true;
      }
    }

    motionDetected = digitalRead(pirPin);
    if (motionDetected != prevMotion) updateNeeded = true;
    if (availableSlots != prevAvailableSlots) updateNeeded = true;

    if (updateNeeded) {
      lcd.clear();

      // Row 0: Slot 1 & Slot 2
      lcd.setCursor(0, 0);
      lcd.print("  S1:");
      lcd.print(distance[0] > distanceThreshold ? "A" : "O");
      lcd.print("      S2:");
      lcd.print(distance[1] > distanceThreshold ? "A" : "O");

      // Row 1: Slot 3 & Slot 4
      lcd.setCursor(0, 1);
      lcd.print("  S3:");
      lcd.print(distance[2] > distanceThreshold ? "A" : "O");
      lcd.print("      S4:");
      lcd.print(distance[3] > distanceThreshold ? "A" : "O");

      // Row 2: Summary
      lcd.setCursor(0, 2);
      lcd.print("Available: ");
      lcd.print(availableSlots);
      lcd.print(" / 4      ");

      // Row 3: Gate and motion
      lcd.setCursor(0, 3);
      if (motionDetected && availableSlots > 0) {
        lcd.print("Car@Gate- Gate Open ");
        gateServo.write(0);
      } else if (motionDetected && availableSlots == 0) {
        lcd.print("No Slot- Gate Hold ");
        gateServo.write(90);
      } else {
        lcd.print("Idle   - Gate Close");
        gateServo.write(90);
      }

      // Store previous values
      for (int i = 0; i < 4; i++) prevDistance[i] = distance[i];
      prevAvailableSlots = availableSlots;
      prevMotion = motionDetected;
    }
  }
}

// Measure distance in cm
int readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000);
  return duration * 0.034 / 2;
}
