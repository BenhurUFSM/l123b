// inclui as definicoes
#include "telag.h"
#include <stdio.h>
#include <assert.h>

// Os includes do allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

static void cai_fora(char *msg)
{
  int cai = 42;
  int fora = 42;
  printf("\n\nERRO\n%s\n\n", msg);
  assert(cai-fora);
}

static void tela_inicializa_janela(float l, float a, char n[])
{
  // pede para tentar linhas mais suaves (multisampling)
  al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
  // cria uma janela
  ALLEGRO_DISPLAY *janela;
  janela = al_create_display(l, a);
  if (janela == NULL) cai_fora("problema na criação de janela do allegro");
  // esconde o cursor do mouse
  al_hide_mouse_cursor(janela);
  al_set_window_title(janela, n);
}

// vetor com as cores
#define NCORES 100 // número máximo de cores diferentes
static ALLEGRO_COLOR cores[NCORES];
static void tela_inicializa_cores(void)
{
  tela_altera_cor(transparente, 0, 0, 0, 0);
  tela_altera_cor(azul, 0, 0, 1, 1);
  tela_altera_cor(vermelho, 1, 0, 0, 1);
  tela_altera_cor(verde, 0, 1, 0, 1);
  tela_altera_cor(amarelo, 1, 1, 0, 1);
  tela_altera_cor(preto, 0, 0, 0, 1);
  tela_altera_cor(laranja, 1, 0.65, 0, 1);
  tela_altera_cor(rosa, 1, 0, 0.5, 1);
  tela_altera_cor(branco, 1, 1, 1, 1);
  tela_altera_cor(marrom, 0.58, 0.29, 0, 1);
}

void tela_altera_cor(int cor,
                     float vm, float az, float vd, float opacidade)
{
  assert(cor >= 0 && cor < NCORES);
  cores[cor] = al_map_rgba_f(vm, az, vd, opacidade);
}

// fila para receber os eventos do teclado
ALLEGRO_EVENT_QUEUE *tela_eventos_teclado;
void tela_inicializa_teclado(void)
{
  if (!al_install_keyboard()) cai_fora("problema na inicialização do teclado do allegro");
  // cria e inicializa a fila de eventos do teclado
  tela_eventos_teclado = al_create_event_queue();
  if (tela_eventos_teclado == NULL) cai_fora("problema na criação da fila de eventos do teclado do allegro");
  al_register_event_source(tela_eventos_teclado,
                           al_get_keyboard_event_source());
}

void tela_inicio(int largura, int altura, char nome[])
{
  // inicializa os subsistemas do allegro
  if (!al_init()) cai_fora("problema na inicialização do allegro");
  if (!al_install_mouse()) cai_fora("problema na inicialização do mouse do allegro");
  if (!al_init_primitives_addon()) cai_fora("problema na inicialização de addons do allegro");
  al_init_font_addon();
  if (!al_init_ttf_addon()) cai_fora("problema na inicialização do addon de fontes ttf");

  // inicializa a tela
  tela_inicializa_janela(largura, altura, nome);
  tela_inicializa_teclado();
  tela_inicializa_cores();
}


void tela_fim(void)
{
  // badabum!
  al_uninstall_system();
}

void tela_atualiza(void)
{
  static double tempo_ultima_tela = 0;
  double agora = tela_relogio();
  double quando_mostrar = tempo_ultima_tela + SEGUNDOS_POR_QUADRO;
  double tempo_ate_mostrar = quando_mostrar - agora;
  if (tempo_ate_mostrar > 0) {
    // é muito cedo, dá uma cochilada
    al_rest(tempo_ate_mostrar);
  }
  // troca a tela mostrada pela que foi desenhada em memória
  al_flip_display();
  tempo_ultima_tela = tela_relogio();

  // limpa todo o canvas em memória, para desenhar a próxima tela
  al_clear_to_color(cores[preto]);
}


void tela_circulo(float x, float y, float r, float l, int corl, int corint)
{
  // preenche
  al_draw_filled_circle(x, y, r, cores[corint]);
  // faz o contorno
  al_draw_circle(x, y, r, cores[corl], l);
}

void tela_linha(float x1, float y1, float x2, float y2, float l, int corl)
{
  al_draw_line(x1, y1, x2, y2, cores[corl], l);
}

void tela_retangulo(float x1, float y1, float x2, float y2, float l,
                    int corl, int corint)
{
  al_draw_filled_rectangle(x1, y1, x2, y2, cores[corint]);
  al_draw_rectangle(x1, y1, x2, y2, cores[corl], l);
}

// tem que ter uma fonte para poder escrever
static ALLEGRO_FONT *fonte = NULL;

static void tela_prepara_fonte(int tam)
{
  static int tamanho_das_letras = 0;

  // se se quer o mesmo tamanho que antes, usa a mesma
  if (tam == tamanho_das_letras) return;

  // se ja tinha uma fonte carregada, livra-se dela antes de carregar outra
  if (fonte != NULL) {
    al_destroy_font(fonte);
  }

  // carrega uma fonte, para poder escrever na tela
  fonte = al_load_font("DejaVuSans.ttf", tam, 0);
  if (fonte == NULL) {
    al_uninstall_system();
    printf("\n\nERRO FATAL\n");
    printf("ARQUIVO QUE DEFINE DESENHO DAS LETRAS (DejaVuSans.ttf) NAO ENCONTRADO.\n"
           "COPIE ESSE ARQUIVO, OU MUDE telag.c PARA USAR UM ARQUIVO QUE EXISTA.\n\n");
    exit(1);
  }
  tamanho_das_letras = tam;
}

void tela_texto(float x, float y, int tam, int c, char t[])
{
  tela_prepara_fonte(tam);
  al_draw_text(fonte, cores[c], x, y-tam/2, ALLEGRO_ALIGN_CENTRE, t);
}

void tela_texto_esq(float x, float y, int tam, int c, char t[])
{
  tela_prepara_fonte(tam);
  al_draw_text(fonte, cores[c], x, y, ALLEGRO_ALIGN_RIGHT, t);
}

void tela_texto_dir(float x, float y, int tam, int c, char t[])
{
  tela_prepara_fonte(tam);
  al_draw_text(fonte, cores[c], x, y, ALLEGRO_ALIGN_LEFT, t);
}

void tela_rato_pos(int *px, int *py)
{
  ALLEGRO_MOUSE_STATE rato;
  al_get_mouse_state(&rato);
  *px = al_get_mouse_state_axis(&rato, 0);
  *py = al_get_mouse_state_axis(&rato, 1);
}

bool tela_rato_apertado(void)
{
  ALLEGRO_MOUSE_STATE rato;
  al_get_mouse_state(&rato);
  // só nos interessa o botão da esquerda
  return al_mouse_button_down(&rato, 1);
}

int x_clicado = 0;
int y_clicado = 0;
bool tela_rato_clicado(void)
{
  static bool tava_apertado = false;
  bool ta_apertado = tela_rato_apertado();
  bool foi_clicado = (tava_apertado && !ta_apertado);
  if (foi_clicado) {
    tela_rato_pos(&x_clicado, &y_clicado);
  }
  tava_apertado = ta_apertado;
  return foi_clicado;
}

void tela_rato_pos_clique(int *px, int *py)
{
  *px = x_clicado;
  *py = y_clicado;
}


char tela_tecla(void)
{
  ALLEGRO_EVENT ev;

  while (al_get_next_event(tela_eventos_teclado, &ev)) {
    if (ev.type == ALLEGRO_EVENT_KEY_CHAR) {
      int k = ev.keyboard.keycode;
      switch (k) {
        case ALLEGRO_KEY_ENTER:     return '\n';
        case ALLEGRO_KEY_BACKSPACE: return '\b';
      }
      int c = ev.keyboard.unichar;
      return c;
    }
  }
  // nada foi pressionado (ou foi pressionado algo não imprimível)
  return '\0';
}


double tela_relogio(void)
{
  return al_get_time();
}
