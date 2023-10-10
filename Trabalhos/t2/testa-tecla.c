#include "tecla.h"
#include <stdio.h>

char imp(char c)
{
  // se c for imprimível, retorna o próprio c, senão retorna '.'
  if (c >= ' ' && c <= '~') {
    return c;
  } else {
    return '.';
  }
}

int main()
{
  tecla_ini();
  char c;
  do {
    c = tecla_le_char();
    if (c == 0) continue;
    printf("%02x %c\n", c, imp(c));
  } while (c != '\n');
  tecla_fim();
}
