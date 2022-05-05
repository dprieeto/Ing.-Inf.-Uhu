#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
using namespace std;

typedef char cad[20];

class tprod
{
private:
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
    if(cantidad>stock)
    {
        cout<<"\nNo se dispone de la cantidad deseada."<<endl;
    }
    else
    {
        stock-=cantidad;
        cout<<"Precio total a pagar(euros): "<<cantidad*precio<<endl;
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
    int insertar(tprod p);
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
    //devuelve -1 si no esta en la tabla
    int pos,i;
    pos=-1;
    i=0;
    cad nombre;

    while(i<nprod&&pos==-1)
    {
        productos[i].leenombre(nombre);
        if(strcmp(nombre,nom)==0)
            pos=i;
        else
        i++;
    }
    return pos;
}
void almacen::verprod(int pos,tprod &prod)
{
    prod=productos[pos];
}
int almacen::insertar(tprod p)
{
    //2-tabla llena 1-ya existe 0-producto añadido
    int pos;
    cad nombre;
    if(nprod==MAX)
    {
        pos=2;
    }
    else
        {
            p.leenombre(nombre);
            if(existe(nombre)!=-1)
                pos=1;
            else
            {
                productos[nprod++]=p;
                pos=0;
            }
        }
    return pos;
}
void almacen::vertabla()
{
    if(nprod==0)
    {
        cout<<"\nEl almacen esta vacio."<<endl;
    }
    else
    {
        cad nombre;
        int stock;
        for(int i=0;i<nprod;i++)
        {
            productos[i].leenombre(nombre);
            productos[i].leestock(stock);
            cout<<"Nombre: "<<nombre<<"\tStock: "<<stock<<"\tPrecio(euros/unidad): "<<productos[i].leeprecio()<<endl;
        }
    }
}
void almacen::vender(int pos,int cant)
{
    int stock;
    float precio;
    precio=productos[pos].leeprecio();
    productos[pos].leestock(stock);
    if(stock<cant)
    {
        cout<<"\nNo se puede comprar mas cantidad de la que se dispone."<<endl;
    }
    else
    {
        productos[pos].cambiarstock(stock-cant);
        cout<<"Total a pagar(euros): "<<precio*cant<<endl;
    }
}
char menu()
{
    char opcion;
    system("cls");
    cout<<"***************MENU******************"<<endl;
    cout<<"*******A.- Visualizar la tabla. *****"<<endl;
    cout<<"*******B.- Insertar un producto.*****"<<endl;
    cout<<"*******C.- Vender un producto.  *****"<<endl;
    cout<<"*******D.- Vaciar el almacen.   *****"<<endl;
    cout<<"*******E.- Salir.               *****"<<endl;
    cout<<"*************************************"<<endl;
    cout<<"\tElige una opcion: ";
    cin>>opcion;cin.ignore();
    //cin.ignore();
    //cin.ignore();
    return opcion;
}
int main()
{
    bool salir;
    cad nombre;
    float precio;
    int stock,pos;
    char opcion;
    almacen alma;
    tprod prod;
    salir=false;
    do
    {
        opcion=menu();

        system("cls");
        switch(opcion)
        {
        case 'A':
        case 'a':
            {
                alma.vertabla();
                break;
            }
        case 'B':
        case 'b':
            {
                cout<<"\nIntroduce el nombre del producto: ";
                cin.getline(nombre,20,'\n');
                cout<<"\nIntroduce la cantidad disponible en stock: ";
                cin>>stock;
                cout<<"\nIntroduce el precio del producto: ";
                cin>>precio;
                prod.cambiarnombre(nombre);
                prod.cambiarstock(stock);
                prod.cambiarprecio(precio);
                pos=alma.insertar(prod);
                if(pos==2)
                {
                    cout<<"\nEl almacen esta lleno."<<endl;
                }
                else if(pos==1)
                {
                    cout<<"\nYa existe un producto con ese nombre."<<endl;
                }
                else if(pos==0)
                {
                    cout<<"\nEl producto fue creado correctamente."<<endl;
                }
                else
                    cout<<"\Error al crear el producto."<<endl;
                break;
            }
        case 'C':
        case 'c':
            {
                cout<<"\nIntroduce el nombre del producto que quieres vender: ";
                cin.getline(nombre,20,'\n');
                pos=alma.existe(nombre);
                if(pos==-1)
                {
                    cout<<"\nNo existen productos con ese nombre."<<endl;
                }
                else
                {
                    cout<<"\nIntroduce la cantidad que quieres vender: ";
                    cin>>stock;
                    alma.vender(pos,stock);
                }
                break;
            }
        case 'D':
        case 'd':
            {
                alma.vaciar();
                cout<<"\nEl almacen fue vaciado correctamente."<<endl;
                break;
            }
        case 'E':
        case 'e':
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
