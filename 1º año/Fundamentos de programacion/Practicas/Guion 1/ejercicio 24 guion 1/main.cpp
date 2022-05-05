#include <iostream>

using namespace std;
class campo{
double q,r;
public:
    void leer();
    double intensidad();
};
void campo::leer(){
cout<<"Escribe el valo de la carga en μC: ";cin>>q;
cout<<"Escribe el valor de la distancia en metros: ";cin>>r;
}
double campo::intensidad(){
double E,ep,pi;
pi=3.141592;
ep=8.85e-12;
E=((q*1e-6)/(4*pi*ep*r*r));
return E;
}
int main()
{
    campo ob;
    ob.leer();
    cout<<"La intensidad del campo electrico es de : "<<ob.intensidad()<<" N/C.";
}
