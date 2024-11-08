#include "array.h"

int * generatePages(int n, int min, int max) {
    int *pages = (int *)malloc(n * sizeof(int));

    for (int i = 0 ; i < n ; i++ ) {
        pages[i] = ( rand() % (max-min) ) + min;
    }

    return pages;
}

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

void test(int id, int n, int min, int max, int capacity) {
        int * pages = generatePages(n, min, max);

    printf("######### TESTE %d #########\n", id);
    printPages(pages, n);
    FIFO(pages, n, capacity);
    printf("---------------------------\n", id);
}