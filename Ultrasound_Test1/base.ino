const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 7;

int duration;
float distance;

void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
pinMode (ledPin, OUTPUT); 
Serial.begin(9600); 
digitalWrite (ledPin, LOW);
}

void LedFlash10() {
    digitalWrite (ledPin, HIGH);
    delay (100);
    digitalWrite (ledPin, LOW);
    delay (100);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;

    if (distance <= 10) {
        Serial.println ("Someone Is Infront Of the Sensor");
        LedFlash10();
    }
    else {
        Serial.println ("Nobody Is Infront Of the Sensor");
        digitalWrite(ledPin, LOW);
    }
Serial.println(distance);
}

// test.ino