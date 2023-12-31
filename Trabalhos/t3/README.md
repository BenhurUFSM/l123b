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
| diz se uma pilha está cheia | `pilha_t *` | `bool` (`true` se cheia)
| empilha uma carta (5) | `pilha_t *`, `carta_t` | `void`
| retorna o topo | `pilha_t *` | `carta_t`
| remove o topo | `pilha_t *` | `carta_t`
| move cartas entre pilhas (1) | `pilha_t *`, `pilha_t *`, `int` | `void`
| abre a carta no topo da pilha | `pilha_t *` | `void`
| fecha todas as cartas da pilha | `pilha_t *` | `void`
| esvazia uma pilha | `pilha_t *` | `void`
| gera baralho inteiro (3) | `pilha_t *` | `void`
| embaralha as cartas em uma pilha | `pilha_t *` | `void`
| retorna o número de cartas em uma pilha | `pilha_t *` | `int`
| retorna o número de cartas fechadas em uma pilha | `pilha_t *` | `int`
| retorna o número de cartas abertas em uma pilha | `pilha_t *` | `int`
| retorna uma carta da pilha (4) | `pilha_t *`, `int`, `bool *` | `carta_t`
| cria uma carta | `valor_t`, `naipe_t` | `carta_t`
| retorna o naipe de uma carta | `carta_t` | `naipe_t`
| retorna o valor de uma carta | `carta_t` | `valor_t`
| retorna a cor de uma carta | `carta_t` | `cor_t`
| descrição de uma carta (2) | `carta_t`, `char *` | `void`
| compara duas cartas (`true` se iguais) | `carta_t`, `carta_t` | `bool`

(1) o inteiro é o número de cartas a mover. Elas são movidas do topo da pilha de origem para o topo da pilha de destino. As cartas passadas devem ficar abertas na pilha de destino, mesmo que estejam fechadas na pilha de origem. As cartas devem permanecer na mesma ordem: a carta que estava no topo na pilha de origem deve ficar no topo na pilha de destino. Deve testar e abortar (com assert) se há cartas suficientes na origem e espaço no destino.

(2) o vetor de char apontado deve ser preenchido com uma string com a descrição da carta (como o que é escrito pela função desenha_carta do exemplo).

(3) esvazia a pilha e insere nela as 52 cartas do baralho, em qualquer ordem.

(4) o inteiro é a posição da carta a retornar: com `n` cartas na pilha, a posição `0` é a da primeira carta da pilha (a que está embaixo de todas), `1` é da que está acima dela, `n-1` a da que está no topo; além disso, `-1` é a da que está no topo, `-2` a da que está abaixo dela, `-n` a da primeira. No ponteiro para `bool` deve ser colocado `true` se a carta estiver aberta e `false` se estiver fechada (a não ser que o ponteiro seja NULL, nesse caso deve ser ignorado). Deve usar `assert` para abortar com posição inválida.

(5) se a pilha estiver vazia, a carta deve ser colocada aberta; senão a carta deve ficar da mesma forma que a carta que está no topo da pilha (aberta ou fechada).

**Somente as funções da parte I podem acessar diretamente os campos das estruturas `carta_t` e `pilha_t`. As funções das demais partes devem usar as funções da parte I.**

### parte II

Funções de manipulação de cartas e pilhas de cartas de mais alto nível, mais próximas às necessidades do jogo. Essas funções **não devem** reimplementar funcionalidades existentes nas funções da parte I (devem chamar as funções).

Crie um tipo `jogo_t`, um registro que conterá os dados necessários para realizar uma partida.
Inicialmente, deve conter 13 pilhas: 
- o monte, que contém as cartas fechadas a serem distribuídas;
- o descarte, onde ficam as cartas do monte ao serem abertas;
- 4 pilhas de saída, onde são colocadas as cartas retiradas do jogo, em ordem e por naipe;
- 7 pilhas principais, onde acontecem as movimentações principais do jogo.

| funcionalidade            | argumentos            | retorno
| :--- | :--- | :---
| inicializa as pilhas do jogo (1) | `jogo_t *` | `void`
| verifica se pode mover para a saída (2) | `jogo_t *`, `int`, `carta_t` | `bool`
| verifica se pode mover para pilha de jogo (3) | `jogo_t *`, `int`, `carta_t` | `bool`
| verifica se pode mover tantas cartas de uma pilha de jogo (4) | `jogo_t *`, `int`, `int` | `bool`
| verifica se o jogador ganhou | `jogo_t *` | `bool`

(1) esvazia todas as pilhas, preenche o monte com o baralho inteiro (fechadas), embaralha, move cartas do monte para as pilhas principais (uma para a primeira, duas para a segunda, sete para a última), fecha todas as cartas exceto a do topo em cada pilha.

(2) é possível mover uma carta para uma pilha de saída se a pilha estiver vazia e a carta for um ás ou se a carta tiver o mesmo naipe da carta no topo da pilha e o valor imediatamente superior. O int (0 a 3) identifica a pilha.

(3) é possível mover uma carta para uma pilha de jogo se a pilha estiver vazia e a carta for um rei ou se a carta tiver a cor diferente da carta no topo da pilha e o valor imediatamente inferior. O int (0 a 6) identifica a pilha.

(4) só é possível mover cartas que estejam abertas.

### parte III

Funções que implementam as jogadas possíveis do jogo. Retornam `true` se a jogada foi bem sucedida e `false` se a jogada não pode ser realizada.
As funções das partes anteriores **devem** ser usadas na implementação destas funções.
As funções que movem cartas de uma pilha do jogo devem mover somente cartas abertas, e fazer com que a carta no topo da pilha esteja aberta após o movimento.

| funcionalidade            | argumentos            | retorno | jogada
| :--- | :--- | :--- | :---
| abre uma carta (1) | `jogo_t *` | `bool` | `mp` ou `m`
| recicla o descarte (2) | `jogo_t *` | `bool` | `pm` ou `p`
| move do descarte para uma saída | `jogo_t *`, `int` | `bool` | `pa` a `pd`
| move do descarte para uma pilha do jogo | `jogo_t *`, `int` | `bool` | `p1` a `p7`
| move de uma pilha do jogo para uma saída | `jogo_t *`, `int`, `int` | `bool` | `1a` a `7d`
| move de uma saída para uma pilha do jogo | `jogo_t *`, `int`, `int` | `bool` | `a1` a `d7`
| move tantas cartas de uma pilha do jogo para outra | `jogo_t *`, `int`, `int`, `int` | `bool` | função auxiliar
| move cartas de uma pilha do jogo para outra (3) | `jogo_t *`, `int`, `int` | `bool` | `17` a `71`
| faz uma jogada (4) | `jogo_t *`, `char *` | `bool` | função de entrada


(1) move a carta do topo do monte para o topo do descarte, aberta. A jogada não é possível se o monte estiver vazio.

(2) move todas as cartas do descarte para o monte, em ordem inversa (a do topo do descarte deve ficar no fundo do monte). As cartas do monte devem ficar fechadas. A jogada não é possível se o descarte tiver vazio ou se o monte não tiver vazio.

(3) a função deve descobrir quantas cartas devem ser movidas para que a jogada seja válida, a chamar a função anterior para realizar o movimento.

(4) chama uma das funções anteriores dependendo da string recebida (e retorna o valor retornado pela função). A string deve conter 2 caracteres (ou excepcionalmente 1), que identificam as 2 pilhas envolvidas na jogada. Se a string não estiver corretamente formatada ou se não corresponder a uma jogada válida, a função deve retornar `false`. As pilhas são identificadas pelos caracteres `m`, `p`, `a`-`d` e `1`-`7`, em maiúsculas ou minúsculas. Por exemplo, a string "5c" deve causar a chamada da função que move de uma pilha do jogo para uma saída, com argumentos 4 e 2. A string "m" deve ser tratada da mesma forma que "mp" e chamar a função que abre uma carta do monte para a pilha de descarte. A jogada pode ainda ser "f", que finaliza o jogo (coloque uma variável em jogo_t para sinalizar que o jogo deve ser terminado). Na coluna "jogada" na tabela acima está a string que esta função deve receber para chamar a função correspondente à linha da tabela.

### parte IV

Funções auxiliares para o desenho do jogo.

Para implementá-las, podem ser usadas as funções de tela.h e tela.c (tem um exemplo de uso em tela_exemplo.c), ou as funções de telag.h e telag.c (tem um exemplo de uso de telag em telag_exemplo.c, com um comentário no início sobre como compilar).
Use os arquivos do t3, eles foram alterados em relação ao t2.

Os 2 inteiros que todas as funcões recebem são linha e coluna na tela (ou coordenadas y e x no caso de tela gráfica) onde o desenho deve iniciar.

| funcionalidade            | argumentos            | retorno
| :--- | :--- | :---
| desenho de local (1) | `int`, `int` | `void`
| desenho de carta fechada | `int`, `int` | `void`
| desenho de carta aberta (5) | `int`, `int`, `carta_t` | `void`
| desenho de pilha fechada (2) | `int`, `int`, `pilha_t *` | `void`
| desenho de pilha aberta (3) | `int`, `int`, `pilha_t *` | `void`
| desenho compacto de pilha aberta (4) | `int`, `int`, `pilha_t *` | `void`

(1) os 2 inteiros são linha e coluna na tela onde o desenho deve iniciar. Faz um desenho que representa um local onde uma carta pode ser posicionada.

(2) Desenha somente a carta que está no topo da pilha, levando em consideração que a pilha pode estar vazia e a carta pode estar aberta ou fechada. **Deve usar uma das 3 funções de desenho anteriores para desenhar**.

(3) Deve desenhar cada carta da pilha, a primeira carta na posição recebida, e cada carta seguinte em uma posição um pouco abaixo, parcialmente sobre a anterior, de forma que se consiga distinguir cada carta. A última carta desenhada é a carta do topo da pilha. Deve ser levado em consideração as cartas fechadas e abertas, e a possibilidade de a pilha estar vazia. **Deve usar as funções anteriores para desenhar (local, carta fechada, carta aberta)**.

(4) Desenha a pilha de forma alternativa, ocupando menos espaço vertical. Por exemplo, pode desenhar uma só carta fechada com um número dentro indicando quantas tem, e a primeira e a última cartas abertas, com uma carta especial entre elas indicando o número de cartas abertas que não estão sendo representadas.

(5) A descrição da carta a imprimir deve ser obtida usando a função da parte I que fornece a descrição de uma carta.

### parte V

Cálculo de pontos.

Altere a estrutura jogo_t para conter os pontos, e o que mais for necessário para poder calcular os pontos como descrito abaixo.
Altere a função de inicialização da estrutura para zerar os pontos.
Altere as funções de movimentação para alterar os pontos:
- reciclagem dos descartes zera os pontos;
- movimentação do descarte para pilha de jogo dá 10 pontos mais bônus;
- abertura de carta na pilha de jogo dá 20 pontos mais bônus;
- carta colocada em pilha de saída dá 15 pontos;
- carta retirada de pilha de saída retira 15 pontos.

O bônus é um adicional de pontos para premiar o jogador rápido, que faz a jogada em menos de 7 segundos. É um percentual dos pontos ganhos na jogada, que pode varias entre 0 e 300%. Se demorar 7 segundos ou mais, o bônus é 0. Senão, o bônus é calculado de acordo com o tempo de duração da jogada (desde a jogada anterior):
```
bonus = (7 - tempo_da_jogada) / 7 * 3 * pontos_da_jogada
```

### parte VI

Desenho da tela.

Altere a estrutura `jogo_t`, para adicionar coordenadas para as 13 pilhas.
Pode adicionar mais dados, caso queira representar algum estado adicional do jogo (por exemplo, poderia ter uma variável que diz que a jogada anterior não foi aceita, e algo ser desenhado na tela para representar essa situação; pode ter uma variável com a string ainda não confirmada da jogada do usuário e essa string ser mostrada, a pilha identificada pela string ser desenhada de forma destacada, etc).

| funcionalidade            | argumentos            | retorno
| :--- | :--- | :---
| inicializar coordenadas (1) | `jogo_t *` | `void`
| desenho das pilhas (2) | `jogo_t *` | `void`
| desenho de extras (3) | `jogo_t *` | `void`
| desenho do fundo (3) | `jogo_t *` | `void`
| desenho da tela (4) | `jogo_t *` | `void`

(1) inicializa as coordenadas das pilhas, levando em conta o tamanho da tela.

(2) chama as funções da parte IV para desenhar as pilhas. Para as pilhas de jogo, pode chamar o desenho compacto ou não, dependendo do tamanho da pilha e do espaço disponível.

(3) desenha os adornos e decorações que achar interessante para que a tela fique mais atrativa. No mínimo tem que ter a identificação das pilhas e a pontuação.

(4) chama as funções que fazem o desenho do fundo, das pilhas, dos extras e a função que atualiza a tela, nessa ordem.

### parte VII

Entrada de dados.

Altere `jogo_t` para conter um vetor onde será colocada a string com o comando do usuário.

| funcionalidade            | argumentos            | retorno
| :--- | :--- | :---
| processa teclado (1) | `jogo_t *` | `void`

(1) lê uma tecla do teclado, monta a string de comando com essa tecla, processa os caracteres especiais '\b' (para apagar o último caractere) e '\n' (para finalizar o comando e chamar a função que executa um comando).

**PROMOÇÃO DE BLACK FRIDAY** Aproveite, o p7 tá com descontaço, só hoje!!!


### parte VIII

Fim de partida.

Deve ser mantido o registro de todas as pontuações feitas no jogo.
Esse registro deve ser mantido em um arquivo, em ordem crescente.
Como não se sabe quantas partidas serão jogadas, em memória esses dados serão mantidos em um vetor alocado dinamicamente.
Esse vetor deve ser inicializado a partir do arquivo no início do programa.
No final de uma partida, se ela foi terminada com vitória, o programa deve inserir a nova pontuação no vetor e regravar o arquivo.
A pontuação deve ser apresentada em uma tela final da partida, com a pontuação obtida no meio da tela, tantos valores anteriores quantos couberem (ou existirem) nas linhas anteriores e tantos valores posteriores quantos couberem (ou existirem) nas linhas posteriores. Cada valor precedido por sua posição no arquivo, o valor da última partida em destaque.

Por exemplo, a última partida obteve 511 pontos, ficando em 15° lugar, mostrado em uma tela de 5 linhas:
```
      13. 499
      14. 507
     >15. 511<
      16. 590
      17. 656
```

A primeira linha do arquivo contém o número de pontuações que o arquivo contém, seguido de uma pontuação por linha.

Em memória, as pontuações devem ser mantidas em uma estrutura que contém um inteiro com o número de pontuações e um ponteiro para uma região de memória alocada dinâmicamente, com as pontuações.

Para inserir uma nova pontuação, aloque uma região de memória onde caibam todas as pontuações anteriores mais a nova, copie as primeiras pontuações (as menores que a que está sendo inserida) da região antiga para a região nova, depois a pontuação nova, depois as pontuações restantes (que são maiores que a nova). Então, libere a memória antiga e atualize o ponteiro na estrutura para apontar para a nova região.

Esta parte é opcional.

### parte IX

Faça um programa para jogar klondike.
O programa deve usar as funções das partes anteriores.


## Respostas a perguntas

1. São geradas as 52 cartas em uma pilha só né, após isso é para embaralhar as 52 e só depois dividir entre as pilhas? Essas cartas são geradas na função "cria uma carta" ou ela serve para outra coisa?
  
   Tá misturando um monte de coisas. Tem uma função que preenche uma pilha com as 52 cartas. Essa função serve para colocar as 52 cartas em uma pilha, que ela recebe por argumento. Um programa pode fazer isso:
   ```c
   pilha_t p;
   // aqui não sei o que tem em p
   preenche_com_baralho_completo(&p);   // ou outro nome para a função que põe as 52 cartas
   // aqui sei que tem as 52 cartas em p
   ```
   Tem outra função que embaralha as cartas que estão em uma pilha que ela recebe por argumento. Por exemplo:
   ```c
   pilha_t p;
   esvazia_pilha(&p);
   empilha(&p, cria_carta(as, ouros));
   empilha(&p, cria_carta(3, copas));
   empilha(&p, cria_carta(rei, ouros));
   imprime_pilha(&p);  // deve aparecer as de ouros, 3 de copas e rei de ouros, nessa ordem
   embaralha(&p);
   imprime_pilha(&p);  // deve aparecer as de ouros, 3 de copas e rei de ouros, sei lá em que ordem
   ```
   Na parte II, essas funções vão ser usadas para inicializar as pilhas do jogo, mas na parte I, é só para implementar e testar as funções separadamente. O fato de na parte II elas serem usadas em um caso específico não muda o que elas devem fazer. A função que embaralha pode ser usada em um jogo de pife ou canastra, e nem saber disso...

1. As funções “diz se uma pilha está vazia” e “diz se uma pilha está cheia” usam o typedef pilha_t incialmente, porém, essas funções levariam em consideração as pilhas destino e origem apenas ou levaria em consideração as pilhas do jogo também? (que possuem 7 cartas) Se levar em consideração as pilhas do jogo eu devo incluir no pilha_t todas as pilhas ou criar separado um para as de “compra” e outra para as de jogo?

   O tipo `pilha_t` é usado para representar uma pilha de cartas. Qualquer pilha de cartas. No jogo, vão ser usadas 13 dessas pilhas para representar o estado do jogo. Em algum momento, talvez se precise saber se alguma dessas pilhas está cheia ou vazia. Nesse caso, essas funções serão chamadas, passando como argumento um ponteiro para a pilha que se quer saber se está cheia ou vazia. A função deve retornar true ou false se a pilha está vazia ou não, independentemente de qual pilha tenha sido passada para ela. O trecho abaixo deve imprimir "sim nao nao nao ":
   ```c
   pilha_t p;
   esvazia_pilha(&p);
   if (pilha_vazia(&p)) printf("sim "); else printf("nao ");
   if (pilha_cheia(&p)) printf("sim "); else printf("nao ");
   empilha(&p, cria_carta(as, ouros));
   if (pilha_vazia(&p)) printf("sim "); else printf("nao ");
   if (pilha_cheia(&p)) printf("sim "); else printf("nao ");
   ```
   
1. As descrição da função “empilha uma carta” diz sobre a carta permanecer fechada, não entendi muito bem como funciona essa função, seria apenas para abrir as cartas de origem para a destino? Acredito que isso seja a função de “move cartas entre pilhas”... Então iria checar se a carta pode ser empilhada em qualquer pilha??? Mas isso também esta na parte II então ...?

   A função "empilha uma carta" recebe um ponteiro para uma pilha e uma carta. A pilha deve ser alterada para conter, além das cartas que já tinha, essa nova carta, empilhada sobre as outras. Se a pilha estava vazia, essa passa a ser a única carta na pilha e deve ser registrada como estando aberta. Se a pilha não estava vazia, tinha pelo menos uma carta. A carta no topo da pilha estava aberta ou fechada. A nova carta, que é colocada sobre a carta do topo deve ficar aberta se a carta que estava no topo estava aberta e fechada se ela estava fechada. Por exemplo:
   ```c
   pilha_t p;
   esvazia_pilha(&p);  // agora não tem carta em p
   empilha(&p, cria_carta(as, ouros)); // agora tem um as de ouros (aberto) em p
   empilha(&p, cria_carta(3, copas)); // agora tem um as de ouros e um 3 de copas (ambos abertos) em p
   fecha_todas(&p); // agora tem um as de ouros e um 3 de copas (ambos fechados) em p
   abre_topo(&p); // agora tem um as de ouros (fechado) e um 3 de copas (aberto) em p
   empilha(&p, cria_carta(rei, ouros)); // agora tem um as de ouros (fechado), um 3 de copas (aberto) e um rei (aberto) em p
   ```

1. A função “fecha todas as cartas da pilha” é usada em que momento do jogo Quando as cartas da pilha de destino voltam para a origem? E ai entra a função “esvazia uma pilha"?

   A função de fechar as cartas pode ser usada no monte, do início de um jogo, nas pilhas de jogo, também no início, logo depois da distribuição. No início também tem que esvaziar as demais pilhas.

1. Para que serve a função "compara duas cartas"?

   No jogo, para nada.

   Mas para testar as funções, pode ser bastante útil:
   ```c
   pilha_t p;
   esvazia_pilha(&p);
   carta_t c1 =  cria_carta(as, ouros);
   carta_t c2 =  cria_carta(rei, ouros);
   empilha(&p, c2);
   empilha(&p, c2);
   empilha(&p, c1);
   assert(iguais(remove_topo(&p), c1)); 
   assert(iguais(remove_topo(&p), c2));
   assert(iguais(remove_topo(&p), c2));
   assert(pilha_vazia(&p));
   ```

1. Pode ter mais ajuda?

   Foi incluído um arquivo com exemplos de teste para a parte I.

1. Não entendi o que seria testar quantas precisa mover para que a jogada seja válida, pode me explicar melhor?

   Por exemplo, suponha que:
   - a pilha 1 está vazia
   - a pilha 2 tem 1 carta fechada e um Kp, Qv
   - a pilha 3 tem 2 cartas fechadas e Jp, 10v, 9p
   - a pilha 4 tem 2 cartas fechadas e 9p, 8v, 7p, 6v
   - a pilha 5 tem 8p, 7v
   - as outras não sei o que tem

   Algumas jogadas possíveis:
   - se a jogada for "21", tem que mover 2 cartas para que a jogada seja válida.
   - se a jogada for "31", não tem jogada válida.
   - se a jogada for "32", tem que mover 3 cartas para que seja válida.
   - se a jogada for "43", tem que mover 3 cartas para que seja válida.
   - nenhuma outra jogada é válida entre as pilhas 1 e 5.

   Se a função "move cartas de uma pilha do jogo para outra" for chamada com os argumentos 3 e 2, para mover cartas da pilha 3 para a pilha 2, ela deve chamar a função "move tantas cartas de uma pilha do jogo para outra" com os argumentos 3, 2 e 3, para mover, da pilha 3 para a pilha 2, 3 cartas.

   Para descobrir quantas cartas mover, ela pode analisar o que tem nas pilhas, ou pode chamar "move tantas cartas de uma pilha do jogo para outra" com 3,2,1, depois com 3,2,2 etc, até que dê true ou que não seja possível movimentar tantas cartas, coisa que a função pode descobrir chamando "verifica se pode mover tantas cartas de uma pilha de jogo".

1. Não entendi a parte 3 do trabalho, o que são aquelas jogadas?

   As funções da parte III são as funções que implementam as jogadas que são possíveis no jogo.
Uma jogada move cartas de uma pilha para outra.
São 7 tipos de jogadas permitidas, de acordo com a pilha origem e a pilha destino da jogada.
Tem uma função para cada uma dessas possíveis jogadas.
A jogada mais complicada é a que move cartas de uma para outra das pilhas centrais do jogo. Para essa jogada, tem 2 funções. A primeira a ser executada recebe como argumento a pilha de origem e a pilha de destino; ela verifica quantas cartas devem ser movidas e chama a função auxiliar para mover as cartas.

   Tem também uma função geral, que serve para selecionar qual das outras funções vai ser chamada, dependendo de uma string que ela recebe, que identifica a pilha de origem e a pilha de destino. É essa a função que vai ser chamada quando o jogador fizer uma jogada. A forma do jogador jogar é digitando 2 caracteres, que identificam a pilha origem e a pilha destino. Esses caracteres são colocados em uma string que é passada para essa função "faz uma jogada". 

   A coluna "jogada" da tabela identifica o que tem que ter na string de comando para que a função "faz uma jogada" deva chamar a função que está nessa linha da tabela. Se a string for recebida por "faz uma jogada" for "mp", a função "faz uma jogada" deve chamar a função "abre uma carta"; se a string for "c6", deve chamar "move de uma saída para uma pilha do jogo", com argumentos 2 e 5 (da pilha de saída 2 (as pilhas abcd têm os números 0123, como posições de um vetor) para a pilha do jogo 5 (as pilhas 1234567 têm números 0123456)).

1. Poderia me explicar a função faz uma jogada na parte 3 do trabalho, eu não consegui entender bem a explicação que está no github

   O jogo tem 13 pilhas:
   - o monte de cartas;
   - a pilha de descarte;
   - 4 pilhas de saída;
   - 7 pilhas de jogo.

   As jogadas possíveis no jogo sempre movimentam uma ou mais cartas entre uma pilha de origem e uma pilha de saída. Para cada jogada possível, foi definida uma função na parte 3. São 7 possibilidades, correspondendo a 7 funções. Essas funções retornam um valor booleano, que indica se a jogada foi realizada ou não. Uma jogada não é realizada se o estado do jogo naquele momento não possibilita que a jogada seja feita sem infringir as regras do jogo.

   Para fazer uma jogada (o que deve causar a execução de uma dessas funções), o jogador deve identificar qual a pilha origem e qual a pilha destino. Cada uma das pilhas é identificada por um caractere diferente, então uma jogada pode ser codificada por 2 caracteres, o primeiro para representar a pilha de origem e o segundo para identificar a pilha de destino. Uma jogada é então representada por uma string que contém 2 caracteres.

   A função que lê um comando do jogador chama a função "faz uma jogada", passando para ela como argumento uma string que representa a jogada pretendida. A função "faz uma jogada" deve analisar essa string e chamar a função que realiza a jogada pretendida, com os argumentos requeridos. A função "faz uma jogada" deve retornar um bool que informa se a jogada foi realizada ou não (que é o valor retornado pela função que ela chamou para realizar a jogada ou false, se a string recebida não corresponde a uma jogada válida).

   Os caracteres usados para identificar as pilhas são:
   - 'm' ou 'M' - o monte de cartas
   - 'p' ou 'P' - a pilha de descartes
   - 'a' ou 'A' - a primeira pilha de saída
   - 'b', 'c', 'd' ou 'B', 'C', 'D' - as outras 3 pilhas de saída
   - '1' a '7' - as 7 pilhas de jogo

   Se a string recebida pela função "faz uma jogada" for "mp", significa que o jogador quer mover cartas, tendo como origem a pilha 'm' (o monte) e como destino a pilha 'p' (a pilha de descartes). Essa jogada é realizada pela função "abre uma carta". A função "faz uma jogada" deve então chamar a função "abre uma carta", e retornar o valor retornado por ela para quem a chamou.

   Se a string recebida pela função "faz uma jogada" for "5B", significa que o jogador quer mover cartas, tendo como origem a pilha '5' (a quinta pilha de jogo) e como destino a pilha 'b' (a segunda pilha de saída). Essa jogada é realizada pela função "move de uma pilha do jogo para uma saída". A função "faz uma jogada" deve então chamar a função "move de uma pilha do jogo para uma saída", passando para ela os valores 4 (a quinta pilha do jogo é a pilha de número 4) e 1 (a segunda pilha de saída é a de número 1) e retornar o valor retornado por ela para quem a chamou.

   Além das jogadas representadas por 2 caracteres, tem 3 jogadas que são representadas por uma string de um só caractere:
   - "m" ou "M": o mesmo que a jogada representada por "mp"
   - "p" ou "P": o mesmo que a jogada representada por "pm"
   - "f" ou "F": uma jogada especial, significa que o jogador quer abandonar a partida
