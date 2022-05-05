#include "ContratoMovil.h"
#include <string.h>

ContratoMovil::ContratoMovil(long int dni, Fecha f, float precio, int minutoshab, char *nac): Contrato(dni, f)
{
    this->nacionalidad=new char [strlen(nac)+1];
    strcpy(nacionalidad, nac);
    this->preciominuto=precio;
    this->minutosHablados=minutoshab;
}

ContratoMovil::ContratoMovil(const ContratoMovil& c): Contrato(c.getDniContrato(), c.getFechaContrato())
{
    this->nacionalidad=new char [strlen(c.nacionalidad)+1];
    strcpy(nacionalidad, c.nacionalidad);
    this->preciominuto=c.preciominuto;
    this->minutosHablados=c.minutosHablados;
}

ContratoMovil::~ContratoMovil()
{
    delete [] this->nacionalidad;
}

void ContratoMovil::setNacionalidad(const char *nac)
{
    delete[] this->nacionalidad;
    nacionalidad=new char[strlen(nac)+1];
    strcpy(nacionalidad, nac);
}

void ContratoMovil::setPrecioMinuto(float precio)
{
    this->preciominuto=precio;
}

void ContratoMovil::setMinutosHablados(int minutos)
{
    this->minutosHablados=minutos;
}

float ContratoMovil::factura() const
{
    return preciominuto*minutosHablados;
}

void ContratoMovil::ver() const
{
    cout << getDniContrato() << " (" << getIdContrato() << " - ";
    if(getFechaContrato().getDia()<10)
        cout << "0";
    cout << getFechaContrato().getDia() << "/";
    if(getFechaContrato().getMes()<10)
        cout << "0";
    cout <<getFechaContrato().getMes() << "/" << getFechaContrato().getAnio() << ") " << minutosHablados << "m, " << nacionalidad << " " << preciominuto << " - " << factura() << "e";
}

ostream& operator<<(ostream& s, ContratoMovil &c)
{
    s << c.getDniContrato() << " (" << c.getIdContrato() << " - " << c.getFechaContrato() << ") " << c.minutosHablados << "m, " << c.nacionalidad << " " << c.preciominuto << " - " << c.factura() << "e";
    return s;
}
