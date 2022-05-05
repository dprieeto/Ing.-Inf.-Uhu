#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int x1,x2,y1,y2;
    cout << "Introduzca la coordenada del eje x del Punto P1: ";
    cin >> x1;
    cout << "Introduzca la coordenada del eje y del Punto P1: ";
    cin >> y1;
    cout << "Introduzca la coordenada del eje x del Punto P2: ";
    cin >> x2;
    cout << "Introduzca la coordenada del eje y del Punto P2: ";
    cin >> y2;
    float esp;
    esp = sqrt(pow((x2-x1),2) + pow ((y2-y1),2));
    cout << "La distancia del Punt P1 al Punto P2 es: " << esp << " u." << endl;
    return 0;
}
