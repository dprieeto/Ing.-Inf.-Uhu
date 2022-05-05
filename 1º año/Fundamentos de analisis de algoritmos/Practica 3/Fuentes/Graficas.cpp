/*
 * Clase Graficas, contiene métodos para guardar las gráficas de los resultados, es decir, crea
 * los ficheros por lo lotes (comandos) para generar los ficheros gráficos que corresponda.
 */
#include "Graficas.h"
#include "Constantes.h"
#include <fstream>
#include <iostream>
using namespace std;

 /*
  * Método generarGraficaMEDIO, genera el fichero de comandos para GNUPlot y dibuja la gráfica
  * del caso medio de un método de ordenación y su ajuste a la función correspondiente.
  * param metodo: metodo de ordenacion.
  * param orden: Orden del metodo de ordenacion.
  */
void Graficas::generarGraficaMEDIO(string nombre_metodo,int orden)
{
//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
    ofstream f((nombre_metodo+".gpl").c_str());
	f << "#ESTE ES UN SCRIPT DE GNUPLOT PARA ESTUDIO DE 1 METODO " << endl;
	f << "set title \"" << nombre_metodo << "\"" << endl;
	f << "set key top left vertical inside" << endl;
	f << "set grid" << endl;
	f << "set xlabel \"Talla (n)\"" << endl;
	f << "set ylabel \"Tiempo (ms)\"" << endl;
	f << "plot \"" << nombre_metodo + ".dat" << "\" using 1:2" << "with lines title\"" << nombre_metodo << "\"" << endl;
	if (orden == CUADRADO)
	{
		f << "Cuadrado(x) = a*x^2 + b*x + c" << endl;
		f << "fit Cuadrado(x) \"" << nombre_metodo + ".dat\" using 1:2 via a,b,c" << endl;
		f << "plot " << "\"" << nombre_metodo + ".dat\"" << " using 1:2 title " << "\"" << nombre_metodo << "\"," << " Cuadrado(x)" << endl;
	}
	else if(orden == NlogN)
	{
		f << "Nlog(x) = a*x*log(x) + b*x + c" << endl;
		f << "fit Nlog(x) \"" << nombre_metodo + ".dat\" using 1:2 via a,b,c" << endl;
		f << "plot " << "\"" << nombre_metodo + ".dat\"" << " using 1:2 title " << "\"" << nombre_metodo + ".dat\"," << " NlogN(x)" << endl;
	}
	else if (orden == N)
	{		f << "N(x) = a*x + b" << endl;
		f << "fit N(x) " << "\"" << nombre_metodo + ".dat\"" << " using 1:2 via a, b" << endl;
		f << "plot " << "\"" << nombre_metodo + ".dat\"" << " using 1:2 title " << "\"" << nombre_metodo << "\"," << " N(x)" << endl;
	}
	else if (orden == LOGN)
	{
		f << "logN(x) = a*log(x)+b" << endl;
		f << "fit logN(x) " << "\"" << nombre_metodo + ".dat\"" << " using 1:2 via a,b" << endl;
		f << "plot " << "\"" << nombre_metodo + ".dat\"" << " using 1:2 title " << "\"" << nombre_metodo + ".dat\"," << " logN(x)" << endl;
	}
	//f << "fit N(x) \"" << nombre_metodo+".dat\" using 1:2 via a,b" << endl;
	//f << "plot \"" << nombre_metodo + ".dat" << "\" using 1:2  title \"" << nombre_metodo << "\",Cuadrado(x)" << endl;
	f << "set terminal pdf" << endl;
	f << "set output \"" << nombre_metodo+".pdf\"" << endl;
	f << "replot" << endl;
	f << "pause 5 \"Pulsa Enter para continuar...\"" << endl;
	f.close();
}

/*
 * Método generarGraficaCMP, genera el fichero de comandos para GNUPlot.
 * param nombre1: es el nombre del fichero de datos del primer método de ordenación
 * param nombre2: es el nombre del fichero de datos del segundo método de ordenación
 */
void  Graficas::generarGraficaCMP(string nombre1,string nombre2)
{
//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
    ofstream f("CmdComparar.gpl");
    f<<"#ESTE ES UN SCRIPT DE GNUPLOT PARA LA COMPARACION DE DOS METODOS"<<endl;
    f<<"set title \"Comparacion tiempos "<<nombre1<<" y "<<nombre2<<"\""<<endl;
    f<<"set key top left vertical inside"<<endl;
    f<<"set grid"<<endl;
    f<<"set xlabel \"Talla (n)\""<<endl;
    f<<"set ylabel \"Tiempo (ms)\""<<endl;
    //f<<"set xrange [100:1000]"<<endl;
    //f<<"set yrange [0:0.000002]"<<endl;
    f<<"plot \""<<nombre1+".dat"<<"\" using 1:2 with lines title\""<<nombre1<<"\",\""<<nombre2+".dat"<<"\" using 1:2 with lines title\""<<nombre2<<"\""<<endl;
         //"SecuencialPeorSecuencialMedioSecuencialMejorEmpirico.dat" using 1:4 with lines title"SecMejorEmpirico"
    f<<"set terminal pdf"<<endl;
    f<<"set output \""<<nombre1+nombre2+".pdf"<<"\""<<endl;
    f<<"replot"<<endl;
    f<<"pause 5 \"Pulsa Enter para continuar...\""<<endl;
}

void Graficas::generartodoslocasos(string metodo1,string metodo2,string metodo3)
{
	ofstream f("CmdCompararTODOS.gpl");
	f << "set title \"Comparacion " << metodo1 << "," << metodo2 << " , " << metodo3 << "\"" << endl;
	f << "set key top left vertical inside" << endl;
	f << "set grid" << endl;
	f << "set xlabel \"Talla (n)\"" << endl;
	f << "set ylabel \"Tiempo (ms)\"" << endl;
	f << "plot \"" << metodo1 << ".dat\" using 1:2 with lines title \"" << metodo1 << "\", \"" << metodo2 << ".dat\" using 1:2 with lines title \"" << metodo2 << "\", \"" << metodo3 << ".dat\" using 1:2 with lines title \"" << metodo3 << "\"" <<endl;// "\", \"" << metodo4 << ".dat\" using 1:2 with lines title \"" << metodo4 << "\"" << endl;
	f << "set terminal pdf" << endl;
	f << "set output \"" << metodo1 + metodo2 + metodo3 << ".pdf\"" << endl;
	f << "replot" << endl;
	f << "pause -1" << "\"" << "Pulsa Enter para continuar..." << "\"" << endl;
	f.close();
}
