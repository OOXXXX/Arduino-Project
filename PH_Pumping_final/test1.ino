float F=96485.309;
int T=290;
float R=8.314510;
float C=2.30258509299;
const int basePin = 10; 
const int acidPin = 11;
int PH_Max = 7.5;
int PH_Min = 6.5;
const int motorPin = 6; 
const int echoPin = 7;
float rps;
float rpm;
float time1;
float time2;
// heating part
#define analogPin A5  
#define beta 4510  
#define resistance 10  
#define HeaterPin 9
float target = 30 ;

void setup() {
  pinMode(basePin, OUTPUT);  
  pinMode(acidPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(HeaterPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    
  // Below are the PH and pumping part
  int PH_N=analogRead(A0);
  int PH_P=analogRead(A1);
  float Voltage_N=PH_N*(5.0/1023.0);
  float Voltage_P=PH_P*(5.0/1023.0);
  float PH = 7.0+((F*(Voltage_P-Voltage_N))/(R*T*C));

  if (PH > PH_Max)
  {
    analogWrite(basePin, 250);
    analogWrite(acidPin, 0);
  }
  else if (PH < PH_Min)
  {
    analogWrite(acidPin, 250);
    analogWrite(basePin, 0);
  }
  else
  {
    analogWrite(basePin, 0);
    analogWrite(acidPin, 0);
  }

  // Below are the motor and speed sensor part
  time1 = pulseIn(echoPin, LOW);
  time2 = pulseIn(echoPin, HIGH);
  rps = 1000000/(2*(time1+time2));
  rpm = rps*60;

  if (rps == -1)
  {
    Serial.println("Motor No signal");
  }
  else
  {
    Serial.println("RPM:");
    Serial.println(rpm);
  }
  
  for (int a = 0; a <= 80; a++) 
  {
    analogWrite(motorPin, a); 
  }
  Serial.println("PH:");
  Serial.println(PH);
  delay(500);

  // Below are the heating part
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
