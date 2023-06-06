int Pd = A3;
int motor_control_1 = 10;
int motor_control_2 = 11;
int pushbutton_s = 8;
int pushbutton_c = 7;
 
bool stateleft = false;
bool stateright = false;

void setup() {
  Serial.begin(9600);
  pinMode(pushbutton_s, INPUT);
  pinMode(pushbutton_c, INPUT);
  pinMode(motor_control_1, OUTPUT);
  pinMode(motor_control_2, OUTPUT);
  pinMode(Pd, INPUT);
   
}

void loop() {
  bool buttonState1 = digitalRead(pushbutton_s);
  bool buttonState2 = digitalRead(pushbutton_c);
  int photodiodeReading = analogRead(Pd);
  
  Serial.println(photodiodeReading);

  if (photodiodeReading < 140) {
    delay(500);
    if (photodiodeReading < 140) {
       
      digitalWrite(motor_control_1, LOW);
      digitalWrite(motor_control_2, LOW);
      delay(500);
       

      if (photodiodeReading < 140) {
         
        digitalWrite(motor_control_1, LOW);
        digitalWrite(motor_control_2, LOW);
        delay(100);
      } else {
        
      }
    }
  } else if (photodiodeReading > 140) {
    if (stateright) {
       
      digitalWrite(motor_control_1, LOW);
      digitalWrite(motor_control_2, HIGH);
    } else if (stateleft) {
       
      digitalWrite(motor_control_1, HIGH);
      digitalWrite(motor_control_2, LOW);
    }
  }

  if (buttonState1) {
     
    digitalWrite(motor_control_1, LOW);
    digitalWrite(motor_control_2, HIGH);
    stateright = true;
    stateleft = false;
  } else if (buttonState2) {
     
    digitalWrite(motor_control_1, HIGH);
    digitalWrite(motor_control_2, LOW);
    stateright = false;
    stateleft = true;
  }
}
