### e2 - multiplicar 2 números

Seu trabalho é fazer um programa que pede 2 números inteiros ao usuário e imprime o valor desses dois números multiplicados entre si.
A execução do seu programa deve ter um comportamento como o abaixo:

```
Digite um valor: [10]
Digite outro valor: [20]
10 multiplicado por 20 vale 200.
```
O que está entre colchetes é o que é digitado pelo usuário do programa. Os colchetes servem para delimitar o que é digitado pelo usuário, não faz parte nem da entrada nem da saída do programa.

A saída do programa deve ser **exatamente** igual ao mostrado acima.

>  *Para ser exatamente mesmo, deveria ter sido formatado como abaixo, porque é o usuário que digita o enter, mas fica mais bonito como acima...*
   ```
   Digite um valor: [10
   ]Digite outro valor: [20
   ]10 multiplicado por 20 vale 200.
   ```

Chame seu programa de `e2-id.c`, com `id` igual ao que está na planilha de avaliação.

Para facilitar a auto verificação do comportamento do programa, foram disponibilizados três arquivos, `e2-e1`, `e2-e2` e `e2-e3` com 3 entradas para o programa, e outros três arquivos, `e2-s1`, `e2-s2` e `e2-s3` com as saídas esperadas para cada entrada.
Para verificar o programa, execute os seguintes comandos no linux (meu id é benhur):
```sh
gcc e2-benhur.c -o e2-benhur
./e2-benhur < e2-e1 > e2-x1
meld e2-s1 e2-x1
```
- o primeiro comando compila o programa;
- o segundo comando executa o programa, mas faz com que a entrada dele, em vez de ser lida do teclado, seja lida do arquivo `e2-e1`, e a saída dele, em vez de ser colocada na tela, seja colocada no arquivo `e2-x1`;
- o terceiro comando executa `meld`, um comparador de arquivos, que vai comparar a saída esperada (em `e2-s1`) com a saída efetiva (em `e2-x1`). Qualquer diferença entre esses arquivos deve ser investigada e o programa deve ser alterado.

Para que o programa meld funcione, deve ter sido instalado.

Pode usar outros programas de comparação, ou até comparar manualmente.

Tendo comparado ok com os 3 arquivos e estando satisfeito com o seu programa, anexe-o (só o arquivo "e2-id.c") em um mail para o endereço da disciplina, com o assunto "l1-e2-id" (id da tabela).

### Perguntas respondidas

- **P** E esses colchetes?
- **R** Os colchetes são só para separar o que são as coisas que o programa escreve e as que o usuário escreve.
O que tá dentro dos colchetes é escrito pelo usuário, e o que está fora é escrito pelo programa. Os colchetes
não são escritos por ninguém, eles não existem.

- **P** Gostaria que o senhor me explicasse como fazer a segunda parte de verificação do arquivo com o meld, pois não consegui realizar o procedimento pelo o mesmo.
- **R** Normalmente, a execução do teu programa seria:
  ```sh
  ./e2-id
  ```
  e então o programa apresenta a saída dele e tu digita a entrada.

  A forma de fazer o teste com os arquivos é, em vez de executar dessa forma, executar, para o primeiro conjunto de arquivos, assim:
  ```sh
  ./e2-id < e2-e1 > e2-x1
  ```
  executando dessa forma, o que o programa escrever vai ser colocado no arquivo `e2-x1` e não na tela; e quando o programa ler alguma coisa, em vez de esperar digitar no teclado, pega no arquivo `e2-e1`.
  O programa vai executar até terminar sem aparecer nada na tela e sem parar para digitar alguma coisa.

  No arquivo `e2-s1` eu coloquei qual seria a saída do programa quando a entrada for o conteúdo de `e2-e1`.
  No arquivo `e2-x1` o comando acima colocou a saída do teu programa quando a entrada foi o conteúdo de `e2-e1`.
  Esses 2 arquivos devem estar iguais, ou o teu programa não tem a saída igual ao que deveria ter.
  O programa `meld` compara 2 arquivos, e diz se são iguais ou onde estão as diferenças.
  Executa assim:
  ```
  meld e2-s1 e2-x1
  ```
  Para o segundo conjunto, substitui `e2-e1`, `e2-x1` e `e2-s1` por `e2-e2`, `e2-x2` e `e2-s2`.
  
