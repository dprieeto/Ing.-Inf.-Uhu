#include <iostream>
#include <stdlib.h>
#include <conio.h>
#define tama 25
using namespace std;
class analisis
{
    int datos[1000];
    int ndatos;
    int valores[tama];
public:
    void pedirdatos();
    void analizardatos();
    bool estantodos();
    int valorrepetido();
    int valormasrepetido();
    void mostrardatos();
    void mostraranalisis();
};
void analisis::pedirdatos()
{
    char respuesta;

    cout<<"¿Quieres introducir los datos manualmente(m) o aleatoriamente(a)? ";cin>>respuesta;
    do
    {
        if()

    }while();
}
int main()
{
    analisis a;
    a.pedirdatos();
    return 0;
}
