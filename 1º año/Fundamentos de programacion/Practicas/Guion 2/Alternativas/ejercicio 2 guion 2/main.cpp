#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout<<"Introduce un numero entero: ";cin>>a;
    cout<<"Introduce otro numero entero: ";cin>>b;
    if (a>b)
        cout<<"El primer numero es mayor.";
    else if (a<b)
        cout<<"El segundo numero es mayor";
    else if (a=b)
        cout<<"Los dos numeros son iguales";
}
