#include "rgb_lcd.h";

int sensorPin1 = A0;
int sensorValue1 = 0;
int sensorPin2 = A1;
int sensorValue2 = 0;

rgb_lcd lcd;

void setup() { 
   Serial.begin(9600);
   lcd.begin(16,2);
}

void loop(){
   lcd.setRGB(102, 0, 102);
   sensorValue1 = analogRead(sensorPin1);
   sensorValue2 = analogRead(sensorPin2);

   lcd.clear();
   lcd.setCursor(0,0);
   if(sensorValue1 > 850 && sensorValue2 > 850) {
      // First Parking Empty and Second Parking Empty
      char toPrint[100] = "A2 & B1 Vacant      ";
      Serial.println(toPrint);
      lcd.println(toPrint);
   }
   else if(sensorValue1 <= 850 && sensorValue2 <= 850) {
      // First Parking Full and Second Parking Full
      char toPrint[100] = "No Parking      ";
      Serial.println(toPrint);
      lcd.println(toPrint);
   }
   else if(sensorValue1 > 850 && sensorValue2 <= 850) {
      // First Parking Empty and Second Parking Full
      char toPrint[100] = "Park in A2--->>> ";
      Serial.println(toPrint);
      lcd.println(toPrint);
   }
   else if(sensorValue1 <= 850 && sensorValue2 > 850) {
      // First Parking Full and Second Parking Empty
      char toPrint[100] = "Park in B1--->>> ";
      Serial.println(toPrint);
      lcd.println(toPrint);
   }
   delay(4000);
}
