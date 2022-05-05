#include <iostream>
#include <cstdlib>
using namespace std;
class tablademultiplicar
{
    int tablaini,tablafin;
public:
    void pedirnotabla();
    void mostrartabla();
};
void tablademultiplicar::pedirnotabla()
{
    cout<<"Ahora vas a introducir dos numeros, para ver las tablas de multiplicar comprendidas desde un numero inicial hasta el numero final elegido.";
    cout<<"\nIntroduce un numero incial entre el 1 y el 10: ";cin>>tablaini;
    cout<<"\nIntroduce un numero final entre el 1 y el 10: ";cin>>tablafin;
    if (tablaini>tablafin)
        {
            int tablac;
            tablac=tablaini;
            tablaini=tablafin;
            tablafin=tablac;
        }
}
void tablademultiplicar::mostrartabla()
{
    int i,a,r,i1;
    a=10;
    for (i1=tablaini;i1<=tablafin;i1++)
    {
        if  ((tablaini && tablafin)>=1 || (tablaini && tablafin)<=10)
        {
            system("color 0a");
            cout<<i1;
        }
        do
        {
            if (tablaini<1 || tablaini>10)
            {
                system("color 04");
                cout<<"\nEl numero elegido no es valido.Introduce un numero entero entre el 1 y el 10:\n ";cin>>tablaini;
            }
        }while (tablaini<1 || tablaini>10);

        do
        {
            if (tablafin<1||tablafin>10)
            {
                system("color 04");
                cout<<"\nEl numero inicial elegido no es valido.Introduce un numero inicial comprendido entre el 1 y el 10: ";cin>>tablafin;
            }

        }while(tablafin<1||tablafin>10);
    }




























    for (i=0;i<=a;i++)
    {
            if (tablaini>=1 || tablaini<=10)
            {
                system("color 0a");
                r=tablaini*i;
                cout<<"\n"<<tablaini<<"*"<<i<<"="<<r<<"\n\t";

            }
        do
        {
            if (tablaini<1 || tablaini>10)
            {
                system("color 04");
                cout<<"\nEl numero elegido no es valido.Introduce un numero entero entre el 1 y el 10:\n ";cin>>tablaini;
            }
        }while (tablaini<1 || tablaini>10);
    }
}
             if (tablafin<1||tablafin>10)
            {
                system("color 04");
                cout<<"\nEl numero final elegido no es valido.Introduce un numero final comprendido entre el 1 y el 10: ";cin>>tablafin;
            }
        }while(tablafin<1||tablafin>
int main()
{
    system("pause");
    system("cls");
    system("color 0a");
    tablademultiplicar ob;
    ob.pedirnotabla();
    ob.mostrartabla();
    system("pause");
    system("color 06");
    return 0;
}
