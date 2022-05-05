#include <iostream>
#include <stdlib.h>
using namespace std;
typedef char cadena[30];
#define MAX_CUENTAS 100
class cuenta
{
    float saldo;
    int nocuenta;
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
    nocuenta=0;
    saldo=0;
}
cuenta::cuenta(int pno,float psal)
{
    nocuenta=pno;
    saldo=psal;
    bloqueada=false;
}
bool cuenta::actualizarsaldo(int psal)
{
    bool bloq=false;
    if(bloqueada==false)
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
    int i,pos;
    pos=-1;
    i=0;
    while(i<ncuentas&&pos==-1)
    {
        if(ctas[i].damenocuenta()==nocuenta)
        {
            pos=i;
        }
        else
            i++;
    }
    return pos;
}
int menucuentas()
{
    int opcion;
    system("cls");
    cout<<"Menu Gestion de cuentas"<<endl;
    cout<<"1.-Agregar una cuenta a un cliente"<<endl;
    cout<<"2.-Mostrar las cuentas de un cliente"<<endl;
    cout<<"3.-Borrar una cuenta a un cliente"<<endl;
    cout<<"4.-Modificar saldo de una cuenta"<<endl;
    cout<<"5.-Modificar estado de una cuenta"<<endl;
    cout<<"6.-Salir"<<endl;
    cout<<endl<<"Elige una opcion: ";cin>>opcion;
    return opcion;
}
int main()
{
    cuenta datoscuenta[MAX_CUENTAS];
    int ncuentas=0;
    bool salir=false;
    int pos,numero;
    char opcion;
    float saldo;
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
                    cout<<"Introduzca el numero de la cuenta: ";
                    cin>>numero;
                    if(buscarcuenta(datoscuenta,ncuentas,numero)==-1)
                       {
                           cout<<"Introduce el saldo: ";
                           cin>>saldo;
                           datoscuenta[ncuentas]=cuenta(numero,saldo);
                           ncuentas++;
                           cout<<endl<<"Cuenta creada correctamente."<<endl;
                       }
                       else
                        {
                            cout<<endl<<"Ya existe una creada con ese numero."<<endl;
                        }
                }
                else
                {
                    cout<<endl<<"Ya ha superado el numero de cuentas permitido."<<endl;
                }
                break;
            }
        case 2:
            {
                if(ncuentas==0)
                {
                    cout<<endl<<"No se han encontrado cuentas guardadas."<<endl;
                }
                else
                {
                    for(int i=0;i<ncuentas;i++)
                    {
                        cout<<"Numero: "<<datoscuenta[i].damenocuenta()<<endl;
                        cout<<"Saldo(euros): "<<datoscuenta[i].damesaldo()<<endl;
                        cout<<"Estado: "<<(datoscuenta[i].establoqueada()?"Bloqueada":"Activa")<<endl;
                    }
                }
                break;
            }
        case 3:
            {
                int pos;
                if(ncuentas==0)
                {
                    cout<<endl<<"No se han encontrado cuentas guardadas."<<endl;
                }else{
                cout<<"Introduce el numero de cuenta que quieres eliminar: ";
                cin>>numero;
                pos=buscarcuenta(datoscuenta,ncuentas,numero);
                if(pos==-1)
                {
                    cout<<endl<<"Actualmente no existe ninguna cuenta con ese numero."<<endl;
                }
                else
                {
                    ncuentas--;
                    for(int i=pos;i<ncuentas;i++)
                    {
                        datoscuenta[i]=datoscuenta[i+1];
                    }
                    cout<<endl<<"La cuenta fue eliminada."<<endl;
                }}
                break;
            }
        case 4:
            {
                if(ncuentas==0)
                {
                    cout<<endl<<"No se han encontrado cuentas guardadas."<<endl;
                }else{
                cout<<"Introduce el numero de cuenta de la que quieres modificar el saldo: ";
                cin>>numero;
                pos=buscarcuenta(datoscuenta,ncuentas,numero);
                if(pos==-1)
                {
                    cout<<endl<<"No existe ninguna cuenta con ese numero."<<endl;
                }
                else
                {
                    cout<<"Introduzca el nuevo saldo: ";
                    cin>>saldo;
                    if(datoscuenta[pos].actualizarsaldo(saldo))
                    {
                        cout<<endl<<"La cuenta fue modificada con exito."<<endl;
                    }
                    else
                    {
                        cout<<endl<<"Actualmente la cuenta se encuentra bloqueada, la operacion no pudo ser realizada."<<endl;
                    }
                }}
                break;
            }
        case 5:
            {
                if(ncuentas==0)
                {
                    cout<<endl<<"No se han encontrado cuentas guardadas."<<endl;
                }else{
                char opc;
                cout<<"Introduce el numero de cuenta que quieras modificar: ";
                cin>>numero;
                pos=buscarcuenta(datoscuenta,ncuentas,numero);
                if(pos==-1)
                {
                    cout<<endl<<"No existe ninguna cuenta asociada a ese numero."<<endl;
                }
                else
                {
                    cout<<"Introduzca 's' para bloquear la cuenta o 'n' para desbloquearla: ";
                    cin>>opc;
                    if(opc=='s')
                    {
                        datoscuenta[pos].actualizarbloqueo(true);
                        cout<<endl<<"La cuenta fue bloqueada."<<endl;
                    }
                    else if(opc=='n')
                    {
                        datoscuenta[pos].actualizarbloqueo(false);
                        cout<<endl<<"La cuenta fue desbloqueada."<<endl;
                    }
                    else
                    {
                        cout<<endl<<"Error al introducir la opcion."<<endl;
                    }
                }}
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
            cout<<endl<<"Pulse cualquier tecla para regresar al menu.";
            cin.ignore();
            cin.ignore();
            system("cls");
        }
    }while(!salir);
    return 0;
}
