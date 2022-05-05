#include <iostream>

using namespace std;
class energia{
float m,v,h;
public:
    void leer();
    float ec();
    float ep();
};
void energia::leer(){
cout<<"Escribe el valor de la masa en kg: ";cin>>m;
cout<<"Escribe el valor de la velocidad en km/h: ";cin>>v;
cout<<"Escribe el valor de la altura en km: ";cin>>h;
}
float energia::ec(){
float ec,a;
a=v/(3600*1e-3);
ec=0.5*m*a*a;
return ec;
}
float energia::ep(){
float ep,g,b;
b=h*1e3;
g=9.8;
ep=g*m*b;
return ep;
}
int main()
{
    energia ob;
    ob.leer();
    cout<<"La energia cinetica es de: "<<ob.ec()<<" Julios.";
    cout<<"\nLa energia potencial es de: "<<ob.ep()<<" Julios.";
    cout<<"\nLa energia mecanica es de: "<<ob.ep()+ob.ec()<<" Julios.";
}
