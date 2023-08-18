### e2 - multiplicar 2 números

Seu trabalho é fazer um programa que pede 2 números inteiros ao usuário e imprime o valor desses dois números multiplicados entre si.
A execução do seu programa deve ter um comportamento como o abaixo:

```
Digite um valor: [10]
Digite outro valor: [20]
10 multiplicado por 20 vale 200.
```
Os colchetes servem para delimitar o que é digitado pelo usuário do programa, não faz parte nem da entrada nem da saída do programa.

A saída do programa deve ser **exatamente** igual ao mostrado acima.

Chame seu programa de `e2-id.c`, com `id` igual ao que está na planilha de avaliação.

Para facilitar a auto verificação do comportamento do programa, foram disponibilizados três arquivos, `e2-e1`, `e2-e2` e `e2-e3` com 3 entradas para o programa, e outros três arquivos, `e2-s1`, `e2-s2` e `e2-s3` com as saídas esperadas para cada entrada.
Para verificar o programa, execute os seguintes comandos no linux (meu id é benhur):
```sh
gcc e2-benhur.c -o e2-benhur
./e2-benhur < e2-e1 > e2-x1
meld e2-s1 e2-x1
```
- o primeiro comando compila o programa;
- o segundo comando executa o programa, mas faz com que a entrada dele, em vez de ser lida do teclado, seja lida do arquivo `e2-e1`, e a saída dele, em vez de ser colocada na tela, seja colocada no arquivo e2-x1;
- o terceiro comando executa `meld`, um comparador de arquivos, que vai comparar a saída esperada (em `e2-s1`) com a saída efetiva (em `e2-x1`). Qualquer diferença entre esses arquivos deve ser investigada e o programa deve ser alterado.

Para que o programa meld funcione, deve ter sido instalado.

Pode usar outros programas de comparação, ou até comparar manualmente.

Tendo comparado ok com os 3 arquivos e estando satisfeito com o seu programa, anexe-o (só o arquivo e2-id.c) em um mail para o endereço da disciplina, com o assunto "l1-e2-id" (id da tabela)
