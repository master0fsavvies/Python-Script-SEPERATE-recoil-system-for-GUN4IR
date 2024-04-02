#include <AccelStepper.h>

const int solenoid1Pin = 7;
const int solenoid2Pin = 8;
bool shouldFire1 = false;
bool shouldFire2 = false;
int toggleState = HIGH;
bool singleFire = false;


void setup() {
  Serial.begin(9600);
  pinMode(solenoid1Pin, OUTPUT);
  pinMode(solenoid2Pin, OUTPUT);
  digitalWrite(solenoid1Pin, LOW);
  digitalWrite(solenoid2Pin, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    char inChar = Serial.read();
    if (inChar == '1' && !shouldFire1) { //trigger is pulled gun1
      shouldFire1 = true;
      digitalWrite(solenoid1Pin, HIGH);
    }
    if (inChar == '2') { //released trigger gun1
      shouldFire1 = false;
    }
    if (inChar == '3' && !shouldFire2) { //trigger is pulled gun2
      shouldFire2 = true;
      digitalWrite(solenoid2Pin, HIGH);
    }
    if (inChar == '4') { //released trigger gun2
      shouldFire2 = false;
    }
    if (inChar == '5') { //switches between autofire and singlefire
      singleFire = !singleFire;
    }
  }
  if(!singleFire){
    if(shouldFire1 && shouldFire2){ //both triggers are pulled in autofire
      digitalWrite(solenoid1Pin, HIGH);
      digitalWrite(solenoid2Pin, HIGH);
      delay(40);
      digitalWrite(solenoid1Pin, LOW);
      digitalWrite(solenoid2Pin, LOW);
      delay(70);
    }
    else {
      if(shouldFire1 && !shouldFire2){ //only gun1 fires in autofire
        digitalWrite(solenoid1Pin, HIGH);
        delay(40);
        digitalWrite(solenoid1Pin, LOW);
        delay(70);
      }
      if(shouldFire2 && !shouldFire1){ //only gun2 fires in autofire
        digitalWrite(solenoid2Pin, HIGH);
        delay(40);
        digitalWrite(solenoid2Pin, LOW);
        delay(70);
      }
    }
  }
  else{
    if(shouldFire1){ //gun1 fires in singlefire
      delay(40);
      digitalWrite(solenoid1Pin, LOW);
      shouldFire1 = false;
    }
    if(shouldFire2){ //gun2 fires in single fire
      delay(40);
      digitalWrite(solenoid2Pin, LOW);
      shouldFire2 = false;
    }
  }
}
