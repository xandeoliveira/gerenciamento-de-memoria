#include "list.h"

Page * createPage(unsigned char id) {
    Page *page = (Page *)malloc(sizeof(Page));
    if (page == NULL) {
        printf("Erro ao alocar memória para as páginas.\n");
        exit(1);
    }

    page->page = id;
    page->next = NULL;
    page->frequence = 0;

    return page;
}

Pages * List(char capacity) {
    Pages *pages = (Pages *)malloc(sizeof(Pages));
    if (pages == NULL) {
        printf("Erro ao alocar memória para as páginas.\n");
        exit(1);
    }

    pages->head = NULL;
    pages->tail = NULL;
    pages->minF = pages->head;

    for (char i = 0; i < capacity; i++)
        insertPage(pages, -1, 0);

    return pages;
}

void insertPage(Pages *list, char id, char frequence) {
    if (list->head == NULL){
        list->head = createPage(id);
        list->tail = list->head;
        list->head->frequence = frequence;
        return;
    }

    list->tail->next = createPage(id);
    list->tail = list->tail->next;
    list->tail->frequence = frequence;

    updateMinimalFrequence(list);
}

bool referencePage(Pages *list, unsigned char id) {
    Page *current = list->head;

    if(!current) {
        printf("Lista vazia.\n");
        return 0;
    }

    while(current) {
        if(current->page == id) {
            current->frequence = current->frequence + 1;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void removeMinFrequence(Pages *list) {
    Page *page = list->minF;

    if (list->head == NULL || page == NULL) {
        printf("Lista vazia ou elemento minF não definido.\n");
        return;
    }

    // Se a página com menor frequência estiver na cabeça da lista
    if (list->head == page) {
        list->head = list->head->next;
        if (list->head == NULL) {
            list->tail = NULL;  // Se a lista ficou vazia, ajuste o tail
        }
        free(page);
        return;
    }

    Page *prev = NULL;
    Page *current = list->head;

    while (current != NULL) {
        if (current == page) {
            if (prev != NULL) {
                prev->next = current->next;
            }
            if (current->next == NULL) {
                list->tail = prev;  // Se a página removida era a última, ajuste o tail
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void replace(Pages *list, unsigned char newId) {
    removeMinFrequence(list);
    insertPage(list, newId, 1);
}

void printList(Pages *list) {
    if(list->head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Page *current = list->head;

    printf("Head -> ");
    do {
        printf("|%d|%d| -> ", current->page, current->frequence);
        current = current->next;
    } while (current);
    printf("Tail\n");
}

void updateMinimalFrequence(Pages *list) {
    Page *minimal = list->head;
    Page *current = list->head;

    do {
        if (current->frequence < minimal->frequence)
            minimal = current;

        current = current->next;
    } while (current);

    list->minF = minimal;
}

// Função para implementar o algoritmo FIFO com frequências
void FIFOF(int pages[], int n, int capacidade) {
    // int *quadros = (int *)malloc(capacidade * sizeof(int));
    Pages *list = List(3);
    char faltasDePagina = 0;

    for (int i = 0; i < n; i++) {
        int pagina = pages[i];

        // Página não encontrada nos quadros (caso de falta de página)
        if (!referencePage(list, pagina)) {
            replace(list, pagina);    // Faz a troca da página
            faltasDePagina++;
        } else {
            updateMinimalFrequence(list);
        }
        
        printList(list);    // Exibe o estado atual dos quadros
    }
    printf("\nTotal de faltas de página: %d\n", faltasDePagina);
}