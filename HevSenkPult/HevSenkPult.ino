
const int nerPin = 0;
const int oppPin = 1;
const int buttonNerPin = 3;
const int buttonOppPin = 2; 
const int buttonSet1Pin = 16;
const int buttonSet2Pin = 17;

int buttonNerState = 0;
int buttonOppState = 0;
int buttonSet1State = 0;
int buttonSet2State = 0;


void setup() {
  
  Serial.begin(9600);

  pinMode(nerPin, OUTPUT);
  pinMode(oppPin, OUTPUT);
  pinMode(buttonNerPin, INPUT_PULLDOWN);
  pinMode(buttonOppPin, INPUT_PULLDOWN);
  pinMode(buttonSet1Pin, INPUT_PULLDOWN);
  pinMode(buttonSet2Pin, INPUT_PULLDOWN);
}

void loop() {

  buttonNerState = digitalRead(buttonNerPin);
  buttonOppState = digitalRead(buttonOppPin);
  buttonSet1State = digitalRead(buttonSet1Pin);
  buttonSet2State = digitalRead(buttonSet2Pin);

  if (buttonNerState == HIGH && buttonOppState == HIGH) {
      digitalWrite(nerPin, LOW);
      digitalWrite(oppPin, LOW);
  } else if (buttonOppState == HIGH) {
      digitalWrite(oppPin, HIGH);
      digitalWrite(nerPin, LOW);
  } else if (buttonNerState == HIGH) {
      digitalWrite(nerPin, HIGH);
      digitalWrite(oppPin, LOW);
  } else if () {
  } else {
      digitalWrite(nerPin, LOW);
      digitalWrite(oppPin, LOW);
  }

  int sensor = analogRead(A2);

  float volt = sensor * (10.0 / 1023.0);

  Serial.println(volt);
}
