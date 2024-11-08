#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef unsigned char bool;

typedef struct Page Page;
struct Page{
    char page;
    Page *next;
    unsigned char frequence;
};

typedef struct Pages Pages;
struct Pages{
    Page *head;
    Page *tail;
    Page *minF;
};

Page * createPage(unsigned char id);

Pages * List(char capacity);

void insertPage(Pages *list, char id, char frequence);

bool referencePage(Pages *list, unsigned char id);

void removeMinFrequence(Pages *list);

void replace(Pages *list, unsigned char newId);

void printList(Pages *list);

void updateMinimalFrequence(Pages *list);

void FIFOF(int pages[], int n, int capacidade);

#endif