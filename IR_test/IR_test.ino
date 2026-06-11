int led=10;
int ir=7;
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(ir,INPUT);
}

void loop()
{
  if (digitalRead(ir)==LOW)
    digitalWrite(led,HIGH);
  else
    digitalWrite(led,LOW);
  
}