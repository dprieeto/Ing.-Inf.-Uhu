#include <iostream>
#include <stdlib.h>

//#include <cstdlib>
#include "TestOrdenacion.h"
#include "TestBusqueda.h"
#include "Constantes.h"

using namespace std;

void menu(void);
void menu_ordenacion(void);
void busqueda_2casos(void);
void menu_busqueda(void);
void ordenacion_casos(void);
void busqueda_casomedio(void);
void ordenacion_comparar_2casos(void);

TestOrdenacion Algoritmo;
TestBusqueda buscar;

/* Programa principal */
int main()
{
/* ESCRIBIR PARA COMPLETAR LA PRÁCTICA*/
    menu();
    cout<<endl<<"Fin Programa."<<endl<<endl;
    system("pause");
    return 0;
}

void menu(void)
{
    int opcion=1;//¿=1?
    do
    {
        system("cls");
        cout<<"\n\t\t\t*** FAA. Practica 3. Curso 19/20 ***"<<endl<<endl;
        cout<<"\t\t\t\t\t\t     Alumno David Prieto Araujo\n\n\n";
        cout<<"\t\t\t*** MENU PRINCIPAL ***\n\n\n";
        cout<<"\t\t\t1.- Menu Ordenacion\n"<<endl;
        cout<<"\t\t\t2.- Menu Busqueda\n"<<endl;
        cout<<"\t\t\t0.- Salir"<<endl;
        cout<<"\t\t-------------------------------------------------------------------"<<endl;
        cout<<"\t\t\tElige una opcion: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 0:
            break;
        case 1:
            {
                menu_ordenacion();
                break;
            }
        case 2:
            {
                menu_busqueda();
                break;
            }
        default:
            {
                cout<<"\n\nLa opcion '"<<opcion<<"' no es valida."<<endl<<endl;
                system("pause");
            }
        }
    }while(opcion!=0);
}

void menu_busqueda(void)
{
    int opcion=1;//¿=1?
    TestBusqueda b;
    do
    {
        system("cls");
        //cout<<"\n\t\t\t*** FAA. Practica 2. Curso 19/20 ***"<<endl<<endl;
        //cout<<"\t\t\t\t\t\t     Alumno David Prieto Araujo\n\n\n";
        cout<<"\t\t\t*** Menu Busqueda ***\n\n\n";
        cout<<"\t\t\t1.- Probar los metodos de busqueda\n"<<endl;
        cout<<"\t\t\t2.- Obtener un caso medio de un metodo de busqueda\n"<<endl;
        cout<<"\t\t\t3.- Comparar los dos metodos\n"<<endl;
        cout<<"\t\t\t4.- Comparar todos los metodos\n"<<endl;
        cout<<"\t\t\t0.- Salir"<<endl;
        cout<<"\t\t-------------------------------------------------------------------"<<endl;
        cout<<"\t\t\tElige una opcion: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 0:
            break;
        case 1:
            {
                b.comprobarMetodosBusqueda();
                break;
            }
        case 2:
            {
                busqueda_casomedio();
                break;
            }
        case 3:
            {
                busqueda_2casos();
                break;
            }
        case 4:
            {
                buscar.comparartodos();
                break;
            }
        default:
            {
                cout<<"\n\nLa opcion '"<<opcion<<"' no es valida."<<endl<<endl;
                system("pause");
            }
        }
    }while(opcion!=0);
}

void busqueda_2casos(void)
{
        int opc1,opc2,m1,m2;
        system("cls");
        cout<<"\n\n\n\t\t*** Comparacion de dos metodos de Busqueda ***\n\n";
        cout<<"\t\t1.- Secuencial Iterativo\n\n";
        cout<<"\t\t2.- Binario Iterativo\n\n";
        cout<<"\t\t3.- Interpolacion Iterativa\n\n";
        cout<<"\t\t---------------------------------------------------------\n\n";
        cout<<"\t\tElige la primera opcion: ";
        do
        {
            cin>>opc1;
            switch(opc1)
            {
        case 1:
            m1=SECUENCIALIT;
            break;
        case 2:
            m1=BINARIAIT;
            break;
        case 3:
            m1=INTERPOLACIONIT;
            break;
            }
        }while(opc1!=1&&opc1!=2&&opc1!=3);
        cout<<"\t\tElige la segunda opcion: ";
        do
        {
            cin>>opc2;
            switch(opc2)
            {
        case 1:
            m2=SECUENCIALIT;
            break;
        case 2:
            m2=BINARIAIT;
            break;
        case 3:
            m2=INTERPOLACIONIT;
            break;
            }
        }while(opc2!=1&&opc2!=2&&opc2!=3);
        buscar.comparar(m1,m2);
}



void busqueda_casomedio(void)
{
        int opcion=1;
    do
    {
        system("cls");
        cout<<"\n\n\n\t\t*** Metodo a estudiar del caso medio ***\n\n";
        cout<<"\t\t1.- Secuencial Iterativo\n\n";
        cout<<"\t\t2.- Binario Iterativo\n\n";
        cout<<"\t\t3.- Interpolacion Iterativa\n\n";
        cout<<"\t\t0.- Volver al menu principal\n\n";
        cout<<"\t\t---------------------------------------------------------\n\n";
        cout<<"\t\tElige una opcion: ";
        cin>>opcion;
        //system("cls");
        switch(opcion)
        {
        case 0:
            break;
        case 1:
            {
                buscar.casoMedio(SECUENCIALIT);
                //tb vale:
                //Algoritmo.casoMedio(0);
                break;
            }
        case 2:
            {
                buscar.casoMedio(BINARIAIT);
                //tb vale:
                //Algoritmo.casoMedio(1);
                break;
            }
        case 3:
            {
                buscar.casoMedio(INTERPOLACIONIT);
                //tb vale:
                //Algoritmo.casoMedio(2);
                break;
            }
        default:
            {
                cout<<"\t\tLa opcion '"<<opcion<<"' no es valida."<<endl<<endl;
                system("pause");
            }
        }
    }while(opcion!=0);
}

void menu_ordenacion(void)
{
    int opcion=1;//¿=1?
    do
    {
        system("cls");
        //cout<<"\n\t\t\t*** FAA. Practica 2. Curso 19/20 ***"<<endl<<endl;
        //cout<<"\t\t\t\t\t\t     Alumno David Prieto Araujo\n\n\n";
        cout<<"\t\t\t*** Menu Ordenacion ***\n\n\n";
        cout<<"\t\t\t1.- Probar los metodos de ordenacion\n"<<endl;
        cout<<"\t\t\t2.- Obtener un caso medio del metodo de ordenacion\n"<<endl;
        cout<<"\t\t\t3.- Comparar los dos metodos\n"<<endl;
        cout<<"\t\t\t0.- Salir"<<endl;
        cout<<"\t\t-------------------------------------------------------------------"<<endl;
        cout<<"\t\t\tElige una opcion: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 0:
            break;
        case 1:
            {
                Algoritmo.comprobarMetodosOrdenacion();
                break;
            }
        case 2:
            {
                ordenacion_casos();
                break;
            }
        case 3:
            {
                ordenacion_comparar_2casos();
                break;
            }
        default:
            {
                cout<<"\n\nLa opcion '"<<opcion<<"' no es valida."<<endl<<endl;
                system("pause");
            }
        }
    }while(opcion!=0);
}

void ordenacion_casos(void)
{
    int opcion=1;
    do
    {
        system("cls");
        cout<<"\n\n\n\t\t*** Metodo a estudiar del caso medio ***\n\n";
        cout<<"\t\t1.- Burbuja\n\n";
        cout<<"\t\t2.- Insercion\n\n";
        cout<<"\t\t3.- Seleccion\n\n";
        cout<<"\t\t0.- Volver al menu principal\n\n";
        cout<<"\t\t---------------------------------------------------------\n\n";
        cout<<"\t\tElige una opcion: ";
        cin>>opcion;
        //system("cls");
        switch(opcion)
        {
        case 0:
            break;
        case 1:
            {
                Algoritmo.casoMedio(BURBUJA);
                //tb vale:
                //Algoritmo.casoMedio(0);
                break;
            }
        case 2:
            {
                Algoritmo.casoMedio(INSERCION);
                //tb vale:
                //Algoritmo.casoMedio(1);
                break;
            }
        case 3:
            {
                Algoritmo.casoMedio(SELECCION);
                //tb vale:
                //Algoritmo.casoMedio(2);
                break;
            }
        default:
            {
                cout<<"\t\tLa opcion '"<<opcion<<"' no es valida."<<endl<<endl;
                system("pause");
            }
        }
    }while(opcion!=0);
}

void ordenacion_comparar_2casos(void)
{
    int opc1,opc2,m1,m2;
        system("cls");
        cout<<"\n\n\n\t\t*** Comparacion de dos metodos de Ordenacion ***\n\n";
        cout<<"\t\t1.- Burbuja\n\n";
        cout<<"\t\t2.- Insercion\n\n";
        cout<<"\t\t3.- Seleccion\n\n";
        cout<<"\t\t---------------------------------------------------------\n\n";
        cout<<"\t\tElige la primera opcion: ";
        do
        {
            cin>>opc1;
            switch(opc1)
            {
        case 1:
            m1=BURBUJA;
            break;
        case 2:
            m1=INSERCION;
            break;
        case 3:
            m1=SELECCION;
            break;
            }
        }while(opc1!=1&&opc1!=2&&opc1!=3);
        cout<<"\t\tElige la segunda opcion: ";
        do
        {
            cin>>opc2;
            switch(opc2)
            {
        case 1:
            m2=BURBUJA;
            break;
        case 2:
            m2=INSERCION;
            break;
        case 3:
            m2=SELECCION;
            break;
            }
        }while(opc2!=1&&opc2!=2&&opc2!=3);
        Algoritmo.comparar(m1,m2);
}

