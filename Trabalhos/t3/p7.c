// ...
#include <string.h>
// ...
#include "tecla.h" // ou "telag.h"
// ...

// ...
#define MAX_CHAR_CMD 2
typedef struct {
  // ...
  char comando[MAX_CHAR_CMD + 1];
  bool ultimo_comando_ok;
  // ...
} jogo_t;
// ...


void processa_entrada_pelo_teclado(jogo_t *jogo)
{
  char tecla;

  tecla = tecla_le_char(); // ou tela_tecla();
  if (tecla == '\0') return;

  int nchar = strlen(jogo->comando);

  switch (tecla) {
    case '\b':
      if (nchar > 0) {
        jogo->comando[--nchar] = '\0';
      }
      break;
    case '\n':
      if (nchar > 0) {
        jogo->ultimo_comando_ok = jogo_faz_uma_jogada(jogo, jogo->comando);
        jogo->comando[0] = '\0';
      }
      break;
    default:
      if (nchar < MAX_CHAR_CMD) {
        jogo->comando[nchar++] = tecla;
        jogo->comando[nchar] = '\0';
      }
      break;
  }
}
