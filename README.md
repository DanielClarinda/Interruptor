Desenvolvido por DACLA Automação
https://dacla-automacao.github.io/site/

Instagram
https://www.instagram.com/daclaautomacao/

Biblioteca para leitura de sinais de entradas digitais de Arduinos através de;
- Botões
- Sensores
- Micro-Switch
- Mosfet
- Transistores
- Reles
- etc.

Seja com a lógica de contato/coletor NO(Normalmente Aberto) ou NC(Normalmente fechado).

Construtor(byte pin, byte inputMode, bool contactLogic, unsigned int deBounceTime);
- pin           =   Entrada digital do arduino
- pinMode		    =   Modo do Resistor interno (INPUT ou INPUT_PULLUP)
- contactLogic  =   NO(Aberto) valor=0 ou NC(Fechado) valor=1
- deBounceTime	=   Filtro em ms para evitar o efeito Bouncing (Recomendado 15ms)

Métodos do objeto

void checkChange(void (*callback)(void));          // call on loop main
- Passar uma função callback sem argumentos e sem retorno.
- A função sempre será chamada caso considere uma mudança de estado lógico considerando o filtro deBounce (equivale ao CHANGE do attackInterrupt).
- Filtro deBounce difinido no contrutor.

isActivated();
- Retorna true or false do estado do objeto com base nas definições do construtor (nivel lógico da entrada, input mode e lógica do contato).

Tabela verdade
se definido (INPUT, NO)         =   _estado == HIGH acionado  / _estado == LOW desacionado;
se definido (INPUT, NC)         =   _estado == LOW acionado   / _estado == HIGH desacionado;
se definido (INPUT_PULLUP, NO)  =   _estado == LOW acionado   / _estado == HIGH desacionado;
se definido (INPUT_PULLUP, NC)  =   _estado == HIGH acionado  / _estado == LOW desacionado;
