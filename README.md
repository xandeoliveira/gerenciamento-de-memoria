# Implementação do algoritmo FIFO para gerenciamento de memória

O problema da substituição de páginas ocorre em decidir quais páginas manter na
memória física limitada e quais enviar para o disco quando a memória está cheia.
Isso é necessário para otimizar o uso da memória, reduzindo o tempo de acesso e
garantindo que as páginas mais relevantes estejam disponíveis para execução. O
algoritmo FIFO (First-In, First-Out) é uma das abordagens para resolver esse
problema. Ele funciona removendo a página que está há mais tempo na memória,
partindo da ideia de que as páginas mais antigas podem ser menos relevantes.
Apesar de sua simplicidade, o FIFO pode levar a um número maior de faltas de
página quando a página descartada, apesar de mais antiga, é frequentemente
referenciada.

## Objetivo

O objetivo desta prática é se familiarizar e entender o algoritmo FIFO no contexto
de substituição de páginas e pensar criticamente sobre métodos para
otimizá-lo de modo a reduzir a falta de página (page miss).O código de partida
comentado está no primeiro commit.

Saída da execução do algoritmo para a sequência: {1, 3, 0, 3, 5, 6, 3}

    Sequência de referências Quadros

            1               1 - -

            3               1 3 -

            0               1 3 0

            5               5 3 0

            6               5 6 0

            3               5 6 3

    Total de faltas de página: 6

## Intervenções feitas no código de partida:

Para que o teste seja feito de forma mais eficiente é melhor que haja uma função geradora de sequência de páginas. Afunção deve receber como argumentoso tamanho da sequência e os valores mínimo e máximo(extremos do sorteio) e deve retornar um array de interos de tamanho n.

Para que possamos saber qual sequência de números foi gerada será escrita também uma função auxiliar para imprimir a lista de páginas em uma linha. E uma função auximilar para testes a fim de não poluir a leitura da função main com muitas chamadas de funções printf.

Depois de executados os testes, as saídas foram organizadas nos gráficos a seguir:

![Gráfico 1](imagens/Faltas%20de%20Página(sorteio%20entre%2010%20e%2020).png)

![Gráfico 2](imagens/Faltas%20de%20Página(sorteio%20entre%2010%20e%2060).png)

![Gráfico 3](imagens/Faltas%20de%20Página(sorteio%20entre%2010%20e%20100).png)

### a) Sequência de páginas: Como a sequência inicial de teste influencia o número de faltas? Testar o algoritmo com diferentes sequências de testes e, de diferentes tamanhos e analisar os resultados.

É possível perceber que se todos os valores das páginas são diferentes o número de faltas de página é igual ao número de páginas.

Nos casos de localidades espaciais o número de faltas de páginas é menor que o número n de páginas.

A existência de localidades temporais também podem apresentar faltas de página menor que n, desde que a capacidade seja suficiente para que a página ainda seja referenciada.

### b) Capacidade dos Quadros: Como o número de quadros disponíveis influencia o número de faltas? Testar o algoritmo com diferentes capacidades e analisar os resultados.

Para ambos os gráficos a linha azul(corresponde ao teste de capacidade igual a 3), se manteve predominantemente acima das outras o que dá a entender que *quanto menor a capacidade maior a quantidade de faltas de página*, que pode ser explicado pelo fato de que a probabilidade da página ser encontrada é menor por ter uma capacidade menor.

### c) Pesquisar e implementar maneiras de reduzir o número de faltas de página. Como o algoritmo poderia se comportar se fosse combinado com uma estratégia de frequência de uso?