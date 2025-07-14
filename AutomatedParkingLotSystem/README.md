# Automated Parking Lot Monitoring and Access Control System 🚗

This project implements a smart parking management system using Arduino Nano, ultrasonic sensors for parking slots, a PIR sensor for detecting incoming vehicles at the gate, a 20x4 LCD for displaying real-time information, and a servo motor to automate gate control.

## 🧠 Features

- Monitors 4 parking slots using ultrasonic sensors (HC-SR04)
- Detects cars waiting at the gate using a PIR sensor
- Displays slot availability and gate status on a 20x4 LCD
- Opens/closes gate automatically based on availability and motion
- Non-blocking code structure using `millis()`
- Simulation available on Wokwi

## 📦 Components

| Component              | Quantity |
|------------------------|----------|
| Arduino Nano           | 1        |
| HC-SR04 Ultrasonic     | 4        |
| PIR Motion Sensor      | 1        |
| Servo Motor            | 1        |
| 20x4 I2C LCD           | 1        |
| 9V DC Adapter          | 1        |
| Jumper Wires + Breadboard | As required |

## 🗂️ Folder Structure

- `AutomatedParkingLotSystem.ino` – Final Arduino code
- `PinConnectionTable.xlsx` – Complete hardware connections
- `WokwiSimulation/` – Simulation files
- `CircuitDiagram.png` – Schematic/diagram of the project

## 🔁 Wokwi Simulation

▶ [Click to open in Wokwi](https://wokwi.com/projects/YOUR_LINK_HERE)

## 📷 LCD Display Layout

| Row | Content                          |
|------|----------------------------------|
| Row 0 | Slot 1 and Slot 2 status        |
| Row 1 | Slot 3 and Slot 4 status        |
| Row 2 | Available slots summary         |
| Row 3 | Gate + Motion detection status  |

## 👨‍💻 Author

Md Moniruzaman  
GitHub: [Moniruzaman](https://github.com/Moniruzaman)

---
