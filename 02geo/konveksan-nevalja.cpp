#include <bits/stdc++.h>
using namespace std; // Конвексни омотач
// https://petlja.org/biblioteka/r/Zbirka3/konveksni_omotac
// Graham's Alg.

typedef struct { // struktura tacka
    int x; 
    int y; } tacka;

int ori( const tacka &t1, const tacka &t2 ) { // FALI t0
    int vp = (t1.x-t0.x) * (t2.y-t0.y) - 
             (t2.x-t0.x) * (t1.y-t0.y);
    if (vp > 0) return 1;
    if (vp < 0) return -1;
    return 0; }

int rast2(   const tacka &t1, const tacka &t2) { // TODO LL
    // racuna kvad. rastojanja
    int dx = t1.x - t2.x, dy = t1.y - t2.y;
    return dx * dx + dy * dy; // bez korena, zbog brzine
}

void prost(vector<tacka>&tacke) {
    auto dd = max_element( begin(tacke), end(tacke), // desno dole
                [](const tacka &t1, const tacka &t2) {
                    return   t1.x < t2.x ||
                            (t1.x == t2.x && t1.y > t2.y); } );
    swap( *begin(tacke), *dd );
    const tacka t0 = tacke[0];

    sort( next(begin(tacke)), end(tacke),
        [t0](const tacka &t1, const tacka &t2) {
            int o = ori(t0, t1, t2);
            if (o == 0) 
                return rast2(t0, t1) <= rast2(t0, t2);
            return o == 1;   } );
    // okreni zadnjih nekolko ako su kolinearne
    auto it = prev(end(tacke)); // n-1 tacka
    while( ori(*prev(it), *it, t0) == 0 ) 
        it = prev(it);
    reverse(it, end(tacke));

    

}

vector<tacka>graham(vector<tacka>&tacke) {
    vector<tacka>omotac; // za konv. omotac
    prost(tacke); // numerisan prost mnogougao
    
    omotac.push_back(tacke[0]); // prve 2 iz pr.mn.
    omotac.push_back(tacke[1]);

    for (int i = 2; i < tacke.size(); i++) {
        while ( omotac.size() > 1 && // ima vise od 1 tecke, stiti tacku 0
                ori( omotac[omotac.size()-2], omotac[omotac.size()-1], tacke[i] ) != 1; ) {
            omotac.pop_back();

        }
        omotac.push_back(tacke[i]);
    }

    return omotac;

}

int main() {
    int n; cin >> n; // broj tacaka, temena, stranica  

    vector<tacka>tacke(n); // vektor za sve tacke

    for (int i = 0; i < n; i++)
        cin >> tacke[i].x >> tacke[i].y;

    vector<tacka> omotac = graham(tacke); // napravi prost mnogougao 

    for ( auto t : tacke ) // ispis
        cout << t.x << ' ' << t.y << '\n';

    cout << omotac.size() << '\n';
    for( auto tt : omotac ) 
        cout << tt.x << ' ' << tt.y << '\n';


    return 0; }