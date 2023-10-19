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

*descrição ainda não disponível*


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
