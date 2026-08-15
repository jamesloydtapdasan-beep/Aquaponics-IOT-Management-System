#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// ================= LCD =================
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ================= DHT11 =================
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ================= DS18B20 =================
#define ONE_WIRE_BUS 5
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature waterSensor(&oneWire);

// ================= ANALOG SENSORS =================
#define WATER_QUALITY_PIN A0
#define PH_PIN A1
#define LIGHT_PIN A3

// ================= OUTPUTS =================
#define LIGHT_RELAY 7
#define STATUS_LED 

// ================= STABLE READ =================
int readStableAnalog(int pin) {
  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(pin);
    delay(5);
  }
  return sum / 10;
}

void setup() {
  Serial.begin(9600);

  dht.begin();
  waterSensor.begin();

  pinMode(LIGHT_RELAY, OUTPUT);
  pinMode(STATUS_LED, OUTPUT);

  digitalWrite(LIGHT_RELAY, LOW);
  digitalWrite(STATUS_LED, LOW);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Aquaponics Sys");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();

  Serial.println("SYSTEM STARTED");
}

void loop() {

  delay(1000);

  // ================= DHT11 =================
  float airTemperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  String airStatus;
  String humStatus;

  if (isnan(airTemperature) || isnan(humidity)) {
    airTemperature = 0;
    humidity = 0;
    airStatus = "ERROR";
    humStatus = "ERROR";
  } else {

    if (airTemperature < 18) airStatus = "COLD";
    else if (airTemperature <= 30) airStatus = "NORMAL";
    else airStatus = "HOT";

    if (humidity < 40) humStatus = "LOW";
    else if (humidity <= 70) humStatus = "NORMAL";
    else humStatus = "HIGH";
  }

  // ================= WATER TEMP =================
  waterSensor.requestTemperatures();
  float waterTemperature = waterSensor.getTempCByIndex(0);

  String waterStatus;

  if (waterTemperature == -127.00)
    waterStatus = "ERROR";
  else if (waterTemperature < 21)
    waterStatus = "COLD";
  else if (waterTemperature <= 30)
    waterStatus = "NORMAL";
  else if (waterTemperature <= 35)
    waterStatus = "ABOVE NORM";
  else
    waterStatus = "HOT";

  // ================= WATER QUALITY =================
  int waterQualityRaw = readStableAnalog(WATER_QUALITY_PIN);
  int waterQuality = map(waterQualityRaw, 0, 1023, 1000, 0);

  // ================= PH =================
  int phRaw = readStableAnalog(PH_PIN);
  float voltage = phRaw * (5.0 / 1023.0);
  float phValue = 7 + ((2.5 - voltage) / 0.18);

  String phStatus;

  if (phValue < 6.5)
    phStatus = "ACIDIC";
  else if (phValue <= 7.5)
    phStatus = "NEUTRAL";
  else
    phStatus = "ALKALINE";

  // ================= LIGHT (YOUR LOGIC INSERTED) =================

  int value = readStableAnalog(LIGHT_PIN);

  Serial.print("LDR Value: ");
  Serial.println(value);

  String lightStatus;

  if (value > 300) {
    // DARK → LED ON
    digitalWrite(STATUS_LED, HIGH);
    lightStatus = "DARK";
    Serial.println("DARK -> LED ON");
  }
  else if (value > 100 && value <= 299) {
    // DIM → LED ON
    digitalWrite(STATUS_LED, HIGH);
    lightStatus = "DIM";
    Serial.println("DIM -> LED ON");
  }
  else {
    // BRIGHT → LED OFF
    digitalWrite(STATUS_LED, LOW);
    lightStatus = "BRIGHT";
    Serial.println("BRIGHT -> LED OFF");
  }

  // ================= SERIAL =================
  Serial.println("===== SENSOR DATA =====");

  Serial.print("Air Temp: "); Serial.println(airTemperature);
  Serial.print("Humidity: "); Serial.println(humidity);
  Serial.print("Water Temp: "); Serial.println(waterTemperature);
  Serial.print("Water Quality: "); Serial.println(waterQuality);
  Serial.print("pH: "); Serial.println(phValue);
  Serial.print("Light: "); Serial.println(value);

  Serial.println("=======================");

  // ================= LCD =================
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Air:");
  lcd.print(airTemperature);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print(airStatus);

  delay(2500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hum:");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print(humStatus);

  delay(2500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WTemp:");
  lcd.print(waterTemperature);

  lcd.setCursor(0, 1);
  lcd.print(waterStatus);

  delay(2500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Qual:");
  lcd.print(waterQuality);

  lcd.setCursor(0, 1);
  lcd.print("OK");

  delay(2500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("pH:");
  lcd.print(phValue);

  lcd.setCursor(0, 1);
  lcd.print(phStatus);

  delay(2500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light:");
  lcd.print(value);

  lcd.setCursor(0, 1);
  lcd.print(lightStatus);

  delay(2500);
}