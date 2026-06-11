#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int push = 7;
String morse = "";
unsigned long PressTime;

void setup() {
  pinMode(push, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.print("Morse Decoder");
  delay(1000);
  lcd.clear();
}

void loop() {

  if (digitalRead(push) == LOW) {

    PressTime = millis();

    while (digitalRead(push) == LOW) {
    }

    long duration = millis() - PressTime;

    if (duration < 100) {
      morse += ".";
      lcd.setCursor(0, 0);
      lcd.print(morse);
    }
    else {
      morse += "-";
      lcd.setCursor(0, 0);
      lcd.print(morse);
    }

    delay(200);
  }

  if (morse.length() > 0 && millis() - PressTime > 500) {
    decodeMorse();
    morse = "";
  }
}

void decodeMorse() {

  lcd.clear();

  if (morse == ".-")
    lcd.print("A");
  else if (morse == ".")
    lcd.print("E");
  else if (morse == "..")
    lcd.print("I");
  else if (morse == "---")
    lcd.print("O");
  else if (morse == "..-")
    lcd.print("U");
  else
    lcd.print("?");

  delay(1000);
  lcd.clear();
}