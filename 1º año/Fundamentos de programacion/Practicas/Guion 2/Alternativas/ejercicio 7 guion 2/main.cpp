#include <iostream>

using namespace std;
class billete{
    int dias,edad,distancia;
    public:
        void informacion();
        float operacion();
};
void billete::informacion(){
    cout<<"Introduce la distancia (en km) del viaje: ";cin>>distancia;
    cout<<"Introduce la edad: ";cin>>edad;
    cout<<"Introduce el numero de dias: ";cin>>dias;
}
float billete::operacion(){
    float precio;
    precio=distancia*0.5;
    if (distancia>800 && edad>55 || dias>7)
        precio*0.75;
    return precio;
}
int main()
{
    billete ob;
    ob.informacion();
    cout<<"\nEl precio de tu billete de ida y vuelta es de: "<<ob.operacion()<<" euros.";
    return 0;
}
