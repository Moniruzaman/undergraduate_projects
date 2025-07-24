# Environment Data Logger with Google Spreadsheet and LCD

This project demonstrates how to create a simple yet powerful environment data logger using an ESP32, DHT22 sensor, and a 16x2 I2C LCD. The system reads temperature and humidity from the DHT22 sensor, displays the values on the LCD, and logs the data to a Google Spreadsheet using HTTP POST requests over Wi-Fi.

## Features
- ESP32-based IoT logger
- DHT22 sensor for temperature and humidity
- 16x2 LCD display with I2C interface
- Data logging to Google Spreadsheet via Apps Script Web App
- Wi-Fi connectivity for remote logging

## Hardware Requirements
- ESP32 Dev Module
- DHT22 Temperature and Humidity Sensor
- 16x2 I2C LCD Display (address 0x27)
- Breadboard and jumper wires

## Wiring Guide
| Component | ESP32 GPIO |
|-----------|------------|
| DHT22 Data | GPIO 14   |
| DHT22 VCC  | 3.3V      |
| DHT22 GND  | GND       |
| LCD SDA    | GPIO 21   |
| LCD SCL    | GPIO 22   |
| LCD VCC    | 3.3V or 5V|
| LCD GND    | GND       |

## Software Requirements
- Arduino IDE with ESP32 board support
- Libraries:
  - Adafruit DHT sensor library
  - ArduinoJson
  - LiquidCrystal_I2C

## Google Apps Script Setup
1. Create a new Google Spreadsheet.
2. Go to Extensions > Apps Script.
3. Paste the provided `Code.gs` script.
4. Deploy as Web App:
   - Execute as: Me
   - Access: Anyone
5. Copy the Web App URL and paste it into the Arduino code.

## Simulation
You can simulate this project on Wokwi:  
https://wokwi.com/projects/437364949523382273

> Note: Wokwi cannot perform actual HTTP requests. Use a real ESP32 for live Google Sheet logging.

## Folder Structure
```
Environment_Data_Logger_GSheet_LCD/
├── Arduino_Code/
│   └── ESP32_DHT22_LCD_Logger.ino
├── Google_Script/
│   └── Code.gs
├── project.json
├── README.md
```

## License
This project is open-source and free to use for educational and prototyping purposes.
