#include <iostream>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include "Empleado.h"
#include "EmpleadoH.h"
#include "Empresa.h"
#include "EmpleadoV.h"

using namespace std;



int main(int argc, char *argv[]) {
  EmpleadoH a("luis", 900, 20), b("juan", 950, 5);
  const EmpleadoV c("ana", 800, 15000); //sueldo minimo es 900
  a.ver(); cout << endl;
  b.ver(); cout << endl;
  c.ver(); cout << endl;
  cout << "---\n";

  Empresa SEAT;
  SEAT.ver(); //hay 0 empleados
  cout << "---\n";
  SEAT.contratar(); SEAT.contratar(); //juan 920 H 10, pepe 870 V 10000
  SEAT.contratar(); SEAT.contratar(); //pepe 950 H 20, ana 900 H 40
  SEAT.ver(); //hay 4 empleados
  cout << "---\n";
  SEAT.eliminarH(); //elimina 3 empleadoH
  SEAT.ver(); //hay 1 empleado
  cout << "---\n";
  SEAT.eliminarH(); //elimina 0 empleadoH
  system("PAUSE");  return EXIT_SUCCESS;
}




