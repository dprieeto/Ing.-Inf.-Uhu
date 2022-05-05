#include <iostream>
#include "uno.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    uno ob;
    ob.cargar();
    cout<<endl<<"El maximo es: "<<ob.maximo();
    cout<<endl<<"El minimo es: "<<ob.minimo();
    return 0;
}
