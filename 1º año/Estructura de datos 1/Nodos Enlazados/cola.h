#ifndef COLA_H
#define COLA_H
#include <iostream>

using namespace std;

typedef char cadena[30];

struct Cadena
{
    cadena nombre;
    cadena apellidos;
    cadena dni;
};

struct TNodo_Cola {
    Cadena Datos; //Datos a almacenar en cada nodo
    TNodo_Cola *Siguiente; //Puntero al siguiente nodo
};

class cola {
    TNodo_Cola *Inicio; //Puntero al inicio de la cola.
    TNodo_Cola *Fin; //Puntero al fin de la cola.
    int ne; //nº de nodos que tiene la lista
public:
    cola(); //constructor de la clase
    ~cola(); //destructor de la clase
    void encolar(Cadena e);
    void desencolar();
    bool esvacia();
    Cadena primero() ;
    int longitud();
};

#endif // COLA_H
