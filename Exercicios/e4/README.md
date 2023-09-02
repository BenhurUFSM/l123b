## e4 - impressão de números em várias bases

Veja a descrição no final da aula 8.

Os arquivos `e4-e*` contêm exemplos de entrada para o programa, e os arquivos `e4-s*` a saída esperada para cada entrada. Na descrição do `e2` tem dicas de como usar esses arquivos.

O arquivo contendo o programa deve se chamar `e4-id.c` (substituindo `id` pelo que está na planilha: `e4-ana.c`, por exemplo), e deve ser formatado como descrito abaixo.

Após testar com os exemplos fornecidos, anexe o arquivo .c em um email com o assunto `l1-e4-ana` (se seu id for ana) e envie para o endereço da disciplina (benhur+l123b@inf.ufsm.br).

### Formatação do arquivo C

O Arquivo deve ser composto por (nessa ordem):
- 4 linhas de comentário, como mostrado no e1.
- uma linha em branco
- linhas de include
- uma linha em branco
- linhas com declarações das funções contidas no arquivo (exceto main), cada uma precedida por uma linha de comentário dizendo o que faz
- as definições das funções, cada uma precedida por uma linha em branco

Tudo o que está fora de chaves inicia na coluna 1.

As chaves do corpo de uma função são colocadas em linhas sozinhas, na primeira coluna.

As demais chaves (as que delimitam os comandos controlados por outro comando, como if):
- o `{` é o último caractere da linha que contém o comando, logo após o `)`, com um espaço entre eles;
- o `}` fica sozinho em uma linha, na mesma coluna em que inicia o comando a que as chaves pertencem (na mesma coluna do i do if, por exemplo).
- no caso da cláusula `else`, a chave que fecha o if e a que abre o else devem estar na mesma linha, separadas do else por um espaço:
  
   `} else {`
- no caso de ifs aninhados para implementar seleção múltipla, o else if deve ser colocado na mesma linha:
  
   `} else if (...) {`

  Todos os `}` de um conjunto de ifs aninhados são colocados na mesma coluna.

As linhas que estão dentro de chaves iniciam 2 colunas além da coluna que contém o fecha chaves correspondente (as linhas que contém comandos controlados por outro são indentadas 2 espaços a mais que o comando que as controla). Caso prefira, pode indentar com 4 espaços em vez de 2 (mas não mistura!).

O `(` de funções são encostados no nome da função (`printf("oi")` e não `printf ("oi");`).

O `(` de um comando é separado do comando por um espaço (`if (a < v)` e não `if(a < v)`).

Logo depois do `(` e logo antes do `)` não tem espaço (`if (a < v)` e não `if ( a < v )`).

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
     printf("O dobro de %d é %d\n", valor, posdobro(valor));
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
