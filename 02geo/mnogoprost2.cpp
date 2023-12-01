#include <bits/stdc++.h>
using namespace std; // Конструкција простог многоугла
// https://petlja.org/biblioteka/r/Zbirka3/prost_poligon

const double epsi = 1e-9; // tacnost...

typedef struct { // struktura tacka
    int x; 
    int y; } tacka;

double xt; // vidljive u svim f-jama, narocito je bitna f
double yt;

bool kol( const tacka &t1, const tacka &t2, const tacka &t3) { // mozda i epsilon
    return ( t1.x - t2.x )*(t1.y - t3.y) == (t1.y-t2.y)*(t1.x-t3.x);

}

double rast2(   double x1, double y1,
                double x2, double y2) {
    // racuna kvad. rastojanja
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2); // bez korena, zbog brzine
}

bool f ( tacka &t1, tacka &t2 ) {
    double dx1 = t1.x - xt, dy1 = t1.y - yt;
    double dx2 = t2.x - xt, dy2 = t2.y - yt;

    double ugao1 = atan2(dy1, dx1);
    double ugao2 = atan2(dy2, dx2);

    if (ugao1 < ugao2 - epsi)
        return true;
    if (ugao2 < ugao1 - epsi)
        return false;  
    // uglovi su isti...
    return rast2(xt,yt,t1.x,t1.y) < rast2(xt,yt,t2.x,t2.y);  
}

void prost(vector<tacka>&tacke){
    // trazi prvu nekol. tacku... sa t0 i t1
    int i = 2;
    while ( kol(tacke[0], tacke[1], tacke[i]) ) 
        i++; // nalazi prvu nekolin.

    // odredi teziste za 3 nelin. tacke...
    xt = ( tacke[0].x + tacke[1].x + tacke[i].x ) / 3.0;
    yt = ( tacke[0].y + tacke[1].y + tacke[i].y ) / 3.0;

    sort( begin(tacke), end(tacke), f );

    
}

int main() {
    int n; cin >> n; // broj tacaka, temena, stranica  

    vector<tacka>tacke(n); // vektor za sve tacke

    for (int i = 0; i < n; i++)
        cin >> tacke[i].x >> tacke[i].y;

    prost(tacke); // napravi prost mnogougao 

    for ( auto t : tacke ) // ispis
        cout << t.x << ' ' << t.y << '\n';

    return 0; }