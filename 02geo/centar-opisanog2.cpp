#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
    
struct Tacka { 
    double x, y; 
    Tacka() : x(0), y(0) { }
    Tacka(double _x, double _y) : x(_x), y(_y) { } };

struct Vektor {
    double x, y;
    Vektor() : x(0), y(0) { }
    Vektor(double _x, double _y) : x(_x), y(_y) { }
    Vektor(const Tacka& P, const Tacka& Q) : x(Q.x - P.x), y(Q.y - P.y) { } };

Vektor operator *(const Vektor& V, double k) { return Vektor(V.x * k, V.y * k ); }

Tacka operator +(const Tacka& P, const Vektor& V) { return Tacka(P.x + V.x, P.y + V.y); }

double Rastojanje(const Tacka& P, const Tacka& Q) { 
    return sqrt((P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y)); }

Vektor VektorSimetraleUgla(const Tacka& P, const Tacka& Q, const Tacka& R) {
    double qr = Rastojanje(Q, R);
    Vektor ort_QR = Vektor(Q, R) * (1.0 / qr);
    double qp = Rastojanje(Q, P);
    Vektor ort_QP = Vektor(Q, P) * (1.0 / qp);
    return Vektor(Q, Q + ort_QP + ort_QR); }

// presek prave MN i prave PQ
Tacka Presek(const Tacka& M, const Vektor& MN, const Tacka& P, const Vektor& PQ) {
    // M.x + t MN.x == P.x + u PQ.x
    // M.y + t MN.y == P.y + u PQ.y
    // ----------------------------
    // ovo je sistem jednacina po t i u
    // po uslovima zadatka vektori PQ i MN nisu paralelni, pa resenje postoji
    double t = ((M.x - P.x) * PQ.y + (P.y - M.y) * PQ.x) / ((PQ.x * MN.y - PQ.y * MN.x));
    Tacka R; 
    R.x = M.x + t * MN.x; 
    R.y = M.y + t * MN.y;
    return R; }
 
Vektor Normala(const Vektor& v) {
    // Rotacija vektora za 90 stepeni ulevo
    return Vektor(-v.y, v.x); }

                                                                                                                                                                                                       
int main() {
    Tacka a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    // Središte stranice AB
    Tacka sab((a.x + b.x) / 2.0, (a.y + b.y) / 2.0);
    // Vektor stranice AB i njegova normala
    Vektor ab(a, b);
    Vektor nab = Normala(ab);
    // Središte stranice BC
    Tacka sbc((b.x + c.x) / 2.0, (b.y + c.y) / 2.0);
    // Vektor stranice BC i njegova normala
    Vektor bc(b, c);
    Vektor nbc = Normala(bc);
    Tacka o = Presek(sab, nab, sbc, nbc);


    cout << fixed << showpoint << setprecision(4) << o.x << " " << o.y << endl;
    return 0;
}