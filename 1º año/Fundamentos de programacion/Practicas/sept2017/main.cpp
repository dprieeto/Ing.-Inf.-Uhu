#include<iostream>
#include<string.h>
using namespace std;
typedef char cadena[30];
struct producto{
cadena nomprod;//Nombre del producto
int precio;//Precio por unidad del producto
};
struct seccion{
producto prods[40];
int nprod;//Número de productos almacenados en prods
//desde prods[0] a prods[nprod-1]
};
class empresa{
cadena nomempresa;//Nombre de la empresa;
seccion sec[5];
int nsec;//Número de secciones almacenadas en sec
//desde sec[0] hasta sec[nsec-1]
public:
empresa();
//Pedirá por teclado el nombre de la empresa, cuantas secciones tiene la empresa
//Para cada seccion anterior pedira cuantos productos tiene y para cada
//producto su nombre y el precio unitario.
bool insertar(int ns,producto prod);
//Comprobará si ya existe un producto almacenado en cualquier sección
//de la empresa con el mismo nombre que tiene prod.
//Si ya existía devolverá false y no lo insertará.
//Si no existía,comprobará si la tabla prods de la seccion ns está llena,
//Si está llena devolverá false no añadiéndolo, en caso contrario
//si hay hueco lo insertará devolviendo true.
void numerosecciones(int &n);
//Devuelve en n el numero de secciones que hay en la empresa
void listar();
}
;
empresa::empresa(){
cout<<"Pon el nombre de la empresa:";
cin>>nomempresa;
cout<<"¿Cuantas secciones tiene?:";
cin>>nsec;
for(int i=0;i<nsec;i++){//Para cada sec[i]
cout<<"¿Cuantos productos tiene?: ";
cin>>sec[i].nprod;
for(int j=0;j<sec[i].nprod;j++){//  Para cada prods[j]
cout<<"Pon el nombre del producto: ";
cin>>sec[i].prods[j].nomprod;
cout<<"Pone el precio del producto ";
cin>>sec[i].prods[j].precio;
}
}
}
bool empresa::insertar(int ns,producto prod){
bool devuelto;
bool tablallena=false;
int cantidad;
bool encontrado=false;
int i=0;
int j=0;
while((i<nsec)&&(!encontrado)){
j=0;
while((j<sec[i].nprod)&&(!encontrado)){
if(strcmp(sec[i].prods[j].nomprod,prod.nomprod)==0)
encontrado=true;
else j++;
}
i++;
}
if(!encontrado){
if(sec[ns].nprod==40)tablallena=true;
else{
cantidad=sec[ns].nprod;
sec[ns].prods[cantidad]=prod;
sec[ns].nprod++;
}
}
if(encontrado==true)devuelto=false;
else if(tablallena==true)devuelto=false;
else devuelto=true;
return devuelto;
}
void empresa::numerosecciones(int&n){
n=nsec;
}
void empresa::listar(){
for(int i=0;i<nsec;i++){
cout<<"SECCION N."<<i<<"\ n";
for(int j=0;j<sec[i].nprod;j++){
cout<<"PRODUCTO N. "<<j<<" "<<
sec[i].prods[j].nomprod<<" "<<sec[i].prods[j].precio<<"\n";
}
}
}
int main(){
empresa emp;
producto p;
int numero;
int numsec;
bool insertado;
cout<<"Pon el nombre del producto a insertar: ";
cin>>p.nomprod;
cout<<"Pon el precio por unidad del producto: ";
cin>>p.precio;
emp.numerosecciones(numsec);
do {
cout<<"Pon el numero de la seccion: ";
cin>>numero;
}
while((numero<0)||(numero>=numsec));
emp.listar();
insertado=emp.insertar(numero,p);
if(insertado==true) cout<<"Se ha insertado correctamente";
else cout<<"Error en la inserción ";
emp.listar();
cout<<"Pon el nombre del producto a insertar:";
cin>>p.nomprod;
cout<<"Pon el precio por  unidad del producto: ";
cin>>p.precio;
emp.numerosecciones(numsec);
do{
cout<<"Pon el numero de la seccion:";
cin>>numero;
}
while((numero<0)||(numero>=numsec));
emp.listar();
insertado=emp.insertar(numero,p);
if(insertado==true)cout<<"Se ha insertado correctamente";
else cout<<"Error en la inserción";
}
