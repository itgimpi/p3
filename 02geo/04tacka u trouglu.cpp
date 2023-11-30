#include <bits/stdc++.h>
using namespace std; // Тачка у троуглу
// https://petlja.org/biblioteka/r/Zbirka3/tacka_u_trouglu


// orijentacija moye da bude + (1), - (-1) i 0 (0)
int orijentacija(double xa, double ya, double xb, double yb, double xc, double yc) {
    double z = (xb-xa)*(yc-ya)-(xc-xa)*(yb-ya); // vek.pr. za 2 vektora, koji su u xy ravni
    // tacnost sa double...
    
    if ( abs(z) < 1e-9 ) return 0; // nula?
    if ( z > 1e-9 ) return 1; // poz
    return -1; } // neg.



bool pripada(   double xt, double yt, 
                double xa, double ya, double xb, double yb, double xc, double yc) {
    int orijentacija1 = orijentacija(xa, ya, xb, yb, xt, yt); // t i ab
    int orijentacija2 = orijentacija(xb, yb, xc, yc, xt, yt); // t i bc
    int orijentacija3 = orijentacija(xc, yc, xa, ya, xt, yt); // t i ab

/*   return  orijentacija1 == orijentacija2 &&
            orijentacija2 == orijentacija3 &&
            orijentacija3 == orijentacija1;  */ 

    return  orijentacija1 == orijentacija2 &&
            orijentacija2 == orijentacija3; // tranzitivnost

}

int main() {
    // prvo se unosi t
    double xt, yt; cin >> xt >> yt; // tacka t
    double xa, ya, xb, yb, xc, yc; cin >> xa >> ya >> xb >> yb >> xc >> yc; // trougao abc

    if ( pripada(xt, yt, xa, ya, xb, yb, xc, yc) )
        cout << "da";
    else
        cout << "ne";


    return 0; }