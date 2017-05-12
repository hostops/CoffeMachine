#include "Arduino.h"
#include "Servo.h"
#include "Addition.h"
Addition::Addition(int pin){
  this->pin=pin;
}
Addition::Addition(int pin, int unit){
  this->pin=pin;
  this->unit=unit;
}
void Addition::start(){
  s.attach(pin);
  close();
}
void Addition::open(){
  s.write(90);
  delay(100);
}
void Addition::close(){
  s.write(180);
  delay(100);
}
void Addition::openFor(int miliseconds){
  open();
  delay(miliseconds);
  close();
}
void Addition::openForUnit(int numberOfUnits){
  open();
  delay(numberOfUnits*unit); 
  close();
}
