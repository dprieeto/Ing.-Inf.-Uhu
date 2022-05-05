/*
 * La clase TestBusqueda contiene los metodos para:
 * 1. Comprobar que los métodos de búsqueda de la clase AlgoritmosBusqueda funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un método de búsqueda,
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente con ajuste al Orden de complejidad.
 * 3. Comparar el coste temporal de dos métodos de búsqueda
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente.
 * 4. Comparar todos los algoritmos de búsqueda implementados.
 */
#include "TestBusqueda.h"
#include "AlgoritmosBusqueda.h"
//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
#include "AlgoritmosOrdenacion.h"
#include "TestOrdenacion.h"
#include "ConjuntoInt.h"
#include "Graficas.h"
#include "Mtime.h"
#include "Constantes.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;


TestBusqueda::TestBusqueda()
{
    nombreAlgoritmo.push_back("SecuencialIt");
	nombreAlgoritmo.push_back("BinariaIt");
	nombreAlgoritmo.push_back("InterpolacionIt");
}
TestBusqueda::~TestBusqueda()
{
}

double TestBusqueda::buscaEnArrayDeInt(int v[],int size,int metodo,int key,int &pos)
{
	AlgoritmosBusqueda estrategia;
	Mtime t;
	LARGE_INTEGER t_inicial, t_final;
	QueryPerformanceCounter(&t_inicial);
	/* Invoca al método de busqueda elegido */
	switch (metodo){
		case SECUENCIALIT: pos=estrategia.busquedaSecuencialIt(v, size,key);
                           //estrategia.busquedaSecuencialIt(v,size,key);
			break;
		case BINARIAIT: pos=estrategia.busquedaBinariaIt(v, size,key);
                        //estrategia.busquedaBinariaIt(v,size,key);
			break;
		case INTERPOLACIONIT: pos=estrategia.busquedaInterpolacionIt(v, size,key);
                                //estrategia.busquedaSecuencialIt(v,size,key);
			break;
	}
	QueryPerformanceCounter(&t_final);
	return t.performancecounter_diff(&t_final, &t_inicial) * 1000;
}

void TestBusqueda::comprobarMetodosBusqueda()
{
    int talla,key,pos;
	cout<<"\t\t **** COMPROBACION DE LOS METODOS DE BUSQUEDA ***\n\n";
	cout<</*endl<<endl<<*/"Introduce la talla: ";
	cin>>talla;
    AlgoritmosOrdenacion o;
	//system("cls");
	for (int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++)
	{
		ConjuntoInt *v= new ConjuntoInt(talla);
		v->GeneraVector(talla);
		cout <<endl<<endl<< "vector inicial para el metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
		o.ordenaInsercion(v->getDatos(),talla);
		v->escribe();
		cout<<"\tIntroduce la clave a buscar: ";
        cin>>key;
        double secs=buscaEnArrayDeInt(v->getDatos(),talla,metodo,key,pos);
        cout<<endl<<endl<<"->   posicion de "<<key<<" buscado con el metodo "<<nombreAlgoritmo[metodo]<<": "<<pos<<endl;
		cout<<endl;
		v->vaciar();
		system("pause");
		//system("cls");
	}
	system("cls");
}

void TestBusqueda::casoMedio(int metodo)
{
    //** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
	 ofstream f((nombreAlgoritmo[metodo]+".dat").c_str());
    system("cls");
    cout<<endl<<"***Ordenacion por " << nombreAlgoritmo[metodo]+" ***"<<endl<<endl;
    cout<<"Tiempos de ejecucion promedio "<<endl<<endl;
    cout<<"\tTalla\t\tTiempo (mseg)"<<endl<<endl;
    double tiempo=0;
    int pos,key;
    //int key;
    double secs=0;
    ConjuntoInt *v;
    AlgoritmosOrdenacion o;
    Graficas g;

		for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
		{
		    v=new ConjuntoInt(talla);
            v->GeneraVector(talla);
                    for(int r=0;r<NUMREPETICIONES;r++)
                    {
                        v=new ConjuntoInt(talla);
                        v->GeneraVector(talla);
                        o.ordenaInsercion(v->getDatos(),talla);
                        key=v->generakey();
                        /*double*/ secs=buscaEnArrayDeInt(v->getDatos(),talla,metodo,key,pos);
                        tiempo = tiempo+secs;
                        delete v;
                    }
                    tiempo=tiempo/NUMREPETICIONES;
			f<<talla<<"\t"<< tiempo<<endl;
			cout<<"\t"<<talla<<"\t\t"<<setw(10)<<setprecision(2)<<(double)tiempo<<" \t\t"<<endl;
		}
		f.close();
		cout <<endl<<"Datos guardados en el fichero "<<nombreAlgoritmo[metodo]<<".dat "<<endl;

		/* Generar grafica */
		char opc;
		cout<<endl<<"Generar grafica de resultados? (s/n): ";
		cin>>opc;
		switch (opc){
		case 's':
		case 'S':{
			switch (metodo){
			case SECUENCIALIT:{
				/* Ejecutar el fichero por lotes (comandos)*/
				g.generarGraficaMEDIO(nombreAlgoritmo[metodo],N);
				system("SecuencialIt.gpl"); system("cls");
				cout <<endl<<"Grafica guardada en el fichero "<<nombreAlgoritmo[metodo]+".pdf"<<endl;
													 }break;
			case BINARIAIT:{
				/* Ejecutar el fichero por lotes (comandos)*/
				g.generarGraficaMEDIO(nombreAlgoritmo[metodo],LOGN);
				system("BinariaIt.gpl"); system("cls");
				cout <<endl<<"Grafica guardada en el fichero "<<nombreAlgoritmo[metodo]<<".pdf"<<endl;
													}break;
			case INTERPOLACIONIT:{
				/* Ejecutar el fichero por lotes (comandos)*/
				g.generarGraficaMEDIO(nombreAlgoritmo[metodo],LOGN);
				system("InterpolacionIt.gpl");
				system("cls");
				//system((gpl).c_str());
				cout <<endl<<"Grafica guardada en el fichero "<<nombreAlgoritmo[metodo]<<".pdf"<<endl;
													 }break;
			default: {cout <<"Error caso "<<endl;}break;
			}break;
		}
		default: {cout <<"Grafica no guardada en fichero "<<endl;
						 }break;

		}
		cout<<endl;
		system("pause");
		system("cls");
}

void TestBusqueda::comparar(int metodo1, int metodo2)
{
	//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
	ofstream f((nombreAlgoritmo[metodo1] + ".dat").c_str());
	ofstream f1((nombreAlgoritmo[metodo2] + ".dat").c_str());
	system("cls");
	cout << endl << "Busqueda " << nombreAlgoritmo[metodo1] << " y " << nombreAlgoritmo[metodo2];
	cout << ". Tiempos de ejecucion promedio " << endl << endl;
	cout << "\t        \t" << nombreAlgoritmo[metodo1] << "\t\t" << nombreAlgoritmo[metodo2] << endl;
	cout << "\tTalla(n)\tTiempo<mseg>\tTiempo<mseg>" << endl << endl;

	double tiempoMetodo1 = 0, tiempoMetodo2 = 0;
	int pos;
	AlgoritmosOrdenacion o;
	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
	{
		ConjuntoInt *v = new ConjuntoInt(talla);
		double secs = 0;
		int key;

		for (int i = 0; i < NUMREPETICIONES; i++)
		{
			v->GeneraVector(talla);
			key = v->generakey();
			o.ordenaInsercion(v->getDatos(), talla);
			secs = buscaEnArrayDeInt(v->getDatos(), talla, metodo1, key, pos);
			tiempoMetodo1 = tiempoMetodo1 + secs;
		}

		tiempoMetodo1 = tiempoMetodo1 / NUMREPETICIONES;


		for (int i = 0; i < NUMREPETICIONES; i++)
		{
			v->GeneraVector(talla);
			key = v->generakey();
			o.ordenaInsercion(v->getDatos(), talla);
			secs = buscaEnArrayDeInt(v->getDatos(), talla, metodo2, key, pos);
			tiempoMetodo2 = tiempoMetodo2 + secs;
		}

		tiempoMetodo2 = tiempoMetodo2 / NUMREPETICIONES;


		/*escribir en el fichero*/
		f << talla << "\t" << tiempoMetodo1 << endl;
		f1 << talla << "\t" << tiempoMetodo2 << endl;
		/*Visualizar en pantalla*/
		cout << "\t" << talla << "\t\t" << setw(10) << setprecision(2) << (double)tiempoMetodo1 << " \t" << setw(10) << setprecision(2) << (double)tiempoMetodo2 << endl;
		cout << endl;

		v->vaciar();
		delete v;
	}
	f.close();
	f1.close();
	cout << endl << "Grafica guardada en el fichero " << nombreAlgoritmo[metodo1] << ".dat y " << nombreAlgoritmo[metodo2] << ".dat" << endl;
	/* Generar grafica */
	char opc;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;
	switch (opc) {
	case 's':
	case 'S': {
		/* Ejecutar el fichero por lotes (comandos)*/
		Graficas c;
		c.generarGraficaCMP(nombreAlgoritmo[metodo1], nombreAlgoritmo[metodo2]);
		system("CmdComparar.gpl"); system("cls");
		//system((gpl).c_str());
		cout << endl << "Grafica guardada en el fichero " << nombreAlgoritmo[metodo1] + nombreAlgoritmo[metodo2] << ".pdf" << endl;
	}break;
	default: {cout << "Grafica no guardada en fichero " << endl;
	}break;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void TestBusqueda::comparartodos()
{
	//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
	ofstream f((nombreAlgoritmo[SECUENCIALIT] + ".dat").c_str());
	ofstream f1((nombreAlgoritmo[BINARIAIT] + ".dat").c_str());
	ofstream f2((nombreAlgoritmo[INTERPOLACIONIT] + ".dat").c_str());
	system("cls");
	cout << endl << "Busqueda " << nombreAlgoritmo[SECUENCIALIT] << " , " << nombreAlgoritmo[BINARIAIT] << " y " << nombreAlgoritmo[INTERPOLACIONIT];
	cout << ". Tiempos de ejecucion promedio " << endl << endl;
	cout << "\t        \t" << nombreAlgoritmo[SECUENCIALIT] << "\t" << nombreAlgoritmo[BINARIAIT] << "\t" << nombreAlgoritmo[INTERPOLACIONIT] << endl;
	cout << "\tTalla(n)\tTiempo<mseg>\tTiempo<mseg>\tTiempo<mseg>\tTiempo<mseg>" << endl << endl;
	double tiempoMetodo1 = 0, tiempoMetodo2 = 0, tiempoMetodo3 = 0;
	int pos;
	AlgoritmosOrdenacion o;

		for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
		{
			ConjuntoInt *v = new ConjuntoInt(talla);
			double secs = 0;
			int key;

			for (int i = 0; i < NUMREPETICIONES; i++)
			{
				v->GeneraVector(talla);
				key = v->generakey();
				o.ordenaInsercion(v->getDatos(), talla);
				secs = buscaEnArrayDeInt(v->getDatos(), talla, key, SECUENCIALIT, pos);
				tiempoMetodo1 = tiempoMetodo1 + secs;
			}

			tiempoMetodo1 = tiempoMetodo1 / NUMREPETICIONES;


			for (int i = 0; i < NUMREPETICIONES; i++)
			{
				v->GeneraVector(talla);
				key = v->generakey();
				o.ordenaInsercion(v->getDatos(), talla);
				secs = buscaEnArrayDeInt(v->getDatos(), talla, key, BINARIAIT, pos);
				tiempoMetodo2 = tiempoMetodo2 + secs;
			}

			tiempoMetodo2 = tiempoMetodo2 / NUMREPETICIONES;

			for (int i = 0; i < NUMREPETICIONES; i++)
			{
				v->GeneraVector(talla);
				key = v->generakey();
				o.ordenaInsercion(v->getDatos(), talla);
				secs = buscaEnArrayDeInt(v->getDatos(), talla, key, INTERPOLACIONIT, pos);
				tiempoMetodo3 = tiempoMetodo3 + secs;
			}

			tiempoMetodo3 = tiempoMetodo3 / NUMREPETICIONES;

			cout << "\t" << talla << "\t\t" << setw(10) << setprecision(2) << (double)tiempoMetodo1 << " \t" << setw(10) << setprecision(2) << (double)tiempoMetodo2 << " \t" << setw(10) << setprecision(2) << (double)tiempoMetodo3 <<endl;
			cout << endl;

			v->vaciar();
			delete v;
		}
	f.close();
	f1.close();
	f2.close();
	/* Generar grafica */
	char opc;
	cout << endl << "Generar grafica de resultados? (s/n): ";
	cin >> opc;
	switch (opc) {
	case 's':
	case 'S': {
		/* Ejecutar el fichero por lotes (comandos)*/
		Graficas c;
		c.generartodoslocasos(nombreAlgoritmo[SECUENCIALIT], nombreAlgoritmo[BINARIAIT], nombreAlgoritmo[INTERPOLACIONIT]);
		system("CmdCompararTODOS.gpl");
		system("cls");
		cout << endl << "Grafica guardada en el fichero " << nombreAlgoritmo[SECUENCIALIT] + nombreAlgoritmo[BINARIAIT] + nombreAlgoritmo[INTERPOLACIONIT] << ".pdf" << endl;
	}break;
	default: {cout << "Grafica no guardada en fichero " << endl;
	}break;
	}
	cout << endl;
	system("pause");
	system("cls");
}
