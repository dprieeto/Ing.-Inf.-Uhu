#include "pila.h"

pila::pila()
{
    //ctor
    elementos=NULL;
    n=0;
}

pila::~pila()
{
    //dtor
    TNodo_Pila *Nodo_Borr;
    while (elementos!=NULL) {
        Nodo_Borr=elementos;
        elementos=Nodo_Borr->Siguiente;
        delete Nodo_Borr;
    }
    n=0;
}

void pila::apilar(Cadena e) {
    TNodo_Pila *Nodo_Aux=new TNodo_Pila;
    if (Nodo_Aux!=NULL) {
        Nodo_Aux->Datos=e;
        Nodo_Aux->Siguiente=elementos;
        elementos=Nodo_Aux;
        n++;
    }
}

void pila::desapilar() {
    TNodo_Pila *Nodo_Aux=elementos;
    elementos=Nodo_Aux->Siguiente;
    delete Nodo_Aux;
    n--;
}

Cadena pila::cima() {
    return elementos->Datos;
}

bool pila::esvacia() {
    return elementos==NULL;
}
int pila::longitud() {
    return n;
}
