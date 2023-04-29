#include <Interruptor.h>

#define pinReset 2

Interruptor Reset(pinReset, INPUT_PULLUP, NO, 15);          // pin, mode, collectorNormalState, deBounceTime

void setup() {
  Serial.begin(115200);
  while(!Serial) delay(10);
  Serial.println("Started");
}

void loop() {
  Reset.monitoraMudanca(comandoReset);
}

void comandoReset() {
  if(Reset.estaAcionado()) Serial.println("Acionado!");
  else Serial.println("Desacionado");
}