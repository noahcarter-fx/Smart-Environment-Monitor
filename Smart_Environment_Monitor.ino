#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <RTClib.h>

// ---------------- PINS ----------------

#define DHTPIN 2
#define DHTTYPE DHT11

#define MQ9_PIN A0
#define BUZZER_PIN 3

// ---------------- OBJECTS ----------------

DHT dht(DHTPIN, DHTTYPE);
RTC_DS3231 rtc;

// LCD 1 → Temp / Humidity / Gas
LiquidCrystal_I2C lcd1(0x27, 16, 2);

// LCD 2 → Date / Time
LiquidCrystal_I2C lcd2(0x26, 16, 2);

// ---------------- SETTINGS ----------------

int gasThreshold = 250;

unsigned long lastSwitchTime = 0;
bool showHumidity = false;

// ⚠️ Set TRUE only once to update RTC time
#define SET_RTC_TIME false

// ---------------- SETUP ----------------

void setup() {

  Serial.begin(9600);

  dht.begin();

  if (!rtc.begin()) {
    Serial.println("RTC not found");
    while (1);
  }

  // RTC Time Setup
  if (SET_RTC_TIME) {

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

    Serial.println("RTC Time Updated!");
    delay(500);
  }

  // LCD Init
  lcd1.init();
  lcd1.backlight();

  lcd2.init();
  lcd2.backlight();

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // Startup Message
  lcd1.setCursor(0, 0);
  lcd1.print("Air Monitor");

  lcd1.setCursor(0, 1);
  lcd1.print("Starting...");

  delay(2000);

  lcd1.clear();
  lcd2.clear();
}

// ---------------- LOOP ----------------

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int gasValue = analogRead(MQ9_PIN);

  DateTime now = rtc.now();

  // -------- BUZZER --------

  if (gasValue > gasThreshold) {
    digitalWrite(BUZZER_PIN, HIGH);
  }
  else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  // -------- SWITCH DISPLAY --------

  if (millis() - lastSwitchTime >= 30000) {

    showHumidity = !showHumidity;

    lastSwitchTime = millis();
  }

  // ---------------- LCD 1 ----------------

  lcd1.clear();

  lcd1.setCursor(0, 0);

  if (isnan(temperature)) {

    lcd1.print("Temp Error");

  }
  else {

    lcd1.print("Temp:");
    lcd1.print(temperature, 1);
    lcd1.print((char)223);
    lcd1.print("C");

  }

  lcd1.setCursor(0, 1);

  if (showHumidity) {

    if (isnan(humidity)) {

      lcd1.print("Humidity Err");

    }
    else {

      lcd1.print("Hum:");
      lcd1.print(humidity, 1);
      lcd1.print("%");

    }

  }
  else {

    lcd1.print("Gas:");
    lcd1.print(gasValue);

    if (gasValue <= 150) {

      lcd1.print(" Clean");

    }
    else if (gasValue <= 250) {

      lcd1.print(" Warn");

    }
    else {

      lcd1.print(" Alert");

    }

  }

  // ---------------- LCD 2 ----------------

  lcd2.clear();

  lcd2.setCursor(0, 0);

  // Date

  if (now.day() < 10) lcd2.print("0");
  lcd2.print(now.day());

  lcd2.print("/");

  if (now.month() < 10) lcd2.print("0");
  lcd2.print(now.month());

  lcd2.print("/");

  lcd2.print(now.year());

  // Time

  lcd2.setCursor(0, 1);

  if (now.hour() < 10) lcd2.print("0");
  lcd2.print(now.hour());

  lcd2.print(":");

  if (now.minute() < 10) lcd2.print("0");
  lcd2.print(now.minute());

  lcd2.print(":");

  if (now.second() < 10) lcd2.print("0");
  lcd2.print(now.second());

  // ---------------- SERIAL OUTPUT ----------------

  Serial.print("Temperature: ");
  Serial.print(temperature);

  Serial.print(" C | Humidity: ");
  Serial.print(humidity);

  Serial.print(" % | Gas: ");
  Serial.print(gasValue);

  Serial.print(" | Date: ");
  Serial.print(now.day());

  Serial.print("/");
  Serial.print(now.month());

  Serial.print("/");
  Serial.print(now.year());

  Serial.print(" | Time: ");
  Serial.print(now.hour());

  Serial.print(":");
  Serial.print(now.minute());

  Serial.print(":");
  Serial.println(now.second());

  delay(1000);
}