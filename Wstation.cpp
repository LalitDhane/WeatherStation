#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
#define SEALEVELPRESSURE_HPA (1013.25)
byte degree[8] = 
              {
                0b00011,
                0b00011,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };
 
Adafruit_BME280 bme;
 
void setup() {
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.createChar(1, degree);
 
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}
 
void loop() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println("*C");
 
  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println("%");
 
  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println("hPa");
 
  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println("m");
 
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.print(bme.readTemperature());
  lcd.write(1);
  lcd.print("C");
 
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(bme.readHumidity());
  lcd.print("%");
 
  lcd.setCursor(0, 2);
  lcd.print("Pressure: ");
  lcd.print(bme.readPressure() / 100.0F);
  lcd.print("hPa");
 
  lcd.setCursor(0, 3);
  lcd.print("Altitude: ");
  lcd.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  lcd.print("m");
 
  Serial.println();
  delay(1000);
  lcd.clear();
}
