#ifndef COLAPRI_H
#define COLAPRI_H
#include "tadcola.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

///Fichero TADColaPri.h

#define MAXcolas 9

using namespace std;

//const int TAM_CADENA=30;
//typedef char cadena[TAM_CADENA];


class ColaPri {
        cola tabla[MAXcolas];
    public:
    ColaPri(); //Constructor: crea un objeto ColaPri vac�o
    ~ColaPri(); //Destructor: libera la memoria din�mica del objeto ColaPri
    void insertarColaPri(int i, Paciente e);
    /*Insertar� el paciente p en la cola de prioridad i de la ColaPri*/
    void sacarColaPri();
    /*Elimina el paciente de mayor prioridad. Si hay varios con la misma
    prioridad saldr� aquel que lleve m�s tiempo en el objeto ColaPri*/
    Paciente consultarColaPri();
    /*Devuelve el paciente de mayor prioridad almacenado en el objeto ColaPri
    original sin quitarlo. Si hay varios con la misma prioridad saldr� aquel
    que lleve m�s tiempo en el objeto ColaPri*/
    bool esvaciaColaPri();//Devuelve si el objeto ColaPri est� vac�o
    int longitudColaPri();//Devuelve la longitud del objeto ColaPri
    bool cargarfichero (cadena fich);
    /*Cargar� los datos almacenados en el fichero cuyo nombre se pasa como
    par�metro en el objeto ColaPri. Devuelve true si no hay error en la carga*/
    bool guardarfichero (cadena fich);
    /*Guardar� los datos del objeto ColaPri en el fichero cuyo nombre se pase
    como par�metro. Devuelve true si no hay error al guardar el objeto*/
};

#endif // COLAPRI_H
