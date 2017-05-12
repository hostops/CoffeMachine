#include "Arduino.h"
#include "Button.h"
Button::Button(int pin){
  this->pin=pin;
  pinMode(pin,INPUT_PULLUP);
}
boolean Button::read(){
  boolean curr=!digitalRead(pin); 
  if(!prev&&curr){//previous is 0 current is 1
    prev=curr;
    return true;
  }
  prev=curr;
  return false;
}
