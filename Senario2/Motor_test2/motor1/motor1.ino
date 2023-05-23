#define BUTTON2_PIN 8
#define BUTTON1_PIN 7
#define PHOTODIODE_PIN A3

int photoDiodePin = 2;
int motorPin = 10;
int motorPin2 = 11;
int button1State = 0;
int button2State = 0;
int ledPin1 = 12;
int ledPin2 = 13;
int photodiodeReading = 0;
int forwardPin = 9;

void setup() {
    pinMode(motorPin, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(forwardPin, OUTPUT);
    pinMode(BUTTON1_PIN, INPUT);
    pinMode(BUTTON2_PIN, INPUT);
    pinMode(PHOTODIODE_PIN, INPUT);
    pinMode(photoDiodePin, INPUT);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(photoDiodePin, HIGH);
    button1State = digitalRead(BUTTON1_PIN);
    button2State = digitalRead(BUTTON2_PIN);
    analogWrite(forwardPin, 150);
    if (button1State == HIGH) {
    analogWrite(motorPin, 50);
    analogWrite(motorPin2, 0);
    Serial.println("Button 1 is pressed");
    }
    if (button2State == HIGH) {
    analogWrite(motorPin, 0);
    analogWrite(motorPin2, 50);
    Serial.println("Button 2 is pressed");
    }
    photodiodeReading = analogRead(PHOTODIODE_PIN);

    //print the photodiode reading
    Serial.print("Photodiode reading: ");
    Serial.println(photodiodeReading);

    //wait a bit before reading again
    delay(100);
}