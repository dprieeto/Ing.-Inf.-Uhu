#include <iostream>

using namespace std;

int main()
{
    float bytes, kbytes;
    cout << "Introduzca un numero de bytes: ";
    cin >> bytes;
    kbytes = bytes * 0.001;
    cout << bytes << "bytes son:" << kbytes << " kbytes" << endl;

    return 0;
}
