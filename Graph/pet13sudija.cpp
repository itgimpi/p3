#include <bits/stdc++.h>
using namespace std;
// in, out degree, without edges

int main() {
    ios_base::sync_with_stdio(false);
    int n, e; cin >> n >> e; // num. of nodes & edges
    vector<int>ulaz(n+1); // ulazni stepeni
    vector<int>izlaz(n+1);

    for (int i = 0; i < e; i++) { // za sve grane...
        int u, v; cin >> u >> v; // u -> v
        ulaz[v]++;  // v is in 
        izlaz[u]++; } // u is out
    // trazi se indeks cvora koji ima indeg==n-1, outdeg==0
    int ind = -1; // ne postoji sudija?
    for (int i = 1; i <= n; i++) { // za svaki cvor...
        if (ulaz[i]==n-1 && izlaz[i]==0) // uslov za sudiju
            ind = i; }
    cout << ind; 
    return 0; }
