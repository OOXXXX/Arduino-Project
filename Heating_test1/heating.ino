#define analogPin A0 
#define beta 4510  
const int heaterPin = 9;
float target = 30;

void setup()
{
  Serial.begin(9600);
  pinMode(heaterPin, OUTPUT);
}

void loop()
{ 
  long a = analogRead(analogPin);
  float tempC = beta /(log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
  Serial.print("Temperature: ");
  Serial.print(tempC);
  delay(20); 

  if (tempC < target-0.25) 
  {
    analogWrite(heaterPin, 150);
    Serial.print("Heater ON");
  } 
  else if (tempC > target+0.25) 
  {
    analogWrite(heaterPin, 0);
    Serial.print("Heater OFF");
  }
}