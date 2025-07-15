# 🤖 Mobile Control Bot

This is my **first embedded systems project**, where I built a Bluetooth-controlled mobile robot using an Arduino Uno. The bot can move forward, backward, turn left or right, and stop, all through smartphone commands via the HC-05 Bluetooth module.

## 📦 Components Used

| Component              | Description                                  |
|------------------------|----------------------------------------------|
| Arduino Uno            | Main microcontroller board                   |
| HC-05 Bluetooth Module | Wireless communication with mobile phone     |
| L293D Motor Driver     | Dual H-Bridge motor driver for DC motors     |
| DC Geared Motors (x2)  | Provides mobility for the bot                |
| AA Battery Pack        | Powers the motor driver and motors (6V)      |
| 9V Battery             | Powers the Arduino Uno                       |
| Custom Chassis         | Designed in a compact, mobile platform       |
| Wheels (x2)            | Mounted with DC motors                       |

## 📱 Control System

- **Bluetooth App**: Arduino Bluetooth Controller (Play Store)
- **Command Mapping**:
  | Button | Command | Action   |
  |--------|---------|----------|
  | 🔼     | `F`     | Forward  |
  | 🔽     | `B`     | Backward |
  | ◀️     | `L`     | Left     |
  | ▶️     | `R`     | Right    |
  | ⏹️     | `S`     | Stop     |

## 💡 How It Works

1. Smartphone sends commands via Bluetooth (HC-05).
2. Arduino reads these commands via serial communication.
3. Based on the input, Arduino controls the motor driver to drive the motors in the appropriate direction.

## 🧠 Arduino Code

The core logic is written in Arduino C++. You can find the full code in [`Mobile_Control_Bot.ino`](./Mobile_Control_Bot.ino).

## 🔋 Power Supply

- **Arduino Uno**: Powered by a 9V battery.
- **Motors & Driver**: Powered by 4x AA batteries (6V).

## 📷 Images (Optional)

_You can add build images or video links here for demonstration._

## 🛠️ Future Improvements

- Add obstacle detection using ultrasonic sensor.
- Add speed control using PWM.
- Upgrade control interface with custom Android app or voice control.

## 📝 License

This project is open-source under the MIT License. Feel free to modify and use it for your own learning!

## 🙋‍♂️ Author

**Md Moniruzaman**  
Embedded Systems & IoT Developer  
GitHub: [@Moniruzaman](https://github.com/Moniruzaman)
