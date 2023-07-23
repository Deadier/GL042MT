#ifndef GL042MT_h
#define GL042MT_h

#include "Arduino.h"

class GL042MT {
  public:
    GL042MT(int rxPin, int txPin);
    void begin();
    int readDistance();
  private:
    int _rxPin;
    int _txPin;
};

#endif
