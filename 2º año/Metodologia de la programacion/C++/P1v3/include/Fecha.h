#ifndef FECHA_H
#define FECHA_H

///SI EL ENUNCIADO PIDE QUE SE EJECUTE LO MAS RAPIDO POSIBLE HABRIA QUE HACER:
///usar const con todo y pasar por referencia todo lo que se pueda

#include <iostream>

using namespace std;

class Fecha{
    //3 atributos
    int dia,mes,anio;
public:
    //Fecha(); //no hace falta el constructor copia porque la clase no usa  memoria dinamica
    Fecha(const int &dia, const int &mes, const int &anio);
    //virtual ~Fecha(); //no hay ningun puntero por lo que no hace falta
    int getDia() const { return dia; } //por get se refiere a devolver
    int getMes() const { return mes; }
    int getAnio() const { return anio; }

    bool bisiesto() const;
    void setFecha(const int &dia, const int &mes, const int &anio);
    void ver() const;

    Fecha operator++(); // ++f
    Fecha operator++(int i);// f++ //si pongo &i da error
    Fecha operator+(int a) const; //f+5 //si pongo &i da error


    friend Fecha operator+(const int &a, const Fecha &f);
    friend ostream& operator<<(ostream& s, const Fecha &o);
};


Fecha operator+(const int &a, const Fecha &f);//funcion amiga, en la clase se escribe la misma funcion con 'friend' antes

ostream& operator<<(ostream& s, const Fecha &o);//funcion amiga


#endif // FECHA_H
