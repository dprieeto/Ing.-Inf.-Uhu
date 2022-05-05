#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    vector v;
    v.cargar();
    //cout<<"Las tablas "<<(v.comparar()?"no":"si")<<" son iguales."<<endl;
    if(v.comparar()==0)
    {
        cout<<"Las tablas son identicas."<<endl;
    }
    else
    {
        cout<<"Las tablas son diferentes."<<endl;
    }
    return 0;
}
