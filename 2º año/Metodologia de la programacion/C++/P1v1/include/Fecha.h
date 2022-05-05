#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;

class Fecha{
    int dia,mes,anio;
    //int mes;
    //int anio;
public:
    Fecha(const int &dia, const int &mes, const int &anio);

    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAnio() const { return anio; }

    bool bisiesto() const;
    void setFecha(const int &dia, const int &mes, const int &anio);
    void ver() const;

    Fecha operator++();
    Fecha operator++(int i);
    Fecha operator+(int a) const;


    friend Fecha operator+(const int &a, const Fecha &f);
    friend ostream& operator<<(ostream& s, const Fecha &o);
};


Fecha operator+(const int &a, const Fecha &f);

ostream& operator<<(ostream& s, const Fecha &o);


#endif // FECHA_H
