#ifndef TADCOLA_H
#define TADCOLA_H
//#include "ColaPri.h"
#include <iostream>
#define INCREMENTO 4

/// FICHERO TADCola.h
using namespace std;

const int TAM_CADENA=30;
typedef char cadena[TAM_CADENA];

struct Paciente
{
    int id;
    cadena nombre;
    cadena apellidos;
    int edad;
};
/*
struct TNodo_cola
{
    Paciente Datos;
    TNodo_cola *Siguiente;
};

class cola
{
    TNodo_cola *Inicio;
    TNodo_cola *Fin;
    int ne;
public:
    cola();
    ~cola();
    void encolar (Paciente e);
    void desencolar ();
    Paciente primero();
    bool esvacia();
    int longitud();
};
*/


class cola
{
 Paciente *elementos; //elementos de la cola
 int inicio, fin; //principio y fin de la cola
 int Tama; //Capacidad de la tabla
 int ne; //Nº de elementos
 public:
 cola(); // constructor de la clase
 ~cola(); // destructor de la clase
 void encolar(Paciente e);
 void desencolar();
 bool esvacia();
 Paciente primero() ;
 int longitud();
};


#endif // TADCOLA_H
