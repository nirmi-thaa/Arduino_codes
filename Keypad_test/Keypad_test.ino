#include <Keypad.h>
const byte ROW=4;
const byte COL=4;

char keys[ROW][COL]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROW]={1,2,3,4};
byte colPins[COL]={8,9,10,11};

Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROW,COL);


void setup()
{
Serial.begin(9600);}

void loop()
{
  char key=keypad.getKey();
  if (key)
  {
    Serial.print("The text:");
    Serial.println(key);
    
  }
}