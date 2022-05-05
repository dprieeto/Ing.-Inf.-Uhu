#include <iostream>

using namespace std;
class numero{
    int a;
    public:
        void informacion();
        long factorial();
};
void numero::informacion(){
    cout<<"Vamos a calcular el factorial de un numero:\n";
    do
    {
        cout<<"Introduce un numero entero positivo menor que 20: ";cin>>a;
    }
    while (a<0 or a>=20);
}
long numero::factorial(){
    long factorial = 1;

	for(int i = 1; i <= a; i++)
		factorial *= i;

	return factorial;
}

int main()
{
    numero ob;
    ob.informacion();
    cout<<"El factorial del numero elegido es: "<<ob.factorial();
    return 0;
}
