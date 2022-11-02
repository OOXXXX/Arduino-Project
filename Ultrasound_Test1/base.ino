const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 7;
const int buzzerPin = 6;

int duration;
float distance;
long frequency;

void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
pinMode (ledPin, OUTPUT); 
pinMode (buzzerPin, OUTPUT);
Serial.begin(9600); 
digitalWrite (ledPin, LOW);
}

void LedFlash16() {
    digitalWrite (ledPin, HIGH);
    delay (400);
    digitalWrite (ledPin, LOW);
    delay (400);
}

void Buzz16() {
    tone(buzzerPin, frequency);
    delay(400); 
    noTone(buzzerPin);
    delay(400); 
}

void LedFlash11() {
    digitalWrite (ledPin, HIGH);
    delay (200);
    digitalWrite (ledPin, LOW);
    delay (200);
}

void Buzz11() {
    tone(buzzerPin, frequency);
    delay(200); 
    noTone(buzzerPin);
    delay(200); 
}

void LedFlash6() {
    digitalWrite (ledPin, HIGH);
    delay (80);
    digitalWrite (ledPin, LOW);
    delay (80);
}

void Buzz6() {
    tone(buzzerPin, frequency);
    delay(80); 
    noTone(buzzerPin);
    delay(80); 
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
frequency = 1000;
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;

    if (distance <= 16 && distance >= 11) {
        Serial.println ("Someone Is Infront Of the Sensor");
        LedFlash16();
        Buzz16();
    }
    else if (distance <= 11 && distance >= 6) {
        Serial.println ("Someone Is Infront Of the Sensor");
        LedFlash11();
        Buzz11(); 
    }
    else if (distance < 6) {
        Serial.println ("Someone Is Infront Of the Sensor");
        LedFlash6();
        Buzz6();
    }
    else {
        Serial.println ("Nobody Is Infront Of the Sensor");
        digitalWrite(ledPin, LOW);
    }
Serial.println(distance);
}
