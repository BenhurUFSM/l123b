## t2 - digite as letras

### parte I

Altere o t1 para processar letras em vez de números:
- troque vetores de `int` por vetores de `char`
- o vetor de char irá conter uma string. O tamanho da string é definido por seu conteúdo e não pelo tamanho do vetor. As funções que não necessitam do tamanho do vetor devem ser alteradas para não receber esse tamanho como argumento.
- O sorteio de valores a colocar no vetor deve sortear letras minúsculas. O númere de letras a sortear deve ser aleatório, entre o mínimo de uma e o máximo que couber no vetor. As letras sorteadas devem formar uma string no vetor
- o nome de algumas funções deve ser trocado para refletir o fato de que não mais manipulam números.

### parte II

Altere novamente o programa. Agora não é necessário encontrar a letra dentro da string, o usuário deve digitar a primeira letra da string. Caso ele digite uma letra diferente, nada acontece.

Os arquivos `tecla.h` e `tecla.c` implementam uma forma de se ler uma letra por vez, sem que o programa precise esperar pelo `enter`. O arquivo `testa_tecla.c` exemplifica seu uso. Para compilar, deve-se informar ao compilador o nome dos dois `.c` que formarão o programa:
```
gcc -o teste_tecla teste_tecla.c tecla.c
```
Use essas funções no programa das letras.

#### Esclarecimentos

O objetivo das funções em `tecla.c` é realizar a entrada de caracteres do teclado sem precisar esperar pela digitação do `enter`.
São 3 funções: `tecla_ini`, `tecla_fim` e `tecla_le_char`.
Para usar essas funções:

- Tem que incluir `tecla.h`, colocando uma linha com `#include "tecla.h"` no início do programa.

- Tem que chamar a função `tecla_ini` no início do programa, para poder usar a função `tecla_le_char`.

- A função `tecla_ini` muda a forma como a entrada é processada, podendo confundir o funcionamento de outras funções de entrada. Por isso, não use outras funções de entrada após chamar `tecla_ini`.

- Antes de terminar o programa, chame `tecla_fim`, para reprogramar o processamento normal da entrada.

- A função `tecla_le_char` retorna o próximo caractere digitado, ou `'\0'` se nada tiver sido digitado.

- O programa deve estar preparado para receber `'\0'` como resposta de `tecla_le_char`.

### parte III

Altere novamente o programa. Agora tem um conjunto de palavras (um vetor de palavras, implementado em uma matriz de letras).
As várias palavras do vetor devem ser preenchidas chamando a função de sorteio para cada palavra.
O programa deve manter uma variável que representa a palavra selecionada (um índice no vetor de palavras).
Pode não existir nenhuma palavra selecionada.

Se existir uma palavra selecionada, o usuário deve digitar a primeira letra dessa palavra, que deve então ser removida da palavra.
Se o usuário digitar a última letra da palavra, ela deve ser retirada do vetor, e o programa passa a não ter uma palavra selecionada.

Se não existir palavra selecionada, a letra digitada pelo usuário será usada para selecionar uma das palavras que iniciam com essa letra (ou não selecionará nada se nenhuma palavra iniciar com a letra digitada).

Quando o vetor ficar vazio (o usuário digitou todas as palavras), o programa termina.

Após cada letra digitada, o programa deve imprimir todas as palavras do vetor. Se houver uma palavra selecionada, ela deve ser impressa por último.


### parte IV

Uso de banco de palavras.

O programa deve ser alterado para, em vez de montar palavras selecionando letras aleatórias, selecionar palavras aleatoriamente de um banco de palavras.
O banco de palavras deve ser lido de um arquivo, que contém uma palavra por linha.

É fornecido o arquivo `palavras`, que contém 920 palavras, a maior delas é "desenvolvimento".
Esse arquivo contém palavras acentuadas e palavras com letras maiúsculas, mas nosso programa só reconhece as 26 letras minúsculas. As letras maiúsculas devem ser convertidas para minúsculas. As palavras que não são constituídas só por letras sem acento devem ser ignoradas. O arquivo não deve ser alterado.

### parte V

Melhorias na interface

Os arquivos `tela.h` e `tela.c` implementam algumas funções que permitem um maior controle sobre a tela. Essas funções estão documentadas no arquivo `tela.h`, e tem um programa exemplo usando essas funções e as de `tecla.h` no arquivo `testa-tela.c`.

Use essas funções para melhorar a interface do programa:
- as palavras devem ser mostradas na parte superior da tela
- a palavra selecionada deve ser mostrada separada das demais, em uma cor diferente
- o tempo deve ser calculado usando a função `tela_relogio`
- o tempo restante deve ser mostrado na tela, em segundos, com um dígito depois da vírgula

### parte VI

Interface mais dinâmica

Cada palavra passa a ser mais independente. Associado a cada palavra, tem 3 valores aleatórios:
- posição horizontal, um número entre 0 e 100 (percentual da linha onde a palavra deve ser colocada)
- hora de ativação, um número entre 0 e 20 (número de segundos de jogo antes dos quais a palavra não está ativa)
- tempo para digitação, um número entre 5 e 30 (a palavra deve ser digitada dentro desse prao, depois de ativada)

Não precisa mais mostrar o tempo na tela.
Cada palavra é mostrada em uma posição que evidencia o prazo que tem para ela ser digitada, quanto menor o prazo, mais para baixo ela aparece.

A posição de uma palavra pode ser calculada assim:
- *coluna*: `(larg - tam) * pos / 100`
  - larg: largura da tela
  - tam: número de caracteres na palavra
  - pos: posição horizontal percentual da palavra
- *linha*: `l_ini + alt * t_ativa / t_dig`
  - l_ini: linha inicial onde aparecem palavras (se reservar alguma linha no topo da tela para outra coisa)
  - alt: número de linhas onde aparecem as palavras (altura da tela menos linhas usadas para outra coisa no topo e embaixo)
  - t_ativa: tempo que a palavra está ativa (data atual menos a hora de ativação da palavra)
  - t_dig: tempo para digitação da palavra
 
A palavra selecionada (se houver) deve ser desenhada por último, em uma cor diferente.

Só devem ser mostradas palavras ativas.

A partida termina quando todas as palavras forem digitadas (não podem restar palavras que ainda não foram ativadas) ou quando o prazo de alguma palavra estourar (o tempo de jogo for superior à hora de ativação mais o tempo de digitação da palavra).

**Dica**

Faça uma função para mostrar a tela, outra para processar a entrada.
A que mostra a tela só mostra a tela; a que processa a entrada só processa a entrada; nenhuma outra função além dessas deve mostrar algo na tela ou ler a entrada durante uma partida.

### parte VII (última)

Pontuação

O jogo deve calcular os pontos do jogador em uma partida, e manter em um arquivo as 3 maiores pontuações da história, junto com os 3 maiores pontuadores.
O número de pontos do jogador deve ser mostrado na tela durante a partida.

*Cálculo dos pontos*

Cada letra certa vale entre 1 e 100 pontos, dependendo do tempo entre essa letra e a última letra certa digitada (ou o início da partida, no caso da primeira letra). Se esse tempo for um segundo ou mais, a letra vale um ponto, e aumenta proporcionalmente conforme esse tempo diminui, valendo 100 pontos se o tempo for 0. Em outras palavras, a pontuação de uma letra certa é (`tl` é o tempo desde a letra certa anterior):
```  
   se tl >= 1
     1
   senão
     100 * (1 - tl)
```

Cada letra errada desconta 10 do número de pontos, sem deixar ficar negativo.

Ao final de uma partida, o programa deve mostrar os recordes, e se a pontuação atual fizer jus, pedir uma identificação ao usuário e alterar o recorde de acordo.

Depois de mostrar (e talvez alterar) os recordes, o programa deve perguntar ao usuário se gostaria de uma nova partida, e proceder de acordo com a resposta.

**Dica**

Leia os recordes à partir do arquivo no início do programa, mantenha em memória. No final de uma partida, se os recordes forem alterados, grave o arquivo. Faça uma função para ler o arquivo (que só é chamada uma vez no início de programa) e outra para gravar (que só é chamada no final de uma partida, se a pontuação for alta o suficiente)


#### Respostas a perguntas


1. Agora tem um conjunto de palavras (um vetor de palavras, implementado em uma matriz de letras). As várias palavras do vetor devem ser preenchidas chamando a função de sorteio para cada palavra. **Dúvidas**: Isso significa que cada linha vai conter uma palavra, correto? Quantas palavras e qual o tamanho máximo?

   Uma matriz de 10x10 char.

2. O programa deve manter uma variável que representa a palavra selecionada (um índice no vetor de palavras). Pode não existir nenhuma palavra selecionada.
   **Dúvidas**: É o usuário quem deve selecionar a palavra inicialmente digitando a letra inicial de uma das palavras? Caso a resposta da pergunta anterior seja sim, então o jogo só começa mesmo quando ele acertar uma letra inicial, nesse momento em que digita a letra inicial e seleciona uma palavra, já deve remover a letra inicial dela?

   O jogo começa sem palavra selecionada. O jogador digita uma letra, se
alguma palavra inicia com essa letra, o jogo seleciona essa palavra
(ou uma delas se houver mais de uma). O jogo passa então a ter uma
palavra selecionada. O tempo tá contando desde o início (tempo é para
a parte 4).
A letra que foi usada pra selecionar a palavra é removida da palavra.

3. Se existir uma palavra selecionada, o usuário deve digitar a primeira letra dessa palavra, que deve então ser removida da palavra. Se o usuário digitar a última letra da palavra, ela deve ser retirada do vetor, e o programa passa a não ter uma palavra selecionada.
   **Dúvidas**: O usuário digitar a última letra, no caso, seria a última letra restante da palavra, para removê-la do vetor? Por exemplo 'luiz', se a primeira letra digitada for 'z' devo remover a palavra ou somente após digitar todas as letras dela, l, u, i, z?

   O usuário deve sempre digitar a primeira letra da palavra selecionada.
Essa letra vai ser removida e a palavra vai ficar mais curta. Se a
primeira letra for a última, a palavra vai ficar vazia, e deve ser
removida, o vetor de palavras fica com uma palavra a menos.
A palavra 'luiz' vai ser selecionada quando for digitado 'l', e vira
'uiz'. Agora a única letra aceita é 'u', independentemente de quantas
outras palavras houver, porque tem uma palavra selecionada, e ela
continua sendo a selecionada até que seja toda digitada.

4. Quando o vetor ficar vazio (o usuário digitou todas as palavras), o programa termina.
   **Dúvida**: Mas aí ele continua tendo a opção de jogar novamente?

   O programa termina. Talvez na parte 4 tenha a opção de jogar de novo. Mmm, a parte 4 tá ficando muito grande, talvez tenha que ter 4 e 5. 

5. (Parte V) Não vai mais ter a apresentação do jogo dizendo pra digitar as letras das palavras, vai apenas aparecer as palavras na parte de cima?

   Isso. Se quiser uma tela inicial de explicação, sem problema.

6. (parte V) A palavra selecionada deve ser mostrada destacadamente, como no exemplo de testa-tela.c ou seja, retira-se ela da matriz e mostro apenas na parte de baixo ou mostrar como última palavra entre todas, fazendo parte da matriz, como nas versões anteriores?

   Tanto faz. O ponto é que seja fácil de identificar a palavra que se está digitando.
 
7. (Parte VI) O que seria ativação de uma palavra e palavras ativas?

   Palavras ativas são as que aparecem na tela. O sorteio das palavras é no início da partida, mas nem todas as palavras aparecem no início. Para cada palavra é sorteado também o momento a partir do qual a palavra vai aparecer (vai ser ativa). Enquanto esse momento não chega, é como se essa palavra não existisse (está inativa).
Na prática, é só não imprimir (nem considerar para ser selecionada) as palavras que têm o tempo de ativação posterior ao tempo atual.

8. (Parte VI) A ordem das palavras é quanto menor o tempo (depois de ativada) mais baixo na matriz ela fica, não preciso mostrar o tempo, mas como o jogador vai saber o tempo que falta? E como vou definir esse tempo pra deixar mais acima ou mais abaixo entre 5 e 30?

   Quanto mais perto está de estourar o tempo de uma palavra, mais baixo ela vai ser mostrada na tela. 
O jogador sabe do tempo que falta sem ter um número aparecendo porque se uma palavra chegar embaixo ele perde. 
O tempo de uma palavra também é sorteado junto com a palavra.
Para cada palavra são sorteadas aleatoriamente 3 coisas: qual a palavra, quando que ela vai ser ativada e quanto tempo depois de ativada ela pode permanecer sem ser digitada.

9. (Parte VI) alt: número de linhas onde aparecem as palavras (altura da tela menos linhas usadas para outra coisa no topo e embaixo). Então se a altura é 500, usei 5 linhas para outra coisa no topo antes das palavras e usei 6 linhas abaixo das palavras, alt = 500 - 11?

   A altura é em linhas, que é a liberdade que temos para posicionamento de uma palavra. A tela não vai ter 500 linhas (a não ser que tenha um monitor muito grande e excelente visão).
Então, se a tela tem 50 linhas e usou 11 para colocar outras coisas, sobram 39 linhas para mostrar as palavras. Aquelas que recém foram ativadas serão mostradas na linha bem de cima dessas 39, as que estiverem prestes a estourar o tempo aparecerão bem abaixo. Cada vez que a tela é desenhada, a posição de cada palavra é recalculada. Conforme o tempo vai passando, as palavras vão sendo mostradas mais para baixo.

10. (Parte III) Sugestão de algoritmo para implementar o laço principal de uma partida:
    ```
    marca a inexistência de palavra selecionada
    repita:
      se acabou o tempo, para de repetir
      se o usuário atingiu os objetivos, para de repetir
      desenha a tela
      lê uma tecla
      se não houver palavra selecionada:
        se alguma palavra iniciar com a letra digitada:
          faz a palavra selecionada ser essa palavra
      se houver palavra selecionada e a primeira letra dela for igual à letra digitada:
        remove a primeira letra da palavra selecionada
        se era a última letra da palavra selecionada:
          remove a palavra selecionada do vetor de palavras
          marca a inexistência de palavra selecionada
    ```
   Na implementação desse algoritmo, a parte de leitura e tratamento de uma tecla provavelmente seria implementada por uma função a parte, que por sua vez também seria provavelmente dividida em funções auxiliares.

11. (Parte IV) Sugestão de implementação da leitura de palavras do arquivo, com a implementação de uma função que adiciona uma palavra em um vetor de palavras (uma matriz):
    ```
    abre o arquivo
    repete:
      lê uma palavra do arquivo
      se a leitura falhou, para de repetir
      vê se a palavra serve
      se for o caso, adiciona a palavra na matriz
    fecha o arquivo
    ```
    A mesma função pode ser usada para copiar palavras selecionadas da matriz que contém todas as palavras para a matriz com as palavras de uma partida:
    ```
    repete tantas vezes:
      sorteia um número que é uma posição válida na matriz grande
      adiciona a palavra que tá nessa posição da matriz grande na matriz pequena
    ```

12.  Como usar as funções de tela.h (e tela.c)
- Desenha uma tela inteira por vez (não espalha printfs).
- De preferência, faz uma função para fazer todo o desenho da tela.
- Nessa função, primeiro chama tela_limpa(), depois desenha tudo o que quiser que apareça na tela, depois chama tela_atualiza().
