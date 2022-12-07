#define analogPin A5 //the thermistor attach to 
#define beta 4510 //the beta of the thermistor
#define resistance 10 //the value of the pull-down resistor
#define HeaterPin 9
float target = 30 ;

void setup()
{
  Serial.begin(9600);
  pinMode(HeaterPin, OUTPUT);
}

void loop()
{ 
  long a = analogRead(analogPin);
  float tempC = beta /(log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
  Serial.print("TempC:  ");
  Serial.print(tempC);
  Serial.print("  C");
  Serial.println();
  delay(200); 
  if (tempC < target-0.25) {
    analogWrite(HeaterPin, 150);
    Serial.print("Heater ON");
    } 
  else if (tempC > target + 0.25) {
    analogWrite(HeaterPin, 0);
    Serial.print("Heater OFF");
  }
}
