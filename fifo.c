#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de geração de lista com itens aleatórios
int * generatePages(int n, int min, int max) {
    int *pages = (int *)malloc(n * sizeof(int));

    for (int i = 0 ; i < n ; i++ ) {
        pages[i] = ( rand() % (max-min) ) + min;
    }

    return pages;
}

// Função auxiliar para impressão de um array de páginas
void printPages(int * pages, int size) {
    printf("Páginas: ");

    for (int i = 0; i < size; i++){
        printf("%d ", pages[i]);
    }

    printf("\n");
}

// Função para implementar o algoritmo FIFO
void FIFO(int pages[], int n, int capacidade) {
    int *quadros = (int *)malloc(capacidade * sizeof(int));
    int indice = 0, faltasDePagina = 0;

    // Inicialização dos quadros com -1 (indicando que estão vazios)
    for (int i = 0; i < capacidade; i++) {
        quadros[i] = -1;
    }

    printf("Sequência de referências \t Quadros\n");
    for (int i = 0; i < n; i++) {
        int pagina = pages[i];
        int encontrada = 0;

        // Verifica se a página já está carregada em um dos quadros
        for (int j = 0; j < capacidade; j++) {
            if (quadros[j] == pagina) {
                encontrada = 1;
                break;
            }
        }

        // Página não encontrada nos quadros (caso de falta de página)
        if (!encontrada) {
            quadros[indice] = pagina;
            indice = (indice + 1) % capacidade; // Atualiza o índice ciclicamente
            faltasDePagina++;

            // Exibe o estado atual dos quadros
            printf("\t%d\t\t\t", pagina);
            for (int j = 0; j < capacidade; j++) {
                if (quadros[j] != -1)
                    printf("%d ", quadros[j]);
                else
                    printf("- ");
            }
            printf("\n");
        }
    }

    printf("\nTotal de faltas de página: %d\n", faltasDePagina);
    free(quadros);
}

// Função auxiliar para deixar o código mais legível.
void test(int id, int n, int min, int max, int capacity) {
    int * pages = generatePages(n, min, max);

    printf("######### TESTE %d #########\n", id);
    printPages(pages, n);
    FIFO(pages, n, capacity);
    printf("---------------------------\n", id);
}

int main() {
    srand(time(NULL));

    printf("BLOCO 1: CAPACIDADE = 3.\n");
    test(1,5,10,100,3);
    test(2,10,10,100,3);
    test(3,15,10,100,3);
    test(4,20,10,100,3);
    test(5,25,10,100,3);

    printf("BLOCO 2: CAPACIDADE = 5.\n");
    test(1,5,10,100,5);
    test(2,10,10,100,5);
    test(3,15,10,100,5);
    test(4,20,10,100,5);
    test(5,25,10,100,5);

    printf("BLOCO 3: CAPACIDADE = 8.\n");
    test(1,5,10,100,8);
    test(2,10,10,100,8);
    test(3,15,10,100,8);
    test(4,20,10,100,8);
    test(5,25,10,100,8);
    
    return 0;
}