#include <bits/stdc++.h>
using namespace std;
// in, out degree

int main() {
    ios_base::sync_with_stdio(false);
    int n, e; cin >> n >> e; // num. of nodes & edges
    vector<int>ulaz(n+1);
    vector<int>izlaz(n+1);

    for (int i = 0; i < e; i++) {
        int u, v; cin >> u >> v;
        ulaz[v]++;
        izlaz[u]++; } // v's in, out degree
    // trazi se indeks cvora koji ima indeg==n-1, outdeg==0
    int ind = -1;
    for (int i = 1; i <= n; i++) { // za svaki cvor...
        if (ulaz[i]==n-1 && izlaz[i]==0) 
            ind = i; }
    cout << ind; 
    return 0; }
