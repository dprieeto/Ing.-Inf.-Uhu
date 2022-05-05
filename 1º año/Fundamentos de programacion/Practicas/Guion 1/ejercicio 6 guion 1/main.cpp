#include <iostream>

using namespace std;

int main()
{
    int nf, nt, np;
    cout << "Introduzca la nota del examen teorico: ";
    cin >>nt;
    cout << "Introduzca la nota del examen practico: ";
    cin >>np;
    nf = nt *0.4 + np * 0.6;
    cout <<  "La nota final es: " << nf << endl;

    return 0;
}
