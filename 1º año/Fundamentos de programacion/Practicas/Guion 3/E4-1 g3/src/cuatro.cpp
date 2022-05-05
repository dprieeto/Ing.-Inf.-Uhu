#include "cuatro.h"

void cuatro::cargar()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<i+1<<"."<<j+1<<"-Introduce una palabra: ";cin>>tabla[i][j];
        }
    }
    cout<<"--------------------------------------------"<<endl;system("pause");system("cls");
}
void cuatro::encontrar()
{
    bool encontrado;int j,i;cadena palabra;
    encontrado=false;i=j=0;
    cout<<"Introduce la palabra a buscar: ";cin>>palabra;
    while(!encontrado && i<M)
    {
        while(!encontrado && j<N)
        {
            if(strcmp(tabla[i][j],palabra)==0)
            {
                encontrado=true;
            }
            j++;
        }
        i++;
    }
    system("cls");
    cout<<"La palabra buscada '"<<palabra<<"' "<<(encontrado ?"si":"no")<<" esta en la lista."<<endl;system("pause");
}
