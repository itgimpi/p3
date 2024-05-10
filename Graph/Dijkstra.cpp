#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX; // beskonacno je najveci ceo broj
// Dijkstra
// odredjuje udaljenost svih cvorova od pocetnog
int main() {
    ios_base::sync_with_stdio(false);
    int n, e; cin >> n >> e; // br. cvorova i broj grana
    vector<vector<pair<int,int>>>veze(n); // u---d--->v
    for (int i = 0; i < e; i++) {
        int u, v, d; cin >> u >> v >> d; // prvi, drugi i rastojanje
        veze[u].emplace_back(d,v); // v,d, ...
    }

    int pocetak; cin >> pocetak; // pocetni cvor
    // int kraj; cin >> kraj;
    vector<int>rast0(n, INF); // pre pocetka, sva rastojanja od poc. cvora 
    vector<bool>resen(n, false); // nijedan cvor nije resen
    // da krenemo...
    rast0[pocetak] = 0; // poc. cvor je na udaljenosti 0 od samog sebe
    int brres = 0; // broj resenih, jos ih nema...
    while ( brres < n ) { // za sve cvorove...
        //int indnajblizeg = 0; // najblizeg pocetnom
        int indnajblizeg; // indeks najblizeg pocetnom
        int najmrast = INF; // najmanje rastojanje
        // nadji indeks najblizeg neresenog cvora
        for ( int c = 0; c < n; c++ )
            if ( !resen[c] && rast0[c] < najmrast ) {
                indnajblizeg = c;
                najmrast = rast0[c];  }
        // indnajblizeg sadrzi indeks najblizeg
        // najm rast je rastojanje
        resen[indnajblizeg] = true; 
        brres++;
        // za svakog suseda...
        for ( auto v : veze[indnajblizeg] ) {
            int cvor, duzina;
            tie(duzina, cvor) = v; // uzmi udaljenost i drugi cvor
            if (!resen[cvor] && najmrast + duzina < rast0[cvor])
                rast0[cvor] = najmrast + duzina;        }     
    }

    for (int i = 0; i < n; i++)
        cout << i << ' ' << rast0[i] << '\n';

    return 0; }
