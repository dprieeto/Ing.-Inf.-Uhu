#ifndef UNO_H
#define UNO_H
#define M 3
#include <iostream>

using namespace std;
class uno
{
    int tabla[M];
public:
    void cargar();
    int maximo();
    int minimo();
};

#endif // UNO_H
