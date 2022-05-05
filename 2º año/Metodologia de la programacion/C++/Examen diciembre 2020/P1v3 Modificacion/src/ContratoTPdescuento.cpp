#include "ContratoTPdescuento.h"

ContratoTPdescuento::ContratoTPdescuento(const long int &dni,const Fecha &f,const int &minutos, const float &descuento):ContratoTP(dni,f,minutos)
{
    //setdescuento(dni,f,minutos,desc);
    //ContratoTP ctp(dni,f,minutos);
    this->descuento=descuento;
}

ContratoTPdescuento::ContratoTPdescuento(const ContratoTPdescuento &c, const float &descuento): ContratoTP(c)
{
  this->descuento=descuento;

}

ContratoTPdescuento::~ContratoTPdescuento()
{
    //dtor
}

ostream& operator<<(ostream& s, ContratoTPdescuento &d)
{
    s<< d.getDniContrato() << " (" << d.getIdContrato() << " - " << d.getFechaContrato() << " " << d.getMinutosHablados() << "m, " << d.getLimiteMinutos() << "(" << d.getPrecio() << ") - " << d.factura() <<"\nDescuento aplicado: "<<d.getdescuento()<<"% Precio final: "<<d.facturadescuento()<<"e";
    return s;
}

void ContratoTPdescuento::ver() const
{
    ContratoTP::ver();
    cout << " " << this->descuento << "%,Factura original: " << factura() << "e (Fatura con descuento: " << facturadescuento() << "e)";
}

void ContratoTPdescuento::setdescuento(const float &descuento)
{
    this->descuento=descuento;
}
