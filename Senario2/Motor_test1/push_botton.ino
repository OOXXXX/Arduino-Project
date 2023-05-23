// Q1 
#define BUTTON1_PIN 7
#define BUTTON2_PIN 8

int button1State = 0;
int button2State = 0;

void setup() {
  pinMode(BUTTON1_PIN, INPUT);
  pinMode(BUTTON2_PIN, INPUT);
 
  Serial.begin(9600);
}

void loop() {
  button1State = digitalRead(BUTTON1_PIN);
  button2State = digitalRead(BUTTON2_PIN);

  if (button1State == HIGH) {
    
    Serial.println("Button 1 is pressed");
  }
  if (button2State == HIGH) {
    
    Serial.println("Button 2 is pressed");
  }
  
}
