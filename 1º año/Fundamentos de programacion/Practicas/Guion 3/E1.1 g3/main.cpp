#include <iostream>
#define M 10
#include <stdlib.h>

using namespace std;
class uno
{
    int tabla[M];
public:
    void cargar();
    int maximo();
    int minimo();
};
void uno::cargar()
{
    for(int i=0;i<M;i++)
    {
        cout<<i+1<<".-Introduce un valor: ";cin>>tabla[i];
    }
    system("pause");system("cls");
}
int uno::maximo()
{
    int max;
    max=tabla[0];
    for(int i=0;i<M;i++)
    {
        if(tabla[i]>max)
            {
                max=tabla[i];
            }

    }
    return max;
}
int uno::minimo()
{
    int min;
    for(int i=0;i<M;i++)
    {
        if(tabla[i]<min)
            min=tabla[i];
    }
    return min;
}
int main()
{
    uno u;
    u.cargar();
    cout<<"El numero maximo es: "<<u.maximo()<<endl;
    cout<<"El numero minimo es: "<<u.minimo()<<endl;
    system("pause");
    return 0;
}
