#include "Contrato.h"

int Contrato::contador=1;

Contrato::Contrato(const long int &dni, const Fecha &f): idContrato(contador), fechaContrato(f)
{
    contador++;
    this->dniContrato=dni;
}

Contrato::~Contrato()
{

}

void Contrato::setFechaContrato(Fecha f)
{
    fechaContrato=f;
}

void Contrato::setDniContrato(const long int &dni)
{
    this->dniContrato=dni;
}

void Contrato::ver() const
{
    cout << dniContrato << " (" << this->idContrato << " - ";
    if(fechaContrato.getDia()<10)
        cout << "0";
    cout << fechaContrato.getDia() << "/";
    if(fechaContrato.getMes()<10)
        cout << "0";
    cout << fechaContrato.getMes() << "/" << fechaContrato.getAnio() << ")";
}

ostream& operator<<(ostream& s, Contrato &c)
{
    s << c.dniContrato << " (" << c.idContrato << " - " << c.fechaContrato << ")";

    return s;
}
