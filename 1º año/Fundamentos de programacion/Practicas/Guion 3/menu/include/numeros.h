#ifndef NUMEROS_H
#define NUMEROS_H
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class numeros
{
     int a,b;bool estado=false;
 public:
    void sumar();
    void restar();
    void multiplicar();
    void dividir();
    void pedirdatos();
};

#endif // NUMEROS_H
