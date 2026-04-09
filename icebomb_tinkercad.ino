#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

#define sensorPin A0
#define motorPin 7

void setup()
{
  lcd_1.begin(16, 2);
  lcd_1.print("Seconds:   s");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Temp:       C");
  lcd_1.setBacklight(1);

  pinMode(sensorPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  int seconds = millis() / 1000;
  lcd_1.setCursor(9, 0);
  lcd_1.print("      ");
  lcd_1.setCursor(9, 0);
  lcd_1.print(seconds);

  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

  lcd_1.setCursor(6, 1);
  lcd_1.print("      ");
  lcd_1.setCursor(6, 1);
  lcd_1.print(temperature, 1);

  if (temperature < 0) {
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }

  delay(200);
}
