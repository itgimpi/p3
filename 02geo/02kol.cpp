#include <iostream>
using namespace std;

void vektorski_proizvod(int x1, int y1, int z1,
                        int x2, int y2, int z2,
                        int& x, int& y, int& z) {
    // izracunavamo determinantu:

    //  i  j  k
    //  x1 y1 z1
    //  x2 y2 z2
    x = y1*z2 - y2*z1; // za xy ravan, z=0
    y = z1*x2 - x1*z2; // za xy ravan, z=0
    z = x1*y2 - x2*y1; // za xy ravan najbitnije
}

bool kolinearni_vektori(    int x1, int y1, int z1,
                            int x2, int y2, int z2) {
    int x, y, z;
    vektorski_proizvod(x1, y1, z1,
                        x2, y2, z2,
                        x, y, z);
    return x == 0 && y == 0 && z == 0;
}

bool kolinearne_tacke(int x1, int y1, int x2, int y2, int x3, int y3) {
    return kolinearni_vektori(x1 - x2, y1 - y2, 0,
                                x1 - x3, y1 - y3, 0);
}

int main() {
    int x1, y1;    cin >> x1 >> y1;
    int x2, y2;    cin >> x2 >> y2;
    int n;    cin >> n;
    int broj = 0;
    for (int i = 0; i < n; i++) {
        int x, y;        cin >> x >> y;
        if (kolinearne_tacke(x1, y1, x2, y2, x, y))
        broj++;
    }
    cout << broj << endl;
    return 0;
}