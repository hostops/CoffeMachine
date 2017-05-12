#ifndef Sugar_h
#define Sugar_h
#include "Button.h"
class Sugar{
  public:
    Sugar(int pin0,int pin1);
    boolean isChanged();
    byte sugar=3;
  private:
    Button add,rem;
    void sAdd();
    void sRemove();
};
#endif
