#ifndef LEAMAZON_P1_ARBOREHEAP_H
#define LEAMAZON_P1_ARBOREHEAP_H

#include <utility>
#include <iostream>


struct arbore_heap {
    int* heap;
    int marime;
    int capacitate;
};

void initAH(arbore_heap*&);
void inserare(arbore_heap* arboreHeap, int valoare);
int stergere(arbore_heap* arboreHeap);

int smallest_k(arbore_heap* arboreHeap, int k);
int biggest_k(arbore_heap* arboreHeap, int k);

void afisare(arbore_heap* arboreHeap);

#endif
