#include <bits/stdc++.h>
using namespace std; // Тачка у троуглу
// https://petlja.org/biblioteka/r/Zbirka3/tacka_u_trouglu

const double eps = 1e-9;

int ori (   double xa, double ya,
            double xb, double yb,
            double xc, double yc) {
    double z =   (xb-xa)*(yc-ya)
                -(xc-xa)*(yb-ya); // vek. pr.

    //if ( z == 0 ) return 0; KAO KOD HERONA
    if ( abs(z) < eps ) return 0;
    if ( z > eps ) // z > 0
        return 1;
    return -1; }

bool pripada(double xt, double yt,
             double xa, double ya, 
             double xb, double yb,
             double xc, double yc) {
    
    // orijentacije ABT, BCT, CAT
    int ori1 = ori(xa, ya, xb, yb, xt, yt);
    int ori2 = ori(xb, yb, xc, yc, xt, yt);
    int ori3 = ori(xc, yc, xa, ya, xt, yt);
    // ako su orijentacije iste
    // tacka je u trouglu
    // inace nije
    return  ori1 == ori2 && ori2 == ori3;  }

int main() {
    double xt, yt, xa, ya, xb, yb, xc, yc;
    cin >> xt >> yt >> xa >> ya >> xb >> yb >> xc >> yc;

    if (pripada(xt, yt, xa, ya, xb, yb, xc, yc))
        cout << "da";
    else
        cout << "ne";




    return 0; }