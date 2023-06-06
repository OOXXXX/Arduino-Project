#define BUTTON2_PIN 8
#define BUTTON1_PIN 7
#define PHOTODIODE_PIN A3

int photoDiodePin = 2;
int motorPin = 10;
int motorPin2 = 11;
int rightButtonState = 0;
int leftButtonState = 0;
int ledPin1 = 12;
int ledPin2 = 13;
int photodiodeReading = 0;
int forwardPin = 9;
int currentDirection = -1; // Current direction of the robot (-1 for left, 1 for right)

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
    setMotorDirection(currentDirection);
}

void loop() {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(photoDiodePin, HIGH);
    rightButtonState = digitalRead(BUTTON1_PIN);
    leftButtonState = digitalRead(BUTTON2_PIN);

    if (rightButtonState == HIGH) {
        digitalWrite(motorPin, HIGH);
        digitalWrite(motorPin2, LOW);
        digitalWrite(forwardPin, HIGH);
    } else if (leftButtonState == HIGH) {
        digitalWrite(motorPin, LOW);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(forwardPin, LOW);
    } else {
        digitalWrite(motorPin, HIGH);
        digitalWrite(motorPin2, LOW);
    }   
    
    photodiodeReading = analogRead(PHOTODIODE_PIN);

    Serial.print("Photodiode reading: ");
    Serial.println(photodiodeReading);

    delay(100);
}

void setMotorDirection(int direction) {
  if (direction == -1) {
    digitalWrite(motorPin, HIGH);
    digitalWrite(motorPin2, LOW);
  } else {
    digitalWrite(motorPin, LOW);
    digitalWrite(motorPin2, HIGH);
  }
}
