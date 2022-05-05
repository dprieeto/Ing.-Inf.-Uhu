#include <iostream>
#include <string.h>
#include "Autobus.h"

using namespace std;

autobuses::autobuses()
{
    elementos=new autobus[tam];
    cargado=false;

    fichero.open("Autobus.dat", ios::in | ios::out |ios::binary);
    if (fichero.fail())
    {
        fichero.close();
        fichero.clear();
        fichero.open("Autobus.dat", ios::binary | ios::out);///creamos el fichero
        n=0;
        fichero.close();
        fichero.clear();
        fichero.open("Autobus.dat", ios::binary | ios::out | ios::in);
    }else
    {


        n=0;
        fichero.seekg(sizeof(autobus), ios::end);
        //n=fichero.tellg()/sizeof(autobus);
        fichero.read((char*)&n, sizeof(autobus));
        tam=SALTO;
    }


    fichero.close();
}

void autobuses::Insertar(autobus a) ///FUNCIONA POR FICHEROS
{
    if(Buscar(a.matricula)!=-1)
    {
        cout << "La matricula ya existe. No se ha podido insertar." << endl;
    }else
    {
        if(cargado==false)
        {
            fichero.open("Autobus.dat", ios::out | ios::app | ios::binary);
            cout << "ESTAMOS EN FICHEROS." << endl;
            if(fichero.fail())
            {
                cout << "No se ha podido abrir el archivo." << endl;
            }else
            {
                fichero.write((char *) &a, sizeof(autobus));
                n++;

                cout << "Autobus insertado correctamente." << endl;
            }
            fichero.close();
        }else
        {
            cout << "ESTAMOS EN TABLA DINAMICA." << endl;

            elementos[n]=a;
            n++;

            cout << "Insertado correctamente." << endl;
        }
    }
}

void autobuses::Borrar(cadena mat, int pos) ///
{
    if(pos==-1)
    {
        pos=Buscar(mat);
    }
        if(cargado==false)
        {
            fichero.open("Autobus.dat", ios::in | ios::out | ios::binary);
            cout << "ESTAMOS EN FICHERO." << endl;
            if(fichero.fail())
            {
                cout << "No se ha podido abrir el fichero." << endl;
            }else
            {
                for(int i=pos; i<n; i++)
                {
                    fichero.seekp(pos*sizeof(autobus), ios::beg);
                    fichero.read((char *) &n, sizeof(autobus));
                    fichero.seekp(sizeof(autobus)*pos, ios::beg);
                    fichero.write((char *) &n, sizeof(autobus));
                    pos++;
                }
                    fichero.seekp(0, ios::beg);
                    fichero.write((char *)&n,sizeof(int));
                    fichero.close();
                    /*fichero.seekg(sizeof(autobus), ios::beg);
                    fichero.read((char *)&a, sizeof(autobus));
                    fichero.seekp((pos-1)*sizeof(autobus), ios::beg); //Posiciona antaes de escribir
                    fichero.write((char *)&a, sizeof(autobus));
                    n--;
                    fichero.seekp(0, ios::beg);
                    fichero.write((char *)&n,sizeof(int));
                    fichero.close();*/
            }
        }else
        {
            cout << "ESTAMOS EN TABLA DINAMICA" << endl;

            for(int i=pos; i<n;i++)
            {
                elementos[i]=elementos[i+1];
            }
        }
}

void autobuses::Modificar(autobus a, cadena mat, int pos) ///FUNCIONA POR FICHEROS
{
    if(pos==-1)
    {
        pos=Buscar(mat);
    }
        if(cargado==false)
        {
            fichero.open("Autobus.dat", ios::out | ios::in | ios::binary);
            cout << "ESTAMOS EN FICHERO." << endl;
            if(fichero.fail())
            {
                cout << "No se ha podido abrir el archivo." << endl;
            }else
            {
                fichero.seekg((pos-1)*sizeof(autobus), ios::beg);
                fichero.seekp((pos-1)*sizeof(autobus), ios::beg);
                fichero.write((char *) &a, sizeof(autobus));

                cout << "Autobus modificado correctamente." << endl;
            }
            fichero.close();
        }else
        {
            cout << "ESTAMOS EN TABLA DINAMICA." << endl;
            elementos[pos]=a;
        }

}

int autobuses::Buscar(cadena mat) ///FUNCIONA POR FICHEROS
{
    bool encontrado=false;
    int pos=-1;
    int k=0, i=1;
    autobus bus;
    if(cargado==true)
    {
        cout << "ESTAMOS EN TABLA DINAMICA." << endl;
        while(k<tam && !encontrado)
        {
            if(strcmp(elementos[k].matricula, mat)==0)
            {
                encontrado=true;
                cout << "--------------------------------" << endl;;
                cout << "Matricula: " << elementos[k].matricula << endl;
                cout << "Activo: " << elementos[k].e.activo << endl;
                cout << "Deposito: " << elementos[k].e.deposito << endl;
                cout << "Ocupacion: " << elementos[k].e.plazas << endl;
                cout << "ITV: " << elementos[k].e.itv << endl;
                cout << "Conductor: " << elementos[k].conductor << endl;
                cout << "--------------------------------" << endl;;
            }else
                k++;
        }

        if(encontrado==true)
        {
            cout << "La matricula ha sido encontrada." << endl;
            pos=k;
        }else
            cout << "La matricula no existe." << endl;
    }else
    {
        fichero.open("Autobus.dat", ios::in | ios::binary);
        if(fichero.fail())
        {
            cout << "No se ha podido abrir el archivo." << endl;
        }else
        {
            cout << "ESTAMOS EN FICHERO." << endl;
            fichero.read((char *) &bus, sizeof(autobus));
            while(!fichero.eof() && !encontrado)
            {
                if(strcmp(bus.matricula, mat)==0)
                {
                    encontrado=true;
                    cout << "--------------------------------" << endl;
                    cout << "Matricula: " << bus.matricula << endl;
                    cout << "Activo: " << bus.e.activo << endl;
                    cout << "Deposito: " << bus.e.deposito << endl;
                    cout << "Ocupacion: " << bus.e.plazas << endl;
                    cout << "ITV: " << bus.e.itv << endl;
                    cout << "Conductor: " << bus.conductor << endl;
                    cout << "--------------------------------" << endl;

                }else
                {
                    fichero.read((char *) &bus, sizeof(autobus));
                    i++;
                }
            }
            fichero.close();

            if(encontrado==true)
            {
                cout << "La matricula ha sido encontrada." << endl;
                pos=i;
            }else
                cout << "La matricula no existe." << endl;
        }
    }
    return pos;
}

void autobuses::Listar() ///FUNCIONA POR FICHEROS
{
    autobus bus;

    if(cargado)
    {
        cout << "ESTAMOS EN TABLA DINAMICA." <<endl;
        for(int i=0; i<n; i++)
        {
            cout << "============================" << endl;
            cout << "Matricula: " << elementos[i].matricula << endl;
            cout << "Activo: " << elementos[i].e.activo << endl;
            cout << "Deposito: " << elementos[i].e.deposito << endl;
            cout << "Ocupacion: " << elementos[i].e.plazas << endl;
            cout << "ITV: " << elementos[i].e.itv << endl;
            cout << "Conductor: " << elementos[i].conductor << endl;
            cout << "============================" << endl;
        }
    }else
    {
        fichero.open("Autobus.dat", ios::in | ios::binary);
        if(!fichero.fail())
        {
            cout << "ESTAMOS EN FICHERO." << endl;
            cout << n << endl;
            fichero.read((char *) &bus, sizeof(autobus));
            while(!fichero.eof())
            {
                cout << "Matricula: " << bus.matricula << endl;
                cout << "Activo: " << bus.e.activo << endl;
                cout << "Deposito: " << bus.e.deposito << endl;
                cout << "Ocupacion: " << bus.e.plazas << endl;
                cout << "ITV: " << bus.e.itv << endl;
                cout << "Conductor: " << bus.conductor << endl;
                fichero.read((char *) &bus, sizeof(autobus));
                cout << n << endl;
            }
        }else
            cout << "No se ha podido abrir correctamente." << endl;

    fichero.close();
    }
}

bool autobuses::Cargar() ///FUCIONA
{
    //elementos = new autobus[tam];
    int i=0;
    autobus b;
    if(n==tam)//Si es igual hay que ampliar el tamaño de la tabla.
    {
        elementos= new autobus[tam+SALTO];
    }else
    {
        elementos = new autobus[tam];
    }

    if(elementos != NULL)
        {
            /*fichero.open("Autobus.dat", ios::in | ios::binary);
            if(fichero.fail())
            {
                cout <<"Error" << endl;
            }else
            {
                cout << n << endl;
                for(int i=0; i<n; i++)
                {
                    fichero.seekg((i*sizeof(autobus)), ios::beg);
                    fichero.read((char *) &b, sizeof(autobus));
                    elementos[i]=b;
                    cout << "Se ha cargado correctamente." << endl;
                }
                cargado=true;
            }*/
            fichero.open("Autobus.dat", ios::in | ios::binary);
            fichero.read((char *) &b, sizeof(autobus));
            while(!fichero.eof())
            {
                cout << "============================" << endl;
                cout << "Matricula: " << b.matricula << endl;
                cout << "Activo: " << b.e.activo << endl;
                cout << "Deposito: " << b.e.deposito << endl;
                cout << "Ocupacion: " << b.e.plazas << endl;
                cout << "ITV: " << b.e.itv << endl;
                cout << "Conductor: " << b.conductor << endl;
                cout << "============================" << endl;

                elementos[i] = b;

                fichero.read((char *) &b, sizeof(autobus));
                i++;
                cargado=true;
                n++;
                cout << "Se ha cargado correctamemnte." << endl;
            }
        }
    fichero.close();
    return cargado;
}

bool autobuses::Guardar()
{
    autobus aux;
    int pos, ele;

    fichero.seekp(0, ios::beg);
    fichero.write((char *) &n, sizeof(int));

    for(pos=0; pos<n; pos++)
        for(ele=n; ele>pos; ele--)
        {
            if(strcmp(elementos[ele-1].matricula, elementos[ele].matricula)==0)
            {
                aux=elementos[ele-1];
                elementos[ele-1]=elementos[ele];
                elementos[ele]=aux;
            }
            for(int i=0; i<n; i++)
            {
                fichero.write((char *) &(elementos[i]), sizeof(autobus));
            }
        }
    cargado=false;
    return cargado;
}

