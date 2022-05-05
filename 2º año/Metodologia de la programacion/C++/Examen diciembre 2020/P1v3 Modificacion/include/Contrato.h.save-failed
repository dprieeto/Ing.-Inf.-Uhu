#ifndef CONTRATO_H
#define CONTRATO_H
#include "Fecha.h"
#include <iostream>

using namespace std;

class Contrato
{
    public:
        Contrato(const long int &dni, const Fecha &f); //No hace falta constructor de copia porq el que se hace por defecto funciona bien
                                                        //al no tener punteros.
        virtual ~Contrato();//No hace falta porque no hay que liberar nada,se puede dejar o se puede quitar

        int getIdContrato() const { return idContrato; }
        Fecha getFechaContrato() const { return this->fechaContrato; }
        long int getDniContrato() const { return this->dniContrato; }

        void setDniContrato(const long int &dni);
        void setFechaContrato(Fecha f);
        virtual void ver() const; //polimorfico
        //virtual float factura() const = 0; //virtual puro -> clase abstracta

        friend ostream& operator<<(ostream& s, Contrato &c);


    protected:

    private:
        static int contador;//Los atributos estaticos se inicialzian fuera del constructor, por ejempl en el '.cpp'
                                //Es único por contrato, entonces si no es static,
                               //cada objeto crea un idContrato empezando de 0(si asi se indica en el constructor)
                               //al ser static es un atributo comun para todos los objetos. si se crea un objeto es un contrato,
                               //si se crea otro objeto ya son dos contratos, etc.
        const int idContrato; //No se puede modifical despues, debe ser const.
        long int dniContrato;
        Fecha fechaContrato;

};

ostream& operator<<(ostream& s, Contrato &c);

#endif // CONTRATO_H
