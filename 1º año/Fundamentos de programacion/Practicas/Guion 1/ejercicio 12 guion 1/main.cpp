#include <iostream>

using namespace std;

int main()
{
    float c, f;
    cout << "Introduce un valor de temperatura en grados centigrados: ";
    cin >> c;
    f = 1.8*c + 32;
    cout << "El valor e¡de esa temperatura en grados farenheit es de: " << f << endl;
    return 0;
}
