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

void LedFlash16() {
    digitalWrite (ledPin, HIGH);
    delay (600);
    digitalWrite (ledPin, LOW);
    delay (600);
}

void LedFlash11() {
    digitalWrite (ledPin, HIGH);
    delay (200);
    digitalWrite (ledPin, LOW);
    delay (200);
}

void LedFlash6() {
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

    if (distance <= 16 && distance >= 11) {
        Serial.println ("Someone Is Infront Of the Sensor");
        LedFlash16();
    }
    else if (distance <= 11 && distance >= 6) {
        Serial.println ("Someone Is Infront Of the Sensor");
        LedFlash11();
    }
    else if (distance < 6) {
        Serial.println ("Someone Is Infront Of the Sensor");
        LedFlash6();
    }
    else {
        Serial.println ("Nobody Is Infront Of the Sensor");
        digitalWrite(ledPin, LOW);
    }
Serial.println(distance);
}
