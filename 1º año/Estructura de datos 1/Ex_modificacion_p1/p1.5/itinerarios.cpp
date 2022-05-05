#include "itinerarios.h"
#include <iostream>
#include <fstream>
#include <string.h>

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

void itinerarios::Insertar(itinerario i) ///FUNCIONA
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

void itinerarios::Borrar(cadena nombrei, cadena mat, int pos) ///FUNCIONA
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

void itinerarios::Modificar(itinerario a, cadena nombrei, cadena mat, int pos) ///FUNCIONA
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

int itinerarios::Buscar(cadena nombrei, cadena mat) ///FUNCIONA
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
}

void itinerarios::Listar() ///FUNCIONA
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

void itinerarios::itinerariosenintervalo(Hora horaini, Hora horafin) ///FUNCIONA
{
    Cargar();
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
            cout <<"============ITINERARIO============" << endl;
            cout << "\nItinerario: " << elementos[i].nombre<< endl;
            cout << "Origen: " << elementos[i].origen << endl;
            cout << "Destino: " << elementos[i].destino << endl;
            cout << "Inicio: " << elementos[i].inicio.h << ":" << elementos[i].inicio.m << endl;
            if(elementos[i].inicio.am == true)
                cout << "am" << endl;
            else
                cout << "pm" << endl;

            cout << "\nFin: " << elementos[i].fin.h << ":" << elementos[i].fin.m << endl;
            if(elementos[i].fin.am == true)
                cout << "am" << endl;
            else
                cout << "pm" << endl;

            cout << "\nMatricula: " << elementos[i].matricula << endl;
        }else
            cout << "No existe itinerario entre esa franja horaria." << endl;
    }
}


bool itinerarios::Cargar() ///FUNCIONA
{
    int i=0;
    itinerario b;
    bool necesita;

    fichero.open("Itinerario.dat", ios::in | ios::binary);
    if(fichero.fail())
    {
        cout <<"Error" << endl;
    }else
    {
        do
        {
            tam=tam+SALTO;
            if(n<tam || n&tam==0)
                necesita=true;
        }while(!necesita);
        elementos = new itinerario[tam];

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
    }
    fichero.close();
    delete[] elementos;
    return cargado;
}

bool itinerarios::Guardar() ///FUNCIONA
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
        tam=0;
        elementos=NULL;
        guardado=true;
    }

    fichero.close();
    return guardado;
}

void itinerarios::numerobuses(cadena origen) ///EN EL EXAMEN TENIA QUE SER TIPO INT LA FUNCION
{
    int contador=0;
    itinerario it;
    fichero.open("Itinerario.dat",ios::binary|ios::in);
    if(fichero.fail())
    {
        cout<<"\nError al abrir el fichero."<<endl;
    }
    else
    {
        fichero.seekg(0,ios::beg);
        fichero.read((char*)&it,sizeof(itinerario));
        while(!fichero.eof())
        {
            if(strcmp(origen,it.origen)==0)
            {
                contador++;
            }
            fichero.read((char*)&it,sizeof(itinerario));
        }
    }
    cout<<"\nEl numero de autobuses es: "<<contador<<"."<<endl;
    fichero.close();
}

