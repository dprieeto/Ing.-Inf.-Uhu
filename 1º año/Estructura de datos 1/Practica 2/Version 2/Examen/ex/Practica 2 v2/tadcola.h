#ifndef TADCOLA_H
#define TADCOLA_H
//#include "ColaPri.h"
#include <iostream>
#include <string.h>
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

class cola
{
 Paciente *elementos; //elementos de la cola
 int inicio, fin; //principio y fin de la cola
 int Tama; //Capacidad de la tabla
 int ne; //Nº de elementos
 public:
 cola(); // constructor de la clase
 ~cola(); // destructor de la clase
 void encolar(Paciente p);
 void desencolar();
 bool esvacia();
 Paciente primero() ;
 int longitud();
 void menores_al_apellido(cadena apellido);
 void mayores_al_apellido(cadena apellido);
};


#endif // TADCOLA_H

