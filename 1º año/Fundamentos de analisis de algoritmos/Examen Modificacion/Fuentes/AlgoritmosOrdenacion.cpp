/*
 * Clase AlgoritmosOrdenacion que implementa los Algoritmos de Ordenación para ordenar un vector de enteros en orden descendente.
 * Define las implementaciones de los siguientes métodos de Ordenación en vectores:
 *	- Burbuja
 *	- Inserción
 *	- Selección.
 */

#include "AlgoritmosOrdenacion.h"

AlgoritmosOrdenacion :: AlgoritmosOrdenacion() {}
AlgoritmosOrdenacion :: ~AlgoritmosOrdenacion(){}

/*
 * método ordenaBurbuja, implementa el método de ordenación Burbuja.
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 */

void AlgoritmosOrdenacion :: ordenaBurbuja(int v[], int size)
{
//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
    int aux;
    for(int i=size-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            if(v[j]>v[j+1])
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;

            }
        }
    }
}


/*
 * método ordenaInsercion, implementa el método de ordenación por Inserción-
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 */

void AlgoritmosOrdenacion :: ordenaInsercion(int v[], int size)
{
//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
    int j,x;
    for(int i=1;i<size;i++)
    {
        x=v[i];
        j=i-1;
        while(j>=0&&x<v[j])
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=x;
    }
}

/*
 * método ordenaSeleccion, implementa el método de ordenación por Selección.
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 */
void AlgoritmosOrdenacion :: ordenaSeleccion(int v[], int size)
{
//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
    int aux,posminimo;
    for(int i=0;i<size;i++)
    {
        posminimo=i;
        for(int j=i+1;j<size;j++)
        {
            if(v[j]<v[posminimo])
                posminimo=j;
        }
        aux=v[posminimo];
        v[posminimo]=v[i];
        v[i]=aux;
    }
}

void AlgoritmosOrdenacion::ordenaQuickSort(int v[],int size)
{
    QuickSort(v,0,size-1);
}

void AlgoritmosOrdenacion::QuickSort(int v[],int p,int size)
{
    int q;
    if(p<size)
    {
        q=Partition(v,p,size);
        QuickSort(v,p,q);
        QuickSort(v,q+1,size);
    }
}

int AlgoritmosOrdenacion::Partition(int v[],int p, int r)
{
    int piv,i,j;
    piv=v[p];
    i=p-1;
    j=r+1;
    do
    {
      do
      {
          j--;
      }while(v[j]>piv);
      do
      {
          i++;
      }while(v[i]<piv);
      if(i<j)
      {
          int aux;
          aux=v[i];
          v[i]=v[j];
          v[j]=aux;
      }
    }while(i<j);
    return j;
}
