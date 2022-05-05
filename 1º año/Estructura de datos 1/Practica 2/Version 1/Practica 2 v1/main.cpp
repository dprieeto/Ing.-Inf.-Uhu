#include <iostream>
#include <stdlib.h>
#include "ColaPri.h"
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

char menuprincipal();
int prioridad(int edad);

int main()
{
    Paciente p;
    int pri=0;
    cadena nombre,n1;
    char n2[]=".dat";
    //strcpy(n2,".dat");
    ColaPri cp,aux1,aux2;
    //fstream fichero;
    char menu;
    do
    {
        menu=menuprincipal();
        system("cls");
        switch(menu)
        {
            case '1':
                {
                    cout<<"\nIntroduce el nombre del fichero para cargar los datos: ";
                    cin>>n1;
                    strcpy(nombre,n1);//copia en nombre n1
                    strcat(nombre,n2);//concatena(une) el nombre del archivo con la extension '.dat'
                    cp.cargarfichero(nombre);
                    system("pause");
                    break;
                }
            case '2':
                {
                    cout<<"\nIntroduce su identificador: ";
                    cin>>p.id;
                    cout<<"\nIntroduce el nombre del paciente: ";
                    cin>>p.nombre;
                    cout<<"\nIntroduce el primer apellido: ";
                    cin>>p.apellidos;
                    cout<<"\nIntroduce la edad: ";
                    cin>>p.edad;
                    pri=prioridad(p.edad);///prioridad el paciente
                    cp.insertarColaPri(pri,p);
                    system("pause");
                    break;
                }
            case '3':
                {
                    cp.sacarColaPri();
                    cout<<"\nPaciente atentido."<<endl<<endl;
                    system("pause");
                    break;
                }
            case '4':
                {
                    while(!cp.esvaciaColaPri())
                    {
                        p=cp.consultarColaPri();
                        aux1.insertarColaPri(prioridad(p.edad),p);
                        cp.sacarColaPri();
                    }
                    while(!aux1.esvaciaColaPri())
                    {
                        p=aux1.consultarColaPri();
                        cout<<"------------------------------"<<endl;
                        cout<<"\nNombre: "<<p.nombre<<endl;
                        cout<<"\nApellidos: "<<p.apellidos<<endl;
                        cout<<"\nEdad: "<<p.edad<<endl;
                        cout<<"\nIndetificador: "<<p.id<<endl;
                        cout<<"------------------------------"<<endl;
                        aux1.sacarColaPri();
                        cp.insertarColaPri(prioridad(p.edad),p);
                    }
                    system("pause");
                    break;
                }
            case '5':
                {
                    bool insertado=false;
                    do
                    {
                        system("cls");
                        cout<<"\nIntroduce una prioridad(1-9 siendo 9 la mas alta): ";
                        cin>>pri;
                    }while(pri<1||pri>9);
                    pri--;//restamos 1 para hacer coger la prioridad en el codigo xk va de 0-8
                    while(!cp.esvaciaColaPri())
                    {
                        p=cp.consultarColaPri();//devuelve el primer paciente
                        if(prioridad(p.edad)==pri)
                        {
                            aux1.insertarColaPri(prioridad(p.edad),p);
                            insertado=true;
                        }
                        aux2.insertarColaPri(prioridad(p.edad),p);
                        cp.sacarColaPri();
                    }
                    if(insertado)
                    {
                        while(!aux1.esvaciaColaPri())
                        {
                            p=aux1.consultarColaPri();
                            cout<<"------------------------------"<<endl;
                            cout<<"\nNombre: "<<p.nombre<<endl;
                            cout<<"\nApellidos: "<<p.apellidos<<endl;
                            cout<<"\nEdad: "<<p.edad<<endl;
                            cout<<"\nIndetificador: "<<p.id<<endl;
                            cout<<"------------------------------"<<endl;
                            aux1.sacarColaPri();
                        }
                    }
                    else
                    {
                        cout<<"\nActualmente no hay pacientes en esa prioridad."<<endl<<endl;
                    }
                    while(!aux2.esvaciaColaPri())
                    {
                        p=aux2.consultarColaPri();
                        cp.insertarColaPri(prioridad(p.edad),p);
                        aux2.sacarColaPri();
                    }
                    system("pause");
                    break;
                }
            case '6':
                {
                    cout<<"\nIntroduce el nombre del fichero para guardar los datos: ";
                    cin>>n1;
                    strcpy(nombre,n1);
                    strcat(nombre,n2);
                    cout<<"\nNombre del archivo: "<<nombre<<endl;
                    cp.guardarfichero(nombre);
                    system("pause");
                    break;
                }
        }
    }while(menu!='6');
    return 0;
}

char menuprincipal()
{
    char opcion;
    system("cls");
    cout<<"----- Menu Principal -----"<<endl;
    cout<<"\n1.- Cargar datos desde fichero"<<endl;
    cout<<"2.- Admision de un nuevo paciente"<<endl;
    cout<<"3.- Atender un nuevo paciente"<<endl;
    cout<<"4.- Listar Pacientes esperando para atender"<<endl;
    cout<<"5.- Listar Pacientes segun prioridad"<<endl;
    cout<<"6.- Salir"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"Introduce una opcion: ";
    cin>>opcion;
    system("cls");
    return opcion;
}

int prioridad(int edad) ///devuelve la prioridad que recibe el paciente para insertarlo en la cola
{
    int pri;
    if(edad<0)
    {
        pri=-1;
    }
    else
    {
        if(edad>=0&&edad<=9)
        {
            pri=1;
        }
        if(edad>=10&&edad<=19)
        {
            pri=2;
        }
        if(edad>=20&&edad<=29)
        {
            pri=3;
        }
        if(edad>=30&&edad<=39)
        {
            pri=4;
        }
        if(edad>=40&&edad<=49)
        {
            pri=5;
        }
        if(edad>=50&&edad<=59)
        {
            pri=6;
        }
        if(edad>=60&&edad<=69)
        {
            pri=7;
        }
        if(edad>=70&&edad<=79)
        {
            pri=8;
        }
        if(edad>=80)
        {
            pri=9;
        }
    }
    return pri-1;///pri-1 xk la colapri va de 0 a 8 y la prioridad de 1 a 9
}
