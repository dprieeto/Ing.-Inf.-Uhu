#include "tres.h"

void tres::cargar()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            tabla[i][j]=i*j;
        }
    }
}
int tres::encontrar()
{
    int numero,i,j,encontrado;i=j=encontrado=0;
    cout<<"Introduce el numero a buscar en la tabla: ";cin>>numero;
    while(!encontrado &&i<M)
    {
        while(!encontrado &&j<N)
        {
            if(numero==tabla[i][j])
            {
                encontrado=1;
            }
            j++;
        }
        i++;
    }
    return encontrado;
}
