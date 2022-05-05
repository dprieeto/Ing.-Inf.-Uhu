/*
 * La clase TestBusqueda contiene los metodos para:
 * 1. Comprobar que los métodos de búsqueda de la clase AlgoritmosBusqueda funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un método de búsqueda,
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente con ajuste al Orden de complejidad.
 * 3. Comparar el coste temporal de dos métodos de búsqueda
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente.
 * 4. Comparar todos los algoritmos de búsqueda implementados.
 */
#ifndef _TEST_BUSQUEDA
#define _TEST_BUSQUEDA

//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//

#include <vector>
#include <string>
#include <iostream>
using namespace std;


class TestBusqueda
{
    vector<string>nombreAlgoritmo;
public:

	TestBusqueda();
	~TestBusqueda();
	static double buscaEnArrayDeInt(int v[],int size,int metodo,int key,int &pos);
	void comprobarMetodosBusqueda();
	void comparar(int metodo1, int metodo2);
	void casoMedio(int metodo);
	void comparartodos();
};

#endif
