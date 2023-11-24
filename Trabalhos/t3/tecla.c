#include "tecla.h"

#include <termios.h>
#include <unistd.h>

// variável global para guardar a configuração original do
//   teclado
static struct termios estado_original_do_teclado;

// muda o processamento de caracteres de entrada pelo terminal
//   para que a leitura seja feita em caracteres individuais, sem esperar
//   digitar enter
// esta função deve ser chamada no início do programa
void tecla_ini(void)
{
  // lê e guarda o estado atual do terminal
  tcgetattr(1, &estado_original_do_teclado);
  // altera o estado do terminal para não ecoar o que é digitado
  //   nem esperar <enter>
  struct termios t = estado_original_do_teclado;
  t.c_lflag &= (~ECHO & ~ICANON);
  t.c_cc[VMIN] = 0; // pode retornar de uma leitura sem nenhum caractere
  t.c_cc[VTIME] = 1; // espera até tantos décimos de segundo antes de retornar
  // envia a nova configuração para o sistema
  tcsetattr(1, TCSANOW, &t);
}

// configura o teclado para o modo que estava quando tecla_ini foi chamada
// esta função deve ser chamada no final da execução do programa
void tecla_fim(void)
{
  tcsetattr(1, TCSANOW, &estado_original_do_teclado);
}

char tecla_le_char(void)
{
  char a;
  if (read(1, &a, 1) != 1) {
    return 0; // nada foi digitado
  }
  // as vezes é codificado um caractere diferente.
  // quero que enter seja \n e backspace seja \b
  if (a == 127) return '\b';
  if (a == '\r') return '\n';
  return a;
}
