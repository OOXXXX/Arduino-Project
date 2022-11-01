int delayTime = 3000;

void setup() {
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(5, HIGH);
  delay(delayTime);
  digitalWrite(5, LOW);
  delay(delayTime);
}
