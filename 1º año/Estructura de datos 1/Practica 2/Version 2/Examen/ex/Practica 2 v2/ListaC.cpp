#include "ListaC.h"

ListaC::ListaC()
{
    //ctor
    primero=new TNodo_ListaC;
    ultimo=new TNodo_ListaC;
    //primero=NULL;
    primero->Sig=ultimo;
    ultimo->Sig=primero;
    n=0;
}

ListaC::~ListaC()
{
    //dtor
    while(primero->Sig!=ultimo)
    {
        eliminarDch();
    }
    delete primero;
    delete ultimo;
}

Paciente ListaC::observarIzq()
{
    return primero->Sig->Datos;
}

Paciente ListaC::observarDch()
{
    return ultimo->Sig->Datos;
}

void ListaC::anadirDch(Paciente p)
{
    TNodo_ListaC *nd=new TNodo_ListaC;
    nd->Datos=p;
    nd->Sig=primero->Sig;
    primero->Sig=nd;
    n++;
}
/*
void ListaC::anadirIzq(Paciente p)
{
    TNodo_ListaC *nd=new TNodo_ListaC;
    nd->Datos=p;
    nd->Sig=ultimo->Sig;
    ultimo->Sig=primero;
    n++;
}
*/
void ListaC::eliminarDch()
{
    TNodo_ListaC *nd=new TNodo_ListaC;
    nd=primero->Sig;
    delete primero;
    primero=nd;
    n--;
}

void ListaC::mostrar_desde_el_principio()
{
    TNodo_ListaC *nd=primero->Sig;
    while(nd!=ultimo)
    {
        cout<<"------------------------------"<<endl;
        cout<<"\nNombre: "<<nd->Datos.nombre<<endl;
        cout<<"\nApellidos: "<<nd->Datos.apellidos<<endl;
        cout<<"\nEdad: "<<nd->Datos.edad<<endl;
        cout<<"\nIdentificador: "<<nd->Datos.id<<endl;
        cout<<"\n------------------------------"<<endl;
        nd=nd->Sig;
    }
}
int ListaC::longitud()
{
    return n;
}

bool ListaC::esvacia()
{
    return (n==0);
}

int ListaC::posicion(int id)
{
    TNodo_ListaC *nd=primero;
    //TNodo_ListaC *nd=primero->Sig;
    bool encontrado=false;
    //nd->Sig=primero;
    int i=0,pos=-1;
    while(nd!=NULL&&!encontrado)
    {
        if(nd->Datos.id!=id)
        {
            nd=nd->Sig;
            i++;
        }
        else
        {
            encontrado=true;
            pos=i;
        }
    }
    //return pos;
    return (encontrado?pos:-1);
}

void ListaC::modificar(int i,Paciente p)
{

    //TNodo_ListaC *nd=new TNodo_ListaC;

    TNodo_ListaC *Nodo_Ant=anterior(i),*Nodo_Aux;
    if (Nodo_Ant==NULL)
        Nodo_Aux=primero;
    else
        Nodo_Aux=Nodo_Ant->Sig;
    Nodo_Aux->Datos=p;

}

TNodo_ListaC *ListaC::anterior(int i)
{
    TNodo_ListaC *nd=primero,*Nodo_Ant=NULL;
    int v=1;
    //if(nd!=NULL)
  //  {
        for(int j=1;j<i;j++)
        //while(nd!=NULL&&v<i)
        {
            nd=nd->Sig;
            v++;
        }
        Nodo_Ant=nd;
   // }
    return Nodo_Ant;
}

Paciente ListaC::observar(int i)
{
    TNodo_ListaC *Nodo_Ant=anterior(i),*nd;
    /*
    if(Nodo_Ant==NULL)
    {
        nd=primero;
    }
    else
    {
        nd=Nodo_Ant->Sig;
    }*/
    ///funciona sin anterior
    /*
    nd=primero;

    for(int j=0;j<i;j++)
    {
        nd=nd->Sig;
    }
    //nd=Nodo_Ant->Sig;
    */
    ///
    nd=Nodo_Ant->Sig;


    return nd->Datos;
}

void ListaC::eliminar(int i)
{
    TNodo_ListaC *Nodo_Ant,*Nodo_Aux;
    Nodo_Ant=anterior(i);
    if (Nodo_Ant==NULL) {
        Nodo_Aux=primero;
        primero=Nodo_Aux->Sig;
    }
    else {
        Nodo_Aux=Nodo_Ant->Sig;
        Nodo_Ant->Sig=Nodo_Aux->Sig;
    }
    delete Nodo_Aux;
    n--;
}

