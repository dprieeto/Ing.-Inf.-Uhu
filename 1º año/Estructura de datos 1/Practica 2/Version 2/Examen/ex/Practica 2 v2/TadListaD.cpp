#include "TadListaD.h"

Lista::Lista()
{
    //ctor

    /*
    primero= new TNodo_ListaD;
    ultimo=new TNodo_ListaD;
    primero->Sig=ultimo;
    ultimo->Ant=primero;
    primero->Ant=NULL;
    ultimo->Sig=NULL;
    */
    ///TNodo_ListaD *nd=new TNodo_ListaD;
    /// Eso solo lo puedo a hacer cuando vaya a crear un nodo(es decir insertar un nuevo nodo)
    ///seria asi en todo caso: TNodo_ListaD *nd; y ya luego lo igualo a primero, NULL o lo que sea

    ///EN TEORIA SEGUN BEJARANO ES ASI
    primero=NULL;
    ultimo=NULL;
    n=0;
}

Lista::~Lista()
{
    //dtor
    while(primero->Sig!=ultimo)
    {
        eliminarIzq();
    }
    delete primero;
    delete ultimo;
}

Paciente Lista::observarIzq()
{
    return primero->Sig->Datos;
}
Paciente Lista::observarDch()
{
    return ultimo->Ant->Datos;
}

void Lista::anadirIzq(Paciente p)
{
    TNodo_ListaD *nd=new TNodo_ListaD;
    nd->Datos=p;
    nd->Ant=primero; ///cambiamos el valor de sus punteros
    nd->Sig=primero->Sig;
    primero->Sig->Ant=nd;///el puntero anterior del primero es el nuevo nodo añadido
    primero->Sig=nd;
    n++;
}

void Lista::anadirDch(Paciente p)
{
    TNodo_ListaD *nd=new TNodo_ListaD;
    nd->Datos=p;
    nd->Ant=ultimo->Ant; ///el nodo anterior al ultimo
    nd->Sig=ultimo; ///el puntoero del nuevo nodo apunta al ultimo nodo
    nd->Ant->Sig=nd; ///a traves el ultimo nodo accedemos al anterior nodo para q apunte al nuevo nodo
    ultimo->Ant=nd;
    n++;
}

void Lista::eliminarIzq()
{
    TNodo_ListaD *nd=primero->Sig->Sig;///accedemos al primer nodo
    delete primero->Sig;
    primero->Sig=nd;
    nd->Ant=primero;
    n--;
}

void Lista::eliminarDch()
{
    TNodo_ListaD *nd=ultimo->Ant->Ant;
    delete ultimo->Ant;
    ultimo->Ant=nd;
    nd->Sig=ultimo;
    n--;
}

void Lista::mostrar_desde_el_principio()
{
    TNodo_ListaD *nd=primero->Sig;
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

void Lista::mostrar_desde_el_final()
{
    TNodo_ListaD *nd=ultimo->Ant;
    while(nd!=primero)
    {
        cout<<"------------------------------"<<endl;
        cout<<"\nNombre: "<<nd->Datos.nombre<<endl;
        cout<<"\nApellidos: "<<nd->Datos.apellidos<<endl;
        cout<<"\nEdad: "<<nd->Datos.edad<<endl;
        cout<<"\nIdentificador: "<<nd->Datos.id<<endl;
        cout<<"\n------------------------------"<<endl;
        nd=nd->Ant;
    }
}

int Lista::longitud()
{
    return n;
}

bool Lista::esvacia()
{
    return (n==0);
}

int Lista::posicion(int id)///FUNCIONA
{
    TNodo_ListaD *nd=primero;
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

void Lista::modificar(int i,Paciente p)///funciona
{
    //TNodo_ListaC *nd=new TNodo_ListaC;
    /*
    TNodo_ListaD *Nodo_Aux;
    Nodo_Aux->Datos=p;
    if (ultimo->Ant==NULL)
        Nodo_Aux=primero;
    else
        Nodo_Aux=ultimo->Sig;
    Nodo_Aux->Datos=p;*/
    ///¿?eliminar
    ///
    TNodo_ListaD *nuevo;//=new TNodo_ListaD;
    TNodo_ListaD *borrar;//=new TNodo_ListaD;
    nuevo=primero;
    borrar=primero;
    for(int j=0;j<i;j++)
    {
        nuevo=nuevo->Sig;
        borrar=borrar->Sig;
    }
    borrar->Ant->Sig=nuevo;
    nuevo->Sig=borrar->Sig;
    ///
    nuevo->Datos=p;

}

Paciente Lista::observar(int id)///funciona
{
    TNodo_ListaD *nd;//=new TNodo_ListaD;
    nd=primero;
    //int i,v=1;
    //i=posicion(id);
    /*
    for (int j=0;j<i;j++)
    {
        nd=nd->Sig;
        v++;
    }
    */
    int i=0;
    bool encontrado=false;
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
        }
    }
    return nd->Datos;
}

///falta eliminar

bool Lista::eliminarpornombre(char nombre[],char apellidos[])
{
    TNodo_ListaD *nd;//=new TNodo_ListaD;
    TNodo_ListaD *borrar;//=new TNodo_ListaD;
    borrar=primero;
    nd=primero;
    bool coincide=false;
    ///FALTA IF BORRAR==NULL
    while(borrar->Sig!=NULL&&!coincide)
    {
        if(strcmp(nombre,borrar->Datos.nombre)==0&&strcmp(apellidos,borrar->Datos.apellidos)==0)
        {
                coincide=true;
        }
        else
        {
            borrar=borrar->Sig;
        }
    }
    if(coincide)
    {
        cout<<"\nEl paciente atendido fue eliminado."<<endl;
        borrar->Ant->Sig=borrar->Sig;
        borrar->Sig->Ant=borrar->Ant;
        ///FALTA AQUI DELETE[] BORRAR;
        ///XK SI NO NO LO BORRA DE LA MEMORIA
        n--;
    }
    else
    {
        cout<<"\nActualmente no se encuentra en la lista un paciente con ese nombre y esos apellidos."<<endl;
    }

}
