#include "vector.h"

void vector::cargar()
{
    system("color 0a");
    for(int i=0;i<10;i++)
    {
        cout<<i+1<<"-Introduce un valor para la primera tabla: ";cin>>tab1[i];
    }
    cout<<"---------------------------------------------------------"<<endl;system("pause");system("cls");
    for(int j=0;j<10;j++)
    {
        cout<<j+1<<"-Introduce un valor para la segunda tabla: ";cin>>tab2[j];
    }
    cout<<"---------------------------------------------------------"<<endl;system("pause");system("cls");
}
int vector::comparar()
{
    bool encontrado;int numero,j,i;
    encontrado=false;i=j=0;
    while(!encontrado && i<10 &&j<10)
    {
        if(tab1[i]==tab2[j])
        {
            //for¿?
            encontrado=true;
        }
        else
        {
            numero=1;
        }
        i++;j++;
    }
    return numero;
}
