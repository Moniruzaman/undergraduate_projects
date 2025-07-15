// Motor driver pin connections
const int motor1Pin1 = 3;  // IN1
const int motor1Pin2 = 4;  // IN2
const int motor2Pin1 = 5;  // IN3
const int motor2Pin2 = 6;  // IN4

char command;

void setup() {
  // Set all the motor pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Check if data is available from HC-05
  if (Serial.available()) {
    command = Serial.read(); // Read the incoming character

    switch (command) {
      case 'F': // Forward
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        break;

      case 'B': // Backward
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        break;

      case 'L': // Left
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        break;

      case 'R': // Right
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        break;

      case 'S': // Stop
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        break;
    }
  }
}
