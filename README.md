Desenvolvido por DACLA Automação - https://dacla-automacao.github.io/site/
Instagram - https://www.instagram.com/daclaautomacao/

Biblioteca para leitura de sinais de entradas digitais através de;
- Botões
- Sensores
- Micro-Switch
- Mosfet
- Transistores
- Reles
- etc.

Seja contato/coletor NO(Normalmente Aberto) ou NC(Normalmente fechado).

Construtor(byte pin, byte mode, bool colector, unsigned int deBounceTime);
- pin           =   Entrada digital do arduino
- mode		      =   Modo do Resistor interno (INPUT ou INPUT_PULLUP)
- colector	    =   NO(Aberto) valor=0 ou NC(Fechado) valor=1
- deBounceTime	=   Tempo em ms para evitar o efeito Bouncing (Recomendado 15ms)

Métodos do obbjeto

void monitoraMudanca(void (*callback)());          // deve ser chamado continuamente no loop para atualizar o estado do objeto
- Passar uma função callback sem argumentos e que não retorna nada.
- A função sempre será chamada quando houver uma mudança de nivel lógico (equivale ao CHANGE do attackInterrupt).
- Filtro deBounce difinido no contrutor.

estaAcionado();
- Retorna true or false do estado do objeto com base nas definições do construtor (nivel lógico da entrada, input mode e lógica do contato).

Tabela verdade
se definido (INPUT, NO)         =   _estado == HIGH acionado  / _estado == LOW desacionado;
se definido (INPUT, NC)         =   _estado == LOW acionado   / _estado == HIGH desacionado;
se definido (INPUT_PULLUP, NO)  =   _estado == LOW acionado   / _estado == HIGH desacionado;
se definido (INPUT_PULLUP, NC)  =   _estado == HIGH acionado  / _estado == LOW desacionado;
