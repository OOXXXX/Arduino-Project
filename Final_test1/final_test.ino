int PH_Max = 7.5;
int PH_Min = 6.5;
float F = 96485.309;
float R = 8.314510;
float C = 2.30258509299;
const int basePin = 10; 
const int acidPin = 11;
const int motorPin = 6; 
const int echoPin = 7;
float rps;
float rpm;
float time1;
float time2;
// heating part
const int heaterPin = 9;
#define ThermistorPin A5
#define A 0.0028
#define B -4.6768e-5
#define C 1.2034e-6
#define R1 10000 //the value of the pull-down resistor
float target = 30 ;
int PH_N=analogRead(A0);
int PH_P=analogRead(A1);

void setup() {
  pinMode(basePin, OUTPUT);  
  pinMode(acidPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(heaterPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  // Below are the motor and speed sensor part
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

  // Below are the heating part
  float ThermistorIN = analogRead(ThermistorPin);
  float R2 = R1 * (1023 / (1023-ThermistorIN) - 1);
  float logR2 = log(R2);
  float T = (1 / (A + B*logR2 + C*logR2*logR2*logR2));
  float TempC = T - 273.15;
  Serial.print("Temperature: ");
  Serial.print(TempC);
  Serial.print(" °C");
  Serial.println();
  delay(1000); 
  if (TempC < target-0.25) 
  {
    analogWrite(heaterPin, 150);
    Serial.print("Heater ON");
    Serial.println();
  } 
  else if (TempC > target + 0.25)
  {
    analogWrite(heaterPin, 0);
    Serial.print("Heater OFF");
    Serial.println();
  }
  else
  {
    analogWrite(heaterPin, 0);
    Serial.print("Heater OFF");
    Serial.println();
  }

  // Below are the PH and pumping part
  float Voltage_N=PH_N*(5.0/1023.0);
  float Voltage_P=PH_P*(5.0/1023.0);
  float PH = 7.0+((F*(Voltage_P-Voltage_N))/(R*T*C));
  Serial.print(Voltage_P);

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
  Serial.println("PH:");
  Serial.println(PH);
  delay(500);
}
