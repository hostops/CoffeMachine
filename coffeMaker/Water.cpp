#include "Arduino.h"
#include "Water.h"
Water::Water(int pin, int unit){
  this->pin=pin;
  this->unit=unit;
  pinMode(pin,OUTPUT);
}
void Water::open(){
  digitalWrite(pin,HIGH);
}
void Water::close(){
  digitalWrite(pin,LOW);
}

void Water::openFor(int miliseconds){
  open();
  delay(miliseconds);
  close();
}
void Water::openForUnit(int numberOfUnits){
  open();
  delay(numberOfUnits*unit); 
  close();
}
