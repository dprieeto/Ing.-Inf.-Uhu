#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MAX_CUENTAS 100
using namespace std;

typedef char cadena[50];

class cuenta
{
private:
    float saldo;//saldo de la cuenta
    int nocuenta;//numero de cuenta
    bool bloqueada;//true si esta bloqueada
public:
    cuenta();
    cuenta(int pno,float psal);
    bool actualizarsaldo(int psal);
    void actualizarbloqueo(bool pbloq);
    float damesaldo();
    int damenocuenta();
    bool establoqueada();
};

cuenta::cuenta()
{
    bloqueada=false;
    nocuenta=saldo=0;
}
cuenta::cuenta(int pno,float psal)
{
    bloqueada=false;
    saldo=psal;
    nocuenta=pno;
}
bool cuenta::actualizarsaldo(int psal)
{
    bool bloq=false;
    if(!bloqueada)
    {
        saldo=psal;
        bloq=true;
    }
    return bloq;
}
void cuenta::actualizarbloqueo(bool pbloq)
{
    bloqueada=pbloq;
}
float cuenta::damesaldo()
{
    return saldo;
}
int cuenta::damenocuenta()
{
    return nocuenta;
}
bool cuenta::establoqueada()
{
    return bloqueada;
}
int buscarcuenta(cuenta ctas[MAX_CUENTAS],int ncuentas,int nocuenta)
{
    //devuelve -1 si no hay ninguna cuenta con ese numero
    //esquema de busqueda
    int i,pos;
    i=pos=-1;
    while(i<ncuentas&&pos==-1)
    {
        i++;
        if(nocuenta==ctas[i].damenocuenta())
            pos=i;
    }
    return pos;
}
int menucuentas()
{
    int opcion;system("cls");system("color f0");
    cout<<"\tMENU GESTION DE CUENTAS"<<endl;
    cout<<"1.-Agregar una cuenta a un cliente"<<endl;
    cout<<"2.-Mostrar las cuentas a un cliente"<<endl;
    cout<<"3.-Borrar una cuenta del cliente"<<endl;
    cout<<"4.-Modificar el saldo de una cuenta"<<endl;
    cout<<"5.-Modificar el estado de una cuenta"<<endl;
    cout<<"6.-Salir"<<endl;
    cout<<"\nElige una opcion: ";cin>>opcion;
    return opcion;
}

int main()
{
    cuenta datoscuentas[MAX_CUENTAS];
    int ncuentas=0;
    bool salir=false;
    int numero,pos;
    float saldo;
    char opcion;
    do
    {
        opcion=menucuentas();
        system("cls");
        switch(opcion)
        {
        case 1:
            {
                if(ncuentas<MAX_CUENTAS)
                {
                    cout<<"Introduce el numero de la nueva cuenta: ";cin>>numero;
                    pos=buscarcuenta(datoscuentas,ncuentas,numero);
                    if(pos!=-1)
                    {
                        cout<<"\nActualmente ya existe una cuenta con ese numero."<<endl;
                    }
                    else
                    {

                        cout<<"Introduce el nuevo saldo: ";cin>>saldo;
                        datoscuentas[ncuentas]=cuenta(numero,saldo);
                        ncuentas++;
                        cout<<"\nLa cuenta fue creada correctamente."<<endl;
                    }
                }
                else
                    {
                        cout<<"\nYa has alcanzado el limite de cuentas creadas."<<endl;
                    }
                break;
            }
        case 2:
            {
                if(ncuentas==0)
                {
                    cout<<"\nActualmente no hay cuentas guardadas."<<endl;
                }
                else
                {
                    for(int i=0;i<ncuentas;i++)
                    {
                        cout<<"\nNumero de cuenta: "<<datoscuentas[i].damenocuenta();
                        cout<<"\nSaldo actual: "<<datoscuentas[i].damesaldo();
                        cout<<"\nEstado: "<<(datoscuentas[i].establoqueada()?"Bloqueada":"Desbloqueada")<<endl;
                    }
                }
                break;
            }
        case 3:
            {
                if(ncuentas==0)
                {
                    cout<<"\nActualmente no hay cuentas guardadas."<<endl;
                }
                else
                {
                    cout<<"Introduce el numero de cuenta a eliminar: ";cin>>numero;
                    pos=buscarcuenta(datoscuentas,ncuentas,numero);
                    if(pos==-1)
                    {
                        system("color f4");
                        cout<<"No existe ninguna cuenta con ese numero."<<endl;
                    }
                    else
                    {
                        ncuentas--;
                        for(int i=pos;i<ncuentas;i++)
                        {
                            datoscuentas[i]=datoscuentas[i+1];
                        }
                        cout<<"\nLa cuenta fue eliminada correctamente."<<endl;
                    }
                }
                break;
            }
        case 4:
            {
                if(ncuentas==0)
                {
                    cout<<"\nActualmente no hay cuentas guardadas."<<endl;
                }
                else
                {
                    cout<<"Introduce el numero de la cuenta a modificar el saldo: ";cin>>numero;
                    pos=buscarcuenta(datoscuentas,ncuentas,numero);
                    if(pos==-1)
                    {
                        system("color f4");
                        cout<<"\nNo existe niguna cuenta guardada con ese numero."<<endl;
                    }
                    else
                    {
                        cout<<"Introduce el nuevo saldo: ";cin>>saldo;
                        if(datoscuentas[pos].actualizarsaldo(saldo))//si es true se actualiza el saldo
                        {
                            cout<<"\n La cuenta fue modificada correctamente."<<endl;
                        }
                        else
                        {
                            system("color f4");
                            cout<<"No se pudo modificar el saldo de la cuenta, actualmente se encunetra blopqueda."<<endl;
                        }
                    }
                }
                break;
            }
        case 5:
            {
                if(ncuentas==0)
                {
                    cout<<"\nActualmente no hay cuentas guardadas."<<endl;
                }
                else
                {
                    cout<<"Introduce el numero de cuenta que quieres actualizar: ";cin>>numero;
                    pos=buscarcuenta(datoscuentas,ncuentas,numero);
                    if(pos==-1)
                    {
                        system("color f4");
                        cout<<"\nNo existe ninguna cuenta guardada con ese numero."<<endl;
                    }
                    else
                    {
                        cout<<"Introduce 's' para bloquear la cuenta o 'n' para desbloquearla: ";cin>>opcion;
                        if(opcion=='s')
                        {
                            datoscuentas[pos].actualizarbloqueo(true);
                            cout<<"\nLa cuenta fue bloqueada."<<endl;
                        }
                        else if(opcion=='n')
                        {
                            datoscuentas[pos].actualizarbloqueo(false);
                            cout<<"\nLa cuenta fue desbloqueada."<<endl;
                        }
                        else
                        {
                            system("color f4");
                            cout<<"\nError al introducir la opcion."<<endl;
                        }
                    }
                }
                break;
            }
        case 6:
            {
                salir=true;
                break;
            }
        }
        if(!salir)
        {
            cout<<endl<<endl;
            system("pause");
        }
    }while(!salir);
    return 0;
}
