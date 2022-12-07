const int basePin = 10; 
const int acidPin = 11;

void setup()
{
  pinMode(basePin, OUTPUT);  
  pinMode(acidPin, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  analogWrite(basePin, 255);
  analogWrite(acidPin, 230);
}