#include <iostream>
#include <stdlib.h>
using namespace std;
class vector
{
    int tab1[10],tab2[10];
public:
    void cargar();
    int comparar();//devuelve 1 si son diferentes y 0 si son iguales
};
void vector::cargar()
{
    for(int i=0;i<10;i++)
    {
        cout<<i+1<<".-Introduce un valor para la primera tabla: ";cin>>tab1[i];
    }
    system("pause");system("cls");
    for(int i=0;i<10;i++)
    {
        cout<<i+1<<".-Introduce un valor para la segunda tabla: ";cin>>tab2[i];
    }
    system("pause");system("cls");
}
int vector::comparar()
{
    bool encontrado=false;
    int valor,i=0;
    while(!encontrado&&i<10)
    {
        if(tab1[i]!=tab2[i])
            encontrado=true;
        else
            i++;
    }
    if(encontrado==true)
        valor=1;
    else
        valor=0;
    return valor;
}
int main()
{
    vector v;
    v.cargar();
    cout<<"Las tablas "<<(v.comparar()?"no":"si")<<" son iguales."<<endl;
    system("pause");
    return 0;
}
