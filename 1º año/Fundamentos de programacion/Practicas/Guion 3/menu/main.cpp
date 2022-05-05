#include <iostream>
#include "numeros.h"

using namespace std;

int menu()
{
    int opcion;system("cls");
    cout<<"MENU"<<endl;
    cout<<"0.Dar valores"<<endl;
    cout<<"1.Sumar"<<endl;
    cout<<"2.Restar"<<endl;
    cout<<"3.Multiplicar"<<endl;
    cout<<"4.Dividir"<<endl;
    cout<<"5.Salir"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Elige una opcion: ";cin>>opcion;
    return opcion;
}
int main()
{
    numeros n;
    char opc;
    do
    {
        opc=menu();system("cls");
        switch(opc)
        {
        case 0:
            {
               n.pedirdatos();
               break;
            }
        case 1:
            {
                n.sumar();
                break;
            }
        case 2:
            {
                n.restar();break;
            }
        case 3:
            {
                n.multiplicar();break;
            }
        case 4:
            {
                n.dividir();break;
            }
        case 5:
            {
                break;
            }
        default:
            {
                system("cls");
                cout<<"Opcion incorrecta, pulse cualquier tecla para volver al menu";getch();
            }

        }
    }while(opc!=5);
    return 0;
}
