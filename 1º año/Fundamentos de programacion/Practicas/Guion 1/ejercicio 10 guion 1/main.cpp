#include <iostream>

using namespace std;

int main()
{
    int const pi = 3.141592654;
    int r, longitud, area, volumen;
    cout << "Introduce el valor del radio en metros: ";
    cin >> r;
    volumen = 4*pi*r^3/3;
    area = pi*r^2;
    longitud = 2*r*pi;
    cout << "La longitud de la circunferencia es de: " << longitud << "m" << endl;
    cout << "La superficie del circulo es de: " << area << "m^2" << endl;
    cout << "El volumen de la esfera es de: " << volumen << "m^3" << endl;
    return 0;
}

