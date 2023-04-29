#include "Interruptor.h"

Interruptor::Interruptor(byte pin, byte mode, bool colector, unsigned int deBounceTime) {
  _pino = pin;
  pinMode(pin, mode);

  _tempoConsiderarMudanca = deBounceTime;

  if(mode == INPUT) _estado = LOW;
  else if(mode == INPUT_PULLUP) _estado = HIGH;

  if(colector == NC) _estado = !_estado;                        // coletor normalmente fechado é lógica inversa

  _ultimoSinal = _estado;
  _acionaCom = !_estado;
}

void Interruptor::monitoraMudanca(void (*callback)()) {         // deve ser chamado continuamente no loop para atualizar o estado
  bool sinalAtual = digitalRead(_pino);

  if(sinalAtual != _ultimoSinal) {
    _ultimoSinal = sinalAtual;
    _tempoUltimoSinal = millis();
  }
  if((millis() - _tempoUltimoSinal) > _tempoConsiderarMudanca) {
    if(sinalAtual != _estado) {
      _estado = sinalAtual;
      callback();
    }
  }
}

bool Interruptor::estaAcionado() {
  if(_estado == _acionaCom) return true;
  else return false;
}