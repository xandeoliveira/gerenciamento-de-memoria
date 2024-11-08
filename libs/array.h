#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de geração de lista com itens aleatórios
int * generatePages(int n, int min, int max);

// Função auxiliar para impressão de um array de páginas
void printPages(int * pages, int size);

// Função para implementar o algoritmo FIFO
void FIFO(int pages[], int n, int capacidade);

// Função auxiliar para deixar o código mais legível.
void test(int id, int n, int min, int max, int capacity);

#endif