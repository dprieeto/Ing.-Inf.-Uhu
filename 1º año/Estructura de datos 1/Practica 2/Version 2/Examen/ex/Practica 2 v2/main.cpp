#include <iostream>
#include <stdlib.h>
#include "ColaPri.h"
#include "TadListaD.h"
#include "tadcola.h"
#include "ListaC.h"
#include <string>
#include <string.h>
#include <fstream>
#include <time.h>

using namespace std;

char menuprincipal();
char menu_pacientes_atendidos();
char menu_division_por_apellidos();
int prioridad(int edad);

int main()
{
    Paciente p;
    int pri=0,N;
    cadena nombre,n1,apellido;
    char n2[]=".dat";
    //strcpy(n2,".dat");
    ColaPri cp,aux1,aux2;
    Lista ld;
    ListaC lc;
    //fstream fichero;
    char menu,menu2;
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
                    cout<<endl;
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
                    do
                    {
                        cin>>p.edad;
                    }while(p.edad<0);
                    pri=prioridad(p.edad);///prioridad el paciente
                    cp.insertarColaPri(pri,p);
                    system("pause");
                    break;
                }
            case '3':
                {
                    if(cp.esvaciaColaPri())
                    {
                        cout<<"\nActualmente no hay pacientes para atender."<<endl<<endl;
                    }
                    else
                    {
                        p=cp.consultarColaPri();
                        srand((unsigned) time(NULL));
                        N=(rand()%2)+1;
                        if(N==1)
                        {
                            lc.anadirDch(p);
                        }
                        else
                        {
                            ld.anadirDch(p);
                        }
                        cp.sacarColaPri();
                        cout<<"\nPaciente atendido."<<endl<<endl;
                    }
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
                    do
                    {
                        menu2=menu_pacientes_atendidos();
                        system("cls");
                        switch(menu2)
                        {
                        case '1':
                            {
                                if(ld.esvacia())
                                {
                                    cout<<"\nActualmente no hay pacientes masculinos atendidos."<<endl;
                                }
                                else
                                {
                                    cout<<"\nPacientes masculinos atendidos."<<endl;
                                    cout<<"\nNumero de pacientes atendidos: "<<ld.longitud()<<endl<<endl;
                                    ld.mostrar_desde_el_principio();
                                }
                                system("pause");
                                break;
                            }
                        case '2':
                            {
                                if(lc.esvacia())
                                {
                                    cout<<"\nActualmente no hay pacientes femeninos atendidos."<<endl;
                                }
                                else
                                {
                                    cout<<"\nPacientes femeninos."<<endl;
                                    cout<<"\nNumero de pacientes atendidos: "<<lc.longitud()<<endl<<endl;
                                    lc.mostrar_desde_el_principio();
                                }
                                system("pause");
                                break;
                            }
                        case '3':
                            {
                                if(lc.esvacia()&&ld.esvacia())
                                {
                                    cout<<"\nActualmente no hay ningun paciente atendido."<<endl;
                                }
                                else if(lc.esvacia()&&!ld.esvacia())
                                {
                                    cout<<"\nActualmente solo hay pacientes masculinos atendidos."<<endl;
                                    cout<<"\nNumero de pacientes atendidos: "<<ld.longitud()<<endl;
                                    ld.mostrar_desde_el_principio();
                                }
                                else if(!lc.esvacia()&&ld.esvacia())
                                {
                                    cout<<"\nActualmente solo hay pacientes femeninas atendidas."<<endl;
                                    cout<<"\nNumero de pacientes atendidos: "<<lc.longitud()<<endl;
                                    lc.mostrar_desde_el_principio();
                                }
                                else if(!lc.esvacia()&&!ld.esvacia())
                                {
                                    cout<<"\nNumero de pacientes atendidos: "<<lc.longitud()+ld.longitud()<<endl;
                                    cout<<"\nPacientes Masculinos: "<<endl;
                                    ld.mostrar_desde_el_principio();
                                    cout<<"\n\nPacientes femeninas atendidas: "<<endl;
                                    lc.mostrar_desde_el_principio();
                                }
                                system("pause");
                                break;
                            }
                        case '0':
                            {
                                break;
                            }
                        case '4':
                            {
                                /*
                                int id,pos;
                                cout<<"Introduce un id: ";cin>>id;
                                pos=ld.posicion(id);
                                cout<<endl<<pos<<endl;
                                //p=lc.observar(pos);

                                cout<<"nombre: ";cin>>p.nombre;
                                cout<<"apellidos: ";cin>>p.apellidos;
                                cout<<"edad: ";cin>>p.edad;
                                cout<<"id: ";cin>>p.id;
                                ld.modificar(pos,p);
                                cout<<endl<<endl;

                                Paciente p1;
                                p1=ld.observar(pos);
                                //lc.eliminar(pos);

                                cout<<"nombre: "<<p1.nombre<<endl;
                                cout<<"apellidos: "<<p1.apellidos<<endl;
                                cout<<"edad: "<<p1.edad<<endl;
                                cout<<"id: "<<p1.id<<endl;
                                */
                                ///examen

                                cadena nombre,apellido1;
                                cout<<"Introduce un nombre para buscar: ";
                                cin>>nombre;
                                cout<<"\nIntroduce los apellidos: ";
                                cin>>apellido1;
                                ld.eliminarpornombre(nombre,apellido1);


                                system("pause");
                                break;
                            }
                        }
                    }while(menu2!='0');
                    break;
                }
            case '7':
                {
                    char menu3;
                    do
                    {
                        menu3=menu_division_por_apellidos();
                        system("cls");
                        switch(menu3)
                        {
                        case '0':
                            {
                                break;
                            }
                        case '1':
                            {
                                cout<<"\nIntroduce un apellido: ";
                                cin>>apellido;
                                cp.menor(apellido);
                                system("pause");
                                break;
                            }
                        case '2':
                            {
                                cout<<"\nIntroduce un apellido: ";
                                cin>>apellido;
                                cp.mayor(apellido);
                                system("pause");
                                break;
                            }

                        }
                    }while(menu3!='3');
                    break;
                }
            case '0':
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
    }while(menu!='0');
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
    cout<<"6.- Listar pacientes atendidos"<<endl;
    cout<<"7.- Division por apellidos"<<endl;
    cout<<"0.- Salir"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"Introduce una opcion: ";
    cin>>opcion;
    system("cls");
    return opcion;
}

char menu_division_por_apellidos()
{
    char opcion;
    system("cls");
    cout<<"\nDivision por apellidos."<<endl<<endl;
    cout<<"1.-Menores al apellido introducido"<<endl;
    cout<<"2.-Mayores al apellido introducido"<<endl;
    cout<<"0.-Volver"<<endl;
    cout<<"\nElige3 una opcion: ";
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

char menu_pacientes_atendidos()
{
    char opcion;
    system("cls");
    cout<<"\nPacientes a mostrar: "<<endl<<endl;
    cout<<"1.- Hombres"<<endl;
    cout<<"\n2.- Mujeres"<<endl;
    cout<<"\n3.- Todos"<<endl;
    cout<<"\n0.- Volver al menu principal"<<endl;
    cout<<"\nIntroduce una opcion: ";
    cin>>opcion;
    system("cls");
    return opcion;
}
