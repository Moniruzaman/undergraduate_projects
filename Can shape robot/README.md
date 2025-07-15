# Can-Shaped Autonomous Obstacle Avoidance Robot 🤖

This project is a compact autonomous robot designed to avoid obstacles using an ultrasonic sensor,
while also supporting manual control via Bluetooth using the Arduino Bluetooth Controller app.

## 📦 Project Structure

- `Arduino/Can_Shaped_Robot.ino` — Arduino sketch with both autonomous and Bluetooth control logic
- `Fritzing/` — Fritzing diagram for physical wiring
- `README.md` — Project documentation for GitHub

## 🧰 Hardware Used

- Arduino Nano
- HC-SR04 Ultrasonic Sensor
- L293D Motor Driver IC
- 2 × DC Motors
- HC-05 Bluetooth Module
- 7.4V Li-Po Battery

## 📲 Manual Control

Use the **Arduino Bluetooth Controller** app (from Google Play Store) to send character commands:
- `F` → Forward
- `B` → Backward
- `L` → Turn Left
- `R` → Turn Right
- `S` → Stop

If no command is received, the robot enters autonomous mode and avoids obstacles using HC-SR04.

## 🔌 Fritzing Diagram

You can find the wiring layout in the `Fritzing/` folder.

## 📜 License

MIT License or your preferred open-source license.
