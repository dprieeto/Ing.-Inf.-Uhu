#include <iostream>
#include <string.h>
#include "Autobus.h"

using namespace std;

autobuses::autobuses()
{
    tam=0;
    elementos=NULL;
    cargado=false;

    fichero.open("Autobus.dat", ios::in | ios::out |ios::binary);
    if (fichero.fail())
    {
        fichero.close();
        fichero.clear();
        fichero.open("Autobus.dat", ios::binary | ios::out);///creamos el fichero
        n=0;
        fichero.seekp(0, ios::beg); ///
        fichero.write((char *) &n, sizeof(int));
        fichero.close();
        fichero.clear();
        fichero.open("Autobus.dat", ios::binary | ios::out | ios::in);
    }
        //fichero.seekg(0, ios::beg);
        fichero.read((char *) &n, sizeof(int));
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
            fichero.open("Autobus.dat", ios::out | ios::in | ios::binary);
            cout << "ESTAMOS EN FICHEROS." << endl;
            if(fichero.fail())
            {
                cout << "No se ha podido abrir el archivo." << endl;
            }else
            {
                fichero.seekp(sizeof(int)+sizeof(autobus)*n, ios::beg);
                fichero.write((char *) &a, sizeof(autobus));
                n++;
                fichero.seekp(0, ios::beg);
                fichero.write((char *)&n, sizeof(int));

                cout << "Autobus insertado correctamente." << endl;
            }
            fichero.close();
        }else
        {
            cout << "ESTAMOS EN TABLA DINAMICA." << endl;

            if(tam==n)
            {

            }
            elementos[n]=a;
            n++;

            cout << "Insertado correctamente." << endl;
        }
    }
}

void autobuses::Borrar(cadena mat, int pos) ///
{
    autobus a;
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
                //fichero.seekg(0, ios::beg);
                //fichero.read((char *) &n, sizeof(int));
                pos=pos-1;
                for(int i=pos; i<n-1; i++)
                {
                    fichero.seekg(sizeof(int)+sizeof(autobus)*(i+1), ios::beg);
                    fichero.read((char *)&a, sizeof(autobus));
                    fichero.seekp(sizeof(int)+sizeof(autobus)*i, ios::beg); //Posiciona antaes de escribir
                    fichero.write((char *)&a, sizeof(autobus));
                }
                n--;
                fichero.seekp(0, ios::beg);
                fichero.write((char *)&n,sizeof(int));
                fichero.close();
                    /*pos=pos-1;
                    fichero.seekg(sizeof(int)+sizeof(autobus)*(pos+1), ios::beg);
                    fichero.read((char *)&a, sizeof(autobus));
                    fichero.seekp(sizeof(int)+sizeof(autobus)*pos, ios::beg); //Posiciona antaes de escribir
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
                cout << n << endl;
                //fichero.seekg(sizeof(int)+((pos-1)*sizeof(autobus)), ios::beg);
                //fichero.read
                fichero.seekp(sizeof(int)+((pos-1)*sizeof(autobus)), ios::beg);
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
            fichero.seekp(sizeof(int), ios::beg);
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
            fichero.seekg(sizeof(int), ios::beg);
            fichero.read((char *) &bus, sizeof(autobus));
            for(int i=0; i<n; i++)
            {
                cout << "Matricula: " << bus.matricula << endl;
                cout << "Activo: " << bus.e.activo << endl;
                cout << "Deposito: " << bus.e.deposito << endl;
                cout << "Ocupacion: " << bus.e.plazas << endl;
                cout << "ITV: " << bus.e.itv << endl;
                cout << "Conductor: " << bus.conductor << endl;
                fichero.read((char *) &bus, sizeof(autobus));
            }

        }else
            cout << "No se ha podido abrir correctamente." << endl;

    fichero.close();
    }
}

bool autobuses::Cargar()
{
    int i=0;
    autobus b;
    elementos = new autobus[tam];

    fichero.open("Autobus.dat", ios::in | ios::binary);
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
            fichero.seekg(sizeof(int)+sizeof(autobus)*i, ios::beg);
            fichero.read((char *) &b, sizeof(autobus));
            elementos[i]=b;

            cout << "============================" << endl;
            cout << "Matricula: " << elementos[i].matricula << endl;
            cout << "Activo: " << elementos[i].e.activo << endl;
            cout << "Deposito: " << elementos[i].e.deposito << endl;
            cout << "Ocupacion: " << elementos[i].e.plazas << endl;
            cout << "ITV: " << elementos[i].e.itv << endl;
            cout << "Conductor: " << elementos[i].conductor << endl;
            cout << "============================" << endl;
        }

        cout << "Se ha cargado correctamente." << endl;
        cargado=true;

        elementos[tam];
    }
    fichero.close();
    return cargado;
}

bool autobuses::Guardar()
{
    bool guardado=false;
    autobus aux;
    int pos, ele;
    fichero.open("Autobus.dat", ios::out | ios::binary);

    if(fichero.fail())
    {
        cout << "No se ha podido abrir el fichero. Error al guardar." << endl;
    }else
    {
        fichero.seekp(0, ios::beg);
        fichero.write((char *) &n, sizeof(int));
        for(pos=1; pos<n; pos++)
            for(ele=n; ele>pos; ele--)
            {
                if(strcmp(elementos[ele-1].matricula, elementos[ele].matricula)==0)
                {
                    aux=elementos[ele-1];
                    elementos[ele-1]=elementos[ele];
                    elementos[ele]=aux;
                }
            }
                for(int i=0; i<n; i++)
                {
                    fichero.seekp(sizeof(int), ios::end);
                    fichero.write((char *) &(elementos[i]), sizeof(autobus));
                }

                cout << "Se ha guardado correctamente." << endl;

        delete [] elementos;
        elementos=NULL;
        tam=0;
        cargado=false;
        guardado=true;
    }
    fichero.close();
    return guardado;
}

