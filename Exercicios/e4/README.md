## E4 - impressão de números em várias bases

Veja a descrição no final da aula 8.

Os arquivos e4-e* contêm exemplos de entrada para o programa, e os arquivos e4-s* a saída esperada para cada entrada. Pode usar o método explicado no e2 para usar esses arquivos.

O arquivo contendo o programa deve se chamar e4-id.c (substituindo id pelo que está na planilha, e4-ana.c, por exemplo), e deve ser formatado como descrito abaixo.

Após testar com os exemplos fornecidos, anexe o arquivo .c em um email com o assunto "l1-e4-ana" (se seu id for ana) e envie para o endereço da disciplina (benhur+l123b@inf.ufsm.br).

### Formatação do arquivo C

O Arquivo deve ser composto por (nessa ordem):
- 4 linhas de comentário, como mostrado no e1.
- uma linha em branco
- linhas de include
- uma linha em branco
- linhas com declarações das funções contidas no arquivo (exceto main), cada uma precedida por uma linha de comentário dizendo o que faz
- as definições das funções, cada uma precedida por uma linha em branco

As chaves do corpo de uma função são colocadas em linhas sozinhas, na primeira coluna.

As demais chaves (delimitam os comandos controlados por outro comando, como if):
- o `{` é o último caractere da linha que contém o comando, logo após o `)`, com um espaço entre eles;
- o `}` fica sozinho em uma linha, na mesma coluna em que inicia o comando a que as chaves pertencem (na mesma coluna do i do if, por exemplo).

As linhas que estão dentro de chaves iniciam 2 colunas além da coluna que contém o fecha chaves correspondente.

O `(` de funções são encostados no nome da função (`printf("oi")` e não `printf ("oi");`).

O `(` de um comando é separado do comando por um espaço (`if (a < v)` e não `if(a < v)`).

Depois do `(` e antes do `)` não tem espaço.

Operadores unários encostam no seu operando, mas são separados por um espaço de algo que não seja seu operando (`a * -b` e não `a * - b` nem `a*-b`).

Operadores binários têm um espaço de cada lado (`c = a * b` e não `c=a*b` nem `c= a *b`).

Vírgula e `;` tem um espaço depois (se não estiver no final da linha), mas não antes (`x = f(y, z);` e não `x = f(y,z);` nem `x = f(y ,z) ;`).

Exemplo de formatação:
```c
   // l123b - exemplo
   // programa para imprimir o dobro de um número
   // Benhur Stein
   // 2023-09-01

   #include <stdio.h>

   // solicita um número ao usuário; retorna o número digitado
   int le_numero();
   // retorna o dobro positivo do número recebido
   int posdobro(int num);

   int main()
   {
     int valor = le_numero();
     printf("O dobro de %d é %d\n", valor, dobro(valor));
   }

   int le_numero()
   {
     int num;
     printf("Digite um número: ");
     scanf("%d", &num);
     return num;
   }

   int posdobro(int num)
   {
     int r = num * 2;
     if (r < 0) {
       r = -r;
     }
     return r;
   }
```