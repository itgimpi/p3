#include <bits/stdc++.h>
using namespace std;
// https://petlja.org/biblioteka/r/Zbirka3/kolinearne_tacke
// ne preporucuje se!!!

void vektorski( int x1, int y1, int z1, // odredi vek. pr. u 3D
                int x2, int y2, int z2, 
                int &x, int &y, int &z) {
    x = y1 * z2 - y2 * z1;
    y = z1 * x2 - x1 * z2;
    z = x1 * y2 - x2 * y1; }

bool kolvektori( int x1, int y1, int z1, // da li su 2 vektora kolinearna?
                 int x2, int y2, int z2 ) {
    int x, y, z; // za vek. proizvod
    vektorski(x1, y1, z1, x2, y2, z2, x, y, z); // poznat vek.pr.
    //cout << x << y << z << endl;
    return x == 0 && y == 0 && z == 0; } // nepotrebno se proverava x i y

bool koltacke(  int x1, int y1,  // da li su 3 tacke kolinearne?
                int x2, int y2, 
                int x3, int y3  ) {
    return kolvektori( x2-x1, y2-y1, 0, x3-x1, y3-y1, 0 ); // povratak u 3D, z=0
}

int main() {  // 2D, xy, z = 0
    int x1, y1; cin >> x1 >> y1; // pocetak vetora
    int x2, y2; cin >> x2 >> y2; // kraj vetora
    int res = 0;

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if ( koltacke(x1, y1, x2, y2, x, y) ) res++;     }

    cout << res; 

    return 0; }