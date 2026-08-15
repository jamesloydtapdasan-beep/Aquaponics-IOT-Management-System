#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>

// ================= SOFTWARESERIAL =================
// D2 = GPIO4 (RX from Arduino TX via voltage divider)
// D1 = GPIO5 (TX, not really used but needed)
SoftwareSerial mySerial(4, 5);

// ================= ACCESS POINT =================
const char* ssid = "Aquaponics_System";
const char* password = "aqua1234";

ESP8266WebServer server(80);

// ================= SENSOR DATA VARS =================
float airTemp = 0, humidity = 0, waterTemp = 0, phValue = 0;
String turbidity = "--", lightStatus = "--";

// ================= PARSE SERIAL FROM ARDUINO =================
void parseSerial(String data) {
  // Format: DATA,airTemp,humidity,waterTemp,ph,turbidity,light
  if (!data.startsWith("DATA,")) return;

  data.remove(0, 5); // remove "DATA,"

  int idx = 0;
  String values[6];

  for (int i = 0; i < data.length(); i++) {
    if (data[i] == ',') {
      idx++;
    } else {
      values[idx] += data[i];
    }
  }

  airTemp     = values[0].toFloat();
  humidity    = values[1].toFloat();
  waterTemp   = values[2].toFloat();
  phValue     = values[3].toFloat();
  turbidity   = values[4];
  lightStatus = values[5];
}

// ================= STATUS HELPERS =================
String waterTempStatus() {
  if (waterTemp < 21) return "COLD";
  if (waterTemp <= 30) return "NORMAL";
  if (waterTemp <= 35) return "ABOVE NORMAL";
  return "HOT";
}

String phStatus() {
  if (phValue < 3.5) return "ACIDIC";
  if (phValue <= 5.5) return "NEUTRAL";
  return "ALKALINE";
}

String airTempStatus() {
  if (airTemp < 18) return "COLD";
  if (airTemp <= 30) return "NORMAL";
  return "HOT";
}

String humStatus() {
  if (humidity < 40) return "LOW";
  if (humidity <= 70) return "NORMAL";
  return "HIGH";
}

String badgeColor(String status) {
  if (status == "NORMAL")                                    return "#2ecc71";
  if (status == "COLD")                                      return "#3498db";
  if (status == "HOT" || status == "DIRTY")                  return "#e74c3c";
  if (status == "HIGH" || status == "CLOUDY" 
   || status == "ABOVE NORMAL" || status == "ALKALINE")      return "#e67e22";
  if (status == "LOW" || status == "DIM")                    return "#f1c40f";
  if (status == "CLEAN" || status == "BRIGHT")               return "#2ecc71";
  if (status == "DARK")                                      return "#95a5a6";
  if (status == "ACIDIC")                                    return "#e74c3c";
  if (status == "NEUTRAL")                                   return "#2ecc71";
  return "#7f8c8d";
}

// ================= HTML PAGE =================
void handleRoot() {
  String wts  = waterTempStatus();
  String phs  = phStatus();
  String ats  = airTempStatus();
  String hums = humStatus();

  String html = R"rawhtml(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="refresh" content="3">
  <title>Aquaponics Monitor</title>
  <style>
    * { box-sizing: border-box; margin: 0; padding: 0; }
    body {
      font-family: 'Segoe UI', sans-serif;
      background: #0f1923;
      color: #eee;
      padding: 16px;
    }
    h1 {
      text-align: center;
      font-size: 1.3em;
      color: #00e5ff;
      margin-bottom: 4px;
    }
    .subtitle {
      text-align: center;
      font-size: 0.75em;
      color: #666;
      margin-bottom: 16px;
    }
    .grid {
      display: grid;
      grid-template-columns: 1fr 1fr;
      gap: 12px;
    }
    .card {
      background: #1a2634;
      border-radius: 14px;
      padding: 14px;
      text-align: center;
      border: 1px solid #1e3a4a;
    }
    .icon { font-size: 1.8em; margin-bottom: 6px; }
    .label {
      font-size: 0.7em;
      color: #888;
      text-transform: uppercase;
      letter-spacing: 1px;
    }
    .value {
      font-size: 1.6em;
      font-weight: bold;
      color: #fff;
      margin: 4px 0;
    }
    .unit { font-size: 0.7em; color: #aaa; }
    .badge {
      display: inline-block;
      padding: 3px 10px;
      border-radius: 20px;
      font-size: 0.7em;
      font-weight: bold;
      margin-top: 6px;
      color: #fff;
    }
    .footer {
      text-align: center;
      margin-top: 20px;
      font-size: 0.7em;
      color: #444;
    }
  </style>
</head>
<body>
  <h1>&#x1F41F; Aquaponics Monitor</h1>
  <p class="subtitle">Auto-refresh every 3s &bull; 192.168.4.1</p>
  <div class="grid">
)rawhtml";

  // Build each card manually
  // 1. Air Temp
  html += "<div class='card'><div class='icon'>&#x1F321;</div>";
  html += "<div class='label'>Air Temp</div>";
  html += "<div class='value'>" + String(airTemp, 1) + "<span class='unit'>°C</span></div>";
  html += "<span class='badge' style='background:" + badgeColor(ats) + "'>" + ats + "</span></div>";

  // 2. Humidity
  html += "<div class='card'><div class='icon'>&#x1F4A7;</div>";
  html += "<div class='label'>Humidity</div>";
  html += "<div class='value'>" + String(humidity, 1) + "<span class='unit'>%</span></div>";
  html += "<span class='badge' style='background:" + badgeColor(hums) + "'>" + hums + "</span></div>";

  // 3. Water Temp
  html += "<div class='card'><div class='icon'>&#x1F41F;</div>";
  html += "<div class='label'>Water Temp</div>";
  html += "<div class='value'>" + String(waterTemp, 1) + "<span class='unit'>°C</span></div>";
  html += "<span class='badge' style='background:" + badgeColor(wts) + "'>" + wts + "</span></div>";

  // 4. pH Level
  html += "<div class='card'><div class='icon'>&#x2697;</div>";
  html += "<div class='label'>pH Level</div>";
  html += "<div class='value'>" + String(phValue, 2) + "<span class='unit'>pH</span></div>";
  html += "<span class='badge' style='background:" + badgeColor(phs) + "'>" + phs + "</span></div>";

  // 5. Turbidity
  html += "<div class='card'><div class='icon'>&#x1F30A;</div>";
  html += "<div class='label'>Turbidity</div>";
  html += "<div class='value'>" + turbidity + "</div>";
  html += "<span class='badge' style='background:" + badgeColor(turbidity) + "'>" + turbidity + "</span></div>";

  // 6. Light
  html += "<div class='card'><div class='icon'>&#x2600;</div>";
  html += "<div class='label'>Light</div>";
  html += "<div class='value'>" + lightStatus + "</div>";
  html += "<span class='badge' style='background:" + badgeColor(lightStatus) + "'>" + lightStatus + "</span></div>";

  html += R"rawhtml(
  </div>
  <div class="footer">Aquaponics IoT System &bull; NodeMCU ESP8266</div>
</body>
</html>
)rawhtml";

  server.send(200, "text/html", html);
}

// ================= SETUP =================
void setup() {
  Serial.begin(9600);    // for debugging in Serial Monitor
  mySerial.begin(9600);  // for reading Arduino data

  WiFi.softAP(ssid, password);

  server.on("/", handleRoot);
  server.begin();

  Serial.println("AP Started: Aquaponics_System");
  Serial.println("IP: 192.168.4.1");
}

// ================= LOOP =================
void loop() {
  if (mySerial.available()) {
    String line = mySerial.readStringUntil('\n');
    line.trim();
    Serial.println("Received: " + line); // debug
    parseSerial(line);
  }
  server.handleClient();
}