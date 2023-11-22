## t3 - klondike

Você deve implementar o jogo "klondike", também conhecido como "solitaire", **como descrito abaixo**.
Um exemplo desse jogo pode ser visto [aqui](https://www.solitr.com/klondike-turn-one).

### parte I

Implemente e teste as funções descritas abaixo.
O programa exemplo da aula 23 deve ser consultado para a definição dos tipos envolvidos e exemplos de implementação.

Algumas dessas funções não podem operar em certas ocasiões. Por exemplo, não é possível acessar a carta no topo de uma pilha vazia; não é possível incluir mais cartas do que cabem em uma pilha. Você deve identificar essas situações e abortar a execução do programa, usando `assert`, que fica disponível com a inclusão de `assert.h`. Por exemplo, no início da função que remove uma carta do topo da pilha apontada por `p` deve ter algo como
```c
   assert(!pilha_vazia(p));
```
que vai chamar a função pilha_vazia, e se ela retornar true vai abortar o programa.

Altere o tipo pilha fornecido, para que contenha também o número de cartas fechadas na pilha. Uma pilha é constituída de 0 ou mais cartas fechadas no início e 0 ou mais cartas abertas no topo.

As funções a implementar para a parte I (essas funções não dependem da forma de funcionamento do jogo):

| funcionalidade            | argumentos            | retorno
| :--- | :--- | :---
| diz se uma pilha está vazia | `pilha_t *` | `bool` (`true` se vazia) 
| empilha uma carta | `pilha_t *`, `carta_t` | `void`
| retorna o topo | `pilha_t *` | `carta_t`
| remove o topo | `pilha_t *` | carta_t
| move cartas entre pilhas (1) | `pilha_t *`, `pilha_t *`, `int` | `void`
| abre a carta no topo da pilha | `pilha_t *` | `void`
| fecha todas as cartas da pilha | `pilha_t *` | `void`
| descrição da carta (2) | `carta_t`, `char *` | `void`

(1) o inteiro é o número de cartas a mover. Elas são movidar do topo da pilha de origem para o topo da pilha de destino. As cartas passadas devem ficar abertas na pilha de destino, mesmo que estejam fechadas na pilha de origem. As cartas devem permanecer na mesma ordem: a carta que estava no topo na pilha de origem deve ficar no topo na pilha de destino. Deve testar e abortar (com assert) se há cartas suficientes na origem e espaço no destino.

(2) o vetor de char apontado deve ser preenchido com uma string com a descrição da carta (como o que é escrito pela função desenha_carta do exemplo).

### parte II

Faça a parte I enquanto aguarda...

### parte III

Implemente as funções abaixo que serão usadas para o desenho das cartas na tela.

Para implementá-las, podem ser usadas as funções de tela.h e tela.c do t2, ou as funções de telag.h e telag.c.

Os 2 inteiros que todas as funcões recebem são linha e coluna na tela (ou coordenadas y e x no caso de tela gráfica) onde o desenho deve iniciar.

| funcionalidade            | argumentos            | retorno
| :--- | :--- | :---
| desenho de local (1) | `int`, `int` | `void`
| desenho de carta fechada | `int`, `int` | `void`
| desenho de carta aberta | `int`, `int`, `carta_t` | `void`
| desenho de pilha fechada (2) | `int`, `int`, `pilha_t *` | `void`
| desenho de pilha aberta (3) | `int`, `int`, `pilha_t *` | `void`

(1) os 2 inteiros são linha e coluna na tela onde o desenho deve iniciar. Faz um desenho que representa um local onde uma carta pode ser posicionada.

(2) Desenha somente a carta que está no topo da pilha, levando em consideração que a pilha pode estar vazia e a carta pode estar aberta ou fechada. Deve usar uma das funções anteriores para desenhar.

(3) Deve desenhar cada carta da pilha, a primeira carta na posição recebida, e cada carta seguinte em uma posição um pouco abaixo, parcialmente sobre a anterior, de forma que se consiga distinguir cada carta. A última carta desenhada é a carta do topo da pilha. Deve ser levado em consideração as cartas fechadas e abertas, e a possibilidade de a pilha estar vazia. Deve usar as funções anteriores para desenhar.

