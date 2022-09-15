#include <Arduino.h>
#line 1 "c:\\Users\\oddsk\\GitHub\\HevSenkPult\\HevSenkPultV2\\HevSenkPultV2.ino"
//Presets
const int preset1 = 100;
const int preset2 = 20;

//Pins
const int downPin = 0;
const int upPin = 1;
const int buttonDownPin = 3;
const int buttonUpPin = 2; 
const int buttonSet1Pin = 16;
const int buttonSet2Pin = 17;
const int trigPin = 4;
const int echoPin = 5;
long duration, cm;


//Variables for Pins
int buttonDownState = 0;
int buttonUpState = 0;
int buttonSet1State = 0;
int buttonSet2State = 0;



#line 25 "c:\\Users\\oddsk\\GitHub\\HevSenkPult\\HevSenkPultV2\\HevSenkPultV2.ino"
void setup();
#line 39 "c:\\Users\\oddsk\\GitHub\\HevSenkPult\\HevSenkPultV2\\HevSenkPultV2.ino"
void loop();
#line 215 "c:\\Users\\oddsk\\GitHub\\HevSenkPult\\HevSenkPultV2\\HevSenkPultV2.ino"
void funnyDelay(float delay);
#line 25 "c:\\Users\\oddsk\\GitHub\\HevSenkPult\\HevSenkPultV2\\HevSenkPultV2.ino"
void setup() {
  
  Serial.begin(9600);

  pinMode(downPin, OUTPUT);
  pinMode(upPin, OUTPUT);
  pinMode(buttonDownPin, INPUT_PULLDOWN);
  pinMode(buttonUpPin, INPUT_PULLDOWN);
  pinMode(buttonSet1Pin, INPUT_PULLDOWN);
  pinMode(buttonSet2Pin, INPUT_PULLDOWN);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT_PULLDOWN);
}

void loop() {

  buttonDownState = digitalRead(buttonDownPin);
  buttonUpState = digitalRead(buttonUpPin);
  buttonSet1State = digitalRead(buttonSet1Pin);
  buttonSet2State = digitalRead(buttonSet2Pin);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  // Distance = (traveltime/2) x speed of sound
  // The speed of sound = 343m/s = 0.0343cm/uS = 1/29.1 cm/uS
  cm = (duration/2) / 29.1;
  


  if (buttonDownState == HIGH && buttonUpState == HIGH) {
      digitalWrite(downPin, LOW);
      digitalWrite(upPin, LOW);

  //Up signal
  } else if (buttonUpState == HIGH) {
      digitalWrite(upPin, HIGH);
      digitalWrite(downPin, LOW);

  //Down signal
  } else if (buttonDownState == HIGH) {
      digitalWrite(downPin, HIGH);
      digitalWrite(upPin, LOW);
      buttonDownState = digitalRead(buttonDownPin);
      buttonUpState = digitalRead(buttonUpPin);
      buttonSet1State = digitalRead(buttonSet1Pin);
      buttonSet2State = digitalRead(buttonSet2Pin);
      

  //Preset 1    
  } else if (buttonSet1State == HIGH && cm != preset1) {
      if (cm < preset1) {
        while (cm < preset1 && buttonSet1State == HIGH) {
          digitalWrite(trigPin, LOW);
          delayMicroseconds(5);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          duration = pulseIn(echoPin, HIGH);
          cm = (duration/2) / 29.1;

          digitalWrite(downPin, LOW);
          digitalWrite(upPin, HIGH);

          Serial.println(cm);
          
          buttonDownState = digitalRead(buttonDownPin);
          buttonUpState = digitalRead(buttonUpPin);
          buttonSet1State = digitalRead(buttonSet1Pin);
          buttonSet2State = digitalRead(buttonSet2Pin);
          
          digitalWrite(trigPin, LOW);
          delayMicroseconds(5);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          duration = pulseIn(echoPin, HIGH);
          cm = (duration/2) / 29.1;
          
        }
      } else if (cm > preset1) {
        while (cm > preset1 && buttonSet1State == HIGH) {
          
          digitalWrite(trigPin, LOW);
          delayMicroseconds(5);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          duration = pulseIn(echoPin, HIGH);
          cm = (duration/2) / 29.1;

          digitalWrite(upPin, LOW);
          digitalWrite(downPin, HIGH);
          
          Serial.println(cm);
          
          buttonDownState = digitalRead(buttonDownPin);
          buttonUpState = digitalRead(buttonUpPin);
          buttonSet1State = digitalRead(buttonSet1Pin);
          buttonSet2State = digitalRead(buttonSet2Pin);
          
          digitalWrite(trigPin, LOW);
          delayMicroseconds(5);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          duration = pulseIn(echoPin, HIGH);
          cm = (duration/2) / 29.1;
        }
      }
  //Preset 2
  } else if (buttonSet2State == HIGH && cm != preset2) {
      if (cm < preset2) {
        while (cm < preset2 && buttonSet2State == HIGH) {
          digitalWrite(trigPin, LOW);
          delayMicroseconds(5);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          duration = pulseIn(echoPin, HIGH);
          cm = (duration/2) / 29.1;

          digitalWrite(downPin, LOW);
          digitalWrite(upPin, HIGH);

          digitalWrite(trigPin, LOW);
          delayMicroseconds(5);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          duration = pulseIn(echoPin, HIGH);
          cm = (duration/2) / 29.1;

          buttonDownState = digitalRead(buttonDownPin);
          buttonUpState = digitalRead(buttonUpPin);
          buttonSet1State = digitalRead(buttonSet1Pin);
          buttonSet2State = digitalRead(buttonSet2Pin);

          digitalWrite(trigPin, LOW);
          delayMicroseconds(5);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          duration = pulseIn(echoPin, HIGH);
          cm = (duration/2) / 29.1;         
        }

      } else if (cm > preset2) {
        while (cm > preset2 && buttonSet2State == HIGH) {
          digitalWrite(trigPin, LOW);
          delayMicroseconds(5);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          duration = pulseIn(echoPin, HIGH);
          cm = (duration/2) / 29.1;

          digitalWrite(upPin, LOW);
          digitalWrite(downPin, HIGH);

          Serial.println(cm);

          buttonDownState = digitalRead(buttonDownPin);
          buttonUpState = digitalRead(buttonUpPin);
          buttonSet1State = digitalRead(buttonSet1Pin);
          buttonSet2State = digitalRead(buttonSet2Pin);

          digitalWrite(trigPin, LOW);
          delayMicroseconds(5);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          duration = pulseIn(echoPin, HIGH);
          cm = (duration/2) / 29.1;
        }
      }

  } else {
      digitalWrite(downPin, LOW);
      digitalWrite(upPin, LOW);
  }

  Serial.println(cm);
  funnyDelay(6.9);
}

void funnyDelay(float delay){
  delayMicroseconds(delay * 1000);
}

