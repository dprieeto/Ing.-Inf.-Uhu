#include <iostream>
#include <cstdlib>
using namespace std;
class primo
{
    int n;
public:
    void cargar();
    bool esprimo();
};
void primo::cargar()
{
    cout<<"\t\t\tIntroduce un numero entero: ";cin>>n;
}
bool primo::esprimo()
{
    int primo1;
    int i=2;
    do
    {
        if (i!=n && n%i==0)
            primo1=false;
            i++;
    }while (i<=n/2 and primo1);
    return primo1;
}
int main()
{
    system("pause");
    system("cls");
    system("color 0a");
    primo ob;
    ob.cargar();
    cout<<"El numero elegido "<<(ob.esprimo()?"si":"no")<<" es primo."<<endl;
    system("pause");
    system("color 06");
    return 0;
}
