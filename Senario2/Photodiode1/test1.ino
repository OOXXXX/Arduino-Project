// define photodiode output pin
#define PHOTODIODE_PIN A0

// variable to hold the photodiode reading
int photodiodeReading = 0;

void setup() {
  // set the photodiode pin as input
  pinMode(PHOTODIODE_PIN, INPUT);

  // start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // read the value from the photodiode
  photodiodeReading = analogRead(PHOTODIODE_PIN);

  // print the photodiode reading
  Serial.print("Photodiode reading: ");
  Serial.println(photodiodeReading);

  // wait a bit before reading again
  delay(100);
}
