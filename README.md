# 🌱 Aquaponics Ecosystem Monitoring System

## Project Overview

The Aquaponics Ecosystem Monitoring System is an Arduino-based monitoring solution designed to maintain healthy environmental conditions for both fish and plants in an aquaponics setup. The system continuously collects data from multiple sensors, displays real-time information, and automates selected responses to improve water quality management and ecosystem stability.

This project addresses the challenge of manually monitoring critical aquaponics parameters such as water temperature, pH levels, turbidity, ambient temperature, and light intensity, helping users make informed decisions and reduce the risk of ecosystem imbalance.

---

## Features

### Real-Time Monitoring
- Water Temperature Monitoring (DS18B20)
- Air Temperature Monitoring (DHT11)
- pH Level Monitoring
- Water Turbidity Monitoring
- Light Intensity Monitoring

### Automated Responses
- Automatic Heater Control via Relay
- Automatic Grow Light Control via Relay
- Audible Alerts using Buzzer

### User Interface
- LCD I2C Display for live sensor readings
- Status indicators for environmental conditions
- Water quality classification (Clean, Cloudy, Dirty)
- pH classification (Acidic, Neutral, Alkaline)

---

## Tech Stack

| Technology | Purpose |
|------------|----------|
| Arduino UNO | Main microcontroller responsible for sensor integration and automation |
| C++ (Arduino IDE) | Firmware development and hardware control |
| DHT11 Sensor | Air temperature monitoring |
| DS18B20 Sensor | Water temperature monitoring |
| pH Sensor Module | Water acidity and alkalinity measurement |
| Turbidity Sensor | Water clarity assessment |
| LDR Sensor | Light intensity detection |
| LCD I2C | Real-time information display |
| Relay Module | Controls heater and grow light |
| Git & GitHub | Version control and project management |

---

## Architecture

```text
                    ┌───────────────────┐
                    │   DHT11 Sensor    │
                    └─────────┬─────────┘
                              │
                    ┌─────────▼─────────┐
                    │   Arduino UNO     │
                    └─────────▲─────────┘
                              │
 ┌───────────────┐            │            ┌───────────────┐
 │ DS18B20       │────────────┤────────────│ Turbidity     │
 │ Water Temp    │            │            │ Sensor        │
 └───────────────┘            │            └───────────────┘
                              │
 ┌───────────────┐            │            ┌───────────────┐
 │ pH Sensor     │────────────┤────────────│ LDR Sensor    │
 └───────────────┘            │            └───────────────┘
                              │
                    ┌─────────▼─────────┐
                    │ LCD I2C Display   │
                    └─────────┬─────────┘
                              │
            ┌─────────────────┴─────────────────┐
            │                                   │
   ┌────────▼────────┐               ┌──────────▼─────────┐
   │ Heater Relay    │               │ Grow Light Relay   │
   └─────────────────┘               └────────────────────┘
                              │
                    ┌─────────▼─────────┐
                    │      Buzzer       │
                    └───────────────────┘
```

---

## Project Structure

```text
Aquaponics-Ecosystem/
│
├── docs/
│   ├── Project_Overview.md
│   ├── User_Manual.md
│   ├── System_Architecture.md
│   └── Troubleshooting.md
│
├── firmware/
│   ├── Arduino_UNO/
│   │   └── Aquaponics_System.ino
│   ├── libraries/
│   └── configuration/
│
├── hardware/
│   ├── Component_List.md
│   ├── wiring/
│   ├── prototype/
│   └── datasheets/
│
├── videos/
│
├── images/
│
└── README.md
```

### Directory Responsibilities

| Folder | Description |
|----------|------------|
| docs | Project documentation and manuals |
| firmware | Arduino source code and configuration |
| hardware | Hardware specifications and wiring diagrams |
| videos | Demonstration videos |
| images | System diagrams and screenshots |

---

## Installation & Setup

### Prerequisites

- Arduino IDE 2.x or later
- USB Cable for Arduino UNO
- Required hardware components

### Required Libraries

Install the following libraries through Arduino IDE:

```cpp
LiquidCrystal_I2C
DHT Sensor Library
DallasTemperature
OneWire
Wire
```

### Hardware Setup

1. Connect all sensors according to the wiring diagram.
2. Connect the LCD I2C module.
3. Connect relay modules for heater and grow light.
4. Connect the buzzer module.
5. Upload the firmware to the Arduino UNO.

### Upload Firmware

```bash
Open Arduino IDE
Select Arduino UNO
Select COM Port
Upload Aquaponics_System.ino
```

---

## Usage

### System Startup

1. Power on the Arduino UNO.
2. Sensors initialize automatically.
3. LCD displays environmental readings.
4. System continuously monitors:

- Water Temperature
- Air Temperature
- pH Level
- Water Turbidity
- Light Intensity

### Automated Actions

| Condition | Action |
|------------|---------|
| Low Water Temperature | Heater activates |
| Low Light Intensity | Grow Light activates |
| Unsafe Sensor Values | Buzzer alarm activates |

### Monitoring

Users can view real-time information through:

- LCD Display
- Arduino Serial Monitor


---

## Screenshots / Demo

### Hardware Prototype

```text
hardware/prototype/Final_Prototype.jpg
```

### Wiring Diagram

```text
hardware/wiring/Wiring_Diagram.png
```

### System Demonstration

```text
videos/System_Demo.mp4
```

---

## API Documentation

This version of the project does not expose REST APIs.

Future versions may include:

- IoT Dashboard Integration
- ESP8266 WiFi Connectivity
- Cloud Database Storage
- Mobile Application Monitoring

---

## Engineering Decisions

### Why Arduino UNO?

Arduino UNO was selected due to its simplicity, reliability, educational value, and compatibility with multiple environmental sensors.

### Why DS18B20 for Water Temperature?

The DS18B20 provides waterproof operation and higher reliability in aquatic environments compared to standard temperature sensors.

### Why Relay-Based Automation?

Relay modules allow safe switching of external devices such as heaters and grow lights while maintaining electrical isolation from the Arduino.

### Why Local Monitoring First?

The project prioritizes reliable local monitoring before introducing cloud-based complexity. This approach simplifies deployment and troubleshooting while maintaining system stability.

---

## Testing

### Hardware Testing

- Sensor calibration verification
- Relay switching validation
- LCD functionality testing
- Buzzer alert testing

### Integration Testing

- Simulated temperature changes
- Simulated pH fluctuations
- Turbidity threshold testing
- Light intensity automation testing

### Performance Testing

- Continuous monitoring operation
- Long-duration sensor stability
- Automated response verification

---

## Limitations & Future Improvements

### Current Limitations

- No cloud connectivity
- No remote monitoring capability
- Limited historical data storage
- Single-node monitoring system
- Manual calibration required for some sensors

### Future Improvements

- ESP8266/ESP32 WiFi Integration
- Mobile Application Dashboard
- Cloud Database Storage
- SMS and Email Notifications
- Automatic Water Pump Control
- Fish Feeding Automation
- AI-Based Water Quality Prediction
- Real-Time Web Dashboard

---

**BS Information Technology Capstone Project**

Developed as an educational and research-based aquaponics monitoring solution focused on environmental sensing, automation, and data-driven decision-making.

---
