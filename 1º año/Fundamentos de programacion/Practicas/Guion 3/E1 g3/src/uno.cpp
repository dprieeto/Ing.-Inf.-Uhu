#include "uno.h"

void uno::cargar()
{
    for(int i=0;i<M;i++)
    {
        cout<<i+1<<".-Introduce un numero: ";cin>>tabla[i];
    }
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
    min=tabla[0];
    for(int i=0;i<M;i++)
    {
        if(tabla[i]<min)
        {
            min=tabla[i];
        }
    }
    return min;
}
