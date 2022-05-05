#include <iostream>

using namespace std;

int main()
{
    int s, minu, horas, minutos, segundos;
    cout <<" Introduce los segundos" << endl;
    cin>> s;

    minu= s / 60;
    segundos= minu / 60;
    horas= minu / 60;
    minutos = minu % 60;

    horas= s /3600;
    minutos = (s % 3600) / 60;
    segundos = (s % 3600) % 60;

    cout << s <<" segundos son"<< horas<< " horas," << minutos<< "minutos y"<< segundos <<" segundos" << endl;



    return 0;
}
