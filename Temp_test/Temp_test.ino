onst int red=8;
const int green=9;
const int buzzer=10;
const int tmp=A0;
float temp=0;
void setup()
{
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop()
{
  int sensor = analogRead(tmp);
  int temperature = (sensor * 5.0 * 100.0) / 1024.0;
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
   if (temperature > 30.0) 
   {
     
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    tone(buzzer, 1000); 
  } else {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    noTone(buzzer);
  }

  delay(1000); 

}