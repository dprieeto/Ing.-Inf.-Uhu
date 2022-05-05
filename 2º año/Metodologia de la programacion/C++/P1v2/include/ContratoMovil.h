#ifndef CONTRATOMOVIL_H
#define CONTRATOMOVIL_H
#include "Fecha.h"
#include <Contrato.h>


class ContratoMovil : public Contrato //asi se declara una clase heredada:  'class clase_herencia:public class clase_padre'
{                                     //una clase heredada puede accerder a atributos protegidos y publicos de la clase padre
    int minutosHablados;
    float preciominuto;
    char* nacionalidad;
public:
    ContratoMovil(long int dni, Fecha f, float precio, int minutoshab, char *nac);
    ContratoMovil(const ContratoMovil& c); //Necesario constructor de copia
    virtual ~ContratoMovil();
    //int getIdContrato() const { return idContrato; }
    int getMinutosHablados() const { return this->minutosHablados; }
    char* getNacionalidad() const { return this->nacionalidad; }
    float getPrecioMinuto() const { return this->preciominuto; }
    //void setFechaContrato(Fecha f); //NO hace falta, coge la de CONTRATO
    void setNacionalidad(const char *nac);
    void setPrecioMinuto(float precio);
    void setMinutosHablados(int minutos);
    float factura() const;
    void ver() const;
    friend ostream& operator<<(ostream& s, ContratoMovil &c);
};

#endif // CONTRATOMOVIL_H
