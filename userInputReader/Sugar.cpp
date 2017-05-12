#include "Arduino.h"
#include "Sugar.h"
#include "Button.h"
Sugar::Sugar(int pin0,int pin1):add(pin1),rem(pin0){}
boolean Sugar::isChanged(){
  if(add.read()){
    sAdd();
    return true;
  }
  if(rem.read()){
    sRemove();
    return true;
  }
  return false;
}
void Sugar::sAdd(){
  if(sugar<5)sugar++;
}
void Sugar::sRemove(){
  if(sugar>0)
    sugar--;
}
