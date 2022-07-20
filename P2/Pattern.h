//
// Created by ottoa on 6/8/2022.
//

#ifndef LEAMAZON_P2_PATTERN_H
#define LEAMAZON_P2_PATTERN_H

#include <iostream>

void citire(char* &T, int &n, char* &P, int &m);
int computeCardinal(const char* T, int n);
void computeBasisVector(const char* T, int n, int m, int* &ti, int &k);
int hashPattern(const char* P, int start, int end, int b);
bool comparePattern(const char* T, const char* P, int start, int m);


#endif //LEAMAZON_P2_PATTERN_H
