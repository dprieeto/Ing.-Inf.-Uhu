#ifndef TRES_H
#define TRES_H
#include <iostream>
#define M 10
#define N 15
#include <conio.h>

using namespace std;

class tres
{
    int tabla[M][N];
public:
    void cargar();
    int encontrar();
};

#endif // TRES_H
