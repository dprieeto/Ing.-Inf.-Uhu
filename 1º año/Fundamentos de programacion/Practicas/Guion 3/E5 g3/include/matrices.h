#ifndef MATRICES_H
#define MATRICES_H
#include <iostream>
#include <stdlib.h>
#define M 2
#define N 4
#include <string.h>
typedef char cadena[30];

using namespace std;

struct persona
{
    int dni;
    cadena nombre;
};

class matrices
{
    persona tabla[M][N];
public:
    void cargar();
    void encontrar();
};

#endif // MATRICES_H
