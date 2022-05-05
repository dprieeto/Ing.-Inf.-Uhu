#ifndef LISTAC_H
#define LISTAC_H
#include <iostream>
#include "tadcola.h"

using namespace std;

struct TNodo_ListaC
{
    Paciente Datos;
    TNodo_ListaC *Sig;
};

class ListaC
{
    TNodo_ListaC *primero,*ultimo;
    TNodo_ListaC *anterior(int i);
    int n;
public:
    ListaC();
    ~ListaC();
    Paciente observarIzq();
    Paciente observarDch();
    //void anadirIzq(Paciente p);
    void anadirDch(Paciente p);///añade al principio
    void eliminarDch();///borra al principio
    //void eliminarIzq();
    void mostrar_desde_el_principio();
    //void mostrar_desde_el_final();
    int longitud();
    bool esvacia();
    int posicion(int id);
    void modificar(int i,Paciente p);
    Paciente observar(int i);
    void eliminar(int i);



};

#endif // LISTAC_H
