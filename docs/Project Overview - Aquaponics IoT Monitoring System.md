# Project Overview

## Project Title

**Aquaponics IoT Monitoring System Using Arduino UNO and ESP8266**

---

## Introduction

Aquaponics is a sustainable farming method that combines aquaculture (raising fish) and hydroponics (growing plants without soil) in a single ecosystem. Maintaining proper environmental conditions is essential to ensure the health of both fish and plants. Manual monitoring can be time-consuming and may lead to inaccurate observations or delayed responses to environmental changes.

The Aquaponics IoT Monitoring System was developed to provide real-time monitoring of critical environmental parameters within an aquaponics ecosystem. The system utilizes sensors connected to an Arduino UNO to collect data and an ESP8266 NodeMCU to transmit and display information through a wireless web dashboard accessible via smartphones, tablets, and computers.

---

## Project Objectives

### General Objective

To develop an Internet of Things (IoT)-based monitoring system capable of measuring and displaying key environmental parameters in an aquaponics ecosystem in real time.

### Specific Objectives

- Monitor air temperature and humidity using a DHT11 sensor.
- Monitor water temperature using a DS18B20 waterproof temperature sensor.
- Monitor water quality using a turbidity sensor.
- Monitor water pH levels using a pH sensor.
- Monitor ambient light intensity using an LDR sensor.
- Display sensor readings on an LCD screen for local monitoring.
- Transmit sensor data wirelessly through an ESP8266 NodeMCU.
- Provide a mobile-friendly web dashboard for remote monitoring.
- Classify sensor readings into meaningful status categories such as Normal, Hot, Cold, Acidic, Alkaline, Bright, and Dark.

---

## System Description

The system consists of two primary microcontrollers:

### Arduino UNO

The Arduino UNO serves as the main controller responsible for:

- Reading sensor data.
- Processing sensor values.
- Determining environmental status conditions.
- Displaying information on the LCD display.
- Sending formatted data to the ESP8266 through serial communication.

### ESP8266 NodeMCU

The ESP8266 serves as the IoT communication module responsible for:

- Receiving data from the Arduino UNO.
- Creating a wireless access point.
- Hosting a local web server.
- Displaying sensor information through a responsive web dashboard.

---

## Hardware Components

| Component | Purpose |
|------------|----------|
| Arduino UNO | Main processing unit |
| ESP8266 NodeMCU | Wireless communication and dashboard hosting |
| DHT11 Sensor | Air temperature and humidity monitoring |
| DS18B20 Sensor | Water temperature monitoring |
| Turbidity Sensor | Water clarity monitoring |
| pH Sensor | Water acidity and alkalinity monitoring |
| LDR Sensor | Light intensity detection |
| LCD I2C Display | Local display of sensor data |
| Relay Module | Automated lighting control |
| LED Indicator | Visual status indication |
| Breadboard and Jumper Wires | Circuit connections |

---

## Monitored Parameters

### Air Temperature

The DHT11 sensor measures ambient air temperature around the aquaponics system.

Status Classification:

- Cold: Below 18°C
- Normal: 18°C to 30°C
- Hot: Above 30°C

---

### Humidity

The DHT11 sensor also measures relative humidity.

Status Classification:

- Low: Below 40%
- Normal: 40% to 70%
- High: Above 70%

---

### Water Temperature

The DS18B20 waterproof sensor measures water temperature within the fish tank.

Status Classification:

- Cold: Below 21°C
- Normal: 21°C to 30°C
- Above Normal: 31°C to 35°C
- Hot: Above 35°C

---

### Water Quality

The turbidity sensor measures the clarity of the water.

Status Classification:

- Clean
- Cloudy
- Dirty

---

### pH Level

The pH sensor measures the acidity or alkalinity of the water.

Status Classification:

- Acidic
- Neutral
- Alkaline

---

### Light Intensity

The LDR sensor detects environmental light levels.

Status Classification:

- Bright
- Dim
- Dark

The system automatically controls indicators based on light conditions.

---

## System Architecture

```text
DHT11
DS18B20
Turbidity Sensor
pH Sensor
LDR Sensor
      │
      ▼
Arduino UNO
      │
      │ Serial Communication
      ▼
ESP8266 NodeMCU
      │
      ▼
WiFi Access Point
      │
      ▼
Web Dashboard
```

---

## Features

### Real-Time Monitoring

The system continuously collects and updates environmental data.

### Local Display

Sensor readings are displayed directly on a 16x2 LCD screen.

### Wireless Dashboard

Users can access a dashboard through the ESP8266 access point using a mobile device or computer.

### Status Classification

Sensor readings are automatically interpreted and displayed with corresponding environmental conditions.

### Mobile-Friendly Interface

The web dashboard is responsive and accessible on various screen sizes.

### Automated Light Monitoring

The system identifies light conditions and controls indicators accordingly.

---

## Expected Benefits

### For Aquaponics Farmers

- Easier monitoring of environmental conditions.
- Reduced manual checking of water and air parameters.
- Improved fish and plant health management.

### For Students and Researchers

- Practical implementation of IoT technologies.
- Application of embedded systems and sensor integration.
- Experience in environmental monitoring and data acquisition.

### For Educational Institutions

- Demonstrates real-world applications of Arduino and IoT technologies.
- Supports learning in agriculture, engineering, and information technology.

---

## Technologies Used

### Hardware

- Arduino UNO
- ESP8266 NodeMCU
- DHT11 Sensor
- DS18B20 Sensor
- Turbidity Sensor
- pH Sensor
- LDR Sensor
- LCD I2C Display
- Relay Module

### Software

- Arduino IDE
- ESP8266 Libraries
- HTML
- CSS
- Embedded C++
- Serial Communication Protocol

---

## Future Enhancements

- Cloud-based data storage.
- Historical data logging.
- Mobile application integration.
- SMS and email notifications.
- Automatic water pump control.
- Automatic feeder integration.
- Advanced analytics and reporting dashboard.
- Integration with cloud IoT platforms.

---

## Conclusion

The Aquaponics IoT Monitoring System provides a practical and efficient solution for monitoring environmental conditions within an aquaponics ecosystem. By integrating multiple sensors with Arduino UNO and ESP8266 technologies, the system enables real-time observation of critical parameters through both local and wireless interfaces. The project demonstrates the application of Internet of Things technologies in smart agriculture while promoting sustainable and data-driven farming practices.