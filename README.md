# l123b
Laboratório de Programação I, segundo semestre de 2023

ELC1065 DLSC/CT/UFSM\
professor: Benhur Stein 
([benhur+l123b@inf.ufsm.br](mailto:benhur%2bl123b@inf.ufsm.br))\
terças e quintas, 14h30\
sala 334, prédio 7 (principal do CT)\
aluno monitor: Gabriel Bisognin Moro ([gbmoro@inf.ufsm.br](mailto:gbmoro@inf.ufsm.br))

## Planilha de avaliação

A avaliação etc dos alunos será colocada na [planilha](https://docs.google.com/spreadsheets/d/19klCrQyGFX9sVlwNINaQz8MRO1kquNxufTVIpa0xCv0/edit?usp=sharing).

## Desenvolvimento da disciplina

Os canais de comunicação entre o professor e os alunos são:
- as aulas presenciais,
- esta página (<https://github.com/BenhurUFSM/l123b>),
- e-mail (ver endereço acima),
- conversa individual, manda um mail que marcamos.

O e-mail pode ser usado para o envio de perguntas, exercícios, reclamações, sugestões, críticas e o que mais for, durante todo o período em que durar a disciplina.

Esta página concentrará os assuntos vistos em aula, a descrição de exercícios e trabalhos, avaliações, etc. Ela estará sendo aumentada/atualizada durante todo o semestre. Ela é o canal mais oficial de informações sobre a disciplina. Todos os alunos devem olhar o que está aqui periodicamente (recomendo descobrir como se habilita notificações).

A disciplina de Laboratório de Programação I é bastante prática, e exige que os alunos se dediquem bastante e desenvolvam trabalhos práticos.
O objetivo da disciplina, aprender a programar computadores, envolve conceitos que podem levar um tempo razoável para serem adquiridos.
A prática de programação tem se mostrado essencial nesse aprendizado.
Para realizar essa prática, é necessário acesso a um computador e a um ambiente de desenvolvimento de programas.
A universidade dispõe de laboratórios com computadores para acesso aos alunos, com todo o software necessário instalado; consulte o NCC caso necessite.
É necessário dedicar um bom tempo à disciplina, além do tempo em aula. Vários dos exercícios terão forma de o próprio aluno ver se o resultado é o esperado. 
Use os canais de comunicação com o professor para sanar dúvidas.

Em um computador pessoal, pode-se instalar um ambiente de desenvolvimento localmente ou usar um dos vários que existem gratuitamente online.
O que se necessita como ambiente de desenvolvimento para a disciplina é o mais básico, basta um editor de textos e um compilador da linguagem "C".
Exemplos de ambiente gratuito online: [replit](https://www.replit.com), [onlineGDB](https://www.onlinegdb.com).
Os exercícios e trabalhos da disciplinas podem ser desenvolvidos nesses ambientes, mas geralmente é menos confortável que usar localmente.

Meu ambiente pessoal de trabalho é no sistema linux, e é nesse ambiente que vou avaliar os trabalhos dos alunos.
Não tenho nenhuma experiência pessoal gratificante com windows, não vou poder auxiliá-lo com problemas diretamente relacionados ao uso desse ambiente.
Minha recomendação para quem quiser manter seu sistema pessoal em windows é a instalação de uma máquina virtual com linux, ou um pendrive para boot em linux.

Por ser uma disciplina prática, a principal forma de avaliação dos alunos será através de exercícios, principalmente o desenvolvimento de pequenos programas de computador, a serem enviados para o professor. No final do semestre, deve ser desenvolvido um trabalho final um pouco mais complexo.
A descrição desses exercícios e programas, bem como a forma de entrega dos mesmos será disponibilizada nesta página.

Os trabalhos entregues não serão imediatamente pontuados, mas comentados de forma individual ou coletiva.
Espera-se que esses comentários sejam aproveitados para gerar novas e melhores versões dos programas, como forma de aprendizagem. 
Os programas podem ser alterados e reenviados ao professor, caso restem dúvidas.

A avaliação será realizada no final do semestre. Para isso, cada aluno deverá entregar a versão final de um subconjunto dos trabalhos desenvolvidos (a ser definido), juntamente com uma auto-avaliação descrevendo o seu desenvolvimento durante o semestre, contendo uma sugestão de nota.

Para quem não alcançar a nota suficiente (7), haverá uma prova escrita de recuperação (chamada exame).

Não deixem dúvidas acumularem.
Quanto mais cedo conseguirmos nos comunicar para apontar problemas, expor sugestões, melhores vão ser nossas chances de sucesso.

### Ementa

Ver [aqui](https://www.ufsm.br/ementario/disciplinas/ELC1065/).

##  Aulas 

Os assuntos vistos em aula serão listados aqui.

|    N |   data | assunto
| ---: | -----: | :--------
|    1 |  8ago  | [introdução](Aulas/01.md)
|    2 |  10ago | [aula prática](Aulas/02.md)
|    3 |  15ago | [primeiro programa C, printf, funções](Aulas/03.md)
|    4 |  17ago | [variáveis](Aulas/04.md)
|    5 |  22ago | [tipos de dados](Aulas/05.md)
|    6 |  24ago | [if](Aulas/06.md)
|    7 |  29ago | Revisão (para quem quiser, e especialmente para os novos ingressantes) (todos vão receber presença)
|    8 |  31ago | [ifs aninhados, argumentos em funções, e4](Aulas/08.md)
|    9 |   5set | [while](Aulas/09.md)
|   10 |  12set | [for, break, continue, bool](Aulas/10.md)
|   11 |  14set | [exercícios](Aulas/11.md)
|   12 |  19set | [exercícios, com prêmio](Aulas/12.md)
|   13 |  21set | [vetores](Aulas/13.md)
|   14 |  26set | exercícios com vetores
|   15 |  28set | [exercícios com vetores](Aulas/15.md)
|   16 |   3out | [strings](Aulas/16.md)
|   17 |   5out | [exercícios com strings](Aulas/17.md)
|   18 |  10out | [Referências (ponteiros)](Aulas/18.md)
|   19 |  17out | [Arquivos](Aulas/19.md)
|   20 |  19out | Exercícios
|   21 |  31out | Exercícios
|   22 |   7nov | [Registros](Aulas/22.md)
|   23 |   9nov | [Exercícios (*struct, enum*)](Aulas/23.md)
|   24 |  14nov | Exercícios
|   25 |  16nov | Exercícios
|   26 |  21nov | [Alocação dinâmica de memória](Aulas/26.md)
|   27 |  23nov | Exercícios
|   28 |  27nov | Exercícios **Atenção, esta segunda tem aulas de quinta**
|   -- |  28nov | **Atenção, esta terça tem aulas de sexta**
|   29 |  30nov |
|   -- |   5dez | **Atenção, esta terça tem aulas de sexta**
|   30 |   7dez | apresentações/conversas (ninguém se candidatou, então será aula para esclarecer dúvidas)
|   -- |  12dez | apresentações/conversas **Atenção, esta terça tem aulas de sábado**
|      |  14dez | 
|      |  19dez | exame


## Exercícios, trabalhos, provas

|     N |     prazo | assunto
| ----: | --------: | :-----------
|    E0 | -         | tem exercícios no final do texto das aulas 1 e 2
|    E1 | 16ago     | [rato e gato](Exercicios/e1)
|    E2 | 21ago,14h | [multiplicação](Exercicios/e2)
|    E3 | 29ago     | ex. 2 no final da aula 6; entrega como os anteriores
|    E4 | 5set      | [impressão de números](Exercicios/e4)
|    T1 | 3out,12h  | [digitação de números](Trabalhos/t1)
|    T2 | 16nov,12h | [digitação de letras](Trabalhos/t2)
|    T3 |  | [klondike](Trabalhos/t3)
| final | 6dez ou 10dez | [entrega final](final.md)

