#include <bits/stdc++.h>
using namespace std;
const double INF = numeric_limits<double>::infinity();
           // rast0, cvor, preth
typedef tuple<double, int, int> Tri;
// Dijkstra PQ

int main() {
    //ios_base...
    int n, e; cin >> n >> e;
    vector<vector<pair<double,int>>>veze(n); // u---d--->v
    for (int i = 0; i < e; i++) {
        int u, v; double d; cin >> u >> v >> d;
        veze[u].emplace_back(d,v); // v,d, ...
    }

    int pocetak; cin >> pocetak; // pocetni cvor
    int kraj; cin >> kraj; // pocetni cvor

    vector<double>rast0(n, INF); // pre pocetka, sve udalj. su INF
    vector<bool>resen(n, false); // i nijedan cvor nije resen....
    vector<int>preth(n, -1); // prethodni
    // da krenemo...

    rast0[pocetak] = 0.0; // trivial

    priority_queue<Tri, vector<Tri>, greater<Tri>>pq;
    pq.emplace(0.0, pocetak, -1);

    while ( !pq.empty() ) {
        int najblizi, roditelj;
        double najmrast;
        tie(najmrast, najblizi, roditelj) = pq.top();
        pq.pop();
        if ( resen[najblizi] ) continue; // ako je resen...
        resen[najblizi] = true; // naj...
        preth[najblizi] = roditelj;//preth.

        if ( najblizi == kraj ) break; // reseno od pocetka do kraja

        for ( auto v : veze[najblizi] ) {
            int cvor; double duzina;
            tie(duzina, cvor) = v;
            if ( !resen[cvor] && najmrast + duzina < rast0[cvor] ) {
                rast0[cvor] = najmrast + duzina;
                pq.emplace(rast0[cvor], cvor, najblizi);  }  }  }

     if ( rast0[kraj] < INF) { // moguce od poc. do kraj.
        cout << fixed << setprecision(5) << showpoint << 
                rast0[kraj] << endl; // TODO
        stack<int>put;
        put.push(kraj); // rekostrukcija puta
        while ( preth[kraj] != -1 ) {
            kraj = preth[kraj];
            put.push(kraj); }
        while ( !put.empty() ) {
            cout << put.top() << ' ';
            put.pop();  }  }
    else
        cout << "ne";




    return 0; }
