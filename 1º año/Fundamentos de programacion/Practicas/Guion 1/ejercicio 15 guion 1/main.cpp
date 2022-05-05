#include <iostream>

using namespace std;

int main()
{
    float a, b, c, d, e, f, x, y;
    cout << "Dado un sistema de ecuaciones lineal: \n" << "ax+by=c \n" << "dx+ey=f" << endl;
    cout << "Introduzca un valor para a: ";
    cin >> a;
    cout << "Introduzca un valor para b: ";
    cin >> b;
    cout << "Introduzca un valor para c: ";
    cin >> c;
    cout << "Introduzca un valor para d: ";
    cin >> d;
    cout << "Introduzca un valor para e: ";
    cin >> e;
    cout << "Introduzca un valor para f: ";
    cin >> f;
    x = (c*e-b*f)/(a*e-b*d);
    y = (a*f-c*d)/(a*e-b*d);
    cout << "El valor de x es: " << x << endl;
    cout << "El valor de y es: " << y << endl;
    return 0;
}
