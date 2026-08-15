# Hardware Components List

## Project Information

**Project Title:** Aquaponics Ecosystem Monitoring System

**Description:**  
The Aquaponics Ecosystem Monitoring System is an Arduino-based monitoring solution designed to observe and maintain optimal environmental conditions for both fish and plants within an aquaponics setup. The system collects real-time data from multiple sensors and displays information through an LCD screen while automatically controlling selected devices through relays.

---

# Hardware Components

| No. | Component | Quantity | Purpose |
|------|------------|----------|----------|
| 1 | Arduino UNO R3 | 1 | Main microcontroller that processes sensor data and controls outputs |
| 2 | LCD I2C 16x2 Display | 1 | Displays monitoring data and system status |
| 3 | DHT11 Temperature Sensor | 1 | Measures ambient air temperature |
| 4 | DS18B20 Waterproof Temperature Sensor | 1 | Measures water temperature |
| 5 | pH Sensor Module | 1 | Measures water acidity and alkalinity |
| 6 | Turbidity Sensor | 1 | Monitors water clarity and quality |
| 7 | LDR (Light Dependent Resistor) | 1 | Detects surrounding light intensity |
| 8 | 2-Channel Relay Module | 1 | Controls external devices such as heater and grow light |
| 9 | Buzzer Module | 1 | Provides audible alerts for abnormal conditions |
| 10 | LED Indicator | 1 | Visual status indication |
| 11 | Breadboard | 1 | Temporary circuit assembly and testing |
| 12 | Jumper Wires | Several | Electrical connections between components |
| 13 | 4.7kΩ Resistor | 1 | Pull-up resistor for DS18B20 sensor |
| 14 | 10kΩ Resistor | 1 | Voltage divider for LDR sensor |
| 15 | USB Cable | 1 | Arduino programming and power supply |

---

# Sensor Functions

## DHT11 Sensor
- Measures ambient air temperature.
- Helps monitor environmental conditions around the aquaponics system.

## DS18B20 Sensor
- Measures water temperature.
- Ensures fish and plant environments remain within safe ranges.

## pH Sensor
- Determines the acidity or alkalinity of the water.
- Supports maintaining a healthy aquatic ecosystem.

## Turbidity Sensor
- Detects water clarity levels.
- Indicates whether water is clean, cloudy, or dirty.

## LDR Sensor
- Measures surrounding light intensity.
- Used to automate grow-light operation.

---

# Actuator Functions

## Relay Module
Controls:

- Water Heater
- Grow Light

### Heater Control
Automatically activates when water temperature falls below the defined threshold.

### Grow Light Control
Automatically activates when ambient light levels become insufficient.

## Buzzer
Provides warning alerts when:
- Water becomes too acidic or alkaline.
- Water quality becomes poor.
- Temperature exceeds safe limits.

---

# Power Requirements

| Component | Operating Voltage |
|------------|------------------|
| Arduino UNO | 5V |
| DHT11 | 3.3V - 5V |
| DS18B20 | 3.0V - 5.5V |
| pH Sensor Module | 5V |
| Turbidity Sensor | 5V |
| LCD I2C | 5V |
| Relay Module | 5V |
| Buzzer | 5V |
| LDR Circuit | 5V |

---

# System Summary

The Aquaponics Ecosystem Monitoring System integrates multiple sensors to continuously monitor water and environmental conditions. Data is processed by the Arduino UNO and displayed on an LCD screen. Automated control of the grow light and heater helps maintain optimal conditions, while the buzzer provides alerts whenever abnormal readings are detected.