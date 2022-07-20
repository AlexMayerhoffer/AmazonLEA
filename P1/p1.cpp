#include <iostream>
#include "ArboreHeap.h"

//Structura de date aleasa este arborele heap. Cei doi algoritmi eficienti constau in faptul ca mereu radacina este cel
//mai mic element (Implementare MinHeap in cazul de fata). Astfel, dupa k eliminari ale radacinii succesive, se obtine
//al k-lea cel mai mic element. Tot in aceasta modalitate se poate obtine si al k-lea cel mai mare, unde acesta se v-a
//obtine dupa n-k eliminari ale radacinii.
//Astfel, algorimtii pentru cel mai mic k si cel mai mare k element sunt de ordin O(n*log(n))

int main() {
    int x;
    arbore_heap* arboreHeap = new arbore_heap;
    initAH(arboreHeap);

    int N;
    std::cout << "N: ";
    std::cin >> N;
    std::cout << "Citeste N numere: ";
    for(int i = 0; i<N; i++)
    {
        std::cin >> x;
        inserare(arboreHeap, x);
    }
    afisare(arboreHeap);

    std::cout << "Cel mai mic K: ";
    int k;
    std::cin>>k;
    std::cout<< "\nSmallest k-th: " << smallest_k(arboreHeap,k) << '\n';

    //TODO implementeaza biggest_k
    //biggest_k(arboreHeap, 1);
    return 0;
}
