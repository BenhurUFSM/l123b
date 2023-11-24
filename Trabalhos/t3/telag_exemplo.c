// Programa de exemplo de uso de telag.h e telag.c
//
// Necessita os arquivos telag_exemplo.c (este), telag.h, telag.c e DejaVuSans.ttf
// Necessita ter instalado a biblioteca allegro5
//
// para compilar este programa manualmente em linux:
// gcc -Wall -o exemplo telag_exemplo.c telag.c -lallegro_font -lallegro_color -lallegro_ttf -lallegro_primitives -lallegro
//

#include "telag.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// A função principal
int main(void)
{
  // inicializa a tela gráfica
  tela_inicio(500, 500, "exemplo");

  // cria uma cor (como não tem essa nas pré-definidas?)
  int fucsia = 11;
  tela_altera_cor(fucsia, 1, 0.2, 0.8, 1);
  
  char tec = 'x';

  double inicio = tela_relogio();
  // laço principal por 10 segundos
  while (true) {
    double tempo = tela_relogio() - inicio;
    if (tempo >= 10) break;

    // desenha um quadrado no contorno da janela
    tela_retangulo(30, 30, 470, 470, 5, fucsia, transparente);

    // cadê o rato?
    int rx, ry;
    tela_rato_pos(&rx, &ry);

    // faz uma linha se o botão do mouse tiver apertado
    if (tela_rato_apertado()) {
      tela_linha(30, 30, rx, ry, 2, branco);
    }

    // desenha um círculo na posição do mouse
    tela_circulo(rx, ry, 10, 2, vermelho, branco);
    tela_texto(rx, ry, 20, verde, "\u256d\u256e\u2573\u2570\u256f");

    // escreve o valor do relógio no canto da tela
    char txt[100];
    sprintf(txt, "\u2660\u2663\u2665\u2666%c%.1f", tec, tempo);
    tela_texto_esq(450, 245, 20, fucsia, "\u2591\u2591");
    tela_texto_esq(450, 245, 20, amarelo, txt);

    char c = tela_tecla();
    if (c) tec = c;
    // faz aparecer na tela o que foi desenhado
    tela_atualiza();
  }

  // encerra a tela gráfica
  tela_fim();

  return 0;
}
