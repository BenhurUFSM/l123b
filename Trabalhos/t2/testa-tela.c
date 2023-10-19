#include "tela.h"
#include "tecla.h"

#include <stdlib.h>
#include <stdio.h>

void aleat(int *r, int *g, int *b)
{
  *r = rand() % 256;
  *g = rand() % 256;
  *b = rand() % 256;
}

int main()
{
  tela_ini();
  tecla_ini();

  int r, g, b;
  aleat(&r, &g, &b);
  char c = '.';
  int t = 0;
  
  for (;;) {
    tela_limpa();
    for (int i = 0; i < tela_nlin() - 1; i++) {
      tela_cor_normal();
      for (int j = 0; j < tela_ncol() - 1; j++) {
        if (j > t) {
          tela_cor_letra(r, g, b);
        }
        putchar(c);
      }
      putchar('\n');
    }
    t++;
    char nc = tecla_le_char();
    if (nc == '\n') break;
    if (nc != '\0') {
      c = nc;
      aleat(&r, &g, &b);
      t = 0;
    }

  }


  tecla_fim();
  tela_fim();
}
