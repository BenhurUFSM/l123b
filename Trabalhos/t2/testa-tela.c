// testa-tela
// programa de exemplo de uso de funções em tela.h e tecla.h
// o usuário deve digitar o alfabeto no tempo fornecido
// para compilar:
//   gcc -o testa-tela testa-tela.c tela.c tecla.c

// inclui os arquivos que declaram as funções para uso da tela e teclado
// (olhe esses arquivos para conhecer as funções e saber o que fazem)
// (a implementação dessas funções está no respectivo arquivo .c)
#include "tela.h"
#include "tecla.h"

#include <stdlib.h>
#include <stdio.h>

// até quanto tempo se pode levar para digitar todas as letras
#define TEMPO_MAXIMO 20
// quantas letras existem
#define N_LETRAS 26

// funções auxiliares
// lê uma tecla, vê se é a correta e age de acordo
void processa_entrada(int *acertos);
// mostra o estado do programa para o usuário 
void desenha_tela(int acertos, double tempo_restante);
// mostra a mensagem de encerramento do programa, conforme o desempenho
void mensagem_final(int acertos, double tempo_restante);
// espera até que o usuário digite enter
void espera_enter();

int main()
{
  // chama as funções de inicialização da tela e do teclado
  tela_ini();
  tecla_ini();

  // quando o programa começou, para calcular o tempo restante
  double inicio = tela_relogio();
  double tempo_restante = TEMPO_MAXIMO;
  // quantas letras já foram acertadas
  int acertos = 0;

  while (tempo_restante > 0 && acertos < N_LETRAS) {
    tempo_restante = TEMPO_MAXIMO - (tela_relogio() - inicio);
    processa_entrada(&acertos);
    desenha_tela(acertos, tempo_restante);
  }

  mensagem_final(acertos, tempo_restante);
  espera_enter();

  // chama as funções de término da tela e do teclado
  tecla_fim();
  tela_fim();
}

void processa_entrada(int *acertos)
{
  char c = tecla_le_char();
  // se não foi digitado nada, não tem o que fazer
  if (c == '\0') return;

  // a próxima letra a digitar depende de quantas já foram acertadas
  char proxima_letra = *acertos + 'a';
  if (c == proxima_letra) {
    *acertos += 1;
  } else {
    // errou, não tem perdão
    *acertos = 0;
  }
}

void desenha_tela(int acertos, double tempo_restante)
{
  tela_limpa();
  int lin = tela_nlin() / 2 - 1;
  int col = tela_ncol() / 2 - 26 / 2;

  tela_lincol(lin, col);
  // desenha as letras já acertadas
  tela_cor_fundo(20, 200, 90);
  for (int i = 0; i < acertos; i++) {
    putchar('A' + i);
  }
  // desenha as letras que faltam
  tela_cor_normal();
  tela_cor_letra(150, 80, 50);
  for (int i = acertos; i < N_LETRAS; i++) {
    putchar('a' + i);
  }
  
  tela_lincol(lin + 2, col);
  tela_cor_normal();
  printf("Faltam %d letras, ", N_LETRAS - acertos);
  if (tempo_restante < 5) {
    tela_cor_letra(200, 0, 0);
  }
  printf("%.1f", tempo_restante);
  tela_cor_normal();
  printf(" segundos");

  tela_atualiza();
}

void mensagem_final(int acertos, double tempo_restante)
{
  int lin = tela_nlin() / 2 + 3;
  int col = tela_ncol() / 2;
  tela_lincol(lin, col);
  if (acertos < N_LETRAS) {
    printf("Acabou o tempo!");
  } else {
    printf("Parabéns!");
  }
  tela_lincol(lin+1, col);
  printf("Média de %.1f cps", acertos / (TEMPO_MAXIMO - tempo_restante));
  tela_atualiza();
}

void espera_enter()
{
  while (tecla_le_char() != '\n') {
    tela_lincol(tela_nlin() - 9, 0);
    unsigned int t = tela_relogio() * 10;
    for (int i = 0; i < tela_ncol(); i++) {
      int r = (t + i) % 512;
      int g = (t+t/7 + 512/3 + i) % 512;
      int b = (t+t/11 + 512/3*2 + i) % 512;
      if (r > 255) r = 511 - r;
      if (g > 255) g = 511 - g;
      if (b > 255) b = 511 - b;
      tela_cor_fundo(r, g, b);
      putchar(' ');
    }
    tela_atualiza();
  }
}
