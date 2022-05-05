#ifndef EMPRESA_H
#define EMPRESA_H


#include "Fecha.h" //definicion clase Fecha
#include "Cliente.h" // definicion clase Cliente
#include "Contrato.h" // definicion de la clase Contrato
#include "ContratoTP.h" // definicion de la clase ContratoTP
#include "ContratoMovil.h" // definicion de la clase ContratoMovil

using namespace std;

class Empresa{
public: // son visibles y pueden ser usados en cualquier ámbito.
    Empresa();
    virtual ~Empresa();

    void crearContrato();
    bool cancelarContrato(int idContrato);
    bool bajaCliente(long int dni);

    void cargarDatos();
    void ver() const;

    int nContratosTP() const; //Devuelve el numero de contratos TP --- typeid
    int descuento(float porcentaje) const; // --- dynamic_cast<>

protected: //Son visibles y pueden ser usados por los métodos de la clase y sus clases derivadas únicamente.
    int buscarCliente(long int dni); //Si no existe, devuelve -1
    int altaCliente(Cliente *c); //Si no hay hueco, devuelve -1
    int altaContrato(Contrato *c);

private: // solo son visibles y pueden ser usados por los métodos de la clase.
    Cliente *clientes[100];
    int ncli;
    const int nmaxcli;
    Contrato **contratos;
    int ncon;
    int nmaxcon;
};

#endif // EMPRESA_H
