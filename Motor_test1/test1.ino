const int motorPin = 6; 
const int echoPin = 7;
float rps;
float rpm;
float time1;
float time2;

void setup()
{
  pinMode(motorPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
}
void loop()
{
  for (int a = 0; a <= 80; a++) 
  {
    analogWrite(motorPin, a); 
  }

  time1 = pulseIn(echoPin, LOW);
  time2 = pulseIn(echoPin, HIGH);
  rps = 1000000/(2*(time1+time2));
  rpm = rps*60;

  if (rpm == INFINITY)
  {
    Serial.println("Sensor no signal");
  }
  else
  {
    Serial.println("RPM: ");
    Serial.println(rpm);
  }
}
