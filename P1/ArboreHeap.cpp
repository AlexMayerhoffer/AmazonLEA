#include "ArboreHeap.h"


//O(log(n)), unde cel mai defavorabil caz este cand numarul inserat este mai mare decat restul
void inserare(arbore_heap *arboreHeap, int valoare) {
    arboreHeap->heap[arboreHeap->marime] = valoare;
    arboreHeap->marime++;

    int fiu = arboreHeap->marime;
    int parinte = arboreHeap->marime / 2;

    while (parinte) {
        if (arboreHeap->heap[parinte-1] < arboreHeap->heap[fiu-1]) {
            std::swap(arboreHeap->heap[parinte-1], arboreHeap->heap[fiu-1]);
            fiu = parinte;
            parinte /= 2;
        }
        else {
            parinte = 0;
        }
    }
}

//O(log(n))
int stergere(arbore_heap *arboreHeap) {
    if (arboreHeap->marime == 0) {
        std::cout << "Eroare! Arbore heap gol!\n";
        return 0;
    }
    else {
        int val_return = arboreHeap->heap[1];
        arboreHeap->heap[1] = arboreHeap->heap[arboreHeap->marime];
        arboreHeap->marime--;
        int parinte = 1;
        int fiu = 2;

        while(fiu <= arboreHeap->marime) {
            if (fiu + 1 < arboreHeap->marime && arboreHeap->heap[fiu] < arboreHeap->heap[fiu + 1]) {
                fiu++;
            }
            if (arboreHeap->heap[fiu] > arboreHeap->heap[parinte]) {
                std::swap(arboreHeap->heap[parinte], arboreHeap->heap[fiu]);
                parinte = fiu;
                fiu *= 2;
            }
            else {
                fiu = arboreHeap->marime + 1;
            }
        }
        return val_return;
    }
}

void initAH(arbore_heap*& arboreHeap) {
    arboreHeap->heap = new int[20];
    arboreHeap->marime = 0;
    arboreHeap->capacitate = 20;
}

int smallest_k(arbore_heap *arboreHeap, int k) {
    return stergere(arboreHeap);
}

int biggest_k(arbore_heap *arboreHeap, int k) {
    return 0;
}

void afisare(arbore_heap* arboreHeap) {
    for(int i = 0; i<arboreHeap->marime;i++)
        std::cout <<arboreHeap->heap[i] << " ";
    std::cout << std::endl;
}
