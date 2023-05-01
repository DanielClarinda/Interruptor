#ifndef INTERRUPTOR_H
#define INTERRUPTOR_H
#include <Arduino.h>

class Interruptor {
  private:
    byte _pin = 0;
    bool _currentState = LOW;
    bool _triggersWith = LOW;                    // Contact logic
    bool _lastSign = LOW;                        // deBounce control
    unsigned long _lastSignTime = 0;             // deBounce control
    unsigned int _filter = 0;                    // deBounce Time

  public:
    Interruptor(byte pin, byte inputMode, bool contactLogic, unsigned int deBounceTime);
    void checkChange(void (*callback)());
    bool isActivated();
};

#endif