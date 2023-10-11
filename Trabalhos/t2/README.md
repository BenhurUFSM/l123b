## t2 - digite as letras

### parte I

Altere o t1 para processar letras em vez de números:
- troque vetores de `int` por vetores de `char`
- o vetor de char irá conter uma string. O tamanho da string é definido por seu conteúdo e não pelo tamanho do vetor. As funções que não necessitam do tamanho do vetor devem ser alteradas para não receber esse tamanho como argumento.
- O sorteio de valores a colocar no vetor deve sortear letras minúsculas. O númere de letras a sortear deve ser aleatório, entre o mínimo de uma e o máximo que couber no vetor. As letras sorteadas devem formar uma string no vetor
- o nome de algumas funções deve ser trocado para refletir o fato de que não mais manipulam números.

### parte II

Altere novamente o programa. Agora não é necessário encontrar a letra dentro da string, o usuário deve digitar a primeira letra da string. Caso ele digite uma letra diferente, nada acontece.

Os arquivos `tecla.h` e tecla.c` implementam uma forma de se ler uma letra por vez, sem que o programa precise esperar pelo `enter`. O arquivo `testa_tecla.c` exemplifica seu uso. Para compilar, deve-se informar ao compilador o nome dos dois `.c` que formarão o programa:
```
gcc -o teste_tecla teste_tecla.c tecla.c
```
Use essas funções no programa das letras.

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

Melhorias na interface

*descrição ainda não disponível*
