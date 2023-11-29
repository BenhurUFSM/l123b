// l123b - código fornecido para o t3
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "tela.h"

// enums para dar nomes a valores constantes, de forma organizada
typedef enum {
  ouros,
  copas,
  espadas,
  paus
} naipe_t;

typedef enum { 
  as = 1,
  // os números 2-10 se auto representam
  valete = 11,
  dama,
  rei
} valor_t;

typedef enum {
  naipe_vermelho,
  naipe_preto
} cor_t;

// registro que representa uma carta de baralho
typedef struct {
  valor_t valor;
  naipe_t naipe;
} carta_t;

// registro que representa uma pilha de cartas
typedef struct {
  int n_cartas;
  carta_t cartas[52];
} pilha_t;

// Funções da parte I
// cria uma carta | valor_t, naipe_t | carta_t
carta_t carta(valor_t valor, naipe_t naipe)
{
  carta_t c = { valor, naipe };
  return c;
}
// retorna o naipe de uma carta | carta_t | naipe_t
naipe_t carta_naipe(carta_t c)
{
  return c.naipe;
}
// retorna o valor de uma carta | carta_t | valor_t
valor_t carta_valor(carta_t c)
{
  return c.valor;
}
// retorna a cor de uma carta | carta_t | cor_t
cor_t carta_cor(carta_t c)
{
  if (carta_naipe(c) == paus || carta_naipe(c) == espadas) {
    return naipe_preto;
  } else {
    return naipe_vermelho;
  }
}
// descrição de uma carta (2) | carta_t, char * | void
void carta_descricao(carta_t c, char *str)
{
  strcpy(str, "A\u2666");
}
// compara duas cartas (true se iguais) | carta_t, carta_t | bool
bool carta_igual(carta_t c1, carta_t c2)
{
  return true;
}

// esvazia uma pilha | pilha_t * | void
void pilha_esvazia(pilha_t *p)
{
}
// retorna o número de cartas em uma pilha | pilha_t * | int
int pilha_ncartas(pilha_t *p)
{
  return 0;
}
// retorna o número de cartas fechadas em uma pilha | pilha_t * | int
int pilha_nfechadas(pilha_t *p)
{
  return 0;
}
// retorna o número de cartas abertas em uma pilha | pilha_t * | int
int pilha_nabertas(pilha_t *p)
{
  return 0;
}
// diz se uma pilha está vazia | pilha_t * | bool (true se vazia)
bool pilha_vazia(pilha_t *p)
{
  return true;
}
// diz se uma pilha está cheia | pilha_t * | bool (true se cheia)
bool pilha_cheia(pilha_t *p)
{
  return true;
}
// abre a carta no topo da pilha | pilha_t * | void
void pilha_abre_topo(pilha_t *p)
{
}
// fecha todas as cartas da pilha | pilha_t * | void
void pilha_fecha_todas(pilha_t *p)
{
}
// gera baralho inteiro (3) | pilha_t * | void
// empilha uma carta (5) | pilha_t *, carta_t | void
void pilha_empilha(pilha_t *p, carta_t c)
{
}
// retorna o topo | pilha_t * | carta_t
carta_t pilha_topo(pilha_t *p)
{
  return carta(as, ouros);
}
// remove o topo | pilha_t * | carta_t
carta_t pilha_remove_topo(pilha_t *p)
{
  return carta(as, ouros);
}
// move cartas entre pilhas (1) | pilha_t *, pilha_t *, int | void
void pilha_move_cartas(pilha_t *destino, pilha_t *origem, int n_cartas)
{
}
void pilha_gera_baralho(pilha_t *p)
{
}
// embaralha as cartas em uma pilha | pilha_t * | void
void pilha_embaralha(pilha_t *p)
{
}
// retorna uma carta da pilha (4) | pilha_t *, int, bool * | carta_t
carta_t pilha_carta_na_pos(pilha_t *p, int pos, bool *p_estado_da_carta)
{
  if (p_estado_da_carta != NULL) {
    *p_estado_da_carta = false;
  }
  return carta(as, ouros);
}



// funções de teste

void desenha_carta(carta_t c, bool aberta)
{
  if (aberta) {
    tela_cor_fundo(200, 200, 200);
  } else {
    tela_cor_fundo(50, 50, 100);
  }
  if (carta_cor(c) == naipe_vermelho) {
    tela_cor_letra(200, 0, 0);
  } else {
    tela_cor_letra(0, 0, 0);
  }
  char s[10];
  carta_descricao(c, s);
  printf("%s", s);
  tela_cor_normal();
}

void desenha_pilha(pilha_t *p)
{
  for (int pos = 0; pos < pilha_ncartas(p); pos++) {
    carta_t c;
    bool aberta;
    c = pilha_carta_na_pos(p, pos, &aberta);
    desenha_carta(c, aberta);
  }
  printf("\n");
}

void testa_p1(void)
{
  pilha_t p;
  pilha_esvazia(&p);
  while (!pilha_cheia(&p)) {
    pilha_empilha(&p, carta(as, ouros));
    printf("%d ", pilha_ncartas(&p));
  }
  printf("\nempilhadas %d cartas\n", pilha_ncartas(&p));
  while (!pilha_vazia(&p)) {
    pilha_remove_topo(&p);
    printf("%d ", pilha_ncartas(&p));
  }
  printf("\nsobraram %d cartas\n", pilha_ncartas(&p));
  pilha_gera_baralho(&p);
  printf("baralho completo: ");
  desenha_pilha(&p);
  pilha_t p2;
  pilha_esvazia(&p2);
  printf("move por naipe\n");
  for (int i = 0; i < 4; i++) {
    pilha_move_cartas(&p2, &p, 13);
    desenha_pilha(&p);
    desenha_pilha(&p2);
  }
  pilha_move_cartas(&p, &p2, 52);
  printf("move de volta: ");
  desenha_pilha(&p);
  printf("tá cheia: %s\n", pilha_cheia(&p) ? "sim" : "não");
  pilha_embaralha(&p);
  printf("bar. embaralhado: ");
  desenha_pilha(&p);
  pilha_fecha_todas(&p);
  pilha_abre_topo(&p);
  printf(" baralho fechado: ");
  desenha_pilha(&p);
  pilha_gera_baralho(&p);
  while (!pilha_vazia(&p)) {
    carta_t c = pilha_remove_topo(&p);
    desenha_carta(c, true);
    printf(" ");
    desenha_pilha(&p);
  }
  pilha_esvazia(&p);
  pilha_empilha(&p, carta(2, copas));
  pilha_empilha(&p, carta(5, copas));
  pilha_empilha(&p, carta(as, copas));
  desenha_pilha(&p);
  assert(pilha_ncartas(&p) == 3);
  assert(pilha_nabertas(&p) == 3);
  pilha_fecha_todas(&p); 
  assert(pilha_nfechadas(&p) == 3);
  assert(pilha_nabertas(&p) == 0);
  pilha_embaralha(&p);
  desenha_pilha(&p);
  assert(carta_naipe(pilha_topo(&p)) == copas);
  assert(carta_naipe(pilha_carta_na_pos(&p, -1, NULL)) == copas);
  pilha_esvazia(&p);
  assert(pilha_ncartas(&p) == 0);
  assert(pilha_nfechadas(&p) == 0);
  assert(pilha_nabertas(&p) == 0);
  printf("Deve morrer no próximo comando\n");
  desenha_carta(pilha_remove_topo(&p), false); // deve morrer no assert
}

int main()
{
  testa_p1();
}
