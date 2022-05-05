#include <iostream>

using namespace std;

int main()
{
    int menu,a,b;
    cout<<"Introduzca un numero entero: ";cin>>a;
    cout<<"Introduzca otro numero entero: ";cin>>b;
    do
    {
        cout<<"\t\tMENU PRINCIPAL\n";
        cout<<"\t\t1.Sumar.\n";
        cout<<"\t\t2.Restar.\n";
        cout<<"\t\t3.Multiplicar.\n";
        cout<<"\t\t4.Dividir.\n";
        cout<<"\n\n         Elija una opcion:";cin>>menu;
            switch (menu)
            {
                case 1:
                {
                    int sum;
                    sum=a+b;
                    cout<<"La suma es: "<<sum<<"\n";
                    break;
                }
                case 2:
                {
                    int res;
                    res=a-b;
                    cout<<"La resta es: "<<res<<"\n";
                    break;
                }
                case 3:
                {
                    int mul;
                    mul=a*b;
                    cout<<"El producto es: "<<mul<<"\n";
                    break;
                }
                case 4:
                {
                    if (b!=0){
                    int div;
                    div=a/b;
                    cout<<"La division es: "<<div<<"\n";}
                   else
                    cout<<"No puede dividir un numero entre 0 porque tiende a infinito.\n";
                    break;
                }
                default:cout<<"Opcion invalida."<<endl;
            }
    } while (menu !=5);
      return 0;
}

