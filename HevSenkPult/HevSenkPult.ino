
const int preset1 = 900;
const int preset2 = 100;

const int nerPin = 0;
const int oppPin = 1;
const int buttonNerPin = 3;
const int buttonOppPin = 2; 
const int buttonSet1Pin = 16;
const int buttonSet2Pin = 17;
const int analogPin = A2;

int buttonNerState = 0;
int buttonOppState = 0;
int buttonSet1State = 0;
int buttonSet2State = 0;
int analogState = 0;


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
  analogState = analogRead(analogPin);

  if (buttonNerState == HIGH && buttonOppState == HIGH) {
      digitalWrite(nerPin, LOW);
      digitalWrite(oppPin, LOW);
  } else if (buttonOppState == HIGH) {
      digitalWrite(oppPin, HIGH);
      digitalWrite(nerPin, LOW);
  } else if (buttonNerState == HIGH) {
      digitalWrite(nerPin, HIGH);
      digitalWrite(oppPin, LOW);
      
  } else if (buttonSet1State == HIGH && analogState != preset1) {
      if (analogState < preset1) {
        while (analogState < preset1) {
          analogState = analogRead(analogPin);
          digitalWrite(nerPin, LOW);
          digitalWrite(oppPin, HIGH);
          Serial.println(analogState);
          
        }
      } else if (analogState > preset1) {
        while (analogState > preset1) {
          analogState = analogRead(analogPin);
          digitalWrite(oppPin, LOW);
          digitalWrite(nerPin, HIGH);
          Serial.println(analogState);
        }
      }
  } else if (buttonSet2State == HIGH && analogState != preset2) {
      if (analogState < preset2) {
        while (analogState < preset2 && buttonSet2State == HIGH) {
          analogState = analogRead(analogPin);
          digitalWrite(nerPin, LOW);
          digitalWrite(oppPin, HIGH);
          Serial.println(analogState);          
        }
      } else if (analogState > preset2) {
        while (analogState > preset2 && buttonSet2State == HIGH) {
          analogState = analogRead(analogPin);
          digitalWrite(oppPin, LOW);
          digitalWrite(nerPin, HIGH);
          Serial.println(analogState);
        }
      }
  } else {
      digitalWrite(nerPin, LOW);
      digitalWrite(oppPin, LOW);
  }

  Serial.println(analogState);

}
