#include <iostream>

using namespace std;

int main()
{
    double a;
    cout<<"Escribe el valor de tu nota: ";cin>>a;
    if (a<0,a>10)
        cout<<"Error en la nota";
    else if (a>=0,a<5)
        cout<<"Suspenso.";
    else if (a>=5,a<7)
        cout<<"Aprobado.";
        else if (a>=7,a<9)
            cout<<"Notable.";
        else if (a>=9)
            cout<<"Sobresaliente.";


}
