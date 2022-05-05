#include "TestAlgoritmo.h"
#include <iostream>
#include <stdlib.h>

//#include <cstdlib>

//#include "TestAlgoritmo.h" //da fallo en el programa en la clase TestAlgoritmo L-18
#include "Constantes.h"

using namespace std;

void menu(void);
void menu_teorico(void);
void menu_teorico_casos(void);
void menu_empirico(void);
void menu_empirico_casos(void);

TestAlgoritmo Algoritmo;

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
        cout<<"\n\t*** FAA. Practica 1. Curso 19/20 ***"<<endl<<endl;
        cout<<"\t\t\t\t\t\t     Alumno David Prieto Araujo\n\n\n";
        cout<<"\t*** ESTUDIO DE LA COMPLEJIDAD DEL ALGORITMO BUSQUEDA SECUENCIAL ***\n\n\n";
        cout<<"\t\t\t1.- ESTUDIO TEORICO"<<endl;
        cout<<"\t\t\t2.- ESTUDIO EMPIRICO"<<endl;
        cout<<"\t\t\t0.- Salir"<<endl;
        cout<<"\t-------------------------------------------------------------------"<<endl;
        cout<<"\t\t\tElige una opcion: ";
        cin>>opcion;
        //system("cls");
        switch(opcion)
        {
        case 0:
            break;
        case 1:
            {
                menu_teorico();
                break;
            }
        case 2:
            {
                menu_empirico();
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

void menu_teorico(void)
{
    int opcion=1;

    do
    {
        system("cls");
        cout<<"\n\n\n\t\t*** MENU TEORICO DEL ALGORITMO DE BUSQUEDA SECUENCIAL ***\n\n";
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
                menu_teorico_casos();
                break;
            }
        case 3:
            {
                Algoritmo.compararTeorico(SECUENCIALPEOR,SECUENCIALMEDIO,SECUENCIALMEJOR);
                //tb vale asi:
                //Algoritmo.compararTeorico(0,1,2);
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

void menu_teorico_casos(void)
{
    int opcion=1;
    do
    {
        system("cls");
        cout<<"\n\n\n\t\t*** Caso a estudiar para la busqueda secuencial ***\n\n";
        cout<<"\t\t1.- Caso peor\n\n";
        cout<<"\t\t2.- Caso medio\n\n";
        cout<<"\t\t3.- Caso mejor\n\n";
        cout<<"\t\t0.- Volver al menu teorico\n\n";
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
                Algoritmo.costeCasoTeorico(0);
                //tb vale:
                //Algoritmo.costeCasoTeorico(SECUENCIALPEOR);
                break;
            }
        case 2:
            {
                Algoritmo.costeCasoTeorico(1);
                //tb vale:
                //Algoritmo.costeCasoTeorico(SECUENCIALMEDIO);
                break;
            }
        case 3:
            {
                Algoritmo.costeCasoTeorico(2);
                //tb vale:
                //Algoritmo.costeCasoTeorico(SECUENCIALMEJOR);
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

void menu_empirico_casos(void)
{
    int opcion=1;
    do
    {
        system("cls");
        cout<<"\n\n\n\t\t*** Caso a estudiar para la busqueda secuencial ***\n\n";
        cout<<"\t\t1.- Caso peor\n\n";
        cout<<"\t\t2.- Caso medio\n\n";
        cout<<"\t\t3.- Caso mejor\n\n";
        cout<<"\t\t0.- Volver al menu empirico\n\n";
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
                Algoritmo.costeCasoEmpirico(0);
                //tb vale:
                //Algoritmo.costeCasoEmpirico(SECUENCIALPEOR);
                break;
            }
        case 2:
            {
                Algoritmo.costeCasoEmpirico(1);
                //tb vale:
                //Algoritmo.costeCasoEmpirico(SECUENCIALMEDIO);
                break;
            }
        case 3:
            {
                Algoritmo.costeCasoEmpirico(2);
                //tb vale:
                //Algoritmo.costeCasoEmpirico(SECUENCIALMEJOR);
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
