#include <iostream>
#include <cstdlib>
using namespace std;

class estadistica
{
    int susp,apr,notab,sob;
public:
    void elaborarestadistica();
    void resultado();
};
void estadistica::elaborarestadistica()
{
    int i,cantidad;
    double nota;
    susp=apr=sob=notab=0;
    cout<<"Escribe el numero de alumnos que se han examinado: ";cin>>cantidad;
    for (i=0;i<cantidad;i++)
    {
       do
       {
        cout<<"\nIntroduce el valor de la nota: ";cin>>nota;
        if (nota<0 || nota>10){
            cout<<"\nError en la nota.Introduce la nota de nuevo.\n";}
    }while (nota<0 || nota>10);
      if (nota>=9){
            sob ++;
            apr ++;}
        else if (nota>=7){
            notab ++;
            apr ++;}
        else if (nota>=5){
            apr ++;}
        else if (nota<5){
            susp ++;}
    }
}
void estadistica::resultado()
{
    cout<<"\nEl numero de suspensos es: "<<susp;
    cout<<"\nEl numero de aprobados es: "<<apr;
    cout<<"\nLa cantidad de notables es: "<<notab;
    cout<<"\nLa cantidad de sobresalientes es: "<<sob;
}
int main()
{
    system("pause");
    system("cls");
    system("color 0a");
    estadistica ob;
    ob.elaborarestadistica();
    ob.resultado();
    return 0;
}
