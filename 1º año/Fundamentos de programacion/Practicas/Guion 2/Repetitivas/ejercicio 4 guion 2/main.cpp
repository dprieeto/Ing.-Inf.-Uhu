#include <iostream>
#include <cstdlib>
using namespace std;
class tablademultiplicar
{
    int tabla;
public:
    void pedirnotabla();
    void mostrartabla();
};
void tablademultiplicar::pedirnotabla()
{
    cout<<"Introduce un numero entero entre el 1 y el 10 para ver su tabla de multiplicar: ";cin>>tabla;
}
void tablademultiplicar::mostrartabla()
{
    int i,r,a;
    a=10;
    for (i=0;i<=a;i++)
    {
            if (tabla>=1 || tabla<=10)
            {
                system("color 0a");
                r=tabla*i;
                cout<<"\n"<<tabla<<"*"<<i<<"="<<r<<"\n";

            }
        do
        {
            if (tabla<1 || tabla>10)
            {
                system("color 04");
                cout<<"\nEl numero elegido no es valido.Introduce un numero entero entre el 1 y el 10:\n ";cin>>tabla;
            }
        }while (tabla<1 || tabla>10);
    }
}
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
