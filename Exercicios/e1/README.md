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
