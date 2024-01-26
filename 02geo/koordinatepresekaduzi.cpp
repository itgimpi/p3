#include <iostream>
#include <iomanip>

typedef long long LL;
using namespace std;

int main() {
    LL xa, ya, xb, yb, xc, yc, xd, yd;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd; // deklarizacija i unos koordinata tacki

    LL a11 = xb - xa, a12 = xc - xd, b1 = xc - xa; // promenjive za prvu vrstu matrice
    LL a21 = yb - ya, a22 = yc - yd, b2 = yc - ya; // promenjive za drugu vrstu matrice
    LL D = a11 * a22 - a12 * a21; // glavna matrica 
    if (D == 0)  // paralelne duzi, nema tacka preseka
     
        cout << "nema" << endl;
    else {
        LL D1 = b1 * a22 - a12 * b2;
        LL D2 = a11 * b2 - a21 * b1; // dodatne determinante za racunanje parametra t1 i t2
        double t1 = (double)D1 / (double)D;
        double t2 = (double)D2 / (double)D;
        if (t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1) // parametri t1 i t2 moraju da budu u intervalu [0,1]
            // nosece prave se seku, ali ne i duzi
            cout << "nema" << endl;
        else {
            double x = xa + t1 * (xb - xa);
            double y = ya + t1 * (yb - ya);//racunanje tacka preseka
            cout << fixed << showpoint << setprecision(5)
            << x << " " << y << endl;
        }
    }
    return 0;
}