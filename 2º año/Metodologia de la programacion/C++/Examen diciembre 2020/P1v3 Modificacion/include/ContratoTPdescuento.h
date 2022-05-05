#ifndef CONTRATOTPDESCUENTO_H
#define CONTRATOTPDESCUENTO_H

#include <ContratoTP.h>
#include "Fecha.h"
#include <iostream>

class ContratoTPdescuento : public ContratoTP
{
    public:
        ContratoTPdescuento(const long int &dni,const Fecha &f,const int &minutos, const float &desc);
        ContratoTPdescuento(const ContratoTPdescuento &c);
        virtual ~ContratoTPdescuento();//no hace falta porque no tiene punteros
        float facturadescuento() const{return this->descuento*factura();}
         friend ostream& operator<<(ostream& s, ContratoTPdescuento &d);
         float getdescuento() const{return this->descuento;}
         void ver() const;
         void setdescuento(const float &descuento);
    protected:

    private:
        //1 atributo solo
        float descuento;//tomara un valor entre 0 y 1
};

ostream& operator<<(ostream& s, ContratoTPdescuento &d);

#endif // CONTRATOTPDESCUENTO_H
