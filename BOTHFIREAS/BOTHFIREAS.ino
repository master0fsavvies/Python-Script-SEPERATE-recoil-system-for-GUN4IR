#include <AccelStepper.h>

const int solenoid1Pin = 7;
const int solenoid2Pin = 8;
const int buttonPin = 9;
bool shouldFire1 = false;
bool shouldFire2 = false;
int toggleState = HIGH;
int lastButtonState = HIGH;
bool isToggleOn = false;
int buttonState = HIGH;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(solenoid1Pin, OUTPUT);
  pinMode(solenoid2Pin, OUTPUT);
  digitalWrite(solenoid1Pin, LOW);
  digitalWrite(solenoid2Pin, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    char inChar = Serial.read();
    if (inChar == '1' && !shouldFire1) {
      shouldFire1 = true;
      delay(15);
      digitalWrite(solenoid1Pin, HIGH);
    }
    if (inChar == '2') {
      shouldFire1 = false;
    }
    if (inChar == '3' && !shouldFire2) {
      shouldFire2 = true;
      delay(15);
      digitalWrite(solenoid2Pin, HIGH);
    }
    if (inChar == '4') {
      shouldFire2 = false;
    }
    if (inChar == '5') {
      isToggleOn = !isToggleOn;
    }
  }
  if(!isToggleOn){
    if(shouldFire1 && shouldFire2){
      digitalWrite(solenoid1Pin, HIGH);
      digitalWrite(solenoid2Pin, HIGH);
      delay(40);
      digitalWrite(solenoid1Pin, LOW);
      digitalWrite(solenoid2Pin, LOW);
      delay(70);
    }
    else {
      if(shouldFire1 && !shouldFire2){
        digitalWrite(solenoid1Pin, HIGH);
        delay(40);
        digitalWrite(solenoid1Pin, LOW);
        delay(70);
      }
      if(shouldFire2 && !shouldFire1){
        digitalWrite(solenoid2Pin, HIGH);
        delay(40);
        digitalWrite(solenoid2Pin, LOW);
        delay(70);
      }
    }
  }
  else{
    if(shouldFire1){
      delay(40);
      digitalWrite(solenoid1Pin, LOW);
      shouldFire1 = false;
    }
    if(shouldFire2){
      delay(40);
      digitalWrite(solenoid2Pin, LOW);
      shouldFire2 = false;
    }
  }
}
