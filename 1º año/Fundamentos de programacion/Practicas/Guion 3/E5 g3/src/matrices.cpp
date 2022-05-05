#include "matrices.h"

void matrices::cargar()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            system("color 0a");
            cout<<i+1<<"."<<j+1<<"-Introduce el D.N.I. sin letra: ";cin>>tabla[i][j].dni;
            cout<<i+1<<"."<<j+1<<"-Introduce el nombre: ";cin>>tabla[i][j].nombre;
            system("cls");
        }
    }
}
void matrices::encontrar()
{
    int numero,i,j;bool encontrado;cadena palabra;
    encontrado=false;i=j=0;
    cout<<"Introduce el D.N.I. que quieres buscar: ";cin>>numero;
    while(!encontrado && i<M)
    {
        while(!encontrado && j<N)
        {
            if(numero==tabla[i][j].dni)
            {
                encontrado=true;
                strcpy(palabra,tabla[i][j].nombre);
            }
            j++;
        }
        i++;
    }
    cout<<"El D.N.I. buscado '"<<numero<<"' "<<(encontrado ?"si":"no")<<" se encuentra en la lista."<<endl;
    if(encontrado==true)
    {
        cout<<"Nombre: "<<palabra<<endl;
    }
    system("pause");
}
