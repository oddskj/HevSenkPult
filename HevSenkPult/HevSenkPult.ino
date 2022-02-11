//Presets
const int preset1 = 900;
const int preset2 = 100;

//Pins
const int downPin = 0;
const int upPin = 1;
const int buttonDownPin = 3;
const int buttonUpPin = 2; 
const int buttonSet1Pin = 16;
const int buttonSet2Pin = 17;
const int analogPin = A2;

//Variables for Pins
int buttonDownState = 0;
int buttonUpState = 0;
int buttonSet1State = 0;
int buttonSet2State = 0;
int analogState = 0;


void setup() {
  
  Serial.begin(9600);

  pinMode(downPin, OUTPUT);
  pinMode(upPin, OUTPUT);
  pinMode(buttonDownPin, INPUT_PULLDOWN);
  pinMode(buttonUpPin, INPUT_PULLDOWN);
  pinMode(buttonSet1Pin, INPUT_PULLDOWN);
  pinMode(buttonSet2Pin, INPUT_PULLDOWN);
}

void loop() {

  buttonDownState = digitalRead(buttonDownPin);
  buttonUpState = digitalRead(buttonUpPin);
  buttonSet1State = digitalRead(buttonSet1Pin);
  buttonSet2State = digitalRead(buttonSet2Pin);
  analogState = analogRead(analogPin);

  if (buttonDownState == HIGH && buttonUpState == HIGH) {
      digitalWrite(downPin, LOW);
      digitalWrite(upPin, LOW);

  } else if (buttonUpState == HIGH) {
      digitalWrite(upPin, HIGH);
      digitalWrite(downPin, LOW);

  } else if (buttonDownState == HIGH) {
      digitalWrite(downPin, HIGH);
      digitalWrite(upPin, LOW);
      
  } else if (buttonSet1State == HIGH && analogState != preset1) {
      if (analogState < preset1) {
        while (analogState < preset1 && buttonSet1State == HIGH) {
          analogState = analogRead(analogPin);
          digitalWrite(downPin, LOW);
          digitalWrite(upPin, HIGH);
          Serial.println(analogState);
          buttonSet1State = digitalRead(buttonSet1Pin);
          
        }
      } else if (analogState > preset1) {
        while (analogState > preset1 && buttonSet1State == HIGH) {
          analogState = analogRead(analogPin);
          digitalWrite(upPin, LOW);
          digitalWrite(downPin, HIGH);
          Serial.println(analogState);
          buttonSet1State = digitalRead(buttonSet1Pin);
        }
      }

  } else if (buttonSet2State == HIGH && analogState != preset2) {
      if (analogState < preset2) {
        while (analogState < preset2 && buttonSet2State == HIGH) {
          analogState = analogRead(analogPin);
          digitalWrite(downPin, LOW);
          digitalWrite(upPin, HIGH);
          Serial.println(analogState);
          buttonSet2State = digitalRead(buttonSet2Pin);          
        }

      } else if (analogState > preset2) {
        while (analogState > preset2 && buttonSet2State == HIGH) {
          analogState = analogRead(analogPin);
          digitalWrite(upPin, LOW);
          digitalWrite(downPin, HIGH);
          Serial.println(analogState);
          buttonSet2State = digitalRead(buttonSet2Pin);
        }
      }

  } else {
      digitalWrite(downPin, LOW);
      digitalWrite(upPin, LOW);
  }

  Serial.println(analogState);

}
