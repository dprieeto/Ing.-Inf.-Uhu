#include "ContratoTP.h"
#include "Contrato.h"

float ContratoTP::precioTP=10;
int ContratoTP::minutosTP=300;
const float ContratoTP::precioExcesoMinutos=0.15;


ContratoTP::ContratoTP(long int dni, Fecha f, int minhablados): Contrato(dni, f)
{
    this->minutosHablados=minhablados;
}

ContratoTP::ContratoTP(const ContratoTP &c): Contrato(c.getDniContrato(), c.getFechaContrato()) //No es necesario
{
    this->minutosHablados = c.minutosHablados;
}

ContratoTP::~ContratoTP()
{
    //dtor
}

void ContratoTP::setTarifaPlana(int limiteMinutos, float precio)
{
    ContratoTP::minutosTP=limiteMinutos; //No hace falta el ContratoTP::
    ContratoTP::precioTP=precio;         //asi recordamos que es estático (static)
}

void ContratoTP::setMinutosHablados(int minutosHablados)
{
    this->minutosHablados=minutosHablados;
}

float ContratoTP::factura() const
{
    int minutos=0;
    if(minutosHablados>minutosTP)
        minutos=minutosHablados-minutosTP;
    return (precioTP+minutos*precioExcesoMinutos);
}

void ContratoTP::ver() const
{
    Contrato::ver();
    cout << " " << this->minutosHablados << "m, " << ContratoTP::minutosTP << "(" << ContratoTP::precioTP << ")";
}

ostream& operator<<(ostream& s, ContratoTP &tp)
{
    s<< tp.getDniContrato() << " (" << tp.getIdContrato() << " - " << tp.getFechaContrato() << " " << tp.minutosHablados << "m, " << ContratoTP::minutosTP << "(" << ContratoTP::precioTP << ") - " << tp.factura() <<"e";
    return s;
}
