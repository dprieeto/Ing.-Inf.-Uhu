#include "cola.h"

cola::cola()
{
    //ctor
    Inicio=NULL;
    Fin=NULL;
    ne=0;
}

cola::~cola()
{
    //dtor
    TNodo_Cola *Nodo_Borr;
    while (Inicio!=NULL)
    {
        Nodo_Borr=Inicio;
        Inicio=Nodo_Borr->Siguiente;
        delete Nodo_Borr;
    }
    Fin=NULL;
    ne=0;
}

void cola::encolar(Cadena e) {
    TNodo_Cola *Nodo_Aux=new TNodo_Cola;
    if (Nodo_Aux!=NULL)
    {
        Nodo_Aux->Datos=e;
        Nodo_Aux->Siguiente=NULL;
        if (Inicio!=NULL)
            Fin->Siguiente=Nodo_Aux;
        else
            Inicio=Nodo_Aux;
        Fin=Nodo_Aux;
        ne++;
    }
}

void cola::desencolar() {
    TNodo_Cola *Nodo_Aux=Inicio;
    Inicio=Nodo_Aux->Siguiente;
    delete Nodo_Aux;
    ne--;
    if (ne == 0)
        Fin = NULL;
}

Cadena cola::primero()
{
    return Inicio->Datos;
}

bool cola::esvacia()
{
    return Inicio==NULL;
}

int cola::longitud()
{
    return ne;
}

