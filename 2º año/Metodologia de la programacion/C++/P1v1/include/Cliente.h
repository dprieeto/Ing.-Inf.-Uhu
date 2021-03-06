#ifndef CLIENTE_H
#define CLIENTE_H
//#include <iostream>
#include "Fecha.h"

//using namespace std;

class Cliente{
    long int dni;
    char *nombre;
    Fecha fechaAlta;

public:
    Cliente(long int dni, char *nombre, Fecha f);
    ~Cliente();

    void setNombre(char *nombre);
    void setFecha(Fecha f);
    long int getDni() const{ return dni; }
    const char* getNombre() const { return nombre; }
    Fecha getFecha() const { return fechaAlta; }

    Cliente& operator=(const Cliente& c);
    bool operator==(const Cliente &c) const;
};

ostream& operator<<(ostream& s, const Cliente &o);

#endif // CLIENTE_H
