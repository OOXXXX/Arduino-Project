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

void LedFlash15() {
    digitalWrite (ledPin, HIGH);
    delay (3000);
    digitalWrite (ledPin, LOW);
    delay (3000);
}

void LedFlash10() {
    digitalWrite (ledPin, HIGH);
    delay (800);
    digitalWrite (ledPin, LOW);
    delay (800);
}

void LedFlash5() {
    digitalWrite (ledPin, HIGH);
    delay (100);
    digitalWrite (ledPin, LOW);
    delay (100);
}

void LedFlash1() {
    digitalWrite (ledPin, HIGH);
    delay (10);
    digitalWrite (ledPin, LOW);
    delay (10);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
//distance = duration * 0.034 / 2;
distance = 4;

    // if (distance <= 15) {
    //     Serial.println ("Someone Is Infront Of the Sensor");
    //     LedFlash15();
    //     if (distance <= 10) {
    //         Serial.println ("Someone Is Infront Of the Sensor");
    //         LedFlash10();
    //         if (distance <= 5) {
    //             Serial.println ("Someone Is Infront Of the Sensor");
    //             LedFlash5();
    //             if (distance <= 1) {
    //                 Serial.println ("Someone Is Infront Of the Sensor");
    //                 LedFlash1();
    //             }
    //         }
    //     }
    // }
    if (distance <= 1) {
        //Serial.println ("Someone Is Infront Of the Sensor");
        LedFlash1();
    }
    if (distance <= 5) {
        //Serial.println ("Someone Is Infront Of the Sensor");
        LedFlash5();
    }
    if (distance <= 10) {
        //Serial.println ("Someone Is Infront Of the Sensor");
        LedFlash10();
    }
    if (distance <= 15) {
        //Serial.println ("Someone Is Infront Of the Sensor");
        LedFlash15();
    }
    else {
        //Serial.println ("Nobody Is Infront Of the Sensor");
        digitalWrite(ledPin, LOW);
    }
Serial.println(distance);
}