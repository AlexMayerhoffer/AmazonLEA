#include <iostream>
#include "Pattern.h"
#include <list>

//Cautarea brute-force este ineficienta, lucrand in O(n^2)
//In cazul programului de fata, sirurile nu se parcurg din fiecare index verificand pattern-ul
//ci se parcurge o singura data sirul, calculandu-se cate o valoare hash pentru fiecare subsir
//Acest lucru se face prin calcul recursiv, folosindu-se valoarea precedenta.
//Aceasta parcurgere se face in O(n + k), unde n este lungimea sirului si k este lungimea patternului


int main() {
    char *T = nullptr, *P = nullptr;            //Initializare siruri caractere
    int n = 0, m = 0;

    citire(T,n,P,m);                //Citire

    int* ti = nullptr;
    int k = 0;
    computeBasisVector(T,n,m,ti,k);         //Calculam vectorul ti

    int ti_pattern = hashPattern(P, 0, m, computeCardinal(T,n));
    //Obtinem valoarea hash a pattern-ului P

    std::list<int> indexes;
    for(int index = 0; index < n-m+1; index++)
    {
        if (ti_pattern == ti[index])
        {
            if(comparePattern(T,P,index, m)) //In cazul unei potriviri false,
                // efectuam inca o verificare suplimentara
                indexes.push_back(index);
        }
    }

    if(!indexes.empty()) {
        std::cout << "Indexii potrivirii: ";
        for (auto index: indexes)
            std::cout << index << ' ';
        std::cout << '\n';
    }
    else
        std::cout << "Nu s-a gasit patternul!\n";

    delete[] T;
    delete[] P;

    return 0;
}
