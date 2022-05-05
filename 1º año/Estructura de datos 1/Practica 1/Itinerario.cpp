#include <iostream>
#include <fstream>
#include <string.h>
#include "Itinerario.h"

using namespace std;

itinerarios::itinerarios()
{
    cargado=false;
    tam=0;
    n=0;
    elementos = NULL;

    fichero.open("Itinerario.dat", ios::in | ios::out |ios::binary);
    if(fichero.fail())
    {
        fichero.close();
        fichero.clear();
        fichero.open("Itinerario.dat", ios::in | ios::out | ios::binary); //Crea el fichero
        fichero.close();
        fichero.clear();
        fichero.open("Itinerario.dat", ios::in | ios::out | ios:: app| ios::binary);
    }

    fichero.seekg(0, ios::end);
    n=fichero.tellg()/sizeof(itinerario);

    fichero.close();
}

void itinerarios::Insertar(itinerario i) ///HECHO
{

    if(cargado)
    {
        if(Buscar(i.nombre, i.matricula)==-1)
        {
            if(n==tam)
            {
               itinerario *aux;
               aux=new itinerario[tam+SALTO];

                for(int i=0; i<n; i++)
                {
                    aux[i]=elementos[i];
                }

                delete [] elementos;
                elementos = new itinerario [tam +SALTO];

                for(int i=0; i<n; i++)
                {
                    elementos[i]=aux[i];
                }
                elementos[n]=i;
                tam=tam+SALTO;
                n++;
                delete [] aux;
            }else
            {
                elementos[n]=i;
                n++;
            }
        }else
        {

            cout << "La matricula ya existe. No se puede añadir." << endl;
       }
    }else
        cout << "No se han cargado los datos." << endl;
}

void itinerarios::Borrar(cadena nombrei, cadena mat, int pos) ///HECHO
{
   if(pos==-1)
    {
        pos=Buscar(nombrei, mat);
    }
    if(cargado)
    {
        for(int i=pos; i<n;i++)
        {
            elementos[i]=elementos[i+1];
        }
        n--;
    }else
        cout << "No se han cargado los datos." << endl;

}

void itinerarios::Modificar(itinerario a, cadena nombrei, cadena mat, int pos) ///HECHO
{
    if(pos==-1)
    {
        pos=Buscar(nombrei, mat);
    }
    if(cargado)
    {
        elementos[pos]=a;
    }else
        cout << "No se han cargado los datos." << endl;
}

int itinerarios::Buscar(cadena nombrei, cadena mat) ///HECHO
{
   int pos=-1, i=0;
    bool encontrado=false;

    if(cargado)
    {
        while(i<tam && !encontrado)
        {
            if(strcmp(elementos[i].matricula, mat)==0 && strcmp(elementos[i].nombre, nombrei)==0)
            {
                encontrado=true;
                pos=i;
            }else
                i++;
        }
        if(encontrado==true)
        {
            cout << "La matricula se ha encontrado correctamente." << endl;
            cout << "=====================================" << endl;
            cout << "Itinerario: " <<elementos[i].nombre << endl;
            cout << "Origen: " << elementos[i].origen << endl;
            cout << "Destino: " << elementos[i].destino << endl;
            cout << "Inicio: " << elementos[i].inicio.h << ":" << elementos[i].inicio.m << " " << elementos[i].inicio.am << endl;
            cout << "Fin: " << elementos[i].fin.h << ":" << elementos[i].fin.m << " " << elementos[i].fin.am << endl;
            cout << "Matricula: " << elementos[i].matricula << endl;
            cout << "=====================================" << endl;
        }else
            cout << "La matricula y nombre no coinciden." << endl;
    }else
        cout << "No se han cargado los datos." << endl;

    return pos;
   /* int pos=-1,i=0;
    bool repetida=false;
    if(cargado)
    {
        cout<<"\nTrapbajando en memoria."<<endl;
        while(i<n&&!repetida)
        {
            if(strcmp(elementos[i].nombre,nombrei)==0&&strcmp(elementos[i].matricula,mat)==0)
            {
                    pos=i;
                    cout<<"-----------------------------"<<endl;
                    cout<<"Nombre: "<<elementos[i].nombre<<endl;
                    cout<<"Matricula: "<<elementos[i].matricula<<endl;
                    cout<<"Origen: "<<elementos[i].origen<<endl;
                    cout<<"Destino: "<<elementos[i].destino<<endl;
                    cout<<"Hora de salida: "<<elementos[i].inicio.h<<":"<<elementos[i].inicio.m<<(elementos[i].inicio.am?"am":"pm")<<endl;
                    cout<<"Hora de llegada: "<<elementos[i].fin.h<<":"<<elementos[i].fin.m<<(elementos[i].fin.am?"am":"pm")<<endl;
                    repetida=true;
            }
            else i++;
        }
    }
    else
    {
        cout<<"\nTienes que cargar los datos del fichero en la memoria primero."<<endl;
    }
    if(repetida)
            cout<<"\nLa matricula esta ya existe en ese itinerario."<<endl;
        else
            cout<<"\nLa matricula no existe."<<endl;
    return pos;*/
}


void itinerarios::Listar() ///HECHO
{
    if(cargado)
    {
        for(int i=0; i<n; i++)
        {
            cout << "Itinerario: " << elementos[i].nombre << endl;
            cout << "Origen: " << elementos[i].origen << endl;
            cout << "Destino: " << elementos[i].destino << endl;
            cout << "Inicio: " << elementos[i].inicio.h << ":" << elementos[i].inicio.m << " " << (elementos[i].inicio.am?"AM":"PM") << endl;
            cout << "Fin: " << elementos[i].fin.h << ":" << elementos[i].fin.m << " " << (elementos[i].fin.am?"AM":"PM") << endl;
            cout << "Matricula: " << elementos[i].matricula << endl;
        }
   }else
        cout << "No se han cargado los datos." << endl;
}

bool itinerarios::Cargar()
{
    int i=0;
    itinerario b;
    elementos = new itinerario[tam];

    fichero.open("Itinerario.dat", ios::in | ios::binary);
    if(fichero.fail())
    {
        cout <<"Error" << endl;
    }else
    {

        while(tam<=n)
        {
            tam=tam+SALTO;
        }

        for(int i=0; i<n; i++)
        {
            fichero.seekg(sizeof(itinerario)*i, ios::beg);
            fichero.read((char *) &b, sizeof(itinerario));
            elementos[i]=b;

            cout << "Itinerario: " << elementos[i].nombre << endl;
            cout << "Origen: " << elementos[i].origen << endl;
            cout << "Destino: " << elementos[i].destino << endl;
            cout << "Inicio: " << elementos[i].inicio.h << ":" << elementos[i].inicio.m << " " << (elementos[i].inicio.am?"AM":"PM") << endl;
            cout << "Fin: " << elementos[i].fin.h << ":" << elementos[i].fin.m << " " << (elementos[i].fin.am?"AM":"PM") << endl;
            cout << "Matricula: " << elementos[i].matricula << endl;
        }

        cout << "Se ha cargado correctamente." << endl;
        cargado=true;

        elementos[tam];
    }
    fichero.close();
    return cargado;
}

bool itinerarios::Guardar()
{
    itinerario i;
    bool guardado=false;

    fichero.open("Itinerario.dat", ios::in | ios::out | ios::binary);
    if(fichero.fail())
    {
        cout << "No se ha podido guardar el fichero." << endl;
    }else
    {
        for(int i=0; i<n; i++)
        {
            fichero.seekp(sizeof(itinerario)*i, ios::beg);
            fichero.write((char *) &elementos[i], sizeof(itinerario));
        }

        cout << "Se ha guardado correctamente." << endl;

        cargado=false;
        delete [] elementos;
        tam=0;
        elementos=NULL;
        guardado=true;
    }

    fichero.close();
    return guardado;
}

void itinerarios::itinerariosenintervalo(int horaini, int horafin)
{
    /*Cargar();
    int totalini, totalfin, elementosini, elementosfin;
    totalini = horaini.h * 60 + horaini.m;
    if(horaini.am == false)
        totalini = totalini + 720;

    totalfin = horafin.h * 60 + horafin.m;
    if(horafin.am == false)
        totalfin = totalfin + 720;

    for(int i= 0; i<n; i++)
    {
        elementosini = elementos[i].inicio.h*60 + elementos[i].inicio.m;
        if(elementos[i].inicio.am == false)
            elementosini = elementosini +720;

        elementosfin = elementos[i].fin.h * 60 + elementos[i].fin.m;
        if(elementos[i].fin.am == false)
            elementosfin = elementosfin + 720;

        if(elementosini >= totalini || elementosfin <= totalfin)
        {
            cout<<"\n----------ITINERARIO----------";
            cout << "\nItinerario: " << elementos[i].nombre<< endl;
            cout << "Origen: " << elementos[i].origen << endl;
            cout << "Destino: " << elementos[i].destino << endl;
            cout << "Inicio: " << elementos[i].inicio.h << ":" << elementos[i].inicio.m;
            if(elementos[i].inicio.am == true)
                cout << "am";
            else
                cout << "pm";

            cout << "\nFin: " << elementos[i].fin.h << ":" << elementos[i].fin.m;
            if(elementos[i].fin.am == true)
                cout << "am";
            else
                cout << "pm";

            cout << "\nMatricula: " << elementos[i].matricula << endl;
        }
    }*/
}
