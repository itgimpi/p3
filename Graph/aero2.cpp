#include <bits/stdc++.h>
using namespace std;
// aero

int main() {
    //ios_base::sync_with_stdio(false);
    int n, e; cin >> n >> e; // n ide od 1 do n
    vector<vector<bool>>letovi(n,vector<bool>(n,false));

    for ( int i = 0; i < e; i++ ) {
        int u, v; cin >> u >> v; //
        u--; v--; // 1->0, 2->1, ..., n->n-1
        letovi[u][v]=true; }

    int sol = 0;
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v; u--; v--;
        if ( letovi[u][v] ) sol++;
    }
    cout << sol;

    return 0; }
