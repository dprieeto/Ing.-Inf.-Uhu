#include <iostream>

using namespace std;

int main()
{
    float L, p1, p2;
    L = 1500;
    p1 = 5000*(L/5280.0);
    p2 = 5000*(L/5280);

    cout << "El precio total del coste de la carretera es de: " << p1 << " euros" << endl;
    cout << "El precio total del coste de la carretera es de: " << p2 << " euros" << endl;
    return 0;
}
