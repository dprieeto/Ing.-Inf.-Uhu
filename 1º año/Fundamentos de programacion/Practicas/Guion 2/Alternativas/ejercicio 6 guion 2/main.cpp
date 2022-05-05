#include <iostream>

using namespace std;
class numero{
    int a,b;
public:
    void informacion();
    void operacion();
};
void numero::informacion(){

    cout<<"Introduce un numero entero: ";cin>>a;
    cout<<"Introduce otro numero entero: ";cin>>b;
    cout<<"Para hacer la suma de esos numeros escribe 'R','r','+'. Si quieres hacer la resta escribe 'R','r','-'.";

}
void numero::operacion(){
    char op;
    cout<<"\nElige la opcion deseada: ";cin>>op;
    if (op=='+' or op=='S' or op=='s')
        cout<<"La suma es: "<<(a+b)<<endl;
    else if (op=='-' or op=='R' or op=='r')
        cout<<"La resta es: "<<(a-b)<<endl;
    else cout<<"La operacion solicitada no es valida.";
}
int main()
{
    numero ob;
    ob.informacion();
    ob.operacion();
}
