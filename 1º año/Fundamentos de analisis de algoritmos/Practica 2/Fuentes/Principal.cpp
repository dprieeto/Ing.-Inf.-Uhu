#include <iostream>
#include <stdlib.h>

//#include <cstdlib>
#include "TestOrdenacion.h"
#include "Constantes.h"

using namespace std;

void menu(void);
void menu_casos(void);
void menu_comparar_2casos(void);

TestOrdenacion Algoritmo;

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
        cout<<"\n\t\t\t*** FAA. Practica 2. Curso 19/20 ***"<<endl<<endl;
        cout<<"\t\t\t\t\t\t     Alumno David Prieto Araujo\n\n\n";
        cout<<"\t\t\t*** ANALISIS EXPERIMENTAL DE ALGORITMOS DE ORDENACION ***\n\n\n";
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
                menu_casos();
                break;
            }
        case 3:
            {
                menu_comparar_2casos();
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

void menu_casos(void)
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

void menu_comparar_2casos(void)
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
/*
void menu_empirico(void)
{
    int opcion=1;

    do
    {
        system("cls");
        cout<<"\n\n\n\t\t*** MENU EMPIRICO DEL ALGORITMO DE BUSQUEDA SECUENCIAL ***\n\n";
        cout<<"\t\t1.- Probar el algoritmo de busqueda secuencial\n\n";
        cout<<"\t\t2.- Obtener los casos del metodo de busqueda secuencial\n\n";
        cout<<"\t\t3.- Comparar los casos\n\n";
        cout<<"\t\t0.- Volver al menu principal\n\n";
        cout<<"\t\t---------------------------------------------------------\n\n";
        cout<<"\t\tElige una opcion: ";
        cin>>opcion;
        system("cls");//esto lo mete en el comprobarAlgoritmo
        switch(opcion)
        {
        case 0:
            break;
        case 1:
            {
                Algoritmo.comprobarAlgoritmo();
                break;
            }
        case 2:
            {
                menu_empirico_casos();
                break;
            }
        case 3:
            {
                Algoritmo.compararEmpirico(SECUENCIALPEOR,SECUENCIALMEDIO,SECUENCIALMEJOR);
                //tb vale asi:
                //Algoritmo.compararEmpirico(0,1,2);
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

*/
