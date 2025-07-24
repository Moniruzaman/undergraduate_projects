# RFID-Based Online Attendance System Using Wemos D1 Mini and Google Sheets

## 📘 Project Summary
This project is a cloud-connected version of a traditional RFID attendance system. Instead of storing data locally, it uses a Wemos D1 Mini (ESP8266-based microcontroller) to read RFID tags and send attendance logs directly to a Google Spreadsheet via Wi-Fi. It ensures real-time, centralized record-keeping of attendance data, suitable for classrooms, offices, or workshops.

## 🔧 Key Features
- RFID-based user identification
- ESP8266 (Wemos D1 Mini)-based processing and Wi-Fi communication
- Real-time data entry into Google Spreadsheet
- Timestamped logging for accurate record-keeping
- LCD display for user feedback (optional)
- Can be expanded with admin control or notification features

## 🧰 Components Used

| Component               | Description                                  |
|-------------------------|----------------------------------------------|
| Wemos D1 Mini           | ESP8266-based Wi-Fi enabled microcontroller  |
| RFID Reader (RC522)     | For reading RFID tags                        |
| RFID Tags/Cards         | Unique ID for each user                      |
| Google Script (Apps Script) | To handle HTTP POST requests into Sheets   |
| 16x2 LCD (optional)     | For displaying user feedback                 |
| I2C Module (for LCD)    | For easier interfacing                       |
| Jumper Wires, Breadboard| General connectivity                        |

## 📡 Workflow Overview
1. **Scan RFID card** using RC522  
2. **Wemos D1 Mini extracts UID** and generates timestamp  
3. **Wemos D1 Mini sends HTTP POST** to Google Apps Script Web App URL  
4. **Google Apps Script** logs data into Google Spreadsheet
