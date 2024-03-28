#include <bits/stdc++.h>
using namespace std;
// Достижни чворови, https://petlja.org/biblioteka/r/Zbirka3/dostizni_cvorovi

int main() {
    ios_base::sync_with_stdio(false);
    int n, e; cin >> n >> e; // num. of nodes & edges
    vector<vector<int>>veze(n);
    for (int i = 0; i < e; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        veze[u].push_back(v); }
        
    int q; cin >> q;
    while (q--) { // za svaki upit...
        int prvi, drugi; cin >> prvi >> drugi; prvi--; drugi--;
        vector<bool>posecen(n, false);
        stack<int>stek;
        stek.push(prvi);
        posecen[prvi] = true;
        bool povezani = false; // prvi i drugi su povezani?
        while( !stek.empty() && !povezani ) {
            int c = stek.top(); stek.pop();
            for ( auto v : veze[c] ) { // sve komsije
                if ( v == drugi ) { // moduce je slanje, povezani su
                    povezani = true;
                    break; }
                if (!posecen[v]) { // komsija nije bio do sada posecen...
                    posecen[v] = true;
                    stek.push(v); } } }
        if (povezani) cout << "da" << '\n';
        else  cout << "ne" << '\n'; }
    return 0; }
