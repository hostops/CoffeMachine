#ifndef Addition_h
#define Addition_h

#include "Arduino.h"
#include "Servo.h"
class Addition{
  public:
    Addition(int pin);
    Addition(int pin, int unit);
    void open();
    void close();
    void start();
    void openFor(int miliseconds);
    void openForUnit(int numberOfUnits);
  private:
    Servo s;
    int pin;
    int unit;
};
#endif
