#ifndef Water_h
#define Water_h
class Water{
  public:
    Water(int pin, int unit);
    void open();
    void close();
    void openFor(int miliseconds);
    void openForUnit(int numberOfUnits);
  private:
    int pin;
    int unit;
};
#endif
