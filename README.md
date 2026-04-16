# 🌡️ Smart Environment Monitoring System using Arduino

## 📌 Project Overview

This project is a Smart Environment Monitoring System built using an Arduino Uno that continuously monitors environmental conditions such as temperature, humidity, gas levels, and real-time clock data. The system uses a DHT11 Temperature and Humidity Sensor to measure temperature and humidity, and an MQ-9 Gas Sensor to detect harmful gases. A DS3231 Real-Time Clock module provides accurate time data, while dual LCD displays show live readings. A buzzer alerts users when unsafe gas levels are detected.

---

## 🎯 Features

- 🌡️ Temperature Monitoring
- 💧 Humidity Monitoring
- 🔥 Gas Detection System
- ⏰ Real-Time Clock Display
- 🖥️ Dual LCD Display Output
- 🔊 Buzzer Alert System
- 🧱 Foam Sheet Enclosure Protection
- ⚡ Real-Time Environmental Monitoring

---

## 🧰 Components Used

| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| DHT11 Temperature & Humidity Sensor | 1 |
| MQ-9 Gas Sensor | 1 |
| DS3231 RTC Module | 1 |
| 16x2 LCD Display (I2C) | 2 |
| Piezo Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | Multiple |
| Foam Sheets (Enclosure) | As needed |

---

## 🔌 Pin Configuration

| Component | Arduino Pin |
|-----------|--------------|
| DHT11 DATA | D2 |
| MQ-9 Analog Output | A0 |
| Buzzer | D3 |
| RTC SDA | A4 |
| RTC SCL | A5 |
| LCD1 SDA | A4 |
| LCD1 SCL | A5 |
| LCD2 SDA | A4 |
| LCD2 SCL | A5 |

---

## 🖥️ LCD Display Output

### LCD1 Displays:

Temperature: 28°C  
Humidity: 65%

### LCD2 Displays:

Time: 10:45 AM  
Gas Level: Safe

---

## ⚙️ Working Principle

The system continuously reads temperature and humidity data from the DHT11 sensor and gas levels from the MQ-9 sensor. The DS3231 RTC module provides accurate real-time clock data. All readings are processed by the Arduino Uno and displayed on dual LCD screens. If the gas level exceeds a predefined safety limit, the buzzer activates to alert users. The system is enclosed using foam sheets to simulate a sealed environmental monitoring setup.

---

## 🧪 Applications

- 🏠 Smart Home Monitoring
- 🧪 Laboratory Monitoring
- 🏭 Industrial Safety Systems
- 📦 Storage Room Monitoring
- 🚨 Gas Leakage Detection
- 🌍 Environmental Monitoring

---

## 🧱 Foam Enclosure Purpose

Foam sheets are used to:

- Protect internal components
- Reduce environmental interference
- Simulate sealed environmental conditions
- Improve sensor accuracy
- Provide physical insulation

---

## 📷 Circuit Diagram
<img width="1376" height="768" alt="circuit_diagram" src="https://github.com/user-attachments/assets/e9b64819-a184-4517-aa36-5bb0ec9e1c66" />
