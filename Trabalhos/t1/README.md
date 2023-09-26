## t1 - digite os números

É um programa para a digitação de números.
O programa apresenta alguns números para o usuário, que deve digitá-los, no tempo disponível.

Ao receber um número, o programa informa caso o número não exista.
Se o número for válido, é removido do conjunto e os números restantes são apresentados novamente.

Os números podem ser digitados em qualquer ordem.

Se o tempo acabar antes que todos os números sejam digitados, o jogador perde. 

Ao final de uma partida, o programa pergunta se o jogador deseja jogar novamente.

O programa obrigatoriamente tem as duas funções abaixo:

- `acha_num` recebe um vetor (com seu tamanho) e um número, e retorna o índice do vetor onde esse número está. Caso o vetor não tenha esse número, a função retorna -1. Exemplos:
   - `[61 12 5 7 78] 5` deve retornar `2`
   - `[61 12 5 7 78] 1` deve retornar `-1`
   - `[61 12 5 7 78 12] 12` deve retornar `1`
- `remove_pos` recebe um vetor (com seu tamanho) e um índice, e desloca os valores do vetor de forma que o valor nesse índice fique no final do vetor, os valores antes desse índice fiquem onde estão e os demais ocupem o índice imediatamente anterior, conforme os exemplos:
   - `[61 12 5 7 78] 2` é alterado para `[61 12 7 78 5]`
   - `[0 1 2] 0` é alterado para `[1 2 0]`
   - `[3 2 2 8] 3` é alterado para `[3 2 2 8]`

O programa está parcialmente implementado no arquivo anexo. Somente as partes a seguir devem ser alteradas:
- comentário inicial
- implementar as funções marcadas
- alterar o nome do arquivo

Anexe o arquivo alterado em um e-mail com o assunto igual ao nome do arquivo sem o .c.
