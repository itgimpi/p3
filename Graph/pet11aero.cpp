#include <bits/stdc++.h>
using namespace std;
// Матрица повезаности
int main() {
    //ios_base...
    int n, e; cin >> n >> e; // num. of nodes & edges
    vector<vector<bool>>veze(n, vector<bool>(n, false)); // M(n^2)

    for (int i = 0; i < e; i++) {
        int u, v; cin >> u >> v; // cvor od i cvor do
        u--; v--; // cvor 1->0, 5->4
        // radi se sa cvorovima od 0 do n-1
        veze[u][v]=true; } // postoji veza od u do v

    int q; cin >> q;
    int brv = 0;
    while (q--) {
        int u, v; cin >> u >> v; u--; v--;
        if ( veze[u][v] ) brv++; }
    cout << brv;

    return 0; }
