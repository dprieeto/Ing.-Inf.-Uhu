#include <iostream>
#include <stdlib.h>
#define M 10
#define N 15
using namespace std;
class tres
{
    int tabla[M][N];
public:
    void cargar();//pondra en la tabla el producto de sus indices
    int encontrar();//1 si el numero buscado estan en la tabla y 0 si no esta
};
void tres::cargar()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            tabla[i][j]=i+j;
        }
    }
}
int tres::encontrar()
{
    int valor,numero,i=0,j=0;
    bool encontrado=false;
    cout<<"Introduce un numeroa buscar en la tabla: ";cin>>numero;
    while(!encontrado&&i<M)
    {
        j=0; //se inicializa ahi porque cuando a i se sume uno j tendra que emepzar de nuevo
        while(!encontrado&&j<N)
        {
            if(tabla[i][j]==numero)
                encontrado=true;
            else
                j++;
        }
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
    tres t;
    t.cargar();
    //cout<<"El numero "<<(t.encontrar()?"si":"no")<<" en la tabla."<<endl;
    if(t.encontrar()==1)
        cout<<"El numero buscado si se encuentra en la tabla."<<endl;
    else
        cout<<"El numero buscado no se encuentra en la tabla."<<endl;
    system("pause");
    return 0;
}
