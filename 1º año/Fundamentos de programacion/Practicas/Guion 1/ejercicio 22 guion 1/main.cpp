#include <iostream>

using namespace std;
class complejo{
float z1,z2,a,b,c,d,sum1,sum2,mul1,mul2,res1,res2,div1,div2;
public:
    void iniciar();
    void sumar();
    void restar();
    void multiplicar();
    void dividir();
    void resultado();


};
void complejo::iniciar(){
cout<<"Dados dos numeros complejos (z1,z2) de la forma 'x+iy': \n";
cout<<"Introduce la coordenada del eje x de z1: ";cin>>a;
cout<<"introduce la coordenada del eje imaginario de z1: ";cin>>b;
cout<<"Introduce la coordenada del eje x de z2: ";cin>>c;
cout<<"Introduce la coordenada del eje imaginario de z2: ";cin>>d;
}
void complejo::sumar(){
sum1=a+c;
sum2=b+d;
}
void complejo::restar(){
res1=a-c;
res2=b-d;
}
void complejo::multiplicar(){
mul1=a*c-b*d;
mul2=a*d+b*c;
}
void complejo::dividir(){
div1=((a*c+b*d)/(c*c+d*d));
div2=((b*c-a*d)/(c*c+d*d));
}

void complejo::resultado(){
cout<<"La suma de los dos numeros complejos es: "<<sum1<<" +(i*"<<sum2<<")";
cout<<"\nLa resta de los dos numeros complejos es: "<<res1<<" +(i*"<<res2<<")";
cout<<"\nEl producto de los dos numeros complejos es: "<<mul1<<" +(i*"<<mul2<<")";
cout<<"\nLa division de los dos numeros complejos es: "<<div1<<" +(i*"<<div2<<")";
}
int main()
{
    complejo ob;
    ob.iniciar();
    ob.sumar();
    ob.restar();
    ob.multiplicar();
    ob.dividir();
    ob.resultado();
}
