#include <cstdlib>
#include <iostream>
#include <iomanip> //std::setprecision
#include "Fecha.h" //definicion clase Fecha
#include "Cliente.h" // definicion clase Cliente
#include "Contrato.h" // definicion de la clase Contrato
#include "ContratoTP.h" // definicion de la clase ContratoTP
#include "ContratoMovil.h" // definicion de la clase ContratoMovil
#include "Empresa.h" // definicion de la clase Empresa
#include "ContratoTPdescuento.h"
using namespace std;
int main(int argc, char *argv[])
{
    ///PRCTICA 1V3
    /*
 bool ok;
 Empresa Yoigo;

 cout << setprecision(2) << fixed; //a partir de aqui float se muestra con 2 decimales
 cout << endl << "APLICACION DE GESTION TELEFONICA\n" << endl;
 Yoigo.cargarDatos(); //crea 3 clientes y 7 contratos. metodo creado para no
 Yoigo.ver(); //tener que meter datos cada vez que pruebo el programa
 cout <<"Yoigo tiene " << Yoigo.nContratosTP() << " Contratos de Tarifa Plana\n\n";

 Yoigo.crearContrato(); //ContratoMovil a 37000017 el 01/01/2017 con 100m a 0.25
 Yoigo.crearContrato(); //ContratoTP a 22330014 (pepe luis) el 2/2/2017 con 305m

 ok=Yoigo.cancelarContrato(28); //este Contrato no existe
 if (ok) cout << "Contrato 28 cancelado\n"; else cout << "El Contrato 28 no existe\n";

 ok=Yoigo.cancelarContrato(4); //este Contrato si existe
 if (ok)
 cout << "El Contrato 4 ha sido cancelado\n";
 else
 cout << "El Contrato 4 no existe\n";

 ok=Yoigo.bajaCliente(75547001); //debe eliminar el cliente y sus 3 Contratos
 if (ok) cout << "El cliente 75547001 y sus Contratos han sido cancelados\n";
 else cout << "El cliente 75547001 no existe\n";
 Yoigo.ver();

 Yoigo.descuento(20);
 cout << "\nTras rebajar un 20% la tarifa de los ContratosMovil...";
 Yoigo.ver();
 cout <<"Yoigo tiene " << Yoigo. nContratosTP () << " Contratos de Tarifa Plana\n";
 */
 ///MODIFICACION EXAMEN EJERCICIO 1D)

    ///*
    Fecha f1(29,2,2001), f2(f1), f3(29,2,2004);
    ContratoTP ct1(17333256, f1, 250); //habla 250 minutos
    ContratoTP ct2(12555100, f3, 320); //habla 320 minutos
    ContratoTPdescuento ctd1(17333256, f1, 250, 0.25); //descuento del 25%
    ContratoTPdescuento ctd2(ctd1, 0.40); //descuento del 40%

    //*/
 system("PAUSE");
 return 0;
}
