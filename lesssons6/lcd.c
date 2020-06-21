#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
  {
    lcd.clear();
  	lcd.setCursor(0, 0);
  
  	lcd.print(Serial.readString());
  }
  delay(10);
}