const int motorPin = 6; 
const int echoPin = 7;
float rps;
float rpm;
int time1;
int time2;

void setup()
{
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
}
void loop()
{
  time1 = pulseIn(echoPin, HIGH);
  time2 = pulseIn(echoPin, LOW);
  rps = 1000000/(2*(time1+time2));
  rpm = rps*60;

  if (rps == -1)
  {
    Serial.println("No signal");
  }
  else
  {
    Serial.println(rpm);
  }
  
  for (int a = 0; a <= 100; a++) 
  {
    analogWrite(motorPin, a); 
  }
}
