#include <LiquidCrystal.h>

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 7;
const int buzzerPin = 6;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int duration;
float distance;

void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
pinMode (ledPin, OUTPUT); 
pinMode (buzzerPin, OUTPUT);
lcd.begin(16, 2);
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
    tone(buzzerPin, 300);
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
    tone(buzzerPin, 700);
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
    tone(buzzerPin, 1100);
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
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;
lcd.setCursor(0, 0);
lcd.print("Distance:");
lcd.setCursor(7, 1);
lcd.print("cm");  
lcd.setCursor(0, 1);
lcd.print(distance);

    if (distance <= 16 && distance >= 11) {
        Serial.println("There's something behind the sensor!");
        LedFlash16();
        Buzz16();
    }
    else if (distance < 11 && distance >= 6) {
        Serial.println("There's something behind the sensor!");
        LedFlash11();
        Buzz11(); 
    }
    else if (distance < 6) {
        Serial.println("There's something behind the sensor!");
        LedFlash6();
        Buzz6();
    }
    else {
        Serial.println("There's nothing behind the sensor!");
        digitalWrite(ledPin, LOW);
    }
Serial.println(distance);
}
