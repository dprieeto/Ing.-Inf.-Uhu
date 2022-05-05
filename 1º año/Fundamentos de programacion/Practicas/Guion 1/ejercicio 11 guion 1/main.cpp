#include <iostream>

using namespace std;

int main()
{
    float euros, dolares, libras;
    cout << "Introduce una cantidad de dinero en euros: ";
    cin >> euros;
    libras = 1.12*euros;
    dolares = euros/1.14;
    cout << "El cambio de euros a dolares es: " << dolares << endl;
    cout << "El cambio de euros a libras esterlinas es: " << libras << endl;
    return 0;
}
