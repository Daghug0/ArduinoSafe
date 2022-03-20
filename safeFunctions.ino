#include "safeFunctions.h"
#include <Servo.h>

bool verify(){
  for (int index = 0 ; index < 4 ; index++){
    if (attempt[index] != password[index]){
      return false;
    }
  }
  return true;
}

void reinitialize(){
  for (passwordIndex = 0 ; passwordIndex < 4 ; passwordIndex++){
    attempt[passwordIndex] = 0;
  }
  passwordIndex = 0;
}

void openChest(){
  tone(buzzPin,200,500);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  myServo.write(180);
  isOpen = true;
}

void closeChest(){
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, HIGH);
  tone(buzzPin,50,500);
  myServo.write(100);
  isOpen = false;
  delay(500);
  digitalWrite(greenLed, LOW);
}

void pressed(int button){
  unsigned long date = millis();
  if ((date - dateDernierChangement) > 100) {
    if(isOpen) {
      closeChest();
    }
    else {
      tone(buzzPin,400,50);
      attempt[passwordIndex] = button;
      passwordIndex = passwordIndex+1;
      if (passwordIndex == 4) {
        if (verify){
          openChest();
        }
        else {
          tone(buzzPin,50,500); 
          }
      reinitialize();
      }
    }
   dateDernierChangement = date;
  }
}

void pressed1() {
  pressed(1);
}

void pressed2() {
  pressed(2);
}

void pressed3() {
 pressed(3);
}

void pressed4() {
  pressed(4);
}
