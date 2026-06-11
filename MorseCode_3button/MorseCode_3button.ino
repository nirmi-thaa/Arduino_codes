int b1=8;
int b2=9;
int b3=10;

void setup() {
  pinMode(b1,INPUT_PULLUP);
  pinMode(b2,INPUT_PULLUP);
  pinMode(b3,INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {

  if(digitalRead(b1)==LOW){
    Serial.print(".");
    delay(200);
  }

  else if(digitalRead(b2)==LOW){
    Serial.print("-");
    delay(200);
  }

  else if(digitalRead(b3)==LOW){
    Serial.print(" ");
    delay(200);
  }

}