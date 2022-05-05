/*
 * La clase TestOrdenacion contiene los metodos para:
 * 1. Comprobar que los m�todos de ordenacion de la clase Ordenacion funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un m�todo de ordenaci�n,
 *    guardando los datos y permitiendo imprimir la gr�fica correspondiente
 * 3. Comparar el coste temporal de dos de los m�todos de ordenaci�n
 *    burbuja, inserci�n, y selecci�n, guardando los datos y permitiendo imprimir la gr�fica correspondiente.
 */
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


TestOrdenacion::TestOrdenacion()
{
	nombreAlgoritmo.push_back("Burbuja");
	nombreAlgoritmo.push_back("Insercion");
	nombreAlgoritmo.push_back("Seleccion");
	nombreAlgoritmo.push_back("Quicksort");
}
TestOrdenacion::~TestOrdenacion(){}

/*
 * Ordena un array de enteros seg�n el m�todo indicado
 * param v: el array de enteros a ordenar
 * param size: tama�o del array de enteros a ordenar
 * param metodo: Metodo de ordenacion a utilizar
 * return Tiempo empleado en la ordenaci�n (en milisegundos)
 */
double TestOrdenacion::ordenarArrayDeInt(int v[],int size,int metodo)
{
	AlgoritmosOrdenacion estrategia;
	Mtime t;
	LARGE_INTEGER t_inicial, t_final;
	QueryPerformanceCounter(&t_inicial);
	/* Invoca al m�todo de ordenaci�n elegido */
	switch (metodo){
		case BURBUJA: estrategia.ordenaBurbuja(v, size);
			break;
		case INSERCION: estrategia.ordenaInsercion(v, size);
			break;
		case SELECCION: estrategia.ordenaSeleccion(v, size);
			break;
        case QUICKSORT: estrategia.ordenaQuickSort(v, size);
			break;
	}
	QueryPerformanceCounter(&t_final);
	return t.performancecounter_diff(&t_final, &t_inicial) * 1000;
}

/*
 * Comprueba los metodos de ordenacion
 */
void TestOrdenacion::comprobarMetodosOrdenacion()
{
	int talla;
	cout<<endl<<endl<<"Introduce la talla: ";
	cin>>talla;
	system("cls");
	for (int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++)
	{
		ConjuntoInt *v= new ConjuntoInt(talla);
		v->GeneraVector(talla);
		cout <<endl<<endl<< "vector inicial para el metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
		v->escribe();
        double secs=ordenarArrayDeInt(v->getDatos(),talla,metodo);
		cout<<endl<<endl<<"Array ordenado con metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
		v->escribe();
		cout<<endl;
		v->vaciar();
		system("pause");
		system("cls");
	}
	system("cls");
}

/*
 * Calcula el caso medio de un metodo de ordenacion.
 * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
 * param metodo: metodo de ordenacion a estudiar.
 */
void TestOrdenacion::casoMedio(int metodo)
{
	 //** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
	 ofstream f((nombreAlgoritmo[metodo]+".dat").c_str());
    system("cls");
    cout<<endl<<"***Ordenacion por " << nombreAlgoritmo[metodo]+" ***"<<endl<<endl;
    cout<<"Tiempos de ejecucion promedio "<<endl<<endl;
    cout<<"\tTalla\t\tTiempo (mseg)"<<endl<<endl;
    double tiempo=0;
    //int key;
    double secs=0;///fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
    ConjuntoInt *v;
    Graficas g;

		for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
		{
		    v=new ConjuntoInt(talla);
            v->GeneraVector(talla);
			switch (metodo){
			case BURBUJA:
				{
                    for(int r=0;r<NUMREPETICIONES;r++)
                    {
                        v=new ConjuntoInt(talla);
                        v->GeneraVector(talla);
                        /*double*/ secs=ordenarArrayDeInt(v->getDatos(),talla,metodo);
                        tiempo = tiempo+secs;
                        delete v;
                    }
                    tiempo=tiempo/NUMREPETICIONES;
				}
				break;
			case INSERCION:
				{
				    for(int r=0;r<NUMREPETICIONES;r++)
                    {
                        v=new ConjuntoInt(talla);
                        v->GeneraVector(talla);
                        double secs=ordenarArrayDeInt(v->getDatos(),talla,metodo);
                        tiempo = tiempo+secs;
                        delete v;
                    }
                    tiempo=tiempo/NUMREPETICIONES;
				}
				break;
			case SELECCION:/*Caso mejor (T(n)= 9)*/
				{
				    for(int r=0;r<NUMREPETICIONES;r++)
                    {
                        v=new ConjuntoInt(talla);
                        v->GeneraVector(talla);
                        double secs=ordenarArrayDeInt(v->getDatos(),talla,metodo);
                        tiempo = tiempo+secs;
                        delete v;
                    }
                    tiempo=tiempo/NUMREPETICIONES;
				}
				break;
            case QUICKSORT:
                {
				    for(int r=0;r<NUMREPETICIONES;r++)
                    {
                        v=new ConjuntoInt(talla);
                        v->GeneraVector(talla);
                        double secs=ordenarArrayDeInt(v->getDatos(),talla,metodo);
                        tiempo = tiempo+secs;
                        delete v;
                    }
                    tiempo=tiempo/NUMREPETICIONES;
				}
				break;
			}
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
			case BURBUJA:{
				/* Ejecutar el fichero por lotes (comandos)*/
				g.generarGraficaMEDIO(nombreAlgoritmo[metodo],CUADRADO);
				system("Burbuja.gpl"); system("cls");
				cout <<endl<<"Grafica guardada en el fichero "<<nombreAlgoritmo[metodo]+".pdf"<<endl;
													 }break;
			case INSERCION:{
				/* Ejecutar el fichero por lotes (comandos)*/
				g.generarGraficaMEDIO(nombreAlgoritmo[metodo],CUADRADO);
				system("Insercion.gpl"); system("cls");
				cout <<endl<<"Grafica guardada en el fichero "<<nombreAlgoritmo[metodo]<<".pdf"<<endl;
													}break;
			case SELECCION:{
				/* Ejecutar el fichero por lotes (comandos)*/
				g.generarGraficaMEDIO(nombreAlgoritmo[metodo],CUADRADO);
				system("Seleccion.gpl");
				system("cls");
				//system((gpl).c_str());
				cout <<endl<<"Grafica guardada en el fichero "<<nombreAlgoritmo[metodo]<<".pdf"<<endl;
													 }break;
            case QUICKSORT:{
				/* Ejecutar el fichero por lotes (comandos)*/
				g.generarGraficaMEDIO(nombreAlgoritmo[metodo],NlogN);
				system("Quicksort.gpl");
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
/*
 * Compara dos metodos de ordenacion.
 * Genera el fichero de datos y permite las opcion de crear la gr�fica correspondiente.
 * param metodo1: Primer metodo de ordenacion a comparar
 * param metodo2: Segundo metodo de ordenacion a comparar
 */
void TestOrdenacion::comparar(int metodo1, int metodo2) {
	 //** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
	 ofstream f1((nombreAlgoritmo[metodo1]+".dat").c_str());
	 ofstream f2((nombreAlgoritmo[metodo2]+".dat").c_str());
    system("cls");
	cout<<endl<<"*** Ordenacion por "<<nombreAlgoritmo[metodo1]<<" y " <<nombreAlgoritmo[metodo2]<<" ***"<<endl;
	cout<<"\tTiempos de ejecucion promedio"<<endl<<endl;
	//cout<<endl;
	cout<<"\t         \t    "<<nombreAlgoritmo[metodo1]<<"\t    "<<nombreAlgoritmo[metodo2]<<endl;
	cout<<"\tTalla (n)\t    Tiempo (mseg)  Tiempo (mseg)"<<endl<<endl;
	double tm1=0,tm2=0,secs;
	ConjuntoInt *v;
	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
	{
	    v=new ConjuntoInt(talla);
		for(int r=0;r<NUMREPETICIONES;r++)
        {
            v->GeneraVector(talla);///se mete dentro de aqui xk si no en el segundo for ya estaria ordenado
            secs=ordenarArrayDeInt(v->getDatos(),talla,metodo1);
            tm1+=secs;
        }
        tm1=tm1/NUMREPETICIONES;
		for(int r=0;r<NUMREPETICIONES;r++)
        {
            v->GeneraVector(talla);
            secs=ordenarArrayDeInt(v->getDatos(),talla,metodo2);
            tm2+=secs;
        }
        tm2=tm2/NUMREPETICIONES;
		/*escribir en el fichero*/
		f1<<talla<<"\t"<<tm1<<endl;
		f2<<talla<<"\t"<<tm2<<endl;
		/*Visualizar en pantalla*/
		cout<<"\t"<<talla<<"\t\t"<<setw(10)<<setprecision(2)<<(double)tm1<<" \t"<<setw(10)<<setprecision(2)<<(double)tm2<<endl;
		cout<<endl;
		v->vaciar();
		delete v;//todo lo que se crea con new se borra luego con delete para q no se quede en la memoria
	}
	f1.close();
	f2.close();
	cout <<endl<<"Datos guardados en los ficheros "<<nombreAlgoritmo[metodo1]+".dat"<<" y "<<nombreAlgoritmo[metodo2]+".dat"<<endl;
	/* Generar grafica */
		char opc;
		cout<<endl<<"Generar grafica de resultados? (s/n): ";
		cin>>opc;
		switch (opc){
		case 's':
		case 'S':{
			/* Ejecutar el fichero por lotes (comandos)*/
			Graficas g;
			g.generarGraficaCMP(nombreAlgoritmo[metodo1],nombreAlgoritmo[metodo2]);
			system("CmdComparar.gpl"); system("cls");
			//system((gpl).c_str());
			cout <<endl<<"Grafica guardada en el fichero "<<nombreAlgoritmo[metodo1]+nombreAlgoritmo[metodo2]+".pdf"<<endl;
						 }break;
		default: {cout <<"Grafica no guardada en fichero "<<endl;
						 }break;
		}
		cout<<endl;
		system("pause");
		system("cls");
}
