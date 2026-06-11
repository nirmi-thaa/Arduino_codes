
const int red=13;
const int yellow=12;
const int green =11;
const int blue =10;
const int button=2;
bool buttonPressed = false;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(button,INPUT);
  digitalWrite(green,HIGH);
}

void loop()
{
  if (digitalRead(button)==HIGH)
  {
    buttonPressed = true;
  }
  if (buttonPressed)
  {
    digitalWrite(green,LOW);
    digitalWrite(yellow,HIGH);
    delay(5000);
    digitalWrite(yellow,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(blue,HIGH);
    delay(5000);
    digitalWrite(blue,LOW);
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    delay(6000);
    buttonPressed = false; 
  }
 
}