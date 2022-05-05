#include <iostream>
#include <cmath>
using namespace std;
class fracciones{
float a,b,c,d,div,mul,sum,res;
public:
    void dividir();
    void sumar();
    void restar();
    void multiplicar();
    void resultado();
    void iniciar();
    };
    void fracciones::sumar(){
    sum=((a/b)+(c/d));
    }
    void fracciones::restar(){
    res=((a/b)-(c/d));
    }
    void fracciones::multiplicar(){
    mul=((a*c)/(b*d));
    }
    void fracciones::dividir(){
    div=((a*d)/(b*c));
    }
    void fracciones::resultado(){
    cout<<"La suma de las fracciones es: "<<sum;
    cout<<"\nLa resta de las fracciones es: "<<res;
    cout<<"\nEl producto de las fracciones es: "<<mul;
    cout<<"\nEl cociente de las fracciones es: "<<div;
    }
    void fracciones::iniciar(){
    cout<<"Escribe el numerador de la primera fraccion: ";cin>>a;
    cout<<"Escribe el denominador de la primera fraccion: ";cin>>b;
    cout<<"Escribe el numerador de la segunda fraccion: ";cin>>c;
    cout<<"Escribe el denominador de la segunda fraccion: ";cin>>d;
    }
int main()
{
    fracciones ob;
    ob.iniciar();
    ob.sumar();
    ob.restar();
    ob.multiplicar();
    ob.dividir();
    ob.resultado();
    return 0;
}
