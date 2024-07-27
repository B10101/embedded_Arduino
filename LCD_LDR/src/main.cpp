#include <Arduino.h>
#include <LiquidCrystal.h>

int RS=7;int EN=8;int D4=9;int D5=10;int D6=11;int D7=12;int lightPin=A0;
int readval;
LiquidCrystal lcd_1(RS,EN,D4,D5,D6,D7);
void setup()
{
  lcd_1.begin(16, 2); 
  pinMode(A0, INPUT);
  lcd_1.begin(16,2); 
}
void loop(){
  readval = analogRead(A0);
  lcd_1.setCursor(0,0);
  lcd_1.print("Value: ");
  lcd_1.setCursor(0,1);
  lcd_1.print(readval);

}