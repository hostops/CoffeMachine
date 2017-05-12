#include "Servo.h";
#include "Addition.h"
#include "Water.h"
/*define defaults*/
#define ms 500 //time default unit milliseconds
#define warmerPin 13
/*define pins*/
/*static variables*/
Water water(2,ms);
Addition sugar(3,250);
Addition milk(4, ms);
Addition coffe1(5, ms);
Addition coffe2(6, ms);
Addition capuccino(7, ms);
Addition cacao(8, ms);

/*code*/
void setup() {
  Serial.begin(9600);
  Serial.write(2);
  /*Attach servos*/
  sugar.start();
  coffe1.start();
  milk.start();
  coffe2.start();
  capuccino.start();
  cacao.start();
  pinMode(warmerPin,OUTPUT);
}

void loop() {
  //Control temperature
  float temp=(analogRead(A0)/1023.0)*500;
  if(temp>100)
    digitalWrite(warmerPin,0);
  else if(temp<95) 
    digitalWrite(warmerPin,1);
  /*start checking*/
  if(Serial.available()){
    if(Serial.read()=='S'){ //Start
      char mode;
      int sUnit;
      do{
        mode=Serial.read();
      }while(mode==-1);
      do{
        sUnit=(int)Serial.read();//sugar, from 1 to 5
      }while(sUnit==-1);
      /*make coffe*/
      Serial.print(mode);
      Serial.print(sUnit);
      switch(mode){
        case 'A': makeCoffe1(); break;
        case 'B': makeCoffe2(); break;
        case 'C': makeCacao(); break;
        case 'D': makeCapuccino(); break;
        case 'E': makeWhiteCoffe(); break;
        case 'F': makeCoffeWithMilk(); break;
        case 'G': makeCoffeWithCacao(); break;
      }
      /*sugar*/
      if(sUnit!=0){
        sugar.openForUnit(sUnit);
      }
        Serial.write('E');//end signal
    }
  }
}
/*recepts*/
void makeCoffe1(){
  coffe1.openForUnit(2);
  water.openForUnit(4);
}
void makeCoffe2(){
  coffe2.openForUnit(2);
  water.openForUnit(5);
}
void makeCacao(){
  cacao.openForUnit(2);
  milk.openForUnit(3);
  water.openForUnit(4);
}
void makeCapuccino(){
  capuccino.openForUnit(2);
  water.openForUnit(4);
}
void makeWhiteCoffe(){
  coffe1.openForUnit(2);
  milk.openForUnit(4);
  water.openForUnit(4);
}
void makeCoffeWithMilk(){
  coffe1.openForUnit(2);
  milk.openForUnit(2);
  water.openForUnit(4);
}
void makeCoffeWithCacao(){
  cacao.openForUnit(2);
  coffe1.openForUnit(2);
  milk.openForUnit(2);
  water.openForUnit(4);
}
