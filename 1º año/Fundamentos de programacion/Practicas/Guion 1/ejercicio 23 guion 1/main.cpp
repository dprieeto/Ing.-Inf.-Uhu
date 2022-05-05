#include <iostream>

using namespace std;
class cargas{
double q1,q2,r;
public:
    void leer();
    double fuerza();
};
void cargas::leer(){
cout<<"Introduce el valor de q1 en μC: ";cin>>q1;
cout <<"Introduce el valor de q2 en μC: ";cin>>q2;
cout<<"Introduce el valor de r en metros: ";cin>>r;
}
double cargas::fuerza(){
double f,k;
k=9*1e9;
f=((k*(q1*1e-6)*(q2*1e-6))/(r*r));
return f;
}
int main()
{
 cargas ob;
 ob.leer();
 cout<<"La fuerza calculada es de: "<<ob.fuerza()<<" Newtons.";
}
