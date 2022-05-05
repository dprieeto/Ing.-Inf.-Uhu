#ifndef PILA_H
#define PILA_H
#include <iostream>

using namespace std;

typedef char cadena[30];

struct Cadena
{
    cadena nombre;
    cadena apellidos;
    cadena dni;
};

struct TNodo_Pila
{
    Cadena Datos; // Dato a almacenar en cada nodo
    TNodo_Pila *Siguiente; // Puntero al siguiente nodo
};

class pila
{
    TNodo_Pila *elementos; // elementos de la pila
    int n; // nº de nodos que tiene la lista
public:
    pila(); //constructor de la clase
    ~pila(); // destructor de la clase
    void apilar(Cadena e);
    void desapilar();
    bool esvacia();
    Cadena cima() ;
    int longitud();
};


#endif // PILA_H
