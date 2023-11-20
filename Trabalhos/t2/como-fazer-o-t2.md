## Dicas de como implementar o t2

### parte I

É uma adaptação do t1 para trabalhar com `char` em vez de `int`.

Na função `jogo`, tem que alterar a declaração das variáveis que passam a ser `char` (e devem trocar de nome também, para ser mais coerente com seu conteúdo):
- o vetor `numeros`,
- a variável `num`.

Como o vetor passa a conter uma string, não precisamos mais uma variável para conter o número de elementos no vetor, porque esse controle em strings é feito pela posição do caractere '\0'. É o fim da variável `n_num`.

A função `preenche_vet` necessita receber o vetor e o seu tamanho, como no t1. A função em si deve ser bastante mudada, porque ela não preenche totalmente o vetor como antes, mas deve sortear o número de caracteres a colocar no vetor, entre 1 e o máximo que cabe. Como vai ser armazenada uma string, tem que tomar cuidado que o máximo de elementor é um a menos que o tamanho do vetor. Tem também que ter o cuidado de terminar corretamente a string com o caractere '\0'. O sorteio de cada valor, que era um número aleatório entre 0 e 999 deve ser alterado para ser entre 'a' e 'z'.

A forma de saber se o jogo acabou, que era controlada por `n_num` passa a ser pelo tamanho da string contida no vetor (pode usar a função `strlen` para isso).

A função que mostra o conteúdo do vetor passa a mostrar a string que o vetor contém. Não necessita mais receber número de elementos como argumento, e pode simplesmente imprimir a string com um printf com '%s'.

A função `acha_num`, além de mudar de nome, também não recebe mais o número de elementos no vetor. Idem para a remove_pos.

Talvez já seja a hora de também modularizar melhor a função `jogo`, que está um pouco complicada demais. Isso facilitará a evolução futura do programa, que acontecerá basicamente nessa função.

O laço principal da função faz 4 coisas:
- verifica se o tempo acabou
- verifica se o objetivo foi atingido
- desenha a tela
- altera o estado do jogo em reação à entrada de caracteres

Que tal colocar cada uma dessas ações em uma função?

### parte II

Esta parte contém duas alterações:
- a digitação passa a ser somente da primeira letra
- uso de funções alternativas para a entrada não bloqueante de caracteres

A primeira alteração é uma simplificação em relação à parte I. A busca de um caractere passa a ser simplesmente uma comparação com o primeiro caractere da string, e a remoção de um caractere não necessita mais de posição, porque é sempre o primeiro caractere que é removido.

A segunda alteração envolve toda a entrada realizada pelo programa, por um lado a única função de entrada que deve ser utilizada é `tecla_le_char`, então tem que alterar todo local que usa getchar ou scanf. Por outro lado, deve-se levar em consideração que a função não espera que um caractere seja digitado, então deve-se tratar corretamente o retorno de `\0` por essa função, que é retornado quando nada foi digitado.

A estrutura do programa não precisa ser alterada.

### parte III

Nesta parte, tem alterações mais consequentes. O programa passa a ter um vetor de palavras, implementado como uma matriz (vetor de vetores) de `char`.

O preenchimento de cada palavra é feito como antes, então dá para usar a mesma função, mas ela é chamada várias vezes, uma para cada palavra. O melhor aqui é fazer uma nova função para preencher a matriz, que chama várias vezes a função já existente.
No vetor de palavras, pode ter um número qualquer de palavras, e esse número vai diminuindo conforme o jogo avança. Precisamos uma variável para conter esse valor (é a mesma utilidade de `n_num` do t1).
Todo lugar que for percorrer o vetor de palavras precisa saber quantos elementos úteis tem nesse vetor, então tem que ter acesso ao valor dessa variável.

Existe o conceito de palavra selecionada, que pode ser implementada como um índice para o vetor de palavras, com valor -1 (por exemplo) para indicar a inexistência.

A finalização do programa agora não é pelo final da digitação de uma palavra, mas pelo esvaziamento do vetor de palavras (como o t1, para o vetor de números).

Se existir uma palavra selecionada, funciona como a parte II, mas se não houver, a entrada é utilizada para fazer a seleção da palavra. Foi dado um algoritmo com uma forma de implementar o laço principal.

### parte IV

O funcionamento do programa é o mesmo da parte III. Só muda a forma como o vetor de palavras é preenchido.

A sugestão é ter um outro vetor de palavras, maior, para conter todas as palavras válidas do arquivo. Uma função que preenche esse vetor à partir do arquivo seria desenvolvida e chamada no início do programa, e a função de preenchimento do vetor de palavras seria alterada para copiar palavras de posições aleatórias do vetor com todas as palavras.

### parte V

A introdução das funções de tela.h exigem algumas alterações na organização do programa.

Uma das alterações é bem simples, a substituição de `time` por `tela_relogio` para a obtenção do tempo atual. Tem que trocar as variáveis usadas para conter tempo para o tipo double, e alterar a formatação desses valores quando forem escritos.

A outra alteração envolve a saída, que deve ser organizada em telas. A melhor forma de fazer isso é ter uma função responsável pelo desenho completo de cada tela do programa (apresentação, despedida, jogo). Cada uma dessas funções só faz o desenho da tela, e chama tela_limpa no início e tela_atualiza no fim. Todos os prints do programa devem ser colocados nessas funções. Elas devem receber argumentos com todos os dados necessários para o desenho de sua tela.
Essas funções só fazem saída de dados, não alteram nenhuma variável que represente o estado do jogo.

A função que faz o desenho da tela principal deve escolher cores para tornar a tela mais interessante, no mínimo uma cor diferente entre as palavras não selecionadas e a selecionada (quando existir).

### parte VI

Agora as palavras estão mais ricas, tem mais informação associada a cada uma. Uma forma de se fazer isso é tendo um vetor para cada informação adicional. A palavra que está na posição 5 do vetor de palavras tem sua duração na posição 5 do vetor de posições.
Esses vetores têm a mesma quantidade de dados que o vetor de palavras, então não precisamos de mais variáveis para conter o número de dados em cada um.
Tem que ter o cuidado de manter esses vetores sincronizados. Em especial, quando uma palavra é movida ou removida no vetor de palavras, as informações referentes a ela devem ser movidas da mesma forma nos demais vetores.

A função que escolhe as palavras pode também sortear os valores adicionais para cada palavra. Para isso, deve receber esses vetores para alterá-los.

A função que desenha a tela principal usa os valores nesses vetores para o desenho da tela, então deve recebê-los como parâmetro.

A função que verifica o final do jogo deve ser alterada para uma nova forma de término, que é o fim de prazo de cada palavra.

A escolha da palavra selecionada deve ser r

A função que verifica o final do jogo deve ser alterada para uma nova forma de término, que é o fim de prazo de cada palavra.

A escolha da palavra selecionada deve ser realizada somente entre as palavras ativas.

### parte VII

Tem que calcular os pontos, ação que é realizada a cada tecla digitada, e depende da tecla e de temporização. Um bom local para colocar esse cálculo é nna função que processa os caracteres de entrada.

A função que desenha a tela deve receber os pontos atuais, já que eles devem aparecer.

As maiores pontuações devem ser registradas em um arquivo. Uma forma simples de implementar isso é tendo essas pontuações em variáveis. Essas variáveis são inicializadas a partir do conteúdo do arquivo no início do programa (faça uma função para isso), e possivelmente alteradas no final de uma partida, dependendo da pontuação. Caso sejam alteradas, devem ser escritas no arquivo (outra função). 
