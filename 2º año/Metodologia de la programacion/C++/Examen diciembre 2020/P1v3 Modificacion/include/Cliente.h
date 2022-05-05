#ifndef CLIENTE_H
#define CLIENTE_H

///LO MAS ROBUSTO POSIBLE= NO USAR FUNCIONES AMIGAS
///NO HAYA FALLOS DE SEGURIDAD QUE PERMITA MODIFICAR LOS ATRIBUTOS= NO USAR PARAMETROS POR REFERENCIA (T1 APARTADO 4.4 PAG 15)


//#include <iostream> //cin,cout y para ostream
#include "Fecha.h"

//using namespace std;

class Cliente{
    long int dni;
    char *nombre;
    Fecha fechaAlta;

public:
    Cliente(long int dni, char *nombre, Fecha f);
    ~Cliente();//aunque no aparezca en el main,habria que implementarlo

    void setNombre(char *nombre);
    void setFecha(Fecha f);
    long int getDni() const{ return dni; }
    const char* getNombre() const { return nombre; }//1º const----> no deja usar en el main el strcpy() al ser constante
                                //VIP devolver un puntero constante para evitar que desde el main() se puede modificar el nombre
    Fecha getFecha() const { return fechaAlta; }

    Cliente& operator=(const Cliente& c);//operador de asignacion
    bool operator==(const Cliente &c) const; //if(c1==c2)
};

ostream& operator<<(ostream& s, const Cliente &o);//hay que poner '#include <iostream>' y 'using namespace std;' para que funcione
//tambien se puede declarar asi: std::ostream&     //funcion NO amiga
//pero para declararlo asi tambien necesitamos la libreria iostream

#endif // CLIENTE_H
