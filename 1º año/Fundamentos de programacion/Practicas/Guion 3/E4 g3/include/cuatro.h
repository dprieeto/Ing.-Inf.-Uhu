#ifndef CUATRO_H
#define CUATRO_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
#define M 2
#define N 3
typedef char cadena[30];
using namespace std;

class cuatro
{
    cadena tabla[M][N];
public:
    void cargar();
    void encontrar();
};

#endif // CUATRO_H
