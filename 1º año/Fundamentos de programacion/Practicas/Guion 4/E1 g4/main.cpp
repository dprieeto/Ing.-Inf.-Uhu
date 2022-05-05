#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 5
using namespace std;
typedef char cad[20];
class tprod
{
    cad nombre;
    float precio;
    int stock;
public:
    tprod();
    void cambiarnombre(cad nom);
    void cambiarprecio(float prec);
    void cambiarstock(int stoc);
    void leenombre(cad nom);
    float leeprecio();
    void leestock(int &st);
    void vender(int cantidad);
};
tprod::tprod()
{
    strcpy(nombre,"NO HAY PRODUCTO");
    precio=0;
    stock=0;
}
void tprod::cambiarnombre(cad nom)
{
    strcpy(nombre,nom);
}
void tprod::cambiarprecio(float prec)
{
    precio=prec;
}
void tprod::cambiarstock(int stoc)
{
    stock=stoc;
}
void tprod::leenombre(cad nom)
{
    strcpy(nom,nombre);
}
float tprod::leeprecio()
{
    return precio;
}
void tprod::leestock(int &st)
{
    st=stock;
}
void tprod::vender(int cantidad)
{
    if(stock>=cantidad)
    {
        stock-=cantidad;
        cout<<"Total a pagar: "<<precio*cantidad<<" euros."<<endl;
    }
    else
    {
        cout<<"No se dispone de sufiente cantidad para realizar la venta."<<endl;
    }
}
class almacen
{
    tprod productos[MAX];
    int nprod;
public:
    almacen();
    void vaciar();
    int existe(cad nom);
    void verprod(int pos,tprod &prod);
    int insertar(tprod P);
    void vertabla();
    void vender(int pos,int cant);
};
almacen::almacen()
{
    vaciar();
}
void almacen::vaciar()
{
    nprod=0;
}
int almacen::existe(cad nom)
{
    int i,pos;
    cad nombre;
    pos=-1;//devuelve -1 si el nombre del producto no esta en el almacen
    i=0;
    while(i<nprod&&pos==-1)//busqueda porque no es necesario pasar por todos los elementos de la tabla
    {
        productos[i].leenombre(nombre);
        if(strcmp(nombre,nom)==0)
        {
            pos=i;
        }
        else
            i++;
    }
    return pos;
}
void almacen::verprod(int pos,tprod &prod)
{
    prod=productos[pos];
}
int almacen::insertar(tprod P)
{
    //devuelve 2-almacen lleno,1-producto con nombre existente,0-producto insertado correctamente
    int resultado;
    cad nombre;
    if(nprod==MAX)
        resultado=2;
    else
    {
        P.leenombre(nombre);
        if(existe(nombre)!=-1)
            resultado=1;
        else
            productos[nprod++]=P;
            resultado=0;
    }
    return resultado;
}
void almacen::vertabla()
{
    cad nombre;
    int stock;
    if(nprod==0)
        cout<<"El almacen esta vacio."<<endl;
    else
    {
        for(int i=0;i<nprod;i++)
        {
            productos[i].leenombre(nombre);
            productos[i].leestock(stock);
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Precio(euros): "<<productos[i].leeprecio()<<endl;
            cout<<"Stock: "<<stock<<endl<<endl;
        }
    }
}
void almacen::vender(int pos,int cant)
{
    int stock;
    float precio=productos[pos].leeprecio();
    productos[pos].leestock(stock);
    if(stock>=cant)
    {
        cout<<"Total a pagar: "<<precio*cant<<" euros."<<endl;
    }
    else
        {
            cout<<"No hay suficiente cantidad en stock."<<endl;
        }
}
char menu()
{
    char opcion;
    system("cls");
    cout<<"************* MENU ******************"<<endl;
    cout<<"*******A.- Visualizar la tabla. *****"<<endl;
    cout<<"*******B.- Insertar un producto.*****"<<endl;
    cout<<"*******C.- Vender un producto.  *****"<<endl;
    cout<<"*******D.- Vaciar el almacen.   *****"<<endl;
    cout<<"*******E.- Salir                *****"<<endl;
    cout<<"*************************************"<<endl;
    cout<<"Pon la opcion que deseas: ";
    cin>>opcion;
    return opcion;
}
int main()
{
    bool continuar=true;
    tprod prod;
    almacen a;
    cad nombre;
    int stock,i,pos;
    float precio;
    char ch;
    do
    {
        system("cls");
        switch(menu())
        {
        case 'A':
        case 'a':
            {
                a.vertabla();
                break;
            }
        case 'B':
        case 'b':
            {
                system("cls");
                cout<<"Introduce el nombre del producto: ";
                cin.ignore();
                gets(nombre);
                prod.cambiarnombre(nombre);
                cout<<"Introduce el precio: ";
                cin>>precio;
                prod.cambiarprecio(precio);
                cout<<"Introduce la cantidad disponible en stock: ";
                cin>>stock;
                prod.cambiarstock(stock);
                switch(a.insertar(prod))
                {
                case 2:
                    {
                        cout<<endl<<"El almacen esta lleno."<<endl;
                        break;
                    }
                case 1:
                    {
                        cout<<endl<<"Ya existe un producto con ese nombre."<<endl;
                        break;
                    }
                case 0:
                    {
                        cout<<endl<<"Producto creado correctamente."<<endl;
                        break;
                    }
                }
                break;
            }
            case 'C':
            case 'c':
            {
                system("cls");
                cout<<"Introduce el nombre del producto a vender: ";
                cin.ignore();
                gets(nombre);
                pos=a.existe(nombre);
                if(pos==-1)
                {
                    cout<<endl<<"No existe ningun producto con ese nombre."<<endl;
                }
                else
                {
                    cout<<"Introduzca la cantidad a vender: ";
                    cin>>stock;
                    a.vender(pos,stock);
                }
            }
        }
    }while(continuar);


















    return 0;
}
