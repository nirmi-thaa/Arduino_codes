// C++ code
#include <Keypad.h>
#include <Servo.h>
const int red=3;
const int green=4;
const int piezo=2;
const byte ROWS=4;
const byte COLS=4;


char keys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS]={13,12,11,10};
byte colPins[COLS]={9,8,7,6};

Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

Servo lockServo;
int servoPin=5;

String Password="1234";
String Input="";


void setup()
{
  Serial.begin(9600);
  
  lockServo.attach(servoPin);
  lockServo.write(0);
  
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(piezo,OUTPUT);
  
}

void loop()
{
  char key=keypad.getKey();
  if(key){
    Serial.print(key);
    if(key=='#'){
      if (Input==Password){
        Unlock();}
       else{
        Lock();}
      Input="";
    }
    else if (key=='*')
    {Input="";}
    else
    {
      Input+=key;    
    }
  }
}
void Unlock()
{
  digitalWrite(green,HIGH);
  tone(piezo,1000,200);
  lockServo.write(90);
  delay(3000);
  lockServo.write(0);
  digitalWrite(green,LOW);
  
}
void Lock()
{
  
  for (int i=0;i<3;i++)
  {
    digitalWrite(red,HIGH);
    tone(piezo,500,200);
    delay(200);
    digitalWrite(red,LOW);
    delay(200);
  }
  
}
    
      
     
 
  
    
    
      
      
  
