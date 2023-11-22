#include "tela.h"

// implementado usando
//   - sequências de escape ANSI para controlar a saída (cursor, cores)
//   - ioctl para descobrir o tamanho do terminal
//   - signal para ser sinalizado quando o terminal mudar de tamanho
//   - clock_gettime para obter o valor do relógio com boa resolução


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <signal.h>
#include <time.h>
#include <sys/ioctl.h>
#include <fcntl.h>


static void tela_altera_modo_saida(void)
{
  // faz com que os caracteres impressos sejam enviados para uma
  // região de memória antes de serem enviados à tela. Isso melhora
  // a qualidade de apresentação na tela
  setbuf(stdout, malloc(BUFSIZ));
}

void tela_mostra_cursor(bool mostra)
{
  if (mostra) {
    printf("\e[?25h");
  } else {
    printf("\e[?25l");
  }
}

static void tela_seleciona_tela_alternativa(bool alt)
{
  if (alt) {
    printf("\e[?1049h");
  } else {
    printf("\e[?1049l");
  }
}

static void tela_le_nlincol(int);

void tela_ini(void)
{
  tela_altera_modo_saida();
  tela_seleciona_tela_alternativa(true);
  // chama tela_le_nlincol se tela mudar de tamanho
  signal(SIGWINCH, tela_le_nlincol);
  tela_le_nlincol(0);
  tela_limpa();
  //tela_mostra_cursor(false);
}

void tela_fim(void)
{
  tela_limpa();
  tela_seleciona_tela_alternativa(false);
  tela_mostra_cursor(true);
}

void tela_atualiza(void)
{
  // envia os dados de saída memorizados para a tela
  fflush(stdout);
}

void tela_limpa(void)
{
  printf("\e[2J");
}

void tela_lincol(int lin, int col)
{
  printf("\e[%d;%dH", lin, col);
}

static int nlin, ncol; 

static void tela_le_nlincol(int nada)
{
  struct winsize tam;
  bool ok = false;
  // pede para o sistema o tamanho da janela de texto
  int fd = open(ctermid(NULL), O_RDWR);
  if (fd != -1) {
    if (ioctl(fd, TIOCGWINSZ, &tam) == 0) {
      nlin = tam.ws_row;
      ncol = tam.ws_col;
      if (nlin > 15 && ncol > 20) {
        ok = true;
      }
    }
  }
  if (!ok) {
    nlin = 24;
    ncol = 80;
    printf("Não consegui identificar tamanho do terminal, usando %dx%d\n",
        nlin, ncol);
  }
}

int tela_nlin(void)
{
  return nlin;
}

int tela_ncol(void)
{
  return ncol;
}

void tela_cor_normal(void)
{
  printf("\e[m");
}

void tela_cor_letra(int vermelho, int verde, int azul)
{
  printf("\e[38;2;%d;%d;%dm", vermelho, verde, azul);
}

void tela_cor_fundo(int vermelho, int verde, int azul)
{
  printf("\e[48;2;%d;%d;%dm", vermelho, verde, azul);
}


double tela_relogio(void)
{
  struct timespec agora;
  clock_gettime(CLOCK_REALTIME, &agora);
  return agora.tv_sec + agora.tv_nsec*1e-9;
}
