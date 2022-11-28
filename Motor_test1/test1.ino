const int motorPin = 6; 

void setup()
{
  pinMode(motorPin, OUTPUT); 
}
void loop()
{
  for (int a = 0; a <= 255; a++) 
  {
    analogWrite(motorPin, a); 
    delay(8); 
  }
  for (int a = 255; a >= 0; a--) 
  {
    analogWrite(motorPin, a); 
    delay(8); 
  }
  delay(800); 
}
