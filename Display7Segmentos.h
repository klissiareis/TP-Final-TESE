#include <Arduino.h>

class Display7Segmentos {
  private:
    int dataPin;
    int latchPin;
    int clockPin; 

    byte displayData[4];

  public:
    Display7Segmentos(int data, int latch, int clock) {
      dataPin = data;
      latchPin = latch;
      clockPin = clock;

      pinMode(dataPin, OUTPUT);
      pinMode(latchPin, OUTPUT);
      pinMode(clockPin, OUTPUT);

      clearAll();
    }

    void clear(int display) {
      if (display >= 0 && display < 4) {
        displayData[display] = 0;
        updateDisplay();
      }
    }

    void clearAll() {
      for (int i = 0; i < 4; i++) {
        displayData[i] = 0;
      }
      updateDisplay();
    }

    void digit(int display, byte value) {
      if (display >= 0 && display < 4) {
        displayData[display] = value;
        updateDisplay();
      }
    }

  private:
    void updateDisplay() {
      digitalWrite(latchPin, LOW);
      for (int i = 3; i >= 0; i--) {
        shiftOut(dataPin, clockPin, LSBFIRST, displayData[i]);
      }
      digitalWrite(latchPin, HIGH);
    }
};
