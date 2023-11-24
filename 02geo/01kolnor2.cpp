#include <bits/stdc++.h>
using namespace std;

int skalar(int x1, int y1, int z1, int x2, int y2, int z2) { // sk. proizvod
    return x1*x2 + y1*y2 + z1*z2; }

void vektor(int x1, int y1, int z1, int x2, int y2, int z2, int &x, int &y, int &z) { // vektorski
    x = y1 * z2 - y2 * z1;
    y = z1 * x2 - z2 * x1;
    z = x1 * y2 - x2 * y1; }

int main() {
    int x1, y1, z1; cin >> x1 >> y1 >> z1; // v1, pocetak je (0,0,0), kraj je (x1,y1,z1)
    int x2, y2, z2; cin >> x2 >> y2 >> z2; // v2, ...                           2  2  2 

    bool nestosu = false;

    if (skalar(x1, y1, z1, x2, y2, z2) == 0 ) {// ugao je 90
        cout << "normalni";   
        nestosu = true; }

    int x, y, z; // za vek. pr.
    vektor(x1,y1,z1, x2,y2,z2, x,y,z); // cout << x << ' ' << y << ' ' << z << '\n';
    if ( x == 0 && y == 0 && z == 0 ) { // nula vektor?
        cout << "kolinearni";
        nestosu = true;     }

    if (!nestosu)
        cout << '-';


    
    
    
    





    return 0; }