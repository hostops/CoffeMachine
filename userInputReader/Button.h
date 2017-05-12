#ifndef Button_h
#define Button_h
class Button{
  public:
    Button(int pin);
    boolean read();
  private:
    int pin;
    int prev;
};
#endif
