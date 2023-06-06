
#define PHOTODIODE_PIN A3

const int leftButtonPin = 8; 
const int rightButtonPin = 7;
int motorPin = 10;
int motorPin2 = 11;
int ledPin1 = 12;
int ledPin2 = 13;
int photodiodeReading = 0;
int forwardPin = 9;
bool stateleft = false;
bool stateright = false;

void setup() {
    pinMode(motorPin, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(forwardPin, OUTPUT);
    pinMode(leftButtonPin, INPUT);
    pinMode(rightButtonPin, INPUT);
    pinMode(PHOTODIODE_PIN, INPUT);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);

    Serial.begin(19200);
}

void loop() {
    Serial.print("Photodiode reading: ");
    Serial.println(photodiodeReading);
    bool buttonState1 = digitalRead(leftButtonPin);
    bool buttonState2 = digitalRead(rightButtonPin);

    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    photodiodeReading = analogRead(PHOTODIODE_PIN);
    
    if (photodiodeReading < 85) {
        delay(950);
        analogWrite(forwardPin, 250);
        analogWrite(motorPin, 0);
        analogWrite(motorPin2, 0);
        
    }
    else if (photodiodeReading > 85){
        
    if (stateright) {
    analogWrite(motorPin, 0);
    analogWrite(motorPin2, 50);

    } 
    else if (stateleft) {
       
    analogWrite(motorPin, 50);
    analogWrite(motorPin2, 0);
    }
    analogWrite(forwardPin, 0);
    }

    if (buttonState1) {
     
    analogWrite(motorPin, 0);
    analogWrite(motorPin2, 50);
    stateright = true;
    stateleft = false;
    } else if (buttonState2) {
    
    analogWrite(motorPin, 50);
    analogWrite(motorPin2, 0);
    stateright = false;
    stateleft = true;
  }
    

}