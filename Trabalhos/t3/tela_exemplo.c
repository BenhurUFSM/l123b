// Programa de exemplo de uso de tela.h e tela.c e tecla.h e tecla.c
//
// Necessita os arquivos tela_exemplo.c (este), tela.h, tela.c, tecla.h, tecla.c
//
// para compilar este programa manualmente em linux:
// gcc -Wall -o exemplo tela_exemplo.c tela.c tecla.c
//

#include "tela.h"
#include "tecla.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// desenha a borda de um retângulo
void borda_retangulo(int li, int ci, int nl, int nc)
{
  int lin = li;
  int col = ci;
  tela_lincol(lin, col);
  printf("\u256d");
  for (int i = 0; i < nc - 2; i++) {
    printf("\u2500");
  }
  printf("\u256e");
  lin++;
  while (lin < li + nl - 1) {
    tela_lincol(lin, ci);
    printf("\u2502");
    tela_lincol(lin, ci + nc - 1);
    printf("\u2502");
    lin++;
  }
  tela_lincol(lin, col);
  printf("\u2570");
  for (int i = 0; i < nc - 2; i++) {
    printf("\u2500");
  }
  printf("\u256f");
}

// preenche um retângulo com os caracteres em s
void retangulo(int li, int ci, int nl, int nc, char *s)
{
  for (int lin = li; lin < li + nl; lin++) {
    tela_lincol(lin, ci);
    for (int col = ci; col < ci + nc; col++) {
      printf("%s", s);
    }
  }
}

// retorna o número de colunas usadas para imprimir a string
// é o tamanho da string menos os caracteres de continuação utf8
int nchar(char *s)
{
  // caracteres com código binário entre 0b10000000 e 0b10111111 são de
  // continuação em utf8
  char ci = 0b10000000;
  char cf = 0b10111111;
  int t = strlen(s);
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] >= ci && s[i] <= cf) {
      t--;
    }
  }
  return t;
}

// desenha o texto em txt de forma que ele termine em lin, col
void texto_esq(int lin, int col, char *txt)
{
  int col_ini = col - nchar(txt) + 1;
  tela_lincol(lin, col_ini);
  printf("%s", txt);
}

// A função principal
int main(void)
{
  // inicializa a tela gráfica
  tela_ini();
  tecla_ini();

  char tec = 'x';
  int lin = 12;
  int col = 30;

  double inicio = tela_relogio();
  // laço principal por 10 segundos
  while (true) {
    double tempo = tela_relogio() - inicio;
    if (tempo >= 10) break;

    tela_limpa();
    // desenha um quadrado no contorno da janela
    tela_cor_letra(255, 50, 200);
    borda_retangulo(1, 1, tela_nlin() - 1, tela_ncol());

    tela_cor_letra(30, 135, 47);
    borda_retangulo(lin, col, 7, 8);
    retangulo(lin + 1, col + 1, 5, 6, "\u2592");
    
    // escreve o valor do relógio no canto da tela
    char txt[100];
    sprintf(txt, "\u2660\u2663\u2665\u2666[%d]%.1f", tec, tempo);
    tela_cor_letra(0, 200, 200);
    texto_esq(tela_nlin() - 2, tela_ncol() - 2, txt);

    char c = tecla_le_char();
    switch (c) {
      case 'w': lin--; break;
      case 'a': col--; break;
      case 's': lin++; break;
      case 'd': col++; break;
    }
    if (c) tec = c;
    // faz aparecer na tela o que foi desenhado
    tela_atualiza();
  }

  // encerra a tela gráfica
  tela_fim();
  tecla_fim();

  return 0;
}
