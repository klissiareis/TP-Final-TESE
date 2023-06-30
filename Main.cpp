#include <Arduino.h>
#include "Display7Segmentos.h"

const int dataPin = 2;
const int latchPin = 3;   
const int clockPin = 4;  

Display7Segmentos displays(dataPin, latchPin, clockPin);

void setup() {
}

void loop() {
  Sequencia();
}

void Sequencia() {
  byte value = 0x01;
  
  while (true) {
    for (int i = 0; i < 4; i++) {
      displays.digit(i, value);
      value = (value + 1) % 16;
    }
    
    delay(1000);
  }
}
