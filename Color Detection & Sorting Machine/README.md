
# 🎨 Color Detection & Sorting Machine

A low-cost, Arduino-based automation system that detects the color of incoming balls and sorts them into designated bins using a servo mechanism. This project demonstrates basic embedded systems, sensor interfacing, and simple automation logic.

---

## 📌 Objective

To build an automated system that can identify ball colors using a TCS3200 color sensor and sort them into bins via a servo motor controlled by an Arduino Uno.

---

## 🧠 Project Description

This machine detects Red, Green, or Blue colored balls using a **TCS3200 color sensor**. Upon detecting a ball using an **IR sensor**, it processes the RGB values and rotates a **servo motor** to the appropriate bin based on the dominant color. The design is ideal for academic demonstration, small-scale automation tasks, and robotics training.

---

## 🧰 Components Used

| Component               | Quantity | Description                                |
|------------------------|----------|--------------------------------------------|
| Arduino Uno            | 1        | Microcontroller Board                       |
| TCS3200 Color Sensor   | 1        | Detects RGB values                          |
| IR Sensor              | 1        | Detects incoming ball                       |
| Servo Motor            | 1        | Sorts balls by rotating to target bin       |
| Breadboard & Wires     | As needed | Circuit connections                        |
| Ball Feeder Mechanism  | Optional | For continuous sorting                      |

---

## 🔌 Pin Connections

### TCS3200 Color Sensor:
- S0 → D2  
- S1 → D3  
- S2 → D4  
- S3 → D5  
- OUT → D6  
- OE → D7  
- VCC → 5V  
- GND → GND  

### Others:
- Servo Motor → D9  
- IR Sensor → A0  

---

## ⚙️ Working Principle

1. **Ball Detection:** IR sensor detects a ball's presence.
2. **Color Sensing:** TCS3200 sensor reads RGB intensities.
3. **Color Decision:** Arduino determines dominant color.
4. **Sorting:** Servo motor rotates to the assigned bin angle.
5. **Reset:** Servo returns to the default position for the next cycle.

---

## 💻 Code Summary

- Uses `pulseIn()` to capture the frequency from TCS3200.
- Compares red, green, and blue pulse widths to determine color.
- Controls servo position via `Servo.h` to direct the ball.

---

## 📝 Conclusion

This project is a hands-on introduction to automation using Arduino. It combines sensors and actuators in a simple workflow that mimics industrial sorting systems. Ideal for students and hobbyists to understand embedded logic, color sensing, and mechanical control.

---
