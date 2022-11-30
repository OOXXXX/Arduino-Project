int sensor = 7;
const int motorPin = 6; 
unsigned long start_time = 0;
unsigned long end_time = 0;
int steps=0;
float steps_old=0;
float temp=0;
float rps=0;
float rpm=0;

void setup()
{
  Serial.begin(115200);
  pinMode(sensor,INPUT_PULLUP);
  pinMode(motorPin, OUTPUT); 
}
void loop()
{
  for (int a = 0; a <= 255; a++) 
  {
    analogWrite(motorPin, a); 
  }

  start_time=millis();
  end_time=start_time+1000;
  while(millis()<end_time)
 {
   if(digitalRead(sensor))
   {
    steps=steps+1; 
    while(digitalRead(sensor));
   }
 }
  temp=steps-steps_old;
  steps_old=steps;
  rps = (temp/20);
  rpm = rps*60;
  //Serial.println(rps);
  Serial.println(rpm);
}
