#include "Empresa.h"
/*
Empresa::Empresa()
{
    //ctor
}
*/
Empresa::~Empresa()
{
    //dtor
    for(int i=0;i<n;i++)
        delete [] lista[i];
    delete [] lista;
}


void Empresa::duplicar()
{
    nmax=nmax*2;
    Empleado **aux;
    aux=new Empleado*[nmax];
    for(int i=0;i<n;i++)
    {
        aux[i]=lista[i];
    }
    delete [] lista;
    lista=aux;
    delete [] aux;
}

void Empresa::ver()
{
    cout<<"La empresa tiene "<<n<<" empleados: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<lista[i].codEmpleado()<<": "<<lista[i].getNombre()<<", nomina: ";
        if(typeid(lista[i])==typeid(EmpleadoH))
        {
            //dynamic_cast <EmpleadoH&> (lista[i]);
            //static_cast <EmpleadoH&> (Empleado &lista[i]);
            EmpleadoH h=lista[i];

            cout<<h.nominaH()<<", horas: "<<h.getHoras()<<endl;
        }
        else
        {
            EmpleadoV v=lista[i];
            cout<<v.nominaV()<<", ventas:  "<<v.getVentas()<<endl;
        }
    }
}

void Empresa::eliminarH()
{
    for(int i=0;i<n-1;i++)
    {
        if(typeid(lista[i])==typeid(EmpleadoH))
        {
            //delete [] lista[i];
            lista[i]=lista[i+1];
            n--;
        }
    }
}

void Empresa::contratar()
{
    int pos=-1;
    bool existe=false;
    char nombre,opcion;
    float sueldo;
    int horas,ventas;
    EmpleadoV v;
    EmpleadoH h;
    for(int i=0;i<2;i++){
    if(n==nmax)
        duplicar();
    else
    {
        for(int i=0;i<2;i++)
        {
            cout<<"\nNombre empleado a contratar: ";cin>>nombre;
            cout<<"\nSueldo: ";cin>>sueldo;
            cout<<"\nEl empleado trabaja por horas (s/n)?";cin>>opcion;
            if(opcion=='s')
                {
                    cout<<"\nHoras: ";cin>>horas;
                    h.EmpleadoH(nombre,sueldo,horas);
                    lista[n++]=h;
                }
            else
            {
                cout<<"\nVentas: ";cin>>ventas;
                v.EmpleadoV(nombre,sueldo,ventas);
                lista[n++]=v;
            }
        }

    }
    }
}
