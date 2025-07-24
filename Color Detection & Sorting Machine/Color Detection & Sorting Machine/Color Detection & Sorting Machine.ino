#include <Servo.h>

// Pin Definitions
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
#define OE 7
#define IR_SENSOR A0

Servo sorterServo;

void setup() {
  // Set color sensor pins
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Set IR sensor pin
  pinMode(IR_SENSOR, INPUT);

  // Configure scaling (recommended: 20%)
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Enable TCS3200 output
  digitalWrite(OE, LOW);

  sorterServo.attach(9);  // Connect servo to D9
  sorterServo.write(90);  // Initial position

  Serial.begin(9600);
}

// Function to read color intensity
int readColor(char color) {
  switch (color) {
    case 'R':
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      break;
    case 'G':
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      break;
    case 'B':
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      break;
  }
  delay(100); // Short delay for stability
  return pulseIn(sensorOut, LOW); // Lower value = higher intensity
}

void loop() {
  int irValue = analogRead(IR_SENSOR);

  // Ball detected
  if (irValue < 500) {
    delay(300);  // Debounce

    int red = readColor('R');
    int green = readColor('G');
    int blue = readColor('B');

    Serial.print("R: "); Serial.print(red);
    Serial.print(" G: "); Serial.print(green);
    Serial.print(" B: "); Serial.println(blue);

    // Determine color
    if (red < green && red < blue) {
      Serial.println("Color: RED");
      sorterServo.write(30); // RED bin
    } else if (green < red && green < blue) {
      Serial.println("Color: GREEN");
      sorterServo.write(90); // GREEN bin
    } else {
      Serial.println("Color: BLUE");
      sorterServo.write(150); // BLUE bin
    }

    delay(1000); // Wait for sorting
    sorterServo.write(90);  // Reset to neutral
    delay(500);
  }
}
