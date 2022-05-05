#include "matrices.h"

void matrices::cargar()
{
    for(int i=0;i<M;i++)
    {
        tabla[i]=i;
    }
}
bool matrices::encontrar()
{
   int numero,i=0;bool encontrado=false;
   cout<<"Introduce el numero a buscar si esta en la tabla: ";cin>>numero;
   while(numero<M &&!encontrado)
   {
       if(numero==tabla[i])
       {
           encontrado=true;
       }
       i++;
   }
   if(encontrado==true)
   {
       cout<<"El numero se encuentra en la tabla."<<endl;system("pause");
   }
   else
    {
        cout<<"El numero introducido no se encuentra en la tabla."<<endl;
    }
   return encontrado;
}
