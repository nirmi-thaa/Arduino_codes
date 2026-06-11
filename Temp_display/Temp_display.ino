#include <LiquidCrystal.h>
int temp=A0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  lcd.begin(16, 2);
  lcd.print("Temperature");
  delay(2000);
  lcd.clear();
}

void loop()
{
  int value=analogRead(temp);
  float voltage = value * (5.0 / 1023.0);
  float TEMP=(voltage-0.5)*100;
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");

  lcd.setCursor(0, 1);
  lcd.print(TEMP);
  lcd.print("C   ");
  delay(1000);
  
}