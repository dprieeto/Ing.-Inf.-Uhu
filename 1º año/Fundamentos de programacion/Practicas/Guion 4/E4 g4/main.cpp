#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> //funcion gets
using namespace std;
typedef char cadena[50];
#define MAX_CUENTAS 10
#define MAX_CLIENTES 100
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
class cliente
{
    cadena nombre;
    cadena direccion;
    cuenta cuentas[MAX_CUENTAS];
    int nocuentas;
public:
    cliente();
    void actualizarcliente(cadena pnom,cadena pdir);
    void damenombre(cadena pnom);
    void damedireccion(cadena pdir);
    int buscarcuenta(int pnocuenta);
    bool crearcuenta(cuenta pcu);
    bool actualizarcuenta(cuenta pcu);
    bool borrarcuenta(int pnocuenta);
    int damenocuentas();
    cuenta damecuenta(int pos);
    void mostrar(char campo);
};
cliente::cliente()
{
    strcpy(nombre,"");
    strcpy(direccion,"");
    nocuentas=0;
}
void cliente::actualizarcliente(cadena pnom,cadena pdir)
{
    strcpy(nombre,pnom);
    strcpy(direccion,pdir);
    nocuentas=0;
}
void cliente::damenombre(cadena pnom)
{
    strcpy(pnom,nombre);
}
void cliente::damedireccion(cadena pdir)
{
    strcpy(pdir,direccion);
}
int cliente::buscarcuenta(int pnocuenta)
{
    //busqueda =while
    bool encontrado=false;
    int i=0,nocue;
    while(!encontrado&&i<nocuentas)
    {
        nocue=cuentas[i].damenocuenta();
        if(nocue==pnocuenta)
            encontrado=true;
        else
            i++;
    }
    if(!encontrado)
        i=-1;
    return i;
}
bool cliente::crearcuenta(cuenta pcu)//inserccion de elementos en una tabla
{
    bool salida;
    int noc=pcu.damenocuenta();
    if(nocuentas<MAX_CUENTAS&&buscarcuenta(noc)<0)
    {
        salida=true;
        cuentas[nocuentas]=pcu;
        nocuentas++;
    }
    else
        salida=false;
    return salida;
}
bool cliente::actualizarcuenta(cuenta pcu)
{
    bool salida;
    int noc=pcu.damenocuenta();
    int posc=buscarcuenta(noc);
    if(posc>=0)
    {
        salida=true;
        cuentas[posc]=pcu;
    }
    else
        salida=false;
    return salida;
}
bool cliente::borrarcuenta(int pnocuenta)
{
    bool salida;
    int posnoc=buscarcuenta(pnocuenta);
    if(posnoc>=0)
    {
        for(int i=posnoc;i<nocuentas;i++)
        {
            cuentas[i]=cuentas[i+1];
            nocuentas--;
            salida=true;
        }
    }
    else
        salida=false;
    return salida;
}
int cliente::damenocuentas()
{
    return nocuentas;
}
cuenta cliente::damecuenta(int pos)
{
    return cuentas[pos];
}
void cliente::mostrar(char campo)
{
    if(campo=='s'||campo=='t')
    {
        cout<<"Nombre: "<<nombre<<"\tDireccion: "<<direccion<<endl;
    }
    if(campo=='c'||campo=='t')
    {
        for(int i=0;i<nocuentas;i++)
        {
            cout<<"N: "<<cuentas[i].damenocuenta()<<"\tSaldo: "
                <<cuentas[i].damesaldo()<<"\tBloq: "
                <<(cuentas[i].establoqueada()?"Si":"No")<<endl;
        }
    }
}
int buscarcliente(cliente ctes[MAX_CLIENTES],int nctes,cadena nombre)
{
    int pos,i;
    cadena nom;
    i=pos=-1;
    while(i<nctes&&pos==-1)
    {
        i++;
        ctes[i].damenombre(nom);
        if(strcmp(nom,nombre)==0)
            pos=i;
    }
    return pos;
}
int menu()
{
    int opcion;
    system("cls");system("color f0");
    cout<<"Menu principal"<<endl;
    cout<<"1.-Agregar un cliente"<<endl;
    cout<<"2.-Actualizar la direccion del cliente"<<endl;
    cout<<"3.-Mostrar un cliente"<<endl;
    cout<<"4.-Mostrar todos los clientes"<<endl;
    cout<<"5.-Submenu de Gestion de cuentas"<<endl;
    cout<<"6.-Salir"<<endl;
    cout<<endl<<"Elige una opcion: ";cin>>opcion;
    return opcion;
    cin.ignore();
}
int main()
{
    cliente datos[MAX_CLIENTES];
    int nclientes=0;
    bool salir;
    int pos;
    char opcion;
    cadena nombre;
    cadena direccion;
    int subpos,spos,numero,ncuentas=0;
    float saldo;
    cuenta c;
    bool subsalir;

    do
    {
        system("color f0");
        salir=false;
        opcion=menu();
        cin.ignore();//ponerlo cada vez que se haga un menu porque puede dar fallo
        system("cls");
        switch(opcion)
        {
        case 1:
            {
                if(nclientes<MAX_CLIENTES)
                {
                    cout<<"\nIntroduce el nombre del cliente: ";
                    //cin.ignore();gets(nombre);
                    //cin.ignore();
                    cin.getline(nombre,50,'\n');//getline sirve para incluir los espacios, el numero es la longitud de la cadena y el '\n' para que acabe la cadena
                    pos=buscarcliente(datos,nclientes,nombre);
                    if(pos!=-1)
                    {
                        cout<<"\nActualmente ya existe un cliente con ese nombre."<<endl;

                    }
                    else
                    {
                        cout<<"\nIntroduce su direccion: ";
                        cin.getline(direccion,50,'\n');
                        datos[nclientes].actualizarcliente(nombre,direccion);
                        nclientes++;
                        cout<<"\nCliente creado correctamente."<<endl;
                    }
                }
                else
                {
                    system("color f4");
                    cout<<"\nYa se ha alcanzado el limite de clientes."<<endl;
                }
                break;
            }
        case 2:
            {
                if(nclientes==0)
                {
                    cout<<"\nActualmente no hay clientes guardados."<<endl;
                }
                else
                {
                    cout<<"Introduce el nombre del cliente para modificar su domicilio: ";
                    cin.getline(nombre,50,'\n');
                    pos=buscarcliente(datos,nclientes,nombre);
                    if(pos==-1)
                    {
                        system("color f4");
                        cout<<"\nNo existe ningun cliente con ese nombre."<<endl;
                    }
                    else
                    {
                        cout<<"Introduce el nuevo domicilio del cliente: ";
                        cin.getline(direccion,50,'\n');
                        datos[pos].actualizarcliente(nombre,direccion);
                        cout<<"\nDireccion actualizada correctamente."<<endl;
                    }
                }
                break;
            }
        case 3:
            {
                if(nclientes==0)
                {
                    cout<<"\nActualmente no hay clientes guardados."<<endl;
                }
                else
                {
                    cout<<"Introduce el nombre del cliente que quieres ver: ";
                    cin.getline(nombre,50,'\n');
                    pos=buscarcliente(datos,nclientes,nombre);
                    if(pos==-1)
                    {
                        system("color f4");
                        cout<<"\nNo existe ningun cliente con ese nombre."<<endl;
                    }
                    else
                    {
                        datos[pos].mostrar('s');
                        //el 's' es del metodo mostrar para que muestre solo el nombre y la direccion
                        //ya que en el submenu se mostraran las cuentas, ya lo intentare de otra forma luego
                    }
                }
                break;
            }
        case 4:
            {
                if(nclientes==0)
                {
                    cout<<"\nActualmente no hay clientes guardados."<<endl;
                }
                else
                {
                    for(int i=0;i<nclientes;i++)
                    {
                        datos[i].mostrar('s');//implementar mas tarde con las cuentas corrientes;
                    }
                }
                break;
            }
        case 5:
            {
                if(nclientes==0)
                {
                    cout<<"\nActualmente no hay clientes guardados."<<endl;
                }
                else
                {
                    cout<<"Introduce el nombre del cliente para gestionar sus cuentas: ";
                    cin.getline(nombre,50,'\n');
                    pos=buscarcliente(datos,nclientes,nombre);
                    if(pos==-1)
                    {
                        system("color f4");
                        cout<<"\nNo existe ningun cliente con ese nombre."<<endl;
                    }
                    else
                    {
                        subpos=pos;
                        do
                        {
                            subsalir=false;
                            opcion=menucuentas();
                            cin.ignore();
                            system("cls");system("color f0");
                            switch(opcion)
                            {
                            case 1:
                                {
                                    if(ncuentas<MAX_CUENTAS)
                                    {
                                        cout<<"Introduce el numero de la cuenta: ";
                                        cin>>numero;
                                        spos=datos[subpos].buscarcuenta(numero);
                                        if(spos==-1)
                                        {
                                            cout<<"Introduce el saldo: ";
                                            cin>>saldo;
                                            if(datos[subpos].crearcuenta(cuenta(numero,saldo))==true);//funcion tipo bool, false si no se crea
                                                {
                                                    cout<<"\nLa cuenta fue creada correctamente."<<endl;
                                                    ncuentas++;
                                                }
                                        }
                                        else
                                        {
                                            system("color f4");
                                            cout<<"\nActualemente ya existe una cuenta con ese numero."<<endl;
                                        }
                                    }
                                    else
                                    {
                                        system("color f4");
                                        cout<<"\nYa se ha alcanzado el limite de cuentas."<<endl;
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
                                        datos[subpos].mostrar('c');
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
                                        cout<<"\nIntroduce el numero de la cuenta que quieres eliminar: ";
                                        cin>>numero;
                                        spos=datos[subpos].buscarcuenta(numero);
                                        if(spos==-1)//tenia numero==-1
                                        {
                                            system("color f4");
                                            cout<<"\nNo existen cuentas guardas con ese numero."<<endl;
                                        }
                                        else
                                        {
                                            if(datos[subpos].borrarcuenta(numero))
                                                cout<<"\nLa cuenta fue eliminada correctamente."<<endl;
                                            else
                                                system("color f4");
                                                cout<<"\nError, no se pudo eliminar la cuenta."<<endl;
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
                                        cout<<"Introduce el numero de la cuenta que quieres modificar su saldo: ";
                                        cin>>numero;
                                        spos=datos[subpos].buscarcuenta(numero);
                                        if(spos==-1)
                                        {
                                            system("color f4");
                                            cout<<"\nNo existe ninguna cuenta guardada con ese numero."<<endl;
                                        }
                                        else
                                        {
                                            cout<<"Introduce el nuevo saldo de la cuenta: ";
                                            cin>>saldo;
                                            datos[subpos].damecuenta(pos);
                                            if(c.actualizarsaldo(saldo))
                                            {
                                                datos[subpos].actualizarcuenta(c);
                                                cout<<"\nLa cuenta fue actualizada correctamente."<<endl;
                                            }
                                            else
                                            {
                                                system("color f4");
                                                cout<<"\nError al actualizar la cuenta, se encuentra bloqueada actualmente."<<endl;
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
                                        cout<<"\nIntroduce el numero de cuenta que quieres modificar su estado: ";
                                        cin>>numero;
                                        spos=datos[subpos].buscarcuenta(numero);
                                        if(spos==-1)
                                        {
                                            system("color f4");
                                            cout<<"\nNo existen cuentas guardas con ese numero."<<endl;
                                        }
                                        else
                                            {
                                                cout<<"Introduce 's' para bloquear la cuenta o 'n' para desbloquearla: ";
                                                cin>>opcion;
                                                c=datos[subpos].damecuenta(pos);
                                                if(opcion=='s')
                                                {
                                                    c.actualizarbloqueo(true);
                                                    cout<<"\nLa cuenta fue bloqueada."<<endl;
                                                    datos[subpos].actualizarcuenta(c);
                                                }
                                                else if(opcion=='n')
                                                {
                                                    c.actualizarbloqueo(false);
                                                    cout<<"\nLa cuenta fue desbloqueada."<<endl;
                                                    datos[subpos].actualizarcuenta(c);
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
                                    subsalir=true;
                                    break;
                                }
                            }
                            if(!subsalir)
                            {
                                cout<<endl<<endl;
                                system("pause");
                            }
                        }while(!subsalir);
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
