#include <Servo.h>
/*define pins*/
#define heightPin A1
#define weightPin A0
#define monneySPin 2
/*static variables*/
int pheight;
int pweight;
Servo monneyS;
/*code*/
void setup() {
  Serial.begin(9600);
  pheight = analogRead(heightPin);
  pweight = analogRead(weightPin);
  monneyS.attach(monneySPin);
}

void loop() {
  /*get max values*/
  int cweight = analogRead(weightPin);
  if (cweight > pweight+10) { //start
    unsigned long m = millis();
    while (millis() - m < 1000) { //check for one second
      cweight = analogRead(weightPin);
      if (cweight > pweight)
        pweight = cweight;
    }
    /*values*/
    int height = analogRead(heightPin);
    int weight = pweight;
    Serial.println("weight\t|height");
    Serial.print(weight);
    Serial.print("\t|");
    Serial.println(height);
    if(weight>505&&weight<515&&height>490&&height<500){
      Serial.println("to je 20 centov");
      }
    pweight = analogRead(weightPin);
    monneyS.write(136);
    delay(100);
    monneyS.write(115);
    delay(100);

  }
}
