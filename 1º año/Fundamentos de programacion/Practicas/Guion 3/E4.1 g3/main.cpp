#include <iostream>
#include <stdlib.h>
#include <string.h>
#define M 3
#define N 4
typedef char cadena[30];
using namespace std;
class cuatro
{
    cadena tabla[M][N];
public:
    void cargar();
    void encontrar();
};
void cuatro::cargar()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<i+1<<"."<<j<<".-Introduce una palabra: ";cin>>tabla[i][j];
        }
    }
    system("pause");system("cls");
}
void cuatro::encontrar()
{
    bool encontrado=false;
    int i=0,j=0;
    cadena palabra;
    cout<<"Introduce la palabra que quieres buscar en la tabla: ";cin>>palabra;
    while(!encontrado&&i<M)
    {
        j=0;
        while(!encontrado&&j<N)
        {
            if(strcmp(tabla[i][j],palabra)==0)
            {
                encontrado=true;
            }
            else
                j++;
        }
        i++;
    }
    if(encontrado==true)
    {
        cout<<"La palabra si se encuentra en la tabla y esta en la posicion: "<<i<<"."<<j<<endl;
    }
    else
        cout<<"La palabra buscada no se encuentra en la tabla."<<endl;
}
int main()
{
    cuatro c;
    c.cargar();
    c.encontrar();
    system("pause");
    return 0;
}
