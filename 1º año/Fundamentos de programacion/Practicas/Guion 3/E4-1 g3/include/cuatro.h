#ifndef CUATRO_H
#define CUATRO_H
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define M 3
#define N 4
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
