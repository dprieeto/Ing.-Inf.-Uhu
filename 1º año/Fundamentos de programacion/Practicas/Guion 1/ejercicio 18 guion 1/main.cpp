#include <iostream>
using namespace std;
    class empleado {
    int hn, he;
public:
    void cargar();
    float nomina();
    };
    void empleado::cargar(){
     cout << "Numero de horas normales trabajadas: ";
    cin >> hn;
    cout << "Numero de horas extraordinarias trabajadas: ";
    cin >> he;

    }
float empleado::nomina(){
    return (hn*5+he*8)*0.85;
}
int main(){
empleado ob1,ob2;
ob1.cargar();
cout<<"El sueldo total es de: "<< ob2.nomina()<<" euros";

return 0;
}

