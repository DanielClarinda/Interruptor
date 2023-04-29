#ifndef INTERRUPTOR_H
#define INTERRUPTOR_H

#include <Arduino.h>

#define NO 0                                    // lógica do sinal
#define NC 1                                    // lógica do sinal

class Interruptor {
  private:
    byte _pino = 0;
    bool _estado = LOW;
    bool _acionaCom = LOW;
    bool _ultimoSinal = LOW;                    // controle deBounce
    unsigned long _tempoUltimoSinal = 0;        // controle deBounce
    unsigned int _tempoConsiderarMudanca = 0;           // deBounceTime

  public:
    Interruptor(byte pin, byte mode, bool colector, unsigned int deBounceTime);
    void monitoraMudanca(void (*callback)());
    bool estaAcionado();
};

#endif