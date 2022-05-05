#include <iostream>

using namespace std;
class numero
{
    int maximo,minimo;
    float media;
public:
    void estadistica();
    int mostrarmax();
    int mostrarmin();
    float mostrarmedia();
};
void numero::estadistica()
{
    int cantidad, tmp;
	media = 0;

	cout << "Introduzca la cantidad de numeros que quieres poner: ";
	cin >> cantidad;

	for(int i = 0; i < cantidad; i++){
		cout << "Introduzca un numero entero: ";
		cin >> tmp;
		if(i == 0){
			maximo = minimo = tmp;
		}else{
			if(tmp < minimo)
				minimo = tmp;
			if(tmp > maximo)
				maximo = tmp;
		}
		media += tmp;
	}

	media /= cantidad;
	cout << "\n";
}
int numero::mostrarmax()
{
    return maximo;
}
int numero::mostrarmin()
{
    return minimo;
}
float numero::mostrarmedia()
{
    return media;
}
int main()
{
    numero ob;
    ob.estadistica();
    cout<<"\nLa media de los numeros elegidos es: "<<ob.mostrarmedia();
    cout<<"\nEl maximo es: "<<ob.mostrarmax();
    cout<<"\nEl minimo es: "<<ob.mostrarmin();
    return 0;
}
