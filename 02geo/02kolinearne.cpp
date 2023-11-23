#include <bits/stdc++.h>
using namespace std;

int skalarni(int x1, int y1, int z1, int x2, int y2, int z2){
    return x1 * x2 + y1 * y2 + z1 * z2; }

void vektorski( int x1, int y1, int z1,
                int x2, int y2, int z2, 
                int &x, int &y, int &z) {
    x = y1 * z2 - y2 * z1;
    y = z1 * x2 - x1 * z2;
    z = x1 * y2 - x2 * y1; }

int main() {
    int x1, y1, z1; cin >> x1 >> y1 >> z1;
    int x2, y2, z2; cin >> x2 >> y2 >> z2;

    bool barnesto = false;
    if (skalarni(x1, y1, z1, x2, y2, z2) == 0) {
        cout << "normalni";
        barnesto = true; }

    int x, y, z;
    vektorski(x1, y1, z1, x2, y2, z2, x, y, z);  // u x,y,z je vektor
    if ( x == 0 && y == 0 && z == 0 ) {
        cout << "kolinearni";
        barnesto = true; }

    if (!barnesto) cout << '-';
    
    
    





    return 0; }