const int sensorPin = 1;  
const int buzzer = 2;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  long duration;

  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(sensorPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(sensorPin, LOW);

  pinMode(sensorPin, INPUT);
  duration = pulseIn(sensorPin, HIGH);

  float distance = duration * 0.034 / 2;

  if (distance < 10) {
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
  }

  delay(100);
}