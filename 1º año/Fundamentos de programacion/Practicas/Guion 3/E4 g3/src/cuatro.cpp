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
}
void cuatro::encontrar()
{
    cadena palabra;bool encontrado=false;int i,j;i=j=0;
    cout<<"Introduce la palabra que quieres buscar en la tabla: ";cin>>palabra;
    while(!encontrado && i<M)
    {
        while(!encontrado && j<N)
        {
            if(strcmp(palabra,tabla[i][j])==0)
            {
                cout<<"La palabra se encuentra en la tabla en la posicion: "<<i<<"."<<j;
                system("pause");
            }
            j++;
        }
        i++;
    }
}
