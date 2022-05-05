#ifndef TADLISTAD_H
#define TADLISTAD_H
#include <iostream>
#include "ColaPri.h"

using namespace std;

struct TNodo_ListaD
{
    Paciente Datos;
    TNodo_ListaD *Ant;
    TNodo_ListaD *Sig;
};



class Lista
{
    //TNodo_ListaD *elementos;
    TNodo_ListaD *primero;
    TNodo_ListaD *ultimo;
    int n; //numero de nodos
public:
    Lista();
    ~Lista();
    Paciente observarIzq();///devuelve el primer paciente del nodo
    Paciente observarDch();///devuelve el ultimo paciente del nodo
    void anadirIzq(Paciente p);///añade un paciente al principio de la lista
    void anadirDch(Paciente p);///añade un paciente al final de la lista
    void eliminarIzq();///elimina el primer paciente al principio del a lista
    void eliminarDch();///elimina el primer paciente al final de la lista
    void mostrar_desde_el_principio();
    void mostrar_desde_el_final();
    int longitud();
    bool esvacia();
    int posicion(int id);
    void modificar(int i,Paciente p);
    Paciente observar(int i);
    //void eliminar(int i,Paciente p);///falta por hacer
    bool eliminarpornombre(char nombre[],char apellidos[]);///metodo del examen
    /*
    Lista(Paciente p);


    //void concatenar(Lista(1));
    void insertar(int i,Paciente p);
    void eliminar(int i,Paciente p);
    void modificar(int i);
    Paciente observar(int i);
    int posicion(Paciente p);
    */
};

#endif // TADLISTAD_H
