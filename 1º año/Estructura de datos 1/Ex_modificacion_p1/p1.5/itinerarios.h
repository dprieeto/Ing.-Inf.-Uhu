#ifndef ITINERARIOS_H
#define ITINERARIOS_H
#include "autobuses.h"

using namespace std;

struct Hora {
 int h;
 int m;
 bool am;
};
struct itinerario
{
 cadena nombre;
 cadena origen;
 cadena destino;
 Hora inicio;
 Hora fin;
 cadena matricula;
};
class itinerarios
{
itinerario *elementos;
fstream fichero;
int tam; //tama�o de la tabla din�mica
int n; //n�mero de autobuses
bool cargado; //indica si el fichero est� cargado en memoria
public:
 itinerarios(); //constructor de la clase;
 void Insertar(itinerario i);
 void Borrar (cadena nombrei,cadena mat,int pos); //borra el itinerario (se le
 // pasa nombre itinerario y matricula o bien posici�n)
 void Modificar(itinerario a, cadena nombrei, cadena mat,int pos); //modifica el
 // itinerario cuyo nombre de itinerario sea nombrei y matr�cula sea mat o
 // bien est� en la posici�n pos, con los datos del itinerario i)
 int Buscar(cadena nombrei,cadena mat); //devuelve la posici�n del itinerario de
 //nombre nombrei y matricula mat. � 1 si no lo encuentra
 void Mostrar(cadena nombrei, cadena mat,int pos); //muestra por pantalla el
 // itinerario de nombre nombrei y matricula mat o bien de posici�n pos)
 void Listar();
 bool Cargar(); //permite cargar en memoria el fichero de itinerarios denominado
 // �itinerarios.dat�. Devuelve true si correcto, false si error.
 bool Guardar();//Vuelca el contenido de la tabla din�mica (si �sta existe) al
 // fichero �itinerarios.dat�
 void itinerariosenintervalo(Hora horaini, Hora horafin);
 void numerobuses(cadena origen);
};

#endif
