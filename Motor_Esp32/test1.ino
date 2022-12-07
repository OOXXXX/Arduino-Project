#include <Wire.h>

#define SLAVE_ADDR 42
#define motorPin 6
#define echoPin 7

float temp_target = 30.0;
float ph_target = 5.0;
int rpm_target = 1000;

float temp_reading = 31.4;
float ph_reading = 4.1;
int rpm_reading = 998;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  pinMode(motorPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void get_rpm_reading() {
  float time1 = pulseIn(echoPin, HIGH);
  float time2 = pulseIn(echoPin, LOW);
  float rps = 1000000/(2*(time1+time2));
  if (rps == -1) Serial.println("No reading from rpm sensor");
  rpm_reading = rps * 60; 

  for (int a = 0; a <= 100; a++) 
  {
    analogWrite(motorPin, a); 
  }
}

void loop() {
  Serial.println("Hello World");
  get_rpm_reading();

  sendReadings();
  receiveTargets();

  delay(500);
}

void sendReadings() {
  int t_reading = temp_reading * 100;
  int p_reading = ph_reading * 100;
  int r_reading = rpm_reading;
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write((byte*) &t_reading, 2);
  Wire.write((byte*) &p_reading, 2);
  Wire.write((byte*) &r_reading, 2);
  Wire.endTransmission();
}

int readInt() {
  int data = 0;
  data = Wire.read();
  data |= Wire.read() << 8;

  return data;
}

void receiveTargets() {
  Wire.requestFrom(SLAVE_ADDR, 6);

  if (!Wire.available()) return;

  int t_target = readInt();
  int p_target = readInt();
  int r_target = readInt();

  temp_target = t_target / 100.0;
  ph_target = p_target / 100.0;
  rpm_target = r_target;

  Serial.print("Temperature: ");
  Serial.println(temp_target);
  Serial.print("pH: ");
  Serial.println(ph_target);
  Serial.print("RPM: ");
  Serial.println(rpm_target);
}