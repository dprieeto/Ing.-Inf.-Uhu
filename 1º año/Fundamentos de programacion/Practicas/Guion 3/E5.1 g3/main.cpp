#include <iostream>
#include <stdlib.h>
#include <string.h>
#define M 2
#define N 4
typedef char cadena[30];
using namespace std;
struct persona
{
    int dni;
    cadena nombre;
};
class matrices
{
    persona tabla[M][N];
public:
    void cargar();
    void encontrar();
};
void matrices::cargar()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<i+1<<"."<<j<<".-Introduce el nombre: ";cin>>tabla[i][j].nombre;
            cout<<i+1<<"."<<j<<".-Introduce el D.N.I sin letra: ";cin>>tabla[i][j].dni;
        }
    }
    system("pause");system("cls");
}
void matrices::encontrar()
{
    int numero,i=0,j=0;
    bool encontrado=false;
    cadena palabra;
    cout<<"Introduce el numero del D.N.I a buscar: ";cin>>numero;
    while(!encontrado&&i<M)
    {
        j=0;
        while(!encontrado&&j<N)
        {
            if(tabla[i][j].dni==numero)
            {
                strcpy(palabra,tabla[i][j].nombre);
                encontrado=true;
            }
            else
                j++;
        }
        i++;
    }
    if(encontrado==true)
    {
        cout<<"El D.N.I introducido: '"<<numero<<"'"<<endl;
        cout<<"Nombre: '"<<palabra<<"'"<<endl;
    }
    else
        cout<<"El D.N.I introducido '"<<numero<<"' no se encuentra en la lista."<<endl;
}
int main()
{
    matrices m;
    m.cargar();
    m.encontrar();
    system("pause");
    return 0;
}
