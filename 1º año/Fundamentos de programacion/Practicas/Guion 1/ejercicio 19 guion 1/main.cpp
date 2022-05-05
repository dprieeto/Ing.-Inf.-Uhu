#include <iostream>

using namespace std;
class rectangulo{
int largo;
int ancho;
public:
    void iniciar();
    void cargar();
    int area();
    void cambiar();
};
void rectangulo::iniciar(){
largo=4;
ancho=2;
cout<<"Inicialmente el largo vale 4u y el ancho 2u, pero lo vamos a cambiar.\n";
}
void rectangulo::cargar(){
cout<<"Dime la longitud del lado largo: ";cin>>largo;
cout<<"Dime la longitud del lado ancho: ";cin>>ancho;
}
int rectangulo::area(){
return (ancho*largo);
}
void rectangulo::cambiar(){
int c;
c=largo;
largo=ancho;
ancho=c;
cout<<"Ahora hemos cambiado el largo por el ancho que vale ahora "<<largo<<"u"<<" y el ancho por el largo que vale "<<ancho<<"u.\n";
}


int main()
{
    rectangulo a;
    a.iniciar();
    a.cargar();
    a.cambiar();
    cout<<"El area es: "<<a.area()<<"u^2.";
}
