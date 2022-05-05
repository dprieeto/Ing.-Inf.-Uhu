#include "numeros.h"



void numeros::pedirdatos()
{
    cout<<"Introduce un valor entero: ";cin>>a;
    cout<<"Introduce otro valor entero: ";cin>>b;
    estado=true;
}
void numeros::sumar()
{
    if(estado==true)
    {
        int suma;
        suma=a+b;
        cout<<"La suma de los dos valores es: "<<suma<<endl;
        system("pause");
    }
    else
    {
        cout<<"Tienes que introducir los datos primero";getch();
    }
}
void numeros::restar()
{
    if(estado==true)
    {
        int resta;
        resta=a-b;
        cout<<"La resta de los dos valores es: "<<resta<<endl;
        system("pause");
    }
    else
    {
        cout<<"Tienes que introducir los datos primero";getch();
    }
}
void numeros::multiplicar()
{
    if(estado==true)
    {
        int mult;
        mult=a*b;
        cout<<"El producto de los dos valores es: "<<mult<<endl;
        system("pause");
    }
    else
    {
        cout<<"Tienes que introducir los datos primero";getch();
    }
}
void numeros::dividir()
{
    if(estado==true)
    {
        float div;
        if(b!=0)
        {
            div=float(a)/float(b);
            cout<<"La division de los dos valores es: "<<div<<endl;
            system("pause");
        }
        else
        {
            cout<<"No se puede dividir entre 0"<<endl;system("pause");
        }
    }
    else
    {
        cout<<"Tienes que introducir los datos primero";getch();
    }
}
