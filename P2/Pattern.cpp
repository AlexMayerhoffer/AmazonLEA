//
// Created by ottoa on 6/8/2022.
//
#include "Pattern.h"
#include <cmath>

#define ASCII_SIZE 128
#define OFFSET_ASCII 32
#define Q 127

void citire(char* &T, int &n, char* &P, int &m) {
    std::cout<<"Lungimea Sirului (n): ";
    std::cin >> n;

    T = new char[n];
    std::cout << "Sirul: ";
    for(int index = 0; index < n; index++)
        std::cin >> T[index];

    std::cout<<"Lungimea Pattern-ului (m): ";
    std::cin >> m;

    P = new char[m];
    std::cout<<"Pattern-ul: ";
    for(int index = 0; index < m; index++)
        std::cin >> P[index];
}

int computeCardinal(const char *T, int n) {
    int b = 0;
    int *check_character = new int[ASCII_SIZE - OFFSET_ASCII];

    for (int index = 0; index < ASCII_SIZE - OFFSET_ASCII; index++) {
        check_character[index] = 0;
    }

    for (int index = 0; index < n; index++) {
        if(check_character[T[index] - OFFSET_ASCII] == 0) {
            b = b + 1;
            check_character[T[index] - OFFSET_ASCII] = 1;
        }
    }

    return b;
}


//In afara de ti[0] unde calculul este O(m) - unde m este lungimea patternului -
//algoritmul de calculare vectorului ti este O(n),
//calculandu-se fiecare element in functie de precedentul
void computeBasisVector(const char *T, int n, int m, int* &ti, int &k) {
    k = n - m + 1;                                  //Lungimea vectorului ti;
    ti = new int[k];

    int b = computeCardinal(T, n);                  //Calculam cardinalul pentru a obtine baza calculelor

    ti[0] = hashPattern(T,0,m,b); //Primul element din ti este calculat separat cu functia hash
    for(int index = 1; index < k; index++) { //Se calculeaza fiecare element din ti folosind predecesorul
        int x = ti[index-1] * (b+1);
        int y = x - (T[index-1] - OFFSET_ASCII + 1) * (int)std::pow(b+1, m) % Q;
        int z = y + (T[index+m-1] - OFFSET_ASCII + 1);
        ti[index] = z % Q;
    }
}

//Calculeaza valoarea hash ti intr-o anumita baza b a unui sir de caractere. O(n)
int hashPattern(const char *P, int start, int end, int b) {

    int hash_val = 0;

    for(int index = start; index < end ; index++) {
        int putere = (int)std::pow(b+1, end - index - 1);
        int numar = (P[index] - OFFSET_ASCII + 1);
        hash_val +=  (putere * numar) % Q;
    }
    return hash_val % Q;
}

//Functie de verificare potrivire falsa. O(n)
bool comparePattern(const char *T, const char *P, int start, int m) {
    for(int index = 0; index < m; index++)
        if(T[start + index] != P[index])
            return false;
    return true;
}

