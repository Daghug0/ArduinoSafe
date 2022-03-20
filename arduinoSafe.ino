/*This project include a servo used as a lock and four buttons as a keyboard to enter the passwords, 2 leds and a piezo are also added to give information about the current state of the chest*/

#include <PinChangeInt.h>
#include <Servo.h>
#include "safeFunctions.h"

Servo myServo;
/*INITIALIZE THE PIN NUMBERS*/
/*There is four button each of which is linked to a digit (as a small keyboard)*/
const int buttonPin1 = 8;
const int buttonPin2 = 9;
const int buttonPin3 = 10;
const int buttonPin4 = 11;
const int buzzPin = 6;
const int redLed = 2;
const int greenLed = 3;
/*Initialize some variables to keep track of our chest's state*/
int password[] = {3,2,3,1}; //this array contain the password for the chest
int attempt[4] ; //this array contain the current attempt to open the chest.
unsigned long dateDernierChangement;
boolean isOpen; 
int passwordIndex;

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buzzPin, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  myServo.attach(5);
  PCintPort::attachInterrupt(buttonPin1, pressed1, RISING);
  PCintPort::attachInterrupt(buttonPin2, pressed2, RISING);
  PCintPort::attachInterrupt(buttonPin3, pressed3, RISING);
  PCintPort::attachInterrupt(buttonPin4, pressed4, RISING);
  closeChest();
  reinitialize();
}

void loop() {
}
