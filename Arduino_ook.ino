#include "HT16K33.h"
HT16K33  seg(0x70);
int COUNT_OF_VEHICLES=0;
int road=1;
const int IR_IN=D0;
const int IR_OUT=D3;
const int IR_LANE_CHANGE=D4;
const int LED_LANE_CHANGE=D5;


void setup() {
  
  pinMode(LED_LANE_CHANGE,OUTPUT);
  pinMode(IR_IN , INPUT);
  pinMode(IR_OUT , INPUT);
  pinMode(IR_LANE_CHANGE , INPUT);


  //For 4 digit seven segment display
  
  seg.begin();     
  Wire.setClock(100000);
  seg.displayOn();
  seg.setDigits(4);
  seg.displayTest(6);
  seg.displayOff();
  delay(1000);
  seg.displayOn();
  seg.displayColon(false);
  
}

void loop() {
 
  if (digitalRead(IR_IN)==HIGH)
  {
    COUNT_OF_VEHICLES+=1;
  }

  if (digitalRead(IR_OUT)==HIGH || digitalRead(IR_LANE_CHANGE)==HIGH  )
  {
    COUNT_OF_VEHICLES-=1;
  }
  if (COUNT_OF_VEHICLES>50)
  {
    digitalWrite(LED_LANE_CHANGE, HIGH);
  }


  //4 digit seven segment display

  seg.setDigits(1); 
  seg.displayInt(64);
  seg.brightness(15);       
  
}
