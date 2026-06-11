
#include <Servo.h>
#include <LiquidCrystal.h>
Servo lid;
LiquidCrystal lcd(12,11,5,4,3,2);
int ultra=7;
int pin=9;
void setup()
{
  lid.attach(pin);
  lid.write(0);
  lcd.begin(16,2);
  lcd.print("Samrt Dustbin");
  delay(1000);
  lcd.clear();
}

void loop()
{
  long duration;
  float distance;
  pinMode(ultra,OUTPUT);
  digitalWrite(ultra,LOW);
  delayMicroseconds(2);
  digitalWrite(ultra,HIGH);
  delayMicroseconds(5);
  digitalWrite(ultra,LOW);
  
  pinMode(ultra,INPUT);
  duration=pulseIn(ultra,HIGH);
  distance=duration*0.0343/2;//Because speed of sound is 343m/s
  
  if (distance>0 && distance<15){
  lid.write(90);
  lcd.setCursor(0,0);
  lcd.print("OPEN");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm");
  delay(6000);
  lid.write(0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Thank You !");
  delay(1000);
  lcd.clear();
  }
  else{
  lid.write(0);
  lcd.setCursor(0,0);
  lcd.print("CLOSED");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm");
  delay(100);}
  delay(1000);
}