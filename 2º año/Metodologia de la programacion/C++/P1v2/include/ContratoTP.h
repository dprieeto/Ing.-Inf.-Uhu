#ifndef CONTRATOTP_H
#define CONTRATOTP_H
#include "Fecha.h"
#include "Contrato.h"


class ContratoTP : public Contrato
{
    static float precioTP;
    static int minutosTP;
    int minutosHablados;
    static const float precioExcesoMinutos;
public:
    ContratoTP(long int dni, Fecha f, int minhablados);
    ContratoTP(const ContratoTP &c); //Constructor de copia. No es necesario, funciona bien el que crea el compilador
    //porque no tiene punteros
    virtual ~ContratoTP();
    //int getIdContrato(); NO hace falta viene del "padre"
    int getMinutosHablados() const { return minutosHablados; }
    static int getLimiteMinutos() { return ContratoTP::minutosTP; } //NO hace falta el ContratoTP::
    static int getPrecio() { return ContratoTP::precioTP; }
    static void setTarifaPlana(int limiteMinutos, float precio);
    void setMinutosHablados(int minutosHablados);
    float factura() const;
    void ver() const;
    friend ostream& operator<<(ostream& s, ContratoTP &tp);
};

ostream& operator<<(ostream& s, const ContratoTP &o);

#endif // CONTRATOTP_H
