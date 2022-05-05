#include <iostream>
#include <stdlib.h>
#define M 10
using namespace std;
class matrices
{
    int tabla[M];
public:
    void cargar();
    bool encontrar();
};
void matrices::cargar()
{
    for(int i=0;i<M;i++)
        tabla[i]=i;
}
bool matrices::encontrar()
{
    bool encontrado=false;
    int numero,i=0;
    cout<<"Introduce el numero que quieres buscar en la tabla: ";cin>>numero;
    while(i<M&&!encontrado)
    {
        if(numero==tabla[i])
        {
            encontrado=true;
        }
        else
            i++;
    }
    return encontrado?1:0;
}
int main()
{
    matrices m;
    m.cargar();
    cout<<"El numero "<<(m.encontrar()?"si":"no")<<" se encuentra en la tabla."<<endl;
    system("pause");
    return 0;
}
