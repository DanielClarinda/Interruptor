#include "Interruptor.h"

// Private properties
// byte _pin = 0;
// bool _currentState = LOW;
// bool _triggersWith = LOW;                    // Contact logic
// bool _lastSign = LOW;                        // deBounce control
// unsigned long _lastSignTime = 0;             // deBounce control
// unsigned int _filter = 0;                    // deBounce Time

Interruptor::Interruptor(byte pin, byte inputMode, bool contactLogic, unsigned int deBounceTime) {
  _pin = pin;
  pinMode(_pin, inputMode);
  _filter = deBounceTime;

  if(inputMode == INPUT) _currentState = LOW;
  else if(inputMode == INPUT_PULLUP) _currentState = HIGH;
  
  if(contactLogic == 1) _currentState = !_currentState;     // 0 = NO(NormalyOpen) / 1 = NC(NormalyClosed)
  // reset properties
  _lastSign = _currentState;
  _triggersWith = !_currentState;
}

void Interruptor::checkChange(void (*callback)(void)) {     // call on loop main
  bool signRead = digitalRead(_pin);

  if(signRead != _lastSign) {
    _lastSign = signRead;
    _lastSignTime = millis();
  }
  if((millis() - _lastSignTime) > _filter) {
    if(signRead != _currentState) {
      _currentState = signRead;
      callback();
    }
  }
}

bool Interruptor::isActivated() {
  if(_currentState == _triggersWith) return true;
  else return false;
}