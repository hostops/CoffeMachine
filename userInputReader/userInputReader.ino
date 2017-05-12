#include <LiquidCrystal.h>
#include "Button.h"
#include "Sugar.h"
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Button coffe1(A0);
Button coffe2(A1);
Button cacao(A2);
Button capuccino(A3);
Button whiteCoffe(A4);
Button coffeWithMilk(6);
Button coffeWithCacao(9);
Sugar sugar(7,8);
bool sugarF=false;
unsigned long m;

void setup() {
  m=millis();
  lcd.begin(16, 2);
  lcd.print("Pozdravljeni!");
  lcd.setCursor(0, 1);
  lcd.print("Dolocite sladkor");
  Serial.begin(9600);
}

void loop() {
  if(coffe1.read())sendData('A');
  if(coffe2.read())sendData('B');
  if(cacao.read())sendData('C');
  if(capuccino.read())sendData('D');
  if(whiteCoffe.read())sendData('E');
  if(coffeWithMilk.read())sendData('F');
  if(coffeWithCacao.read())sendData('G');
  
  if(millis()-m>2000&&sugarF){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Izberite napitek");
    sugarF=false;
  }
  if(sugar.isChanged()){
    sugarPrint();
    sugarF=true;
    m=millis();
  }
}
void sendData(char mode){
  Serial.write('S');
  Serial.write(mode);
  Serial.write(sugar.sugar);
  String t;
  switch(mode){
    case 'A': t="Kava 1"; break;
    case 'B': t="Kava 2"; break;
    case 'C': t="Kakav"; break;
    case 'D': t="Kapucino"; break;
    case 'E': t="Bela kava"; break;
    case 'F': t="Kava z mlekom"; break;
    case 'G': t="Cokoladna kava"; break;
  }
  byte p=0;
  while(Serial.read()!='E'){
    if(millis()-m>500){
      m=millis();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Priprava");
      for(byte i=0;i<p;i++)
        lcd.print(".");
      p=(p+1)%4;
      lcd.setCursor(0,1);
      lcd.print(t);
      m=millis();
    }
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Koncano!");
  lcd.setCursor(0,1);
  lcd.print("Postrezite si!");
  delay(5000);
  sugar.sugar=3;
  sugarF=false;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pozdravljeni!");
  lcd.setCursor(0, 1);
  lcd.print("Dolocite sladkor");
}
void sugarPrint(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sladkor");
  lcd.setCursor(0,1);
  for(byte i =0;i<sugar.sugar;i++)
    lcd.print("#");
}
