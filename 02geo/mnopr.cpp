#include <bits/stdc++.h>
using namespace std; // Конструкција простог многоугла
// https://petlja.org/biblioteka/r/Zbirka3/prost_poligon


typedef struct { // struktura tacka
    int x; 
    int y; } tacka;

tacka t0;

int ori( const tacka &t1, const tacka &t2 ) {
    int vp = (t1.x-t0.x) * (t2.y-t0.y) - 
             (t2.x-t0.x) * (t1.y-t0.y);
    if (vp > 0) return 1;
    if (vp < 0) return -1;
    return 0; }

int rast2(   const tacka &t1, const tacka &t2) {
    // racuna kvad. rastojanja
    int dx = t1.x - t2.x, dy = t1.y - t2.y;
    return dx * dx + dy * dy; // bez korena, zbog brzine
}

bool f ( const tacka &t1, const tacka &t2 ) {
    int oro = ori(t1, t2);

    if (oro == 0) // ako su kol.
        return rast2(t0, t1) < rast2(t0, t2); // odaberi blizu t0

    return oro == 1; // ako je v.p. poz, vrati T
     
}

void prost(vector<tacka>&tacke){
    // trazi krajnje desnu tacku, ako su vise, donju...
    int indd = 0; // njen indeks
    for ( int i = 0; i < tacke.size(); i++ ) // za sve tacke
        if ( tacke[i].x > tacke[indd].x          // i je desnija od preth.
             || tacke[i].x == tacke[indd].x      // ili isto desne
             && tacke[i].y < tacke[indd].y )     // ali je vise dole
            indd = i;
    // ta DD tacka ide na poz. 0
    swap(tacke[0], tacke[indd]);
    t0 = tacke[0];
    sort( next(begin(tacke)), end(tacke), f ); // sort bez t0, po f-u

    // ako na kraju postoje kolinearne, ne valja...
    auto it = prev(end(tacke)); // zadnja
    while ( ori( *prev(it), *it ) == 0 ) // dok postoje kol.
        it = prev(it);  // idi na preth.
    // it ukazuje na prvu kol. sa zadnjom
    reverse(it, end(tacke));
   
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