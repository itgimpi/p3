#include <bits/stdc++.h>
using namespace std; // Конструкција простог многоугла
// https://petlja.org/biblioteka/r/Zbirka3/prost_poligon

const double eps = 1e-9;
typedef struct { // struktura tacka
    int x; 
    int y; } tacka;

double xt; // vidljive u svim f-jama, narocito je bitna f
double yt;

bool kolinearne(const tacka &t1, const tacka &t2, const tacka &t3) {
    return (t1.x - t2.x) * (t1.y - t3.y) == (t1.y - t2.y) * (t1.x - t3.x); }

double rast(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2, dy = y1 - y2;
    // return sqrt... je tacno rast.
    return dx * dx + dy * dy; // kv. rast, ne racuna se koren, brze je...
}

bool f ( tacka &t1, tacka &t2 ) { // 2 tacke za poredjenje
    double dx1 = t1.x - xt, dy1 = t1.y - yt;
    double dx2 = t2.x - xt, dy2 = t2.y - yt;

    double teta1 = atan2(dy1, dx1);
    double teta2 = atan2(dy2, dx2);

    if ( teta1 < teta2 - eps ) // prvi ugao je manji
        return true;

    if ( teta2 < teta1 - eps ) // drugi ...
        return false;

    // uglovi su isti...
    return ( rast(xt,yt,t1.x,t1.y) < rast(xt,yt,t2.x,t2.y) ); // prva treba da bude bliza
}

void prost(vector<tacka>&tacke){
    // odredi tri nekolinearne tacke za trougao
    // prve dve se 0 i 1 iz vektora, fali treca
    int i = 2; // kreni od pozicije 2 u vektoru
    // nadji prvu nekolinearnu sa 0 i 1
    while ( kolinearne(tacke[0], tacke[1], tacke[i]) ) { // sve dok su kolinearne...
        i++; } // probaj sledecu
    // tri nekolinearne tacke su t0, t1 i ti
    // odredi teziste trougla t0t1ti
    xt = ( tacke[0].x + tacke[1].x + tacke[i].x ) / 3.0 ;
    yt = ( tacke[0].y + tacke[1].y + tacke[i].y ) / 3.0 ;
    // sortiraj tacke po uglovima, ...
    // ako su uglovi isti sort po rastojanju
    sort( begin(tacke), end(tacke), f ); }

int main() {
    int n; cin >> n; // broj tacaka, temena, stranica  

    vector<tacka>tacke(n); // vektor za sve tacke
    for (int i = 0; i < n; i++)
        cin >> tacke[i].x >> tacke[i].y;

    prost(tacke); // napravi prost mnogougao 

    for ( auto t : tacke )
        cout << t.x << ' ' << t.y << '\n';

    return 0; }