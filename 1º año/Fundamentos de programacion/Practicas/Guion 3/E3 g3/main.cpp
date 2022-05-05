#include <iostream>
#include "tres.h"
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    tres t;
    t.cargar();
    cout<<"El numero "<<(t.encontrar()?"":"no")<<" se encuentra en la tabla___";getch();
    return 0;
}
