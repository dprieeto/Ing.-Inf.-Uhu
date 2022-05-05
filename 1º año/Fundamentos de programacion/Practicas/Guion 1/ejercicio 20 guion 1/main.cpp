#include <iostream>

using namespace std;
class movimiento
{
    float vo,so,a,t,s,v;
public:
    void iniciar();
    void calculo();
    void resultado();
};
void movimiento::iniciar()
{
    cout<<"Escribe la velocidad inicial(en metros por segundo): ";
    cin>>vo;
    cout<<"Escribe la distancia inicial(en metros): ";
    cin>>so;
    cout<<"Escribe el tiempo empleado(en segundos): ";
    cin>>t;
    cout<<"Escribe la aceleracion(en metros por segundo al cuadrado): ";
    cin>>a;
}
void movimiento::calculo()
{
    v=vo+a*t;
    s=(so+(vo*t)+(0.5*a*(t*t)));

}
void movimiento::resultado()
{
    cout<<"La velocidad final sera de "<<v<<"m/s y el espacio recorrido sera de "<<s<<"m.";
}
int main()
{
    movimiento a;
    a.iniciar();
    a.calculo();
    a.resultado();
    return 0;
}
