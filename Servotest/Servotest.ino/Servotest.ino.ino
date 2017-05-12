#include "Addition.h"
#include "Servo.h"
Addition a(3);
void setup() {
  a.start();
}

void loop() {
  a.open();
  delay(500);
  a.close();
  delay(500);
}
