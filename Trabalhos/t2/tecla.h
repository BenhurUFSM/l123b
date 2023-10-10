#ifndef TECLA_H
#define TECLA_H

// muda o processamento de caracteres de entrada pelo terminal
//   para que a leitura seja feita em caracteres individuais, sem esperar
//   digitar enter
// esta função deve ser chamada no início do programa
void tecla_ini(void);

// configura o teclado para o modo que estava quando tecla_ini foi chamada
// esta função deve ser chamada no final da execução do programa
void tecla_fim(void);

// retorna o próximo caractere lido do teclado, ou 0 se não tiver nenhum
//   caractere a ser lido
char tecla_le_char(void);

#endif // TECLA_H
