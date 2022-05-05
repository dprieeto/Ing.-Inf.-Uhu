#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int a, b, c, x1, x2, aux;
    cout << "Dada una ecuacion de segundo grado ax^2 + bx + c = 0.";
    cout << "\n Introduzca el valor de a: ";
    cin >> a;
    cout << "introduzca un valor para b: ";
    cin >> b;
    cout << "Introduzca un valor para c: ";
    cin >> c;
    aux = b*b - 4*a*c;
    x1 = (-b+(aux)^(1/2))/(2*a);
    x2 = (-b-(aux)^(1/2))/(2*a);
    if (aux<0)
        cout << "La ecuacion no tiene soluciones reales" << endl;
    else
    if (aux=0)
        cout << "La ecuacion tiene una solucion doble por lo que el valor de x es: " << x1 << endl;
    else
        cout << "Las soluciones son: " << "\n x1 = " << x1 << "\n x2 = " << x2 << endl;




    return 0;
}
