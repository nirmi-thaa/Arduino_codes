const int button=2;
const int led=13;
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
}
void loop()
{
  int bs =digitalRead(button);
  if (bs==HIGH){
    
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
  }
  else
  {
    digitalWrite(led,LOW);
  
  }
  


}