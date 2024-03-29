#include <bits/stdc++.h>
using namespace std;
// Да ли је бипартитан

bool bi(const vector<vector<int>>&veze, vector<int>&res, int n){
    vector<int>boje(n, -1); // svi cvorovi su bez boje
    boje[0] = 1; // prvi cvor je boje 1 

    queue<int>q; // BFS
    q.push(0);  // pocinje se od cvora 0
    res.push_back(0); // 0 je deo resenja, ako resenje postoji

    while ( !q.empty() ) { // sve dok ima komsija, komsija od komsija, ....
        int u = q.front(); q.pop();
        for ( auto v : veze[u] ) { // za svakog komsiju od cvora u, da ga krstimo v...
            if ( boje[v] == -1 ) { // ako je neobojen...
                // if boje [u] 0-> 1, 1->0, 1-1=0, 1-0=1
                boje[v] = 1 - boje[u]; // oboji komsiju u suprotnu boju od u-a
                q.push(v); // taj komsija ide ured za obradu...
                if (boje[v] == 1) // ako je iste boje sa 0-om
                    res.push_back(v); } // ide u resenje
            else if ( boje[u] == boje[v] ) // komsije su iste boje!!!!!!
                return false; } } // graf nije bipartitan, back to the main
    // nijednom se nije desilo da su komsije iste boje...            
    return true; }

int main() {
    ios_base::sync_with_stdio(false);

    int n, e; cin >> n >> e;
    vector<vector<int>>veze(n);
    for (int i = 0; i < e; i++) {
        int u, v; cin >> u >> v;
        veze[u].push_back(v);
        veze[v].push_back(u); }

    vector<int>res; // resenja
    if (!bi(veze, res, n)) // nije bi...
        cout << '-';
    else { // jeste bi..., ispis resenja
        sort(res.begin(), res.end()); // resenje treba da bude sortirano
        for ( auto r : res )
            cout << r << ' ';  }

    
    return 0; }
