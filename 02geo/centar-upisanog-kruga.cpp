#include <bits/stdc++.h>
using namespace std;
    
struct Tacka {  // Struktura
    double x, y; 
    Tacka() : x(0), y(0) { } // Podrazumevani konstruktor
    Tacka(double xx, double yy) : x(xx), y(yy) { } };

// Struktura koja predstavlja vektor u 2D prostoru
struct Vektor {
    double x, y;

    Vektor() : x(0), y(0) { } 

    Vektor(double xx, double yy) : x (xx), y (yy) { } 
    Vektor(const Tacka& a, const Tacka& b) : x (b.x - a.x), y (b.y - a.y) { } };

// Mnozi komponente vektora skalarom
Vektor operator *(const Vektor& v, double k) { 
    return Vektor(v.x * k, v.y * k ); }

// Pomera tacku t za vrednosti vektora v i vraca novu tacku
Tacka operator +(const Tacka& t, const Vektor& v) { 
    return Tacka(t.x + v.x, t.y + v.y); } // translacija

// rast. izmedju dve tacke 
double rast(const Tacka& a, const Tacka& b) { 
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }

// vektor pravca simetrale ugla u temenu b, izmedju krakova ab i bc
Vektor simetrala(const Tacka& a, const Tacka& b, const Tacka& c) {
    double bc = rast(b, c); // duzina stranice bc
    Vektor jedbc = Vektor(b, c) * (1.0 / bc); // jedinicni vektora u smeru b -> c
    
    double ba = rast(b, a); // Nalazenje duzine stranice ba
    Vektor jedba = Vektor(b, a) * (1.0 / ba); // jedinicni vektora u smeru b -> a
    
    // Sabiranjem dva jedinicna vektora dobija se smer simetrale
    // Konstruktor Vektor(b, ...) ce oduzeti koordinate tacke b, 
    // i ostaje zbir jedinicnih vektora (ort_QP + ort_QR).
    return Vektor(b, b + jedba + jedbc); }

// pronalazi tacku preseka dve prave odredjene tackama i njihovim vektorima pravca
Tacka presek(const Tacka& a, const Vektor& ab, const Tacka& c, const Vektor& cd) {
    // Postavlja se sistem jednacina po parametrima t1 i t2:
    // a.x + t1 * ab.x == c.x + t2 * cd.x
    // a.y + t1 * ab.y == c.y + t2 * cd.y
    // ab.x * t1 - cd.x * t2 = c.x - a.x 
    // ab.y * t1 - cd.y * t2 = c.y - a.y 
    double d = - ab.x * cd.y + ab.y * cd.x;
    double d1 = (a.x - c.x) * cd.y + (c.y - a.y) * cd.x;
    double t = d1 / d;
    // Sistem se resava po nepoznatoj t
    //double t = ((a.x - c.x) * cd.y + (c.y - a.y) * cd.x) / ((cd.x * ab.y - cd.y * ab.x));
    
    // tacka preseka p dobija se iz pocetne tacke M duz vektora MN
    Tacka p; 
    p.x = a.x + t * ab.x; 
    p.y = a.y + t * ab.y;
    return p;
}
   
int main() {
    Tacka a, b, c;
    // koordinate sva tri temena trougla (Ax, Ay, Bx, By, Cx, Cy)
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    // vektor pravca simetrale ugla u temenu B (izmedju krakova BA i BC)
    Vektor bs = simetrala(a, b, c);
    // vektor pravca simetrale ugla u temenu C (izmedju krakova CB i CA)
    Vektor cs = simetrala(b, c, a);
    // Centar upisanog kruga u je tacka preseka ove dve simetrale prave
    Tacka u = presek(b, bs, c, cs);
    cout << fixed << showpoint << setprecision(4) << u.x << " " << u.y << endl;
    
    return 0;
}