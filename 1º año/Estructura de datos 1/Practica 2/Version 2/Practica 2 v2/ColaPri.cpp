#include "ColaPri.h"

///FUNCIONA

ColaPri::ColaPri()
{
    //ctor
}

ColaPri::~ColaPri()
{
    //dtor
}

void ColaPri::insertarColaPri(int i,Paciente e)
{
    tabla[i].encolar(e);
}
void ColaPri::sacarColaPri()
{

    int i=MAXcolas-1;
    while(tabla[i].esvacia()&&i>0)
    {
        i--;
    }
    tabla[i].desencolar();
}

Paciente ColaPri::consultarColaPri()
{

    int i=MAXcolas-1;
    while(tabla[i].esvacia()&&i>0)
    {
        i--;
    }
    return tabla[i].primero();
}

bool ColaPri::esvaciaColaPri()
{

    bool vacia=false;
    int i=MAXcolas-1;
    while(tabla[i].esvacia()&&i>0)
    {
        i--;
    }
    if(tabla[i].esvacia())
        vacia=true;

    return vacia;
}

int ColaPri::longitudColaPri()
{

    int lon=0;
    for(int i=0;i<MAXcolas;i++)
    {
        lon=lon+tabla[i].longitud();
    }
    return lon;
}

bool ColaPri::guardarfichero(cadena fich)
{
    bool guardado=false;
    Paciente p;
    fstream fichero;
    int npacientes;
    npacientes=longitudColaPri();
    fichero.open(fich, ios::out | ios::binary);
    if(fichero.fail())
    {
        cout << "No se ha podido abrir el fichero." << endl;
    }else
    {
        //fichero.write((char*)&npacientes,sizeof(int));
        //fichero.seekp(sizeof(int),ios::beg);
        fichero.seekp(0,ios::beg);
        fichero.write((char*)&npacientes,sizeof(int));
        for(int i=0;i<npacientes;i++)
        {

            p=consultarColaPri();
            fichero.seekp(sizeof(int)+i*sizeof(Paciente),ios::beg);
            fichero.write((char*)&p,sizeof(Paciente));
            sacarColaPri();
        }

        /*for(int i=0; i<MAXcolas; i++)
            npacientes=npacientes+tabla[i].longitud();

        fichero.seekp(0, ios::beg);
        fichero.write ((char *)&npacientes, sizeof(int));

        for(int i=0; i<npacientes; i++)
        {
            fichero.seekp (sizeof(int)+i*sizeof(Paciente), ios::beg);
            fichero.write ((char *) &tabla[i], sizeof(Paciente));
        }*/
        guardado=true;
        cout << "Se ha cargado correctamente." << endl;
    }
    fichero.close();
    return guardado;
}

bool ColaPri::cargarfichero(cadena fich)
{

    int npacientes=0,prioridad;///
    bool cargado=false;///
    Paciente p;///

    fstream fichero;///
    fichero.open(fich,ios::in|ios::binary);///
    if(fichero.fail())///
    {
        cout<<"\nError al cargar los datos del fichero."<<endl;///
    }
    else
    {
        fichero.seekg(0,ios::beg);///
        fichero.read((char*)&npacientes,sizeof(int));///
        for(int i=0;i<npacientes;i++)///
        {
            fichero.seekg(sizeof(int)+i*sizeof(Paciente),ios::beg);///
            fichero.read((char*)&p,sizeof(Paciente));
            cout<<"------------------------------"<<endl;
            cout<<"\nIdentificador: "<<p.id<<endl;
            cout<<"\nNombre: "<<p.nombre<<endl;
            cout<<"\nApellidos: "<<p.apellidos<<endl;
            cout<<"\nEdad: "<<p.edad<<endl;
            cout<<"\n------------------------------"<<endl;
            if(p.edad>=0&&p.edad<=9)
            {
                prioridad=0;
            }
            else if(p.edad>=10&&p.edad<=19)
            {
                prioridad=1;
            }
            else if(p.edad>=20&&p.edad<=29)
            {
                prioridad=2;
            }
            else if(p.edad>=30&&p.edad<=39)
            {
                prioridad=3;
            }
            else if(p.edad>=40&&p.edad<=49)
            {
                prioridad=4;
            }
            else if(p.edad>=50&&p.edad<=59)
            {
                prioridad=5;
            }
            else if(p.edad>=60&&p.edad<=69)
            {
                prioridad=6;
            }
            else if(p.edad>=70&&p.edad<=79)
            {
                prioridad=7;
            }
            else if(p.edad>=80)
            {
                prioridad=8;
            }
            insertarColaPri(prioridad,p);
        }
        cargado=true;
        cout<<"\nLos datos del fichero fueron cargados correctamente."<<endl;
    }
    fichero.close();
    return cargado;
}

void ColaPri::menor(cadena apellido)
{
    int i=MAXcolas-1;
    while(!tabla[i].esvacia()&&i>0)
    {
        tabla[i].menores_al_apellido(apellido);
    }
}

void ColaPri::mayor(cadena apellido)
{
    int i=MAXcolas-1;
    while(!tabla[i].esvacia()&&i>0)
    {
        tabla[i].mayores_al_apellido(apellido);
    }
}

