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

void cola::encolar(Paciente p)
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
        elementos[fin]=p;
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

void cola::menores_al_apellido(cadena apellido)
{
    bool encontrado=false;
    int i=0;
    cola aux,c;
    while(i<c.longitud())
    {
        if(strcmp(apellido,elementos[i].apellidos)>0)
        {
            cout<<"\n-----------------------------------------"<<endl;
            cout<<"Nombre\t\tApellido\tEdad"<<endl;
            cout<<elementos[i].nombre<<"\t"<<elementos[i].apellidos<<"\t"<<elementos[i].edad<<endl;
            cout<<"\n-----------------------------------------"<<endl;
        }
        i++;
    }

}
void cola::mayores_al_apellido(cadena apellido)
{
    bool encontrado=false;
    int i=0;
    cola aux,c;
    while(i<c.longitud())
    {
        if(strcmp(apellido,elementos[i].apellidos)<0)
        {
            cout<<"\n-----------------------------------------"<<endl;
            cout<<"Nombre\t\tApellido\tEdad"<<endl;
            cout<<elementos[i].nombre<<"\t"<<elementos[i].apellidos<<"\t"<<elementos[i].edad<<endl;
            cout<<"\n-----------------------------------------"<<endl;
        }
        i++;
    }
}
