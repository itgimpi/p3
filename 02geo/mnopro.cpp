#include <bits/stdc++.h>
using namespace std; // Конструкција простог многоугла
// https://petlja.org/biblioteka/r/Zbirka3/prost_poligon

typedef struct tacka { int x, y };

tacka t0;

int ori( const tacka &t0, const tacka &t1, const tacka &t2) {
    int z = ( t1.x - t0. x) * ( t2.y - t0.y ) - ( t2.x - t0.x ) * (t1.y - t0.y);
    if ( z > 0) return +1;
    if ( z < 0) return -1;
    return 0; }

int rast2( const tacka &t1, const tacka &t2){
    int dx = t1.x - t2.x;
    int dy = t1.y - t2.y;
    return dx * dx + dy * dy; }  // vodi racuna o prekoracenju, long long

// sort je pre svega po orijentaciji
// ako su tacke kolinearne, bira se bliza krajnje desnoj tacki
bool f( const tacka &t1, const tacka &t2 ) {
    int or = ori(t0, t1, t2);
    if ( or == 0 ) // kolinearne?
        return rast2(t0, t1) < rast2(t0, t2);
    return or == 1; // + orijentacija
}

void prost(vector<tacka>&tacke) {
    // trazi se tacka sa xmax
    int indd = 0; // neka je to prva...
    for ( int i = 0; i < tacke.size(); i++ )
        if ( tacke[i].x > tacke[indd].x       // ako je i-ta tacka desnija...
            || tacke[i].x == tacke[indd].x  // ili ako su isto desno
            && tacke[i].y < tacke[indd].y ) // a tacka je dole
       
                indd = i; // desnija je
    swap(tacke[0], tacke[indd]); // ide na prvu poziciju
    t0 = tacke[0]; // t0 je ta desna tacka
    // sortiraj ostale
    sort(next(begin(tacke)), end(tacke), f); // bez t0

    auto it = prev(end(tacke)); // zadnja
    while ( ori( *prev(it), *it, t0  ) == 0  )
        it = prev(it);
    
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