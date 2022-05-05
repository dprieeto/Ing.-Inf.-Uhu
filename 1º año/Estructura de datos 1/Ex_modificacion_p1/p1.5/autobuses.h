#ifndef AUTOBUSES_H
#define AUTOBUSES_H
#include <fstream>

using namespace std;
typedef char cadena[50];
#define SALTO 4 //valor de constante usado para adaptar el tama�o de las tablas
 // din�micas, si �stas necesitan �crecer�
struct estado {
 bool activo; //en servicio si/no
 float deposito; //litros del dep�sito
 int ocupadas;
 int plazas; //capacidad
 bool itv; //itv pasada si/no
};
struct autobus
{
 cadena matricula; //formato NNNNLLL
 estado e;
 int conductor; //identificador conductor
};
class autobuses
{
autobus *elementos;
fstream fichero;
int tam; //tama�o de la tabla din�mica
int n; //n�mero de autobuses
bool cargado; //indica si el fichero est� cargado en memoria
//autobus *aux;
public:
 autobuses(); //constructor de la clase. Inicializa las variables de la clase. En
 //particular destacar que se �enlaza� ya con el fichero f�sico de
 //�autobuses.dat� para permitir poder trabajar con �l mientras no se
 //cargue en memoria
 void Insertar(autobus a);
 void Borrar (cadena mat,int pos); //borra el autob�s (se le pasa matr�cula o
 //posici�n)
 void Modificar(autobus a, cadena mat,int pos); //modifica el autob�s cuya
 // matr�cula sea mat o est� en la posici�n pos, con los datos del autobus a)
 int Buscar(cadena mat); //devuelve la posici�n del autob�s mat. � 1 si no lo
 // encuentra
 void Mostrar(cadena mat,int pos); //muestra por pantalla el autob�s (se le pasa
 // matr�cula o posici�n)
 void Listar();
 bool Cargar(); //permite cargar en memoria el fichero de autobuses denominado
 // �autobuses.dat�. Devuelve true si correcto, false si error.
 bool Guardar();//Vuelca el contenido de la tabla din�mica (si �sta existe) al
 // fichero �autobuses.dat�
 void numeroplazas();
};

#endif
