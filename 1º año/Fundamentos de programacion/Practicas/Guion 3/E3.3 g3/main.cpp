#include <iostream>
#include <stdlib.h>
#define M 10
#define N 15
using namespace std;
class tres
{
    int tabla[M][N];
public:
    void cargar();
    int encontrar();
};
void tres::cargar()
{
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            tabla[i][j]=i*j;
}
int tres::encontrar()
{
    bool encontrado=false;
    int valor,numero,i=0,j;
    cout<<"Introduce el numero que quieres buscar en la tabla: ";cin>>numero;
    while(i<M&&!encontrado)
    {
        j=0;
        while(j<N&&!encontrado)
        {
            if(tabla[i][j]==numero)
            {
                encontrado=true;
            }
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
    cout<<"El numero buscado "<<(t.encontrar()?"si":"no")<<" se encuentra en la tabla."<<endl;
    system("pause");
    return 0;
}
