
const int nerPin = 0;
const int oppPin = 1;
const int buttonNerPin = 2;
const int buttonOppPin = 3; 

void setup() {
  
  Serial.begin(9600);

  pinMode(nerPin, OUTPUT);
  pinMode(oppPin, OUTPUT);
  pinMode(buttonNerPin, INPUT_PULLUP);
  pinMode(buttonOppPin, INPUT_PULLUP);
}

void loop() {

  int sensor = analogRead(A2);

  float volt = sensor * (10.0 / 1023.0);

  Serial.println(volt);
}
