## E1 - Oi, mundo

É uma tradição que o primeiro programa escrito em uma novo linguagem de programação seja um que escreve uma mensagem do oi no terminal.

Abra um terminal.
Ele vai ser nossa interface com o computador.
Cada linha que se escreve no terminal (e termina com um enter) é um pedido para executar um comando.
Nosso programa é um texto escrito na linguagem de programação C. 
Por convenção, o nome de um arquivo que contém um programa em C termina em `.c`. 
Vamos chamar nosso arquivo de "e1.c".
Precisamos executar um editor de textos para editar esse arquivo.
Entre com o comando abaixo no terminal. Ele pede para executar o programa "nano", um editor de textos simples, para editar o arquivo "e1.c".
```sh
nano e1.c
```
Tem que ser em minúsculas, tem que ter espaço entre "nano" e "e1.c", não pode ter espaço no meio de "nano" ou de "e1.c", tem que terminar com enter.

Com o nano em execução, digite o texto abaixo:

```c
// l123b - e1
// programa para dizer oi
// coloque seu nome aqui
// coloque a data aqui, no formato aaaa-mm-dd

#include <stdio.h>

int main()
{
  printf("Oi, mundo!");
}
```

Grave seu arquivo, com o comando `^O` (no nano isso quer dizer que tem que teclar a tecla `o` enquanto segura a tecla `ctrl`), ele vai pedir confirmação. Saia do nano com `^X`. Dá para sair direto, se o arquivo não tiver sido gravado o nano pergunta se é para gravar.

De volta ao terminal, precisamos compilar nosso programa. Vamos executar o `gcc` para isso, dizendo para ele compilar o arquivo "e1.c" e gravar o programa executável no arquivo "e1", com o comando:
```sh
gcc e1.c -o e1
```
Se o gcc não encontrar erros, ele não diz nada, e o nosso executável está pronto.
Se disser alguma coisa, é porque não gostou de algum aspecto do programa. 
Nesse caso, o arquivo deve ser alterado, deve ter algo que não foi digitado corretamente -- volte para o nano.

Para executar o programa resultante, digite no terminal:
```sh
./e1
```
O programa deve executar, e imprimir a mensagem.

Se não deu tudo certo, pede ajuda. Só siga se tiver OK.

Altere o programa para que imprima uma segunda linha, com a mensagem "Sou o e1.".

Tem que imprimir um caractere especial para pular para a linha seguinte (representado por `\n`).

Altere novamente o programa, para imprimir:

Um ratinho:
```
<:3)~~~
```
Um gatinho:
```
=^..^=
```
Um ratão:
```
 _   _
(_)_(_)
 (o o)
==\o/==
```
Um gatão:
```
 /\_/\
( o.o )
 > ^ <
```

Altere novamente o programa, para que cada desenho seja feito por uma função diferente.
Faça a função main chamar cada uma das outras, imprimindo nosso conjunto de figurinhas. Para ficar mais legível, coloque uma linha em branco separando um desenho do outro.

Envie esse último programa. Anexe-o a um mail e envie para o mail do professor, com o assunto "e1-l1-fulano", substituindo "fulano" pelo seu nome (ou nome e sobrenome se não for único na chamada).
Não esquece os comentários (linhas que iniciam com //), veja o início desta página.

#### Exemplos

Abaixo estão dois exemplos de arquivos recebidos.
Será que você consegue extrair alguma inspiração para seus próximos programas analisando as diferenças entre esses exemplos?

```c
// l123b - e1
// programa para dizer oi
// Nome Censurado
// 2023-08-16
#include <stdio.h>

//função que cria e imprime o ratinho
void ratinho()
{
  printf("\n");
  printf("<:3)~~~\n");
  printf("\n");
} 
//função que cria e imrpime o gatinho
void gatinho()
{
  printf("=^..^=\n");
  printf("\n");
}
//função que cria e imprime o ratão
void ratão()
{
  printf(" _   _\n");
  printf("(_)_(_)\n");
  printf(" (o o)\n");
  printf("==\\o/==\n");
  printf("\n");
}
//função que cria e imrpime o gatão
void gatão()
{
  printf(" /\\_/\\\n");
  printf("( o.o )\n");
  printf(" > ^ <\n");
  printf("\n");
}
int main()
{
  printf("Oi,\n");
  ratinho();    //chamando a função que cria o ratinho
  gatinho();    //chamando a função que cria o gatinho
  ratão(); /*chamando a função que cria o ratão*/
  gatão();  /*chamando a função que cria o gatão*/
  printf("mundo\n");
}
```
```c
#include <stdio.h> 

void gato();
void ratinho();
void gatinho();
void ratao();

int main()
{
    printf("inicio\n");
    gato();
    ratinho();
    ratao();
    gatinho();
    printf("fim/n");
    return 0;
}

void gato()
{
printf(" /\\_/\\ \n( o.o )\n >ˆ<\n");
}

void ratinho()
{
    printf("<:3--\n");
}

void gatinho()
{
    printf("=ˆ.ˆ=\n");
}

void ratao()
{
    printf("_   _\n (_)_(_)\n  (0 0)\n ==\\o/==\n");
}
```
