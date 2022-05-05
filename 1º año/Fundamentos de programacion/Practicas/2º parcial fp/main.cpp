/*Se necesita implementar un peque�o programa
que realice la gesti�n del �carrito de compras�
de clientes de un almac�n por internet. */
#include <iostream>
#include <string.h>
using namespace std;
//---------------------------------------------------------------------------
typedef char Cadena[20];

#define MAX_COMPRAS_CLIENTES 5
struct Compra
{
   Cadena Nombrep;   //Nombre de un producto
   float Precio;     //Precio del producto por unidad
   int Unidades;     //N�mero de unidades en el almacen
};

class Cliente
//Almacenar� los datos y las compras de un cliente
{
   Cadena Nombrec;  //Nombre del cliente
   int Dni;         //DNI del cliente, sin letra
   long CCorriente; //N�mero de la cuenta corriente del cliente
   Compra Carrito[MAX_COMPRAS_CLIENTES];
                    //Compras realizads por el cliente.
   int NCompras;    //N�mero de compras realizadas, las compras
            //en la tabla Carrito estar�n almacenadas desde
            //la posici�n 0 hasta la posici�n NCompras-1

 public:
   Cliente();
   //Inicializa el campo Nombrec a la cadena vac�a.
   //El Dni, la cuenta corriente y el n�mero de compras
   //se inicializar�n a 0.
   Cliente(Cadena N, int D, int CC);
   /*Inicializa el objeto, copiando N en Nombrec, D en el Dni,
   CC en CCorriente. El n�mero de compras se inicializar� a 0.*/
   void GetNombre(Cadena N);
   /*Devuelve el nombre del cliente en el par�metro N.*/
   int GetDni();
   /*Devuelve el Dni del cliente.*/
   void GetCC(int &cc);
   /*Devuelve la cuenta corriente del cliente en
   el par�metro cc*/
   int BuscarCompra(Cadena Producto);
   /*Busca dentro de la tabla Carrito la compra cuyo nombre
   coincide con el pasado por par�metro. Devuelve la posici�n
   de dicha compra dentro del vector o -1 si no se encuentra.*/
   void Insertar(Compra Datos);
   /*A�ade la compra Datos pasada por par�metro al Carrito.
   Si el producto no existe previamente en el carrito del
   cliente, �ste se a�adir� al final de la tabla.
   En el caso de que el producto exista en el Carrito previamente
   se actualizar� dicha compra a�adiendo las nuevas unidades
   compradas.*/
   int NProductos() {return NCompras;};

   void EliminarCompra(int Pos);
   /*Elimina la compra que est� situada en la posici�n Pos
   de la tabla de compras del cliente. */
};

Cliente::Cliente()
{
  strcpy(Nombrec,"");
  Dni=0;
  NCompras=0;
  CCorriente=0;
}

Cliente::Cliente(Cadena N, int D, int CC)
{       //A rellenar por el alumno 0.25 puntos
    strcpy(Nombrec,N);
    Dni=D;
    CCorriente=CC;
    NCompras=0;
}

void Cliente::GetNombre(Cadena N)
{
   strcpy(N,Nombrec);
}

int Cliente::GetDni()
{
   return Dni;
}

void Cliente::GetCC(int &cc)
{           //A rellenar por el alumno 0.25 puntos
    cc=CCorriente;
}

int Cliente::BuscarCompra(Cadena Producto)
{      //A rellenar por el alumno 0.6 puntos
    int pos=-1,i=0;
    while(i<NCompras&&pos==-1)
    {
        if(strcmp(Carrito[i].Nombrep,Producto)==0)
            pos=i;
        else
            i++;
    }
    return pos;
}

void Cliente::Insertar(Compra Datos)
{         //A rellenar por el alumno 0.7 puntos
    int pos = BuscarCompra (Datos.Nombrep);

    if (pos != -1) {
            Carrito[pos].Unidades = NCompras + Datos.Unidades; // Actualiza las unidades
            Carrito[pos].Precio = NCompras + Datos.Precio; //Actualiza el precio
    }

    else {
            Carrito[NCompras] = Datos;
            NCompras++;
            }
}

void Cliente::EliminarCompra(int Pos)
{        //A rellenar por el alumno 0.7 puntos
    if(BuscarCompra(Carrito[Pos].Nombrep)!=-1)
    {
        for(int i=Pos; i<NCompras-1;i++)
        {
            Carrito[i]=Carrito[i+1];
        }
        NCompras--;
    }
}


int main( )
{     //A rellenar por el alumno 1 punto
  /* Realice un main que cree dos objetos de tipo Cliente,
  uno vac�o y el otro con el nombre Luis con Dni 11111111
  y cuenta corriente 123456789.*/

    Compra datos;
    Cliente c;
    Cadena N;
    long D;
    int CC;
    Cliente();
    cout << "\n Introduce el Nombre del nuevo cliente: ";
    cin >> N;
    cout << "\n Introduce el DNI de este cliente: ";
    cin >> D;
    cout<<"\n Introduce la cuenta corriente del cliente: ";
    cin >> CC;
    Cliente client(N, D, CC);

  /*Realice una compra para el cliente Luis pidiendo por
  teclado el nombre del producto, el precio y cuantas
  unidades quiere comprar, a�ada la compra al carrito*/

    cout << "\n\n";
	cout << "\n\n Introduce el nombre del producto: ";
    cin >> datos.Nombrep;
    cout << "\n Introduce el precio del producto: ";
    cin >> datos.Precio;
    cout << "\n Introduce el numero de unidades del producto: ";
    cin >> datos.Unidades;
	c.Insertar(datos);
    cout <<"Compra realizada";

  /* Muestre por pantalla el nombre, dni y cuenta corriente
  del cliente Luis, obtenidos de los atributos del objeto que
  cre� al comienzo del main*/
    c.GetNombre(N);
	c.GetCC(CC);
    cout << N << c.GetDni() <<CC;
    return 0;
}
//---------------------------------------------------------------------------
