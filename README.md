# Smart-Touch-Vibration-Sensor-Projects-using-Arduino-Uno
# 🚀 Smart Touch & Vibration Sensor Projects using Arduino Uno

A collection of four Arduino Uno projects that demonstrate the use of **touch sensors**, **vibration sensors**, **OLED displays**, **LEDs**, and **buzzers** to build interactive automation and security systems. These projects focus on user interaction, real-time monitoring, alarm systems, and embedded system programming using Arduino.

---

# 📖 Project Overview

This repository contains four practical embedded systems projects developed using the Arduino Uno platform. Each project explores different applications of touch and vibration sensing, ranging from simple LED control to advanced security systems with alarm mechanisms.

---

# 🛠️ Components Used

* Arduino Uno
* TTP223 Touch Sensor
* SW-420 Vibration Sensor
* 0.96" I2C OLED Display (SSD1306)
* LEDs
* Active Buzzer
* Jumper Wires
* Breadboard
* USB Cable

---

# 📂 Projects Included

## 💡 Project 1 – Touch Toggle Lamp

### Objective

Develop a touch-controlled lamp that toggles an LED ON and OFF using a TTP223 touch sensor while providing visual and audio feedback.

### Features

* Toggle LED state with a single touch.
* OLED displays the current LED status.
* Buzzer beeps whenever a touch is detected.
* Displays the total number of touches made.
* Simple and responsive user interface.

---

## 🎛️ Project 2 – Multi-Level Touch Controller

### Objective

Control multiple LEDs independently using two touch sensors.

### Features

* Two touch sensors control two separate LEDs.
* OLED displays the status of both LEDs.
* Different buzzer tones indicate which touch sensor was activated.
* Supports independent operation of each output device.

---

## 🚨 Project 3 – Knock Alarm System

### Objective

Detect vibrations, count knocks, and trigger an alarm when repeated knocks are detected.

### Features

* Detects knocks using a vibration sensor.
* Displays knock count on the OLED.
* Activates a continuous buzzer alarm if five knocks occur within ten seconds.
* Alarm can be reset using a touch sensor.
* Includes a countdown timer before resetting the alarm.

---

## 🔐 Project 4 – Secure Tamper Box

### Objective

Create a smart security system using both touch and vibration sensors to detect tampering.

### Features

* Touch sensor arms and disarms the system.
* When armed, vibration immediately triggers:

  * Continuous buzzer alarm
  * OLED warning message:

    ```
    ⚠ TAMPER DETECTED!
    ```
* When disarmed, vibrations only increase a movement counter.
* Optional secret touch sensor for secure alarm reset.

---

# 🔌 Circuit Connections

## Common Components

| Component        | Arduino Pin                         |
| ---------------- | ----------------------------------- |
| OLED SDA         | A4                                  |
| OLED SCL         | A5                                  |
| OLED VCC         | 5V                                  |
| OLED GND         | GND                                 |
| Active Buzzer    | Digital Pin                         |
| LED              | Digital Pin (through 220Ω resistor) |
| Touch Sensor     | Digital Pin                         |
| Vibration Sensor | Digital Pin                         |

> **Note:** Pin numbers may vary depending on the individual project implementation.

---

# 💻 Code Explanation

Each project follows a modular programming approach using the Arduino IDE.

### Main Functionalities

* Reading digital input from touch and vibration sensors.
* Controlling LEDs and buzzers based on sensor events.
* Displaying real-time information on the OLED.
* Implementing timing operations using `millis()` instead of `delay()`.
* Managing system states such as Armed, Disarmed, Alarm Active, and Reset.
* Counting user interactions and vibration events.

---

# 📸 Output Images

Touch-and-Vibration-Sensor-Projects/
│
├── Project-1_Touch-Toggle-Lamp:
LED OFF:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/a47a4735-c3e6-4f7e-a132-76def961d619" />
LED ON:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/f654f221-ef6c-4fbf-ab75-f5b65727bd04" />

├── Project-2_Multi-Level-Touch-Controller:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/0fe4603e-28ba-4c27-86a3-d7f56a5aa431" />
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/b5588e00-4352-400c-90d5-36c280852e9b" />
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/30f661fe-caa2-43af-89df-ade32eadd759" />

├── Project-3_Knock-Alarm-System:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/34cc1b69-d485-49fa-9dc1-f23e03d732c0" />

├── Project-4_Secure-Tamper-Box:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/1895481d-32d0-47c5-a432-c535efda72b2" />
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/286a4de2-deb4-4bb7-87af-64bfc466865a" />


# 🎯 Learning Outcomes

Through these projects, the following concepts were explored:

* Interfacing touch and vibration sensors with Arduino Uno.
* Controlling LEDs and buzzers using digital I/O.
* Displaying real-time information on an OLED display.
* Implementing event-driven programming.
* Using `millis()` for non-blocking timing.
* Designing embedded security and monitoring systems.
* Managing multiple sensors and outputs simultaneously.
* Developing interactive user interfaces for embedded applications.


# 🏷️ Technologies Used

* Arduino Uno
* Embedded C / Arduino IDE
* SSD1306 OLED Library
* Adafruit GFX Library
* TTP223 Touch Sensor
* SW-420 Vibration Sensor

---

# ⭐ If you found these projects helpful, consider giving this repository a Star!
