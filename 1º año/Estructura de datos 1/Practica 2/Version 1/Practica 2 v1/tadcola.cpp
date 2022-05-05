#include "tadcola.h"

//FICHERO TADCola.cpp
//#include "TadCola.h"
cola::cola()
{
    elementos=new Paciente[INCREMENTO];
    if(elementos!=NULL)
    {
        ne=fin=inicio=0;
        Tama=INCREMENTO;
    }
    else
    {
        ne=fin=inicio=-1;
        Tama=-1;
    }
}
cola::~cola()
{
    if(elementos!=NULL)
    {
        delete [] elementos;
    }
    elementos=NULL;
    ne=fin=inicio=-1;
    Tama=0;
}
Paciente cola::primero()
{
    return elementos[inicio];
}
bool cola::esvacia()
{
    return (ne==0);
}
int cola::longitud()
{
    return ne;
}

void cola::encolar(Paciente e)
{
    if(ne==Tama)
    {
        Paciente *NuevaZona=new Paciente[Tama+INCREMENTO];
        if(NuevaZona!=NULL)
        {
            for(int i=0;i<ne;i++)
            {
                NuevaZona[i]=elementos[inicio];
                inicio++;
                if(inicio==Tama) // inicio=(inicio+1)%Tama
                    inicio=0;
            }
            inicio=0;
            fin=ne;
            Tama+=INCREMENTO;
            delete elementos;
            elementos=NuevaZona;
        }
    };
    if(ne<Tama)
    {
        elementos[fin]=e;
        fin=(fin+1)%Tama;
        ne++;
    }
}

void cola::desencolar()
{
    inicio++; // inicio=(inicio+1)%Tama
    if(inicio==Tama)
        inicio=0;
    ne--;
    if(Tama-ne>=INCREMENTO && Tama>INCREMENTO)
    {
        Paciente *NuevaZona=new Paciente[Tama-INCREMENTO];
        if(NuevaZona!=NULL)
        {
            for(int i=0;i<ne;i++)
            {
                NuevaZona[i]=elementos[inicio++];
                if(inicio==Tama)
                    inicio=0;
            }
            Tama-=INCREMENTO;
            inicio=0;
            fin=Tama;
            delete [] elementos;
            elementos=NuevaZona;
        };
    };
}
/*
//#include "cola.h"

using namespace std;

cola::cola()
{
    Inicio=NULL;
    Fin=NULL;
    ne=0;
}

cola::~cola()
{
    TNodo_cola *Nodo_Borr;
    while(Inicio!=NULL)
    {
        Nodo_Borr=Inicio;
        Inicio=Nodo_Borr -> Siguiente;
        delete Nodo_Borr;
    }

    Fin=NULL;
    ne=0;
}

void cola::encolar(Paciente e)
{
    TNodo_cola *Nodo_Aux=new TNodo_cola;
    if(Nodo_Aux!=NULL)
    {
        Nodo_Aux ->Datos=e;
        Nodo_Aux ->Siguiente=NULL;
        if(Inicio!=NULL)
        {
            Fin->Siguiente=Nodo_Aux;
        }else
            Inicio=Nodo_Aux;

        Fin=Nodo_Aux;
        ne++;
    }
}

int cola::longitud()
{
    return ne;
}

void cola::desencolar()
{
    TNodo_cola *Nodo_Aux=Inicio;
    Inicio=Nodo_Aux->Siguiente;
    delete Nodo_Aux;
    ne--;
    if(ne==0)
        Fin=NULL;
}

Paciente cola::primero()
{
    return Inicio->Datos;
}

bool cola::esvacia()
{
    return (Inicio==NULL);
}
*/
