#include "autobuses.h"

autobuses::autobuses()
{
    tam=0;
    elementos=new autobus[tam];
    cargado=false;

    fichero.open("Autobuses.dat", ios::in | ios::out |ios::binary);
    if (fichero.fail())
    {
        fichero.close();
        fichero.clear();
        fichero.open("Autobuses.dat", ios::binary | ios::out);//creamos el fichero
        n=0;
        fichero.close();
        fichero.clear();
        fichero.open("Autobuses.dat", ios::binary | ios::out | ios::in);
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

void autobuses::Listar() //FUNCIONA POR FICHEROS
{
    autobus bus;

    if(cargado)
    {
        cout << "ESTAMOS EN TABLA DINAMICA." <<endl;
        for(int i=0; i<n; i++)
        {
            //cout << "============================" << endl;
            cout<<"---------------------------------------------------"<<endl;
            cout << "Matricula: " << elementos[i].matricula << endl;
            cout << "Conductor: " << elementos[i].conductor << endl;
            cout << "Deposito: " << elementos[i].e.deposito << endl;
            cout << "Plazas ocupadas: " << elementos[i].e.plazas << endl;
            cout << "En servicio: " << (elementos[i].e.activo?"SI":"NO") << endl;
            cout << "Itv pasada: " << (elementos[i].e.itv?"SI":"NO") << endl;
            cout<<"---------------------------------------------------"<<endl;
            //cout << "============================" << endl;
        }
    }else
    {
        fichero.open("Autobuses.dat", ios::in | ios::binary);
        if(!fichero.fail())
        {
            cout << "ESTAMOS EN FICHERO." << endl;
            cout << n << endl;
            fichero.read((char *) &bus, sizeof(autobus));
            while(!fichero.eof())
            {
                cout<<"---------------------------------------------------"<<endl;
                cout << "Matricula: " << bus.matricula << endl;
                cout << "Conductor: " << bus.conductor << endl;
                cout << "Deposito(litros): " << bus.e.deposito << endl;
                cout << "Plazas ocupadas: " << bus.e.plazas << endl;
                cout << "Activo: " << (bus.e.activo?"SI":"NO") << endl;
                cout << "ITV: " << (bus.e.itv?"SI":"NO") << endl;
                cout<<"---------------------------------------------------"<<endl;
                fichero.read((char *) &bus, sizeof(autobus));
                cout << n << endl;
            }
        }else
            cout << "No se ha podido abrir correctamente." << endl;

    fichero.close();
    }
}

void autobuses::Insertar(autobus a)
{
    if(Buscar(a.matricula)!=-1)
    {
        cout<<"\nMatricula repetida, no se pudo insertar el autobus."<<endl;
    }
    else
    {
        if(!cargado)
        {
            cout<<"\nUsando el fichero fisico."<<endl;
            fichero.open("Autobuses.dat",ios::binary|ios::out|ios::app);
            if(fichero.fail())
            {
                cout<<"\nError al abrir el fichero."<<endl;
            }
            else
            {
                fichero.write((char *)&a,sizeof(autobus));
                n++;
                cout<<"\nAutobus insertado."<<endl;
            }
            fichero.close();
        }
        else
        {
            cout<<"\nFichero importado a la memoria, trajando en memoria."<<endl;
            if(n==tam)
            {
                elementos=new autobus[tam+SALTO];
                elementos[n]=a;
                n++;
                tam=n+1;
            }
            else
            {
                elementos=new autobus[tam];
                elementos[n]=a;
                n++;
            }
        }
    }
}

int autobuses::Buscar(cadena mat)
{
    int pos=-1,i=0;
    autobus a;
    bool repetida=false;
    if(cargado)
    {
        while(i<n&&!repetida)
        {
            if(strcmp(a.matricula,mat)==0)
            {
                pos=i;
                repetida=true;
            }
            i++;
        }
    }
    else
    {
        fichero.open("Autobuses.dat",ios::binary|ios::in);
        if(fichero.fail())
        {
            cout<<"\nError al buscar la matricula en el fichero."<<endl;
        }
        else
        {
            fichero.read((char *)&a,sizeof(autobus));
            while(!fichero.eof())
            {
                if(strcmp(a.matricula,mat)==0)
                {
                    cout<<"\nMatricula repetida, estos son los datos asociados a la matricula:"<<endl;
                    cout<<"\nMatricula: "<<a.matricula<<endl;
                    cout<<"Conductor: "<<a.conductor<<endl;
                    cout<<"Deposito(litros): "<<a.e.deposito<<endl;
                    cout<<"Plazas ocupadas: "<<a.e.plazas<<endl;
                    cout<<"En servicio: "<<(a.e.activo?"SI":"NO")<<endl;
                    cout<<"Itv pasada: "<<(a.e.itv?"SI":"NO")<<endl;
                    pos=i;
                    repetida=true;
                }
                    fichero.read((char *)&a,sizeof(autobus));
                    i++;
            }
            fichero.close();
        }
    }
    return pos;
}

void autobuses::Modificar(autobus a, cadena mat, int pos) ///FUNCIONA POR FICHEROS
{
    if(pos==-1)
    {
        pos=Buscar(mat);
    }
        if(cargado==false)
        {
            fichero.open("Autobuses.dat", ios::out | ios::in | ios::binary);
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

void autobuses::Borrar(cadena mat, int pos) ///
{
    if(pos==-1)
    {
        pos=Buscar(mat);
    }
        if(cargado==false)
        {
            fichero.open("Autobuses.dat", ios::in | ios::out | ios::binary);
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
            fichero.open("Autobuses.dat", ios::in | ios::binary);
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







/*
autobuses::autobuses()
{
    elementos=new autobus[tam];
    n=0;
    cargado=false;
    fichero.open("Autobuses.dat",ios::binary|ios::in|ios::out);
    if(fichero.fail())
    {
        fichero.close();
        fichero.clear();
        fichero.open("Autobuses.dat",ios::binary|ios::out);
        fichero.close();
        fichero.clear();
        fichero.open("Autobuses.dat",ios::binary|ios::out|ios::in);
    }
    fichero.seekg(sizeof(autobus),ios::end);
    n=fichero.tellg()/sizeof(autobus);
    tam=SALTO;
    fichero.close();
}
*/


