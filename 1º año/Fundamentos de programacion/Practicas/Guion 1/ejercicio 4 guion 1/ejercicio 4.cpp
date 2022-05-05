#include <iostream>

using namespace std;

int main()
{
    int x, y, aux; //Declaración de variables

    //Datos de entrada
    cout<<"Introduce los valores de las variables a intercambiar: ";
    cin>>x>>y;

    //Mostrar datos
    cout<<"x = "<<x<< " y = "<<y <<endl;

    //Intercambio de variables
    aux = x;
    x = y;
    y = aux;

    //Mostrar datos intercambiados
    cout<<"\nx = "<<x<< "y = "<<y;
    return 0;

}
