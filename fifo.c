#include "libs/array.h"
#include "libs/list.h"

int main() {
    srand(time(NULL));

    int n = 10;
    int *pages = generatePages(n, 1, 10);
    // int pages[] = {4, 3, 2, 4, 1, 4, 3, 1, 2, 2};

    printPages(pages, n);

    printf("FIFO normal.\n");
    FIFO(pages, n, 3);

    printf("FIFO com frequência.\n");
    FIFOF(pages, n, 3);

    return 0;
}