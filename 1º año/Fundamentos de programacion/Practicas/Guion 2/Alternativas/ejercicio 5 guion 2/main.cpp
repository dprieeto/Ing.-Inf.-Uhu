#include <iostream>

using namespace std;
class fecha{
        int agno;
    public:
        bool bisiesto();
        void leer();
};
bool fecha::bisiesto(){
        int resto;
        resto=agno%4;
        if (resto==0){
            cout<<"El agno es bisiesto.";
            return true;}
            else
                cout<<"El agno no es bisiesto.";
                return false;
}

void fecha::leer(){
    cout<<"Escribe un agno: ";cin>>agno;
}
int main()
{
    fecha ob;
    ob.leer();
    ob.bisiesto();
    return 0;
}
